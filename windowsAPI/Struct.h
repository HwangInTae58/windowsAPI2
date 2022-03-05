#pragma once
struct fPoint
{
	//포인터를 float형태로 바꿔사용하는 구조체
	float x;
	float y;
	fPoint()
	{
		x = 0;
		y = 0;
	}
	fPoint(float x, float y)
	{
		this->x = x;
		this->y = y;
	}
};

struct fvec
{
	//포인터를 float형태로 바꿔사용하는 구조체
	float x;
	float y;
	fvec()
	{
		x = 0;
		y = 0;
	}
	fvec(float x, float y)
	{
		this->x = x;
		this->y = y;
	}
	
	fvec& Normalize()
	{
		// sqrt : 루트 함수
		// length 에 x와 y를 각각 나누면 1이 된다.
		float length = sqrt(x * x + y * y);

		//에초에 0이 나오면 계산자체가 안되기 때문에 assert사용
		// 0이 아니라면 true로 진행0이라면 null이 뜨면서 트리거
		assert(length != 0.f);
		x /= length;
		y /= length;
		

		return *this;
	}
};