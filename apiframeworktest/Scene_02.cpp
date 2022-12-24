#include "pch.h"
#include "Scene_02.h"
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
#include "Core.h"
Panel* tObj;
Scene_02::Scene_02()
{
}

Scene_02::~Scene_02()
{
}

void Scene_02::Enter()
{
	SoundMgr::GetInst()->LoadSound(L"BGM2", true, L"Sound\\Get Lucky.mp3");
	SoundMgr::GetInst()->Stop(SOUND_CHANNEL::SC_BGM);
	SoundMgr::GetInst()->Play(L"BGM2");
	tObj = new Panel(L"StartButton2", ResMgr::GetInst()->ImgLoad(L"Button", L"Image\\Get Lucky Panel.bmp"));
	tObj->SetPos(Vec2(360.f, 300.f));
	tObj->SetScale(Vec2(3.f, 3.f));
	AddObject(tObj, GROUP_TYPE::BUTTON);
}

void Scene_02::Exit()
{
}

void Scene_02::Update()
{
	Scene::Update();
	if (KEY_TAP(KEY::LBTN) && tObj->IsButtonPos() == true)
	{
		ChangeScene(SCENE_TYPE::START);
	}
}