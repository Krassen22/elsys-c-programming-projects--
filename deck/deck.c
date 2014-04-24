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

struct card_t push_card(struct card_t card_to_push, struct deck_t *player_deck)
{
    player_deck->cards[player_deck->top++] = card_to_push;
}

struct card_t draw_card(struct deck_t *player_deck)
{
	if(player_deck->top)
    {
        return player_deck->cards[--player_deck->top];
    }
}

struct card_t look_card(struct deck_t player_deck)
{
        if(player_deck.top)
        {
            printf("\nLook at the first card:");
            printf("\nName: %s", player_deck.cards[player_deck.top].name);
            printf("\nPower: %d", player_deck.cards[player_deck.top].power);
            printf("\nLive: %d", player_deck.cards[player_deck.top].live);
            printf("\nMana_cost: %d", player_deck.cards[player_deck.top].mana_cost);
        }
}

struct card_t print_stack(struct deck_t *player_deck)
{
    int i;
	for (i=0; i < player_deck->top ; i++)
    {
        printf("\nName: %s", player_deck->cards[i].name);
        printf("\nPower: %d", player_deck->cards[i].power);
        printf("\nLive: %d", player_deck->cards[i].live);
        printf("\nMana_cost: %d", player_deck->cards[i].mana_cost);
    }
}


