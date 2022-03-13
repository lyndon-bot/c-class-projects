#include "Human.h"
#include "Elf.h"
#include "Demon.h"
#include "Barlog.h"
#include <ctime>

using namespace std;

//Function prototypes
void battleArena(Creature & c1, Creature & c2);

int main()
{
	//seed the random number generator
	srand(time(0));

	Barlog ncBarlog(40, 150);
	Demon ncDemon(60, 200);

	Elf ncElf(60, 220);
	Barlog ncBarlog2(30, 180);

	battleArena(ncBarlog, ncDemon);

	battleArena(ncBarlog2, ncElf);

	system("pause");

	return 0;
}

void battleArena(Creature & c1, Creature & c2)
{
	cout << "\n*******************************************\n";
	cout << "Battle between " << c1.getSpecies() << " and " << c2.getSpecies() << endl;
	cout << "*******************************************\n";

	int round = 1;
	while(c1.getHitpoints() > 0 && c2.getHitpoints() > 0)
	{
		c1.attack(c2);
		c2.attack(c1);

		cout << "End of round " << round << endl << endl;
		round++;
	}

	cout << c1.getSpecies() << " has " << c1.getHitpoints() << " points.\n";
	cout << c2.getSpecies() << " has " << c2.getHitpoints() << " points.\n";

	if(c1.getHitpoints() <= 0 && c2.getHitpoints() <= 0)
		cout << "The match is a tie.\n";
	else if(c1.getHitpoints() > 0)
		cout << c1.getSpecies() << " won.\n";
	else
		cout << c2.getSpecies() << " won.\n";

}
