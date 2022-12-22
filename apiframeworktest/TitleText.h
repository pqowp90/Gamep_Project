#pragma once
#include "Object.h"
class Image;
class TitleText : public Object
{
private:
    Image* m_tImage;
public:
    //TitleText();
    TitleText(Image* _Img);
    ~TitleText();
private:
    //    Player* Clone{ return new Player(*this); }
    CLONE(TitleText);
public:
    void Update()       override;
    void Render(HDC _dc) override;
};

