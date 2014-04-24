#ifndef __CARD__
#define __CARD__
#define DECKSZ 3
// push_card, draw_card, look_card

struct card_t
{
    char name[255];
    int power, live, mana_cost;
};

struct deck_t
{
    struct card_t cards[DECKSZ];
    int top;
};

void init_deck(struct deck_t *player_deck);
int is_stack_empty(struct deck_t *player_deck);
int is_stack_full(struct deck_t *player_deck);
struct card_t push_card(struct card_t card_to_push, struct deck_t *player_deck);
struct card_t draw_card(struct deck_t *player_deck);
struct card_t look_card(struct deck_t player_deck);


#endif

