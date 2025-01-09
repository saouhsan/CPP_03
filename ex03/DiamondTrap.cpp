#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void): ClapTrap("Basic_clap_name"), ScavTrap("Basic"), FragTrap("Basic"){
	std::cout << BOLDGREEN << "DiamondTrap Constructor Called" << RESET << std::endl;
	this->_name = "Basic";
	this->_hit_pts = FragTrap::get_health();
	this->_energy_pts = ScavTrap::get_energy_pts();
	this->_attack_damage =  FragTrap::get_attack_damage();
	return ;
}

DiamondTrap::DiamondTrap(std::string name):ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name){
	std::cout << BOLDGREEN <<"DiamondTrap Parametric Constructor Called" << RESET << std::endl;
	this->_name = name;
	this->_hit_pts = FragTrap::get_health();
	this->_energy_pts = ScavTrap::get_energy_pts();
	this->_attack_damage =  FragTrap::get_attack_damage();
	return ;
}

DiamondTrap::DiamondTrap(DiamondTrap const &src):ClapTrap(src._name){
	std::cout << GREEN << "DiamondTrap Copy Constructor Called" << RESET << std::endl;
	*this = src;
	return ;
}

DiamondTrap::~DiamondTrap(void){
	std::cout << BOLDRED << "DiamondTrap Destructor Called" << RESET << std::endl;
	return ;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap const &rhs){
	std::cout << GREEN << "Diamond Copy Assignement Operator Called" << RESET << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hit_pts = rhs.FragTrap::_hit_pts;
		this->_energy_pts = rhs.ScavTrap::_energy_pts;
		this->_attack_damage = rhs.FragTrap::_attack_damage;
		this->ClapTrap::_name = rhs.ClapTrap::_name;
	}
	return (*this);
}

void DiamondTrap::attack(const std::string& target){
	ScavTrap::attack(target);
	return;
}

void DiamondTrap::whoAmI(void){
	std::cout << "I am a DiamondTrap! My name is " << this->_name <<  std::endl;
	std::cout << "My ClapTrap name is " << ClapTrap::_name <<  std::endl;
	return;
}
