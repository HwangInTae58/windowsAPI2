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
	// ���� ���α׷��� �۾� ��θ� �������� �Լ�
	GetCurrentDirectory(255, m_strContentPath);

	//���������� ã�¹�
	// wcslen : wchar_t(���ڿ�)���� nullptr�� �����ϰ� ���ڿ��� ���̸� ��ȯ�Ѵ�.
	int iLen = wcslen(m_strContentPath);	// ���� ���ڿ� ũ�⸦ �˾Ƴ���.


	for (int i = iLen - 1; i >= 0; i--)
	{
		if ('\\' == m_strContentPath[i])
		{
			m_strContentPath[i] = '\0';
			break;
		}
	}
	// wchar_t ���ڿ� �ڿ� ���ڿ� ���̱�
	wcscat_s(m_strContentPath, 255, L"\\Release\\content\\");	


}

const wchar_t* PathManager::GetContentPath()
{
	return m_strContentPath;
}


