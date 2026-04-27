#include "RPN.hpp"

rpn::rpn() {}

rpn::rpn(const rpn& cpy) {
    *this = cpy;
}

rpn& rpn::operator=(const rpn& cpy) {
    (void)cpy;
    return *this;
}

rpn::~rpn() {}

int rpn::exec(std::string data) {
    for (size_t i = 0; i < data.length(); ++i) {
        if (isspace(data[i])) continue;

        if (isdigit(data[i])) {
            _stack.push(data[i] - '0');
        } 
        else if (data[i] == '+' || data[i] == '-' || data[i] == '*' || data[i] == '/') {
            if (_stack.size() < 2) return 0;

            int b = _stack.top(); _stack.pop();
            int a = _stack.top(); _stack.pop();

            if (data[i] == '+') _stack.push(a + b);
            else if (data[i] == '-') _stack.push(a - b);
            else if (data[i] == '*') _stack.push(a * b);
            else if (data[i] == '/') {
                if (b == 0) return 0;
                _stack.push(a / b);
            }
        } 
        else {
            return 0;
        }
    }


    if (_stack.size() != 1) return 0;

    std::cout << _stack.top() << std::endl;
    return 1;
}