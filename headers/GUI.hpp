#include "Buttons.hpp"
#include "Lables.hpp"

//^ Useful functions

void SetFont(sf::Font &font,std::string path)
{
    if (!font.loadFromFile(path))
    {
        printf("The font file was not found\n");
        return;
    }
    
}

void assignFont(sf::Text &text, sf::Font &font) // Just sets the font to the text object
{
    text.setFont(font);
}

void SetText(sf::Text &text,std::string subject) // sets the given text to the text object (string only)
{
    text.setString(subject);
}

