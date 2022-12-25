#pragma once
#include "Object.h"
class Image;
class Monster :
    public Object
{
private:
    float   m_fSpeed;
    Vec2    m_vCenterPos;
    int     m_iDir; // 1, -1
    int     m_iHp;
public:
    float GetSpeed() { return m_fSpeed; }
    void SetSpeed(float _f) { m_fSpeed = _f; }
    void SetCenterPos(Vec2 _vPos) { m_vCenterPos = _vPos; }
public:
    virtual void Update() override;
    virtual void	EnterCollision(Collider* _pOther);
    virtual void Render(HDC _dc) override;
//    Monster* Clone() { return new Monster(*this); }
    CLONE(Monster);
public:
    Monster(bool who);
    ~Monster();
};

