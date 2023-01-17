/*
 * CPlayer.cpp
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
#include "CPlayer.h"

/* static member's initialization to 0, viz. Player 1's coin representation in integer for the first round of the game. */
unsigned short CPlayer::element = 0;

CPlayer::CPlayer()
{
	m_boardPtr = NULL;
}

CPlayer::~CPlayer()
{
	delete m_boardPtr;
}

void CPlayer::setBoardPtr(CTicTacToeBoard* boardPtr)
{
	if(boardPtr != NULL)
		m_boardPtr = boardPtr;
	else
		std::cout << "Invalid address passed to the board pointer." << std::endl;
}




