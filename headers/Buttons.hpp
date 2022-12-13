#pragma once
#pragma once
#include <component.hpp>
#include <SFML/Graphics.hpp>
#include <functional>
#include <SFML/Audio.hpp>

class Button : public component
{
private:
    std::string id;
    sf::RenderWindow* ButtonWindowCopy;
    sf::SoundBuffer* source;
    sf::Sound* audio;
public:
    Button(std::string id,sf::RenderWindow* window);
    ~Button();

    void align(short);
    void hover();
    void onClick();
    bool cursorOverButton();
    void render();
    bool Clicked();
    void setSound(std::string); // I think that each button can have seprated sound
    void Play();
    std::string getID();

};


