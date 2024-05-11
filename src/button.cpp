#include "Buttons.hpp"

extern sf::RenderWindow *window;
namespace GUI
{
    Button::Button(std::string idString) : component(true)
    {
        id = idString;

        // setting the default size to be 1
        body = new sf::RectangleShape;
        body->setSize(sf::Vector2f(10, 10));
        body->setFillColor(sf::Color(60, 60, 60));
        body->setPosition(sf::Vector2f(10, 10));
        body->setOutlineThickness(1.2f);

        // text object settings
        text = new sf::Text;
        text->setFont(font);
        text->setFillColor(sf::Color::White);
    }

    void Button::align(short side) // Align the button to the sides of the window or the center of the window
    {
        // ! call this function only after deciding the size of the button and the text of the button. !
        /*
          0 -  Center of the screen
          1 - left Top corner of the window
          2 - right top corner of the window
          3 - left bottom corner of the window
          4 - right bottom corner of the window


          Note:- Needs to be called after the setting of the inner-text, this can be made as an implicit call as well
        */

        switch (side)
        {
        case 0:
            SetPosition(sf::Vector2f(width / 2 - GetSize().x / 2, height / 2 - GetSize().y / 2));
            break;
        case 1:
            SetPosition(sf::Vector2f(GetSize().x, 10));
            break;
        case 2:
            SetPosition(sf::Vector2f(width - GetSize().x - 10, 10));
            break;
        case 3:
            SetPosition(sf::Vector2f(10, height - GetSize().y * 1.5f));
            break;
        case 4:
            SetPosition(sf::Vector2f(width - GetSize().x - 10, height - GetSize().y - 10));
            break;
        default:
            SetPosition(sf::Vector2f(10, 10));
            break;
        }

        // OnSizeChange();
    }

    bool Button::cursorOverButton()
    {
        sf::Vector2f mousePosition(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y);
        sf::FloatRect buttonArea = getBounds();
        if (buttonArea.contains(mousePosition))
        {
            return true;
        }

        return false;
    }

    void Button::onClick() // for now let me just send the lamda code right here later it will be sent to the scene class
    {
        try
        {
            if (action == nullptr)
            {
                throw "Action Not Found";
            }
            else
            {
                action();
            }
        }
        catch (const char *ex)
        {
            // printf("%s : ",ex);
            std::cout << ex << " ,  ButtonID: " << getID() << '\n';
        }
    }
    void Button::setAction(std::function<void()> statements)
    { //^ Sets the Action to be performed after clicking the button
        action = statements;
    }
    void Button::hover()
    {
        sf::Vector3i originalColor = GetColor();
        if (cursorOverButton() == true)
        {
            SetColor(Vector4i(originalColor.x, originalColor.y, originalColor.z, 200));
        }
        else
        {
            SetColor(Vector4i(originalColor.x, originalColor.y, originalColor.z, 255));
        }
    }

    // Changes the inner text of the button
    void Button::SetInnerText(std::string innertext, short characterSize)
    {
        // call the set font function before this
        text->setString(innertext);
        if (characterSize != 30)
        {
            text->setCharacterSize(characterSize);
        }

        ButtonSizeAccordingToText();
    }

    bool Button::Clicked()
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) and cursorOverButton())
        {
            return true;
        }

        return false;
    }

    sf::Vector2f Button::GetSize()
    {
        return body->getSize();
    }

    sf::Vector2f Button::GetPosition()
    {
        return body->getPosition();
    }

    sf::Vector3i Button::GetColor()
    {
        return sf::Vector3i(body->getFillColor().r, body->getFillColor().g, body->getFillColor().b);
    }

    void Button::ChangeTextColor(Vector4i rgb)
    {
        text->setFillColor(sf::Color(rgb.a, rgb.b, rgb.c, rgb.d));
    }

    void Button::SetColor(Vector4i rgb)
    {
        body->setFillColor(sf::Color(rgb.a, rgb.b, rgb.c, rgb.d));
    }

    void Button::OnSizeChange(bool calledFromTextSize = 0) // this function when setsSize function is called
    {
        if (!calledFromTextSize)
        {
            text->setCharacterSize(GetSize().y / 2); // if this function is called by the accordingtotext function then we will not change the text size
        }

        text->setPosition(GetPosition().x + (GetSize().x / 2 - text->getGlobalBounds().width / 2), GetPosition().y + text->getGlobalBounds().height / 2);
    }

    // Changes the button size according to the new entered text
    void Button::ButtonSizeAccordingToText()
    {

        SetSize(sf::Vector2f(text->getGlobalBounds().width + 5, text->getGlobalBounds().height + 10));
        OnSizeChange();
    }
    void Button::SetPosition(sf::Vector2f position)
    {
        body->setPosition(position);
        OnSizeChange();
    }

    void Button::SetSize(sf::Vector2f size)
    {
        body->setSize(size);
    }

    sf::FloatRect Button::getBounds()
    {
        return body->getGlobalBounds();
    }

    std::string Button::getID() // return the button id
    {
        return id;
    }

    void Button::render()
    {
        window->draw(*body);
        window->draw(*text);
        hover();

        if (Clicked())
        {
            onClick();
        }
    }
}