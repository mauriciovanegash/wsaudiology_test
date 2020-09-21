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

typedef struct peg_code
{
    //! Defines code-color at position 1
    color peg1;
    //! Defines code-color at position 2
    color peg2;
    //! Defines code-color at position 3
    color peg3;
    //! Defines code-color at position 4
    color peg4;
    //! Constructor
    peg_code() : peg1(blue), peg2(blue), peg3(blue), peg4(blue) {};
    //! Constructor overload
    peg_code(color p1, color p2, color p3, color p4) : peg1(p1), peg2(p2), peg3(p3), peg4(p4) {};
    //!  Exchanges the values at index1 and index2.
    void swap(uint32_t index1, uint32_t index2){
        if ((index1 > 4) || (index2 > 4))
            return;
        color *ptrToThis = static_cast<color *>(&this->peg1);
        color temp = ptrToThis[index1];
        ptrToThis[index1] = ptrToThis[index2];
        ptrToThis[index2] = temp;
    }
    //! Shift-left operator
    peg_code operator <<=(int val){
        peg_code value = *this;
        for (auto i=0; i<val; i++)
        {
            peg4 = value.peg1; peg1 = value.peg2; peg2 = value.peg3; peg3 = value.peg4;
            value = *this;
        }
        return *this;
    }
    //! Shift-right operator
    peg_code operator >>=(int val){
        peg_code value = *this;
        for (auto i=0; i<val; i++)
        {
            peg2 = value.peg1; peg3 = value.peg2; peg4 = value.peg3; peg1 = value.peg4;
            value = *this;
        }
        return *this;
    }
    //! Equality operator
    bool operator ==(peg_code value) const{
        return ((peg1 == value.peg1) && (peg2 == value.peg2) && (peg3 == value.peg3) && (peg4 == value.peg4));
    }
    //! Inequality operator
    bool operator !=(peg_code value) const{
        return ((peg1 != value.peg1) || (peg2 != value.peg2) || (peg3 != value.peg3) || (peg4 != value.peg4));
    }
} code_t;
/**< code_t is of type struct peg_code */
/*! \struct peg_code base_player.h "base_player.h"
 *  \brief This is the struct used to define a code.
 * It has four variable members representing the pegs in the game.
 */

typedef struct code_comparison
{
    //! Defines the number of right colors in the right positions
    uint32_t right_position;
    //! Defines the number of right colors
    uint32_t right_colours;

    //! Constructor
    code_comparison() : right_position(0), right_colours(0) {};
    //! Constructor overload
    code_comparison(uint32_t val1, uint32_t val2) : right_position(val1), right_colours(val2) {};
    //! Equality operator
    bool operator ==(code_comparison value) const{
        return ((right_position == value.right_position) && (right_colours == value.right_colours));
    }
    //! Inequality operator
    bool operator !=(code_comparison value) const{
        return ((right_position != value.right_position) || (right_colours != value.right_colours));
    }
} comp_t;
/**< comp_t is of type struct code_comparison */
/*! \struct code_comparison base_player.h "base_player.h"
 *  \brief This is the struct used to evaluate the number of hits in the code.
 * It has two variable members representing the number of both the right positions
 * and right colors in the code.
 */

typedef struct game_state
{
    //! Defines the different colors for the four positions
    code_t code;
    //! Defines the assesment of the code in light of the master-code
    comp_t assess;
    //! Constructor
    game_state() : code(), assess() {};
    //! Constructor overload
    game_state(code_t val) : code(val), assess() {};
} state_t;
/**< state_t is of type struct game_state */
/*! \struct game_state base_player.h "base_player.h"
 *  \brief This is the struct used to define the state of the game at any time.
 * It has two variable members representing the code provided by the code-breaker
 * and the assess provided by the code-maker.
 */

class base_player
{
    public:
        base_player() {};
        virtual ~base_player() {};

        virtual void init_game(state_t value) = 0;
        virtual void play_round(state_t &value) = 0;

    protected:
        //! Defines the number of rounds since the game start
        int _round = 0;
};
/*! \class base_player base_player.h "base_player.h"
 *  \brief This is a wrap interface for a player.
 * This is a pure virtual class used to define the dependency-injection
 * pattern for the players in the Mastermind game.
 */

/*! \fn virtual base_player::~base_player() {}
 *  \brief Destructor:
 *  It is delared as virtual in order to be sure that the destructor of any
 *  derived class is called instead.
 */

/*! \fn void base_player::init_game(state_t value)
 *  \brief Init game:
 *  This function initialises the object according to
 *  the information in value.
 *  \param value: A value respresenting a game state
 */

/*! \fn void base_player::play_round(state_t &value)
 *  \brief Play round:
 *  This function executes a round in the game.
 *  \param value: Reference to game state
 */

#endif // BASE_PLAYER_H