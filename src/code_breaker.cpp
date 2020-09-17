#include <stdio.h>
#include "code_breaker.h"

void code_breaker::init_game(state_t value)
{
    printf("Breaker: Initialising game!!!\n");
}

void code_breaker::play_round(state_t &value)
{
    value.code = code_t(blue, blue, yellow, yellow);
    _round++;
}