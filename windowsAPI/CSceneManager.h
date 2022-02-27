#pragma once


class CScene;

class CSceneManager
{
private:
	//TODO : 싱글톤으로 선언했는데 생성자랑 소멸자 넣어서 오류가 발생한 거였음
	SINGLETON(CSceneManager);

	
	CScene* m_arrScene[(int)SCENE_TYPE::Size];	//	모든 씬 목록
	CScene* m_pCurScene;						//	현제 씬 목록

public:

	void update();
	void render(HDC hDC);
	void init();

	CScene* GetCurScene();							//현재 씬 반환
};