#include "pch.h"
#include "Scene_01.h"
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
Panel* tObj;
Arrow* aObj;
Arrow* bObj;
Scene_01::Scene_01()
{
}

Scene_01::~Scene_01()
{
}

void Scene_01::Enter()
{
	SoundMgr::GetInst()->LoadSound(L"BGM1", true, L"Sound\\Scene1BGM.wav");  
	SoundMgr::GetInst()->Stop(SOUND_CHANNEL::SC_BGM);
	SoundMgr::GetInst()->Play(L"BGM1", 517, -100);
	SoundMgr::GetInst()->endTime = 1000000000;


	tObj = new Panel(L"StartButton", ResMgr::GetInst()->ImgLoad(L"StartButton", L"Image\\TechnologicPanel.bmp"));
	tObj->SetScale(Vec2(3.f, 3.f));
	tObj->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2));
	tObj->IsDumChit();
	AddObject(tObj, GROUP_TYPE::BUTTON);
	
	aObj = new Arrow(L"LeftArrow", ResMgr::GetInst()->ImgLoad(L"LeftArrow", L"Image\\LeftArrow.bmp"));
	aObj->SetPos(Vec2(100.f, 385.f));
	aObj->SetScale(Vec2(3.f, 3.f));
	AddObject(aObj, GROUP_TYPE::BUTTON);
	
	bObj = new Arrow(L"RightArrow", ResMgr::GetInst()->ImgLoad(L"RightArrow", L"Image\\RightArrow.bmp"));
	bObj->SetPos(Vec2(1165.f, 385.f));
	bObj->SetScale(Vec2(3.f, 3.f));
	AddObject(bObj, GROUP_TYPE::BUTTON);
	
}

void Scene_01::Exit()
{
}

void Scene_01::Update()
{
	Scene::Update();
	if (KEY_TAP(KEY::LBTN))
	{
		if (tObj->IsButtonPos() == true)
		{
			ChangeScene(SCENE_TYPE::PLAYERTEST2);
		}
		if (aObj->IsButtonPos() == true)
		{
			ChangeScene(SCENE_TYPE::SCENE_02);
		}
		if (bObj->IsButtonPos() == true)
		{
			ChangeScene(SCENE_TYPE::SCENE_02);
		}
	}
}

