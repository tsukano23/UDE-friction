/* -----------------------------------------------------------------------
 * MBDyn (C) is a multibody analysis code.
 * http://www.mbdyn.org
 *
 * Copyright (C) 1996-2017
 *
 * Pierangelo Masarati  <masarati@aero.polimi.it>
 *
 * Dipartimento di Ingegneria Aerospaziale - Politecnico di Milano
 * via La Masa, 34 - 20156 Milano, Italy
 * http://www.aero.polimi.it
 *
 * Changing this copyright notice is forbidden.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation (version 2 of the License).
 * 
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 * -----------------------------------------------------------------------*/

/* -----------------------------------------------------------------------
 * Module - Sea
 *
 * Implemented by
 * Ryoya Hisamatsu <hisamatsu@nams.kyushu-u.ac.jp>
 * Department of Marine Systems Engineering, Kyushu University
 * Motooka 744, Nishi-ku, Fukuoka 819-0395, Fukuoka, Japan 
 * -----------------------------------------------------------------------*/


#include <cassert>
#include <cstdio>
#include <cmath>
#include <cfloat>
#include <iostream>
#include <iomanip>
#include <limits>

#include "mbconfig.h"
#include "seabedprop.h"
#include "coulombfriction.h"

/*seabedprop-----------------------------------------------*/
seabedprop::seabedprop(void)
{
    NO_OP;
}

seabedprop::~seabedprop(void)
{
    NO_OP;
}

void
seabedprop::setValue(doublereal& pg, doublereal& pz)
{
    g = pg;
    z_seabed = pz;
}

void
seabedprop::get(doublereal& pg, doublereal& pz) const
{
    pg = g;
    pz = z_seabed;
}

/*coulombfriction------------------------------------------*/

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



/*seabedpropowner------------------------------------------*/
seabedpropowner::seabedpropowner(void)
{
    NO_OP;
}

seabedpropowner::~seabedpropowner(void)
{
    NO_OP;   
}

//incooporate-seabedprop
void
seabedpropowner::setSeabedprop(doublereal& g, doublereal& z)
{
    pSeabedprop.setValue(g, z);
}

void
seabedpropowner::get(doublereal& g, doublereal& z) const
{
    pSeabedprop.get(g, z);
}

//incooporate-coulombfriction
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
