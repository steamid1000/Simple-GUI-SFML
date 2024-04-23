#pragma once
#include <SFML/Graphics.hpp>

// using external global variables
extern short width, height;
extern sf::Font font;
extern sf::RenderWindow* window;

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
    
    bool IsVisible;

    // The below option is still usefull here, lets see
    bool SizeGiven; // If the size is fixed by the user
    short id;

public:
    sf::Vector2i center; // This is used to store the center of the window based on the window size
    component(); // empty constructor
    component(bool);
    ~component();


    virtual void SetPosition(sf::Vector2f)=0;
    virtual sf::FloatRect getBounds()=0;
    virtual sf::Vector2f GetPosition() = 0;
    

    virtual void render()=0; // maybe move this function to the gui file, should each component have render funvtion

    virtual sf::Vector3i GetColor() = 0;    
    virtual void SetColor(Vector4i)=0;
};
