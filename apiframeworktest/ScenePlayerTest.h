#pragma once
#include "Scene.h"
class ScenePlayerTest : public Scene
{
private:
public:
    ScenePlayerTest();
    virtual ~ScenePlayerTest();
public:
    virtual void Enter() override;
    virtual void Exit() override;
    virtual void Update() override;
};

