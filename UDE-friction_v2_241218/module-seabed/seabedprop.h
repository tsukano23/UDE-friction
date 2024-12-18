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

#include <mbconfig.h>
#include "dataman.h"

#ifndef SEABEDPROP_H
#define SEABEDPROP_H

class seabedprop
{
private:
    doublereal g;
    doublereal z_seabed;
    doublereal nu1d;
    doublereal nu1s;
    doublereal nu2d;
    doublereal nu2s;
    doublereal vt;
public:
    seabedprop(void);
    virtual ~seabedprop(void);

    virtual void setValue(
        doublereal& pg, doublereal& pz,
        doublereal& pnu1d, doublereal& pnu1s, doublereal& pnu2d, doublereal& pnu2s,
        doublereal& pvt
        );
    virtual void get(
        doublereal& pg, doublereal& pz,
        doublereal& pnu1d, doublereal& pnu1s, doublereal& pnu2d, doublereal& pnu2s,
        doublereal& pvt
        ) const;
};

#endif // SEABEDPROP_H

#ifndef SEABEDPROPOWBER_H
#define SEABEDPROPOWBER_H

class seabedpropowner
{
protected:
    seabedprop pSeabedprop; 
public:
    seabedpropowner(void);
    virtual ~seabedpropowner(void);

    virtual void setSeabedprop(
        doublereal& g, doublereal& z,
        doublereal& nu1d, doublereal& nu1s, doublereal& nu2d, doublereal& nu2s,
        doublereal& vt
        );
    virtual void get(
        doublereal& g, doublereal& z,
        doublereal& nu1d, doublereal& nu1s, doublereal& nu2d, doublereal& nu2s,
        doublereal& vt
        )const;
};

#endif // SEABEDPROPOWBER_H