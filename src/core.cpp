#include <SFML/Graphics.hpp>
#include <GUI.hpp>
#include "MenuScene.hpp"
#include "TestingScene.hpp"

// Should we make the window object universal so that we dont have to make copies of it every time we create a new object
// Lets try this
sf::RenderWindow* window;

/*// & I think the Onsize change and The auto size on text are fighting with each other as the characterSize is not changing */
short width = 600, height = 400;
sf::Font font;
short sceneIndex = 0;

int main() 
{
    srand(time(0)); //^ initializing for the random variables
    // I want this file to be as clean as possible maybe after a scene manager this will be accomplished
    SetFont(font, "res/times.ttf"); //& this function should be called only once
    window = new sf::RenderWindow(sf::VideoMode(width, height), "GUI Testing");
    window->setFramerateLimit(60);

    // Creating an array of Scenes by refering them as their base class 'Scene'
    MenuScene menu;
    TestScene test;

    Scene *Scenes[2];
    Scenes[0] = &menu; 
    Scenes[1] = &test;

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
            
            //& Prevent resize code
            if (events.type == sf::Event::Resized)
            {                
                window->setSize(sf::Vector2u(width,height));
            }
            
            Scenes[sceneIndex]->render();           
            // & Each Scene should have its own clear screen and display calls
        }

    }

    return EXIT_SUCCESS;
}