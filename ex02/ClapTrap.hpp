#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"

#define BOLDRED     "\033[1m\033[31m"
#define BOLDGREEN   "\033[1m\033[32m"
#define BOLDYELLOW  "\033[1m\033[33m"

class ClapTrap
{
	protected :
		std::string 	_name;
		unsigned int	_hit_pts; // health of the ClapTrap
		unsigned int	_energy_pts;
		unsigned int	_attack_damage;

	public :
		ClapTrap(void); // default constructor
		ClapTrap(ClapTrap const &src); //copy constructor (const prevent modification to src)
		ClapTrap(std::string name); // parameterized constructor
	
		~ClapTrap(void); //destuctor
		// OPPERATOR OVERLOAD
		// ASSIGNMENT OPERATOR
		/* Update current object (cannot be const) with rhs param*/
		ClapTrap&	operator=(ClapTrap const &rhs); // return REF to make it possible to write a = b = c = d, built-in operators allow that
        /* Here REF is return (current object updated), otherwise otherwise a simple copy is returned
            const on rhs prevent modification to src*/
	
		void		attack(const std::string& target); // -1 _energy_pts
		void		takeDamage(unsigned int amount); // -amount _hit_pts
		void		beRepaired(unsigned int amount); // -1 _energy_pts

		void				set_name(std::string name);
		std::string			get_name(void) const;
		unsigned int		get_health(void) const;
		unsigned int		get_energy_pts(void) const;
		unsigned int		get_attack_damage(void) const;

};

#endif