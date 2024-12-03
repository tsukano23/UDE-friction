
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

    ////calculate lateral vector
    virtual Vec3 cross(Vec3& a, Vec3& b) const;
    virtual void unitVec_axial(Vec3& unitaxial, const Vec3& r1, const Vec3& r2) const;
    virtual void unitVec_lateral(Vec3& unitlateral, const Vec3& r1, const Vec3& r2) const;
};

#endif // exchangevector_H