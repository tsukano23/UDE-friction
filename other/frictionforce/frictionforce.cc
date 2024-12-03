#include <cassert>
#include <cstdio>
#include <cmath>
#include <cfloat>
#include <iostream>
#include <iomanip>
#include <limits>

#include "mbconfig.h"

frictionforce::frictionforce(void)
{
    NO_OP;
}

frictionforce::~frictionforce(void)
{
    NO_OP;
}


//以下をcontactlawに追記して動作確認
//set matrix dimension
void
Contactlaw::WorkSpaceDim(integer* piNumRows, integer* piNumCols) const
{
	*piNumRows = 6;
	*piNumCols = 6;
    //3自由度が2節点
	//std ::cout << "14" << std::endl;
}

/*assresの中に書きたい条件分岐-----------------*/
SubVectorHandler& 
Contactlaw::AssRes(
	SubVectorHandler& WorkVec,
	doublereal dCoef,
	const VectorHandler& XCurr, 
	const VectorHandler& XPrimeCurr)
{
	//obtain vector dimension
	integer iNumRows;
	integer iNumCols;
	WorkSpaceDim(&iNumRows, &iNumCols);
	WorkVec.ResizeReset(iNumRows);

	//set index from global state vector
	const integer iPositionIndex = pNode->iGetFirstPositionIndex();
	const integer iMomentumIndex = pNode->iGetFirstMomentumIndex();
	WorkVec.PutRowIndex(1, iMomentumIndex+3);

	/*calculate refrecionforces------------------------------------*/
	doublereal g,Zs;
	pSeabed->get(g, Zs);
    pSeabed->get(
        nu_d_axial,
        nu_s_axial,
        nu_d_lateral,
        nu_s_lateral
    );
	doublereal c1;
	doublereal F;
    doublereal F_friction_axial;
    doublereal F_friction_lateral;
    doublereal nu_axial; 
    doublereal nu_lateral;  
    

	doublereal z    = XCurr(iPositionIndex+3) - Zs;
    doublereal vx   = XPrimeCurr(iPositionIndex+1);
    doublereal vy   = XPrimeCurr(iPositionIndex+2);
	doublereal vz   = XPrimeCurr(iPositionIndex+3);
	doublereal delta = std::abs(z);
	if (z>0.0) {
		c1 = 0.0;
		std::cout << "Res00" << std::endl;
/*ここからが摩擦力計算の該当箇所*/
	} else {
		c1 = 1.0;
        if(vx == 0.0 && vy == 0.0){
            nu_axial    = nu_s_axial; 
            nu_lateral  = nu_s_lateral;
        std::cout << "Res01" << std::endl;    
        }
        else if (vx == 0.0 && vy != 0.0){
            nu_axial    = nu_s_axial;
            nu_lateral  = nu_d_lateral;
        std::cout << "Res02" << std::endl;         
        }
        else if (vx != 0.0 && vy == 0.0){
            nu_axial    = nu_d_axial; 
            nu_lateral  = nu_s_lateral;
        std::cout << "Res03" << std::endl;           
        }
        else (vx != 0.0 && vy != 0.0){
            nu_axial    = nu_d_axial;
            nu_lateral  = nu_d_lateral;
        std::cout << "Res04" << std::endl;           
        }
		
	}
	
	F                   = (k*delta -c*vz)*c1;
    F_friction_axial    = nu_axial*F 
    F_friction_lateral  = nu_lateral*F 

	//set value=============修正必要
	WorkVec.PutCoef(1, F);
	return WorkVec;
	std ::cout << "15" << std::endl;
}

/*assjacの中に書きたい条件分岐-----------------*/
//calculate Jacobian matrix
VariableSubMatrixHandler& 
Contactlaw::AssJac(
	VariableSubMatrixHandler& WorkMat,
	doublereal dCoef, 
	const VectorHandler& XCurr,
	const VectorHandler& XPrimeCurr)
{
	FullSubMatrixHandler& WM = WorkMat.SetFull();

	//obtain vector dimension
	integer iNumRows;
	integer iNumCols;
	WorkSpaceDim(&iNumRows, &iNumCols);
	WM.ResizeReset(iNumRows, iNumCols);

	//set index from global matrix
  	const integer iPositionIndex = pNode->iGetFirstPositionIndex();
	const integer iMomentumIndex = pNode->iGetFirstMomentumIndex();
	WM.PutRowIndex(1, iMomentumIndex+3);
	WM.PutColIndex(1, iPositionIndex+3);

	//calculate forces
	doublereal g,Zs;
	pSeabed->get(g,Zs);
	doublereal A;
	doublereal dc1_dx;
	doublereal dF_dx;

	doublereal z = XCurr(iPositionIndex+3) - Zs;
	doublereal v = XPrimeCurr(iPositionIndex+3);
	if (z>0.0) {
		dc1_dx = 0.0;
		std::cout << "Jac00" << std::endl;
	} else {
		dc1_dx = 1.0;
		std::cout << "Jac01" << std::endl;
	}

	A = (-c - dCoef*k)*dc1_dx;
	

	// set value
    //個々の部分のみ修正必要（WorkMatの大きさのみ変更）
	WM.PutCoef( 1,  1, A );
	return WorkMat;
	std ::cout << "16" << std::endl;
}