#include "pch.h"
#include "BackGround.h"
#include "KeyMgr.h"
#include "TimeMgr.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "Image.h"
#include "PathMgr.h"
#include "ResMgr.h"
#include "Animator.h"
#include "Animation.h"

Background::Background(std::wstring _Key, Image* _Img)
{
	CreateAnimator();
	GetAnimator()->CreateAnimation(_Key, _Img, Vec2(0.f, 0.f), Vec2(840.f, 424.f), Vec2(840.f, 0.f), 2, 0.45f);
	GetAnimator()->Play(_Key, true);
	Animation* bAnim = GetAnimator()->FindAnimation(_Key);
	for (size_t i = 0; i < bAnim->GetMaxFrame(); i++)
		bAnim->GetFrame(i).vOffset = Vec2(10.f, -50.f);
}

Background::~Background()
{
}

void Background::Render(HDC _dc)
{
	Component_Render(_dc);
}

void Background::Update()
{
	Vec2 vPos = GetPos();
	SetPos(vPos);
	GetAnimator()->Update();
}
