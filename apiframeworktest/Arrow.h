#pragma once
#include "Object.h"
class Image;
class Arrow : public Object
{
private:
    Image* m_tImage;
    Animation* aAnim;
public:
    Arrow(std::wstring _Key, Image* _Img);
    ~Arrow();
private:
    CLONE(Arrow);
public:
    void Update()       override;
    void Render(HDC _dc) override;
    bool IsButtonPos();
};
