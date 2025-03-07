#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>


class Fixed{
    private:
        int fvalue;
        static const int fw = 8;
    public:
        Fixed();
        Fixed(const int &n);
        Fixed(const float &n);
        Fixed(const Fixed &copy);
        Fixed& operator=(const Fixed& fix);
        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
};
std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif