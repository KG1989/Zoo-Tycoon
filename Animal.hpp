#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>
using std::cout;
using std::endl;

class Animal
{
protected:
	int age;
	int cost;
	int numberOfBabies;
	int baseFoodCost = 10;
	int payoff;
public:
	Animal();
	void setAge(int);	//use this
	int getAge();		//returns
	void setCost(int);
	int getCost() const;
	void setNumberOfBabies(int);
	int getNumberOfBabies();
	void setBaseFoodCost(int);
	int getBaseFoodCost();
	void setPayoff(int);
	int getPayoff();
	void nextDay();
	std::string toString() const;
};

#endif	
