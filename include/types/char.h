#ifndef CHAR_H
#define CHAR_H

#include <iostream>
using namespace std;

namespace ctl
{

namespace type
{

namespace base
{

    class Char
    {
        int _code;
        char _char;

    public:
        Char() : _code(0), _char(0)
        {

        }

        ~Char()
        {

        }

        Char(const char c) :  _code( static_cast<int>(c) ), _char(c)
        {

        }

        int code()
        {
            return this->_code;
        }

        Char& operator=(const Char &c)
        {
            this->_char = c._char;
            this->_code = c._code;
            return *this;
        }

        Char& operator=(char c)
        {
            this->_char = c;
            this->_code = static_cast<int>(c);
            return *this;
        }

        friend ostream &operator<<(ostream &os, Char &c)
        {
            os << c._char;
            return os;
        }

    };

}

}

}

#endif
