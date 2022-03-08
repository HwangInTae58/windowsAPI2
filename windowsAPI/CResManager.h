#pragma once

class CTexture;

class CResManager
{
	SINGLETON(CResManager);
private:
	

	map<wstring, CTexture*> m_mapTex;


public:
	CTexture* FindTexture(const wstring& strKey);	// ����� Texture Ž��
	// Texture �ҷ����� �̹� �ִ� ��� �ִ� Texture ��ȯ
	CTexture* LoadTextrue(const wstring& strKey, const wstring& strRelativePath);	
	
};

