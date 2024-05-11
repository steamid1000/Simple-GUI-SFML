#pragma once
#include "Scene.hpp"


extern short sceneIndex;
extern sf::Font font;
extern sf::RenderWindow *window;

class MenuScene : public Scene
{
private:
    GUI::Button *play;
    GUI::Button *quit;
    GUI::Button *settings;
    // GUI::Lable *greet;
    GUI::Button *help;
    GUI::Button *test;

public:
    MenuScene();

    ~MenuScene();
    void setup();
    void render();
};

MenuScene::MenuScene()
{
    setup();
}

MenuScene::~MenuScene()
{
   
}

void MenuScene::setup()
{
    //Defining the actions for the buttons
    auto incre = [](){
        ++sceneIndex;
    };

    auto quitaction = [&]()
    { window->close(); };
    
    play = new GUI::Button("play");
    quit = new GUI::Button("quit");
    settings = new GUI::Button("Authors");
    // greet = new GUI::Lable();
    help = new GUI::Button("help");
    test = new GUI::Button("test");



    play->SetInnerText("Play", 30);
    //  greet->SetInnerText("PONG - THE GAME");
    quit->SetInnerText("Quit");
    settings->SetInnerText("Authors");
    help->SetInnerText("game like why not now", 50); // The size 90 will not applied as the SetSize function is called on this object

    // testing the function
    test->SetInnerText("Working", 70); // This size will be set as the user havent provided any size for the button object

    play->SetSize(sf::Vector2f(100, 30));
    quit->SetSize(sf::Vector2f(100, 30));
    // greet->SetSize(25);
    help->SetSize(sf::Vector2f(500, 40));

    // greet->SetColor(Vector4i(10, 10, 10));
    help->SetColor(Vector4i(190, 145, 160));

    play->align(0);
    help->SetPosition(sf::Vector2f(help->center.x - help->getBounds().width / 2, height - help->getBounds().height - 10));

    settings->SetPosition(sf::Vector2f(quit->center.x - settings->getBounds().width / 2, play->GetPosition().y + settings->GetSize().y + 10));
    quit->SetPosition(sf::Vector2f(quit->center.x - quit->getBounds().width / 2, settings->GetPosition().y + play->GetSize().y + 10));

    // greet->SetPosition(sf::Vector2f(greet->center.x, play->GetPosition().y - 60));


    //Setting up the actions for the buttons
    quit->setAction(quitaction);
    play->setAction(incre);

    printf("The Scene has been setup\n");
}

void MenuScene::render()
{
    window->clear(sf::Color(110, 110, 90));
    play->render();
    // greet->render();
    test->render();
    help->render();
    quit->render();
    settings->render();
    window->display();
}