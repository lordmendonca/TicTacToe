/*
 * CBoard.h
 *
 *  Created on: 22 Nov 2021
 *      Author: JASON
 */

#ifndef CBOARD_H_
#define CBOARD_H_
/*
 * Standard header files
 */
#include <iostream>
#include <stdlib.h>
/**
 * \brief To calculate and indicate if the move made is within the board dimensions.
 * \details INVALID_INDEX	: To indicate that the move made is outside the board dimensions.
 * \details VALID_INDEX		: To indicate that the move made is within the board dimensions.
 */
typedef enum {INVALID_INDEX = -1 /**< -1 */, VALID_INDEX = 0 /**< 0 */} indexCalc_t;
/**
 * \brief Class CBoard
 */
class CBoard
{
	/**
	 * \param m_rows : Number of Rows in the board.
	 */
	unsigned short m_rows;
	/**
	 * \param m_columns : Number of Columns in the board.
	 */
	unsigned short m_columns;
	/**
	 * \param m_boardElement : An integer pointer that points to the individual position of the Board.
	 */
	unsigned short* m_boardElement;
public:
	/**
	 * \brief Default Constructor
	 */
	CBoard();
	/**
	 * \brief Destructor
	 */
	virtual ~CBoard();
	/**
	 *  \brief Set Function : To set the member attribute 'm_rows'.
	 *  \param [in] row value of 'm_rows' to be set to.
	 */
	void setRows(unsigned short rows);
	/**
	 *  \brief Set Function : To set the member attribute 'm_columns'.
	 *  \param [in] column value of 'm_columns' to be set to.
	 */
	void setColumns(unsigned short columns);
	/**
	 *  \brief Set Function : To allocate the memory and size 'size' to the array of pointer of type 'unsigned int'.
	 *  \param [in] size size of the pointer array.
	 */
	void setBoardElement(unsigned short size);
	/**
	 * \brief Get Function : To get the number of rows on the board.
	 * \return unsigned int : Value of rows on the board.
	 */
	unsigned short getRows() const;
	/**
	 * \brief Get Function : To get the number of columns on the board.
	 * \return unsigned int : Value of columns on the board.
	 */
	unsigned short getColumns() const;
	/**
	 * \brief Get Function : To get the state of the board element at given position.
	 * \param [in] position : Calculated position on the board.
	 * \return unsigned short : Board element at the given position.
	 */
	unsigned short getBoardElement(unsigned short position) const;
	/**
	 * \brief Helper Function : This method takes user provided parameters for a co-ordinate in terms of a 'row' and a 'column' and calculates the position of the placement of coin at current move.
	 * \param [in] row : user row index.
	 * \param [in] column : user column index.
	 * \return int : It either returns 'INVALID_INDEX' or calculated coin position on the board.
	 */
	int boardIndexCalc(unsigned short row, unsigned short column);
	/**
	 * \brief To set the element 'element' at the position 'position'.
	 * \param [in] position : Calculated position on the board.
	 * \param [in] element 	: object to be placed on the board at the position 'position'. 
	 */
	void placeBoardElement(int position, unsigned short element);
};

#endif /* CBOARD_H_ */
