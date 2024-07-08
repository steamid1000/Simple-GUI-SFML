#include "component.hpp"



component::component(){
    SizeGiven = false;     // by default this will be false until the user calls the SetSize function
    center = {width / 2, height / 2};  
}
component::component(bool isvisible = true)
{
    IsVisible = isvisible; // this will tell if the outer rectangle will be valid or not
    SizeGiven = false;     // by default this will be false until the user calls the SetSize function
    center = {width / 2, height / 2};  
}
component::~component(){}












