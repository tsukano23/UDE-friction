#include <cassert>
#include <cstdio>
#include <cmath>
#include <cfloat>
#include <iostream>
#include <iomanip>
#include <limits>

#include "mbconfig.h"
#include "frictionforce.h"

/* ------------------------------ frictionforce start ---------------------------------------*/

frictionforce::frictionforce(void)
{
    NO_OP;
}

frictionforce::~frictionforce(void)
{
    NO_OP;
}

/*--係留軸方向の摩擦力-----------------------------------*/
void
frictionforce::f_friction_axial(Vec3& friction_axial, const doublereal& F, const Vec3& v_axial)const
{
	doublereal v_axial_x 	= v_axial.dGet(1);
	doublereal v_axial_y 	= v_axial.dGet(2);
	doublereal v_axial_z 	= v_axial.dGet(3);

	
	friction_axial = Vec3(
			F*v_axial_x,
			F*v_axial_y,
			F*v_axial_z
			);
}

/*--係留軸横方向の摩擦力-----------------------------------*/
void
frictionforce::f_friction_lateral(Vec3 friction_lateral, const doublereal& F, const Vec3& v_lateral)const
{
	doublereal v_lateral_x 	= v_lateral.dGet(1);
	doublereal v_lateral_y 	= v_lateral.dGet(2);
	doublereal v_lateral_z 	= v_lateral.dGet(3);

	
	friction_lateral = Vec3(
		F*v_lateral_x,
		F*v_lateral_y,
		F*v_lateral_z
		);
}

/* ------------------------------- frictionforce end ----------------------------------------*/
