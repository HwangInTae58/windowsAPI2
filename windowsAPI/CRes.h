#pragma once
class CRes
{
private:
	// 텍스쳐 사운드 둘다 가져야할 값
	wstring m_strKey;	//리소스 키 (가져올 리소스에 대한 문자열)
	wstring m_strRelativePath; //리소스 상대 경로

public:
	CRes();
	virtual ~CRes();

	void SetKey(const wstring& strKey);
	void SetRelativePath(const wstring& strPath);

	const wstring& GetKey();
	const wstring& GetRekativePath();


};

