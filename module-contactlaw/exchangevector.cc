
#include "mbconfig.h"

#include <cassert>
#include <cstdio>
#include <cmath>
#include <cfloat>
#include <iostream>
#include <iomanip>
#include <limits>


#include "exchangevector.h"



/* ------------------------------ exchangevector start ---------------------------------------*/
exchangevector::exchangevector(void)
{
	NO_OP;
}

exchangevector::~exchangevector(void)
{
	NO_OP;
}

/*--[0A-1]inner_calc(内積計算)-----------------------------------------------------*/
Vec3
exchangevector::inner(Vec3& a, Vec3& b) const
{
    doublereal ax 	= a.dGet(1);
	doublereal ay 	= a.dGet(2);
	doublereal az 	= a.dGet(3);

    doublereal bx 	= b.dGet(1);
	doublereal by 	= b.dGet(2);
	doublereal bz 	= b.dGet(3);

	Vec3 r_inner 	= Vec3(
					ax * bx,
					ay * by,
					az * bz
					);

	return r_inner;
}

/*--[0A-2]inner_yacb_calc(内積ヤコビ行列計算)--------------------------------------*/



/*--[0B-2]cross_calc(外積計算)----------------------------------------------------*/
Vec3
exchangevector::cross(Vec3& a, Vec3& b) const
{
    doublereal ax 	= a.dGet(1);
	doublereal ay 	= a.dGet(2);
	doublereal az 	= a.dGet(3);

    doublereal bx 	= b.dGet(1);
	doublereal by 	= b.dGet(2);
	doublereal bz 	= b.dGet(3);

	Vec3 r_cross 	= Vec3(
					ay * bz - az * by,
					az * bx - ax * bz,
					ax * by - ay * bx
					);

	return r_cross;
}

/*--[0B]cross_yacb_calc(外積ヤコビ行列計算)---------------------------------------*/


/*--[0B-2]orthographic_projection_vec_calc(正射影ベクトル計算)--------------------*/
Vec3
exchangevector::op_vec(Vec& a, Vec& x) const
{
	Vec3 	op_vec	= (inner(a, x)/(x.norm()*x.norm()))*x;
	return 	op_vec;
}
/*--[1A]normal_vec_calc(海底面に対する法線ベクトル計算)----------------------------*/
void 
exchangevector::normal_vec(Vec& normal_vec) const
{
	normal_vec = Vec3(0., 0., 1.);
}

/*--[1B]internode_vec_calc(節点間方向ベクトル計算)--------------------------------*/
void
exchangevector::internode_vec(Vec3& internode_unitvec, const Vec3& r1, const Vec3& r2) const
{
	Vec3 internode_vec 	= r2-r1;
	internode_unitvec 	= internode_vec/internode_vec.Norm();
}

/*--[1C]lateral_vec_calc(係留横方向ベクトル計算)----------------------------------*/
void
exchangevector::lateral_vec(Vec3& lateral_unitvec, Vec& normal_vec, Vec3& internode_unitvec, const Vec3& r1, const Vec3& r2) const
{
	Vec3 lateral_vec 	= cross(normal_vec, internode_unitvec);
	lateral_unitvec 	= lateral_vec/lateral_vec.Norm();
}

/*--[1D]axial_vec_calc(係留軸方向ベクトル計算)------------------------------------*/
void
exchangevector::axial_vec(Vec3& axial_unitvec, Vec& normal_vec, Vec3& lateral_unitvec, const Vec3& r1, const Vec3& r2) const
{
	Vec3 axial_vec 		= cross(normal_vec, lateral_unitvec);
	axial_unitvec 		= axial_vec/axial_vec.Norm();
}

/* ------------------------------- exchangevector end ----------------------------------------*/