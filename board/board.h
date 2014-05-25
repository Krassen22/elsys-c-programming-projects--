#ifndef __BOARD__
#define __BOARD__
#include "..\card\card.h"
#include "..\deck\deck.h"
#include "..\manapool\manapool.h"
#include "..\player\player.h"
#define PLAYERS 1 // 0 and 1 (2 players)
#define LANES 4 // 0,1,2,3,4 (5 lanes)


struct board_t
{
	struct player_t players[2];
	struct card_t board_game[2][5];
			
};
void init_board(struct board_t *board);
int can_play_card(struct board_t *board, char *card_name, int player, int num_lane);
int play_card(struct board_t *board, int player, char *card_name, int num_lane);
void turn_end(struct board_t *board, int player);
int winner(struct board_t *board);
void print_board(struct board_t board, int turn);

#endif
