#ifndef BARLOG_H_INCLUDED
#define BARLOG_H_INCLUDED

#include "Demon.h"

class Barlog : public Demon
{
public:
	Barlog(int s = 10, int h = 10)
		: Demon(s, h)
	{
	}

	virtual string getSpecies()
	{
		return "Barlog";
	}

	virtual void attack(Creature & c)
	{
		//barlog will do the demonic attack first
		Demon::attack(c);

		//barlog is so fast so they get to attack twice
		cout << "Barlog is attacking again.\n";
		int damage2 = 1 + rand()%strength;

		cout << "Barlog is inflicting " << damage2 << " additional points.\n";

		c.setHitpoints(c.getHitpoints() - damage2);
	}

};


#endif
