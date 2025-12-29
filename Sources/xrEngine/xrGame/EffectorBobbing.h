#ifndef _EFFECTOR_BOBBING_H
#define _EFFECTOR_BOBBING_H
#pragma once

#include "CameraEffector.h"
#include "../cameramanager.h"

class CEffectorBobbing : public CEffectorCam  
{
	float	fTime;
	fVector3	vAngleAmplitude;
	float	fYAmplitude;
	float	fSpeed;

	u32		dwMState;
	float	fReminderFactor;
	bool	is_limping;
	bool	m_bZoomMode;

	float	m_fAmplitudeRun;
	float	m_fAmplitudeWalk;
	float	m_fAmplitudeLimp;

	float	m_fSpeedRun;
	float	m_fSpeedWalk;
	float	m_fSpeedLimp;

public:
			CEffectorBobbing	();
	virtual ~CEffectorBobbing	();
	virtual	BOOL	Process		(fVector3& delta_p, fVector3& delta_d, fVector3& delta_n, float& fFov, float& fFar, float& fAspect);
	void	SetState			(u32 st, bool limping, bool ZoomMode);
};

#endif //_EFFECTOR_BOBBING_H
