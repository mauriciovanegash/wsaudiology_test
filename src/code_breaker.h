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
        //! A vector with the history of the game state
        std::vector<state_t> _game_state;
        //! A vector containing the right colors in the master-code
        std::vector<color> _right_colors;
        //! Defines the best code guess
        code_t _best_guess;
        //! Auxiliary variable to guess a code
        code_t _just_a_guess;
        //! Auxiliary variable used during the search for the right colors
        color _current_color = yellow;
        //! Auxiliary variable to count the number of colors found
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
 *  \brief Init game:
 *  This function initialises the object according to
 *  the information in value.
 *  \param value: A value respresenting a game state
 */

/*! \fn void code_breaker::play_round(state_t &value)
 *  \brief Play round:
 *  This function executes a round in the game. It purpose is to provide
 *  generate a code in the light of the information provided by the code-
 *  maker in value. The model to crack the code is brute force!
 *  \param value: Reference to game state
 */

#endif // CODE_BREAKER_H