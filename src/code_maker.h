#ifndef CODE_MAKER_H
#define CODE_MAKER_H

#include "base_player.h"

class code_maker: public base_player
{
    public:
        code_maker() {};
        ~code_maker() {};

        void init_game();
        void play_round();

    private:
        
};

#endif // CODE_MAKER_H