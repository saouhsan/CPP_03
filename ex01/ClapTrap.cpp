#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _hit_pts(10), _energy_pts(10), _attack_damage(0) {
	std::cout << BOLDGREEN << "Default Constructor Called" << RESET << std::endl;
    return ;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_pts(10), _energy_pts(10), _attack_damage(0) {
	std::cout << GREEN << "Parametric Constructor Called" << RESET << std::endl;
	return ;
}

ClapTrap::ClapTrap(ClapTrap const &src) : _name(src._name) {
	std::cout << GREEN << "Copy Constructor Called" << RESET << std::endl;
	*this = src;
	return ;
}

ClapTrap::~ClapTrap(void) {
	std::cout << BOLDRED << "Destructor Called" << RESET << std::endl;
	return ;
}

ClapTrap&	ClapTrap::operator=(ClapTrap const &rhs) {

	std::cout << GREEN << "Copy Assignement Operator Called" << RESET << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs.get_name();
		this->_hit_pts = rhs._hit_pts;
		this->_energy_pts = rhs._energy_pts;
		this->_attack_damage = rhs._attack_damage;
	}
	return (*this);
}

void		ClapTrap::set_name(std::string name){
    this->_name = name;
    return;
}

std::string	ClapTrap::get_name(void) const {
	return (this->_name);
}

unsigned int		ClapTrap::get_health(void) const{
    return (this->_hit_pts);
}

unsigned int		ClapTrap::get_energy_pts(void) const{
    return (this->_energy_pts);
}

unsigned int		ClapTrap::get_attack_damage(void) const{
    return (this->_attack_damage);
}

void		ClapTrap::attack(const std::string& target){
    if (get_energy_pts() <= 0 || get_health() <= 0)
    {
        std::cout << RED << "ClapTrap " << this->_name << "cannot attack." <<std::endl;
        if(get_health() <= 0)
            std::cout << "ClapTrap " << this->_name << "is dead!" << RESET <<std::endl;
        if(get_energy_pts() <= 0)
            std::cout << "ClapTrap " << this->_name << "is exhausted!" << RESET <<std::endl;
        return;
    }
    this->_energy_pts -= 1;
    std::cout << "ClapTrap " << this->_name << "attacks " << target << " causing " << this-> _attack_damage << " points of damage!" <<std::endl;
    if (get_health() <= 0)
    {
        std::cout << RED << "ClapTrap " << this->_name << "died while striking an enemy." << RESET <<std::endl;
        return;
    }
    std::cout << "ClapTrap " << this->_name << "lost 1 energy pts." << std::endl;
    std::cout << YELLOW << "ClapTrap " << this->_name << "has " << this-> _energy_pts << " energy point left." << RESET << std::endl;
}

void		ClapTrap::takeDamage(unsigned int amount){
    if(get_health() <= 0){
        std::cout << RED << "ClapTrap " << this->_name << "is already dead!" << RESET <<std::endl;
        return;
    }
    if(get_health() <= amount)
    {
        this->_hit_pts = 0;
        std::cout << RED << "ClapTrap " << this->_name << "is dead!" << RESET <<std::endl;
        return;
    }
    this->_hit_pts -= amount;
    std::cout << "ClapTrap " << this->_name << "has been attacked." << std::endl;
    std::cout << "ClapTrap " << this->_name << "lost " << amount << " hit (life) points." << std::endl;
    std::cout << YELLOW << "ClapTrap " << this->_name << "has " << this-> _hit_pts << " hit (life) point left." << RESET << std::endl;
    return;
}

void		ClapTrap::beRepaired(unsigned int amount){
    if (get_energy_pts() <= 0 || get_health() <= 0)
    {
        if(get_health() <= 0){
            std::cout << RED << "ClapTrap " << this->_name << "is already dead!" << RESET <<std::endl;
            return;
        }
        std::cout << RED << "ClapTrap " << this->_name << "is exhausted!" << std::endl;
        std::cout << "ClapTrap " << this->_name << "cannot repair itself without energy points." << RESET <<std::endl;
        return;
    }
    this->_hit_pts += amount;
    if(this->_hit_pts > 10)
        this->_hit_pts = 10;
    this->_energy_pts -=1;
    std::cout << GREEN << "ClapTrap " << this->_name << "gained " << amount << " hit (life) point back." << RESET << std::endl;
    std::cout << YELLOW << "ClapTrap " << this->_name << "has " << this-> _hit_pts << " hit (life) point now." << RESET << std::endl;
    std::cout << "ClapTrap " << this->_name << "lost 1 energy pts." << std::endl;
    std::cout << YELLOW << "ClapTrap " << this->_name << "has " << this-> _energy_pts << " energy point left." << RESET << std::endl;
    return;
}
