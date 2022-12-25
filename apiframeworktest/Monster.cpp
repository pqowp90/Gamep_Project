#include "pch.h"
#include "Monster.h"
#include "TimeMgr.h"
#include "Collider.h"
#include <random>
#include "ResMgr.h"
#include "Animator.h"
#include "Animation.h"
Monster::Monster(bool who)
	: m_fSpeed(100.f)
	, m_vCenterPos(Vec2(0.f,0.f))
	, m_iDir(1)
	, m_iHp(5)
{
	CreateCollider();
	GetCollider()->SetScale(Vec2(40.f, 40.f));
	Image* pImg;
	if (!who)
	{
		pImg = ResMgr::GetInst()->ImgLoad(L"enemy", L"Image\\Drone1.bmp");
		CreateAnimator();
		GetAnimator()->CreateAnimation(L"enemy", pImg, Vec2(0.f, 0.f), Vec2(100.f, 64.f), Vec2(100.f, 0.f), 6, 0.1f);
		GetAnimator()->Play(L"enemy", true);
		Animation* pAnim = GetAnimator()->FindAnimation(L"enemy");
		for (size_t i = 0; i < pAnim->GetMaxFrame(); i++)
			pAnim->GetFrame(i).vOffset = Vec2(10.f, -50.f);
	}
	else
	{
		pImg = ResMgr::GetInst()->ImgLoad(L"enemy2", L"Image\\drone3-sheet.bmp");
		CreateAnimator();
		GetAnimator()->CreateAnimation(L"enemy2", pImg, Vec2(0.f, 0.f), Vec2(32.f, 32.f), Vec2(32.f, 0.f), 8, 0.1f);
		GetAnimator()->Play(L"enemy2", true);
		Animation* pAnim = GetAnimator()->FindAnimation(L"enemy2");
		for (size_t i = 0; i < pAnim->GetMaxFrame(); i++)
			pAnim->GetFrame(i).vOffset = Vec2(10.f, -50.f);
	}

	// animation offset 위로 올리기. 
}

Monster::~Monster()
{
}

void Monster::Update()
{
	Vec2 vCurPos = GetPos();
	// 진행방향으로 시간당 m_fSpeed만큼 이동
//	vCurPos.x += m_fSpeed * fDT * m_iDir;
	//vCurPos.x += fDT* m_fSpeed * m_iDir;

	//// 배회 거리 기준량을 넘어섰는지 확인
	////if (m_fMaxDistance < abs(m_vCenterPos.x - vCurPos.x))
	////{

	////}
	//float fDist = abs(m_vCenterPos.x - vCurPos.x) - m_fMaxDistance;
	//if (fDist > 0.f)
	//{
	//	m_iDir *= -1;
	//	vCurPos.x += fDist * m_iDir;
	//}
	vCurPos.x += m_fSpeed * fDT * -1;
	SetPos(vCurPos);
}

void Monster::EnterCollision(Collider* _pOther)
{
	Object* pOtherObj = _pOther->GetObj();
	if (pOtherObj->GetName() == L"Bullet_Player")
	{
		DeleteObject(this);
	}
}

void Monster::Render(HDC _dc)
{
	Component_Render(_dc);
}

