#pragma once
#include "component.hpp"
#include <functional>
#include<iostream>

namespace GUI{
class Button : public component
{
private:
    std::string id;
    sf::Text* text;
    sf::RectangleShape *body;
    std::function<void()> action;
    bool buttonbodyvisible = true;
public:
    Button(std::string id);
    ~Button();

    void align(short);
    void hover();
    void onClick();
    void setAction(std::function<void()> statements);
    bool cursorOverButton();
    void toggleButtonBodyVisibility();
    void render();
    bool Clicked();
    void ButtonSizeAccordingToText();
    void SetInnerText(std::string,int=30);
    sf::Vector2f GetSize();
    sf::Vector2f GetPosition();
    sf::Vector3i GetColor();
    void ChangeTextColor(Vector4i rgb);
    void SetColor(Vector4i rgb);
    void SetPosition(sf::Vector2f position);
    void AdjustTextPosition();
    void containText();
    void OnSizeChange();
    void SetSize(sf::Vector2f size);
    sf::FloatRect getBounds();
    std::string getID();

};
}

