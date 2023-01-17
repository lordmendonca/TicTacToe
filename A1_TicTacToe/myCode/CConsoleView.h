/*
 * CConsoleView.h
 *
 *  Created on: 3 Dec 2021
 *      Author: JASON
 */

#ifndef CCONSOLEVIEW_H_
#define CCONSOLEVIEW_H_
/*
 * Project specific header file
 */
#include "CScreen.h"
/**
 * \brief Class CConsoleView derived from Class CScreen
 */
class CConsoleView: public CScreen
{
public:
	/**
	 *  \brief Default Constructor
	 */
	CConsoleView();
	/**
	 * \brief Destructor
	 */
	virtual ~CConsoleView();
	/**
	 * \brief This method is used to display the Tic-Tac-Toe Board on the console.
	 */
	void printScreen();
};

#endif /* CCONSOLEVIEW_H_ */
