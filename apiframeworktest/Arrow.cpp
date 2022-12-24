#include "pch.h"
#include "Arrow.h"
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
Animation* aAnim;
Arrow::Arrow(std::wstring _Key, Image* _Img)
{
	Image* bImg = _Img;
	CreateAnimator();
	GetAnimator()->CreateAnimation(_Key, bImg, Vec2(0.f, 0.f), Vec2(30.f, 50.f), Vec2(30.f, 50.f), 1, 0.2f);
	GetAnimator()->Play(_Key, true);
	aAnim = GetAnimator()->FindAnimation(_Key);
	aAnim->GetFrame(0).vOffset = Vec2(10.f, 0.f);
}

Arrow::~Arrow()
{
}

void Arrow::Update()
{
	Vec2 vPos = GetPos();
	SetPos(vPos);
	GetAnimator()->Update();
}

void Arrow::Render(HDC _dc)
{
	Component_Render(_dc);
}

bool Arrow::IsButtonPos()
{
	if (Core::GetInst()->GetMousePos()->x >= GetPos().x + 91.f && Core::GetInst()->GetMousePos()->y >= GetPos().y + 92.f)
		if (Core::GetInst()->GetMousePos()->x <= GetPos().x + 91.f + aAnim->GetFrame(0).vSlice.x * 3.f && Core::GetInst()->GetMousePos()->y <= GetPos().y + 92.f + aAnim->GetFrame(0).vSlice.y * 3.f)
			return true;
		else
			return false;
	return false;
}
