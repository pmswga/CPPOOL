#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
using namespace std;

class MatrixException : public exception
{
    const char *msg;

public:
    MatrixException(const char *msg) : exception(), msg(msg)
    {
    }

    const char* what()
    {
        return this->msg;
    }

};

class Matrix
{
    unsigned int n, m;
    int _det;
    int **matrix;

    void add(int number)
    {
        for (int i = 0; i < this->n; i++) {
            for (int j = 0; j < this->m; j++) {
                this->matrix[i][j] += number;
            }
        }
    }

    void add(const Matrix &b)
    {
        if (this->n == b.n && this->m == b.m) {
            for (int i = 0; i < this->n; i++) {
                for (int j = 0; j < this->m; j++) {
                    this->matrix[i][j] += b.matrix[i][j];
                }
            }
        } else {
            throw MatrixException("Incompatible sizes of matrixes");
        }
    }

    void mul(int number)
    {
        for (int i = 0; i < this->n; i++) {
            for (int j = 0; j < this->m; j++) {
                this->matrix[i][j] *= number;
            }
        }
    }

public:
    Matrix(int n, int m) : n(n), m(m)
    {
        this->matrix = new int*[n];
        this->_det = 0;

        srand(time(0));
        for (int i = 0; i < this->n; i++) {
            matrix[i] = new int[m];

            for (int j = 0; j < this->m; j++) {
                this->matrix[i][j] = (rand() % 10)+1;
            }
        }



        /*!
            Evaluate determinant
        */

        if (this->n == 3 && this->m == 3)
        {
            this->_det =
                ( this->matrix[0][0] * this->matrix[1][1] * this->matrix[2][2] ) +
                ( this->matrix[0][1] * this->matrix[2][0] * this->matrix[1][2] ) +
                ( this->matrix[0][3] * this->matrix[1][0] * this->matrix[2][1] ) -
                ( this->matrix[0][2] * this->matrix[1][1] * this->matrix[2][0] ) -
                ( this->matrix[0][1] * this->matrix[1][0] * this->matrix[2][2] ) -
                ( this->matrix[0][0] * this->matrix[1][2] * this->matrix[2][1] )
            ;
        }

    }

    int det()
    {
        return this->_det;
    }

    Matrix& operator+(int b)
    {
        this->add(b);
        return *this;
    }

    Matrix& operator+(Matrix &b)
    {
        this->add(b);
        return *this;
    }

    Matrix& operator+=(int b)
    {
        this->add(b);
        return *this;
    }

    Matrix& operator*(int b)
    {
        this->mul(b);
        return *this;
    }

    Matrix& operator*(Matrix &b)
    {

        return *this;
    }

    friend ostream& operator<<(ostream &os, Matrix &m)
    {
        for (int i = 0; i < m.n; i++) {
            os << "|";
            for (int j = 0; j < m.m; j++) {
                os << m.matrix[i][j];
                if (j+1 < m.m) {
                    os << ", ";
                }
            }
            os << "|" << '\n';
        }
        return os;
    }

};


#endif