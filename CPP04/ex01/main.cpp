#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int	main(void)
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;
    delete i;

    Animal* zoo[10];
    for(int i = 0;i < 10;i++)
    {
        if(i % 2 == 0)
	        zoo[i] = new Cat();
        else
            zoo[i] = new Dog();
    }
    for(int i = 0;i < 10;i++)
    {
        std::cout << zoo[i]->getType() << " " << std::endl;
        zoo[i]->makeSound();
    }
    Cat cat;
    Cat cato;
    cat.createIdea(1,"hello im cat probably");
    cat.createIdea(2,"or not?");
    cato = cat;
    std::cout << "First cat idea: " << cat.getIdea(1) << std::endl;
    std::cout << "First cato idea: " << cato.getIdea(1) << std::endl;
    std::cout << "Second cat idea: " << cat.getIdea(2) << std::endl;
    std::cout << "Second cato idea: " << cato.getIdea(2) << std::endl;
    cato.createIdea(1,"am i catodog?");
    cato.createIdea(2,"or am i dogocat?");
    std::cout << "First cat idea: " << cat.getIdea(1) << std::endl;
    std::cout << "First cato idea: " << cato.getIdea(1) << std::endl;
    std::cout << "Second cat idea: " << cat.getIdea(2) << std::endl;
    std::cout << "Second cato idea: " << cato.getIdea(2) << std::endl;
    cat = cato;
    std::cout << "First cat idea: " << cat.getIdea(1) << std::endl;
    std::cout << "First cato idea: " << cato.getIdea(1) << std::endl;
    std::cout << "Second cat idea: " << cat.getIdea(2) << std::endl;
    std::cout << "Second cato idea: " << cato.getIdea(2) << std::endl;
    for(int i = 0;i < 10;i++)
	    delete zoo[i];
	return (0);
}