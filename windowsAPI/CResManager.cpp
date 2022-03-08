#include "framework.h"
#include "CResManager.h"
#include "PathManager.h"
#include "CTexture.h"

CResManager::CResManager()
{

}
CResManager::~CResManager()
{
	// �ڷᱸ���� ����� ��� Texture ����
	for (map<wstring, CTexture*>::iterator iter = m_mapTex.begin(); iter != m_mapTex.end(); iter++)
	{
		if (nullptr != iter->second)
		{
			delete iter->second;
		}
	}
	m_mapTex.clear();
}

CTexture* CResManager::LoadTextrue(const wstring &strKey, const wstring&strRelativePath)
{
	// Texture�� �ҷ����� �� �ڷᱸ���� �̹� Texture�� �ִ��� Ȯ��
	CTexture* pTex = FindTexture(strKey);
	if (nullptr != pTex)
		return pTex;

	// ������θ� ã�� ���� �ϴ� Content������ �������� 
	wstring strFilePath = PathManager::getInst()->GetContentPath();
	//ã�� �������ϰ� ���ļ� ���� ��θ� ã�´�
	strFilePath += strRelativePath;

	// Texture ���� �� ����
	pTex = new CTexture;
	pTex->Load(strFilePath);
	// TODO : ���� ��ġ�°� ã�ƺ��ߵ�
	pTex->SetKey(strKey);
	pTex->SetRelativePath(strRelativePath);

	m_mapTex.insert(make_pair(strKey, pTex));
	return pTex;
}

CTexture* CResManager::FindTexture(const wstring& _strKey)
{
	map<wstring,CTexture*>::iterator iter = m_mapTex.find(_strKey);

	//texture�� ã�����ؼ� end�� ���� �׳� nullptr��ȯ
	if(iter == m_mapTex.end())
		return nullptr;

	return iter->second;

}
