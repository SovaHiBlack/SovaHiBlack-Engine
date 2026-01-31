#pragma once

template <class T>
class _plane
{
public:
	using TYPE = T;
	using Self = _plane<TYPE>;
	using SelfRef = Self&;
	using SelfCRef = const Self&;
	using Tvector = _vector3<TYPE>;
	using Tmatrix = _matrix4x4<TYPE>;

	Tvector n;
	TYPE d;

	IC SelfRef set(SelfRef P)
	{
		n.set(P.n);
		d = P.d;
		return *this;
	}
	IC BOOL similar(SelfRef P, TYPE eps_n = EPS, TYPE eps_d = EPS)
	{
		return (n.similar(P.n, eps_n) && (_abs(d - P.d) < eps_d));
	}
	ICF SelfRef build(const Tvector& v1, const Tvector& v2, const Tvector& v3)
	{
		Tvector t1;
		Tvector t2;
		n.crossproduct(t1.sub(v1, v2), t2.sub(v1, v3)).normalize( );
		d = -n.dotproduct(v1);
		return *this;
	}
	ICF SelfRef build_precise(const Tvector& v1, const Tvector& v2, const Tvector& v3)
	{
		Tvector t1;
		Tvector t2;
		n.crossproduct(t1.sub(v1, v2), t2.sub(v1, v3)); exact_normalize(n);
		d = -n.dotproduct(v1);
		return *this;
	}
	ICF SelfRef build(const Tvector& _p, const Tvector& _n)
	{
		d = -n.normalize(_n).dotproduct(_p);
		return *this;
	}
	ICF SelfRef build_unit_normal(const Tvector& _p, const Tvector& _n)
	{
		VERIFY(fsimilar(_n.magnitude( ), 1, EPS));
		d = -n.set(_n).dotproduct(_p);
		return *this;
	}
	IC SelfRef project(Tvector& pdest, Tvector& psrc)
	{
		pdest.mad(psrc, n, -classify(psrc));
		return *this;
	}
	ICF TYPE classify(const Tvector& v) const
	{
		return n.dotproduct(v) + d;
	}
	IC SelfRef normalize( )
	{
		TYPE denom = 1.0f / n.magnitude( );
		n.mul(denom);
		d *= denom;
		return *this;
	}
	IC TYPE distance(const Tvector& v)
	{
		return _abs(classify(v));
	}
	IC BOOL intersectRayDist(const Tvector& P, const Tvector& D, TYPE& dist)
	{
		TYPE numer = classify(P);
		TYPE denom = n.dotproduct(D);

		if (_abs(denom) < EPS_S)  // normal is orthogonal to vector3, cant intersect
		{
			return FALSE;
		}

		dist = -(numer / denom);
		return ((dist > 0.0f) || fis_zero(dist));
	}
	ICF BOOL intersectRayPoint(const Tvector& P, const Tvector& D, Tvector& dest)
	{
		TYPE numer = classify(P);
		TYPE denom = n.dotproduct(D);

		if (_abs(denom) < EPS_S) // normal is orthogonal to vector3, cant intersect
		{
			return FALSE;
		}
		else
		{
			f32 dist = -(numer / denom);
			dest.mad(P, D, dist);
			return ((dist > 0.0f) || fis_zero(dist));
		}
	}
	IC BOOL intersect(const Tvector& u, const Tvector& v,	// segment
					  Tvector& isect)						// intersection point
	{
		TYPE denom;
		TYPE dist;
		Tvector t;

		t.sub(v, u);
		denom = n.dotproduct(t);
		if (_abs(denom) < EPS) // they are parallel
		{
			return false;
		}

		dist = -(n.dotproduct(u) + d) / denom;
		if (dist < -EPS || dist > 1 + EPS)
		{
			return false;
		}

		isect.mad(u, t, dist);
		return true;
	}

	IC BOOL intersect_2(const Tvector& u, const Tvector& v,			// segment
						Tvector& isect)								// intersection point
	{
		TYPE dist1;
		TYPE dist2;
		Tvector t;

		dist1 = n.dotproduct(u) + d;
		dist2 = n.dotproduct(v) + d;

		if (dist1 * dist2 < 0.0f)
		{
			return false;
		}

		t.sub(v, u);
		isect.mad(u, t, dist1 / _abs(dist1 - dist2));

		return true;
	}
	IC SelfRef transform(Tmatrix& M)
	{
		// rotate the normal
		M.transform_dir(n);
		// slide the offset
		d -= M.c.dotproduct(n);
		return *this;
	}
};

using fPlane = _plane<f32>;
//using dPlane = _plane<f64>;

template <class T>
BOOL _valid(const _plane<T>& s)
{
	return (_valid(s.n) && _valid(s.d));
}
