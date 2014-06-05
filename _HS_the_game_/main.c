#include <stdio.h>
#include "deck.h"
#include "manapool.h"
#include "player.h"
#include "board.h"



int main()
{

	//struct card_t card_to_push;
	struct card_t one = { "card_one", 1, 7, 3 };
	struct card_t two = { "card_two", 3, 7, 10 };
	struct card_t three = { "card_three", 3, 2, 5 };
	struct card_t four = { "card_four", 1, 2, 2 };
	struct card_t five = { "card_five", 3, 2, 4 };
	struct card_t six = { "card_six", 5, 4, 1 };
	struct card_t seven = { "card_seven", 6, 2, 4 };
	struct card_t eight = { "card_eight", 1, 7, 2 };
	struct card_t nine = { "card_nine", 3, 7, 1 };
	struct card_t ten = { "card_ten", 3, 2, 2 };
	struct card_t eleven = { "card_eleven", 1, 2, 2 };
	struct card_t twelve = { "card_twelve", 3, 2, 4 };
	struct card_t thirteen = { "card_thirteen", 5, 4, 2 };
	struct card_t fourteen = { "card_fourteen", 2, 2, 1 };
	
	struct card_t one_special = { "special_card_one", -1, 0, 1};// +5 life
	struct card_t two_special = { "special_card_two", -2, 0, 1};// *2 card_power and +5 card_life 
	struct card_t three_special = { "special_card_three", -3, 0, 5};// +1 mana
	struct card_t shaman = {"shaman", 4, 5, 2};
	struct card_t grivna = {"grivna", 6, 3, 3};
	struct card_t kolelo = {"kolelo", 5, 2, 2};
	
	//printf("%d\n", attack(&one, &two));
	
	//---------------------------------------------------------------
	//struct deck_t player_deck;
	//struct player_t player;
	
	struct player_t first_player;
	struct player_t second_player;
	struct deck_t first_player_deck;
	struct deck_t second_player_deck;
	first_player.name_player = "TGS";
	second_player.name_player = "Baba Gusi";
	init_deck(&first_player_deck);
	init_deck(&second_player_deck);
	
	push_card(one, &first_player_deck);
	push_card(two, &first_player_deck);
	push_card(three, &first_player_deck);
	push_card(four, &first_player_deck);
	push_card(five, &first_player_deck);
	push_card(six, &first_player_deck);
	push_card(seven, &first_player_deck);
	
	push_card(eight, &first_player_deck);
	push_card(nine, &first_player_deck);
	push_card(ten, &first_player_deck);
	
	push_card(eleven, &second_player_deck);
	push_card(twelve, &second_player_deck);
	push_card(thirteen, &second_player_deck);
	push_card(fourteen, &second_player_deck);
	
	push_card(one_special, &second_player_deck);
	push_card(two_special, &second_player_deck);
	push_card(three_special, &second_player_deck);
	push_card(shaman, &second_player_deck);
	push_card(grivna, &second_player_deck);
	push_card(kolelo, &second_player_deck);
	
	print_stack(first_player_deck);
	print_stack(second_player_deck);

	Null_player_hand(&first_player);
	Null_player_hand(&second_player);
	
	init_player(&first_player_deck, &first_player);
	
	init_player(&second_player_deck, &second_player);
	down_hp(&second_player,5);
	up_hp(&second_player,2);
	
	
	
	turn_begin(&first_player_deck, &first_player);
	
	turn_begin(&second_player_deck, &second_player);
	printf("\n--------------------------------------------------------");
	printf("\nTGS hand:\n");
	print_cards_in_hand(&first_player);
	printf("\n--------------------------------------------------------");
	printf("\nBaba Gusi hand:\n");
	print_cards_in_hand(&second_player);
	//play_card_from_hand(&player, "card_four");
	
	
	struct board_t board;

	init_board(&board);
	
	turn_end(&board, &first_player, 0);
	turn_end(&board, &second_player, 1);
	turn_end(&board, &first_player, 0);
	turn_end(&board, &second_player, 1);
	turn_end(&board, &first_player, 0);
	turn_end(&board, &second_player, 1);
	turn_end(&board, &first_player, 0);
	turn_end(&board, &second_player, 1);
	turn_end(&board, &first_player, 0);
	turn_end(&board, &second_player, 1);
	turn_end(&board, &first_player, 0);

	
	
	can_play_card(&board, &first_player, 0, six, 3);// players 0 or 1
	
	play_card(&board, &first_player, 0, six, 3);// players 0 or 1
	
	can_play_card(&board, &second_player, 1, grivna, 3);// players 0 or 1
	
	play_card(&board, &second_player, 1, grivna, 3);// players 0 or 1
	
	print_board(board, first_player, second_player, 1);
	printf("\n--------------------------------------------------------\n");
	
	
	turn_begin(&first_player_deck, &first_player);
	
	turn_begin(&second_player_deck, &second_player);
	
	play_card(&board, &first_player, 0, seven, 2);// players 0 or 1
	
	play_card(&board, &second_player, 1, two_special, 3);// players 0 or 1

	print_board(board, first_player, second_player, 3);
	printf("\n--------------------------------------------------------\n");
	
	
	turn_begin(&first_player_deck, &first_player);
	
	turn_begin(&second_player_deck, &second_player);
	
	play_card(&board, &first_player, 0, eight, 1);// players 0 or 1
	
	play_card(&board, &second_player, 1, shaman, 1);// players 0 or 1

	print_board(board, first_player, second_player, 5);
	
	
	printf("\n--------------------------------------------------------\n");
	
	winner(first_player, second_player);
	
	printf("\n--------------------------------------------------------\n");
	
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

