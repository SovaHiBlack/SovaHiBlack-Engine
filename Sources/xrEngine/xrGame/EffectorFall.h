#pragma once

#include "../Effector.h"

// приседание после падения
class CEffectorFall : public CEffectorCam
{
	float	fPower;
	float	fPhase;
public:
	virtual	BOOL	Process(fVector3& p, fVector3& d, fVector3& n, float& fFov, float& fFar, float& fAspect);

	CEffectorFall(float power, float life_time=1);
	virtual ~CEffectorFall();
};
