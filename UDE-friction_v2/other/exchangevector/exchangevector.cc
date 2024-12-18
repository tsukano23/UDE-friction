
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

/*--外積計算_v1-----------------------------------*/
void
exchangevector::cross(Vec3& a, Vec3& b) const
{
	return {
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x
    };
}

/*--係留軸方向-----------------------------------*/
Vec3
exchangevector::unitVec_axial(Vec3& r1, Vec3& r2) const
{
	Vec3 axial = r2-r1;
	Vec3 unitaxial = axial/axial.Norm();
	return  unitaxial;
}

/*--係留軸に対して垂直（横）方向-----------------------------------
+係留軸方向とz軸（簡易版では[0,0,1],詳細版では海底地形に対して垂直）を利用して求める
+グローバル座標を座標変換することによって求める
*/
Vec3
exchangevector::unitVec_lateral(Vec3& z, Vec3& v_axial, Vec3& r1, Vec3& r2) const
{
	Vec3 z 				= {0.0, 0.0, 1.0};
	Vec3 v_axial		= unitVec_axial(Vec3& r1, Vec3& r2);
	Vec3 lateral 		= cross(z,v_axial);
	Vec3 unitlateral 	= lateral/lateral.Norm();
	return unitlateral;
	/*--外積計算_v2-----------------------------------*/
	//Mat3x3 v1_tild()
}

/* ------------------------------- exchangevector end ----------------------------------------*/

