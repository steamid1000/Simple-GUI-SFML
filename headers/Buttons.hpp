#pragma once
#include "component.hpp"
#include <functional>
#include<iostream>

namespace GUI{
class Button : public component
{
private:
    std::string id;
    sf::RenderWindow* ButtonWindowCopy;
    std::function<void()> action;
public:
    Button(std::string id);
    ~Button();

    void align(short);
    void hover();
    void onClick();
    void setAction(std::function<void()> statements);
    bool cursorOverButton();
    void render();
    bool Clicked();
    void ButtonSizeAccordingToText();
    std::string getID();

};
}

