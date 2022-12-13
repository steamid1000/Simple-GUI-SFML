#pragma once
#include <iostream>

void ButtonClicked(std::string buttonID){
    if (buttonID== "play")
    {
        printf("the play button was pressed\n");
    }
    else if (buttonID=="quit")
    {
        printf("the quit button was pressed\n");
    }
    else if(buttonID=="Authors"){
        printf("clicked the authors button\n");
    }
    
    
}

class menuScene
{
private:
    /* data */
public:
    menuScene();
    ~menuScene();
};

menuScene::menuScene()
{
}

menuScene::~menuScene()
{
}
