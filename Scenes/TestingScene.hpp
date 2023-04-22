#pragma once
#include "Scene.hpp"

extern short sceneIndex;

class TestScene : public Scene{
    sf::RenderWindow * internalwindow;
public:
    TestScene(sf::RenderWindow &);
    ~TestScene();
    void setup();
    void render();
};

TestScene::TestScene(sf::RenderWindow &copy){
    internalwindow = &copy;

}

TestScene::~TestScene(){
    logData("The Test Scene has been closed.");
    setup();
}

void TestScene::setup(){}

void TestScene::render(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) --sceneIndex;
    
    internalwindow->clear();
    internalwindow->display();
}