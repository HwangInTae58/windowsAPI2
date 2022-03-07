#include "framework.h"
#include "CObject_Player.h"
#include "CScene.h"
#include "CMissile.h"
#include "PathManager.h"
#include "CTexture.h"

CObject_Player::CObject_Player()
{
	
	//Texture 로딩하기
	m_pTex = new CTexture;
	wstring strFilepath = PathManager::getInst()->GetContentPath();
	strFilepath += L"texture\\Player.bmp";
	m_pTex->Load(strFilepath);
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

	CMissile* missile2 = new CMissile;
	missile2->SetPos(fMissilePos);
	missile2->SetScale(fPoint(25.f, 25.f));
	missile2->SetDir(fvec(1.f, -1.f));
	pCurScene->AddObject(missile2, GROUP_TYPE::Default);
}
