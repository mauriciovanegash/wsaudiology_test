#ifndef CODE_MAKER_H
#define CODE_MAKER_H

#include <vector>
#include "base_player.h"

class code_maker: public base_player
{
    public:
        code_maker() {};
        ~code_maker() {};

        void init_game(state_t value);
        void play_round(state_t &value);

    private:
        // Variables
        code_t _key;

        // Functions
        void _check_code(state_t &value);
        std::vector<color> _list_colors(code_t value);
};

/*! \class code_maker code_maker.h "code_maker.h"
 *  \brief This is the code-maker class.
 * This class inheritates from pure virtual class base_player in which
 * the dependency-injection pattern is defined for two main functions.
 */

/*! \fn void code_maker::init_game(state_t value)
 *  \brief Init game
 *  This function initialises the object according to
 *  the information in value.
 *  \param value: A value respresenting a game state - it is of type "state_t"
 */

/*! \fn void code_maker::play_round(state_t &value)
 *  \brief Play round
 *  This function executes a round in the game. It purpose is to provide
 *  feedback to the player "code-breaker" regarding their code guess. The
 *  code is part of the game-state value contained in value.
 *  \param value: Reference to game state - it is of type "state_t"
 */

#endif // CODE_MAKER_H