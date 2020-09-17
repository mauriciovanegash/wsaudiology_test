#ifndef CODE_BREAKER_H
#define CODE_BREAKER_H

#include <vector>
#include "base_player.h"

class code_breaker: public base_player
{
    public:
        code_breaker() {};
        ~code_breaker() {};

        void init_game(state_t value);
        void play_round(state_t &value);

    private:
};

/*! \class code_breaker code_breaker.h "code_breaker.h"
 *  \brief This is the code-breaker class.
 * This class inheritates from pure virtual class base_player in which
 * the dependency-injection pattern is defined for two main functions.
 */

/*! \fn void code_breaker::init_game(state_t value) 
 *  \brief Init game
 *  This function initialises the object according to
 *  the information in \param value.
 *  \param value: A value respresenting a game state - it is of type "state_t"
 */

/*! \fn void code_breaker::play_round(state_t &value)
 *  \brief Play round
 *  This function executes a round in the game. It purpose is to provide
 *  generate a code in the light of the information provided by the code-
 *  maker in \param value.
 *  \param value: Reference to game state - it is of type "state_t"
 */

#endif // CODE_BREAKER_H