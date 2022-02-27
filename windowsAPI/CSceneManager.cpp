#include "framework.h"
#include "CSceneManager.h"
#include "StartScene.h"


CSceneManager::CSceneManager()
{
	//ÇöÁ¦ ¾À ÃÊ±âÈ­
	for (int i = 0; i < (int)SCENE_TYPE::Size; i++)
	{
		m_arrScene[i] = nullptr;
	}
	m_pCurScene = nullptr;
}


CSceneManager::~CSceneManager()
{
	// ¾À »èÁ¦
	for (int i = 0; i < (int)SCENE_TYPE::Size; i++)
	{
		if (nullptr != m_arrScene[i])
		{
			delete m_arrScene[i];
		}
	}
}
void CSceneManager::init()
{
	// ¾À »ı¼º
	m_arrScene[(int)SCENE_TYPE::START] = new StartScene;
	m_arrScene[(int)SCENE_TYPE::START]->SetName(L"Start Scene");


	// ÇöÁ¦ ¾À ÁöÁ¤
	m_pCurScene = m_arrScene[(int)SCENE_TYPE::START];
	m_pCurScene->Enter();
}

void CSceneManager::update()
{
	m_pCurScene->update();
}

void CSceneManager::render(HDC hDc)
{
	m_pCurScene->render(hDc);
}

CScene* CSceneManager::GetCurScene()
{
	return m_pCurScene;
}