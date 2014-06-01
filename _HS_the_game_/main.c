#include <stdio.h>
#include "deck.h"
#include "manapool.h"
#include "player.h"
#include "board.h"



int main()
{
	
	
	
	

	struct card_t card_to_push;
	struct card_t one = { "card_one", 1, 7, 3 };
	struct card_t two = { "card_two", 3, 7, 10 };
	struct card_t three = { "card_three", 3, 2, 5 };
	struct card_t four = { "card_four", 1, 2, 2 };
	struct card_t five = { "card_five", 3, 2, 4 };
	struct card_t six = { "card_six", 5, 4, 1 };
	struct card_t seven = { "card_seven", 6, 2, 4 };
	struct card_t eight = { "card_eight", 1, 7, 3 };
	struct card_t nine = { "card_nine", 3, 7, 10 };
	struct card_t ten = { "card_ten", 3, 2, 5 };
	struct card_t eleven = { "card_eleven", 1, 2, 2 };
	struct card_t twelve = { "card_twelve", 3, 2, 4 };
	struct card_t thirteen = { "card_thirteen", 5, 4, 1 };
	struct card_t fourteen = { "card_fourteen", 6, 2, 4 };
	
	struct card_t one_special = { "special_card_one", -1, 0, 3};// +5 life
	struct card_t two_special = { "special_card_two", -2, 0, 4};// -5 opponent life
	struct card_t three_special = { "special_card_three", -3, 0, 5};// +1 mana
	//printf("%d\n", attack(&one, &two));
	
	//---------------------------------------------------------------
	// player
	struct deck_t player_deck;
	struct player_t player;
	
	struct player_t first_player;
	struct player_t second_player;
	
	init_deck(&player_deck);
	
	push_card(one, &player_deck);
	push_card(two, &player_deck);
	push_card(three, &player_deck);
	push_card(four, &player_deck);
	push_card(five, &player_deck);
	push_card(six, &player_deck);
	push_card(seven, &player_deck);
	
	push_card(eight, &player_deck);
	push_card(nine, &player_deck);
	push_card(ten, &player_deck);
	push_card(eleven, &player_deck);
	push_card(twelve, &player_deck);
	push_card(thirteen, &player_deck);
	push_card(fourteen, &player_deck);
	
	push_card(one_special, &player_deck);
	push_card(two_special, &player_deck);
	push_card(three_special, &player_deck);
	
	print_stack(player_deck);

	Null_player_hand(&player);
	init_player(&player_deck, &first_player);
	init_player(&player_deck, &second_player);
	down_hp(&first_player,4);
	up_hp(&first_player,2);
	
	
	
	turn_begin(&player_deck, &first_player);
	
	turn_begin(&player_deck, &second_player);
	
	print_cards_in_hand(&first_player);
	printf("\n--------------------------------------------------------");
	print_cards_in_hand(&second_player);
	//play_card_from_hand(&player, "card_four");
	
	
	struct board_t board;

	init_board(&board);
	
	
	can_play_card(&board, &first_player, 0, thirteen, 3);// players 0 or 1
	
	play_card(&board, &first_player, 0, thirteen, 3);// players 0 or 1
	
	//turn_end(&board, 0);//players 0 or 1
	
	can_play_card(&board, &second_player, 1, nine, 3);// players 0 or 1
	
	play_card(&board, &second_player, 1, nine, 3);// players 0 or 1
	
	
	
	printf("\n--------------------------------------------------------");
	print_cards_in_hand(&first_player);
	printf("\n--------------------------------------------------------");
	print_cards_in_hand(&second_player);
	
	print_cards_in_hand(&second_player);
	
	//printf("%d\n", winner(&board, &first_player, &second_player));
	print_board(board, first_player, second_player, 1);
	turn_end(&board, &first_player, 0);
	turn_end(&board, &second_player, 1);
	/*
	//---------------------------------------------------------------
	// manapool
	struct manapool_t pool;
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
	//---------------------------------------------------------------
	// board
	
	
	//---------------------------------------------------------------
	
	

*/



return 0;
}

