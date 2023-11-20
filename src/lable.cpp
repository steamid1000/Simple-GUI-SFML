#include "Lables.hpp"

namespace GUI{
Lable::Lable() : component(false){}

Lable::~Lable(){}

void Lable::SetInnerText(std::string innerText) 
{
    component::SetInnerText(innerText);
}

void Lable::SetSize(short charactersize){
    component::SetSize(sf::Vector2f(charactersize,0));
}
}