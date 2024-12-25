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
 * Module - Contactlaw
 *
 * Implemented by
 * Ryoya Hisamatsu <hisamatsu@nams.kyushu-u.ac.jp>
 * Department of Marine Systems Engineering, Kyushu University
 * Motooka 744, Nishi-ku, Fukuoka 819-0395, Fukuoka, Japan 
 * -----------------------------------------------------------------------*/

#ifndef MODULE_CONTACTLAW_H
#define MODULE_CONTACTLAW_H

#include "dataman.h"
#include "userelem.h"
#include "module-seabed.h"
#include "exchangevector.h"
#include "tanhfunc.h"

class Contactlaw
: virtual public Elem, public UserDefinedElem 
{
private:
	/*===================================================================
	 * Private Member Variables
	 *===================================================================*/
	//other private member
	const StructNode *pNode1;
	const StructNode *pNode2;
	const Seabed 			*pSeabed;
	const tanhfunc 			ptanhf;
	const exchangevector	pexv; 
	doublereal 				k;
	doublereal 				c;
private:
	


public:
	/*===================================================================
	 * Constructor and Destructor
	 *===================================================================*/
	//constructor
	Contactlaw(unsigned uLabel, const DofOwner *pDO,
		DataManager* pDM, MBDynParser& HP);
	//destructor
	virtual ~Contactlaw(void);


	/*===================================================================
	 * Intial Assembly Process
	 *===================================================================*/
	/*-------------------------------------------------------------------
	 * Configure private DOF for intial assembly process
	 *-------------------------------------------------------------------*/
	//set number of DOF
	virtual unsigned int iGetInitialNumDof(void) const;
	//set initial value
	virtual void SetInitialValue(VectorHandler& XCurr);

	/*-------------------------------------------------------------------
	 * Configure contribution for intial assembly iteration
	 *-------------------------------------------------------------------*/
	//set initial assembly matrix dimension
	virtual void 
	InitialWorkSpaceDim(integer* piNumRows, integer* piNumCols) const;
	//calculate residual vector for initial assembly analysis
   	SubVectorHandler& 
	InitialAssRes(SubVectorHandler& WorkVec, const VectorHandler& XCurr);
	//calculate Jaconbian for initial assembly analysis
   	VariableSubMatrixHandler&
	InitialAssJac(VariableSubMatrixHandler& WorkMat, 
		      const VectorHandler& XCurr);


	/*===================================================================
	 * Initial Value Problem
	 *===================================================================*/
	/*-------------------------------------------------------------------
	 * Configure private DOF
	 *-------------------------------------------------------------------*/
	//set number of DOF
	virtual unsigned int iGetNumDof(void) const;
	//set DOF type
	virtual DofOrder::Order GetDofType(unsigned int i) const;
	//set initial value
	void SetValue(DataManager *pDM, VectorHandler& X, VectorHandler& XP,
		SimulationEntity::Hints *ph);
	//print explanation of variables and equations
	virtual std::ostream& DescribeDof(std::ostream& out, const char *prefix, bool bInitial) const;
	virtual std::ostream& DescribeEq(std::ostream& out, const char *prefix, bool bInitial) const;
	

	/*-------------------------------------------------------------------
	 * Configure contribution for state equation
	 * state equation A@\Delta{\dot{y}} = b,
	 * where, y is the state vector
	 * AssRes evaluates: b = F(\dot{y},y,t)
	 * AssJac evaluates: A = -F_{\dot{y}}-dCoef F_{y}
	 *-------------------------------------------------------------------*/
	//set matrix dimension
	virtual void WorkSpaceDim(integer* piNumRows, integer* piNumCols) const;
	//calculate residual vector, b
	SubVectorHandler& 
	AssRes(SubVectorHandler& WorkVec,
		doublereal dCoef,
		const VectorHandler& XCurr, 
		const VectorHandler& XPrimeCurr);
	//calculate Jacobian matrix, A
	VariableSubMatrixHandler& 
	AssJac(VariableSubMatrixHandler& WorkMat,
		doublereal dCoef, 
		const VectorHandler& XCurr,
		const VectorHandler& XPrimeCurr);


	/*===================================================================
	 * Private Data
	 *===================================================================*/
	/*-------------------------------------------------------------------
	 * Configure private data
	 *-------------------------------------------------------------------*/
	//set number of private data
	virtual unsigned int iGetNumPrivData(void) const;
	/*
	//set index of private data
	virtual unsigned int iGetPrivDataIdx(const char *s) const;
	//function to get private data
	virtual doublereal dGetPrivData(unsigned int i) const;
	*/

	/*-------------------------------------------------------------------
	 * Configure runtime processing
	 *-------------------------------------------------------------------*/
	//describe update function
	virtual void 
	Update(const VectorHandler& XCurr, const VectorHandler& XPrimeCurr);
	//process before each iteration
	virtual void
	BeforePredict(VectorHandler& /* X */ ,
					VectorHandler& /* XP */ ,
					VectorHandler& /* XPrev */ ,
					VectorHandler& /* XPPrev */ ) const;
	//process after each iteration
	virtual void
	AfterPredict(VectorHandler& X, VectorHandler& XP);
	//process after convergence (each time step)
	virtual void
	AfterConvergence(const VectorHandler& X, const VectorHandler& XP);


	/*===================================================================
	 * Output
	 *===================================================================*/
	//output file 
	virtual void Output(OutputHandler& OH) const;


	/*===================================================================
	 * etc
	 *===================================================================*/
	//print information of connected nodes
	virtual int iGetNumConnectedNodes(void) const;
	virtual void GetConnectedNodes(std::vector<const Node *>& connectedNodes) const;
	//output restart file
	virtual std::ostream& Restart(std::ostream& out) const;
};

#endif // MODULE_HYDROSTATIC_v1_H
