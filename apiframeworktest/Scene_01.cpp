#include "pch.h"
#include "Scene_01.h"
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

}

void Scene_01::Exit()
{
}

void Scene_01::Update()
{
	Scene::Update();
	if (KEY_TAP(KEY::ENTER))
	{
		ChangeScene(SCENE_TYPE::START);
	}
}
