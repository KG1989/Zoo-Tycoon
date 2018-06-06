#include "Turtle.hpp"

Turtle::Turtle()
{
	//setAge(0);
	setBaseFoodCost(getBaseFoodCost()/2);
	setCost(100);
	setNumberOfBabies(10);
	setPayoff(getCost()/20);
}

