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

	void SetKey(wstring& strKey);
	void SetRekativePath(wstring& strPath);

	const wstring& GetKey();
	const wstring& GetRekativePath();


};

