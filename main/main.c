#include <stdio.h>
#include "..\card\card.h"
#include "..\deck\deck.h"
#include "..\manapool\manapool.h"

int main()
{
 //manapool
struct card_t card_to_push;
    struct manapool_t pool;
    struct card_t one = { "card_one", 1, 7, 3 };
    struct card_t two = { "card_two", 3, 7, 10 };
    struct card_t three = { "card_three", 4, 6, 4};
    init_mana(&pool);
    print_manapool(&pool);
    push_mana(&pool);//2 mana
    push_mana(&pool);//3 mana
    push_mana(&pool);//4 mana
    push_mana(&pool);//5 mana
    push_mana(&pool);//6 mana
        printf("\nCan we put card?(yes-1, no-0): %d\n", can_put_card(one, &pool));
        take_mana(one, &pool);//1 mana
    push_mana(&pool);//7 mana
        printf("\nCan we put card?(yes-1, no-0): %d\n", can_put_card(two, &pool));
        take_mana(two, &pool);//3 mana
    push_mana(&pool);//8 mana
    push_mana(&pool);//9 mana
    push_mana(&pool);//10 mana
    push_mana(&pool);//10 mana
        printf("\nCan we put card?(yes-1, no-0): %d\n", can_put_card(two, &pool));
        take_mana(three, &pool);//6 mana
    push_mana(&pool);//=> 10 mana


//deck
/*
struct card_t card_to_push;
struct deck_t player_deck;
struct card_t card;
struct card_t one = { "card_one", 1, 7, 0 };
struct card_t two = { "card_two", 3, 7, 4 };
struct card_t three = { "card_three", 4, 6, 4};


printf("is stack empty? = %d\n", is_stack_empty(&player_deck));
printf("is stack full? = %d\n", is_stack_full(&player_deck));
init_deck(&player_deck);
push_card(one, &player_deck);
push_card(two, &player_deck);
push_card(three, &player_deck);

print_stack(&player_deck);
printf("\nis stack empty? = %d\n", is_stack_empty(&player_deck));
printf("is stack full? = %d\n", is_stack_full(&player_deck));
//---------------------------------

draw_card(&player_deck);
look_card(player_deck);
print_stack(&player_deck);

printf("\nis stack empty? = %d\n", is_stack_empty(&player_deck));
printf("is stack full? = %d\n", is_stack_full(&player_deck));
*/

//card
/*int main()
{
	struct card_t one = { "card_one", 1, 7, 0};
	struct card_t two = { "card_two", 1, 7, 0};
    printf("%i\n", attack(&one, &two));
    return 0;
}

*/

        return 0;
}
