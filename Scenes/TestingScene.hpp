#pragma once
#include "Scene.hpp"


class TestScene : public Scene
{
    GUI::Button *back;
    GUI::Panels backImg;
    unsigned short index;
    short align = 0;
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
    back->SetInnerText("Back To Main Menu",70);
    back->ChangeTextColor(Vector4i(100,120,50,255));
    back->align(1);
    back->SetInnerText("Back",25);
    auto backAction = [&]()
    { SM.switchScene("MenuScene"); };
    back->setAction(backAction);

    backImg.setPanelImage("res/Level2Panel.jpg");
}

void TestScene::render()
{

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        SM.switchScene("MenuScene");
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        align = (align+1)%5;
        back->align(align);
    }
    window->clear();
    backImg.render();
    back->render();
    window->display();
}