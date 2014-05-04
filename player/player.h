#ifndef __PLAYER__
#define __PLAYER__
#include "..\manapool\manapool.h"
#define HANDSZ 10


struct player_t
{
    char name_player[255];
    struct deck_t deck_player;
    struct card_t *cards_in_hand;
    int last_t_card_in_hand;
    struct manapool_t mana_player;
    int hp_player;

};

void init_player(struct player_t *player);
void down_hp(struct player_t *player, int hp);
void up_hp(struct player_t *player, int hp);
void turn_begin(struct player_t *player);
void play_card_from_hand(struct player_t *player, char *card_name);
void print_cards_in_hand(struct player_t player);



#endif

