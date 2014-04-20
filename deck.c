#include <stdio.h>
#include "deck.h"
// push_card, draw_card, look_card

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

struct card_t look_card(struct deck_t *player_deck)
{
        if(player_deck->top)
        {
            printf("\nLook at the first card:");
            printf("\nName: %s", player_deck->cards[player_deck->top].name);
            printf("\nPower: %d", player_deck->cards[player_deck->top].power);
            printf("\nLive: %d", player_deck->cards[player_deck->top].live);
            printf("\nMana_cost: %d", player_deck->cards[player_deck->top].mana_cost);
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

int main()
{

struct card_t card_to_push;
struct deck_t player_deck;
player_deck.top = 0;
struct card_t card;
struct card_t one = { "card_one", 1, 7, 0 };
struct card_t two = { "card_two", 3, 7, 4 };
struct card_t three = { "card_three", 4, 6, 4};


printf("is stack empty? = %d\n", is_stack_empty(&player_deck));
printf("is stack full? = %d\n", is_stack_full(&player_deck));
push_card(one, &player_deck);
push_card(two, &player_deck);
push_card(three, &player_deck);

print_stack(&player_deck);
printf("\nis stack empty? = %d\n", is_stack_empty(&player_deck));
printf("is stack full? = %d\n", is_stack_full(&player_deck));
//---------------------------------

draw_card(&player_deck);
look_card(&player_deck);
print_stack(&player_deck);

printf("\nis stack empty? = %d\n", is_stack_empty(&player_deck));
printf("is stack full? = %d\n", is_stack_full(&player_deck));

    return 0;
}
