#pragma once

template <class T>
class _plane2
{
public:
	using TYPE = T;
	using Self = _plane2<TYPE>;
	using SelfRef = Self&;
	using SelfCRef = const Self&;
	using Tvector = _vector2<TYPE>;

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
	IC SelfRef build(const Tvector& _p, const Tvector& _n)
	{
		d = -n.normalize(_n).dotproduct(_p);
		return *this;
	}
	IC SelfRef project(Tvector& pdest, Tvector& psrc)
	{
		pdest.mad(psrc, n, -classify(psrc));
		return *this;
	}
	IC TYPE classify(const Tvector& v) const
	{
		return (n.dotproduct(v) + d);
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

		if (_abs(denom) < EPS_S)			// normal is orthogonal to vector3, cant intersect
		{
			return FALSE;
		}

		dist = -(numer / denom);
		return ((dist > 0.0f) || fis_zero(dist));
	}
	IC BOOL intersectRayPoint(const Tvector& P, const Tvector& D, Tvector& dest)
	{
		TYPE numer = classify(P);
		TYPE denom = n.dotproduct(D);

		if (_abs(denom) < EPS_S)			// normal is orthogonal to vector3, cant intersect
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
	IC BOOL intersect(const Tvector& u, const Tvector& v,		// segment
					  Tvector& isect)							// intersection point
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
};

using fPlane2 = _plane2<f32>;
using dPlane2 = _plane2<f64>;

template <class T>
BOOL _valid(const _plane2<T>& s)
{
	return _valid(s.n) && _valid(s.d);
}
