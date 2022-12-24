#include "pch.h"
#include "ScenePlayerTest.h"
#include "Object.h"
#include "Player.h"
#include "Background.h"
#include "TitleText.h"
#include "Monster.h"
#include "Core.h"
#include "Image.h"
#include "PathMgr.h"
#include "CollisionMgr.h"
#include "KeyMgr.h"
#include "SceneMgr.h"
#include "SoundMgr.h"
#include "ResMgr.h"
ScenePlayerTest::ScenePlayerTest()
{
}

ScenePlayerTest::~ScenePlayerTest()
{
}

void ScenePlayerTest::Enter()
{
	SoundMgr::GetInst()->LoadSound(L"BGM1", true, L"Sound\\Scene1BGM.wav");
	SoundMgr::GetInst()->Stop(SOUND_CHANNEL::SC_BGM);
	SoundMgr::GetInst()->Play(L"BGM1");
	TitleText* tObj = new TitleText(L"StartButton", ResMgr::GetInst()->ImgLoad(L"StartButton", L"Image\\TechnologicPanel.bmp"));
	tObj->SetPos(Vec2(490.f, 200.f));
	tObj->SetScale(Vec2(2.f, 2.f));
	AddObject(tObj, GROUP_TYPE::BUTTON);
}

void ScenePlayerTest::Exit()
{
}

void ScenePlayerTest::Update()
{
	Scene::Update();
	if (KEY_TAP(KEY::ENTER))
	{
		ChangeScene(SCENE_TYPE::START);
	}
}
