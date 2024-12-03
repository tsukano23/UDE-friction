
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

/*--外積計算--------------------------------------*/
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

/*--係留軸方向-----------------------------------*/
Vec3
exchangevector::unitVec_axial(const Vec3& r1, const Vec3& r2) const
{
	Vec3 axial 		= r2-r1;
	Vec3 unitaxial 	= axial/axial.Norm();
	return unitaxial;
}

/*--係留軸に対して垂直（横）方向-----------------------------------
+係留軸方向とz軸（簡易版では[0,0,1],詳細版では海底地形に対して垂直）を利用して求める
+グローバル座標を座標変換することによって求める
*/

Vec3
exchangevector::unitVec_lateral(const Vec3& r1, const Vec3& r2) const
{
	Vec3 z 				= Vec3(0.0, 0.0, 1.0);
	Vec3 v_axial		= unitVec_axial(Vec3& r1, Vec3& r2);
	Vec3 lateral 		= cross(z,v_axial);
	Vec3 unitlateral 	= lateral/lateral.Norm();
	return unitlateral;
}



/* ------------------------------- exchangevector end ----------------------------------------*/

