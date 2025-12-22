#pragma once
#include "../../../../effector.h"
#include "../../../pp_effector_custom.h"

////////////////////////////////////////////////////////////////////////////////////
// CPsyHitEffectorPP
////////////////////////////////////////////////////////////////////////////////////

//class CPsyHitEffectorPP : public CPPEffectorController {
//	typedef CPPEffectorController inherited;
//	
//	float			m_attack_perc;
//	float			m_release_perc;
//
//public:
//	virtual void	load					(LPCSTR section);
//	virtual bool	check_completion		();
//	virtual bool	check_start_conditions	();
//	virtual void	update_factor			();
//
//	virtual CPPEffectorControlled *create_effector	();
//};


////////////////////////////////////////////////////////////////////////////////////
// CPsyHitEffectorCam
////////////////////////////////////////////////////////////////////////////////////

//class CPsyHitEffectorCam : public CEffector {
//	typedef CEffector inherited;	
//
//	float	m_time_total;
//	fVector3	dangle_target;
//	fVector3 dangle_current;
//
//public:
//					CPsyHitEffectorCam	(EEffectorType type);
//	virtual	BOOL	Process				(fVector3 &p, fVector3 &d, fVector3 &n, float& fFov, float& fFar, float& fAspect);
//};
