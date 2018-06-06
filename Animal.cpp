#include "Animal.hpp"


Animal::Animal()
{
	setAge(age);
	setCost(cost);
	setBaseFoodCost(baseFoodCost);
	setPayoff(payoff);
	setNumberOfBabies(numberOfBabies);
}
void Animal::setAge(int age)
{
	this->age = age;
}
int Animal::getAge()
{
	return age;
}
void Animal::setCost(int cost)
{
	this->cost = cost;
}
int Animal::getCost() const
{
	return cost;
}
void Animal::setNumberOfBabies(int numberOfbabies)
{
	this->numberOfBabies = numberOfBabies;
}
int Animal::getNumberOfBabies()
{
	return numberOfBabies;
}
void Animal::setBaseFoodCost(int baseFoodCost)
{
	this->baseFoodCost = baseFoodCost;
}
int Animal::getBaseFoodCost()
{
	return baseFoodCost;
}
void Animal::setPayoff(int payoff)
{
	this->payoff = payoff;
}
int Animal::getPayoff()
{
	return payoff;
}
void Animal::nextDay()
{
	//age all the animals
	age++;
}
std::string Animal::toString() const
{
	return "Age: " + std::to_string(this->age);
}