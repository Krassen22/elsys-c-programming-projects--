#ifndef __CARD__
#define __CARD__

struct card_t{
char name[255];
int power, live, mana_cost;
};

int attack(struct card_t *attacker, struct card_t *defender);

#endif
