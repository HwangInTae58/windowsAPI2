#pragma once
class PathManager
{
	SINGLETON(PathManager);
private:
	// �����쿡�� ��ΰ� 255���ڷ� ������ �ɷ������ϱ� 255�� ����
	wchar_t		m_strContentPath[255];
public:
	void init();

	// ���ҽ� ���� ������ ��� ��ȯ
	const wchar_t* GetContentPath();	

};

