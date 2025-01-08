#include "FragTrap.hpp"

FragTrap::FragTrap(void): ClapTrap(){
    this->_name = "";
	this->_hit_pts = 100;
	this->_energy_pts = 100;
	this->_attack_damage = 30;
	std::cout << BOLDGREEN <<"FragTrap Default Constructor Called" << RESET << std::endl;
	return ;
}

FragTrap::FragTrap(std::string name): ClapTrap(name){
    this->_name = name;
	this->_hit_pts = 100;
	this->_energy_pts = 100;
	this->_attack_damage = 30;
	std::cout << BOLDGREEN <<"FragTrap Parametric Constructor Called" << RESET << std::endl;
	return ;
}

FragTrap::FragTrap(FragTrap const &src): ClapTrap(){
	std::cout << GREEN << "FragTrap Copy Constructor Called" << RESET << std::endl;
	*this = src;
	return ;
}

FragTrap::~FragTrap(void){
	std::cout << BOLDRED << "FragTrap Destructor Called" << RESET << std::endl;
	return ;
}


FragTrap& FragTrap::operator=(FragTrap const &rhs){
	std::cout << GREEN << "FragTrap Copy Assignement Operator Called" << RESET << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs.get_name();
		this->_hit_pts = rhs._hit_pts;
		this->_energy_pts = rhs._energy_pts;
		this->_attack_damage = rhs._attack_damage;
	}
	return (*this);
}

void FragTrap::attack(const std::string& target){
    if (get_energy_pts() <= 0 || get_health() <= 0)
    {
        std::cout << RED << "FragTrap " << this->_name << "cannot attack." <<std::endl;
        if(get_health() <= 0)
            std::cout << "FragTrap " << this->_name << "is dead!" << RESET <<std::endl;
        if(get_energy_pts() <= 0)
            std::cout << "FragTrap " << this->_name << "is exhausted!" << RESET <<std::endl;
        return;
    }
    this->_energy_pts -= 1;
    std::cout << "FragTrap " << this->_name << "attacks " << target << " causing " << this-> _attack_damage << " points of damage!" <<std::endl;
    if (get_health() <= 0)
    {
        std::cout << RED << "FragTrap " << this->_name << "died while striking an enemy." << RESET <<std::endl;
        return;
    }
    std::cout << "FragTrap " << this->_name << "lost 1 energy pts." << std::endl;
    std::cout << YELLOW << "FragTrap " << this->_name << "has " << this-> _energy_pts << " energy point left." << RESET << std::endl;
}

void    FragTrap::highFivesGuys(void){
    if(get_health() > 0)
    {
        std::cout << GREEN << "FragTrap " << this->_name << " wants a high five ..." << RESET << std::endl;
        return;
    }
    std::cout << RED << "FragTrap " << this->_name << "is dead!" << RESET <<std::endl;
    return;
}