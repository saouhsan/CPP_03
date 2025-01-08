#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"


class DiamondTrap : virtual public FragTrap, virtual public ScavTrap
{
    private:
		std::string 	_name;

	public:
		DiamondTrap(void);
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap const &src);
		~DiamondTrap(void);

		DiamondTrap& operator=(DiamondTrap const &src);

		void attack(const std::string& target);
        void whoAmI();
};

#endif