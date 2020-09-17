#include <stdio.h>
#include "code_breaker.h"

void code_breaker::init_game(state_t value)
{
    printf("Breaker: Initialising game!!!\n");
}

void code_breaker::play_round(state_t &value)
{
    //! Take a copy of the state of the game
    _game_state.push_back(value);
    //! Generate a new code
    value.code = _set_a_code(value);
    _round++;
}

/**
 * \brief Strategy for guessing a code
 * This function implements a brute force mechanism to crack the master code.
 * It first finds the colors used in the master code and then the position.
 * \param value: Reference to game state - it is of type "state_t"
 * \return a code_t
 */
code_t code_breaker::_set_a_code(state_t value)
{
    if ((value.assess.right_colours+value.assess.right_position > _num_colors) && ((value.assess.right_colours != 0) || (value.assess.right_position != 0)))
    {
        _right_colors.push_back(static_cast<color>(static_cast<int>(_current_color) - 1)); //! The algorithm gets here after increasing color
        _num_colors++;
    }
    code_t code(_current_color, _current_color, _current_color, _current_color);
    color *ptrToCode = static_cast<color *>(&code.peg1);
    int i = 0;
    for (auto it=_right_colors.begin(); it<_right_colors.end(); it++)
    {
        ptrToCode[i] = *it;
        i = i%4+1; //! Needed to avoid and exception as only four words are reserved for code
    }
    //! Change color for next round
    _current_color = static_cast<color>((static_cast<int>(_current_color) + 1)%6);
    return code;
}