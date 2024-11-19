/* -----------------------------------------------------------------------*/
//seabedprop.ccのように書きたい箇所（classのような振る舞いかつ,seabedpropownerに読み込まれるという形式も保持）
///追加した定義は軸方向、横方向の摩擦係数（静止最大+動摩擦）の４つ
/*  nu_d_axial
    nu_s_axial
    nu_d_lateral
    nu_s_lateral
*/


#include <cassert>
#include <cstdio>
#include <cmath>
#include <cfloat>
#include <iostream>
#include <iomanip>
#include <limits>

#include "mbconfig.h"
#include "coulombfriction.h"

coulombfriction::coulombfriction(void)
{
    NO_OP;
}

coulombfriction::~coulombfriction(void)
{
    NO_OP;
}

void
coulombfriction::setValue(
    doublereal& pnu_d_axial,
    doublereal& pnu_s_axial,
    doublereal& pnu_d_lateral,
    doublereal& pnu_s_lateral    
    ) const
{
    nu_d_axial      = pnu_d_axial;
    nu_s_axial      = pnu_s_axial;
    nu_d_lateral    = pnu_d_lateral;
    nu_s_lateral    = pnu_s_lateral;
}

void
coulombfriction::get(
    doublereal& pnu_d_axial,
    doublereal& pnu_s_axial,
    doublereal& pnu_d_lateral,
    doublereal& pnu_s_lateral    
    ) const
{
    pnu_d_axial      = nu_d_axial;
    pnu_s_axial      = nu_s_axial;
    pnu_d_lateral    = nu_d_lateral;
    pnu_s_lateral    = nu_s_lateral;
}


void
seabedpropowner::setCoulombfriction(
    doublereal& nu_d_axial,
    doublereal& nu_s_axial,
    doublereal& nu_d_lateral,
    doublereal& nu_s_lateral
    )
{
    pCoulombfriction.setValue(
    nu_d_axial,
    nu_s_axial,
    nu_d_lateral,
    nu_s_lateral
    );
}

void
seabedpropowner::get(
    doublereal& nu_d_axial,
    doublereal& nu_s_axial,
    doublereal& nu_d_lateral,
    doublereal& nu_s_lateral
    ) const
{
    pCoulombfriction.get(
    nu_d_axial,
    nu_s_axial,
    nu_d_lateral,
    nu_s_lateral
    );
}
