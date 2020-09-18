#include <stdio.h>
#include <algorithm>
#include "code_maker.h"

void code_maker::init_game(state_t value)
{
    printf("Maker: Initialising game!!!\n");
    printf("The KEY: [%d, %d, %d, %d]\n", value.code.peg1, value.code.peg2, value.code.peg3, value.code.peg4);
    _key = value.code;
    _round = 0;
}

void code_maker::play_round(state_t &value)
{
    _check_code(value);
    // if (value.assess.right_position != 0)
    //     printf("Maker: Got %d right positions!!!\n", value.assess.right_position);
    // if (value.assess.right_colours != 0)
    //     printf("Maker: Got %d right colors!!!\n", value.assess.right_colours);
    _round++;
}

/**
 * \brief Check code:
 * This function checks if the code in value match the
 * master-code. Specifically, it gives an account of
 * the number of matches or the number of colors otherwise.
 * \param value: A value respresenting a game state
 */
void code_maker::_check_code(state_t &value)
{
    color *code = static_cast<color *>(&value.code.peg1);
    color *master_code = static_cast<color *>(&_key.peg1);

    // Reset counters
    value.assess.right_position = 0;
    value.assess.right_colours = 0;

    // Check for right position
    for (auto i=0; i<4; i++)
    {
        if (*(code++) == *(master_code++))
            value.assess.right_position++;
    }
    // Check for right color
    std::vector<color>colors = _list_colors(value.code);
    master_code = static_cast<color *>(&_key.peg1);
    for (auto it=colors.begin(); it!=colors.end(); it++)
    {
        for (auto i=0; i<4; i++)
        {
            if (master_code[i] == *it)
            {
                value.assess.right_colours++;
                break;
            }
        }
    }
    // At this point the number of right colors give an account
    // of the ones in the right position and so, they need to
    // be removed
    value.assess.right_colours -= value.assess.right_position;
}

/**
 * \brief Create a list of unique colors:
 * This function creates a vector with unique elements
 * representing the colors in value
 * \param value: A code
 * \return std::vector<color>
 */
std::vector<color> code_maker::_list_colors(code_t value)
{
    std::vector<color> color_list{value.peg1, value.peg2, value.peg3, value.peg4};
    std::sort(color_list.begin(), color_list.end());
    color_list.erase(std::unique( color_list.begin(), color_list.end() ), color_list.end());
    return color_list;
}