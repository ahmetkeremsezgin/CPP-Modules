#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>

class Span {
    private:
        unsigned int n;
        std::vector<int> stack;

    public:
        Span();
        Span(unsigned int max);
        Span(const Span& cpy);
        Span& operator=(const Span &cpy);
        ~Span();

        void addNumber(int newNumber);
        
        template <typename Iterator>
        void addNumber(Iterator begin, Iterator end) {
            if (std::distance(begin, end) + stack.size() > n) {
                throw std::out_of_range("Span outofrange.");
            }
            stack.insert(stack.end(), begin, end);
        }

        long shortestSpan();
        long longestSpan();
};

#endif