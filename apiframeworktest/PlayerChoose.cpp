#include "pch.h"
#include "PlayerChoose.h"
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
Animation* cAnim;
PlayerChoose::PlayerChoose(std::wstring _Key, Image* _Img)
{
	Image* bImg = _Img;
	CreateAnimator();
	GetAnimator()->CreateAnimation(_Key, bImg, Vec2(0.f, 0.f), Vec2(32.f, 32.f), Vec2(32.f, 32.f), 1, 0.2f);
	GetAnimator()->Play(_Key, true);
	cAnim = GetAnimator()->FindAnimation(_Key);
	cAnim->GetFrame(0).vOffset = Vec2(10.f, 0.f);
}

PlayerChoose::~PlayerChoose()
{
}

void PlayerChoose::Update()
{
	Vec2 vPos = GetPos();
	SetPos(vPos);
	GetAnimator()->Update();
}

void PlayerChoose::Render(HDC _dc)
{
	Component_Render(_dc);
}

bool PlayerChoose::IsButtonPos()
{
	if (Core::GetInst()->GetMousePos()->x >= GetPos().x + 91.f && Core::GetInst()->GetMousePos()->y >= GetPos().y + 92.f)
		if (Core::GetInst()->GetMousePos()->x <= GetPos().x + 91.f + cAnim->GetFrame(0).vSlice.x * 3.f && Core::GetInst()->GetMousePos()->y <= GetPos().y + 92.f + cAnim->GetFrame(0).vSlice.y * 3.f)
			return true;
		else
			return false;
	return false;
}
