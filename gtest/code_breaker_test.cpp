#include <gtest/gtest.h>
#include "../src/code_breaker.h"

TEST(GameTest, Breaker) {
    state_t game_state(code_t(yellow, blue, red, violet));
    code_breaker player;
    player.init_game(game_state);
    // Iteration 1
    code_t just_a_code = code_t(yellow, blue, green, cyan);
    game_state.code = just_a_code;
    player.play_round(game_state);
    ASSERT_NE(just_a_code, game_state.code);
    // // Iteration 2
    // just_a_code = code_t(yellow, violet, red, cyan);
    // game_state.code = just_a_code;
    // player.play_round(game_state);
    // ASSERT_NE(just_a_code, game_state.code);
}