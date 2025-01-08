#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap Random;
    ClapTrap TheDoctor("The Doctor ");
    ClapTrap Dalek("Dalek ");
    ClapTrap Cybermen("Cybermen ");

    Random.attack("Dalek");
    Dalek.takeDamage(2);
    std::cout << std::endl;

    Dalek.attack("The Doctor");
    TheDoctor.takeDamage(5);
    std::cout << std::endl;

    Cybermen.attack("Dalek");
    Dalek.takeDamage(6);
    std::cout << std::endl;

    Cybermen.attack("The Doctor");
    TheDoctor.takeDamage(4);
    std::cout << std::endl;

    TheDoctor.beRepaired(6);
    std::cout << std::endl;

    TheDoctor.beRepaired(6);
    std::cout << std::endl;

    TheDoctor.attack("Dalek");
    Dalek.takeDamage(10);
    std::cout << std::endl;

    TheDoctor.attack("Cybermen");
    Cybermen.takeDamage(10);

    return (0);
}