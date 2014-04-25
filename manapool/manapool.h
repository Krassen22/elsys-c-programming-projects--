#ifndef __MANAPOOL__
#define __MANAPOOL__
#include "..\deck\deck.h"
#define MANASZ 10

struct manapool_t
{
    int size_mana;
    int current_mana;

};
void init_mana (struct manapool_t *pool);
void push_mana(struct manapool_t *pool);
int take_mana(struct card_t card_to_push, struct manapool_t *pool);
int can_put_card(struct card_t card_to_push, struct manapool_t *pool);
void print_manapool(struct manapool_t *pool);

#endif
