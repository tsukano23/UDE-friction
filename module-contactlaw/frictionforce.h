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
    virtual Vec3 f_friction_axial(doublereal& F, Vec3& v_axial)const;
    virtual Vec3 f_friction_lateral(doublereal& F, Vec3& v_lateral)const;

};
#endif // FRICTIONAOFRCE_H