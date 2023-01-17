/*
 * CGraphicalUserInterface.h
 *
 *  Created on: 3 Dec 2021
 *      Author: JASON
 */

#ifndef CGRAPHICALUSERINTERFACE_H_
#define CGRAPHICALUSERINTERFACE_H_
/*
 * Project specific header file
 */
#include "CScreen.h"
/**
 * \brief Class CGraphicalUserInterface derived from Class CScreen
 */
class CGraphicalUserInterface: public CScreen
{
public:
	/**
	 *  \brief Default Constructor
	 */
	CGraphicalUserInterface();
	/**
	 * \brief Destructor
	 */
	virtual ~CGraphicalUserInterface();
	/**
	 * \brief This method is used to display the Tic-Tac-Toe Board on the Graphical User-Interface.
	 */
	void printScreen();
};

#endif /* CGRAPHICALUSERINTERFACE_H_ */
