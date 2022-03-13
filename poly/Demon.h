#ifndef DEMON_H_INCLUDED
#define DEMON_H_INCLUDED

#include "Creature.h" // must include, big 3 not inherited

class Demon : public Creature
{
public:
	Demon(int s = 10, int h = 10)
		: Creature (s, h)
	{}

	virtual string getSpecies()
	{
		return "Demon";
	}

	//C is polymorphic, c can be any creature under the hierarchy
	virtual void attack(Creature & c)
	{
		int damage = 1 + rand() % strength;

		//5% change for demonic attack
		if(rand()% 100 < 5)
		{
			damage += 50;

			cout << "Demonic attack inflicts 50 additional damage points." << endl;
		}

		cout << getSpecies() << " attacks for " << damage << " points.\n";

		c.setHitpoints(c.getHitpoints() - damage);

	}

};


#endif
