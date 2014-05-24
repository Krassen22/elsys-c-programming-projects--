#include <stdio.h>
#include "board.h"

void init_board(struct board_t *board)
{
	
	int i;
	for (i=0;i <= PLAYERS;i++)
	{
		int j;
		for (j=0;j <= LANES;j++)
		{
			board->board_game[i][j].name = "";
			board->board_game[i][j].live = 0;
			board->board_game[i][j].power = 0;
			board->board_game[i][j].mana_cost = 0;
		}	
	}	
}

void print_player(struct player_t *player, int turn)
{
	
		printf("PLAYER_NAME: %s, HP: %d, MANA: %d/10, TURN: %d\n", player->name_player, player->hp_player, player->mana_player.current_mana, turn);
	
}


int can_play_card(struct board_t *board, struct player_t *pl, char *card_name, int player, int num_lane)
{
	int i;
		for(i=0;i <= pl->last_t_card_in_hand;i++)
		{
			if (pl->cards_in_hand[i].name == card_name && &board->board_game[player][num_lane] == 0 && pl->mana_player.current_mana >= pl->cards_in_hand[i].mana_cost)
			{
				return 1; // we can play card 
			}
			else
			{
				return 0; // we can NOT play card
			}
		}
}

int play_card(struct board_t *board, struct player_t *pl, int player, char *card_name, int num_lane)
{
	int i;
	for(i=0;i <= pl->last_t_card_in_hand ;i++)
	{
		if (pl->cards_in_hand[i].name == card_name && &board->board_game[player][num_lane] == 0 && pl->mana_player.current_mana >= pl->cards_in_hand[i].mana_cost )
		{
			board->board_game[player][num_lane].name = pl->cards_in_hand[i].name;	
			board->board_game[player][num_lane].live = pl->cards_in_hand[i].live;	
			board->board_game[player][num_lane].power = pl->cards_in_hand[i].power;	
			board->board_game[player][num_lane].mana_cost = pl->cards_in_hand[i].mana_cost;	
			
			return 1; // we can play card 	
		}
		else
		{
			return 0; // we can NOT play card	
		}
	}
	
}


//void turn_end(struct board_t *board, int first_pl);


void print_board(struct board_t *board, struct player_t first_player, struct player_t second_player, int turn)//it can be 1,3,5,7... 
{
	printf("PLAYER_NAME: %s, HP: %d, MANA: %d/10, TURN: %d\n", first_player.name_player, 
	first_player.hp_player, first_player.mana_player.current_mana, turn);
 
	printf("________________________________________________________________________\n");
	int i;
	for (i=0;i <= first_player.last_t_card_in_hand;i++)
	{
		printf("|   %d|%d(%d)  ", first_player.cards_in_hand[i].power, 
		first_player.cards_in_hand[i].live, first_player.cards_in_hand[i].mana_cost);
	}	
	printf("|\n");
	
    printf("#########################################################################\n");
    int player;
	for (player=0; player <= PLAYERS; player++)
	{ 
		int num_lane;
		for (num_lane=0;num_lane <= LANES;num_lane++)
		{
			printf("#   %d|%d  ", board->board_game[player][num_lane].power, board->board_game[player][num_lane].live);	
		}	
		printf("#\n");
	}	       
	printf("#########################################################################\n");
    
    for(i=0;i <= second_player.last_t_card_in_hand;i++)
    {
		printf("|   %d|%d(%d)  ", second_player.cards_in_hand[i].power, 
		second_player.cards_in_hand[i].live, first_player.cards_in_hand[i].mana_cost);   
    }      
    printf("|\n");       
             
    printf("________________________________________________________________________\n");
   
    printf("PLAYER_NAME: %s, HP: %d, MANA: %d/10, TURN: %d\n", second_player.name_player, 
    second_player.hp_player, second_player.mana_player.current_mana, turn+1);
}

/*int main(int argc, char **argv)
{
	
	return 0;
}
*/
