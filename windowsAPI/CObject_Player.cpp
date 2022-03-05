#include "framework.h"
#include "CObject_Player.h"
#include "CScene.h"
#include "CMissile.h"

void CObject_Player::update()
{
	//GetPos로 가져와서 수정
	fPoint fpt = GetPos();
	if (CKeyManager::getInst()->GetButton(VK_LEFT))
	{
		fpt.x -= 300.f * (float)DT;
	}

	if (CKeyManager::getInst()->GetButton(VK_RIGHT))
	{
		fpt.x += 300.f * (float)DT;
	}

	if (CKeyManager::getInst()->GetButton(VK_UP))
	{
		fpt.y -= 300.f * (float)DT;
	}

	if (CKeyManager::getInst()->GetButton(VK_DOWN))
	{
		fpt.y += 300.f * (float)DT;
	}

	if (CKeyManager::getInst()->GetButtonDown(VK_SPACE))
	{
		CreateMissile();
	}
	// GetPos 지역변수이므로 SetPos로 수정한 것을 세팅해줌
	SetPos(fpt);

}

void CObject_Player::CreateMissile()
{
	//만들어지는 미사일의 위치를 플레이어 기준으로 하고
	fPoint fMissilePos = GetPos();
	// 플레이어의 플러스 x좌표의 반쯤에서 생성
	fMissilePos.x += GetScale().x / 2.f;
	//미사일 오브젝트 생성
	CMissile* missile1 = new CMissile;
	//오브젝트 생성위치
	missile1->SetPos(fMissilePos);
	//오브젝트 크기 설정
	missile1->SetScale(fPoint(15.f, 15.f));
	//오브젝트의 움직이는 위치설정
	

	CScene* pCurScene =	CSceneManager::getInst()->GetCurScene();
	pCurScene->AddObject(missile1,GROUP_TYPE::Default);

}
