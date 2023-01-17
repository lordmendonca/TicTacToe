/*
 * CComputer.h
 *
 *  Created on: 27 Nov 2021
 *      Author: JASON
 */

#ifndef CCOMPUTER_H_
#define CCOMPUTER_H_
/*
 * Project specific header files
 */
#include "CPlayer.h"
/**
 * \brief Represents if a winning move exists or not and used as a return type for the method winningMove().
 * \details NOT_WINNING_MOVE	: To indicate if the move does not makes the current player win the game.
 * \details WINNING_MOVE		: To indicate if the move makes the current player win the game.
 */
typedef enum {NOT_WINNING_MOVE = 0 /**< 0 */, WINNING_MOVE = 1 /**< 1 */} winSt_t;
/**
 * \brief Represents if a defending move exists or not and used as a return type for the method defendingMove().
 * \details NOT_DEFENSE_MOVE	: To indicate if the move does not defends the current player from the opponent's winning of the game.
 * \details DEFENSE_MOVE		: To indicate if the move defends the current player from the opponent's winning of the game.
 */
typedef enum {NOT_DEFENSE_MOVE = 0 /**< 0 */, DEFENSE_MOVE = 1 /**< 1 */} defenseSt_t;
/**
 * \brief Represents the position types on the Tic-Tac-Toe Board.
 * \details CORNERS	: The corners of the Tic-Tac-Toe Board.
 * \details EDGES		: The edges of the Tic-Tac-Toe Board.
 * \details CENTER	: The center of the Tic-Tac-Toe Board.
 * \details LAST_POSITION	: The last position (Bottom-Rightmost corner) of the Tic-Tac-Toe Board.
 */
typedef enum {CORNERS = 0  /**< 0 */, EDGES = 1 /**< 1 */, CENTER = (((TTT_SIZE)-1)/2) /**< (((TTT_SIZE)-1)/2) */, LAST_POSITION = ((TTT_SIZE) - 1)  /**< ((TTT_SIZE) - 1) */} positionSt_t;
/**
 * \brief Class CComputer derived from Class CPlayer
 */
class CComputer: public CPlayer
{
	/**
	 *  \brief Function that identfies if the move at position index 'position' is a winning move.
	 *  
	 *  \param [in] position position index for the move on the Tic-Tac-Toe board.
	 *  \return Returns 1 (= WINNING_MOVE) if at position index 'position' there exists a winning move, else 0 (= NOT_WINNING_MOVE).
	 */
	 winSt_t isWinningMove(unsigned int position);
	/**
	 *  \brief Function that identfies if the move at position index 'position' needs to be defended against the opponent.
	 *  
	 *  \param [in] position position index for the move on the Tic-Tac-Toe board.
	 *  \return Returns 1 (= DEFENSE_MOVE) if at position index 'position' there exists a defending move, else 0 (= NOT_DEFENSE_MOVE).
	 */
	defenseSt_t isDefendingMove(unsigned int position);
	/**
	 *  \brief Function that identifies the best current move for the Computer player.
	 *  
	 *  \return returns the position index, viz. the best current move for the Computer player.
	 */
	unsigned int bestNormalMove();
public:
	/**
	 * \brief Default Constructor
	 */
	CComputer();
	/**
	 * \brief Destructor
	 */
	virtual ~CComputer();
	/**
	 *  \brief Function that must implement the move of a computer player.
	 *  
	 *  \return Return value is either 1 or 0, representing whether a game has been won or not after the move, respectively.
	 *  
	 *  \details The Computer player identifies the best move considering the winning move (isWinningMove()), defending move (isDefendingMove()) and and normal moves in the function bestNormalMove() and evaluates and retruns that move which scores the best outcome.
	 */
	bool makeMove();
};

#endif /* CCOMPUTER_H_ */
