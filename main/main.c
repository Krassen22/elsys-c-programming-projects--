#include <stdio.h>
#include "..\card\card.h"
#include "..\deck\deck.h"
#include "..\manapool\manapool.h"
#include "..\player\player.h"


int main()
{
//player
struct card_t card_to_push;
struct deck_t player_deck;
struct player_t player;
struct card_t one = { "card_one", 1, 7, 3 };
struct card_t two = { "card_two", 3, 7, 10 };
struct card_t three = { "card_three", 3, 2, 5 };
struct card_t four = { "card_four", 1, 2, 2 };
struct card_t five = { "card_five", 3, 2, 4 };
struct card_t six = { "card_six", 5, 4, 1 };
struct card_t seven = { "card_seven", 6, 2, 4 };
init_deck(&player_deck);
push_card(one, &player_deck);
push_card(two, &player_deck);
push_card(three, &player_deck);
push_card(four, &player_deck);
push_card(five, &player_deck);
push_card(six, &player_deck);
push_card(seven, &player_deck);

print_stack(player_deck);
init_player(&player);

down_hp(&player,4);
up_hp(&player,2);

turn_begin(&player);
turn_begin(&player);

print_cards_in_hand(player);
play_card_from_hand(&player, "card_four");
print_cards_in_hand(player);

//manapool
/*
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

*/
//deck
/*
	struct card_t card_to_push;
	struct deck_t player_deck;
	struct card_t one = { "card_one", 1, 7, 0};
	struct card_t two = { "card_two", 3, 7, 4};
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
/*
	struct card_t one = { "card_one", 1, 7, 0};
	struct card_t two = { "card_two", 3, 7, 4};
	struct card_t three = { "card_three", 4, 6, 4};
    	printf("%i\n", attack(&one, &two));
*/



return 0;
}

