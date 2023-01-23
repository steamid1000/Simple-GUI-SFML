#pragma once
#include "Scene.hpp"
#include <GUI.hpp>

extern short sceneIndex;

class GameScene : public Scene
{
private:
    GUI::Button* gameMode;
    sf::RenderWindow *internalwindow;    
public:
    GameScene(sf::RenderWindow&);
    ~GameScene();

    void setup();
    void render();
};

GameScene::GameScene(sf::RenderWindow& window)
{
    internalwindow = &window;
    
    gameMode = new GUI::Button("Game",internalwindow);
    setup();
}

GameScene::~GameScene()
{
    // delete internalwindow; //! Could be problamatic if 
                           //! it deletes the original window oject
}

void GameScene::setup(){
    gameMode->SetInnerText("Game is on!",50);
    gameMode->SetPosition(sf::Vector2f(width/2-gameMode->getBounds().width/2,height/2));
    printf("The game scene has loaded succesfully\n");
}

void GameScene::render(){

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                printf("The game Scene has been closed\n");
                sceneIndex--;
                return;
            }
            
     gameMode->render();
     
}
