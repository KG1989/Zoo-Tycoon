#include "Zoo.hpp"
#include "Util.hpp"


Zoo::Zoo()
{
	this->turtCapacity = 10;
	this->turtElements = 0;
	//this->turtles = new Turtle*[turtCapacity];

	this->tigCapacity = 10;
	this->tigElements = 0;
	//this->tigers = new Tiger*[tigCapacity];

	this->pengCapacity = 10;
	this->pengElements = 0;
	//this->penguins = new Penguin*[pengCapacity];
}
Zoo::~Zoo()
{
	for (int i = 0; i < this->turtElements; i++)
	{
		delete this->turtles[i];
	}
	delete this->turtles;

	for (int i = 0; i < this->tigElements; i++)
	{
		delete this->tigers[i];
	}
	delete this->tigers;

	for (int i = 0; i < this->pengElements; i++)
	{
		delete this->penguins[i];
	}
	delete this->penguins;
}

void Zoo::intitialize(int from)
{
	for (int i = from; i < this->turtCapacity; i++)
	{
		this->turtles[i] = NULL;
	}

	for (int i = from; i < this->tigCapacity; i++)
	{
		this->tigers[i] = NULL;
	}

	for (int i = from; i < this->pengCapacity; i++)
	{
		this->penguins[i] = NULL;
	}
}

void Zoo::expandTurtles()
{
	this->turtCapacity *= 2;
	Turtle **tempArr = new Turtle*[turtCapacity];

	for (size_t i = 0; i < this->turtElements; i++)
	{
		tempArr[i] = new Turtle(*turtles[i]);
	}

	for (size_t i = 0; i < turtElements; i++)
	{
		delete turtles[i];
	}

	delete[] turtles;
	turtles = tempArr;

	this->intitialize(this->turtElements);
}

void Zoo::expandTigers()
{
	this->tigCapacity *= 2;
	Tiger **tempArr = new Tiger*[tigCapacity];

	for (size_t i = 0; i < this->tigElements; i++)
	{
		tempArr[i] = new Tiger(*tigers[i]);
	}

	for (size_t i = 0; i < tigElements; i++)
	{
		delete tigers[i];
	}

	delete[] tigers;
	tigers = tempArr;

	this->intitialize(this->tigElements);
}

void Zoo::expandPenguins()
{
	this->pengCapacity *= 2;
	Penguin **tempArr = new Penguin*[pengCapacity];

	for (size_t i = 0; i < this->pengElements; i++)
	{
		tempArr[i] = new Penguin(*penguins[i]);
	}

	for (size_t i = 0; i < pengElements; i++)
	{
		delete penguins[i];
	}

	delete[] penguins;
	penguins = tempArr;

	this->intitialize(this->pengElements);
}

void Zoo::addTurtObject(int age)
{
	if (turtElements >= turtCapacity )
		expandTurtles();

	Turtle *turt = new Turtle;
	turt->setAge(age);

	turtles[turtElements++] = turt;
}

void Zoo::addTigObject(int age)
{
	if (tigElements >= tigCapacity)
		expandTigers();

	Tiger *tig = new Tiger;
	tig->setAge(age);

	tigers[tigElements++] = tig;
}
void Zoo::addPengObject(int age)
{
	if (pengElements >= pengCapacity)
		expandPenguins();

	Penguin *peng = new Penguin;
	peng->setAge(age);

	penguins[pengElements++] = peng;
}

Turtle& Zoo::getAtTurtle(int index) const
{
	if (index < 0 || index >= turtElements)
		throw "OUT OF BOUNDS EXCEPTION!";

	return *turtles[index];
}

Tiger& Zoo::getAtTiger(int index) const
{
	if (index < 0 || index >= tigElements)
		throw "OUT OF BOUNDS EXCEPTION!";

	return *tigers[index];
}

Penguin& Zoo::getAtPenguin(int index) const
{
	if (index < 0 || index >= pengElements)
		throw "OUT OF BOUNDS EXCEPTION!";

	return *penguins[index];
}

void Zoo::getZooInfo()
{
	int selectTiger = 0;
	int selectTurtle = 0;
	int selectPenguin = 0;
	std::string input;


	cout << "lets start with the tigers. Enter 1 to buy just 1 tiger, and enter 2 to buy 2 tigers. " << endl;
	selectTiger = getInt(input, 1, 2);

	if (selectTiger == 1)
	{
		addTigObject(0);
		
		for (int i = 0; i < tigElements; i++)
		{
			bankSize -= tigers[i]->getCost();
		}
		
	}

	if (selectTiger == 2)
	{
		addTigObject(0);
		addTigObject(0);
		//this wouldn't work for some reason!! needed to move on so I just hardcoded it
		for (int i = 0; i < tigElements; i++)
		{
			bankSize -= tigers[i]->getCost();
		}
		
		//bankSize -= tigers[0]->getCost();
		//bankSize -= 20000;
	}

	cout << "Now the turtles, how many little shell creatures would you like to buy? " << endl;
	selectTurtle = getInt(input, 1, 2);

	if (selectTurtle == 1)
	{
		addTurtObject(0);

		for (int i = 0; i < turtElements; i++)
		{
			bankSize -= turtles[i]->getCost();
		}
	}

	if (selectTurtle == 2)
	{
		addTurtObject(0);
		addTurtObject(0);
		for (int i = 0; i < turtElements; i++)
		{
			bankSize -= turtles[i]->getCost();
		}
	}

	cout << "Last but not least, the penguins. How many creatures from the frozen wastelands would you like to buy? " << endl;
	selectPenguin = getInt(input, 1, 2);

	if (selectPenguin == 1)
	{
		addPengObject(0);
		for (int i = 0; i < pengElements; i++)
		{
			bankSize -= penguins[i]->getCost();
		}
		
	}

	if (selectPenguin == 2)
	{
		addPengObject(0);
		addPengObject(0);
		for (int i = 0; i < pengElements; i++)
		{
			bankSize -= penguins[i]->getCost();
		}
	}
}

void Zoo::startZoo()
{
	std::string input;
	std::vector<std::string> vec;
	int selection = 0;
	int buyAdult = 0;
	/* debugging
	cout << tigElements << endl;
	cout << turtElements << endl;
	cout << pengElements << endl;*/
	//cout << tigers[1]->getNumberOfBabies();
	cout << "Have you ever wanted to own your own zoo?? Well now is your chance! " << endl
		<< "First you need some animals! You can buy tigers, penguins, and turtles, and you must " << endl
		<< "buy at least one of each, but you can alspo buy two if you nwould like. " << endl;

	getZooInfo();

	cout << "Enter 0 to view the menu, or 2 to quit right away. " << endl;

	while (selection != 2)
	{
		menu(selection, vec, "Press 1 to start the zoo simulation! ", "Press 2 to quit!");

		if (selection == 1)
		{
			
			// checking to see if any elements are in the arrays
			
			cout << "Animals and their ages. " << endl;
			
			for (int i = 0; i < getTigElements(); i++)
			{
				cout << "Tiger " << i+1 << " " << getAtTiger(i).toString() << endl;
			}
			

			for (int i = 0; i < getTurtElements(); i++)
			{
				cout << "Turtle " << i+1 << " " << getAtTurtle(i).toString() << endl;
			}

			for (int i = 0; i < getPengElements(); i++)
			{
				
				cout << "Penguin " << i+1 << " " << getAtPenguin(i).toString() << endl;
			}

			cout << "After buying the animals, this is how much money you have. " << endl;
			cout << bankSize << endl;

				increaseAge();

				randomEvent();

				bankSize += totalPayoff();
				bankSize -= totalFoodCost();
				cout << "Amount at the end of each day. " << endl;
				cout << bankSize << endl;

				cout << "Do you want to buy anymore adult animals? " << endl;
				cout << "Enter 1 to buy adult tiger, 2 to buy adult turtle, 3 to buy adult penguin " << endl
					<< " or 4 to not buy any more animals. " << endl;
				buyAdult = getInt(input, 0, 4);

				if (buyAdult == 1)
				{
					addTigObject(3);
					bankSize -= 10000;
				}
				else if (buyAdult == 2)
				{
					addTurtObject(3);
					bankSize -= 100;
				}
				else if (buyAdult == 3)
				{
					addPengObject(3);
					bankSize -= 1000;
				}
				else
					cout << "you chose not to buy any more animals. " << endl;

				cout << "would you like to play another day? Please press 0 to view the menu or 2 to quit. " << endl;
				menu(selection, vec, "Press 1 to go to the next day", "press 2 to exit. ");

			 //end bank while

		}//end selection if

	} //end selection while
}

void Zoo::increaseAge()
{
	//increase tiger age
	for (int i = 0; i < tigElements; i++)
	{
		tigers[i]->nextDay();
		//cout << tigers[i]->getAge() << endl;
	}
	//check for adult tiger
	for (int i = 0; i < getTigElements(); i++)
	{
		if (tigers[i]->getAge() >= 3)
		{
			adultTiger++;
		}
	}
	//increase turtle age
	for (int i = 0; i < turtElements; i++)
	{
		turtles[i]->nextDay();
		//cout << turtles[i]->getAge() << endl;
	}
	//check for adult turtle
	for (int i = 0; i < getTurtElements(); i++)
	{
		if (turtles[i]->getAge() >= 3)
		{
			adultTurtle++;
		}
	}
	//increase penguin age
	for (int i = 0; i < pengElements; i++)
	{
		penguins[i]->nextDay();
		//cout << penguins[i]->getAge() << endl;
	}
	//check for adult penguin
	for (int i = 0; i < getPengElements(); i++)
	{
		if (penguins[i]->getAge() >= 3)
		{
			adultPenguin++;
		}
	}
}

int Zoo::totalPayoff()
{
	int tigPayoffs = 0;
	int turtPayoffs = 0;
	int pengPayoffs = 0;
	int payoffs = 0;

	for (int i = 0; i < tigElements; i++)
	{
		tigPayoffs += tigers[i]->getPayoff();
	}

	for (int i = 0; i < turtElements; i++)
	{
		turtPayoffs += turtles[i]->getPayoff();
	}

	if (pengElements > 0)
	{
		for (int i = 0; i < pengElements; i++)
		{
			pengPayoffs += penguins[i]->getPayoff();
		}
	}

	payoffs = tigPayoffs + turtPayoffs + pengPayoffs + tigerBonus;
	
	return payoffs;
}
void Zoo::randomEvent()
{
	int ranEvent = 0;
	//random number between 1 and 4;
	enum ranAnimal { Tiger = 1, Turtle, Penguin };
	ranAnimal animalDeath;
	ranEvent = rand() % 4 + 1;
	/*
	used this for help with random enums
	http://www.cplusplus.com/forum/beginner/60374/
	used this for help with the random range 
	http://www.cplusplus.com/reference/cstdlib/rand/
	*/

	switch (ranEvent)
	{
	case 1: 
		cout << "random 1 happened. " << endl;
		animalDeath = (ranAnimal)((rand() % 3 + 1));
		if (turtElements > 0 || tigElements > 0 || pengElements > 0)
		{
			if (animalDeath == 1)
			{
				cout << "One of your tigers got sick and died. " << endl;
				killTiger();
			}
			else if (animalDeath == 2)
			{
				cout << "One of your turtles got sick and died. " << endl;
				killTurtle();
			}
			else if (animalDeath == 3)
			{
				cout << "One of your penguins died. " << endl;
				killPenguin();
			}
			else
				cout << "bad input, no death. " << endl;
		}
		break;
	case 2:
		cout << "random 2 happened. " << endl;
		cout << "Tiger bonus due to boom in attendance! " << endl;
		tigerBonus = (rand() % 250 + 250)*tigElements;
		break;
	case 3:
	{
		cout << "random 3 happened. " << endl;

		int ranBirth = rand() % 3 + 1;
		if (ranBirth == 1)
		{
			if (adultTiger != 0)
			{
				cout << "A tiger has been born! " << endl;
				birthTiger();
			}
			else
				cout << "No tigers are old enough to give birth. " << endl;

			for (int i = 0; i < getTigElements(); i++)
			{
				cout << getAtTiger(i).toString() << endl;
			}
		}
		else if (ranBirth == 2)
		{
			if (adultTurtle != 0)
			{
				cout << "10 turtles have been born! " << endl;
				birthTurtle();
			}
			else
				cout << "No turtles are old enough to give birth. " << endl;

			for (int i = 0; i < getTurtElements(); i++)
			{
				cout << getAtTurtle(i).toString() << endl;
			}
		}
		else if (ranBirth == 3)
		{
			if (adultPenguin != 0)
			{
				cout << "5 penguins have been born! " << endl;
				birthPenguin();
			}
			else
				cout << "No Penguins are old enough to give birth. " << endl;

			for (int i = 0; i < getPengElements(); i++)
			{
				cout << getAtPenguin(i).toString() << endl;
			}
		}
		else
			cout << "bad input. " << endl;
		break;
	}
	case 4:
		cout << "Nothing has happened today. " << endl;
	}
}

void Zoo::killTiger()
{	
	if (turtElements > 0)
		tigElements--;
}
void Zoo::killTurtle()
{
	if (turtElements > 0)
		turtElements--;
}
void Zoo::killPenguin()
{
	if (pengElements > 0)
		pengElements--;
}

void Zoo::birthTiger()
{
	//if (tigElements >= tigCapacity)
		//expandTigers();
	//tigElements += tigers[0]->getNumberOfBabies();

	for (int i = 0; i < 1; i++)
		addTigObject(0);
}
void Zoo::birthTurtle()
{
	//if (turtElements >= turtCapacity)
		//expandTurtles();
	//turtElements += turtles[0]->getNumberOfBabies();

	for (int i = 0; i < 10; i++)
		addTurtObject(0);
}
void Zoo::birthPenguin()
{
	//if (pengElements >= pengCapacity)
		//expandPenguins();
	//pengElements += penguins[0]->getNumberOfBabies();

	for (int i = 0; i < 5; i++)
		addPengObject(0);
}

int Zoo::totalFoodCost()
{
	int tigCost = 0;
	int turtCost = 0;
	int pengCost = 0;
	int totalFoodCost = 0;

	for (int i = 0; i < tigElements; i++)
	{
		tigCost += tigers[i]->getBaseFoodCost();
	}

	for (int i = 0; i < turtElements; i++)
	{
		turtCost += turtles[i]->getBaseFoodCost();
	}

	for (int i = 0; i < pengElements; i++)
	{
		pengCost += penguins[i]->getBaseFoodCost();
	}

	totalFoodCost = tigCost + pengCost + turtCost;
	return totalFoodCost;
}