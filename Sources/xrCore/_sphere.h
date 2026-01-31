#pragma once

template <class T>
class _sphere
{
public:
	using TYPE = T;
	using Self = _sphere<TYPE>;
	using SelfRef = Self&;
	using SelfCRef = const Self&;
	using Tvector = _vector3<TYPE>;

	Tvector			P;
	TYPE			R;

	IC void set(const Tvector& _P, TYPE _R)
	{
		P.set(_P);
		R = _R;
	}
	IC void set(SelfCRef S)
	{
		P.set(S.P);
		R = S.R;
	}
	IC void identity( )
	{
		P.set(0, 0, 0);
		R = 1;
	}

	enum ERP_Result
	{
		rpNone = 0,
		rpOriginInside = 1,
		rpOriginOutside = 2,
		fcv_forcedword = u32(-1)
	};
	// Ray-sphere intersection
	ICF ERP_Result intersect(const Tvector& S, const Tvector& D, TYPE range, s32& quantity, TYPE afT[2]) const
	{
		// set up quadratic Q(t) = a*t^2 + 2*b*t + c
		Tvector kDiff;
		kDiff.sub(S, P);
		TYPE fA = range * range;
		TYPE fB = kDiff.dotproduct(D) * range;
		TYPE fC = kDiff.square_magnitude( ) - R * R;
		ERP_Result result = rpNone;

		TYPE fDiscr = fB * fB - fA * fC;
		if (fDiscr < (T)0.0)
		{
			quantity = 0;
		}
		else if (fDiscr > (TYPE)0.0)
		{
			TYPE fRoot = _sqrt(fDiscr);
			TYPE fInvA = ((TYPE)1.0) / fA;
			afT[0] = range * (-fB - fRoot) * fInvA;
			afT[1] = range * (-fB + fRoot) * fInvA;
			if (afT[0] >= (TYPE)0.0)
			{
				quantity = 2;
				result = rpOriginOutside;
			}
			else if (afT[1] >= (TYPE)0.0)
			{
				quantity = 1;
				afT[0] = afT[1];
				result = rpOriginInside;
			}
			else
			{
				quantity = 0;
			}
		}
		else
		{
			afT[0] = range * (-fB / fA);
			if (afT[0] >= (TYPE)0.0)
			{
				quantity = 1;
				result = rpOriginOutside;
			}
			else
			{
				quantity = 0;
			}
		}

		return result;
	}

	ICF ERP_Result intersect_full(const Tvector& start, const Tvector& dir, TYPE& dist) const
	{
		s32 quantity;
		f32 afT[2];
		fSphere::ERP_Result result = intersect(start, dir, dist, quantity, afT);

		if (result == fSphere::rpOriginInside || ((result == fSphere::rpOriginOutside) && (afT[0] < dist)))
		{
			switch (result)
			{
				case fSphere::rpOriginInside:
				{
					dist = afT[0] < dist ? afT[0] : dist;
				}
				break;
				case fSphere::rpOriginOutside:
				{
					dist = afT[0];
				}
				break;
			}
		}

		return result;
	}

	ICF ERP_Result intersect(const Tvector& start, const Tvector& dir, TYPE& dist) const
	{
		s32 quantity;
		TYPE afT[2];
		ERP_Result result = intersect(start, dir, dist, quantity, afT);
		if (rpNone != result)
		{
			VERIFY(quantity > 0);
			if (afT[0] < dist)
			{
				dist = afT[0];
				return	result;
			}
		}

		return rpNone;
	}

	IC ERP_Result intersect2(const Tvector& S, const Tvector& D, TYPE& range) const
	{
		Tvector Q;
		Q.sub(P, S);

		TYPE R2 = R * R;
		TYPE c2 = Q.square_magnitude( );
		TYPE v = Q.dotproduct(D);
		TYPE d = R2 - (c2 - v * v);

		if (d > 0.0)
		{
			TYPE _range = v - _sqrt(d);
			if (_range < range)
			{
				range = _range;
				return (c2 < R2) ? rpOriginInside : rpOriginOutside;
			}
		}

		return rpNone;
	}
	ICF BOOL intersect(const Tvector& S, const Tvector& D) const
	{
		Tvector Q;
		Q.sub(P, S);

		TYPE c = Q.magnitude( );
		TYPE v = Q.dotproduct(D);
		TYPE d = R * R - (c * c - v * v);
		return (d > 0);
	}
	ICF BOOL intersect(SelfCRef S) const
	{
		TYPE SumR = R + S.R;
		return (P.distance_to_sqr(S.P) < SumR * SumR);
	}
	IC BOOL contains(const Tvector& PT) const
	{
		return (P.distance_to_sqr(PT) <= (R * R + EPS_S));
	}

	// returns true if this wholly contains the argument sphere
	IC BOOL contains(SelfCRef S) const
	{
		// can't contain a sphere that's bigger than me !
		const TYPE RDiff = R - S.R;
		if (RDiff < 0)
		{
			return false;
		}

		return (P.distance_to_sqr(S.P) <= RDiff * RDiff);
	}

	// return's volume of sphere
	IC TYPE volume( ) const
	{
		return TYPE(PI_MUL_4 / 3) * (R * R * R);
	}
};

using fSphere = _sphere<f32>;
//using dSphere = _sphere<f64>;

template <class T>
BOOL	_valid(const _sphere<T>& s)
{
	return (_valid(s.P) && _valid(s.R));
}

void	XRCORE_API		Fsphere_compute(fSphere& dest, const fVector3* verts, int count);
