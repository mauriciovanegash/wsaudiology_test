#include <stdio.h>
#include <vector>
#include "code_breaker.h"
#include "code_maker.h"

/**
 * \brief Main application
 * This is an example of how to use both the \class code_maker
 */
int main()
{
    code_breaker breaker;
    code_maker maker;
    std::vector<base_player *> players;
    int iterations = 10; //! Define the number of trials for the code-breaker
    state_t key(code_t(yellow, blue, cyan, red));
    state_t code;
    const comp_t cracked_value(4, 0);

    //! Initialise players
    maker.init_game(key);
    breaker.init_game(code);

    //! Populate vector - the order counts during execution
    players.push_back(&breaker);    //! First the code-breaker
    players.push_back(&maker);      //! Then the code-maker

    while (iterations-- != 0)
    {
        //! Play a round
        printf("Main: Playing round %d!!!\n", 10-iterations);
        for (auto it = players.begin(); it != players.end(); it++)
        {
            (*it)->play_round(code);
        }
        //! Check if code has been cracked
        if (code.assess == cracked_value)
        {
            printf("Main: Code has been cracked in %d iterations!!!\n", 10-iterations);
            iterations = 0;
        }
    }

    return 0;
}