/*
	SOURCES SITED:
	I used the following sources for assistance in this program.
	For resizing arrays, 2d array syntax, and deleting items, I used
	https://www.youtube.com/watch?v=AQAGQ7aTlHU 
*/

#ifndef ZOO_HPP
#define ZOO_HPP

#include <ctime>
#include <cstdlib>

#include "Penguin.hpp"
#include "Turtle.hpp"
#include "Tiger.hpp"
#include "Animal.hpp"

class Zoo
{
private:
	Turtle **turtles = new Turtle*[10];
	Penguin **penguins = new Penguin*[10];
	Tiger **tigers = new Tiger*[10];

	int turtCapacity; //size of array
	int turtElements; //number of turtles

	int tigCapacity;
	int tigElements;

	int pengCapacity;
	int pengElements;

	int adultTurtle = 0;
	int adultTiger = 0;
	int adultPenguin = 0;

	int bankSize = 100000; //cash money

	int tigerBonus;
public:
	Zoo();
	virtual ~Zoo();
	void intitialize(int);

	void expandTurtles();
	void expandTigers();
	void expandPenguins();

	void birthTiger();
	void birthTurtle();
	void birthPenguin();

	void addTurtObject(int);
	void addTigObject(int);
	void addPengObject(int);

	//these next functions are mainly for debugging
	//making sure I am actually adding the elements and all that
	inline const int& getTurtElements() const { return this->turtElements; }
	Turtle& getAtTurtle(int) const;
	inline const int& getTigElements() const { return this->tigElements; }
	Tiger& getAtTiger(int) const;
	inline const int& getPengElements() const { return this->pengElements; }
	Penguin& getAtPenguin(int) const;

	
	void getZooInfo();
	void startZoo();
	void increaseAge();
	int totalPayoff();
	void randomEvent();
	void killTiger();
	void killTurtle();
	void killPenguin();
	int totalFoodCost();
	//bool isAdult();
};


#endif
