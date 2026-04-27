#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>

class rpn {
    private:
        std::stack<int> _stack;
    public:
        rpn();
        rpn(const rpn& cpy);
        rpn& operator=(const rpn& cpy);
        ~rpn();
        int exec(std::string data);
};

#endif