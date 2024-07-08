#include "Lables.hpp"

namespace GUI
{
    Lable::Lable()
    {
        text = new sf::Text;
        text->setFont(font);
        text->setFillColor(sf::Color::White);
    }

    Lable::~Lable()
    {
        delete text;
    }

    void Lable::SetInnerText(std::string innertext)
    {
        // call the set font function before this
        text->setString(innertext);

        text->setCharacterSize(30);
    }

    void Lable::SetSize(short charactersize)
    {
        text->setCharacterSize(charactersize);
        
    }

    void Lable::SetColor(Vector4i rgb)
    {
        text->setFillColor(sf::Color(rgb.a, rgb.b, rgb.c, rgb.d));
    }

    void Lable::SetPosition(sf::Vector2f position)
    {
        text->setPosition(position.x - getBounds().width / 2, position.y);
    }

    sf::FloatRect Lable::getBounds()
    {
        return text->getGlobalBounds();
    }

    sf::Vector3i Lable::GetColor(){
         return sf::Vector3i(text->getFillColor().r, text->getFillColor().g, text->getFillColor().b);
    }

    sf::Vector2f Lable::GetPosition(){
        return text->getPosition();
    }
    // render function
    void Lable::render()
    {
        window->draw(*text);
    }
}
