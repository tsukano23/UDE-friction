#include "mbconfig.h"

#include <cassert>
#include <cstdio>
#include <cmath>
#include <cfloat>
#include <iostream>
#include <iomanip>
#include <limits>


#include "tanhfunc.h"

/* ------------------------------ tanhfunc start ---------------------------------------*/
tanhfunc::tanhfunc(void)
{
	NO_OP;
}

tanhfunc::~tanhfunc(void)
{
	NO_OP;
}

/*tanh()定義-----------------------------------*/
doublereal
tanhfunc::tanh(doublereal& x, doublereal& d_crit) const
{
    doublereal exp2x = std::exp(2 * x);
    doublereal func_tanh = (exp2x - 1) / (exp2x + 1); 
    if (x < -1.0*d_crit) {
        return -1.0;
    }
    else if (x > d_crit) {
        return 1.0;
    }
    else{
        return func_tanh;
    }
     
}

/* ------------------------------ tanhfunc end -----------------------------------------*/