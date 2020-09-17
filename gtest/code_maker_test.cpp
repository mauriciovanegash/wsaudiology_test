#include <gtest/gtest.h>
#include "../src/code_maker.h"

TEST(GameTest, Maker) {
    code_t master_code(yellow, blue, red, violet);
    state_t game_state(master_code);
    code_maker player;
    player.init_game(game_state);
    // Iteration 1
    game_state.code = code_t(yellow, blue, green, cyan);
    comp_t comparison = comp_t(2, 0);
    player.play_round(game_state);
    ASSERT_EQ(comparison, game_state.assess);
    // // Iteration 2
    // game_state.code = code_t(green, cyan, red, violet);
    // comparison = comp_t(2, 0);
    // player.play_round(game_state);
    // ASSERT_EQ(comparison, game_state.assess);
    // // Iteration 3
    // game_state.code = code_t(red, violet, yellow, blue);
    // comparison = comp_t(0, 4);
    // player.play_round(game_state);
    // ASSERT_EQ(comparison, game_state.assess);
    // // Iteration 4
    // game_state.code = code_t(yellow, blue, violet, red);
    // comparison = comp_t(2, 2);
    // player.play_round(game_state);
    // ASSERT_EQ(comparison, game_state.assess);
    // // Iteration 5
    // game_state.code = master_code;
    // comparison = comp_t(2, 2);
    // player.play_round(game_state);
    // ASSERT_EQ(comparison, game_state.assess);
}