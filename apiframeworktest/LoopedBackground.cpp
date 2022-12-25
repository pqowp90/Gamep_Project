#include "pch.h"
#include "LoopedBackground.h"
#include "KeyMgr.h"
#include "TimeMgr.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "Image.h"
#include "PathMgr.h"
#include "ResMgr.h"
#include "Animator.h"
#include "Animation.h"
Animation* bAnim;
LoopedBackground::LoopedBackground(std::wstring _Key, Image* _Img) : poolX_Pos(0)
{
	CreateAnimator();
	GetAnimator()->CreateAnimation(_Key, _Img, Vec2(0.f, 0.f), Vec2(240.f, 135.f), Vec2(0.f, 0.f), 3, 1);
	GetAnimator()->Play(_Key, true);
	bAnim = GetAnimator()->FindAnimation(_Key);
	for (size_t i = 0; i < bAnim->GetMaxFrame(); i++)
		bAnim->GetFrame(i).vOffset = Vec2(10.f, -50.f);
}

LoopedBackground::~LoopedBackground()
{
}

void LoopedBackground::Render(HDC _dc)
{
	Component_Render(_dc);
}

void LoopedBackground::Update()
{
	Vec2 vPos = GetPos();
	vPos.x -= speed * fDT;
	if (poolX_Pos >= vPos.x)
	{
		vPos.x = -poolX_Pos * 3.f;
	}
	SetPos(vPos);
	GetAnimator()->Update();
}
