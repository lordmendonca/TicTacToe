/*
 * CHuman.cpp
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
#include "CHuman.h"

CHuman::CHuman()
{
	/* Nothing to initialize. */
}

CHuman::~CHuman()
{
	/* Nothing to destruct. */
}

bool CHuman::makeMove()
{
	/* Player status. */
	std::cout << "HUMAN having coin " << (char)((element == PLAYER_1)?ELEMENT_x:ELEMENT_o) << std::endl;

	/* user entry of row and column indices. */
	unsigned short input_row = 0;
	unsigned short input_column = 0;
	
	int userEntry = INCORRECT_ENTRY; /* Initialize as incorrect entry so that user entry can be looped until it is valid. */

	do
	{
	int position = 0;
	std::cout << "-----------------------------------------------------------------" << std::endl;
	std::cout << "Enter either Row or Column index as 9 to terminate the game at any point" << std::endl;
	std::cout << "-----------------------------------------------------------------" << std::endl;
	std::cout << "Enter the ROW index	: ";
	std::cin >> input_row;
	std::cout << "Enter the COLUMN index 	: ";
	std::cin >> input_column;
	std::cout << "-----------------------------------------------------------------" << std::endl;
	position = m_boardPtr->boardIndexCalc(input_row, input_column);
	if(input_row == TERMINATE_GAME || input_column == TERMINATE_GAME)
	{
		std::cout << "Game terminated by Player " << element + 1 << "."<< std::endl;
		exit(EXIT_SUCCESS); /* Game termination by the player. */
	}
	else if(INVALID_INDEX == position)
	{
		std::cout << "Invalid Position! Enter co-ordinates again." << std::endl;
	}
	else if(EMPTY_FIELD != m_boardPtr->getBoardElement(position))
	{
		std::cout << "Coin already placed by opponent here! Enter co-ordinates again." << std::endl;
	}
	else
	{
		m_boardPtr->placeBoardElement(position, element); /* Coin element placed successfull. */
		element = (element + 1) % 2; /* Switch the player. */
		userEntry = 1; /* Correct entry found. */
	}
	}while(CORRECT_ENTRY != userEntry); /* Loop until row and column indices entered are valid. */

	return m_boardPtr->checkWin(); /* returns 1 if winner was found, else 0, after the current move. */
}
