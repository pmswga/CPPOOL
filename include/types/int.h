#ifndef INT_H
#define INT_H

#include <iostream>
using namespace std;

namespace ctl
{

namespace type
{

namespace base
{

    class Int
    {
        int _int;

    public:
        Int() : _int(0)
        {

        }

        ~Int()
        {

        }

        Int(const int _int) : _int(_int)
        {

        }

        Int(Int &_int)
        {
            this->_int = _int._int;
        }


        Int& operator=(const Int &a)
        {
            this->_int = a._int;
            return *this;
        }

        Int& operator=(int a)
        {
            this->_int = a;
            return *this;
        }

        int operator()()
        {
            return this->_int;
        }

        friend Int operator + (Int l, const Int& r)
        {
            l._int += r._int;
            return l;
        }

        Int &operator++()
        {
            this->_int++;
            return *this;
        }

        Int operator++(int)
        {
            Int tmp(*this);
            operator++();
            return tmp;
        }

        Int &operator--()
        {
            this->_int--;
            return *this;
        }

        Int operator--(int)
        {
            Int tmp(*this);
            operator--();
            return tmp;
        }

        bool operator == (const Int &a)
        {
            return this->_int == a._int;
        }

        friend ostream &operator<<(ostream &os, Int &a)
        {
            os << a._int;
            return os;
        }

        friend istream &operator>>(istream &is, Int &a)
        {
            is >> a._int;
            return is;
        }

    };

}

}

}


#endif
