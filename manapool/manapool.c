#include <stdio.h>
#include "manapool.h"


void init_mana(struct manapool_t *pool)
{
    pool->size_mana = 1;
    pool->current_mana = 1;
}

void push_mana(struct manapool_t *pool)
{
    if(pool->size_mana < MANASZ )
    {
        pool->size_mana += 1;
        pool->current_mana = pool->size_mana;
        printf("\nMana in manapool: %d ", pool->size_mana);
		printf("\nCurrent mana: %d",pool->current_mana);
		printf("\n----------------------");

    }
    else
    {
        printf("\nManapool is full!");
        pool->size_mana = 10;
        pool->current_mana = pool->size_mana;
        printf("\nMana in manapool: %d ", pool->size_mana);
		printf("\nCurrent mana: %d",pool->current_mana);
		//printf("\n----------------------");
    }
}

int take_mana(struct card_t card_to_push, struct manapool_t *pool)
{
    if (card_to_push.mana_cost <= pool->size_mana)
    {
        pool->current_mana -=card_to_push.mana_cost;
        printf("\nMana in manapool: %d ", pool->size_mana);
		printf("\nCurrent mana: %d",pool->current_mana);
		printf("\n----------------------");
    }
    else
    {
        printf("\nNot enough mana in manapool!");
        printf("\n----------------------");

    }

}


int can_put_card(struct card_t card_to_push, struct manapool_t *pool)
{

    if(card_to_push.mana_cost <= pool->size_mana)
        return 1;
    else
        return 0;

}


void print_manapool(struct manapool_t *pool)
{
		printf("\nMana in manapool: %d ", pool->size_mana);
		printf("\nCurrent mana: %d",pool->current_mana);
		printf("\n----------------------");
}


