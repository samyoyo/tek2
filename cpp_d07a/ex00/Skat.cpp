//
// Skat.cpp for Skat in /home/guillaume2.roux/rendu/cpp_d07a/ex00
// 
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
// 
// Started on  Tue Jan 10 16:12:42 2017 Guillaume Roux
// Last update Tue Jan 10 16:12:42 2017 Guillaume Roux
//

#include "Skat.h"

Skat::Skat(std::string const& name, int stimPaks) : _name(name), _stimPaks(stimPaks)
{

}

Skat::~Skat()
{

}

int&	Skat::stimPaks()
{
	return (this->_stimPaks);
}

std::string const&	Skat::name()
{
	return (this->_name);
}

void	Skat::shareStimPaks(int number, int&	stock)
{
	if (this->_stimPaks >= number)
	{
		stock += number;
		this->_stimPaks -= number;
		std::cout << "Keep the change." << std::endl;
	}
	else
		std::cout << "Don't be greedy" << std::endl;
}
	
void	Skat::addStimPaks(unsigned int number)
{
	if (number == 0)
		std::cout << "Hey boya, did you forget something ?" << std::endl;
	else
		this->_stimPaks += number;
}
	
void	Skat::useStimPaks()
{
	if (this->_stimPaks > 0)
	{
		this->_stimPaks--;
		std::cout << "Time to kick some ass and chew bubble gum." << std::endl;
	}
	else
		std::cout << "Mediiiiiic" << std::endl;
}

void	Skat::status() const
{
	std::cout << "Soldier " << this->_name << " reporting " << this->_stimPaks << " stimpaks remaining sir !" << std::endl;
}