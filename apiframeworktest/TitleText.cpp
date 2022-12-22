#include "pch.h"
#include "TitleText.h"
#include "KeyMgr.h"
#include "TimeMgr.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "Image.h"
#include "PathMgr.h"
#include "ResMgr.h"
#include "Animator.h"
#include "Animation.h"

TitleText::TitleText(std::wstring _Key, Image* _Img)
{
	Image* bImg = _Img;
	CreateAnimator();
	GetAnimator()->CreateAnimation(_Key, bImg, Vec2(0.f, 0.f), Vec2(325.f, 325.f), Vec2(325.f, 325.f), 1, 0.2f);
	GetAnimator()->Play(_Key, true);
	Animation* pAnim = GetAnimator()->FindAnimation(_Key);
	pAnim->GetFrame(0).vOffset = Vec2(10.f, 0.f);
}

TitleText::~TitleText()
{
}

void TitleText::Render(HDC _dc)
{
	Component_Render(_dc);
}

void TitleText::Update()
{
	Vec2 vPos = GetPos();
	SetPos(vPos);
	GetAnimator()->Update();
}