#include "framework.h"
#include "StartScene.h"
#include "CGameObject.h"
#include "CObject_Player.h"
#include "CMonster.h"
#include "PathManager.h"
#include "CTexture.h"

StartScene::StartScene()
{

}

StartScene::~StartScene()
{

}

void StartScene::Enter()
{
	//Texture 로딩하기
	CTexture* pTex = new CTexture;
	wstring strFilepath = PathManager::getInst()->GetContentPath();
	strFilepath += L"texture\\Player.bmp";
	pTex->Load(strFilepath);

	delete pTex;
	// object 추가
	//Player
	CGameObject* pObj = new CObject_Player;
	pObj->SetPos(fPoint(640.f,360.f));
	pObj->SetScale(fPoint(75.f,75.f));
	AddObject(pObj, GROUP_TYPE::Default);

	CMonster* pMObj = new CMonster;
	pMObj->SetPos(fPoint(1200.f, 360.f));
	pMObj->SetCenterPos(pMObj->GetPos());
	pMObj->SetScale(fPoint(100.f, 75.f));
	AddObject(pMObj, GROUP_TYPE::Default);

	
}

void StartScene::Exit()
{

}
