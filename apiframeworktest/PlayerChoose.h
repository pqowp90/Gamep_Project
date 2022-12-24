#pragma once
#include "Object.h"
class Image;
class PlayerChoose : public Object
{
private:
    Image* m_tImage;
public:
    PlayerChoose(std::wstring _Key, Image* _Img);
    ~PlayerChoose();
private:
    CLONE(PlayerChoose);
public:
    void Update()       override;
    void Render(HDC _dc) override;
    bool IsButtonPos();
};

