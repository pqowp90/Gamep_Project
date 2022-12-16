#include "pch.h"
#include "BackGround.h"
#include "KeyMgr.h"
#include "TimeMgr.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "Image.h"
#include "PathMgr.h"
#include "ResMgr.h"

Background::Background()
{
	Image* bImg = ResMgr::GetInst()->ImgLoad(L"BackGround", L"Image\\title.bmp");
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
}