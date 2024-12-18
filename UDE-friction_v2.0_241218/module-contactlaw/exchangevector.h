
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

    //[0]
    ///A-1
    virtual doublereal inner(Vec3& a, Vec3& b) const;
    ///A-2

    ///B-1
    virtual Vec3 cross(Vec3& a, Vec3& b) const;
    ///B-2
    
    ///C
    virtual Vec3 op_vec(Vec3& a, Vec3& x) const;
    //[1]
    ///A
    virtual void normal_vec(Vec3& normal_vec) const;
    ///B
    virtual void internode_vec(Vec3& internode_unitvec, const Vec3& r1, const Vec3& r2) const;
    ///C
    virtual void lateral_vec(Vec3& lateral_unitvec, Vec3& normal_vec, Vec3& internode_unitvec, const Vec3& r1, const Vec3& r2) const;
    ///D
    virtual void axial_vec(Vec3& axial_unitvec, Vec3& normal_vec, Vec3& lateral_unitvec, const Vec3& r1, const Vec3& r2) const;
};

#endif // exchangevector_H