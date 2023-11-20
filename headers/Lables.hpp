#include "component.hpp"
namespace GUI{
class Lable : public component
{
private:
public:
    Lable();
    ~Lable();
    void SetInnerText(std::string);
    void SetSize(short);    
};
}