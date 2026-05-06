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
            if (i > 0 && !winners[i].losers.empty()) {
                pend.push_back(winners[i].losers.back());
                winners[i].losers.pop_back();
            }
            main_chain.push_back(winners[i]);
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
        return runInternalSort(raw_data, container, start);
    }

    static double runInternalSort(std::vector<int>& raw, std::vector<int>& target, std::clock_t start);
    static double runInternalSort(std::vector<int>& raw, std::deque<int>& target, std::clock_t start);

    static void printBefore(int argc, char** argv);
};

#endif