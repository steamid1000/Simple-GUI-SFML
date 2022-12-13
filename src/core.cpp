#include <iostream>
#include <SFML/Graphics.hpp>
#include <GUI.hpp>
#include "Buttons.hpp"
#include "Lables.hpp"


/*// & I think the Onsize change and The auto size on text are fighting with each other as the characterSize is not changing */
const short width = 600,height = 400;
sf::Font font;

int main()
{
    //I want this file to be as clean as possible maybe after a scene manager this will be accomplished
    SetFont(font,"times.ttf");
    sf::RenderWindow window(sf::VideoMode(width,height),"GUI Testing");
    // window.setFramerateLimit(60);
    
    sf::Event events;

    Button play("play",&window);
    Button quit("quit",&window);
    Button settings("Authors",&window);
    Lable greet(&window);   
    Button help("help",&window);
    Button test("test",&window);
    
    play.SetInnerText("Play",10);
    greet.SetInnerText("PONG - THE GAME");
    quit.SetInnerText("Quit");
    settings.SetInnerText("Authors");
    help.SetInnerText("game like why not now",90); //The size 90 will not applied as the SetSize function is called on this object
    
    //testing the function
    test.SetInnerText("Working",90); // This size will be set as the user havent provided any size for the button object

    play.SetSize(sf::Vector2f(100,30));
    // // settings.SetSize(sf::Vector2f(100,30));
    quit.SetSize(sf::Vector2f(100,30));
    greet.SetSize(25);
    help.SetSize(sf::Vector2f(500,40)); 

    greet.SetColor(Vector4i(10,10,10));
    help.SetColor(Vector4i(190,145,160));

    play.align(0);
    help.SetPosition(sf::Vector2f(help.center.x - help.getBounds().width/2,height - help.getBounds().height - 10));

    settings.SetPosition(sf::Vector2f(quit.center.x - settings.getBounds().width/2,play.GetPosition().y + settings.GetSize().y + 10));
    quit.SetPosition(sf::Vector2f(quit.center.x - quit.getBounds().width/2,settings.GetPosition().y + play.GetSize().y + 10));

    greet.SetPosition(sf::Vector2f(greet.center.x,play.GetPosition().y - 60));
    
    while (window.isOpen())
    {
        while (window.pollEvent(events))
        {
            if (events.type == sf::Event::Closed)
            {
                window.close();
                return EXIT_SUCCESS;
            }
            

            window.clear(sf::Color(110,110,90));
            play.render();
            quit.render();
            settings.render();
            greet.render();
            help.render();
            test.render();
            window.display();
            
        }
        
    }
    
    return EXIT_SUCCESS;
}