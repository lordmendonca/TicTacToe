/*
 * CBoard.cpp
 *
 *  Created on: 22 Nov 2021
 *      Author: JASON
 */
/*
 * Standard header files
 */
#include <iostream>
#include <stdlib.h>
/*
 * Project specific header files
 */
#include "CBoard.h"

CBoard::CBoard()
{
	/*
	 * Initialization of number of rows and columns to 0 as values will be assigned in the derived class.
	 */
	m_rows = 0;
	m_columns = 0;
	/*
	 * memory will be allocated in the derived class.
	 */
	m_boardElement = NULL;
}

CBoard::~CBoard()
{
	delete [] m_boardElement;
}

void CBoard::setRows(unsigned short rows)
{
	this->m_rows = rows;
}

void CBoard::setColumns(unsigned short columns)
{
	this->m_columns = columns;
}

void CBoard::setBoardElement(unsigned short size)
{
	m_boardElement = new unsigned short [size];
}

unsigned short CBoard::getRows() const
{
	return m_rows;
}

unsigned short CBoard::getColumns() const
{
	return m_columns;
}

unsigned short CBoard::getBoardElement(unsigned short position) const
{
	return m_boardElement[position];
}

int CBoard::boardIndexCalc(unsigned short row, unsigned short column)
{
	/*	To check if player input parameters are outside board dimensions.	 */
	if (row >= getRows() || column >= getColumns())
	{
		return INVALID_INDEX;
	}
	/* To check if calculated coin position is outside the scope of the board dimensions. */
	else if(row < 0 || column < 0)
	{
		return INVALID_INDEX;
	}
	/* Calculation of coin position on the board. */
	else
	{
		return (row * getColumns()) + column;
	}
}

void CBoard::placeBoardElement(int position, unsigned short element)
{
	this->m_boardElement[position] = element;
}
