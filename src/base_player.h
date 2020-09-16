#ifndef BASE_PLAYER_H
#define BASE_PLAYER_H

class base_player
{
    public:
        base_player() {};
        ~base_player() {};

        virtual void init_game() = 0;
        virtual void play_round() = 0;

    protected:
        int _round = 0;

};

#endif // BASE_PLAYER_H