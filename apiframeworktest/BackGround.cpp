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

Background::Background()
{
	Image* bImg = ResMgr::GetInst()->ImgLoad(L"BackGround", L"Image\\title.bmp");
	CreateAnimator();
	GetAnimator()->CreateAnimation(L"BackGround", bImg, Vec2(0.f, 0.f), Vec2(840.f, 424.f), Vec2(840.f, 0.f), 2, 0.45f);
	GetAnimator()->Play(L"BackGround", true);
	Animation* bAnim = GetAnimator()->FindAnimation(L"BackGround");
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
