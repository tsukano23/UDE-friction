#include <cassert>
#include <cstdio>
#include <cmath>
#include <cfloat>
#include <iostream>
#include <iomanip>
#include <limits>

#include "mbconfig.h"
#include "seabedprop.h"

seabedprop::seabedprop(void)
{
    NO_OP;
}

seabedprop::~seabedprop(void)
{
    NO_OP;
}

void
seabedprop::setValue(
    doublereal& pg, doublereal& pz,
    doublereal& pnu1d, doublereal& pnu1s, doublereal& pnu2d, doublereal& pnu2s)
{
    g = pg;
    z_seabed = pz;
    nu1d = pnu1d; 
    nu1s = pnu1s;
    nu2d = pnu2d;
    nu2s = pnu2s;

}

void
seabedprop::get(
    doublereal& pg, doublereal& pz,
    doublereal& pnu1d, doublereal& pnu1s, doublereal& pnu2d, doublereal& pnu2s
    ) const
{
    pg = g;
    pz = z_seabed;
    pnu1d = nu1d; 
    pnu1s = nu1s;
    pnu2d = nu2d;
    pnu2s = nu2s;

}

seabedpropowner::seabedpropowner(void)
{
    NO_OP;
}

seabedpropowner::~seabedpropowner(void)
{
    NO_OP;   
}

void
seabedpropowner::setSeabedprop(
    doublereal& g, doublereal& z,
    doublereal& nu1d, doublereal& nu1s, doublereal& nu2d, doublereal& nu2s
)
{
    pSeabedprop.setValue(
        g, z,
        nu1d, nu1s, nu2d, nu2s
        );
}

void
seabedpropowner::get(
    doublereal& g, doublereal& z,
    doublereal& nu1d, doublereal& nu1s, doublereal& nu2d, doublereal& nu2s
    ) const
{
    pSeabedprop.get(
        g, z,
        nu1d, nu1s, nu2d, nu2s
    );
}

