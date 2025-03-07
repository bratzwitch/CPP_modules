#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed{
    private:
        int fvalue;
        static const int fw = 8;
    public:
        Fixed();
        Fixed(const Fixed &copy);
        Fixed& operator=(const Fixed& fix);
        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits( int const raw );
};


#endif