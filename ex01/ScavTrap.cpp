#include "ScavTrap.hpp"


ScavTrap::ScavTrap(std::string Name) : name(Name), HitPoints(100), EnergyPoints(50), AttackDamage(20) 
{
    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ClapTrap &other) : name(other.name), HitPoints(other.HitPoints), EnergyPoints(other.EnergyPoints), AttackDamage(other.AttackDamage) 
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other)
{
    std::cout << "ScavTrap copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->name = other.name;
        this->HitPoints = other.HitPoints;
        this->EnergyPoints = other.EnergyPoints;
        this->AttackDamage = other.AttackDamage;
    }
    return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap default destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (this->EnergyPoints > 0 && this->HitPoints > 0)
    {
        this->EnergyPoints -= 1;
        std::cout << "Clap Trap " << this->name << " attacks " << target << ", causing " << this->AttackDamage << " points of damage!" << std::endl;
    }
    else
        std::cout << "Clap Trap doesn't have enough power to attack." << std::endl;
    std::cout << "Clap Trap " << this->name << " has now " << this->EnergyPoints <<  " energy points." << std::endl;
    
}
void ScavTrap::ClapTrap::takeDamage(unsigned int amount)
{
    this->HitPoints -= amount;
    std::cout << "Clap Trap " << this->name << " has taken damage. Its Hit points are now " << this->HitPoints << std::endl;
}
void ScavTrap::ClapTrap::beRepaired(unsigned int amount)
{
    this->HitPoints += amount;
    std::cout << "Clap Trap " << this->name << " is being repared by " << this->HitPoints << " points." << std::endl;
}