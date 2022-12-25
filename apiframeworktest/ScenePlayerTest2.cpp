#include "pch.h"
#include "ScenePlayerTest2.h"
#include "Object.h"
#include "Player.h"
#include "TitleText.h"
#include "PlayerChoose.h"
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
#include "LoopedBackground.h"
#include "Background.h"
#include <random>
#include <time.h>
// 시드값을 얻기 위한 random_device 생성.
std::random_device rd2;

// random_device 를 통해 난수 생성 엔진을 초기화 한다.
std::mt19937 gen2(rd2());

// 0 부터 99 까지 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의.
std::uniform_int_distribution<int> dis2(0, Core::GetInst()->GetResolution().y);
PlayerChoose* c2Obj;
PlayerChoose* d2Obj;
LoopedBackground* b2Obj1;
LoopedBackground* b2Obj2;


ScenePlayerTest2::ScenePlayerTest2()
{

}
ScenePlayerTest2::~ScenePlayerTest2()
{
}
void ScenePlayerTest2::Enter()
{
	srand(time(NULL));

	SoundMgr::GetInst()->LoadSound(L"BGM4", true, L"Sound\\Scene1BGM.wav");
	SoundMgr::GetInst()->Stop(SOUND_CHANNEL::SC_BGM);
	SoundMgr::GetInst()->Play(L"BGM4", 471, -100);
	SoundMgr::GetInst()->endTime = 180000;
	// Object 추가

	b2Obj1 = new LoopedBackground(L"LoopedBackground", ResMgr::GetInst()->ImgLoad(L"LoopedBackground", L"Image\\demo04_PixelSky.bmp"));
	b2Obj1->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2.f, Core::GetInst()->GetResolution().y / 2.f));
	b2Obj1->SetScale(Vec2(5.4f, 5.4f));
	b2Obj1->speed = 500.f;
	b2Obj1->poolX_Pos = -(float)Core::GetInst()->GetResolution().x / 2.0f;
	AddObject(b2Obj1, GROUP_TYPE::LOOPED_BACKGROUND);

	b2Obj2 = new LoopedBackground(L"LoopedBackground", ResMgr::GetInst()->ImgLoad(L"LoopedBackground", L"Image\\demo04_PixelSky.bmp"));
	b2Obj2->SetPos(Vec2(Core::GetInst()->GetResolution().x * 1.5f, Core::GetInst()->GetResolution().y / 2.f));
	b2Obj2->SetScale(Vec2(5.4f, 5.4f));
	b2Obj2->speed = 500.f;
	b2Obj2->poolX_Pos = -(float)Core::GetInst()->GetResolution().x / 2.0f;
	AddObject(b2Obj2, GROUP_TYPE::LOOPED_BACKGROUND);

	c2Obj = new PlayerChoose(L"silver", ResMgr::GetInst()->ImgLoad(L"silver", L"Image\\silver.bmp"));
	c2Obj->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2.f - 50, Core::GetInst()->GetResolution().y / 2.f));
	c2Obj->SetScale(Vec2(3.f, 3.f));
	c2Obj->IsDumChit();

	AddObject(c2Obj, GROUP_TYPE::BUTTON);
	d2Obj = new PlayerChoose(L"gold", ResMgr::GetInst()->ImgLoad(L"gold", L"Image\\gold.bmp"));
	d2Obj->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2.f + 50, Core::GetInst()->GetResolution().y / 2.f));
	d2Obj->SetScale(Vec2(3.f, 3.f));
	d2Obj->IsDumChit();
	AddObject(d2Obj, GROUP_TYPE::BUTTON);
	CollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::MONSTER);
	CollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::BULLET_PLAYER, GROUP_TYPE::MONSTER);

}

void ScenePlayerTest2::EnemySpawn()
{
	Monster* pMonsterObj = new Monster(rand() % 2);
	pMonsterObj->SetPos(Vec2((float)Core::GetInst()->GetResolution().x, (float)(rand() % Core::GetInst()->GetResolution().x)));
	pMonsterObj->SetScale(Vec2((float)(rand() % 2 + 1), (float)(rand() % 2 + 1)));
	pMonsterObj->SetSpeed(300.f);
	pMonsterObj->SetCenterPos(pMonsterObj->GetPos());
	pMonsterObj->IsDumChit();
	pMonsterObj->SetDumChitScale(1.f);
	AddObject(pMonsterObj, GROUP_TYPE::MONSTER);
}

void ScenePlayerTest2::Exit()
{
	DeleteAll();
	CollisionMgr::GetInst()->CheckReset();
}

void ScenePlayerTest2::Update()
{
	Scene::Update();
	if (KEY_TAP(KEY::ESC))
	{
		ChangeScene(SCENE_TYPE::SCENE_01);
	}
	if (KEY_TAP(KEY::LBTN) && c2Obj->IsButtonPos() == true)
	{
		DeleteObject(c2Obj);
		DeleteObject(d2Obj);
		Object* pObj = new Player(ResMgr::GetInst()->ImgLoad(L"PlayerAni", L"Image\\player.bmp"), true);
		pObj->SetPos(Vec2(100.f, Core::GetInst()->GetResolution().y / 2.f));
		//Core::GetInst()->GetResolution().x/2
		pObj->SetScale(Vec2(3.f, 3.f));
		pObj->IsDumChit();
		pObj->SetDumChitScale(0.3f);
		AddObject(pObj, GROUP_TYPE::PLAYER);
	}
	if (KEY_TAP(KEY::LBTN) && d2Obj->IsButtonPos() == true)
	{
		DeleteObject(c2Obj);
		DeleteObject(d2Obj);
		Object* pObj = new Player(ResMgr::GetInst()->ImgLoad(L"PlayerAni2", L"Image\\player.bmp"), false);
		pObj->SetPos(Vec2(100.f, Core::GetInst()->GetResolution().y / 2.f));
		//Core::GetInst()->GetResolution().x/2
		pObj->SetScale(Vec2(3.f, 3.f));
		pObj->IsDumChit();
		pObj->SetDumChitScale(0.3f);
		AddObject(pObj, GROUP_TYPE::PLAYER);
	}

	//pObj->SetScale(Vec2(3.f, 3.f));

}
