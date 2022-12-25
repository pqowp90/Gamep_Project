#include "pch.h"
#include "ScenePlayerTest.h"
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
std::random_device rd;

// random_device 를 통해 난수 생성 엔진을 초기화 한다.
std::mt19937 gen(rd());

// 0 부터 99 까지 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의.
std::uniform_int_distribution<int> dis(0, Core::GetInst()->GetResolution().y);
PlayerChoose* cObj;
PlayerChoose* dObj;
LoopedBackground* bObj1;
LoopedBackground* bObj2;


ScenePlayerTest::ScenePlayerTest()
{
	
}
ScenePlayerTest::~ScenePlayerTest()
{
}
void ScenePlayerTest::Enter()
{
	srand(time(NULL));

	SoundMgr::GetInst()->LoadSound(L"BGM3", true, L"Sound\\GetLucky.mp3");
	SoundMgr::GetInst()->Stop(SOUND_CHANNEL::SC_BGM);
	SoundMgr::GetInst()->Play(L"BGM3", 517, -100);
	SoundMgr::GetInst()->endTime = 180000;
	// Object 추가

	bObj1 = new LoopedBackground(L"LoopedBackground", ResMgr::GetInst()->ImgLoad(L"LoopedBackground", L"Image\\demo04_PixelSky.bmp"));
	bObj1->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2.f, Core::GetInst()->GetResolution().y/2.f));
	bObj1->SetScale(Vec2(5.4f, 5.4f));
	bObj1->speed = 500.f;
	bObj1->poolX_Pos = -(float)Core::GetInst()->GetResolution().x/2.0f;
	AddObject(bObj1, GROUP_TYPE::LOOPED_BACKGROUND);

	bObj2 = new LoopedBackground(L"LoopedBackground", ResMgr::GetInst()->ImgLoad(L"LoopedBackground", L"Image\\demo04_PixelSky.bmp"));
	bObj2->SetPos(Vec2(Core::GetInst()->GetResolution().x * 1.5f, Core::GetInst()->GetResolution().y / 2.f));
	bObj2->SetScale(Vec2(5.4f, 5.4f));
	bObj2->speed = 500.f;
	bObj2->poolX_Pos = -(float)Core::GetInst()->GetResolution().x / 2.0f;
	AddObject(bObj2, GROUP_TYPE::LOOPED_BACKGROUND);

	cObj = new PlayerChoose(L"silver", ResMgr::GetInst()->ImgLoad(L"silver", L"Image\\silver.bmp"));
	cObj->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2.f - 50, Core::GetInst()->GetResolution().y / 2.f));
	cObj->SetScale(Vec2(3.f, 3.f));
	cObj->IsDumChit();

	AddObject(cObj, GROUP_TYPE::BUTTON);
	dObj = new PlayerChoose(L"gold", ResMgr::GetInst()->ImgLoad(L"gold", L"Image\\gold.bmp"));
	dObj->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2.f + 50, Core::GetInst()->GetResolution().y / 2.f));
	dObj->SetScale(Vec2(3.f, 3.f));
	dObj->IsDumChit();
	AddObject(dObj, GROUP_TYPE::BUTTON);
	
		Monster* pMonsterObj = new Monster;
		pMonsterObj->SetPos(Vec2((float)Core::GetInst()->GetResolution().x, (float)dis(gen)));
		pMonsterObj->SetScale(Vec2(50.f, 50.f));
		pMonsterObj->SetSpeed(300.f);
		pMonsterObj->SetCenterPos(pMonsterObj->GetPos());
		AddObject(pMonsterObj, GROUP_TYPE::MONSTER);
	CollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::MONSTER);
	CollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::BULLET_PLAYER, GROUP_TYPE::MONSTER);

}

void ScenePlayerTest::Exit()
{
	DeleteAll();
	CollisionMgr::GetInst()->CheckReset();
}

void ScenePlayerTest::Update()
{
	Scene::Update();
	if (KEY_TAP(KEY::ESC))
	{
		ChangeScene(SCENE_TYPE::SCENE_01);
	}
	if (KEY_TAP(KEY::LBTN) && cObj->IsButtonPos() == true)
	{
		DeleteObject(GROUP_TYPE::BUTTON);
		DeleteObject(GROUP_TYPE::BUTTON);
		Object* pObj = new Player(ResMgr::GetInst()->ImgLoad(L"PlayerAni", L"Image\\player.bmp"), true);
		pObj->SetPos(Vec2(100.f, Core::GetInst()->GetResolution().y / 2.f));
		//Core::GetInst()->GetResolution().x/2
		pObj->SetScale(Vec2(3.f, 3.f));
		pObj->IsDumChit();
		pObj->SetDumChitScale(0.3f);
		AddObject(pObj, GROUP_TYPE::PLAYER);
	}
	if (KEY_TAP(KEY::LBTN) && dObj->IsButtonPos() == true)
	{
		DeleteObject(GROUP_TYPE::BUTTON);
		DeleteObject(GROUP_TYPE::BUTTON);
		Object* pObj = new Player(ResMgr::GetInst()->ImgLoad(L"PlayerAni2", L"Image\\player.bmp"), false);
		pObj->SetPos(Vec2(100.f, Core::GetInst()->GetResolution().y / 2.f));
		//Core::GetInst()->GetResolution().x/2
		pObj->SetScale(Vec2(3.f, 3.f));
		pObj->IsDumChit();
		pObj->SetDumChitScale(0.3f);
		AddObject(pObj, GROUP_TYPE::PLAYER);
	}

	Monster* pMonsterObj = new Monster;
	pMonsterObj->SetPos(Vec2((float)Core::GetInst()->GetResolution().x, (float)(rand() % Core::GetInst()->GetResolution().x)));
	pMonsterObj->SetScale(Vec2(50.f, 50.f));
	pMonsterObj->SetSpeed(300.f);
	pMonsterObj->SetCenterPos(pMonsterObj->GetPos());
	pMonsterObj->IsDumChit();
	AddObject(pMonsterObj, GROUP_TYPE::MONSTER);
	
	//pObj->SetScale(Vec2(3.f, 3.f));
	
}
