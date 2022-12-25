#pragma once
#include "Object.h"
class Image;
class Background : public Object
{
private:
    Image* m_bImage;
public:
    //Background();
    Background(std::wstring _Key, Image* _Img);
    ~Background();
private:
    //    Player* Clone{ return new Player(*this); }
    CLONE(Background);
public:
    void Update()       override;
    void Render(HDC _dc) override;
};

