#ifndef ELF_H_INCLUDED
#define ELF_H_INCLUDED

#include "Creature.h"

class Elf : public Creature
{
public:
	Elf(int s = 10, int h = 10)
		:Creature(s, h)
	{}

	virtual string getSpecies()
	{
		return "Elf";
	}

	virtual void attack(Creature & c)
	{
		int damage = 1 + rand() % strength;

		//There is a 10% chance that elf will inflict magical attack which doubles up the damage
		if(rand() % 10 == 1)
		{
			cout << "Magical attack inflicts " << damage << " additional damage points!\n";
			damage *= 2;
		}

		cout << "Elf attacks for " << damage << " points.\n";
		c.setHitpoints(c.getHitpoints() - damage );
	}
};



#endif
