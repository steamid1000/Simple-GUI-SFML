#pragma once
#include "Scene.hpp"

extern short sceneIndex;
// extern sf::RenderWindow *window;

class TestScene : public Scene{
    GUI::Button* back;
public:
    TestScene();
    ~TestScene();
    void setup();
    void render();
};

TestScene::TestScene(){
    back = new GUI::Button("backButton");
    setup();

}

TestScene::~TestScene(){
    logData("The Test Scene has been closed.");
}

void TestScene::setup(){
    back->SetInnerText("Back To Main Menu");
    back->align(0);
    back->SetColor(Vector4i(150,100,190,1));
    auto backAction = [&]()
    { --sceneIndex; };
    back->setAction(backAction);
}

void TestScene::render(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) --sceneIndex;
    
    window->clear();
    back->render();
    window->display();
}