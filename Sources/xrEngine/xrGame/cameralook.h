#pragma once

#include "../CameraBase.h"

class CCameraLook	: public CCameraBase
{
	typedef CCameraBase inherited;

	fVector2		lim_zoom;
	float			dist, prev_d;
public:
					CCameraLook		( CObject* p, u32 flags=0);
	virtual			~CCameraLook	( );
	virtual void	Load			(LPCSTR section);
	virtual void	Move			( int cmd, float val=0, float factor=1.0f );

	virtual	void	OnActivate		( CCameraBase* old_cam );
	virtual void	Update			(fVector3& point, fVector3& noise_dangle );

	virtual float	GetWorldYaw		( )	{ return -yaw;	};
	virtual float	GetWorldPitch	( )	{ return pitch; };
};

class CCameraLook2	: public CCameraLook
{
public:
	static fVector3	m_cam_offset;

protected:
	CObject*		m_locked_enemy;
	fVector2		m_autoaim_inertion_yaw;
	fVector2		m_autoaim_inertion_pitch;
	void			UpdateAutoAim	();

public:
					CCameraLook2	( CObject* p, u32 flags=0):CCameraLook(p, flags){m_locked_enemy=NULL;};
	virtual			~CCameraLook2	(){}
	virtual	void	OnActivate		( CCameraBase* old_cam );
	virtual void	Update			(fVector3& point, fVector3& noise_dangle );
	virtual void	Load			(LPCSTR section);
};
