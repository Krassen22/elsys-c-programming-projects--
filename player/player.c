#include <stdio.h>
#include "player.h"


int down_hp(struct player_t *player, int hp)
{
    if (hp < player->hp_player)
    {
        player->hp_player -=hp;
        printf("\nHP_PLAYER:(after down hp) %d", player->hp_player);
    }
    else
    {
        player->hp_player = 0;
        printf("\nPLAYER is dead!: %d", player->hp_player);

    }

}

int up_hp(struct player_t *player, int hp)
{
    if((hp + player->hp_player) <= 30)
    {
        player->hp_player += hp;
        printf("\nHP_PLAYER:(after up   hp) %d", player->hp_player );
    }
    else
    {
        player->hp_player = 30;
        printf("\nHP_PLAYER:(after up   hp) %d", player->hp_player);
    }

}



int main()
{
struct card_t card_to_push;
struct player_t player;
//struct card_t one = { "card_one", 1, 7, 0};
//play_card_from_hard(&player, &one);
down_hp(&player, 5);
up_hp(&player,2);
//turn_begin(&player);
    return 0;
}



