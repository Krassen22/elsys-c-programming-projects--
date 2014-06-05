#ifndef __BOARD__
#define __BOARD__
#include "card.h"
#include "deck.h"
#include "manapool.h"
#include "player.h"
#define PLAYERS 1 // 0 and 1 (2 players)
#define LANES 4 // 0,1,2,3,4 (5 lanes)



struct board_t
{
	struct player_t players[2];
	struct card_t board_game[2][5];
			
};
void init_board(struct board_t *board);
int can_play_card(struct board_t *board, struct player_t *pl, int player, struct card_t card, int num_lane);
int play_card(struct board_t *board, struct player_t *pl, int player, struct card_t card, int num_lane);
int attack_cards(struct board_t *board, struct player_t *attacker, struct player_t *defender, int attk, int def, int num_lane);
void turn_end(struct board_t *board, struct player_t *pl, int player);
int winner(struct player_t pl_one, struct player_t pl_two);
void print_board(struct board_t board, struct player_t pl_one, struct player_t pl_two, int turn);

#endif
