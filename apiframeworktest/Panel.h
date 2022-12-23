#pragma once
#pragma once
#include "Object.h"
class Image;
class Panel : public Object
{
private:
    Image* m_tImage;
public:
    Panel(std::wstring _Key, Image* _Img);
    ~Panel();
private:
    //    Player* Clone{ return new Player(*this); }
    CLONE(Panel);
public:
    void Update()       override;
    void Render(HDC _dc) override;
    bool IsButtonPos();
};



