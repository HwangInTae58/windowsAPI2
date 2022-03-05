#pragma once
#include "CGameObject.h"
class CMissile : public CGameObject
{
private:
	//미사일이 날아가는 방향을 각도로 정한다
	float m_fTheta; // 미사일이 날아가는 각도

public:
	CMissile();
	virtual ~CMissile();

	virtual void update();
	virtual void render(HDC hDC);

	void SetDir(bool _Right);

};

