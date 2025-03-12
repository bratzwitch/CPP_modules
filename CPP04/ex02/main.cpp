#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"


int main() 
{
    // const Animal* meta = new Animal(); 
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << "\n" << std::endl;
    std::cout << j->getType() << std::endl;
    std::cout << i->getType() << std::endl;
    std::cout << "\n" << std::endl;
    i->makeSound();
    j->makeSound();
    std::cout << "\n" << std::endl;
    delete j;
    delete i;
    return 0;
}