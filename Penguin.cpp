#include "Penguin.hpp"

Penguin::Penguin()
{
	//setAge(0);
	setBaseFoodCost(getBaseFoodCost());
	setCost(1000);
	setNumberOfBabies(5);
	setPayoff(getCost()/10.0);
}


