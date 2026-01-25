/////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
#ifndef PH_JOINT
#define PH_JOINT
#include "PhysicsShell.h"
class CPHJointDestroyInfo;
class CPHJoint: public CPhysicsJoint{
///////////////////////////////////////////////////////
				u16									m_bone_id																								;
				CPHElement							*pFirst_element																							;
				CPHElement							*pSecond_element																						;
				CODEGeom							*pFirstGeom																								;
			/////////////////////////////////////////////////////////
				CPHShell							*pShell																									;
				dJointID							m_joint																									;
				dJointID							m_joint1																								;
				CPhysicsJoint						**m_back_ref																							;					
				CPHJointDestroyInfo					*m_destroy_info																							;
				float								m_erp																									;			//joint erp
				float								m_cfm																									;			//joint cfm
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	struct SPHAxis {
			float					high							;						//high limit
			float					low								;						//law limit
			float					zero							;						//zero angle position
			float					erp								;						//limit erp
			float					cfm								;						//limit cfm
			eVs  					vs								;						//coordinate system 
			float					force							;						//max force
			float					velocity						;						//velocity to achieve
			fVector3				direction						;						//axis direction
		IC 	void 					set_limits						(float h, float l)												{high=h; low=l			;}
		IC 	void 					set_direction					(const fVector3& v)												{direction.set(v)		;}
		IC 	void 					set_direction					(const float x,const float y,const float z)						{direction.set(x,y,z)	;}
		IC 	void 					set_param						(const float e,const float c)											{erp=e;cfm=c	;}	
		   	void					set_sd_factors					(float sf,float df,enumType jt)															;
									SPHAxis							();
	};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
				xr_vector<SPHAxis>		axes																																																												;
				fVector3				anchor																																																												;
				eVs						vs_anchor																																																											;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////																						
				void 					CreateBall					()																																																						;
				void 					CreateHinge					()																																																						;
				void 					CreateHinge2				()																																																						;
				void 					CreateFullControl			()																																																						;
				void					CreateSlider				()																																																						;
				void 					LimitAxisNum				(int &axis_num)																																																			;
				void 					SetForceActive				(const int axis_num)																																																	;
				void 					SetVelocityActive			(const int axis_num)																																																	;
				void					SetLimitsActive				(int axis_num)																																																			;
				void 					CalcAxis					(int ax_num, fVector3& axis,float& lo,float& hi,const fMatrix4x4& first_matrix,const fMatrix4x4& second_matrix)																													;
				void 					CalcAxis					(int ax_num, fVector3& axis,float& lo,float& hi,const fMatrix4x4& first_matrix,const fMatrix4x4& second_matrix,const fMatrix4x4& rotate)																							;
	virtual		u16						GetAxesNumber				()																																																						;
	virtual		void 					SetAxisSDfactors			(float spring_factor,float damping_factor,int axis_num)																																									;
	virtual		void 					SetJointSDfactors			(float spring_factor,float damping_factor)																																												;
	virtual		void					SetJointSDfactorsActive		()																																																						;
	virtual		void					SetLimitsSDfactorsActive	()																																																						;
	virtual		void					SetAxisSDfactorsActive		(int axis_num)																																																			;
	virtual		void 					SetAxis						(const SPHAxis& axis,const int axis_num)																																												;
	virtual		void 					SetAnchor					(const fVector3& position)																																					{SetAnchor(position.x,position.y,position.z);}
	virtual		void 					SetAnchorVsFirstElement		(const fVector3& position)																																	{SetAnchorVsFirstElement(position.x,position.y,position.z)	;}
	virtual		void 					SetAnchorVsSecondElement	(const fVector3& position)																																	{SetAnchorVsSecondElement(position.x,position.y,position.z)	;}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	virtual		void 					SetAxisDir					(const fVector3& orientation,const int axis_num)																											{SetAxisDir(orientation.x,orientation.y,orientation.z,axis_num)	;}
	virtual		void 					SetAxisDirVsFirstElement	(const fVector3& orientation,const int axis_num)																							{SetAxisDirVsFirstElement(orientation.x,orientation.y,orientation.z,axis_num)	;}
	virtual		void 					SetAxisDirVsSecondElement	(const fVector3& orientation,const int axis_num)																							{SetAxisDirVsSecondElement(orientation.x,orientation.y,orientation.z,axis_num)	;}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	virtual		void 					SetLimits					(const float low,const float high,const int axis_num)																																									;
	virtual		void 					SetLimitsVsFirstElement		(const float low,const float high,const int axis_num)																																									;
	virtual		void 					SetLimitsVsSecondElement	(const float low,const float high,const int axis_num)																																									;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	virtual		void 					SetAnchor					(const float x,const float y,const float z)																																												;
	virtual		void 					SetAnchorVsFirstElement		(const float x,const float y,const float z)																																												;
	virtual		void 					SetAnchorVsSecondElement	(const float x,const float y,const float z)																																												;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	virtual		void 					SetAxisDir					(const float x,const float y,const float z,const int axis_num)																																							;
	virtual		void 					SetAxisDirVsFirstElement	(const float x,const float y,const float z,const int axis_num)																																							;
	virtual		void 					SetAxisDirVsSecondElement	(const float x,const float y,const float z,const int axis_num)																																							;
public:
	virtual		CPhysicsElement			*PFirst_element 			()																																																						;
	virtual		CPhysicsElement			*PSecond_element			()																																																						;
	virtual		u16					 	BoneID						()																																																	{return m_bone_id	;}
	virtual		void					SetBoneID					(u16 bone_id)																																														{m_bone_id=bone_id	;}
IC				CPHElement				*PFirstElement  			()																																																{return pFirst_element	;}
IC				CPHElement				*PSecondElement 			()																																																{return pSecond_element	;}
	virtual		void 					Activate					()																																																						;
	virtual		void 					Create						()																																																						;
	virtual		void 					RunSimulation				()																																																						;
	virtual		void 					SetBackRef					(CPhysicsJoint	**j)																																																	;
	virtual		void 					SetForceAndVelocity			(const float force,const float velocity=0.f,const int axis_num=-1)																																						;
	virtual		void 					SetForce					(const float force,const int axis_num=-1)																																												;
	virtual		void 					SetVelocity					(const float velocity=0.f,const int axis_num=-1)																																										;
	virtual		void 					SetBreakable				(float force, float torque)																																																;
	virtual		bool					isBreakable					()																																																{return !!m_destroy_info;}
	virtual		dJointID 				GetDJoint					()																																																{return m_joint			;}
	virtual		dJointID 				GetDJoint1					()																																																{return m_joint1		;}
	virtual		void 					GetLimits					(float& lo_limit,float& hi_limit,int axis_num)																																											;
	virtual		void 					GetAxisDir					(int num, fVector3& axis,eVs& vs)																																															;
	virtual		void 					GetAxisDirDynamic			(int num, fVector3& axis)																																																	;
	virtual		void 					GetAnchorDynamic			(fVector3& anchor)																																																		;
	virtual		void 					GetAxisSDfactors			(float& spring_factor,float& damping_factor,int axis_num)																																								;
	virtual		void 					GetJointSDfactors			(float& spring_factor,float& damping_factor)																																											;
	virtual		void					GetMaxForceAndVelocity		(float &force,float &velocity,int axis_num)																																												;
	virtual		float					GetAxisAngle				(int axis_num)																																																			;
	virtual		void 					Deactivate					()																																																						;
				void 					ReattachFirstElement		(CPHElement* new_element)																																																;
				CODEGeom				*&RootGeom					()																																																	{return pFirstGeom	;}
	virtual		CPHJointDestroyInfo		*JointDestroyInfo			()																																																{return m_destroy_info	;}
										CPHJoint					(CPhysicsJoint::enumType type ,CPhysicsElement* first,CPhysicsElement* second)																																			;
	virtual								~CPHJoint					()																																																						;
				void					SetShell					(CPHShell* p)																																																			;			

				void					ClearDestroyInfo			();
};

///////////////////////////////////////////////////////////////////////////////////////////////////
IC void own_axis(const fMatrix4x4& m, fVector3& axis){
	if(m._11==1.f) {axis.set(1.0f,0.0f,0.0f); return;}
	float k=m._13*m._21-m._11*m._23+m._23;

	if(k==0.0f){
		if(m._13==0.0f) {axis.set(0.0f,0.0f,1.0f);return;}
		float k1=m._13/(1.0f-m._11);
		axis.z=_sqrt(1.0f/(1.0f+k1*k1));
		axis.x=axis.z*k1;
		axis.y=0.0f;
		return;
	}

	float k_zy=-(m._12*m._21-m._11*m._22+m._11+m._22-1.0f)/k;
	float k_xy=(m._12+m._13*k_zy)/(1.0f-m._11);
	axis.y=_sqrt(1.0f/(k_zy*k_zy+k_xy*k_xy+1.0f));
	axis.x=axis.y*k_xy;
	axis.z=axis.y*k_zy;
	return;
}

IC void own_axis_angle(const fMatrix4x4& m, fVector3& axis,float& angle){
	own_axis(m,axis);
	fVector3 ort1;
	fVector3 ort2;
	if(!(axis.z==0.0f&&axis.y==0.0f)){
		ort1.set(0.0f,-axis.z,axis.y);
		ort2.crossproduct(axis,ort1);
	}
	else{
		ort1.set(0.0f,1.0f,0.0f);
		ort2.crossproduct(axis,ort1);
	}
	ort1.normalize();
	ort2.normalize();

	fVector3 ort1_t;
	m.transform_dir(ort1_t,ort1);

	float cosinus=ort1.dotproduct(ort1_t);
	float sinus=ort2.dotproduct(ort1_t);
	angle=acosf(cosinus);
	if(sinus<0.f) angle= -angle;
}

IC void axis_angleB(const fMatrix4x4& m, const fVector3& axis,float& angle){

	fVector3 ort1;
	fVector3 ort2;
	if(!(fis_zero(axis.z)&&fis_zero(axis.y))){
		ort1.set(0.0f,-axis.z,axis.y);
		ort2.crossproduct(axis,ort1);
	}
	else{
		ort1.set(0.0f,1.0f,0.0f);
		ort2.crossproduct(axis,ort1);
	}
	ort1.normalize();
	ort2.normalize();
	fVector3 ort1_t;
	m.transform_dir(ort1_t,ort1);
	fVector3 ort_r;
	float pr1,pr2;
	pr1=ort1.dotproduct(ort1_t);
	pr2=ort2.dotproduct(ort1_t);
	if(pr1==0.0f&&pr2==0.0f){angle=0.0f;return;}
	ort_r.set(pr1*ort1.x+pr2*ort2.x,
		pr1*ort1.y+pr2*ort2.y,
		pr1*ort1.z+pr2*ort2.z);

	ort_r.normalize();
	float cosinus=ort1.dotproduct(ort_r);
	float sinus=ort2.dotproduct(ort_r);
	angle=acosf(cosinus);
	if(sinus<0.0f) angle= -angle;
}

IC void axis_angleA(const fMatrix4x4& m, const fVector3& axis,float& angle){

	fVector3 ort1;
	fVector3 ort2;
	fVector3 axis_t;
	m.transform_dir(axis_t,axis);
	if(!(fis_zero(axis_t.z)&&fis_zero(axis_t.y))){
		ort1.set(0.0f,-axis_t.z,axis_t.y);
		ort2.crossproduct(axis_t,ort1);
	}
	else{
		ort1.set(0.0f,1.0f,0.0f);
		ort2.crossproduct(axis_t,ort1);
	}
	ort1.normalize();
	ort2.normalize();
	fVector3 ort1_t;
	m.transform_dir(ort1_t,ort1);
	fVector3 ort_r;
	float pr1,pr2;
	pr1=ort1.dotproduct(ort1_t);
	pr2=ort2.dotproduct(ort1_t);
	if(pr1==0.0f&&pr2==0.0f){angle=0.0f;return;}
	ort_r.set(pr1*ort1.x+pr2*ort2.x,
		pr1*ort1.y+pr2*ort2.y,
		pr1*ort1.z+pr2*ort2.z);

	ort_r.normalize();
	float cosinus=ort1.dotproduct(ort_r);
	float sinus=ort2.dotproduct(ort_r);
	angle=acosf(cosinus);
	if(sinus<0.f) angle= -angle;
	//if(angle>M_PI) angle=angle-2.f*M_PI;
	//if(angle<-M_PI) angle=angle+2.f*M_PI;
}
#endif
