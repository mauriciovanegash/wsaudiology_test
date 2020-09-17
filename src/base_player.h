#ifndef BASE_PLAYER_H
#define BASE_PLAYER_H

#include <stdint.h>

/*! This enum type is used to define the possible colors in the game for the pegs */
enum color
{
    yellow = 0, /*!< yellow */
    blue,       /*!< blue */
    red,        /*!< red */
    green,      /*!< green */
    cyan,       /*!< cyan */
    violet      /*!< violet */
};

typedef struct _peg_code
{
    color peg1;
    color peg2;
    color peg3;
    color peg4;
    _peg_code() : peg1(blue), peg2(blue), peg3(blue), peg4(blue) {};
    _peg_code(color p1, color p2, color p3, color p4) : peg1(p1), peg2(p2), peg3(p3), peg4(p4) {};
} code_t;
/**< code_t is of type struct _peg_code */
/*! \struct _peg_code base_player.h "base_player.h"
 *  \brief This is the struct used to define a code.
 * It has four variable members representing the pegs in the game.
 */

typedef struct _code_comparison
{
    uint32_t right_position;
    uint32_t right_colours;

    _code_comparison() : right_position(0), right_colours(0) {};
    _code_comparison(uint32_t val1, uint32_t val2) : right_position(val1), right_colours(val2) {};

    bool operator ==(_code_comparison value){
        return (right_position == value.right_position && right_colours == value.right_colours);
    }
} comp_t;
/**< comp_t is of type struct _code_comparison */
/*! \struct _code_comparison base_player.h "base_player.h"
 *  \brief This is the struct used to evaluate the number of hits in the code.
 * It has two variable members representing the number of both the right positions
 * and right colors in the code.
 */

typedef struct _game_state
{
    code_t code;
    comp_t assess;
    _game_state() : code(), assess() {};
    _game_state(code_t val) : code(val), assess() {};
} state_t;
/**< state_t is of type struct _game_State */
/*! \struct _game_state base_player.h "base_player.h"
 *  \brief This is the struct used to define the state of the game at any time.
 * It has two variable members representing the code provided by the code-breaker
 * and the assess provided by the code-maker.
 */

class base_player
{
    public:
        base_player() {};
        virtual ~base_player() {};

        virtual void init_game(state_t) = 0;
        virtual void play_round(state_t &) = 0;

    protected:
        int _round = 0;

};

/*! \class base_player base_player.h "base_player.h"
 *  \brief This is a wrap interface for a player.
 * This is a pure virtual class used to define the dependency-injection
 * pattern for the players in the Mastermind game.
 */

/*! \fn virtual ~base_player() {}
 *  \brief Destructor
 *  It is delared as virtual in order to be sure that the destructor of any
 *  derived class is called instead.
 */

/*! \fn void base_player::init_game(state_t value)
 *  \brief Init game
 *  This function initialises the object according to
 *  the information in \param value.
 *  \param value: A value respresenting a game state - it is of type "state_t"
 */

/*! \fn void base_player::play_round(state_t &value)
 *  \brief Play round
 *  This function executes a round in the game.
 *  \param value: Reference to game state - it is of type "state_t"
 */

#endif // BASE_PLAYER_H