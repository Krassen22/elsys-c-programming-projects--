#ifndef __PLAYER__
#define __PLAYER__
#include "..\deck\deck.h"
#include "..\manapool\manapool.h"
#define HANDSZ 10


struct player_t
{
    char name_player[255];
    struct deck_t player_deck;
    struct card_t cards_in_hand[HANDSZ];
    struct manapool_t mana_player;
    int hp_player;

};

int down_hp(struct player_t *player, int hp);
int up_hp(struct player_t *player, int hp);
//struct card_t play_card_from_hard(struct player_t *player, struct deck_t *player_deck);
//void turn_begin(struct player_t *player);





#endif

