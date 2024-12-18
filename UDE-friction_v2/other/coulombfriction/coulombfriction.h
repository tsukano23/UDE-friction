/*
seabedprop.hの class seabedpropownerのところに以下を追記必要

class seabedpropowner
{
protected:
    coulombfriction pcoulombfriction; 

*/

#include "dataman.h"

#ifndef COULOMBFRICTION_H
#define COULOMBFRICTION_H

class coulombfriction
{
private:
    doublereal nu_d_axial;
    doublereal nu_s_axial;
    doublereal nu_d_lateral;
    doublereal nu_s_lateral;
public:
    coulombfriction(void);
    virtual ~coulombfriction(void);
        
    virtual void setValue(
    doublereal& pnu_d_axial,
    doublereal& pnu_s_axial,
    doublereal& pnu_d_lateral,
    doublereal& pnu_s_lateral    
    );
    virtual void get(
    doublereal& pnu_d_axial,
    doublereal& pnu_s_axial,
    doublereal& pnu_d_lateral,
    doublereal& pnu_s_lateral 
    ) const;
};
#endif // COULOMBFRICTION_H