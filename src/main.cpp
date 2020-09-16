#include <vector>
#include "code_breaker.h"
#include "code_maker.h"

int main()
{
    code_breaker breaker;
    code_maker maker;
    std::vector<base_player *> players;
    int iterations = 10;

    // Initialise players
    maker.init_game();
    breaker.init_game();

    // Populate vector - the order counts during execution
    players.push_back(&breaker);    // First the code-breaker
    players.push_back(&maker);      // Then the code-maker

    while (iterations-- != 0)
    {
        for (auto it = players.begin(); it != players.end(); it++)
        {
            (*it)->play_round();
        }
    }

    return 0;
}