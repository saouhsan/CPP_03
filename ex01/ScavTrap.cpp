# include "ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap(){
    this->_name = "";
	this->_hit_pts = 100;
	this->_energy_pts = 50;
	this->_attack_damage = 20;
	std::cout << BOLDGREEN <<"ScavTrap Default Constructor Called" << RESET << std::endl;
	return ;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name){
    this->_name = name;
	this->_hit_pts = 100;
	this->_energy_pts = 50;
	this->_attack_damage = 20;
	std::cout << BOLDGREEN <<"ScavTrap Parametric Constructor Called" << RESET << std::endl;
	return ;
}

ScavTrap::ScavTrap(ScavTrap const &src): ClapTrap(){
	std::cout << GREEN << "ScavTrap Copy Constructor Called" << RESET << std::endl;
	*this = src;
	return ;
}

ScavTrap::~ScavTrap(void){
	std::cout << BOLDRED << "ScavTrap Destructor Called" << RESET << std::endl;
	return ;
}


ScavTrap& ScavTrap::operator=(ScavTrap const &rhs){
	std::cout << GREEN << "ScavTrap Copy Assignement Operator Called" << RESET << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs.get_name();
		this->_hit_pts = rhs._hit_pts;
		this->_energy_pts = rhs._energy_pts;
		this->_attack_damage = rhs._attack_damage;
	}
	return (*this);
}


void ScavTrap::attack(const std::string& target){
    if (get_energy_pts() <= 0 || get_health() <= 0)
    {
        std::cout << RED << "ScavTrap " << this->_name << "cannot attack." <<std::endl;
        if(get_health() <= 0)
            std::cout << "ScavTrap " << this->_name << "is dead!" << RESET <<std::endl;
        if(get_energy_pts() <= 0)
            std::cout << "ScavTrap " << this->_name << "is exhausted!" << RESET <<std::endl;
        return;
    }
    this->_energy_pts -= 1;
    std::cout << "ScavTrap " << this->_name << "attacks " << target << " causing " << this-> _attack_damage << " points of damage!" <<std::endl;
    if (get_health() <= 0)
    {
        std::cout << RED << "ScavTrap " << this->_name << "died while striking an enemy." << RESET <<std::endl;
        return;
    }
    std::cout << "ScavTrap " << this->_name << "lost 1 energy pts." << std::endl;
    std::cout << YELLOW << "ScavTrap " << this->_name << "has " << this-> _energy_pts << " energy point left." << RESET << std::endl;
}

void ScavTrap::guardGate(void){
    if(get_health() > 0)
    {
        std::cout << GREEN << "ScavTrap " << this->_name << " is now in Gate keeper mode" << RESET << std::endl;
        return;
    }
            
    std::cout << RED << "ScavTrap " << this->_name << "is dead!" << RESET <<std::endl;
    return;
}
