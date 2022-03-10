#pragma once

//���� ����� ������ �ƴ϶� ����� ����
//���漱�� : ���漱������ �������� ��Ȯ���Ͽ� ���̴°� ���´�.
class CGameObject;

class CScene
{
public:
	CScene();
	// �Ҹ��ڸ� �ڽļҸ��ں��� �ҷ��� �Ǵµ� �����Լ� �Ⱥ��̸� �θ�Ҹ��ڸ� �θ���
	virtual ~CScene();
	
	virtual void Enter() = 0; // �ش� ���� ���� �� ȣ�� 
	virtual void Exit() = 0;	//��� ���� Ż��

	void SetName(const wstring& _strName);
	const wstring& GetName();

	void update();
	void finalupdate(); // ������Ʈ�� ������ ���� ���� ������ Ȯ������ update
	void render(HDC hDc);
private:
	//������Ʈ�� ���� �� ������ ���͸� �׷� ������ŭ ����
	vector<CGameObject*> m_arrObj[(UINT)GROUP_TYPE::Size];

	// wstring : wchar_t�� string ���ڿ��� �� Ÿ��
	wstring		m_strName;	//Scene �̸�

public:
	void AddObject(CGameObject* _pObj, GROUP_TYPE _eType);

};

