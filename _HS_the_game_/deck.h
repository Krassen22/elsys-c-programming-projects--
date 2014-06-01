#ifndef __CARD__
#define __CARD__
#define DECKSZ 30
// push_card, draw_card, look_card

struct card_t
{
    char* name;
    int power, life, mana_cost;
};

struct deck_t
{
    struct card_t cards[DECKSZ];
    int top;
};

void init_deck(struct deck_t *player_deck);
int is_stack_empty(struct deck_t *player_deck);
int is_stack_full(struct deck_t *player_deck);
void push_card(struct card_t card_to_push, struct deck_t *player_deck);
struct card_t draw_card(struct deck_t *player_deck);
void look_card(struct deck_t player_deck);
void print_stack(struct deck_t player_deck);


#endif

