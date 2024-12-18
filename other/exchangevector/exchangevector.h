
#ifndef DIRECTIONVEC_H
#define DIRECTIONVEC_H

#include <mbconfig.h>
#include "dataman.h"

/* =================================================
 * class Exchange Vector
 * ================================================= */
class exchangevector
{
public:
    exchangevector(void);
    ~exchangevector(void);

    virtual void cross(Vec3& a, Vec3& b) const;
    virtual Vec3 unitVec_axial(Vec3& r1, Vec3& r2) const;
    virtual Vec3 unitVec_lateral(Vec3& z, Vec3& v_axial, Vec3& r1, Vec3& r2) const;
};

#endif // exchangevector_H
