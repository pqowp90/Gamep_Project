#include "pch.h"
#include "Panel.h"
#include "KeyMgr.h"
#include "TimeMgr.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "Image.h"
#include "PathMgr.h"
#include "ResMgr.h"
#include "Animator.h"
#include "Animation.h"
#include "Core.h"
Animation* pAnim;
Panel::Panel(std::wstring _Key, Image* _Img)
{
	Image* bImg = _Img;
	CreateAnimator();
	GetAnimator()->CreateAnimation(_Key, bImg, Vec2(0.f, 0.f), Vec2(255.f, 76.f), Vec2(255.f, 76.f), 1, 0.2f);
	GetAnimator()->Play(_Key, true);
	pAnim = GetAnimator()->FindAnimation(_Key);
	pAnim->GetFrame(0).vOffset = Vec2(10.f, 0.f);
}

Panel::~Panel()
{
}

void Panel::Render(HDC _dc)
{
	Component_Render(_dc);
}

void Panel::Update()
{
	Vec2 vPos = GetPos();
	SetPos(vPos);
	GetAnimator()->Update();
}

bool Panel::IsButtonPos()
{
	if (Core::GetInst()->GetMousePos()->x >= GetPos().x - 20.f && Core::GetInst()->GetMousePos()->y >= GetPos().y + 92.f)
		if (Core::GetInst()->GetMousePos()->x <= GetPos().x - 20.f + pAnim->GetFrame(0).vSlice.x * 3.f && Core::GetInst()->GetMousePos()->y <= GetPos().y + 92.f + pAnim->GetFrame(0).vSlice.y * 3.f)
		return true;
	else
		return false;
	return false;
}