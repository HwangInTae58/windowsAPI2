#include "framework.h"
#include "CObject_Player.h"
#include "CScene.h"
#include "CMissile.h"
#include "PathManager.h"
#include "CTexture.h"

CObject_Player::CObject_Player()
{
	
	//Texture �ε��ϱ�
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
	//GetPos�� �����ͼ� ����
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
	// GetPos ���������̹Ƿ� SetPos�� ������ ���� ��������
	SetPos(fpt);

}

void CObject_Player::render(HDC hDC)
{
	// ���� �̻������� �����Ƿ� ����(int)�� ����ȯ
	int iWidth = (int)m_pTex->Width();
	int iHeight = (int)m_pTex->Height();
	
	fPoint fPos = GetPos();

	//TransparentBlt : ���� ������ ������ ����ó��
	TransparentBlt(hDC,							//�ڽ��� �׸� ������
		int(fPos.x - (float)(iWidth / 2)),		//�»��
		int(fPos.y - (float)(iHeight / 2)),		//
		iWidth, iHeight,
		m_pTex->GetDC(),						//�Ű����� ���� DC
		0, 0, 
		iWidth, iHeight,						//�ű涧�� ���� ũ��? �ڸ��� �ʰ� �����Ŷ� ��ü ����
		RGB(255, 0, 255));
}


void CObject_Player::CreateMissile()
{

	CScene* pCurScene = CSceneManager::getInst()->GetCurScene();

	//��������� �̻����� ��ġ�� �÷��̾� �������� �ϰ�
	fPoint fMissilePos = GetPos();
	// �÷��̾��� �÷��� x��ǥ�� ���뿡�� ����
	fMissilePos.x += GetScale().x / 2.f;
	//�̻��� ������Ʈ ����
	CMissile* missile1 = new CMissile;
	//������Ʈ ������ġ
	missile1->SetPos(fMissilePos);
	//������Ʈ ũ�� ����
	missile1->SetScale(fPoint(15.f, 15.f));
	//������Ʈ�� �����̴� ��ġ����
	missile1->SetDir(fvec(1.f, 0.f));
	pCurScene->AddObject(missile1, GROUP_TYPE::Default);

	CMissile* missile2 = new CMissile;
	missile2->SetPos(fMissilePos);
	missile2->SetScale(fPoint(25.f, 25.f));
	missile2->SetDir(fvec(1.f, -1.f));
	pCurScene->AddObject(missile2, GROUP_TYPE::Default);
}
