# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include "DiamondTrap.hpp"


int main(void)
{
    DiamondTrap TheDoctor("The Doctor ");
    DiamondTrap Cybermen("Cybermen ");
    DiamondTrap Dalek("Dalek ");
    DiamondTrap Potts(Cybermen);
    
    std::cout << "-------------------" << std::endl;
    TheDoctor.whoAmI();
    std::cout << "-------------------" << std::endl;
    Cybermen.whoAmI();
    std::cout << "-------------------" << std::endl;
    Dalek.whoAmI();
    std::cout << "-------------------" << std::endl;
    std::cout << "-------------------" << std::endl;
    Potts.whoAmI();
    std::cout << "-------------------" << std::endl;
    Potts = Dalek;
    Potts.whoAmI();
    std::cout << "-------------------" << std::endl;
    std::cout << "-------------------" << std::endl;
    std::cout << "-------------------" << std::endl;

    TheDoctor.attack("Dalek");
    std::cout << "-------------------" << std::endl;
    Dalek.takeDamage(TheDoctor.get_attack_damage());
    std::cout << "-------------------" << std::endl;
    Dalek.beRepaired(5);
    std::cout << "-------------------" << std::endl;
    TheDoctor.attack("Cybermen");
    std::cout << "-------------------" << std::endl;
    Cybermen.takeDamage(TheDoctor.get_attack_damage());


    return (0);
}