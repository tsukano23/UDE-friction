
#ifndef TANHFUNC_H
#define TANHFUNC_H

#include <mbconfig.h>
#include "dataman.h"

/* =================================================
 * class Calc Tanh(x)
 * ================================================= */
class tanhfunc
{
public:
    tanhfunc(void);
    ~tanhfunc(void);

    virtual doublereal tanh(doublereal& x, doublereal& d_crit) const;

};

#endif // tanhfunc_H