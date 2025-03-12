#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {
    private:
        std::string ideas[100];
    public:
        Brain();
        Brain(const Brain &copy);
        ~Brain();
        Brain& operator=(const Brain& copy);
        void createIdea(int i,const std::string &idea);
        std::string getIdea(int i) const;
};

#endif