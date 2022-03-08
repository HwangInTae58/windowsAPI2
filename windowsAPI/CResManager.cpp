#include "framework.h"
#include "CResManager.h"
#include "PathManager.h"
#include "CTexture.h"

CResManager::CResManager()
{

}
CResManager::~CResManager()
{
	// 자료구조에 저장된 모든 Texture 삭제
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
	// Texture를 불러오기 전 자료구조에 이미 Texture가 있는지 확인
	CTexture* pTex = FindTexture(strKey);
	if (nullptr != pTex)
		return pTex;

	// 최종경로를 찾기 위해 일단 Content폴더를 가져온후 
	wstring strFilePath = PathManager::getInst()->GetContentPath();
	//찾을 폴더값하고 합쳐서 최종 경로를 찾는다
	strFilePath += strRelativePath;

	// Texture 생성 후 저장
	pTex = new CTexture;
	pTex->Load(strFilePath);
	// TODO : 오류 고치는거 찾아봐야됨
	pTex->SetKey(strKey);
	pTex->SetRelativePath(strRelativePath);

	m_mapTex.insert(make_pair(strKey, pTex));
	return pTex;
}

CTexture* CResManager::FindTexture(const wstring& _strKey)
{
	map<wstring,CTexture*>::iterator iter = m_mapTex.find(_strKey);

	//texture를 찾지못해서 end로 가면 그냥 nullptr반환
	if(iter == m_mapTex.end())
		return nullptr;

	return iter->second;

}
