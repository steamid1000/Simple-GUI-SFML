#include "component.hpp"

class Lable : public component
{
private:
    sf::RenderWindow* LableWindowCopy;
public:
    Lable(sf::RenderWindow*);
    ~Lable();
    void SetInnerText(std::string);
    void SetSize(short);    
};
