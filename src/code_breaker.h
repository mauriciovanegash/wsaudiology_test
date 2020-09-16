#ifndef CODE_BREAKER_H
#define CODE_BREAKER_H

#include "base_player.h"

class code_breaker: public base_player
{
    public:
        code_breaker() {};
        ~code_breaker() {};

        void init_game();
        void play_round();

    private:
        
};

#endif // CODE_BREAKER_H