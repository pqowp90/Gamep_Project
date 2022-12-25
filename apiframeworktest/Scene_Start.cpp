#include "pch.h"
#include "Scene_Start.h"
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
#include "Animation.h"
#include "Animator.h"
Scene_Start::Scene_Start()
{
}

Scene_Start::~Scene_Start()
{
}
void Scene_Start::Enter()
{
	SoundMgr::GetInst()->LoadSound(L"BGM", true, L"Sound\\TitleBGM.mp3");
	SoundMgr::GetInst()->Stop(SOUND_CHANNEL::SC_BGM);
	SoundMgr::GetInst()->Play(L"BGM", 330 * 2.2f, -100);
	SoundMgr::GetInst()->endTime = 1000000000;
	// Object Ãß°¡
	Background* bObj = new Background(L"BackGround" ,ResMgr::GetInst()->ImgLoad(L"BackGround", L"Image\\title.bmp"));
	Animation* bAnim = bObj->GetAnimator()->FindAnimation(L"BackGround");
	bObj->SetPos(Vec2(Core::GetInst()->GetResolution().x - bAnim->GetFrame(0).vSlice.x + 220.f, Core::GetInst()->GetResolution().y - bAnim->GetFrame(0).vSlice.y));
	bObj->SetScale(Vec2(2.f, 2.f)); 
	AddObject(bObj, GROUP_TYPE::BACKGROUND);

	TitleText* tObj = new TitleText(L"TitleText", ResMgr::GetInst()->ImgLoad(L"TitleText", L"Image\\logo.bmp"));
	Animation* tAnim = tObj->GetAnimator()->FindAnimation(L"TitleText");
	tObj->SetPos(Vec2(660.f, 300.f));
	tObj->SetScale(Vec2(2.f, 2.f));
	tObj->IsDumChit();
	AddObject(tObj, GROUP_TYPE::TEXT);

	CollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::MONSTER);
	CollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::BULLET_PLAYER, GROUP_TYPE::MONSTER);

}

void Scene_Start::Exit()
{
	DeleteAll();
	CollisionMgr::GetInst()->CheckReset();
}

void Scene_Start::Update()
{  
	Scene::Update();
	if (KEY_TAP(KEY::ENTER))
	{
		ChangeScene(SCENE_TYPE::SCENE_01);
	}
}
