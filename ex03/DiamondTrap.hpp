#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

#include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"

#define BOLDRED     "\033[1m\033[31m"
#define BOLDGREEN   "\033[1m\033[32m"
#define BOLDYELLOW  "\033[1m\033[33m"

/*
	- "diamond problem”: multiple inheritance where a derived class inherits from
		two or more base classes that have a common base class.
	- C++ provides virtual inheritance. Itensures that the derived class has only
		one instance of the common base class, which is shared by all derived classes.
	- This ensures that the derived class does not inherit duplicate copies of the
		common base class, thus resolving the diamond problem.

	- Here DiamondTrap inherit from FragTrap & ScavTrap both of which inherit from
		ClapTrap
		Virtual makes sure that DiamondTrap has only one instance of ClapTrap
*/

class DiamondTrap : public FragTrap, public ScavTrap
{
    private:
		std::string 	_name;

	public:
		DiamondTrap(void);
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap const &src);
		~DiamondTrap(void);

		DiamondTrap& operator=(DiamondTrap const &rhs);

		void attack(const std::string& target);
        void whoAmI(void);
};

#endif