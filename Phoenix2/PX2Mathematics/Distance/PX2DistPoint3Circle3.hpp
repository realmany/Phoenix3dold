/*
* Phoenix 3D 游戏引擎 Version 2.0
*
* Copyright (C) 2009-2011 http://www.Phoenix3d.org/
*
* 文件名称	：	PX2DistPoint3Circle3.hpp
*
* 版本		:	1.0 (2011/01/30)
*
* 作者		：	more
*
*/

#ifndef PX2DISTPOINT3CIRCLE3_HPP
#define PX2DISTPOINT3CIRCLE3_HPP

#include "PX2MathematicsPrerequisites.hpp"
#include "PX2Distance.hpp"
#include "PX2Vector3.hpp"
#include "PX2Circle3.hpp"

namespace PX2
{

	template <typename Real>
	class PX2_MATHEMATICS_ENTRY DistPoint3Circle3 
		: public Distance<Real,Vector3<Real> >
	{
	public:
		DistPoint3Circle3 (const Vector3<Real>& point,
			const Circle3<Real>& circle);

		// 对象访问
		const Vector3<Real>& GetPoint () const;
		const Circle3<Real>& GetCircle () const;

		// Static distance queries.  Compute the distance from the point P to the
		// circle.  When P is on the normal line C+t*N where C is the circle
		// center and N is the normal to the plane containing the circle, then
		// all circle points are equidistant from P.  In this case the returned
		// point is (infinity,infinity,infinity).
		virtual Real Get ();
		virtual Real GetSquared ();

		// Function calculations for dynamic distance queries.
		virtual Real Get (Real t, const Vector3<Real>& velocity0,
			const Vector3<Real>& velocity1);
		virtual Real GetSquared (Real t, const Vector3<Real>& velocity0,
			const Vector3<Real>& velocity1);

	private:
		using Distance<Real,Vector3<Real> >::mClosestPoint0;
		using Distance<Real,Vector3<Real> >::mClosestPoint1;

		const Vector3<Real>* mPoint;
		const Circle3<Real>* mCircle;
	};

	typedef DistPoint3Circle3<float> DistPoint3Circle3f;
	typedef DistPoint3Circle3<double> DistPoint3Circle3d;

}

#endif