#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>

class Rpn {
    private:
        std::stack<int> _stack;
    public:
        Rpn();
        Rpn(const Rpn& cpy);
        Rpn& operator=(const Rpn& cpy);
        ~Rpn();
        int exec(std::string data);
};

#endif