#include "framework.h"
#include "StartScene.h"
#include "CGameObject.h"
#include "CObject_Player.h"
#include "CMonster.h"

StartScene::StartScene()
{

}

StartScene::~StartScene()
{

}

void StartScene::Enter()
{
	// object Ãß°¡
	//Player
	CGameObject* pObj = new CObject_Player;
	pObj->SetPos(fPoint(640.f,360.f));
	pObj->SetScale(fPoint(75.f,75.f));
	AddObject(pObj, GROUP_TYPE::Default);

	pObj = new CMonster;
	pObj->SetPos(fPoint(640.f, 360.f));
	pObj->SetScale(fPoint(100.f, 75.f));
	AddObject(pObj, GROUP_TYPE::Default);

	
}

void StartScene::Exit()
{

}
