#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    private:
        std::string name;
        unsigned int         HitPoints;
        int         EnergyPoints;
        int         AttackDamage;
    public:
        ScavTrap(std::string name);
        ScavTrap(const ClapTrap &other);
        ScavTrap& operator=(const ScavTrap &other);
        ~ScavTrap();
        void attack(const std::string& target);
        void guardGate();

};
#endif
