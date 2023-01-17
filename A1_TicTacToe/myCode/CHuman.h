/*
 * CHuman.h
 *
 *  Created on: 27 Nov 2021
 *      Author: JASON
 */

#ifndef CHUMAN_H_
#define CHUMAN_H_
/*
 * Project specific header files
 */
#include "CPlayer.h"
/**
 * \brief Describes type of entry by the human player.
 * \details INCORRECT_ENTRY	: Represented by '0' to indicate that invalid entry by the human player.
 * \details CORRECT_ENTRY	: Represented by '1' to indicate a valid entry by the human player.
 * \details TERMINATE_GAME	: Represented by '9' to acknowledge that player wants to terminate the game.
 */
typedef enum {INCORRECT_ENTRY = 0 /**< 0 */, CORRECT_ENTRY = 1 /**< 1 */, TERMINATE_GAME = 9 /**< 9 */} humanEntry_t;

/**
 * \brief Class CHuman derived from Class CPlayer
 */
class CHuman: public CPlayer
{
public:
	/**
	 * \brief Default Constructor
	 */
	CHuman();
	/**
	 * \brief Destructor
	 */
	virtual ~CHuman();
	/**
	 *  \brief Function that must implement the move of a human player.
	 *  
	 *  \return Return value is either 1 or 0, representing whether a game has been won or not after the move, respectively.
	 *  
	 *  \details The human player is allowed to enter the valid coin position through input of row and column indices. The human player can also terminate the game at any point of time.
	 */
	bool makeMove();
};

#endif /* CHUMAN_H_ */
