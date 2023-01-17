/*
 * CTicTacToeBoard.h
 *
 *  Created on: 27 Nov 2021
 *      Author: JASON
 */

#ifndef CTICTACTOEBOARD_H_
#define CTICTACTOEBOARD_H_
/*
 * Project specific header files
 */
#include "CBoard.h"
/**
 * \brief Pre-processor value of the board.
 * \details THREE			:  Dimensions of Tic-Tac-Toe game.
 */
#define DIMENSIONS 3
/**
 * \brief Pre-processor value of the board.
 * \details TTT_ROWS	: Tic-Tac-Toe game rows.
 */
#define TTT_ROWS DIMENSIONS
/**
 * \brief Pre-processor value of the board.
 * \details TTT_COLUMNS	: Tic-Tac-Toe game columns.
 */
#define TTT_COLUMNS TTT_ROWS
/**
 * \brief Pre-processor value of the board.
 * \details TTT_SIZE	: Size of the Tic-Tac-Toe Board (Number of available positions for the coin).
 */
#define TTT_SIZE TTT_ROWS*TTT_COLUMNS
/**
 * \brief Pre-processor value of the board.
 * \details NO_OF_PLAYERS	: Two players at a time.
 */
#define NO_OF_PLAYERS	2
/**
 * \brief Describes the field elements of the board in integer representation.
 * \details PLAYER_1			: Player 1 is represented by '0'
 * \details PLAYER_2			: Player 2 is represented by '1'
 * \details EMPTY_FIELD			: An empty field is represented by '2'.
 */
typedef enum {PLAYER_1 = 0 /**< 0 */, PLAYER_2 = 1 /**< 1 */, EMPTY_FIELD = 2 /**< 2 */} boardElement_t;
/**
 * \brief Used to display the field elements of the board for the user.
 * \details ELEMENT_x			: ASCII value of 'x' to represent that coin element in the position.
 * \details ELEMENT_o			: ASCII value of 'o' to represent that coin element in the position.
 * \details ELEMENT_underscore	: ASCII value of '_' to represent unoccupied position.
 */
typedef enum {ELEMENT_x = 120 /**< 120 */, ELEMENT_o = 111 /**< 111 */, ELEMENT_underscore = 95 /**< 95 */} boardElementDisplay_t;
/**
 * \brief Describes the status of the game.
 * \details GAME_NOT_WON		: Represented by '0' to indicate that the game has not been won.
 * \details GAME_WON			: Represented by '1' to indicate that the game has been won.
 */
typedef enum {GAME_NOT_WON = 0 /**< 0 */, GAME_WON = 1 /**< 1 */} gameWin_st;
/**
 * \brief Class CTicTacToeBoard derived from Class CBoard
 */
class CTicTacToeBoard: public CBoard
{
	/**
	 *  \brief Checks for 3 same coins along either one of the rows.
	 *  
	 *  \return Returns 1 (= GAME_WON) if there are 3 same coins are along either one of the rows, otherwise 0 (= GAME_NOT_WON).
	 *  
	 */
	gameWin_st checkRows();
	/**
	 *  \brief Checks for 3 same coins along either one of the columns.
	 *  
	 *  \return Returns 1 (= GAME_WON) if there are 3 same coins are along either one of the columns, otherwise 0 (= GAME_NOT_WON).
	 *  
	 */
	gameWin_st checkColumns();
	/**
	 *  \brief Checks for 3 same coins along either one of the two diagonals.
	 *  
	 *  \return Returns 1 (= GAME_WON) if there are 3 same coins are along either one of the two diagonals, otherwise 0 (= GAME_NOT_WON).
	 *  
	 */
	gameWin_st checkDiagonals();
public:
	/**
	 * \brief Default Constructor
	 */
	CTicTacToeBoard();
	/**
	 * \brief Destructor
	 */
	~CTicTacToeBoard();
	/**
	 *  \brief checks if the winner has been found.
	 *
	 *  \return Returns 1 (= GAME_WON) if the game has been won, otherwise 0 (= GAME_NOT_WON).
	 *
	 *  \details Uses the methods checkRows(), checkColumns() and checkDiagonals() to find the winner.
	 */
	gameWin_st checkWin();
};

#endif /* CTICTACTOEBOARD_H_ */
