#ifndef T04_PREKLOPUVANJE_NA_OPERATORI_H
#define T04_PREKLOPUVANJE_NA_OPERATORI_H

#include <iomanip>
#include <iostream>
#include <cstring>
#include <sstream>

class Dropka
{
private:
    int mNumerator;
    int mDenominator;

    static int GCD(int num1, int num2)
    {
        while(1)
        {
            if (num2 == 0)
                return num1;

            int temp = num1%num2;
            num1 = num2;
            num2 = temp;
        }
    }

    static int LCM(int num1, int num2)
    {
        return (num1 * num2) / GCD(num1, num2);
    }

public:
    Dropka(int numerator, int denominator) :
        mNumerator(numerator),
        mDenominator(denominator)
    {

    }

    Dropka& reduce()
    {
        int gcd = GCD(mNumerator, mDenominator);
        mNumerator /= gcd;
        mDenominator /= gcd;
        return *this;
    }

    Dropka operator+(const Dropka& f)
    {
        int d = LCM(mDenominator, f.mDenominator);
        int n = (d/mDenominator)*mNumerator + (d/f.mDenominator)*f.mNumerator;
        return Dropka(n, d).reduce();
    }

    Dropka operator-(const Dropka& f)
    {
        int d = LCM(mDenominator, f.mDenominator);
        int n = (d/mDenominator)*mNumerator - (d/f.mDenominator)*f.mNumerator;
        return Dropka(n, d).reduce();
    }

    Dropka operator*(const Dropka& f)
    {
        return Dropka(mNumerator * f.mNumerator, mDenominator * f.mDenominator).reduce();
    }

    Dropka operator/(const Dropka& f)
    {
        return Dropka(mNumerator * f.mDenominator, mDenominator * f.mNumerator).reduce();
    }

    friend std::ostream& operator<<(std::ostream& os, const Dropka& f)
    {
        return os << f.mNumerator << "/" << f.mDenominator;
    }

    double real()
    {
        return (double)mNumerator / mDenominator;
    }
};

//copy-paste od zadaca02_03
void zadaca04_01()
{
    srand(time(NULL));

    int num;

    std::cout << "Vnesete broj na simulacii na dropki: ";
    std::cin >> num;

    for (int i=0;i<num;++i)
    {
        int n1, d1, n2, d2;

        while(true)
        {
            n1 = rand()%198-99;
            n2 = rand()%198-99;
            d1 = rand()%198-99;
            d2 = rand()%198-99;

            if (d1 != 0 && d2 !=0)
                break;
        }

        Dropka f1(n1, d1);
        Dropka f2(n2, d2);

        std::cout << f1 << " + " << f2 << " = " << f1+f2 << " = " << (f1+f2).real() << " = " << (double)n1/d1 + (double)n2/d2 << std::endl;
        std::cout << f1 << " - " << f2 << " = " << f1-f2 << " = " << (f1-f2).real() << " = " << (double)n1/d1 - (double)n2/d2 << std::endl;
        std::cout << f1 << " * " << f2 << " = " << f1*f2 << " = " << (f1*f2).real() << " = " << ((double)n1/d1) * ((double)n2/d2) << std::endl;
        std::cout << f1 << " / " << f2 << " = " << f1/f2 << " = " << (f1/f2).real() << " = " << ((double)n1/d1) / ((double)n2/d2) << std::endl;
        std::cout << std::endl;
    }

    std::cout << std::endl;
}

class Complex
{
public:
    Complex( double r=0.0, double i=0.0 )
        : real( r ), imaginary( i ) { }
    Complex operator+( const Complex &operand2 ) const
    {
        return Complex( real + operand2.real,
                        imaginary + operand2.imaginary );
    }
    Complex operator-( const Complex &operand2 ) const
    {
        return Complex( real - operand2.real,
                        imaginary - operand2.imaginary );
    }
    const Complex &operator=( const Complex &right )
    {
        real = right.real;
        imaginary = right.imaginary;
        return *this;
    }

    Complex operator*( const Complex &operand2 ) const
    {
        return Complex( real * operand2.real,
                        imaginary * operand2.imaginary );
    }

    Complex operator*( int operand2 ) const
    {
        return Complex( real * operand2,
                        imaginary );
    }

    friend Complex operator*(const int& operand1, const Complex &operand2 )
    {
        return Complex( operand1 * operand2.real,
                        operand2.imaginary );
    }

    friend std::ostream& operator<<(std::ostream& os, const Complex& c)
    {
        return os << '(' << c.real << ", " << c.imaginary << ')';
    }

    friend std::istream& operator>>(std::istream& is, Complex& c)
    {
        return is >> c.real >> c.imaginary;
    }

    bool operator==(const Complex& operand2)
    {
        return real == operand2.real && imaginary == operand2.imaginary;
    }

    bool operator!=(const Complex& operand2)
    {
        return !(*this == operand2);
    }

    Complex& operator+=(const Complex& operand2)
    {
        *this = *this + operand2;
        return *this;
    }

    Complex& operator-=(const Complex& operand2)
    {
        *this = *this - operand2;
        return *this;
    }

    Complex& operator*=(const Complex& operand2)
    {
        *this = *this * operand2;
        return *this;
    }

private:
    double real;
    double imaginary;
};

void zadaca04_02()
{
    Complex x, y( 4.3, 8.2 ), z( 3.3, 1.1 );
    std::cout << "x: " << x << std::endl;
    std::cout << "y: " << y << std::endl;
    std::cout << "z: " << z << std::endl;

    x = y + z;
    std::cout << "x = y + z = " << x << std::endl;

    x = y - z;
    std::cout << "x = y - z = " << x << std::endl;

    x = y * z;
    std::cout << "x = y * z = " << x << std::endl;

    x = y * 4;
    std::cout << "x = y * 4 = " << x << std::endl;

    x = 4 * z;
    std::cout << "x = 4 * z = " << x << std::endl;

    x = y;
    std::cout << "x = y = " << x << std::endl;

    std::cout << "x == y = " << (x == y) << std::endl;

    std::cout << "x != y = " << (x != y) << std::endl;

    std::cout << "y == z = " << (y == z) << std::endl;

    std::cout << "y != z = " << (y != z) << std::endl;

    x += y;
    std::cout << "x += y = " << x << std::endl;

    x -= z;
    std::cout << "x -= z = " << x << std::endl;

    std::cout << std::endl;
}

template <class T>
class Matrix
{
private:
    T** mData;
    int mRows;
    int mCols;

    class Array
    {
    private:
        T* mArray;

    public:
        Array(T* array) :
            mArray(array)
        {

        }

        T& operator[](int i) const
        {
            return mArray[i];
        }
    };
public:
    int getRows()
    {
        return mRows;
    }

    int getCols()
    {
        return mCols;
    }


    Matrix(int rows, int cols)
    {
        mRows = rows;
        mCols = cols;

        mData = new T*[mRows];
        for (int i=0;i<mRows;++i)
            mData[i] = new T[mCols];
    }

    ~Matrix()
    {
        for (int i=0;i<mRows;++i)
            delete[] mData[i];

        delete[] mData;
    }

    Matrix(const Matrix& m)
    {
        mRows = m.mRows;
        mCols = m.mCols;

        mData = new T*[mRows];
        for (int i=0;i<mRows;++i)
            mData[i] = new T[mCols];

        for (int i=0;i<mRows;++i)
            for (int j=0;j<mCols;++j)
                (*this)[i][j] = m[i][j];
    }

    Matrix& operator=(const Matrix& m)
    {
        this->~Matrix();

        mRows = m.mRows;
        mCols = m.mCols;

        mData = new T*[mRows];
        for (int i=0;i<mRows;++i)
            mData[i] = new T[mCols];

        for (int i=0;i<mRows;++i)
            for (int j=0;j<mCols;++j)
                (*this)[i][j] = m[i][j];

        return *this;
    }

    Matrix(const std::initializer_list<std::initializer_list<T>>& list)
    {
        mRows = list.size();
        mCols = (*list.begin()).size();

        mData = new T*[mRows];
        for (int i=0;i<mRows;++i)
            mData[i] = new T[mCols];


        auto iti = list.begin();
        for (int i=0;i<mRows;++i,++iti)
        {
            auto itj = (*iti).begin();
            for (int j=0;j<mCols;++j,++itj)
            {
                mData[i][j] = (*itj);
            }
        }
    }

    Array operator[](int i) const
    {
        return Array(mData[i]);
    }

    friend std::ostream& operator<<(std::ostream& os, const Matrix& m)
    {
        for (int i=0;i<m.mRows;++i)
        {
            for (int j=0;j<m.mCols;++j)
            {
                os << m[i][j] << "\t";
            }
            os << std::endl;
        }
        return os;
    }

    Matrix operator+(const Matrix& m) const
    {
        if (mRows != m.mRows || mCols != m.mCols)
        {
            throw "Error! Rows and columns do not match";
        }

        Matrix result(mRows, mCols);

        for (int i=0;i<mRows;++i)
            for (int j=0;j<mCols;++j)
                result[i][j] = (*this)[i][j] + m[i][j];

        return result;
    }

    Matrix operator+(const T& t) const
    {
        Matrix result(mRows, mCols);

        for (int i=0;i<mRows;++i)
            for (int j=0;j<mCols;++j)
                result[i][j] = (*this)[i][j] + t;

        return result;
    }

    friend Matrix operator+(const T& t, const Matrix& m)
    {
        return m + t;
    }

    Matrix operator-(const Matrix& m) const
    {
        if (mRows != m.mRows || mCols != m.mCols)
        {
            throw "Error! Rows and columns do not match";
        }

        Matrix result(mRows, mCols);

        for (int i=0;i<mRows;++i)
            for (int j=0;j<mCols;++j)
                result[i][j] = (*this)[i][j] - m[i][j];

        return result;
    }

    Matrix operator-(const T& t) const
    {
        Matrix result(mRows, mCols);

        for (int i=0;i<mRows;++i)
            for (int j=0;j<mCols;++j)
                result[i][j] = (*this)[i][j] - t;

        return result;
    }

    friend Matrix operator-(const T& t, const Matrix& m)
    {
        return m - t;
    }

    Matrix operator*(const Matrix& m) const
    {
        if (mCols != m.mRows)
        {
            throw "Error! Cols of A does not match rows of B";
        }

        Matrix result(mRows, m.mCols);

        for (int i=0;i<mRows;++i)
            for (int j=0;j<m.mCols;++j)
            {
                result.mData[i][j] = 0;
                for (int k=0;k<mCols;++k)
                    result[i][j] += (*this)[i][k] * m[k][j];
            }

        return result;
    }

    Matrix operator*(const T& t) const
    {
        Matrix result(mRows, mCols);

        for (int i=0;i<mRows;++i)
            for (int j=0;j<mCols;++j)
                result[i][j] = (*this)[i][j] * t;

        return result;
    }

    friend Matrix operator*(const T& t, const Matrix& m)
    {
        return m * t;
    }

    bool operator==(const Matrix& m) const
    {
        if (mRows != m.mRows || mCols != m.mCols)
            return false;

        for (int i=0;i<mRows;++i)
            for (int j=0;j<mCols;++j)
                if ((*this)[i][j] != m[i][j])
                    return false;

        return true;
    }

    bool operator!=(const Matrix& m) const
    {
        return !((*this)==m);
    }
};

void zadaca04_03()
{
    try
    {
        Matrix a = { {2, 4, 2}, {9, 3, 1} };
        Matrix b = { {3, 8}, {2, 1}, {4, 7} };

        std::cout << "Matrix A:\n" << a << std::endl;
        std::cout << "Matrix B:\n" << b << std::endl;

        //std::cout << "A + B:\n" << a+b << std::endl; // kje frli exception ovde
        std::cout << "A + A:\n" << a+a << std::endl;
        std::cout << "A + 4:\n" << a+4 << std::endl;
        std::cout << "4 + A:\n" << 4+a << std::endl;

        //std::cout << "B - A:\n" << b-a << std::endl; // kje frli exception ovde
        std::cout << "B - B:\n" << b-b << std::endl;
        std::cout << "B - 4:\n" << b-4 << std::endl;
        std::cout << "4 - B:\n" << 4-b << std::endl;

        std::cout << "A * B:\n" << a*b << std::endl;
        //std::cout << "A * A:\n" << a*a << std::endl; // kje frli exception ovde
        //std::cout << "B * B:\n" << b*b << std::endl; // kje frli exception ovde
        std::cout << "A * 4:\n" << a*4 << std::endl;
        std::cout << "4 * A:\n" << 4*a << std::endl;

        std::cout << "A == A: " << (a == a) << std::endl;
        std::cout << "A == B: " << (a == b) << std::endl;
        std::cout << "A != A: " << (a != a) << std::endl;
        std::cout << "A != B: " << (a != b) << std::endl;
    }
    catch (const char* e)
    {
        std::cerr << e << std::endl;
    }

    std::cout << std::endl;
}

#endif // T04_PREKLOPUVANJE_NA_OPERATORI_H
