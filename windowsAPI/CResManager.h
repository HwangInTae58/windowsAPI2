#pragma once

class CTexture;

class CResManager
{
	SINGLETON(CResManager);
private:
	

	map<wstring, CTexture*> m_mapTex;


public:
	CTexture* FindTexture(const wstring& strKey);	// 저장된 Texture 탐색
	// Texture 불러오기 이미 있는 경우 있던 Texture 반환
	CTexture* LoadTextrue(const wstring& strKey, const wstring& strRelativePath);	
	
};

