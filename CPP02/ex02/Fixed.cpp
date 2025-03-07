#include "Fixed.hpp"

Fixed::Fixed() : fvalue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int &n) 
{
    fvalue = n << fw;
}

Fixed::Fixed(const float &n) 
{
    fvalue = roundf(n * (1 << fw));
}

Fixed::Fixed(const Fixed &fix)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = fix; 
}

Fixed& Fixed::operator=(const Fixed& fix)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if(this != &fix)
    {
        this->fvalue = fix.getRawBits();
    }
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return out;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->fvalue;
}

void Fixed::setRawBits(int const raw)
{
    this->fvalue = raw;
}

float Fixed::toFloat() const 
{ 
    return (float)fvalue / (1 << fw);
}

int Fixed::toInt() const 
{
    return fvalue >> fw;
}

bool Fixed::operator>(const Fixed& other) const 
{ 
    return fvalue > other.fvalue; 
}
bool Fixed::operator<(const Fixed& other) const 
{ 
    return fvalue < other.fvalue; 
}
bool Fixed::operator>=(const Fixed& other) const 
{ 
    return fvalue >= other.fvalue; 
}
bool Fixed::operator<=(const Fixed& other) const 
{ 
    return fvalue <= other.fvalue; 
}
bool Fixed::operator==(const Fixed& other) const 
{ 
    return fvalue == other.fvalue; 
}
bool Fixed::operator!=(const Fixed& other) const 
{ 
    return fvalue != other.fvalue; 
}

Fixed Fixed::operator+(const Fixed& other) const 
{
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const 
{
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const 
{
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const 
{
    if (other.fvalue == 0) {
        std::cerr << "Error: Division by zero!" << std::endl;
        return Fixed(0);
    }
    return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++() 
{
    fvalue++;
    return *this;
}

Fixed Fixed::operator++(int) 
{
    Fixed temp = *this;
    fvalue++;
    return temp;
}

Fixed& Fixed::operator--() 
{
    fvalue--;
    return *this;
}

Fixed Fixed::operator--(int) 
{
    Fixed temp = *this;
    fvalue--;
    return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) 
{
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) 
{
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) 
{
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) 
{
    return (a > b) ? a : b;
}