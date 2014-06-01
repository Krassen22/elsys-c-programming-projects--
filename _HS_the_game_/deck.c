#include <stdio.h>
#include "deck.h"


// push_card, draw_card, look_card

void init_deck(struct deck_t *player_deck)
{
    player_deck->top = 0;
}

int is_stack_empty(struct deck_t *player_deck)
{
    if (player_deck->top == 0)
        return 1;
    else
        return 0;
}

int is_stack_full(struct deck_t *player_deck)
{
    if (player_deck->top == DECKSZ )
        return 1;
    else
        return 0;
}

void push_card(struct card_t card_to_push, struct deck_t *player_deck)
{
    player_deck->cards[player_deck->top++] = card_to_push;
}

struct card_t draw_card(struct deck_t *player_deck)
{
	
	return player_deck->cards[--player_deck->top];
	      
}

void look_card(struct deck_t player_deck)
{
        if(player_deck.top)
        {
            printf("\nLook at the first card:");
            printf("\nName: %s", player_deck.cards[player_deck.top].name);
            printf("\nPower: %d", player_deck.cards[player_deck.top].power);
            printf("\nLife: %d", player_deck.cards[player_deck.top].life);
            printf("\nMana_cost: %d", player_deck.cards[player_deck.top].mana_cost);
        }
}

void print_stack(struct deck_t player_deck)
{
    int i;
	for (i=0; i < player_deck.top ; i++)
    {
        printf("\nName: %s", player_deck.cards[i].name);
        printf("\nPower: %d", player_deck.cards[i].power);
        printf("\nLife: %d", player_deck.cards[i].life);
        printf("\nMana_cost: %d", player_deck.cards[i].mana_cost);
    }
}


