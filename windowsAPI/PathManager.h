#pragma once
class PathManager
{
	SINGLETON(PathManager);
private:
	// 윈도우에서 경로가 255글자로 제안이 걸려있으니까 255로 선언
	wchar_t		m_strContentPath[255];
public:
	void init();

	// 리소스 저장 폴더의 경로 반환
	const wchar_t* GetContentPath();	

};

