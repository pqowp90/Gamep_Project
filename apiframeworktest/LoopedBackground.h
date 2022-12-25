#pragma once
#include "Object.h"
class Image;
class LoopedBackground : public Object
{
private:
    Image* m_bImage;
public:
    float poolX_Pos;
    float speed;
public:
    //Background();
    LoopedBackground(std::wstring _Key, Image* _Img);
    ~LoopedBackground();
private:
    //    Player* Clone{ return new Player(*this); }
    CLONE(LoopedBackground);
public:
    void Update()       override;
    void Render(HDC _dc) override;
};

