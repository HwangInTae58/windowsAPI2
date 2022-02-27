#include "framework.h"
#include "CScene.h"
#include "CGameObject.h"


CScene::CScene()
{
}
// 소멸자이므로 소멸할때 벡터도 자동으로 삭제되므로 신경안써도 됨
CScene::~CScene()
{
	for (int i = 0; i < (int)GROUP_TYPE::Size; i++)
	{
		for (int j = 0; j < m_arrObj[i].size(); j++)
		{
			// i 백터의 j 오브젝트를 삭제
			//주소 타입이므로 삭제해야됨
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