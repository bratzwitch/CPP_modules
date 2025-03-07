#include "Fixed.hpp"

Fixed::Fixed() : fvalue(0)
{
    std::cout << "Default constructor called" << std::endl;
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