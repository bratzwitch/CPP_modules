# C++ Modules (CPP 00-09)

A comprehensive series of C++ learning modules covering fundamental to advanced C++ programming concepts.

## Description

The C++ modules are a series of exercises designed to teach C++ programming from basic syntax to advanced features. Each module focuses on specific aspects of C++ and object-oriented programming, building upon previous knowledge to create a solid foundation in modern C++ development.

## Module Overview

### CPP Module 00 - Namespace, Classes, Member Functions
**Topics Covered:**
- Namespaces and scope resolution
- Basic class definition and instantiation
- Member functions and attributes
- Constructors and destructors
- Const member functions

**Exercises:**
- Megaphone (string manipulation)
- PhoneBook (basic class implementation)

### CPP Module 01 - Memory Allocation, Pointers, References
**Topics Covered:**
- Stack vs heap memory allocation
- Pointers and references
- Dynamic memory allocation (new/delete)
- Memory management best practices

**Exercises:**
- Zombie horde (dynamic allocation)
- Sed replacement (file manipulation)
- Violence (classes and pointers)

### CPP Module 02 - Ad-hoc Polymorphism, Operators, Orthodox Form
**Topics Covered:**
- Operator overloading
- Copy constructor
- Assignment operator
- Orthodox canonical form
- Fixed-point arithmetic

**Exercises:**
- Fixed point number class
- Operator overloading implementation

### CPP Module 03 - Inheritance
**Topics Covered:**
- Class inheritance
- Access specifiers (public, protected, private)
- Virtual functions introduction
- Diamond problem basics

**Exercises:**
- ClapTrap hierarchy
- ScavTrap and FragTrap classes
- DiamondTrap (virtual inheritance)

### CPP Module 04 - Subtype Polymorphism, Abstract Classes
**Topics Covered:**
- Pure virtual functions
- Abstract base classes
- Polymorphism and virtual function tables
- Interface design

**Exercises:**
- Animal hierarchy with polymorphism
- Abstract Brain class
- Deep copy implementation

### CPP Module 05 - Repetition, Exceptions
**Topics Covered:**
- Exception handling (try/catch/throw)
- Custom exception classes
- Exception safety guarantees
- RAII principles

**Exercises:**
- Bureaucrat class with exceptions
- Form hierarchy
- Exception propagation

### CPP Module 06 - C++ Casts
**Topics Covered:**
- Static cast
- Dynamic cast
- Const cast
- Reinterpret cast
- Type conversion and casting

**Exercises:**
- Scalar conversion
- Serialization/deserialization
- Type identification

### CPP Module 07 - C++ Templates
**Topics Covered:**
- Function templates
- Class templates
- Template specialization
- STL introduction

**Exercises:**
- Generic functions (swap, min, max)
- Array template class
- Iterator implementation

### CPP Module 08 - Templated Containers, Iterators, Algorithms
**Topics Covered:**
- STL containers (vector, list, stack, etc.)
- Iterators and their categories
- STL algorithms
- Template metaprogramming basics

**Exercises:**
- Easy find algorithm
- Span container
- Longest span calculation

### CPP Module 09 - STL
**Topics Covered:**
- Advanced STL usage
- Container adapters
- Algorithm complexity
- Real-world STL applications

**Exercises:**
- Bitcoin exchange calculator
- Reverse Polish Notation calculator
- Ford-Johnson merge insertion sort

## Compilation

Each module contains its own Makefile:

```bash
cd cpp0X/exXX
make
```

## General Usage

1. Clone the repository:
```bash
git clone https://github.com/bratzwitch/CPP_modules.git
cd CPP_modules
```

2. Navigate to specific module:
```bash
cd cpp01/ex00
```

3. Compile and run:
```bash
make
./program_name [arguments]
```

## Code Standards

### Orthodox Canonical Form
All classes follow the Orthodox Canonical Form when applicable:

```cpp
class MyClass {
private:
    // Private members

public:
    // Default constructor
    MyClass();
    
    // Copy constructor
    MyClass(const MyClass& other);
    
    // Assignment operator
    MyClass& operator=(const MyClass& other);
    
    // Destructor
    ~MyClass();
    
    // Other member functions
};
```

### Example Implementation

**CPP00 - PhoneBook Class:**
```cpp
class Contact {
private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

public:
    Contact();
    ~Contact();
    
    void setContact(void);
    void displayContact(int index) const;
    void displayFullContact(void) const;
};

class PhoneBook {
private:
    Contact contacts[8];
    int currentIndex;
    int contactCount;

public:
    PhoneBook();
    ~PhoneBook();
    
    void addContact(void);
    void searchContact(void) const;
    void displayContacts(void) const;
};
```

**CPP02 - Fixed Point Class:**
```cpp
class Fixed {
private:
    int value;
    static const int fractionalBits = 8;

public:
    Fixed();
    Fixed(const int n);
    Fixed(const float f);
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);
    ~Fixed();
    
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;
    
    // Arithmetic operators
    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;
    
    // Comparison operators
    bool operator>(const Fixed& other) const;
    bool operator<(const Fixed& other) const;
    bool operator>=(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;
    bool operator==(const Fixed& other) const;
    bool operator!=(const Fixed& other) const;
    
    // Increment/decrement operators
    Fixed& operator++();      // Pre-increment
    Fixed operator++(int);    // Post-increment
    Fixed& operator--();      // Pre-decrement
    Fixed operator--(int);    // Post-decrement
    
    static Fixed& min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);
```

## Key Learning Outcomes

### Module 00-01: Fundamentals
- Basic C++ syntax and compilation
- Class design and encapsulation
- Memory management principles
- Difference between stack and heap

### Module 02-03: OOP Principles
- Operator overloading design patterns
- Inheritance hierarchies
- Access control mechanisms
- Virtual function basics

### Module 04-05: Advanced OOP
- Abstract classes and interfaces
- Polymorphism implementation
- Exception handling strategies
- RAII and resource management

### Module 06-07: Generic Programming
- Type conversion and casting
- Template programming
- Generic algorithm design
- Code reusability principles

### Module 08-09: STL Mastery
- Container selection criteria
- Iterator design patterns
- Algorithm complexity analysis
- Standard library best practices

## File Structure

```
CPP_modules/
├── cpp00/
│   ├── ex00/          # Megaphone
│   ├── ex01/          # PhoneBook
│   └── ex02/          # Account (if exists)
├── cpp01/
│   ├── ex00/          # BraiiiiiiinnnzzzZ
│   ├── ex01/          # Moar brainz!
│   ├── ex02/          # HI THIS IS BRAIN
│   ├── ex03/          # Unnecessary violence
│   ├── ex04/          # Sed is for losers
│   ├── ex05/          # Harl 2.0
│   └── ex06/          # Harl filter
├── cpp02/
│   ├── ex00/          # Fixed point
│   ├── ex01/          # Towards useful fixed point
│   ├── ex02/          # Operator overloading
│   └── ex03/          # BSP (Point in triangle)
└── ...continuing for cpp03-cpp09
```

## Common Patterns and Best Practices

### RAII (Resource Acquisition Is Initialization)
```cpp
class FileHandler {
private:
    std::fstream file;

public:
    FileHandler(const std::string& filename) : file(filename) {
        if (!file.is_open())
            throw std::runtime_error("Failed to open file");
    }
    
    ~FileHandler() {
        if (file.is_open())
            file.close();
    }
    
    // Disable copy operations for resource safety
    FileHandler(const FileHandler&) = delete;
    FileHandler& operator=(const FileHandler&) = delete;
};
```

### Exception Safety
```cpp
class SafeContainer {
private:
    int* data;
    size_t size;

public:
    void push_back(int value) {
        int* newData = new int[size + 1];  // May throw
        
        // Copy existing data (no-throw operations)
        for (size_t i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        newData[size] = value;
        
        // Commit the changes (no-throw)
        delete[] data;
        data = newData;
        ++size;
    }
};
```

## Requirements

- **C++98 standard**: All code must compile with C++98
- **GCC/Clang**: Modern C++ compiler
- **Make**: Build system
- **No STL**: Until explicitly allowed in later modules

## Compilation Flags

```bash
c++ -Wall -Wextra -Werror -std=c++98 *.cpp -o program_name
```

## Testing Strategies

### Unit Testing Example
```cpp
// Test for Fixed class
void testFixedArithmetic() {
    Fixed a(10.5f);
    Fixed b(2.25f);
    
    Fixed sum = a + b;
    assert(sum.toFloat() == 12.75f);
    
    Fixed product = a * b;
    assert(abs(product.toFloat() - 23.625f) < 0.01f);
}
```

### Memory Testing
```bash
# Check for memory leaks
valgrind --leak-check=full ./program_name

# Check for undefined behavior
valgrind --tool=memcheck ./program_name
```

## Common Pitfalls and Solutions

1. **Memory Leaks**: Always pair new/delete, prefer RAII
2. **Shallow Copy**: Implement proper copy constructor for dynamic memory
3. **Dangling Pointers**: Set pointers to nullptr after delete
4. **Exception Safety**: Use RAII and commit-or-rollback patterns
5. **Template Compilation**: Implement templates in header files

## Author

Viacheslav Moroz - 42 Student
