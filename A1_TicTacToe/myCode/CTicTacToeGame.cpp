/*
 * CTicTacToeGame.cpp
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
#include "CTicTacToeGame.h"

CTicTacToeGame::CTicTacToeGame()
{
	/*
	 * The requirement is to print the output on console only.
	 * However, selectScreen() function can updated for the user to dynamically choose between console and GUI, in the future.
	 */
	selectScreen(CONSOLE);
	m_screen->setBoardPtr(&m_tttBoard);
	std::cout << "-----------------------------------------------------------------" << std::endl;
	std::cout << "WELCOME TO TIC-TAC-TOE" << std::endl;
	std::cout << "-----------------------------------------------------------------" << std::endl;
	/* Game begins with the selection of type of the two players involved. */
	selectPlayer(PLAYER_1);	/* Player 1. */
	selectPlayer(PLAYER_2);	/* Player 2. */
	/* Initialize both the players' board pointers using the same tic-tac-toe board with the same address. */
	m_player1Ptr->setBoardPtr(&m_tttBoard);
	m_player2Ptr->setBoardPtr(&m_tttBoard);
	/* First display of the console after all the necessary initializations. */
	m_screen->printScreen();
}

CTicTacToeGame::~CTicTacToeGame()
{
	delete m_player1Ptr;
	delete m_player2Ptr;
}

void CTicTacToeGame::selectPlayer(unsigned int playerNo)
{
	unsigned int playerType = COMPUTER;	/* Assume the default player type is COMPUTER. */
	checkPlayerType_t checkCorrect = INCORRECT_TYPE_CHOSEN; /* Initialize as incorrect entry so that user entry can be looped until it is valid. */

	std::cout << "-----------------------------------------------------------------" << std::endl;
	std::cout << "[ 1 : Human	|	2 : Computer ]" << std::endl;
	std::cout << std::endl;
	do
	{
		std::cout << " Select Player " << playerNo + 1 << " : ";
		std::cin >> playerType; /* User entry for the player type. */
		if(((playerType - 1) == PLAYER_1) || ((playerType - 1) == PLAYER_2))
			checkCorrect = CORRECT_TYPE_CHOSEN; /* Correct entry found. */
		else
			std::cout << " Invalid Player Selection! Enter again." << std::endl;
	}while(CORRECT_TYPE_CHOSEN != checkCorrect); /* Loop until row and column indices entered are valid. */
	std::cout << "-----------------------------------------------------------------" << std::endl;
	/* Selection of the player types. */
	if(HUMAN == playerType)
	{
		CHuman* cH = new CHuman();
		if(PLAYER_1 == playerNo)
		{
			m_player1Ptr = cH; /* Make the object (base) pointer of type 'CPlayer' point to the derived (CHuman) class' object pointer type. This allows dynamically choose the appropriate makeMove() method. */
			std::cout << "PLAYER CHOSEN : HUMAN" << std::endl;
		}
		else if(PLAYER_2 == playerNo)
		{
			m_player2Ptr = cH; /* Make the object (base) pointer of type 'CPlayer' point to the derived (CHuman) class' object pointer type. This allows dynamically choose the appropriate makeMove() method. */
			std::cout << "PLAYER CHOSEN : HUMAN" << std::endl;
		}
	}
	else if(COMPUTER == playerType)
	{
		CComputer* cC = new CComputer();
		if(PLAYER_1 == playerNo)
		{
			m_player1Ptr = cC; /* Make the object (base) pointer of type 'CPlayer' point to the derived (CComputer) class' object pointer type. This allows dynamically choose the appropriate makeMove() method. */
			std::cout << "PLAYER CHOSEN : COMPUTER" << std::endl;
		}
		else if(PLAYER_2 == playerNo)
		{
			m_player2Ptr = cC; /* Make the object (base) pointer of type 'CPlayer' point to the derived (CComputer) class' object pointer type. This allows dynamically choose the appropriate makeMove() method. */
			std::cout << "PLAYER CHOSEN : COMPUTER" << std::endl;
		}
	}
}

void CTicTacToeGame::selectScreen(unsigned int screenType)
{
	/* Selection of the screen type. */
	if(CONSOLE == screenType)
	{
		CConsoleView* cV = new CConsoleView();
		m_screen = cV; /* Make the object (base) pointer of type 'CScreen' point to the derived (CConsoleView) class' object pointer type. This allows dynamically choose the appropriate printScreen() method. */
	}
	else if(GUI == screenType)
	{
		CGraphicalUserInterface* GUI = new CGraphicalUserInterface();
		m_screen = GUI; /* Make the object (base) pointer of type 'CScreen' point to the derived (CGraphicalUserInterface) class' object pointer type. This allows dynamically choose the appropriate printScreen() method. */
	}
}

void CTicTacToeGame::playGame()
{
	bool checkWin = 0; /* Boolean entity that is used to check if we are in the end game with a winner. */
	for(unsigned int i = 0; i < TTT_SIZE; i++)
	{
		std::cout << "ROUND : " << i+1 << std::endl;
		if(0 == i%2) /* Switch between players in each round. */
		{
			std::cout << "Player 1 : \t";
			checkWin = m_player1Ptr->makeMove(); /* Player 1's turn to make a move. Returns 1 if game has been won, else 0 if not won.*/
		}
		else
		{
			std::cout << "Player 2 : \t";
			checkWin = m_player2Ptr->makeMove(); /* Player 2's turn to make a move. Returns 1 if game has been won, else 0 if not won.*/
		}
		m_screen->printScreen(); /* Print the console view at the end of each round. */
		std::cout << "-----------------------------------------------------------------" << std::endl;
		if(checkWin == 1) /* Check if winner was found in the current round. */
		{
			std::cout << "Player " << (i%2) + 1 << " won the game" << std::endl;
			std::cout << "-----------------------------------------------------------------" << std::endl;
			break;			
		}
		if(i == TTT_SIZE - 1)
		{
			std::cout << " DRAW." << std::endl;
			std::cout << "-----------------------------------------------------------------" << std::endl;
		}
	}
	std::cout << " END OF GAME. " << std::endl;
	std::cout << "-----------------------------------------------------------------" << std::endl;
	exit(EXIT_SUCCESS); /* Game successfully terminated after a winner was found. */
}
