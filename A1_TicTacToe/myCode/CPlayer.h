/*
 * CPlayer.h
 *
 *  Created on: 27 Nov 2021
 *      Author: JASON
 */

#ifndef CPLAYER_H_
#define CPLAYER_H_
/*
 * Project specific header files
 */
#include "CTicTacToeBoard.h"
/**
 * \brief Class CPlayer
 */
class CPlayer
{
protected:
	/**
	 *  \param m_boardPtr : A pointer to the class object of type 'CTicTacToeBoard'.
	 */
	CTicTacToeBoard* m_boardPtr;
	/**
	 *  \param element : A static member attribute that has the user's coin's integer representation.
	 *  \details As a static variable, it will hold the same value across any function and any class that has been derived from this class, where it is accessed to play the game. It will hold 0 (= 'x') and 1 (= 'o') in alternate rounds.
	 */
	static unsigned short element;
public:
	/**
	 * \brief Default Constructor
	 */
	CPlayer();
	/**
	 * \brief Destructor
	 */
	virtual ~CPlayer();
	/**
	 *  \brief Set Function : To set the address of the object pointer of type 'CTicTacToeBoard'.
	 *  
	 *  \param [in] boardPtr Pointer to the object of type 'CTicTacToeBoard'. 
	 */
	void setBoardPtr(CTicTacToeBoard* boardPtr);
	/**
	 *  \brief Function that must implement the move of a player.
	 *  
	 *  \return Return value is either 1 or 0, representing whether a game has been won or not, respectively.
	 *  
	 *  \details This is a pure virtual function. It's implementation can be found only in the derived class/classes.
	 */
	virtual bool makeMove() = 0;
};

#endif /* CPLAYER_H_ */
