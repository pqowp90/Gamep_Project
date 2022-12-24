#include "pch.h"
#include "Stage1.h"
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
Stage1::Stage1()
{
}

Stage1::~Stage1()
{
}

void Stage1::Enter()
{
	SoundMgr::GetInst()->LoadSound(L"BGM2", true, L"Sound\\Get Lucky.mp3");
	SoundMgr::GetInst()->Stop(SOUND_CHANNEL::SC_BGM);
	SoundMgr::GetInst()->Play(L"BGM2");
	Panel* tObj = new Panel(L"StartButton", ResMgr::GetInst()->ImgLoad(L"StartButton", L"Image\\TechnologicPanel.bmp"));
	tObj->SetPos(Vec2(300.f, 300.f));
	tObj->SetScale(Vec2(3.f, 3.f));
	AddObject(tObj, GROUP_TYPE::BUTTON);
}

void Stage1::Exit()
{
}

void Stage1::Update()
{
	Scene::Update();
	if (KEY_TAP(KEY::LBTN))
	{
		ChangeScene(SCENE_TYPE::START);
	}
}
