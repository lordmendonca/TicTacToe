/*
 * CTicTacToeBoard.cpp
 *
 *  Created on: 27 Nov 2021
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
#include "CTicTacToeBoard.h"

CTicTacToeBoard::CTicTacToeBoard()
{
	if(TTT_ROWS > 0 && TTT_COLUMNS > 0 && TTT_SIZE >0)
	{
		/* Tic-Tac-Toe row dimension initialization. */
		setRows(TTT_ROWS);
		/* Tic-Tac-Toe column dimension initialization. */
		setColumns(TTT_COLUMNS);
		/* Tic-Tac-Toe row board size allocation and initialization. */
		setBoardElement(TTT_SIZE);
		for(unsigned short index = 0; index < TTT_SIZE; index++)
		{
			placeBoardElement(index, EMPTY_FIELD);
		}
	}
	else
	{
		std::cout << "Incorrect Board Dimensions." << std::endl;
	}
}

CTicTacToeBoard::~CTicTacToeBoard()
{
	/* Nothing to destruct here as no object pointers were created here but in the base class, where it will be destroyed. */
}

gameWin_st CTicTacToeBoard::checkRows()
{
	/* Checking Rows for Victory.*/
	 for (int row = 0; row < getRows(); row++)
	 {
	 	if( (getBoardElement(boardIndexCalc(row, 0)) == getBoardElement(boardIndexCalc(row, 1))) &&
	 			(getBoardElement(boardIndexCalc(row, 1)) == getBoardElement(boardIndexCalc(row, 2))) )
	 	{
	 		if(getBoardElement(boardIndexCalc(row, 0)) != EMPTY_FIELD)
	 			return GAME_WON;	/*  Game won. */
		}
	 }
	/*  Game not won. */
	return GAME_NOT_WON;
}

gameWin_st CTicTacToeBoard::checkColumns()
{
	/* Checking Columns for Victory. */
	for (int col = 0; col < getColumns(); col++)
	{
		if( (getBoardElement(boardIndexCalc(0, col)) == getBoardElement(boardIndexCalc(1, col))) &&
				(getBoardElement(boardIndexCalc(1, col)) == getBoardElement(boardIndexCalc(2, col))) )
		{
			if(getBoardElement(boardIndexCalc(0, col)) != EMPTY_FIELD)
				return GAME_WON;	/*  Game won. */
		}
	}
	/*  Game not won. */
	return GAME_NOT_WON;
}

gameWin_st CTicTacToeBoard::checkDiagonals()
{
	/* Checking Diagonals for Victory. */
		if((getBoardElement(boardIndexCalc(0, 0)) == getBoardElement(boardIndexCalc(1, 1))) &&
				(getBoardElement(boardIndexCalc(1, 1)) == getBoardElement(boardIndexCalc(2, 2))) )
		{
			if(getBoardElement(boardIndexCalc(1, 1)) != EMPTY_FIELD)
				return GAME_WON;	/*  Game won. */
		}

		if((getBoardElement(boardIndexCalc(0, 2)) == getBoardElement(boardIndexCalc(1, 1))) &&
				(getBoardElement(boardIndexCalc(1, 1)) == getBoardElement(boardIndexCalc(2, 0))) )
		{
			if(getBoardElement(boardIndexCalc(1, 1)) != EMPTY_FIELD)
				return GAME_WON;	/*  Game won. */
		}
	/*  Game not won. */
	return GAME_NOT_WON;
}

gameWin_st CTicTacToeBoard::checkWin()
{
	/* Check if either rows or columns or diagonals has a win. */
	if(checkRows() | checkColumns() | checkDiagonals())
		return GAME_WON;		/*  Game won. */
	else
		return GAME_NOT_WON;	/*  Game not won. */
}
