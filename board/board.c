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


int can_play_card(struct board_t *board, char *card_name, int player, int num_lane) //players 0 or 1
{
	int i;
	if(player == 0)
	{
		for(i=0;i <= board->players[player].last_t_card_in_hand;i++)
		{
			if (board->players[player].cards_in_hand[i].name == card_name && &board->board_game[player][num_lane] == 0 && board->players[player].mana_player.current_mana >= board->players[player].cards_in_hand[i].mana_cost)
			{
				return 1; // we can play card 
			}
			else
			{
				return 0; // we can NOT play card
			}
		}
	}
	else if(player == 1)
	{
		for(i=0;i <= board->players[player].last_t_card_in_hand;i++)
		{
			if (board->players[player].cards_in_hand[i].name == card_name && &board->board_game[player][num_lane] == 0 && board->players[player].mana_player.current_mana >= board->players[player].cards_in_hand[i].mana_cost)
			{
				return 1; // we can play card 
			}
			else
			{
				return 0; // we can NOT play card
			}
		}
	}	
}

int play_card(struct board_t *board, int player, char *card_name, int num_lane)//players 0 or 1
{
	int i;
	if(player == 0)
	{
		for(i=0;i <= board->players[player].last_t_card_in_hand;i++)
		{
			if (board->players[player].cards_in_hand[i].name == card_name && &board->board_game[player][num_lane] == 0 && board->players[player].mana_player.current_mana >= board->players[player].cards_in_hand[i].mana_cost )
			{
				board->board_game[player][num_lane].name = board->players[player].cards_in_hand[i].name;	
				board->board_game[player][num_lane].live = board->players[player].cards_in_hand[i].live;	
				board->board_game[player][num_lane].power = board->players[player].cards_in_hand[i].power;	
				board->board_game[player][num_lane].mana_cost = board->players[player].cards_in_hand[i].mana_cost;	
			
				return 1; // we can play card 	
			}
			else
			{
				return 0; // we can NOT play card	
			}
		}
	}
	else if (player == 1)
	{
		for(i=0;i <= board->players[player].last_t_card_in_hand;i++)
		{
			if (board->players[player].cards_in_hand[i].name == card_name && &board->board_game[player][num_lane] == 0 && board->players[player].mana_player.current_mana >= board->players[player].cards_in_hand[i].mana_cost )
			{
				board->board_game[player][num_lane].name = board->players[player].cards_in_hand[i].name;	
				board->board_game[player][num_lane].live = board->players[player].cards_in_hand[i].live;	
				board->board_game[player][num_lane].power = board->players[player].cards_in_hand[i].power;	
				board->board_game[player][num_lane].mana_cost = board->players[player].cards_in_hand[i].mana_cost;	
			
				return 1; // we can play card 	
			}
			else
			{
				return 0; // we can NOT play card	
			}
		}
	}
	
}


void turn_end(struct board_t *board, int player)
{
	board->players[player].mana_player.size_mana+=1;
	board->players[player].mana_player.current_mana = board->players[player].mana_player.size_mana;
	
}


int winner(struct board_t *board)
{
		if(board->players[0].hp_player == 0)
		{
			return 1; // second_player wins
		} 
		else if (board->players[1].hp_player == 0)
		{
			return 2; // first_player wins
		}
		else 
		{
			return 0; // we haven NOT winner yet
		}
}


void print_board(struct board_t board, int turn)//it can be 1,3,5,7... 
{
	printf("PLAYER_NAME: %s, HP: %d, MANA: %d/10, TURN: %d\n", board.players[0].name_player, 
	board.players[0].hp_player, board.players[0].mana_player.current_mana, turn);
 
	printf("________________________________________________________________________\n");
	int i;
	for (i=0;i <= board.players[0].last_t_card_in_hand;i++)
	{
		printf("|   %d|%d(%d)  ", board.players[0].cards_in_hand[i].power, 
		board.players[0].cards_in_hand[i].live, board.players[0].cards_in_hand[i].mana_cost);
	}	
	printf("|\n");
	
    printf("#########################################################################\n");
    int player;
	for (player=0; player <= PLAYERS; player++)
	{ 
		int num_lane;
		for (num_lane=0;num_lane <= LANES;num_lane++)
		{
			printf("#   %d|%d  ", board.board_game[player][num_lane].power, board.board_game[player][num_lane].live);	
		}	
		printf("#\n");
	}	       
	printf("#########################################################################\n");
    
    for(i=0;i <= board.players[1].last_t_card_in_hand;i++)
    {
		printf("|   %d|%d(%d)  ", board.players[1].cards_in_hand[i].power, 
		board.players[1].cards_in_hand[i].live, board.players[1].cards_in_hand[i].mana_cost);   
    }      
    printf("|\n");       
             
    printf("________________________________________________________________________\n");
   
    printf("PLAYER_NAME: %s, HP: %d, MANA: %d/10, TURN: %d\n", board.players[1].name_player, 
    board.players[1].hp_player, board.players[1].mana_player.current_mana, turn+1);
}


/*int main(int argc, char **argv)
{
	
	return 0;
}
*/
