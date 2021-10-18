#include <SFML/Graphics.h>

#include "game.h"

int main(void)
{
    game_t game;

    game_init(&game);
    train_add_wagon(&game.train, game.texture_wagon);
    while (sfRenderWindow_isOpen(game.window)) {
        game_event(&game);
        game_update(&game);
        game_draw(&game);
    }
    game_end(&game);
    sfRenderWindow_destroy(game.window);
}
