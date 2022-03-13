#ifndef CREATURE_H_INCLUDED
#define CREATURE_H_INCLUDED

#include <string>
#include <iostream>

using namespace std;


// abstract class cannot because the the two pure virtual fuctions
class Creature
{
public:
	Creature(int s = 10, int h = 10)
		: strength(s), hitpoints(h) // assignment operator to initilize constant member values
	{}


	//Accessors
	int getStrength() const // can only access member functions cannot change them
	{
		return strength;
	}
	int getHitpoints() const
	{
		return hitpoints;
	}

	//Mutators
	void setStrength(int newStrength)
	{
		strength = newStrength;
	}
	void setHitpoints(int newPoints)
	{
		hitpoints = newPoints;
	}

	virtual string getSpecies() = 0; //pure virtual function, no body // ment for overriding


	//pure virtual function that must be overriden by derived class
	//otherwise, derived class will be abstract class as well
	virtual void attack(Creature & c) = 0;


protected:
	int strength;
	int hitpoints;
};


#endif
