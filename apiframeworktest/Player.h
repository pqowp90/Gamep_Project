#pragma once
#include "Object.h"

class Image;
class Player :
    public Object
{
private:
    Image* m_pImage;
public:
    Player(Image* _Img, bool who);
    //Player(const Player& _origin) 
    //    : Object(_origin)
    //    , m_pImage(_origin.m_pImage)
    //{}
    ~Player();
public:
    float grabity = 9.81f;
    Vec2 velocity;
    float upMaxForce = 300;
    float upForce = 1200;

private:
    void CreateBullet();

//    Player* Clone{ return new Player(*this); }
    CLONE(Player);
public:
    void Update()       override;
    void PlayerInput();
    void Render(HDC _dc) override;
};

