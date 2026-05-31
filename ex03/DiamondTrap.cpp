#include "DiamondTrap.hpp"


DiamondTrap::DiamondTrap(std::string Name) : ClapTrap(Name + "_clap_name"), ScavTrap(Name), FragTrap(Name) 
{
    name = Name;
    this->HitPoints = FragTrap::HitPoints;
    this->EnergyPoints = ScavTrap::EnergyPoints;
    this->AttackDamage = FragTrap::AttackDamage;
    std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), ScavTrap(other), FragTrap(other)
{
    this->HitPoints = 100;
    this->EnergyPoints = 100;
    this->AttackDamage = 30;
    std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &other)
{
    std::cout << "DiamondTrap copy assignment operator called" << std::endl;
    if (this != &other)
    {
        ClapTrap::operator=(other);
        this->HitPoints = 100;
        this->EnergyPoints = 100;
        this->AttackDamage = 30;
    }
    return (*this);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap default destructor called" << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
    if (this->EnergyPoints > 0 && this->HitPoints > 0)
    {
        this->EnergyPoints -= 1;
        std::cout << "Frag Trap " << this->name << " attacks " << target << ", causing " << this->AttackDamage << " points of damage!" << std::endl;
    }
    else
        std::cout << "Frag Trap doesn't have enough power to attack." << std::endl;
    std::cout << "Frag Trap " << this->name << " has now " << this->EnergyPoints <<  " energy points." << std::endl;
    
}

void DiamondTrap::whoAmI()
{
    std::cout << "Hey guys, my name is " << name << " and my ClapTrap name is " << ClapTrap::name << "!" << std::endl;
}