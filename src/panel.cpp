#include "Panels.hpp"

namespace GUI
{
    Panels::Panels()
    {colorGiven = false;imageGiven=false;}
    Panels::~Panels(){}

    void Panels::render(){
        if(imageGiven) window->draw(backImg);
    }

    void Panels::setPanelColor(Vector4i rgba){
        colorGiven = !colorGiven;
    }

    void Panels::setPanelImage(std::string texPath){
        imageGiven = !imageGiven;

        backImgTexture.loadFromFile(texPath);
        backImg.setTexture(backImgTexture);
        backImg.setScale(1.f,0.9f);
    }
}