#include "Buttons.hpp"
#include "Lables.hpp"

//^ Useful functions

// logs input to the console
template <typename t>
void logData(t data) 
{
    std::cout << data << '\n';
}

//& Remove this function and call the once from the GUI file
void setText(sf::Font &fontObject, sf::Text &textObject, std::string filepath, short characterSize, std::string data = "null")
{
    if (!fontObject.loadFromFile(filepath))
    {
        logData("Font file for text was not found\n");
        return;
    }
    
    textObject.setFont(fontObject);
    textObject.setCharacterSize(characterSize);
    textObject.setString(data);
}



#ifndef SetFont // Why in the world are there two function to set font, got to remove it 
void SetFont(sf::Font &font,std::string path)
{
    if (!font.loadFromFile(path))
    {
        printf("The font file was not found\n");
        return;
    }
    
}
#endif

#ifndef assignFont
void assignFont(sf::Text &text, sf::Font &font) // Just sets the font to the text object
{
    text.setFont(font);
}
#endif

#ifndef SetText
void SetText(sf::Text &text,std::string subject) // sets the given text to the text object (string only)
{
    text.setString(subject);
}
#endif


