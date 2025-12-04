// CameraBase.h: interface for the CCameraBase class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CAMERABASE_H__B11F8AE1_1213_11D4_B4E3_4854E82A090D__INCLUDED_)
#define AFX_CAMERABASE_H__B11F8AE1_1213_11D4_B4E3_4854E82A090D__INCLUDED_
#pragma once

#include "CameraDefs.h"

// refs
class CObject;

class ENGINE_API	CCameraBase
{
protected:
	CObject*		parent;

public:
	BOOL			bClampYaw, bClampPitch, bClampRoll;
	float			yaw,pitch,roll;

	enum{
		flRelativeLink		= (1<<0),
		flPositionRigid		= (1<<1),
		flDirectionRigid	= (1<<2),
	};
	Flags32			m_Flags;

	ECameraStyle	style;
	fVector2		lim_yaw;
	fVector2		lim_pitch;
	fVector2		lim_roll;
	fVector3			rot_speed;

	fVector3			vPosition;
	fVector3			vDirection;
	fVector3			vNormal;
	float			f_fov;
	float			f_aspect;

	int				tag;
public:
					CCameraBase		( CObject* p, u32 flags );
	virtual			~CCameraBase	( );
	virtual void	Load			(LPCSTR section);
	void			SetParent		( CObject* p )								{parent=p; VERIFY(p);}
	virtual	void	OnActivate		( CCameraBase* old_cam )					{;}
	virtual	void	OnDeactivate	( )											{;}
	virtual void	Move			( int cmd, float val=0, float factor=1.0f)	{;}
	virtual void	Update			(fVector3& point, fVector3& noise_angle )	{;}
	virtual void	Get				(fVector3& P, fVector3& D, fVector3& N )		{P.set(vPosition);D.set(vDirection);N.set(vNormal);}
	virtual void	Set				( const fVector3& P, const fVector3& D, const fVector3& N ){vPosition.set(P);vDirection.set(D);vNormal.set(N);}
	virtual void	Set				( float Y, float P, float R )				{yaw=Y;pitch=P;roll=R;}
	
	virtual float	GetWorldYaw		( )	{ return 0; };
	virtual float	GetWorldPitch	( )	{ return 0; };

	virtual float	CheckLimYaw		( );
	virtual float	CheckLimPitch	( );
	virtual float	CheckLimRoll	( );
};

#endif // !defined(AFX_CAMERABASE_H__B11F8AE1_1213_11D4_B4E3_4854E82A090D__INCLUDED_)
