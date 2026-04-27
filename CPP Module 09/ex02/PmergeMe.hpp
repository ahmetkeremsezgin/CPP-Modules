#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <cstdlib>
#include <ctime>

class PmergeMe {
private:
    struct Node {
        int value;
        std::vector<Node> losers;

        Node() : value(-1) {}
        Node(int v) : value(v) {}
        
        bool operator<(const Node& other) const {
            return value < other.value;
        }
    };

    static std::vector<size_t> generateJacobsthal(size_t n);

    // Bu fonksiyon her zaman Node içeren bir konteynerle çalışır
    template <typename T>
    static void sortImplementation(T& container) {
        if (container.size() <= 1) return;

        bool hasStraggler = (container.size() % 2 != 0);
        Node straggler;
        if (hasStraggler) {
            straggler = container.back();
            container.pop_back();
        }

        T winners;
        for (size_t i = 0; i < container.size(); i += 2) {
            if (container[i + 1] < container[i]) {
                container[i].losers.push_back(container[i + 1]);
                winners.push_back(container[i]);
            } else {
                container[i + 1].losers.push_back(container[i]);
                winners.push_back(container[i + 1]);
            }
        }

        sortImplementation(winners);

        T main_chain;
        T pend;

        if (!winners.empty() && !winners[0].losers.empty()) {
            main_chain.push_back(winners[0].losers.back());
            winners[0].losers.pop_back();
        }

        for (size_t i = 0; i < winners.size(); ++i) {
            main_chain.push_back(winners[i]);
            if (!winners[i].losers.empty()) {
                pend.push_back(winners[i].losers.back());
                winners[i].losers.pop_back();
            }
        }

        std::vector<size_t> jacob = generateJacobsthal(pend.size());
        size_t last_inserted = 0;

        for (size_t i = 0; i < jacob.size(); ++i) {
            size_t current_jacob = std::min(jacob[i], pend.size());
            for (size_t j = current_jacob; j > last_inserted; --j) {
                Node item = pend[j - 1];
                typename T::iterator it_pos = std::lower_bound(main_chain.begin(), main_chain.end(), item);
                main_chain.insert(it_pos, item);
            }
            last_inserted = current_jacob;
        }

        for (size_t j = pend.size(); j > last_inserted; --j) {
            Node item = pend[j - 1];
            typename T::iterator it_pos = std::lower_bound(main_chain.begin(), main_chain.end(), item);
            main_chain.insert(it_pos, item);
        }

        if (hasStraggler) {
            typename T::iterator it_pos = std::lower_bound(main_chain.begin(), main_chain.end(), straggler);
            main_chain.insert(it_pos, straggler);
        }

        container = main_chain;
    }

public:
    // Execute fonksiyonu artık her iki tip için de ayrı Node konteynerleri oluşturur
    template <typename T>
    static double execute(int argc, char** argv, T& container) {
        std::vector<int> raw_data;
        for (int i = 1; i < argc; ++i) {
            char* endptr;
            long val = std::strtol(argv[i], &endptr, 10);
            if (*endptr != '\0' || val < 0 || val > 2147483647)
                throw std::runtime_error("Error: Invalid input");
            raw_data.push_back(static_cast<int>(val));
        }

        std::clock_t start = std::clock();
        
        // Hatanın çözümü: T tipi std::vector<int> ise internal_container std::vector<Node> olmalı
        // Bunu C++98'de sağlamanın en temiz yolu, T'nin tipine göre Node konteynerini seçmektir.
        
        // Önce int'leri Node'a çeviriyoruz
        // Not: Burada 'internal_container' tipi T'nin kendisi değil, Node versiyonu olmalı.
        // main.cpp'de hem vector hem deque çağırdığın için buradaki mantığı ikiye ayırıyoruz:
        
        return runInternalSort(raw_data, container, start);
    }

    // Yardımıcı: Vector için
    static double runInternalSort(std::vector<int>& raw, std::vector<int>& target, std::clock_t start) {
        std::vector<Node> internal_vec;
        for (size_t i = 0; i < raw.size(); ++i) internal_vec.push_back(Node(raw[i]));
        sortImplementation(internal_vec);
        target.clear();
        for (size_t i = 0; i < internal_vec.size(); ++i) target.push_back(internal_vec[i].value);
        std::clock_t end = std::clock();
        return static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
    }

    // Yardımcı: Deque için
    static double runInternalSort(std::vector<int>& raw, std::deque<int>& target, std::clock_t start) {
        std::deque<Node> internal_deq;
        for (size_t i = 0; i < raw.size(); ++i) internal_deq.push_back(Node(raw[i]));
        sortImplementation(internal_deq);
        target.clear();
        for (size_t i = 0; i < internal_deq.size(); ++i) target.push_back(internal_deq[i].value);
        std::clock_t end = std::clock();
        return static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
    }

    static void printBefore(int argc, char** argv);
};

#endif