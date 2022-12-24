#pragma once
#include "Scene.h"
class Scene_02 :
    public Scene
{
private:
public:
    Scene_02();
    virtual ~Scene_02();
public:
    virtual void Enter() override;
    virtual void Exit() override;
    virtual void Update() override;
};


