#include "component.hpp"


// call the set size method before calling the setPosition method


namespace GUI{
class Lable : public component
{
private:
    sf::Text* text;
public:
    Lable();
    ~Lable();
    void SetInnerText(std::string);
    void SetColor(Vector4i rgb);
    void SetPosition(sf::Vector2f position);
    void SetSize(short);
    sf::Vector2f GetPosition();
    sf::FloatRect getBounds();
    sf::Vector3i GetColor();
    void render();
};
}