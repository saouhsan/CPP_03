#include "ClapTrap.hpp"
# include "ScavTrap.hpp"

int main(void)
{
    ScavTrap TheDoctor("The Doctor ");
    ScavTrap Cybermen("Cybermen ");
    ClapTrap Dalek("Dalek ");


    TheDoctor.attack("Dalek");
    Dalek.takeDamage(TheDoctor.get_attack_damage());

    Dalek.beRepaired(5);

    TheDoctor.attack("Cybermen");
    Cybermen.takeDamage(TheDoctor.get_attack_damage());

    TheDoctor.guardGate();
    Cybermen.attack("The Doctor");
    TheDoctor.takeDamage(Cybermen.get_attack_damage());
    TheDoctor.beRepaired(12);

   // Dalek.guardGate();

    return (0);
}