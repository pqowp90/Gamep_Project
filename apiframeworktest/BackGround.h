#pragma once
#include "Object.h"
class Image;
class Background : public Object
{
private:
    Image* m_bImage;
    bool isLoop;
public:
    Background();
    //Player(const Player& _origin) 
    //    : Object(_origin)
    //    , m_pImage(_origin.m_pImage)
    //{}
    ~Background();
private:
    //    Player* Clone{ return new Player(*this); }
    CLONE(Background);
public:
    void Update()       override;
    void Render(HDC _dc) override;
};

