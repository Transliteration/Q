#pragma once 
#include "Object.hpp"

class Clickable : public Object
{
protected:
    virtual void onClick() = 0;
    virtual void onHover();
public:
    Clickable();
    ~Clickable();
};

