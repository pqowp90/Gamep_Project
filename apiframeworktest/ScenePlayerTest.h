
#pragma once
#include "Scene.h"
class ScenePlayerTest :
    public Scene
{

public:
    virtual void Enter() override;
    virtual void Exit() override;
    virtual void Update() override;
public:
    ScenePlayerTest();
    virtual ~ScenePlayerTest();
};

