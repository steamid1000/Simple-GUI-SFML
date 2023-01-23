#include <SFML/Graphics.hpp>
#include "MenuScene.hpp"
#include "GameScene.hpp"

/*// & I think the Onsize change and The auto size on text are fighting with each other as the characterSize is not changing */
const short width = 600, height = 400;
sf::Font font;
short sceneIndex = 0;
int main()
{
    // I want this file to be as clean as possible maybe after a scene manager this will be accomplished
    SetFont(font, "res/times.ttf"); //& this function should be called only once
    sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(width, height), "GUI Testing");
    // window->setFramerateLimit(60);

    sf::Event events;

    MenuScene menu(*window);
    GameScene game(*window);

    Scene *Scenes[2];
    Scenes[0] = &menu;
    Scenes[1] = &game;

    while (window->isOpen())
    {
        while (window->pollEvent(events))
        {
            if (events.type == sf::Event::Closed)
            {
                window->close();
                return EXIT_SUCCESS;
            }

            window->clear(sf::Color(110, 110, 90));
            Scenes[sceneIndex]->render();
            window->display();
        }
    }

    return EXIT_SUCCESS;
}