#include "Tiger.hpp"

Tiger::Tiger()
{
	//setAge(0);
	setBaseFoodCost(getBaseFoodCost()*5);
	setCost(10000);
	setNumberOfBabies(1);
	setPayoff(getCost()/5);
}

