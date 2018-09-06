#pragma once 

class Solid
{
protected:
    virtual bool checkForCollision() = 0;
    virtual void castShadow() {};
public:
    Solid();
    ~Solid();
};


