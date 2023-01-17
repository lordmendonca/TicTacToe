/*
 * CScreen.cpp
 *
 *  Created on: 3 Dec 2021
 *      Author: JASON
 */
/*
 * Standard header files
 */
#include <iostream>
#include <stdlib.h>
/*
 * Project header file
 */
#include "CScreen.h"

CScreen::CScreen()
{
	m_boardPtr = NULL;
}

CScreen::~CScreen()
{
	delete [] m_boardPtr;
}

void CScreen::setBoardPtr(CTicTacToeBoard* boardPtr)
{
	if(boardPtr != NULL)
		m_boardPtr = boardPtr;
	else
		std::cout << "Invalid address passed to the board pointer." << std::endl;
}
