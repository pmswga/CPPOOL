#ifndef VECTOR3D
#define VECTOR3D

#include <iostream>
using namespace std;

class Vector3D
{
    int x, y, z;
    int ceil_module;
    double real_module;

public:
    Vector3D(int x, int y, int z) : x(x), y(y), z(z)
    {
        this->ceil_module = x*x + y*y + z*z;
        this->real_module = sqrt(this->ceil_module);
    }

    int getModule()
    {
        return this->ceil_module;
    }

    double getRealModule()
    {
        return this->real_module;
    }

    Vector3D &operator*(int b)
    {
        this->x *= b;
        this->y *= b;
        this->z *= b;
        return *this;
    }

    Vector3D &operator*(Vector3D &b)
    {
        this->x *= b.x;
        this->y *= b.y;
        this->z *= b.z;
        return *this;
    }

    friend ostream &operator<<(ostream &os, Vector3D &v)
    {
        os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
        return os;
    }

};

#endif

