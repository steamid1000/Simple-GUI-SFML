#include <SFML/Graphics.hpp>
#include <GUI.hpp>
#include "MenuScene.hpp"
#include "GameScene.hpp"

/*// & I think the Onsize change and The auto size on text are fighting with each other as the characterSize is not changing */
short width = 600, height = 400;
sf::Font font;
short sceneIndex = 0;
int main()
{
    srand(time(0)); //^ initializing for the random variables
    // I want this file to be as clean as possible maybe after a scene manager this will be accomplished
    SetFont(font, "res/times.ttf"); //& this function should be called only once
    sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(width, height), "GUI Testing");
    // window->setFramerateLimit(60);

    
    MenuScene menu(*window);
    GameScene game(*window);

    Scene *Scenes[2];
    Scenes[0] = &menu;
    Scenes[1] = &game;

    while (window->isOpen())
    {
        sf::Event events;
        while (window->pollEvent(events))
        {
            if (events.type == sf::Event::Closed)
            {
                window->close();
                return EXIT_SUCCESS;
            }
            
            //& resize code
            if (events.type == sf::Event::Resized)
            {
                width = window->getSize().x;
                height = window->getSize().y;

                std::string words[]{"what","game","good"};
                window->setSize(sf::Vector2u(width,height));
                logData("the window has been resized");
                logData("Width: ");
                logData(width);
                logData("Height: ");
                logData(height);

                //Temp
                logData(words);

            }
            

            window->clear(sf::Color(110, 110, 90));
            Scenes[sceneIndex]->render();
            window->display();
            
        }

    }

    return EXIT_SUCCESS;
}