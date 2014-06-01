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
			board->board_game[i][j].life = 0;
			board->board_game[i][j].power = 0;
			board->board_game[i][j].mana_cost = 0;
		}	
	}	
}


int can_play_card(struct board_t *board, struct player_t *pl, int player, struct card_t card, int num_lane) //players 0 or 1
{
	int i;
	
	for(i=0;i <= pl->last_t_card_in_hand;i++)
	{
		if (pl->cards_in_hand[i].name == card.name && &board->board_game[player][num_lane] == 0 && 
		pl->mana_player.current_mana >= pl->cards_in_hand[i].mana_cost)
		{
			return 1; // we can play card 
		}
		else
		{
			return 0; // we can NOT play card
		}
	}
}
	

int play_card(struct board_t *board, struct player_t *pl, int player, struct card_t card, int num_lane)//players 0 or 1
{
	if(pl->mana_player.current_mana >= card.mana_cost)
	{	
		if(card.power >= 0)// monster
		{
			board->board_game[player][num_lane].name = card.name;	
			board->board_game[player][num_lane].power = card.power;	
			board->board_game[player][num_lane].life = card.life;	
			board->board_game[player][num_lane].mana_cost = card.mana_cost;	
			
		}
		else if(card.power == -1)// special card_one
		{
			pl->hp_player += 2;
		}
		else if(card.power == -2)// special card_two
		{
			board->board_game[player][num_lane].power *=2; 
			board->board_game[player][num_lane].life +=5;
		}
		else if(card.power == -3)
		{
			pl->mana_player.current_mana += 1;// special card_three	 	
		}
		pl->mana_player.current_mana -= card.mana_cost;
		int i;
		for(i=0; i<=pl->last_t_card_in_hand; i++)
		{
			if (pl->cards_in_hand[i].name == card.name)
			{
				pl->cards_in_hand[i].name = "";
				pl->cards_in_hand[i].life = 0;
				pl->cards_in_hand[i].power = 0;
				pl->cards_in_hand[i].mana_cost = 0;
			}
		}
	}		
	else
	{
		printf("\nPLAYER:%s Not enough mana for:%s\n",pl->name_player, card.name);
	}	
		
}
	

void turn_end(struct board_t *board, struct player_t *pl, int player)
{
	pl->mana_player.size_mana+=1;
	pl->mana_player.current_mana = pl->mana_player.size_mana;
	
}

int winner(struct board_t *board, struct player_t *pl_one, struct player_t *pl_two)
{
		
		if(pl_one->hp_player == 0)
		{
			return 1; // second_player wins
		} 
		else if (pl_two->hp_player == 0)
		{
			return 2; // first_player wins
		}
		else 
		{
			return 0; // we haven NOT winner yet
		}
}


void print_board(struct board_t board, struct player_t pl_one, struct player_t pl_two, int turn)//it can be 1,3,5,7... 
{
	
	printf("\nPLAYER_NAME: %s, HP: %d, MANA: %d/10, TURN: %d\n", pl_one.name_player, 
	pl_one.hp_player, pl_one.mana_player.current_mana, turn);
 
	printf("________________________________________________________________________\n");
	int i;
	for (i=0;i <= pl_one.last_t_card_in_hand;i++)
	{
		printf("|   %d|%d(%d)  ", pl_one.cards_in_hand[i].power, 
		pl_one.cards_in_hand[i].life, pl_one.cards_in_hand[i].mana_cost);
	}	
	printf("|\n");
	
    printf("#########################################################################\n");
    int player;
	for (player=0; player <= PLAYERS; player++)
	{ 
		int num_lane;
		for (num_lane=0;num_lane <= LANES;num_lane++)
		{
			printf("#   %d|%d  ", board.board_game[player][num_lane].power, board.board_game[player][num_lane].life);	
		}	
		printf("#\n");
	}	       
	printf("#########################################################################\n");
    
    for(i=0;i <= pl_two.last_t_card_in_hand;i++)
    {
		printf("|   %d|%d(%d)  ", pl_two.cards_in_hand[i].power, 
		pl_two.cards_in_hand[i].life, pl_two.cards_in_hand[i].mana_cost);   
    }      
    printf("|\n");       
             
    printf("________________________________________________________________________\n");
   
    printf("PLAYER_NAME: %s, HP: %d, MANA: %d/10, TURN: %d\n", pl_two.name_player, 
    pl_two.hp_player, pl_two.mana_player.current_mana, turn+1);  
    
}

