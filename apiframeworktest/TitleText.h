#pragma once
#include "Object.h"
class Image;
class TitleText : public Object
{
private:
    Image* m_bImage;
public:
    TitleText();
    //Player(const Player& _origin) 
    //    : Object(_origin)
    //    , m_pImage(_origin.m_pImage)
    //{}
    ~TitleText();
private:
    //    Player* Clone{ return new Player(*this); }
    CLONE(TitleText);
public:
    void Update()       override;
    void Render(HDC _dc) override;
};

