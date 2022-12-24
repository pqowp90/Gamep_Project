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
Scene_Start::Scene_Start()
{
}

Scene_Start::~Scene_Start()
{
}
void Scene_Start::Enter()
{
	SoundMgr::GetInst()->LoadSound(L"BGM", true, L"Sound\\TitleBGM.mp3");
	SoundMgr::GetInst()->Play(L"BGM");
	// Object 추가
	Background* bObj = new Background(L"BackGround" ,ResMgr::GetInst()->ImgLoad(L"BackGround", L"Image\\title.bmp"));
	bObj->SetPos(Vec2(230.f, 170.f));
	bObj->SetScale(Vec2(2.f, 2.f)); 
	AddObject(bObj, GROUP_TYPE::BACKGROUND);
	TitleText* tObj = new TitleText(L"TitleText", ResMgr::GetInst()->ImgLoad(L"TitleText", L"Image\\logo.bmp"));
	tObj->SetPos(Vec2(490.f, 200.f));
	tObj->SetScale(Vec2(2.f, 2.f));
	AddObject(tObj, GROUP_TYPE::TEXT);
	/*Object* pObj = new Player;
	pObj->SetPos(Vec2(Core::GetInst()->GetResolution().x/2, Core::GetInst()->GetResolution().y/2));
	pObj->SetScale(Vec2(3.f,3.f));
	AddObject(pObj, GROUP_TYPE::PLAYER);*/
//	Object* pOtherPlayer = new Player(*(Player*)pObj);
	/*Object* pOtherPlayer = pObj->Clone();
	pOtherPlayer->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2.f + 100.f, Core::GetInst()->GetResolution().y / 2.f));
	AddObject(pOtherPlayer, GROUP_TYPE::PLAYER);*/

	//m_vecObj[(UINT)GROUP_TYPE::DEFAULT].push_back(pObj); 

	// Monster Object 추가
	//Monster* pMonsterObj = new Monster;
	//pMonsterObj->SetPos(Vec2(640.f, 50.f));
	//pMonsterObj->SetScale(Vec2(50.f, 50.f));
	//pMonsterObj->SetCenterPos(pMonsterObj->GetPos());
	//AddObject(pMonsterObj, GROUP_TYPE::MONSTER);

	// 몬스터 배치
	/*Vec2 vResolution(Vec2(Core::GetInst()->GetResolution()));
	int iMonster = 16;
	float fMoveDist = 25.f;
	float fObjScale = 50.f;
	float fTerm = (vResolution.x - ((fMoveDist + fObjScale /2.f) * 2)) / (float)(iMonster-1);
	Monster* pMonsterObj = nullptr;
	for (int i = 0; i < iMonster; i++)
	{
		pMonsterObj = new Monster;
		pMonsterObj->SetName(L"Monster");
		pMonsterObj->SetPos(Vec2((fMoveDist + fObjScale / 2.f) + (float)i*fTerm, 50.f));
		pMonsterObj->SetScale(Vec2(fObjScale, fObjScale));
		pMonsterObj->SetCenterPos(pMonsterObj->GetPos());
		pMonsterObj->SetMoveDistance(fMoveDist);
		AddObject(pMonsterObj, GROUP_TYPE::MONSTER);
	}*/
	//pObj = new Object;

	//pObj->SetPos(Vec2(640.f, 384.f));
	//pObj->SetScale(Vec2(100.f, 100.f));

	//AddObject(pObj, GROUP_TYPE::DEFAULT);
	// 충돌 지정 
	// Player - Monster 그룹 간의 충돌 체크
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
