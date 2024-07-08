#pragma once
#include "Scene.hpp"

extern short sceneIndex;
// extern sf::RenderWindow *window;

class TestScene : public Scene
{
    GUI::Button *back;
    GUI::Panels backImg;
    GUI::Panels backImg2;
    unsigned short index;
public:
    TestScene();
    ~TestScene();
    void setup();
    void render();
};

TestScene::TestScene()
{
    back = new GUI::Button("backButton");
    index = 0;
    setup();
}

TestScene::~TestScene()
{
    logData("The Test Scene has been closed.");
}

void TestScene::setup()
{
    back->SetInnerText("Back To Main Menu");
    back->align(0);
    auto backAction = [&]()
    { --sceneIndex; };
    back->setAction(backAction);

    backImg.setPanelImage("/home/coder/Pictures/pillar.jpg");
    backImg2.setPanelImage("/home/coder/Pictures/9.png");
}

void TestScene::render()
{

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        --sceneIndex;

    window->clear();
    backImg.render();
    back->render();
    window->display();
}