#include <stdio.h>
#include "code_maker.h"

void code_maker::init_game()
{
    printf("Maker: Initialising game!!!\n");
}

void code_maker::play_round()
{
    printf("Maker: Playing round %d!!!\n", _round);
    _round++;
}