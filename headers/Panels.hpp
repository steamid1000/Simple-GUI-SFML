#include "component.hpp" // remove this later

/*
Panels will be used to provide customisation of the backgrounds of the scenes, with images or colours
A scene can have many panels, each having its own asthetics.
i.e: 
    Panel-0 could be a image
    Panel-1 could be a png which is sort of frame aspects on the corners of the window
*/

namespace GUI{
class Panels
{
private:
    sf::Sprite backImg;
    sf::Color backColor;
    sf::Texture backImgTexture;
    bool colorGiven,imageGiven;
public:
    Panels();
    ~Panels();
    void setPanelColor(Vector4i);
    void setPanelImage(std::string);
    void render();

};

}