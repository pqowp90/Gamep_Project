#include "pch.h"
#include "Scene_02.h"
#include "Object.h"
#include "Player.h"
#include "Background.h"
#include "TitleText.h"
#include "Panel.h"
#include "Arrow.h"
#include "Monster.h"
#include "Core.h"
#include "Image.h"
#include "PathMgr.h"
#include "CollisionMgr.h"
#include "KeyMgr.h"
#include "SceneMgr.h"
#include "SoundMgr.h"
#include "ResMgr.h"
#include "Core.h"
Panel* t2Obj;
Arrow* a2Obj;
Arrow* b2Obj;
Scene_02::Scene_02()
{
}

Scene_02::~Scene_02()
{
}

void Scene_02::Enter()
{
	SoundMgr::GetInst()->LoadSound(L"BGM2", true, L"Sound\\GetLucky.mp3");
	SoundMgr::GetInst()->Stop(SOUND_CHANNEL::SC_BGM);
	SoundMgr::GetInst()->Play(L"BGM2", 471, -100);
	SoundMgr::GetInst()->endTime = 1000000000;

	t2Obj = new Panel(L"StartButton2", ResMgr::GetInst()->ImgLoad(L"StartButton2", L"Image\\Get Lucky Panel.bmp"));
	t2Obj->SetScale(Vec2(3.f, 3.f));
	t2Obj->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2));
	t2Obj->IsDumChit();
	AddObject(t2Obj, GROUP_TYPE::BUTTON);

	a2Obj = new Arrow(L"LeftArrow", ResMgr::GetInst()->ImgLoad(L"LeftArrow", L"Image\\LeftArrow.bmp"));
	a2Obj->SetPos(Vec2(100.f, 385.f));
	a2Obj->SetScale(Vec2(3.f, 3.f));
	AddObject(a2Obj, GROUP_TYPE::BUTTON);

	b2Obj = new Arrow(L"RightArrow", ResMgr::GetInst()->ImgLoad(L"RightArrow", L"Image\\RightArrow.bmp"));
	b2Obj->SetPos(Vec2(1165.f, 385.f));
	b2Obj->SetScale(Vec2(3.f, 3.f));
	AddObject(b2Obj, GROUP_TYPE::BUTTON);
}

void Scene_02::Exit()
{
}

void Scene_02::Update()
{
	Scene::Update();
	if (KEY_TAP(KEY::LBTN))
	{
		if (t2Obj->IsButtonPos() == true)
		{
			ChangeScene(SCENE_TYPE::PLAYERTEST);
		}
		if (a2Obj->IsButtonPos() == true)
		{
			ChangeScene(SCENE_TYPE::SCENE_01);
		}
		if (b2Obj->IsButtonPos() == true)
		{
			ChangeScene(SCENE_TYPE::SCENE_01);
		}
	}
}