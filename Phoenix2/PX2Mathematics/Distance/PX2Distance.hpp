/*
* Phoenix 3D 游戏引擎 Version 2.0
*
* Copyright (C) 2009-2011 http://www.Phoenix3d.org/
*
* 文件名称	：	PX2Distance.hpp
*
* 版本		:	1.0 (2011/01/30)
*
* 作者		：	more
*
*/

#ifndef PX2DISTANCE_HPP
#define PX2DISTANCE_HPP

#include "PX2MathematicsPrerequisites.hpp"
#include "PX2Vector2.hpp"
#include "PX2Vector3.hpp"

namespace PX2
{

	/// 距离模板抽象基类
	template <typename Real, typename TVector>
	class PX2_MATHEMATICS_ENTRY Distance
	{
	public:
		// Abstract base class.
		virtual ~Distance ();

		// Static distance queries.
		virtual Real Get () = 0;     // distance
		virtual Real GetSquared () = 0;  // squared distance

		// Function calculations for dynamic distance queries.
		virtual Real Get (Real t, const TVector& velocity0,
			const TVector& velocity1) = 0;
		virtual Real GetSquared (Real fT, const TVector& velocity0,
			const TVector& velocity1) = 0;

		// Derivative calculations for dynamic distance queries.  The defaults
		// use finite difference estimates
		//   f'(t) = (f(t+h)-f(t-h))/(2*h)
		// where h = DifferenceStep.  A derived class may override these and
		// provide implementations of exact formulas that do not require h.
		virtual Real GetDerivative (Real t, const TVector& velocity0,
			const TVector& velocity1);
		virtual Real GetDerivativeSquared (Real t, const TVector& velocity0,
			const TVector& velocity1);

		// Dynamic distance queries.  The function computes the smallest distance
		// between the two objects over the time interval [tmin,tmax].
		virtual Real Get (Real tmin, Real tmax, const TVector& velocity0,
			const TVector& relocity1);
		virtual Real GetSquared (Real fTMin, Real fTMax,
			const TVector& velocity0, const TVector& velocity1);

		// For Newton's method and inverse parabolic interpolation.
		int MaximumIterations;  // default = 8
		Real ZeroThreshold;     // default = Math<Real>::ZERO_TOLERANCE

		// For derivative approximations.
		void SetDifferenceStep (Real differenceStep);  // default = 1e-03
		Real GetDifferenceStep () const;

		// The time at which minimum distance occurs for the dynamic queries.
		Real GetContactTime () const;

		// Closest points on the two objects.  These are valid for static or
		// dynamic queries.  The set of closest points on a single object need
		// not be a single point.  In this case, the Boolean member functions
		// return 'true'.  A derived class may support querying for the full
		// contact set.
		const TVector& GetClosestPoint0 () const;
		const TVector& GetClosestPoint1 () const;
		bool HasMultipleClosestPoints0 () const;
		bool HasMultipleClosestPoints1 () const;

	protected:
		Distance ();

		Real mContactTime;
		TVector mClosestPoint0;
		TVector mClosestPoint1;
		bool mHasMultipleClosestPoints0;
		bool mHasMultipleClosestPoints1;
		Real mDifferenceStep, mInvTwoDifferenceStep;
	};

	typedef Distance<float,Vector2f> Distance2f;
	typedef Distance<float,Vector3f> Distance3f;
	typedef Distance<double,Vector2d> Distance2d;
	typedef Distance<double,Vector3d> Distance3d;

}

#endif