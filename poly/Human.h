#ifndef HUMAN_H_INCLUDED
#define HUMAN_H_INCLUDED

#include "Creature.h"

class Human : public Creature
{
public:
	Human(int s = 10, int h = 10)
		: Creature(s, h)
	{}

	virtual string getSpecies() //over-rides the base class version (not re-definition)
	{
		return "Human";
	}
	virtual void attack(Creature & c)
	{
		//human inflicts a random damage up to its strength
		int damage = 1 + rand()%strength;

		cout << getSpecies() << " attacks for " << damage << " points.\n";

		//Decrement the hitpoints for the target creature
		c.setHitpoints(c.getHitpoints() - damage);
	}
};



#endif
