/*
 * CScreen.h
 *
 *  Created on: 3 Dec 2021
 *      Author: JASON
 */

#ifndef CSCREEN_H_
#define CSCREEN_H_
/*
 * Project specific header files
 */
#include "CTicTacToeBoard.h"
/**
 * \brief Class CScreen
 */
class CScreen
{
protected:
	/**
	 * \param m_boardPtr	: A pointer to the class object of type 'CTicTacToeBoard'.
	 */
	CTicTacToeBoard* m_boardPtr;
public:
    /**
	 * \brief Parameterized Constructor
	 * \param boardPtr : A pointer argument type 'CTicTacToeBoard'.
	 */
	CScreen();
	/**
	 * \brief Destructor
	 */
	virtual ~CScreen();
	/**
	 *  \brief Set Function : To set the address of the object pointer of type 'CTicTacToeBoard'.
	 *  
	 *  \param [in] boardPtr Pointer to the object of type 'CTicTacToeBoard'. 
	 */
	void setBoardPtr(CTicTacToeBoard* boardPtr);
    /**
	 * \brief This is a pure virtual function. It's implementation can be found only in the derived class/classes.
	 */
	virtual void printScreen() = 0;
};

#endif /* CSCREEN_H_ */
