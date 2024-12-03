#include "dataman.h"

#ifndef FRICTIONAOFRCE_H
#define FRICTIONAOFRCE_H

class frictionforce
{
private:
public:
    frictionforce(void);
    virtual ~frictionforce(void);

    //calcurate friction force vector
    virtual void f_friction_axial(Vec3& friction_axial, const doublereal& F, const Vec3& v_axial)const;
    virtual void f_friction_lateral(Vec3 friction_lateral, const doublereal& F, const Vec3& v_lateral)const;

};
#endif // FRICTIONAOFRCE_H