#include "component.hpp"
namespace GUI{
class Lable : public component
{
private:
    sf::Text* text;
public:
    Lable();
    ~Lable();
    void SetInnerText(std::string);
    void SetSize(short);
    void SetInnerText(std::string innertext, short characterSize);
    void SetColor(Vector4i rgb);
    void SetPosition(sf::Vector2f position);
    void SetSize(sf::Vector2f size);
    sf::FloatRect getBounds();
    sf::Vector3i GetColor();
    void render();
};
}