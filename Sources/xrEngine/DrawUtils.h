//----------------------------------------------------
// file: DrawUtils.h
//----------------------------------------------------

#ifndef DrawUtilsH
#define DrawUtilsH
//----------------------------------------------------
// Utilities
//----------------------------------------------------
class CDUInterface
{
public:
    //----------------------------------------------------
    virtual void __stdcall DrawCross			(const fVector3& p, float szx1, float szy1, float szz1, float szx2, float szy2, float szz2, u32 clr, BOOL bRot45=false)=0;
    virtual void __stdcall DrawCross			(const fVector3& p, float sz, u32 clr, BOOL bRot45=false)=0;
    virtual void __stdcall DrawFlag				(const fVector3& p, float heading, float height, float sz, float sz_fl, u32 clr, BOOL bDrawEntity)=0;
    virtual void __stdcall DrawRomboid			(const fVector3& p, float radius, u32 clr)=0;
    virtual void __stdcall DrawJoint			(const fVector3& p, float radius, u32 clr)=0;

    virtual void __stdcall DrawSpotLight	   	(const fVector3& p, const fVector3& d, float range, float phi, u32 clr)=0;
    virtual void __stdcall DrawDirectionalLight	(const fVector3& p, const fVector3& d, float radius, float range, u32 clr)=0;
    virtual void __stdcall DrawPointLight	   	(const fVector3& p, float radius, u32 clr)=0;

    virtual void __stdcall DrawSound		   	(const fVector3& p, float radius, u32 clr)=0;
    virtual void __stdcall DrawLineSphere	   	(const fVector3& p, float radius, u32 clr, BOOL bCross)=0;

	virtual void __stdcall dbgDrawPlacement		(const fVector3& p, int sz, u32 clr, LPCSTR caption=0, u32 clr_font=0xffffffff)=0;
    virtual void __stdcall dbgDrawVert			(const fVector3& p0, u32 clr, LPCSTR caption=0)=0;
    virtual void __stdcall dbgDrawEdge			(const fVector3& p0, const fVector3& p1, u32 clr, LPCSTR caption=0)=0;
    virtual void __stdcall dbgDrawFace			(const fVector3& p0, const fVector3& p1, const fVector3& p2, u32 clr, LPCSTR caption=0)=0;

    virtual void __stdcall DrawFace				(const fVector3& p0, const fVector3& p1, const fVector3& p2, u32 clr_s, u32 clr_w, BOOL bSolid, BOOL bWire)=0;
    virtual void __stdcall DrawLine				(const fVector3& p0, const fVector3& p1, u32 clr)=0;
    virtual void __stdcall DrawLine				(const fVector3* p, u32 clr)=0;
    virtual void __stdcall DrawLink				(const fVector3& p0, const fVector3& p1, float sz, u32 clr)=0;
    virtual void __stdcall DrawFaceNormal	   	(const fVector3& p0, const fVector3& p1, const fVector3& p2, float size, u32 clr)=0;
    virtual void __stdcall DrawFaceNormal	   	(const fVector3* p, float size, u32 clr)=0;
    virtual void __stdcall DrawFaceNormal	   	(const fVector3& C, const fVector3& N, float size, u32 clr)=0;
    virtual void __stdcall DrawSelectionBox		(const fVector3& center, const fVector3& size, u32* c=0)=0;
    virtual void __stdcall DrawSelectionBox		(const Fbox& box, u32* c=0)=0;
    virtual void __stdcall DrawIdentSphere		(BOOL bSolid, BOOL bWire, u32 clr_s, u32 clr_w)=0;
    virtual void __stdcall DrawIdentSpherePart	(BOOL bSolid, BOOL bWire, u32 clr_s, u32 clr_w)=0;
    virtual void __stdcall DrawIdentCone	   	(BOOL bSolid, BOOL bWire, u32 clr_s, u32 clr_w)=0;
	virtual void __stdcall DrawIdentCylinder   	(BOOL bSolid, BOOL bWire, u32 clr_s, u32 clr_w)=0;
    virtual void __stdcall DrawIdentBox			(BOOL bSolid, BOOL bWire, u32 clr_s, u32 clr_w)=0;

    virtual void __stdcall DrawBox				(const fVector3& offs, const fVector3& Size, BOOL bSolid, BOOL bWire, u32 clr_s, u32 clr_w)=0;
    virtual void __stdcall DrawAABB				(const fVector3& p0, const fVector3& p1, u32 clr_s, u32 clr_w, BOOL bSolid, BOOL bWire)=0;
    virtual void __stdcall DrawAABB				(const Fmatrix& parent, const fVector3& center, const fVector3& size, u32 clr_s, u32 clr_w, BOOL bSolid, BOOL bWire)=0;
    virtual void __stdcall DrawOBB				(const Fmatrix& parent, const Fobb& box, u32 clr_s, u32 clr_w)=0;
	virtual void __stdcall DrawSphere		   	(const Fmatrix& parent, const fVector3& center, float radius, u32 clr_s, u32 clr_w, BOOL bSolid, BOOL bWire)=0;
	virtual void __stdcall DrawSphere		   	(const Fmatrix& parent, const Fsphere& S, u32 clr_s, u32 clr_w, BOOL bSolid, BOOL bWire)=0;
	virtual void __stdcall DrawCylinder			(const Fmatrix& parent, const fVector3& center, const fVector3& dir, float height, float radius, u32 clr_s, u32 clr_w, BOOL bSolid, BOOL bWire)=0;
	virtual void __stdcall DrawCone				(const Fmatrix& parent, const fVector3& apex, const fVector3& dir, float height, float radius, u32 clr_s, u32 clr_w, BOOL bSolid, BOOL bWire)=0;
    virtual void __stdcall DrawPlane		   	(const fVector3& center, const fVector2& scale, const fVector3& rotate, u32 clr_s, u32 clr_w, BOOL bCull, BOOL bSolid, BOOL bWire)=0;
    virtual void __stdcall DrawPlane		   	(const fVector3& p, const fVector3& n, const fVector2& scale, u32 clr_s, u32 clr_w, BOOL bCull, BOOL bSolid, BOOL bWire)=0;
    virtual void __stdcall DrawRectangle	   	(const fVector3& o, const fVector3& u, const fVector3& v, u32 clr_s, u32 clr_w, BOOL bSolid, BOOL bWire)=0;

    virtual void __stdcall DrawGrid				()=0;
    virtual void __stdcall DrawPivot		   	(const fVector3& pos, float sz=5.f)=0;
	virtual void __stdcall DrawAxis				(const Fmatrix& T)=0;
	virtual void __stdcall DrawObjectAxis	   	(const Fmatrix& T, float sz, BOOL sel)=0;
	virtual void __stdcall DrawSelectionRect   	(const iVector2& m_SelStart, const iVector2& m_SelEnd)=0;

    virtual void __stdcall OutText				(const fVector3& pos, LPCSTR text, u32 color=0xFF000000, u32 shadow_color=0xFF909090)=0;
};
//----------------------------------------------------
#endif

