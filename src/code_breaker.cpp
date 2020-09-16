#include <stdio.h>
#include "code_breaker.h"

void code_breaker::init_game()
{
    printf("Breaker: Initialising game!!!\n");
}

void code_breaker::play_round()
{
    printf("Breaker: Playing round %d!!!\n", _round);
    _round++;
}