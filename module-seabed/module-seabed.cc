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
 * Module - Seabed
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

#include "module-seabed.h"
#include "seabedprop.h"

/* ----------------------------- Seabed start --------------------------------------*/

/*=======================================================================================
 * Constructor and Destructor
 *=======================================================================================*/
//constructor
Seabed::Seabed (
	unsigned uLabel,
	const DofOwner *pDO,
	DataManager* pDM,
	MBDynParser& HP
)
: Elem(uLabel, flag(0)), UserDefinedElem(uLabel, pDO), seabedpropowner()
{
	// help message or no arg error
	if (HP.IsKeyWord("help")) {
		silent_cout(
			"help message\n"
			"==== Module: Seabed ====\n"
			"- Note: \n"
			"\tTest, \n"
			"- Usage: \n"
			"\tSeabed, g, z;\n"
			<< std::endl);
		
		if (!HP.IsArg()) {
			throw NoErr(MBDYN_EXCEPT_ARGS);
		}
	}

	doublereal g = HP.GetReal();
	doublereal z = HP.GetReal();
	pSeabedprop.setValue(g, z);

	//output flag
	SetOutputFlag(pDM->fReadOutput(HP, Elem::LOADABLE));
	//export log file
	pDM->GetLogFile()
		<< "Seabed: " << uLabel
		<< std::endl;
	std ::cout << "30" << std::endl;
}

//destructor
Seabed::~Seabed (void)
{
	NO_OP;
	std ::cout << "31" << std::endl;
}
/*=======================================================================================
 * Intial Assembly Process
 *=======================================================================================*/
//set number of DOF
unsigned int
Seabed::iGetInitialNumDof(void) const
{
	return 0;
	std ::cout << "32" << std::endl;
}

//set initial value
void
Seabed::SetInitialValue(VectorHandler& XCurr)
{
	return;
	std ::cout << "33" << std::endl;
}

//set initial assembly matrix dimension
void 
Seabed::InitialWorkSpaceDim(integer* piNumRows, integer* piNumCols) const
{
	*piNumRows = 0;
	*piNumCols = 0;
	std ::cout << "34" << std::endl;
}

//calculate residual vector for initial assembly analysis
SubVectorHandler& 
Seabed::InitialAssRes(
	SubVectorHandler& WorkVec,
	const VectorHandler& XCurr)
{
	WorkVec.ResizeReset(0);
	return WorkVec;
	std ::cout << "35" << std::endl;
}
//calculate Jaconbian for initial assembly analysis
VariableSubMatrixHandler&
Seabed::InitialAssJac(
	VariableSubMatrixHandler& WorkMat, 
	const VectorHandler& XCurr)
{
	WorkMat.SetNullMatrix();
	return WorkMat;
	std ::cout << "36" << std::endl;
}
/*=======================================================================================
 * Initial Value Problem
 *=======================================================================================*/
//set number of DOF
unsigned int
Seabed::iGetNumDof(void) const
{
	return 0;
	std ::cout << "37" << std::endl;
}

//set DOF type
DofOrder::Order
Seabed::GetDofType(unsigned int i) const
{

	return DofOrder::DIFFERENTIAL;
	std ::cout << "38" << std::endl;
}

//set initial value
void
Seabed::SetValue(
	DataManager *pDM,
	VectorHandler& X,
	VectorHandler& XP,
	SimulationEntity::Hints *ph)
{
	return;
	std ::cout << "39" << std::endl;
}

/*
//print explanation of variables and equations
std::ostream&
Sea::DescribeDof(std::ostream& out, const char *prefix, bool bInitial) const
{
}
std::ostream&
Sea::DescribeEq(std::ostream& out, const char *prefix, bool bInitial) const
{
}
*/

//set matrix dimension
void
Seabed::WorkSpaceDim(integer* piNumRows, integer* piNumCols) const
{
	*piNumRows = 0;
	*piNumCols = 0;	
	std ::cout << "40" << std::endl;
}

//calculate residual vector
SubVectorHandler& 
Seabed::AssRes(
	SubVectorHandler& WorkVec,
	doublereal dCoef,
	const VectorHandler& XCurr, 
	const VectorHandler& XPrimeCurr)
{
	WorkVec.ResizeReset(0);
	return WorkVec;
	std ::cout << "41" << std::endl;
}

//calculate Jacobian matrix
VariableSubMatrixHandler& 
Seabed::AssJac(
	VariableSubMatrixHandler& WorkMat,
	doublereal dCoef, 
	const VectorHandler& XCurr,
	const VectorHandler& XPrimeCurr)
{
	WorkMat.SetNullMatrix();
	return WorkMat;
	std ::cout << "42" << std::endl;
}
/*=======================================================================================
 * Private Data
 *=======================================================================================*/
//set number of private data
unsigned int
Seabed::iGetNumPrivData(void) const
{
	return 0;
	std ::cout << "43" << std::endl;
}

/*
//set index of private data
unsigned int
Sea::iGetPrivDataIdx(const char *s) const
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

	silent_cerr("Sea (" << GetLabel() << "): no private data \"" << s << "\"" << std::endl);

	return 0;	
}
//function to get private data
doublereal
Sea::dGetPrivData(unsigned int i) const;
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
Seabed::Update(const VectorHandler& XCurr, const VectorHandler& XPrimeCurr)
{
	return;
	std ::cout << "44" << std::endl;
}
//process before each iteration
void
Seabed::BeforePredict(VectorHandler& /* X */ ,
					VectorHandler& /* XP */ ,
					VectorHandler& /* XPrev */ ,
					VectorHandler& /* XPPrev */ ) const
{
	return;
	std ::cout << "45" << std::endl;
}
//process after each iteration
void
Seabed::AfterPredict(VectorHandler& X, VectorHandler& XP)
{
	return;
	std ::cout << "46" << std::endl;
}
//process after convergence (each time step)
void
Seabed::AfterConvergence(const VectorHandler& X, const VectorHandler& XP)
{
	return;
	std ::cout << "47" << std::endl;
}
/*=======================================================================================
 * Output
 *=======================================================================================*/
//output file 
void
Seabed::Output(OutputHandler& OH) const
{
	if (bToBeOutput()) {
		if (OH.UseText(OutputHandler::LOADABLE)) {
			OH.Loadable() << GetLabel()
				<< std::endl;
		}
	}
	std ::cout << "48" << std::endl;
}

/*=======================================================================================
 * etc
 *=======================================================================================*/
/*
//print information of connected nodes
int
Sea::iGetNumConnectedNodes(void) const
{
	return 0;
}
void
Sea::GetConnectedNodes(std::vector<const Node *>& connectedNodes) const
{
	return;
}
*/
//output restart file
std::ostream&
Seabed::Restart(std::ostream& out) const
{
   	return out << "# Seabed (" << GetLabel() << "): not implemented yet" << std::endl;
	std ::cout << "49" << std::endl;
}
/* ----------------------------- Seabed end -------------------------------------- */

/*=======================================================================================
 *  Module init function
 *=======================================================================================*/
extern "C"
int module_init(const char *module_name, void *pdm, void *php)
{
	bool UDEset = true;

	UserDefinedElemRead *rf = new UDERead<Seabed>;
	if (!SetUDE("Seabed", rf)) {
		delete rf;
		return false;
	}

	if (!UDEset) {
		silent_cerr("Seabed: "
			"module_init(" << module_name << ") "
			"failed" << std::endl);
		return -1;
	}

	return 0;
}