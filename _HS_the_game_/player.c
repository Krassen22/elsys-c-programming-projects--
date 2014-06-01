#include <stdio.h>
#include <stdlib.h>
#include "player.h"

void Null_player_hand(struct player_t *player)
{
	player->last_t_card_in_hand = 0;	
}

void init_player(struct deck_t *player_deck, struct player_t *player)
{
        player->hp_player = 30;
        init_mana(&player->mana_player);
        player->deck_player = (struct deck_t*)malloc(DECKSZ * sizeof(struct deck_t)); 
        player->cards_in_hand = (struct card_t*)malloc(HANDSZ * sizeof(struct card_t)); 
        for(player->last_t_card_in_hand = 0; player->last_t_card_in_hand <= 4; player->last_t_card_in_hand++)
		{
			
			player->cards_in_hand[player->last_t_card_in_hand] = player_deck->cards[--player_deck->top];
	
			
		}
}

void down_hp(struct player_t *player, int hp)
{
	if (hp < player->hp_player)
	{
		player->hp_player -=hp;
		printf("\nHP_PLAYER:(after down hp) %d\n", player->hp_player);
	}
	else
	{
		player->hp_player = 0;
		printf("\nPLAYER is dead!: %d\n", player->hp_player);

	}

}

void up_hp(struct player_t *player, int hp)
{
	if((hp + player->hp_player) <= 30)
	{
		player->hp_player += hp;
        	printf("\nHP_PLAYER:(after up   hp) %d\n", player->hp_player );
	}
	else
	{
		player->hp_player = 30;
		printf("\nHP_PLAYER:(after up   hp) %d\n", player->hp_player);
	}

}


void turn_begin(struct deck_t *player_deck, struct player_t *player)
{
	
	if (player->last_t_card_in_hand <= HANDSZ)
	{
	
			if (player_deck->top != 0)
			{
					player->cards_in_hand[player->last_t_card_in_hand] = player_deck->cards[--player_deck->top];
					player->last_t_card_in_hand++;
			}
			else
			{
				printf("Player deck is empty!");
			}

	}
	else 
	{
			printf("Hand is full!");
	}
}


void play_card_from_hand(struct player_t *player, char *card_name)
{
	int e;
	for(e = 0; e < player->last_t_card_in_hand; ++e)
	{
		if(player->cards_in_hand[e].name == card_name)
		{
			player->cards_in_hand[e].name = "";
			player->cards_in_hand[e].life = 0;
			player->cards_in_hand[e].power = 0;
			player->cards_in_hand[e].mana_cost = 0;
			
		}
		
	}
}

void print_cards_in_hand(struct player_t *player)
{
    int i;
	for (i=0; i < player->last_t_card_in_hand ; i++)
    {
        printf("\nName: %s", player->cards_in_hand[i].name);
        printf("\nPower: %d", player->cards_in_hand[i].power);
        printf("\nLife: %d", player->cards_in_hand[i].life);
        printf("\nMana_cost: %d", player->cards_in_hand[i].mana_cost);
    }
}


