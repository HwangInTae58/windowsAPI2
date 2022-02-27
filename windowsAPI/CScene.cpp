#include "framework.h"
#include "CScene.h"
#include "CGameObject.h"


CScene::CScene()
{
}
// �Ҹ����̹Ƿ� �Ҹ��Ҷ� ���͵� �ڵ����� �����ǹǷ� �Ű�Ƚᵵ ��
CScene::~CScene()
{
	for (int i = 0; i < (int)GROUP_TYPE::Size; i++)
	{
		for (int j = 0; j < m_arrObj[i].size(); j++)
		{
			// i ������ j ������Ʈ�� ����
			//�ּ� Ÿ���̹Ƿ� �����ؾߵ�
			delete m_arrObj[i][j];
		}
	}
}

void CScene::SetName(const wstring& _strName)
{
	m_strName = _strName;
}

const wstring& CScene::GetName()
{
	return m_strName;
}

void CScene::update()
{
	for (int i = 0; i < (int)GROUP_TYPE::Size; i++)
	{
		for (int j = 0; j < m_arrObj[i].size(); j++)
		{
			m_arrObj[i][j]->update();
		}
	}
}

void CScene::render(HDC hDc)
{
	for (int i = 0; i < (int)GROUP_TYPE::Size; i++)
	{
		for (int j = 0; j < m_arrObj[i].size(); j++)
		{
			m_arrObj[i][j]->render(hDc);
		}
	}
}

void CScene::AddObject(CGameObject* _pObj, GROUP_TYPE _eType)
{
	m_arrObj[(UINT)_eType].push_back(_pObj);
}