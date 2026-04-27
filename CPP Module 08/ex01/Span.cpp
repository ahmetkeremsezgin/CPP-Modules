#include "Span.hpp"
#include <algorithm>
#include <stdexcept>
#include <limits>

Span::Span() : n(0) {}

Span::Span(unsigned int max) : n(max) {}

Span::Span(const Span& cpy) : n(cpy.n), stack(cpy.stack) {}

Span &Span::operator=(const Span &cpy) {
    if (this != &cpy) {
        this->n = cpy.n;
        this->stack = cpy.stack;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int newNumber) {
    if (this->stack.size() >= this->n) {
        throw std::out_of_range("Span is already full.");
    }
    this->stack.push_back(newNumber);
}

long Span::shortestSpan() {
    if (this->stack.size() < 2) {
        throw std::logic_error("Not enough elements to find a span.");
    }
    
    std::vector<int> sorted = this->stack;
    std::sort(sorted.begin(), sorted.end());

    int best = std::numeric_limits<int>::max();
    for (std::vector<int>::size_type i = 0; i < sorted.size() - 1; ++i) {
        int diff = sorted[i + 1] - sorted[i];
        if (diff < best)
            best = diff;
    }
    return best;
}

long Span::longestSpan() {
    if (this->stack.size() < 2) {
        throw std::logic_error("Not enough elements to find a span.");
    }

    std::vector<int>::iterator min_it = std::min_element(this->stack.begin(), this->stack.end());
    std::vector<int>::iterator max_it = std::max_element(this->stack.begin(), this->stack.end());
    
    return *max_it - *min_it;
}