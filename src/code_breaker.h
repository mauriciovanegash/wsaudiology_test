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
        // Variables
        std::vector<state_t> _game_state;
        std::vector<color> _right_colors;
        code_t _best_guess;
        code_t _just_a_guess;
        color _current_color = yellow;
        uint32_t _num_colors = 0;

        // Functions
        code_t _set_a_code(state_t value);
};

/*! \class code_breaker code_breaker.h "code_breaker.h"
 *  \brief This is the code-breaker class.
 * This class inheritates from pure virtual class base_player in which
 * the dependency-injection pattern is defined for two main functions.
 */

/*! \fn void code_breaker::init_game(state_t value)
 *  \brief Init game
 *  This function initialises the object according to
 *  the information in value.
 *  \param value: A value respresenting a game state - it is of type "state_t"
 */

/*! \fn void code_breaker::play_round(state_t &value)
 *  \brief Play round
 *  This function executes a round in the game. It purpose is to provide
 *  generate a code in the light of the information provided by the code-
 *  maker in value. The model to crack the code is brute force!
 *  \param value: Reference to game state - it is of type "state_t"
 */

#endif // CODE_BREAKER_H