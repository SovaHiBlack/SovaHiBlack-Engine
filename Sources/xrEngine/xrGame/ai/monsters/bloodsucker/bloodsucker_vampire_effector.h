#pragma once

#include "../../../../effectorPP.h"
#include "../../../CameraEffector.h"
#include "../../../../cameramanager.h"

//////////////////////////////////////////////////////////////////////////
// Vampire Postprocess Effector
//////////////////////////////////////////////////////////////////////////
class CVampirePPEffector : public CEffectorPP {
	typedef CEffectorPP inherited;	

	SPPInfo state;			//current state
	float	m_total;		// total PP time

public:
					CVampirePPEffector		(const SPPInfo &ppi, float life_time);
	virtual	BOOL	Process					(SPPInfo& pp);
};

//////////////////////////////////////////////////////////////////////////
// Vampire Camera Effector
//////////////////////////////////////////////////////////////////////////
class CVampireCameraEffector : public CEffectorCam {
	typedef CEffectorCam inherited;	

	float	m_time_total;
	fVector3	dangle_target;
	fVector3 dangle_current;

	float	m_dist;
	fVector3 m_direction;

public:
					CVampireCameraEffector	(float time, const fVector3& src, const fVector3& tgt);
	virtual	BOOL	Process					(fVector3& p, fVector3& d, fVector3& n, float& fFov, float& fFar, float& fAspect);
};



