#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    const WrongAnimal* main = new WrongAnimal();
    const WrongAnimal* cato = new WrongCat();
    std::cout << "Animal meta type: " << meta->getType() << " " << std::endl;
    std::cout << "Animal i type: " << i->getType() << " " << std::endl;
    std::cout << "Animal j type: " << j->getType() << " " << std::endl;
    std::cout << "Animal main type: " << main->getType() << " " << std::endl;
    std::cout << "Animal cato type: " << cato->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();
    cato->makeSound();
    main->makeSound();

    delete meta;
    delete i;
    delete j;
    delete main;
    delete cato;
	return (0);
}