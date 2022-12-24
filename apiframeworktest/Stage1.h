#pragma once
#include "Scene.h"
class Stage1 :
    public Scene
{
private:
public:
    Stage1();
    virtual ~Stage1();
public:
    virtual void Enter() override;
    virtual void Exit() override;
    virtual void Update() override;
};

