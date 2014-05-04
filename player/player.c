#include <stdio.h>
#include "player.h"


void init_player(struct player_t *player)
{
        player->hp_player = 30;
        init_mana(&player->mana_player);
        
        for(player->last_t_card_in_hand = 0; player->last_t_card_in_hand <= 4; player->last_t_card_in_hand++)
		{
			player->cards_in_hand[player->last_t_card_in_hand] = draw_card(&player->deck_player);
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


void turn_begin(struct player_t *player)
{
	if (player->last_t_card_in_hand <= HANDSZ)
	{
	
			if (player->deck_player.top != 0)
			{
					player->cards_in_hand[player->last_t_card_in_hand] = draw_card(&player->deck_player);
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
			player->cards_in_hand[e].live = 0;
			player->cards_in_hand[e].power = 0;
			player->cards_in_hand[e].mana_cost = 0;
		}
		
	}
}

void print_cards_in_hand(struct player_t player)
{
    int i;
	for (i=0; i < player.last_t_card_in_hand ; i++)
    {
        printf("\nName: %s", player.cards_in_hand[i].name);
        printf("\nPower: %d", player.cards_in_hand[i].power);
        printf("\nLive: %d", player.cards_in_hand[i].live);
        printf("\nMana_cost: %d", player.cards_in_hand[i].mana_cost);
    }
}

int main()
{
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

    return 0;
}



