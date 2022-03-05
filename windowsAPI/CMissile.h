#pragma once
#include "CGameObject.h"
class CMissile : public CGameObject
{
private:
	//미사일이 날아가는 방향을 각도로 정한다
	float m_fTheta; // 미사일이 날아가는 각도

	// 빗변(r)이 1일때 x, y는 x = cos각도 / 빗변, y = sin각도 / 빗변 이니까
	//x = cos각도, y = sin각도
	fvec m_vDir;

public:
	CMissile();
	virtual ~CMissile();

	virtual void update();
	virtual void render(HDC hDC);
	void SetDir(fvec _fvec);



};

