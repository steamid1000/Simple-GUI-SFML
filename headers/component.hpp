#pragma once
#include <SFML/Graphics.hpp>

// using external global variables
extern short width, height;
extern sf::Font font;

struct Vector4i
{
    short a, b, c, d;
    Vector4i(short ab, short bc, short cd, short de = 255)
    {
        a = ab;
        b = bc;
        c = cd;
        d = de;
    }
};

class component
{
private:
    //Move the below to there respective classes
    sf::RectangleShape *body;
    sf::Text *text;
    bool IsVisible;

    // The below option is still usefull here, lets see
    bool SizeGiven; // If the size is fixed by the user
    short id;

public:
    sf::Vector2i center; // This is used to store the center of the window based on the window size
    component(bool);
    ~component();

    short getId(){return id;}

    void SetPosition(sf::Vector2f);
    sf::FloatRect getBounds(short = 0);
    sf::Vector2f GetPosition();
    sf::Vector2f GetSize();

    virtual void SetSize(sf::Vector2f); // this should be either a sf::vector or short for button and lable respectively
    virtual void render(); // maybe move this function to the gui file, should each component have render funvtion

    //Move this function to the respective classes, some function will be repeated but the code will be much cleaner
    void ChangeTextColor(Vector4i);
    virtual sf::Vector3i GetColor();
    
    void ButtonSizeAccordingToText();
    void OnSizeChange(bool=false);
    virtual void SetInnerText(std::string,short= 30);
    void SetColor(Vector4i);
};
