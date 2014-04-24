#include <stdio.h>
#include "card.h"


int attack(struct card_t *attacker, struct card_t *defender)
{
	int first_monster = 0, second_monster = 0;
	if((attacker->live -= defender->power) <= 0)
		first_monster = 1;
    if((defender->live -= attacker->power) <= 0)
        second_monster = 1;
    printf("%i %i\n", second_monster, first_monster);

    if(first_monster==1 && second_monster==1)
        return 0;
    if(first_monster==0 && second_monster==1)
        return 1;
    if(first_monster==1 && second_monster==0)
        return 2;
    if(first_monster==0 && second_monster==0)
        return 3;
}


