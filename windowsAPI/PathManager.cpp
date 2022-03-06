#include "framework.h"
#include "PathManager.h"

PathManager::PathManager() 
{
	m_strContentPath[0] = {};
}
PathManager::~PathManager()
{

}

void PathManager::init()
{
	// 현재 프로그램의 작업 경로를 가져오는 함수
	GetCurrentDirectory(255, m_strContentPath);

	//상위폴더를 찾는법
	// wcslen : wchar_t(문자열)에서 nullptr를 제외하고 문자열의 길이를 반환한다.
	int iLen = wcslen(m_strContentPath);	// 먼저 문자열 크기를 알아낸다.


	for (int i = iLen - 1; i >= 0; i--)
	{
		if ('\\' == m_strContentPath[i])
		{
			m_strContentPath[i] = '\0';
			break;
		}
	}
	// wchar_t 문자열 뒤에 문자열 붙이기
	wcscat_s(m_strContentPath, 255, L"\\Release\\content\\");	


}

const wchar_t* PathManager::GetContentPath()
{
	return m_strContentPath;
}


