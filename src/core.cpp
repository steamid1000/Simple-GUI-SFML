#include <SFML/Graphics.hpp>
#include <GUI.hpp>
#include <SceneManager.hpp>
#include <MenuScene.hpp>
#include <TestingScene.hpp>

sf::RenderWindow *window;
short width = 1300, height = 600;
sf::Font font;

int main()
{
    srand(time(0)); //^ initializing for the random variables
    // I want this file to be as clean as possible maybe after a scene manager this will be accomplished
    GUI::SetFont(font, "res/times.ttf"); //& this function should be called only once
    window = new sf::RenderWindow(sf::VideoMode(width, height), "Simple GUI");
    window->setFramerateLimit(60);


    // Creating an array of Scenes by refering them as their base class 'Scene'
    MenuScene* menu = NULL;
    TestScene* test = NULL;

    menu = new MenuScene();
    test = new TestScene();

    SM.addScene("MenuScene",menu);
    SM.addScene("LevelScene",test);

    SM.switchScene("MenuScene");
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
        }
        
        SM.update();
        // & Each Scene should have its own clear screen and display calls
    }

    return EXIT_SUCCESS;
}