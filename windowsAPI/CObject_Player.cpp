#include "framework.h"
#include "CObject_Player.h"
#include "CScene.h"
#include "CMissile.h"
#include "PathManager.h"
#include "CTexture.h"
#include "CResManager.h"

CObject_Player::CObject_Player()
{
	// Resource Manager를 통한 Texture 로딩하기
	m_pTex = CResManager::getInst()->LoadTextrue(L"PlayerTex", L"texture\\Player.bmp");
}

CObject_Player::~CObject_Player()
{
	if (nullptr != m_pTex)
	{
		delete m_pTex;
	}
}

void CObject_Player::update()
{
	//GetPos로 가져와서 수정
	fPoint fpt = GetPos();
	if (Key(VK_LEFT))
	{
		fpt.x -= 300.f * (float)DT;
	}

	if (Key(VK_RIGHT))
	{
		fpt.x += 300.f * (float)DT;
	}

	if (Key(VK_UP))
	{
		fpt.y -= 300.f * (float)DT;
	}

	if (Key(VK_DOWN))
	{
		fpt.y += 300.f * (float)DT;
	}
	
	if (KeyDown(VK_SPACE))
	{
		CreateMissile();
	}
	
	if (KeyDown(VK_LSHIFT))
	{
		CreateGrenade();
	}
	// GetPos 지역변수이므로 SetPos로 수정한 것을 세팅해줌
	SetPos(fpt);

}

void CObject_Player::render(HDC hDC)
{
	// 값이 이상해질수 있으므로 정수(int)로 형변환
	int iWidth = (int)m_pTex->Width();
	int iHeight = (int)m_pTex->Height();
	
	fPoint fPos = GetPos();

	//TransparentBlt : 내가 지정한 조건을 투명처리
	TransparentBlt(hDC,							//자신이 그릴 목적지
		int(fPos.x - (float)(iWidth / 2)),		//좌상단
		int(fPos.y - (float)(iHeight / 2)),		//
		iWidth, iHeight,
		m_pTex->GetDC(),						//옮겨찍을 원본 DC
		0, 0, 
		iWidth, iHeight,						//옮길때의 사진 크기? 자르지 않고 찍을거라 전체 지정
		RGB(255, 0, 255));
}


void CObject_Player::CreateMissile()
{

	CScene* pCurScene = CSceneManager::getInst()->GetCurScene();

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
	missile1->SetDir(fvec(1.f, 0.f));
	pCurScene->AddObject(missile1, GROUP_TYPE::Default);

}

void CObject_Player::CreateGrenade()
{
	//TODO : 중력작용 배워서 수류탄 만들기 
	//TODO : Grenade 오브젝트 만들기
	CScene* pCurScene = CSceneManager::getInst()->GetCurScene();

	//만들어지는 미사일의 위치를 플레이어 기준으로 하고
	fPoint fMissilePos = GetPos();
	// 플레이어의 플러스 x좌표의 반쯤에서 생성
	fMissilePos.y -= GetScale().y / 3.f;
	//미사일 오브젝트 생성
	CMissile* grenade1 = new CMissile;
	//오브젝트 생성위치
	grenade1->SetPos(fMissilePos);
	//오브젝트 크기 설정
	grenade1->SetScale(fPoint(15.f, 15.f));
	//오브젝트의 움직이는 위치설정
	grenade1->SetDir(fvec(1.f, -2.f));
	pCurScene->AddObject(grenade1, GROUP_TYPE::Default);
}

