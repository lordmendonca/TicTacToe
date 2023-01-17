/*
 * CConsoleView.cpp
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
#include "CConsoleView.h"

CConsoleView::CConsoleView()
{
	/* Nothing to initialize. */
}

CConsoleView::~CConsoleView()
{
	/* Nothing to destruct. */
}

void CConsoleView::printScreen()
{
	std::cout << "-----------------------------------------------------------------" << std::endl;

	unsigned rowSize = m_boardPtr->getRows();
	unsigned columnSize = m_boardPtr->getColumns();
	
	/* Display indentation along the column for user-friendly input. */
	std::cout << "#\t";
	for(unsigned short col = 0; col < columnSize; col++)
	{
		std::cout << col << "|\t";
	}
	std::cout << std::endl;
	
	/* Printing the board elements. */
	for (unsigned short row = 0; row < rowSize; row++)
	{
		/* Display indentation along the row for user-friendly input. */
		std::cout << row << "|\t";
		for (unsigned short column = 0; column < columnSize; column++)
		{
			unsigned int boardElement = m_boardPtr->getBoardElement(m_boardPtr->boardIndexCalc(row, column));
			std::cout << (char)((boardElement == PLAYER_1)?ELEMENT_x:((boardElement == PLAYER_2)?ELEMENT_o:ELEMENT_underscore));
			std::cout << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << "-----------------------------------------------------------------" << std::endl;
}

