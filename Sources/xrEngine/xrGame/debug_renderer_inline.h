////////////////////////////////////////////////////////////////////////////
//	Module 		: debug_renderer_inline.h
//	Created 	: 19.06.2006
//  Modified 	: 19.06.2006
//	Author		: Dmitriy Iassenev
//	Description : debug renderer inline functions
////////////////////////////////////////////////////////////////////////////

#pragma once

IC	void CDebugRenderer::render			()
{
	if (m_line_vertices.empty())
		return;

	RCache.set_xform_world			(Fidentity);
	RCache.dbg_Draw					(D3DPT_LINELIST,&*m_line_vertices.begin(),m_line_vertices.size(),&*m_line_indices.begin(),m_line_vertices.size()/2);
	m_line_vertices.resize			(0);
}

IC	void CDebugRenderer::draw_line		(const fMatrix4x4& matrix, const fVector3& vertex0, const fVector3& vertex1, const u32 &color)
{
	if ((m_line_vertices.size() + 2) >= line_vertex_limit)
		render						();

	FVF::L							temp;
	temp.color						= color;

	matrix.transform_tiny			(temp.p,vertex0);
	m_line_vertices.push_back		(temp);

	matrix.transform_tiny			(temp.p,vertex1);
	m_line_vertices.push_back		(temp);
}

IC	void CDebugRenderer::draw_aabb		(const fVector3& center, const float &half_radius_x, const float &half_radius_y, const float &half_radius_z, const u32 &color)
{
	fVector3						half_radius;
	half_radius.set					(half_radius_x,half_radius_y,half_radius_z);

	fMatrix4x4							matrix;
	matrix.translate				(center);

	draw_obb						(matrix,half_radius,color);	
}
