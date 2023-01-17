/*
 * CTicTacToeGame.h
 *
 *  Created on: 27 Nov 2021
 *      Author: JASON
 */

#ifndef CTICTACTOEGAME_H_
#define CTICTACTOEGAME_H_
/*
 * Project header files
 */
#include "CTicTacToeBoard.h"
#include "CScreen.h"
#include "CConsoleView.h"
#include "CGraphicalUserInterface.h"
#include "CPlayer.h"
#include "CHuman.h"
#include "CComputer.h"
/**
 * \brief Describes the type of screen.
 * \details CONSOLE	: Represents Console View Screen.
 * \details GUI		: Represents a Graphical User Interface Screen.
 */
typedef enum{CONSOLE = 1 /**< 1 */, GUI = 2 /**< 2 */} screenType_t;
/**
 * \brief Describes the type of player.
 * \details HUMAN			: Represents a human player.
 * \details COMPUTER		: Represents a computer player.
 */
typedef enum{HUMAN = 1 /**< 1 */, COMPUTER = 2 /**< 2 */} gamePlayers_t;
/**
 * \brief Describes if the user has entered the correct entry for the type of player as HUMAN or COMPUTER.
 * \details INCORRECT_TYPE_CHOSEN		: User has made an invalid entry.
 * \details CORRECT_TYPE_CHOSEN			: User has made a valid entry.
 */
typedef enum{INCORRECT_TYPE_CHOSEN = 0 /**< 0 */, CORRECT_TYPE_CHOSEN = 1 /**< 1 */} checkPlayerType_t;
/**
 * \brief Class CTicTacToeGame
 */
class CTicTacToeGame
{
    /**
     * \param m_tttBoard 	: A pointer to the class object of type 'CTicTacToeBoard'. 
     * @link aggregationByValue
     * @supplierCardinality 0..1
     */
	CTicTacToeBoard m_tttBoard;
    /**
     * \param m_screen 	: A pointer to the class object of type 'CScreen'.
     * @link aggregationByValue
     */
	CScreen* m_screen;
    /**
     * \param m_player1Ptr 	: A pointer to the class object of type 'CPlayer' for Player 1.
     * @link aggregationByValue
     */
	CPlayer* m_player1Ptr;
    /**
     * \param m_player2Ptr 	: A pointer to the class object of type 'CPlayer' for Player 2.
     * @link aggregationByValue
     */
	CPlayer* m_player2Ptr;
	/**
	 *  \brief Method that allows dynamic selection of the type of players in the game.
	 *  
	 *  \param [in] playerNo To index the player playing the game.
	 *  
	 *  \details Tic-Tac-Toe has only two players.
	 */
	void selectPlayer(unsigned int playerNo);
	/**
	 *  \brief Method that allows dynamic selection of the type of screen in the game.
	 *
	 *  \param [in] screenType To index the type of screen required.
	 */
	void selectScreen(unsigned int screenType);
public:
	/**
	 * \brief Default Constructor
	 */
	CTicTacToeGame();
	/**
	 * \brief Destructor
	 */
	~CTicTacToeGame();
	/**
	 *  \brief Method that has the control logic (play) of the game.
	 *  
	 *  \details Alternates the game between players and declares the winner or draw match at the end of the game.
	 */
	void playGame();
};

#endif /* CTICTACTOEGAME_H_ */
