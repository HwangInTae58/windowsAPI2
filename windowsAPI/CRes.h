#pragma once
class CRes
{
private:
	// �ؽ��� ���� �Ѵ� �������� ��
	wstring m_strKey;	//���ҽ� Ű (������ ���ҽ��� ���� ���ڿ�)
	wstring m_strRelativePath; //���ҽ� ��� ���

public:
	CRes();
	virtual ~CRes();

	void SetKey(const wstring& strKey);
	void SetRelativePath(const wstring& strPath);

	const wstring& GetKey();
	const wstring& GetRekativePath();


};

