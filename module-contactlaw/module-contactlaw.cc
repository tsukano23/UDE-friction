/* -----------------------------------------------------------------------
* MBDyn (C) is a multibody analysis code.
* http://www.mbdyn.org
*
* Copyright (C) 1996-2017
*
* Pierangelo Masarati  <masarati@aero.polimi.it>
*
* Dipartimento di Ingegneria Aerospaziale - Politecnico di Milano
* via La Masa, 34 - 20156 Milano, Italy
* http://www.aero.polimi.it
*
* Changing this copyright notice is forbidden.
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation (version 2 of the License).
* 
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
* -----------------------------------------------------------------------*/

/* -----------------------------------------------------------------------
* Module - contactlaw
*
* Implemented by
* Ryoya Hisamatsu <hisamatsu@nams.kyushu-u.ac.jp>
* Department of Marine Systems Engineering, Kyushu University
* Motooka 744, Nishi-ku, Fukuoka 819-0395, Fukuoka, Japan 
* -----------------------------------------------------------------------*/

#include "mbconfig.h"

#include <cassert>
#include <cstdio>
#include <cmath>
#include <cfloat>
#include <iostream>
#include <iomanip>
#include <limits>

#include "module-contactlaw.h"
#include "exchangevector.h"
<<<<<<< HEAD
#include "tanhfunc.h"
=======
#include "frictionforce.h"
>>>>>>> 443587a971f615aab80508aa00292e2642dd7ecd


/* ----------------------------- contactlaw start --------------------------------------*/

/*=======================================================================================
* Constructor and Destructor
*=======================================================================================*/
//constructor
Contactlaw::Contactlaw (
	unsigned uLabel,
	const DofOwner *pDO,
	DataManager* pDM,
	MBDynParser& HP
)
: Elem(uLabel, flag(0)), UserDefinedElem(uLabel, pDO)
{
	// help message or no arg error
	if (HP.IsKeyWord("help")) {
		silent_cout(
			"help message\n"
			"==== Module: Contactlaw ====\n"
			"- Note: \n"
			"\ttest\n"
			"- Usage: \n"
			"\tContactlaw,\n"
			"\t<node_label_1>,\n"
			"\t<node_label_2>;\n"
			<< std::endl);
		if (!HP.IsArg()) {
			throw NoErr(MBDYN_EXCEPT_ARGS);
		}
	}

	std:: cout << "1" << std::endl;

	// read node1
	pNode1 = dynamic_cast<const StructNode *>(pDM->ReadNode(HP, Node::STRUCTURAL));

<<<<<<< HEAD
	/*
	// read node2
	pNode2 = dynamic_cast<const StructNode *>(pDM->ReadNode(HP, Node::STRUCTURAL));
	*/
=======
	// read node2
	pNode2 = dynamic_cast<const StructNode *>(pDM->ReadNode(HP, Node::STRUCTURAL));
>>>>>>> 443587a971f615aab80508aa00292e2642dd7ecd

	// read seabed object
	unsigned int uElemLabel = (unsigned int)HP.GetInt();
	pSeabed = dynamic_cast<Seabed *>(pDM->pFindElem(Elem::LOADABLE, uElemLabel));

	std:: cout << "2" << std::endl;

	
	// read k
	if (!HP.IsKeyWord("k")) {
	silent_cerr("Contactlaw(" << GetLabel() << "): keyword \"k\" expected at line " << HP.GetLineData() << std::endl);
	throw ErrGeneric(MBDYN_EXCEPT_ARGS);
	}
	k = HP.GetReal();

	// read c
	if (!HP.IsKeyWord("c")) {
	silent_cerr("Contactlaw(" << GetLabel() << "): keyword \"c\" expected at line " << HP.GetLineData() << std::endl);
	throw ErrGeneric(MBDYN_EXCEPT_ARGS);
	}
	c = HP.GetReal();

	std ::cout << "3" << std::endl;

	//output flag
	SetOutputFlag(pDM->fReadOutput(HP, Elem::LOADABLE));
	//export log file
	pDM->GetLogFile()
		<< "Contactlaw: " << uLabel
		<< " " << pNode1->GetLabel()
<<<<<<< HEAD
		/*
		<< " " << pNode2->GetLabel()
		*/
=======
		<< " " << pNode2->GetLabel()
>>>>>>> 443587a971f615aab80508aa00292e2642dd7ecd
		<< " " << pSeabed->GetLabel()
		<< std::endl;

	std ::cout << "4" << std::endl;		
}



//destructor
Contactlaw::~Contactlaw (void)
{
	NO_OP;
	std ::cout << "5" << std::endl;
}



/*=======================================================================================
* Intial Assembly Process
*=======================================================================================*/
//set number of DOF
unsigned int
Contactlaw::iGetInitialNumDof(void) const
{
	return 0;
	std ::cout << "6" << std::endl;
}

//set initial value
void
Contactlaw::SetInitialValue(VectorHandler& XCurr)
{
	return;
	std ::cout << "7" << std::endl;
}

//set initial assembly matrix dimension
void 
Contactlaw::InitialWorkSpaceDim(integer* piNumRows, integer* piNumCols) const
{
	*piNumRows = 0;
	*piNumCols = 0;
	std ::cout << "8" << std::endl;
}

//calculate residual vector for initial assembly analysis
SubVectorHandler& 
Contactlaw::InitialAssRes(
	SubVectorHandler& WorkVec,
	const VectorHandler& XCurr)
{
	WorkVec.ResizeReset(0);
	return WorkVec;
	std ::cout << "9" << std::endl;
}

//calculate Jaconbian for initial assembly analysis
VariableSubMatrixHandler&
Contactlaw::InitialAssJac(
	VariableSubMatrixHandler& WorkMat, 
	const VectorHandler& XCurr)
{
	WorkMat.SetNullMatrix();
	return WorkMat;
	std ::cout << "10" << std::endl;
}

/*=======================================================================================
* Initial Value Problem
*=======================================================================================*/
//set number of DOF
unsigned int
Contactlaw::iGetNumDof(void) const
{
	return 0;
	std ::cout << "11" << std::endl;
}

//set DOF type
DofOrder::Order
Contactlaw::GetDofType(unsigned int i) const
{
	return DofOrder::DIFFERENTIAL;
	std ::cout << "12" << std::endl;
}

//set initial value
void
Contactlaw::SetValue(
	DataManager *pDM,
	VectorHandler& X,
	VectorHandler& XP,
	SimulationEntity::Hints *ph)
{
	return;
	std ::cout << "13" << std::endl;
}

//print explanation of variables and equations
std::ostream&
Contactlaw::DescribeDof(std::ostream& out, const char *prefix, bool bInitial) const
{
}
std::ostream&
Contactlaw::DescribeEq(std::ostream& out, const char *prefix, bool bInitial) const
{
}


//set matrix dimension
void
Contactlaw::WorkSpaceDim(integer* piNumRows, integer* piNumCols) const
{
<<<<<<< HEAD
	*piNumRows = 3;
	*piNumCols = 3;	
=======
	*piNumRows = 6;
	*piNumCols = 6;	
>>>>>>> 443587a971f615aab80508aa00292e2642dd7ecd
	//std ::cout << "14" << std::endl;
}


//calculate residual vector
SubVectorHandler& 
Contactlaw::AssRes(
	SubVectorHandler& WorkVec,
	doublereal dCoef,
	const VectorHandler& XCurr, 
	const VectorHandler& XPrimeCurr)
{
	//node1 current data
	const integer iPositionIndex1 = pNode1->iGetFirstPositionIndex();
	const integer iMomentumIndex1 = pNode1->iGetFirstMomentumIndex();
<<<<<<< HEAD

	/*
	//node2 current data
	const integer iPositionIndex2 = pNode2->iGetFirstPositionIndex();
	const integer iMomentumIndex2 = pNode2->iGetFirstMomentumIndex();
	*/

=======
	
	//node2 current data
	const integer iPositionIndex2 = pNode2->iGetFirstPositionIndex();
	const integer iMomentumIndex2 = pNode2->iGetFirstMomentumIndex();

	const Vec3 r1 = Vec3(
		XCurr(iPositionIndex1+1),
		XCurr(iPositionIndex1+2),
		XCurr(iPositionIndex1+3)
	);
	const Vec3 v1 = Vec3(
		XPrimeCurr(iPositionIndex1+1),
		XPrimeCurr(iPositionIndex1+2),
		XPrimeCurr(iPositionIndex1+3)
	);
	const Vec3 r2 = Vec3(
		XCurr(iPositionIndex2+1),
		XCurr(iPositionIndex2+2),
		XCurr(iPositionIndex2+3)
	);
	const Vec3 v2 = Vec3(
		XPrimeCurr(iPositionIndex2+1),
		XPrimeCurr(iPositionIndex2+2),
		XPrimeCurr(iPositionIndex2+3)
	);
	
>>>>>>> 443587a971f615aab80508aa00292e2642dd7ecd
	//configuring workvec
	integer iNumRows;
	integer iNumCols;
	WorkSpaceDim(&iNumRows, &iNumCols);
	WorkVec.ResizeReset(iNumRows);
	for(int iCnt = 1; iCnt <=3; iCnt++){
		WorkVec.PutRowIndex(iCnt, iMomentumIndex1+iCnt);
	}
<<<<<<< HEAD
	/*
	for(int iCnt = 1; iCnt <=3; iCnt++){
		WorkVec.PutRowIndex(iCnt+3, iMomentumIndex2+iCnt);
	}
	*/

	/*nodedata_config-----------------------------------------------*/
	const Vec3 r1 = Vec3(
			XCurr(iPositionIndex1+1),
			XCurr(iPositionIndex1+2),
			XCurr(iPositionIndex1+3)
		);
		const Vec3 v1 = Vec3(
			XPrimeCurr(iPositionIndex1+1),
			XPrimeCurr(iPositionIndex1+2),
			XPrimeCurr(iPositionIndex1+3)
		);
	/*calculate refrecionforces------------------------------------*/
	//seabedの定数定義
	doublereal g,Zs, nu1d, nu1s, nu2d, nu2s;
	pSeabed->get(g, Zs, nu1d, nu1s, nu2d, nu2s);
	doublereal c1;

	//摩擦力計算時のFと摩擦係数定義
	doublereal F;
	doublereal nu;  

	Vec3 normal_vec 			= Vec3(0.0,0.0,0.0);
	Vec3 internode_unitvec 		= Vec3(0.0,0.0,0.0);
	Vec3 axial_unitvec 			= Vec3(0.0,0.0,0.0);
	Vec3 lateral_unitvec 		= Vec3(0.0,0.0,0.0);

	doublereal z    	= r1.dGet(3) - Zs;
	doublereal vz   	= v1.dGet(3);
	doublereal delta 	= std::abs(z);


	/*反力計算-----------------------------------------------------------*/
	if (z>0.0) {
		c1 = 0.0;
		std::cout << "Res00" << std::endl;
	} else {
		c1 = 1.0;
		//tanh(x)を使って静摩擦から動摩擦の移行を表現
	}

	//弾性床からの反力計算
	F           = (k*delta -c*vz)*c1;

	/*摩擦力計算----------------------------------------------------------*/
	//摩擦係数
	nu = nu1d;
	//ベクトル
	////法線ベクトル
	normal_vec = pexv.normal_vec(normal_vec);
	////internode(一つの質点では考えなくてよい)
	////lateralnode(一つの質点では考えなくてよい)
	////axialnode(一つの質点の場合、質点の速度方向でよい)
	Vec3 axial_vec 		= v1;
	Vec3 friction_vec 	= -v1;

	//step関数で摩擦力の推移表現
	doubleral vt 		= 5.e-3; 
	doublereal dcrit    = v1.norm()/Vt;
	Vec3 f_friction 	= ptanhfunc.tanh(dcrit,2.5)*nu*F*(friction_vec/v1.rorm());


	//WorkVecに代入
	WorkVec.Put(1, f_friction);
	//WorkVec.Put(2, F_y);
	//WorkVec.Put(3, F_z);

=======
	for(int iCnt = 1; iCnt <=3; iCnt++){
		WorkVec.PutRowIndex(iCnt+3, iMomentumIndex2+iCnt);
	}

	/*calculate refrecionforces_node1------------------------------------*/

	doublereal g,Zs, nu1d, nu1s, nu2d, nu2s;
	pSeabed->get(g, Zs, nu1d, nu1s, nu2d, nu2s);
	doublereal b1;
	doublereal c1;

	doublereal d1;
	doublereal d2;
	doublereal e1;
	doublereal e2;
	Vec3 z_global 				= Vec3(0.0, 0.0, 1.0);
	
    doublereal nu_axial; 
    doublereal nu_lateral;  
	
	doublereal F_friction_axial_abs;
	doublereal F_friction_lateral_abs;
	Vec3 unit_axial 			= Vec3(0.0,0.0,0.0);
    Vec3 unit_lateral 			= Vec3(0.0,0.0,0.0);
	Vec3 F_friction_axial 		= Vec3(0.0,0.0,0.0);
    Vec3 F_friction_lateral 	= Vec3(0.0,0.0,0.0);

	//node1
    doublereal vx_1   = v1.dGet(1);
    doublereal vy_1   = v1.dGet(2);
	doublereal vz_1   = v1.dGet(3);
	doublereal z_1    = r1.dGet(3) - Zs;
	doublereal delta_1 = std::abs(z_1);
	//node2
	doublereal vx_2   = v2.dGet(1);
    doublereal vy_2   = v2.dGet(2);
	doublereal vz_2   = v2.dGet(3);
	doublereal z_2    = r2.dGet(3) - Zs;
	doublereal delta_2 = std::abs(z_2);


	if (z_1>0.0) {
		b1 = 0.0;
		std::cout << "Res00" << std::endl;
	} else {
		b1 = 1.0;
		std::cout << "Res01" << std::endl;
	}
	
	doublereal F1 = (k*delta_1 -c*vz_1)*b1;

	Vec3 F1_v = Vec3(
		0.,
		0.,
		F1
	);

	if (z_2>0.0) {
		c1 = 0.0;
		std::cout << "Res02" << std::endl;
	} else {
		c1 = 1.0;
		std::cout << "Res03" << std::endl;
	}
	
	doublereal F2 = (k*delta_2 -c*vz_2)*c1;

	Vec3 F2_v = Vec3(
		0.,
		0.,
		F2
	); 

	//WorkVecに代入
	WorkVec.Put(1, F1_v);
	WorkVec.Put(4, F2_v);
>>>>>>> 443587a971f615aab80508aa00292e2642dd7ecd
	return WorkVec;
	std ::cout << "15" << std::endl;
}


//calculate Jacobian matrix
VariableSubMatrixHandler& 
Contactlaw::AssJac(
	VariableSubMatrixHandler& WorkMat,
	doublereal dCoef, 
	const VectorHandler& XCurr,
	const VectorHandler& XPrimeCurr)
{
	FullSubMatrixHandler& WM = WorkMat.SetFull();

	//node1 current data
<<<<<<< HEAD
	const integer iMomentumIndex1 = pNode1->iGetFirstMomentumIndex();
	const integer iPositionIndex1 = pNode1->iGetFirstPositionIndex();
	const Vec3& r1 = pNode1->GetXCurr();

	/*
	//node2 current data
	const integer iMomentumIndex2 = pNode2->iGetFirstMomentumIndex();
	const integer iPositionIndex2 = pNode2->iGetFirstPositionIndex();
	const Vec3& r2 = pNode2->GetXCurr();
	*/
=======
	const integer iPositionIndex1 = pNode1->iGetFirstPositionIndex();
	const integer iMomentumIndex1 = pNode1->iGetFirstMomentumIndex();
	const Vec3& r1 = pNode1->GetXCurr();
	const Vec3& v1 = pNode1->GetXPPCurr();

	//node2 current data
	const integer iPositionIndex2 = pNode2->iGetFirstPositionIndex();
	const integer iMomentumIndex2 = pNode2->iGetFirstMomentumIndex();
	const Vec3& r2 = pNode2->GetXCurr();
	const Vec3& v2 = pNode2->GetXPPCurr();
>>>>>>> 443587a971f615aab80508aa00292e2642dd7ecd

	//obtain vector dimension
	integer iNumRows;
	integer iNumCols;
	WorkSpaceDim(&iNumRows, &iNumCols);
	WM.ResizeReset(iNumRows, iNumCols);

	for(int iCnt = 1; iCnt<=3; iCnt++){
		WM.PutRowIndex(iCnt, iMomentumIndex1+iCnt);
		WM.PutColIndex(iCnt, iPositionIndex1+iCnt);
	}	
<<<<<<< HEAD
	/*
=======
>>>>>>> 443587a971f615aab80508aa00292e2642dd7ecd
	for(int iCnt = 1; iCnt<=3; iCnt++){
		WM.PutRowIndex(iCnt+3, iMomentumIndex2+iCnt);
		WM.PutColIndex(iCnt+3, iPositionIndex2+iCnt);
	}
<<<<<<< HEAD
	*/

	//calculate forces
	/*
	doublereal g,Zs, nu1d, nu1s, nu2d, nu2s;
	pSeabed->get(g, Zs, nu1d, nu1s, nu2d, nu2s);
	doublereal A;
=======

	doublereal g,Zs, nu1d, nu1s, nu2d, nu2s;
	pSeabed->get(g, Zs, nu1d, nu1s, nu2d, nu2s);

	
	//node1
	doublereal A1;
    doublereal vx_1   = v1.dGet(1);
    doublereal vy_1   = v1.dGet(2);
	doublereal vz_1   = v1.dGet(3);
	doublereal z_1    = r1.dGet(3) - Zs;
	doublereal delta_1 = std::abs(z_1);
	doublereal db1_dx;
	//node2
	doublereal A2;
	doublereal vx_2   = v2.dGet(1);
    doublereal vy_2   = v2.dGet(2);
	doublereal vz_2   = v2.dGet(3);
	doublereal z_2    = r2.dGet(3) - Zs;
	doublereal delta_2 = std::abs(z_2);
>>>>>>> 443587a971f615aab80508aa00292e2642dd7ecd
	doublereal dc1_dx;

<<<<<<< HEAD
		doublereal z = XCurr(iPositionIndex+3) - Zs;
		doublereal v = XPrimeCurr(iPositionIndex+3);
		doublereal z = XCurr(iPositionIndex1+3) - Zs;
		doublereal v = XPrimeCurr(iPositionIndex1+3);
	if (z>0.0) {
	dc1_dx = 0.0;
	std::cout << "Jac00" << std::endl;
	} else {
	dc1_dx = 1.0;
	std::cout << "Jac01" << std::endl;
	}

	A = (-c - dCoef*k)*dc1_dx;


	// set value
	//どう計算すればよいのか相談
	WM.PutCoef( 1,  1, A );
	*/
=======
	//node1_jac
	if (z_1>0.0) {
		db1_dx = 0.0;
		std::cout << "Jac00" << std::endl;
	} else {
		db1_dx = 1.0;
		std::cout << "Jac01" << std::endl;
	}

	A1 = (-c - dCoef*k)*db1_dx;

	//node2_jac
	if (z_2>0.0) {
		dc1_dx = 0.0;
		std::cout << "Jac02" << std::endl;
	} else {
		dc1_dx = 1.0;
		std::cout << "Jac03" << std::endl;
	}

	A2 = (-c - dCoef*k)*dc1_dx;

	WM.PutCoef( 1,  1, A1 );
	WM.PutCoef( 3,  3, A2 );
>>>>>>> 443587a971f615aab80508aa00292e2642dd7ecd
	return WorkMat;

	std ::cout << "16" << std::endl;
}


/*=======================================================================================
* Private Data
*=======================================================================================*/
//set number of private data
unsigned int
Contactlaw::iGetNumPrivData(void) const
{
	return 0;
	std ::cout << "17" << std::endl;
}

/*
//set index of private data
unsigned int
Hydrostatic::iGetPrivDataIdx(const char *s) const
{	
	static const struct {
		int index;
		char name[3];
	}

	data[] = {
			{ 1, "A"},
			{ 2, "B"},
			{ 3, "C"},
	};

	for (unsigned i = 0; i < sizeof(data) / sizeof(data[0]); ++i ) {
		if (0 == strcmp(data[i].name,s)) {
			return data[i].index;
		}
	}

	silent_cerr("Hydrostatic (" << GetLabel() << "): no private data \"" << s << "\"" << std::endl);

	return 0;	
}
//function to get private data
doublereal
Hydrostatic::dGetPrivData(unsigned int i) const;
{
	switch (i) {
	case 1:
		return a;
	case 2:
		return b;
	case 3:
		return c;
	}
	throw DataManager::ErrGeneric(MBDYN_EXCEPT_ARGS);
}
*/

/*=======================================================================================
* Configure runtime processing
*=======================================================================================*/
//describe update function
void 
Contactlaw::Update(const VectorHandler& XCurr, const VectorHandler& XPrimeCurr)
{
	return;
	std ::cout << "18" << std::endl;
}
//process before each iteration
void
Contactlaw::BeforePredict(VectorHandler& /* X */ ,
					VectorHandler& /* XP */ ,
					VectorHandler& /* XPrev */ ,
					VectorHandler& /* XPPrev */ ) const
{
	return;
	std ::cout << "19" << std::endl;
}
//process after each iteration
void
Contactlaw::AfterPredict(VectorHandler& X, VectorHandler& XP)
{
	return;
	std ::cout << "20" << std::endl;
}
//process after convergence (each time step)
void
Contactlaw::AfterConvergence(const VectorHandler& X, const VectorHandler& XP)
{
	return;
	std ::cout << "21" << std::endl;
}

/*=======================================================================================
* Output
*=======================================================================================*/
//output file 
void
Contactlaw::Output(OutputHandler& OH) const
{
	if (bToBeOutput()) {
		if (OH.UseText(OutputHandler::LOADABLE)) {
			OH.Loadable() << GetLabel()
				<< std::endl;
		}
	}
	std ::cout << "22" << std::endl;
}



/*=======================================================================================
* etc
*=======================================================================================*/
//print information of connected nodes
int
Contactlaw::iGetNumConnectedNodes(void) const
{
	return 0;
	std ::cout << "23" << std::endl;
}
void
Contactlaw::GetConnectedNodes(std::vector<const Node *>& connectedNodes) const
{
	return;
	std ::cout << "24" << std::endl;
}
//output restart file
std::ostream&
Contactlaw::Restart(std::ostream& out) const
{
	return out << "# Contactlaw (" << GetLabel() << "): not implemented yet" << std::endl;
	std ::cout << "25" << std::endl;
}

/* ----------------------------- Contactlaw end -------------------------------------- */


/*=======================================================================================
*  Module init function
*=======================================================================================*/
extern "C"
int module_init(const char *module_name, void *pdm, void *php)
{
	bool UDEset = true;

	UserDefinedElemRead *rf = new UDERead<Contactlaw>;
	if (!SetUDE("Contactlaw", rf)) {
		delete rf;
		return false;
	}

	if (!UDEset) {
		silent_cerr("Contactlaw: "
			"module_init(" << module_name << ") "
			"failed" << std::endl);
		return -1;
	}

	return 0;
	std ::cout << "26" << std::endl;
}