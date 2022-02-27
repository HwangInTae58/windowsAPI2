#pragma once


class CScene;

class CSceneManager
{
private:
	//TODO : �̱������� �����ߴµ� �����ڶ� �Ҹ��� �־ ������ �߻��� �ſ���
	SINGLETON(CSceneManager);

	
	CScene* m_arrScene[(int)SCENE_TYPE::Size];	//	��� �� ���
	CScene* m_pCurScene;						//	���� �� ���

public:

	void update();
	void render(HDC hDC);
	void init();

	CScene* GetCurScene();							//���� �� ��ȯ
};