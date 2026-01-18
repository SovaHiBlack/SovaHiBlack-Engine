#include "pch_script.h"
#include "ai_space.h"
#include "script_engine.h"
#include "ActorEffector.h"
#include "../ObjectAnimator.h"

void CAnimatorCamEffectorScriptCB::ProcessIfInvalid(fVector3& p, fVector3& d, fVector3& n, f32& fFov, f32& fFar, f32& fAspect)
{
	if(m_bAbsolutePositioning)
	{
		const fMatrix4x4& m			= m_objectAnimator->XFORM();
		d							= m.k;
		n							= m.j;
		p							= m.c;
	}
}

BOOL CAnimatorCamEffectorScriptCB::Valid()
{
	BOOL res = inherited::Valid();
	if(!res && cb_name.size() )
	{
		luabind::functor<LPCSTR>			fl;
		R_ASSERT							(ai().script_engine().functor<LPCSTR>(*cb_name,fl));
		fl									();
		cb_name								= "";
	}
	return res;
}
