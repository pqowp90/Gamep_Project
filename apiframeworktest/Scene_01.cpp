#include "pch.h"
#include "Scene_01.h"
#include "Object.h"
#include "Player.h"
#include "Background.h"
#include "TitleText.h"
#include "Panel.h"
#include "Monster.h"
#include "Core.h"
#include "Image.h"
#include "PathMgr.h"
#include "CollisionMgr.h"
#include "KeyMgr.h"
#include "SceneMgr.h"
#include "SoundMgr.h"
#include "ResMgr.h"
<<<<<<< HEAD
=======
#include "Core.h"
Panel* tObj;
>>>>>>> 0a2366873bad1ba44e0f41b87cff09ba33557451
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
	SoundMgr::GetInst()->Play(L"BGM1");
<<<<<<< HEAD
	TitleText* tObj = new TitleText(L"StartButton", ResMgr::GetInst()->ImgLoad(L"StartButton", L"Image\\TechnologicPanel.bmp"));
	tObj->SetPos(Vec2(490.f, 200.f));
	tObj->SetScale(Vec2(2.f, 2.f));
=======
	tObj = new Panel(L"StartButton", ResMgr::GetInst()->ImgLoad(L"Button", L"Image\\TechnologicPanel.bmp"));
	tObj->SetPos(Vec2(360.f, 300.f));
	tObj->SetScale(Vec2(3.f, 3.f));
>>>>>>> 0a2366873bad1ba44e0f41b87cff09ba33557451
	AddObject(tObj, GROUP_TYPE::BUTTON);
}

void Scene_01::Exit()
{
}

void Scene_01::Update()
{
	Scene::Update();
	if (KEY_TAP(KEY::LBTN) && tObj->IsButtonPos() == true)
	{
		ChangeScene(SCENE_TYPE::START);
	}
}

