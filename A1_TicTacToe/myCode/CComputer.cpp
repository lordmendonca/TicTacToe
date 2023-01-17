/*
 * CComputer.cpp
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
#include "CComputer.h"

CComputer::CComputer()
{
	/* Nothing to initialize. */
}

CComputer::~CComputer()
{
	/* Nothing to destruct. */
}

winSt_t CComputer::isWinningMove(unsigned int position)
{
	if(m_boardPtr->getBoardElement(position) == EMPTY_FIELD)
		{
			m_boardPtr->placeBoardElement(position, element); /* Place the current player's coin at the given position index */
			if(GAME_WON == m_boardPtr->checkWin())
			{
				m_boardPtr->placeBoardElement(position, EMPTY_FIELD); /* Winning move found but undo the move. */
				return WINNING_MOVE; /* Winning move exists. */
			}
			else
				m_boardPtr->placeBoardElement(position, EMPTY_FIELD); /* Undo the move anyway. */
		}
	return NOT_WINNING_MOVE; /* Winning move does not exists. */
}

defenseSt_t CComputer::isDefendingMove(unsigned int position)
{
	unsigned short opponent = (element + 1) % 2; /* Calculating the integer value of the opponent player's coin element. */
	if(m_boardPtr->getBoardElement(position) == EMPTY_FIELD)
	{
		m_boardPtr->placeBoardElement(position, opponent); /* Place the opponent player's coin at the given position index */
		if(GAME_WON == m_boardPtr->checkWin())
		{
			m_boardPtr->placeBoardElement(position, EMPTY_FIELD); /* Defending move found but undo the move. */
			return DEFENSE_MOVE; /* Defending move against the opponent exists. */
		}
		else
			m_boardPtr->placeBoardElement(position, EMPTY_FIELD); /* Undo the move anyway. */
		}
	return NOT_DEFENSE_MOVE; /* Defending move against the opponent does not exists. */
}

unsigned int CComputer::bestNormalMove()
{
	unsigned int opponent = (element + 1) % 2;
	/* The local variable 'score' is  used to find the weight of the move at any position on the board by the current player. */
	unsigned int score[TTT_SIZE];
	for(unsigned int i = 0; i < TTT_SIZE; i++)
		score[i] = 0;	/* Initialization. */

	/*
	 * Award a score +100 if the move found is a winning move.
	 * Award a score +50 if the move found is a defending move.
	 * Award scores +5, +3 and +2 for moves at center, corners and edges of the board respectively.
	 * The scoring is in the sense of priority of the move to be taken at the current move.
	 * The descending order of the scoring is also the descending order of the strongest moves in the game.
	 * The highest total score at any position is considered to be the best possible move.
	 */
	for(unsigned int position = 0; position < TTT_SIZE; position++)
	{
		if(m_boardPtr->getBoardElement(position) == EMPTY_FIELD)
		{
			if(WINNING_MOVE == isWinningMove(position))
			{
				score[position] = score[position] + 100;
			}

			else if(DEFENSE_MOVE == isDefendingMove(position))
			{
				score[position] = score[position] + 50;
			}

			else if(CENTER == position)
			{
				score[position] = score[position] + 5;
			}
			else if(CORNERS == (position%2))
			{
				score[position] = score[position] + 3;
				/* Placement of the coin is cyclic in nature for the computer. The moves around corners are prioritized as 0, 2, 6 and 8, in ascending order, on the board by default. */
				/* As the placement of the coin is cyclic, position 0 always has the highest priority. */
				/* With this assumption, the blind spots for positions 2, 6 and 8 are positions 5, 7 and 3, respectively. */
				/* However, position 3 is ruled out as blind-spot for position 8 since it is not for position 0, which currently has highest priority. */
				/* Therefore, prioritize the moves among positions 2 and 6 w.r.t. position 0 at the corners. */
				/* Priority can be set by identifying the if the opponent has placed the coin in the blind-spot in the previous move. */
				/* If coin is placed by opponent at position 5, current player must place coin at position 2. */
				/* If coin is placed by opponent at position 7, current player must place coin at position 6. */
				/* Award an additional score of +1 when such a move exists. */
				/* therefore, only these two such cases are written. */
				if(2 == position)
				{
					if(m_boardPtr->getBoardElement(5) == opponent)
						score[position] = score[position] + 1;
				}
				else if(6 == position)
				{
					if(m_boardPtr->getBoardElement(7) == opponent)
						score[position] = score[position] + 1;
				}
			}
			else if(EDGES == (position%2))
			{
				score[position] = score[position] + 2;
				/* Corners are weighed heavier than edges in the game. The placement of coins at corners or edges are cyclic in nature. */
				/* However, there exist two scenarios wherein edges prioritize over corners. */
				/* The edges take precedence when opponent coin is either placed at position 6 or position 8. */
				/* If coin is placed by opponent at position 8, current player must place coin at position 5. */
				/* If coin is placed by opponent at position 6, current player must place coin at position 7. */
				/* Award an additional score of +2 such that it exceeds the awarded score of +3 for the corners, when such a move exists. */
				/* therefore, only these two such cases are written. */
				if(5 == position)
				{
					if(m_boardPtr->getBoardElement(8) == opponent)
						score[position] = score[position] + 2;
				}
				else if(7 == position)
				{
					if(m_boardPtr->getBoardElement(6) == opponent)
						score[position] = score[position] + 2;
				}
			}
		}

	}
	/* local copy of score[TTT_SIZE] in order to find the highest score. */
	unsigned int scoreCompare[TTT_SIZE];
	for(unsigned int position = 0; position < TTT_SIZE; position++)
		scoreCompare[position] = score[position];
	/* Move the largest score to the last position of the array. */
	for(unsigned int position = 0, temp = 0; position < TTT_SIZE - 1; position++)
	{
		if(scoreCompare[position] > scoreCompare[position+1])
		{
			temp = scoreCompare[position+1];
			scoreCompare[position+1] = scoreCompare[position];
			scoreCompare[position] =  temp;
		}
	}
	/* Return variable that returns the position on the board for which the best move, viz. the highest weighed score, has been found. */
	unsigned int maxScoreAt = 0;
	/* Finding the highest score in the score[TTT_SIZE]. */ 
	for(unsigned int position = 0; position < TTT_SIZE; position++)
	{
		if(scoreCompare[LAST_POSITION] == score[position])
		{
			maxScoreAt = position; /*Position for the best move found. */
			break;
		}
	}
	/*return the best move which is already in terms of linearized position on the board. */
	return maxScoreAt;
}

bool CComputer::makeMove()
{
	/* Player status. */
	std::cout << "COMPUTER having coin " << (char)((element == PLAYER_1)?ELEMENT_x:ELEMENT_o) << std::endl;
	
	m_boardPtr->placeBoardElement(bestNormalMove(), element); /* The best move is made at the returned best normal move. */
	element = (element + 1) % 2; /* Switch the player. */
	return m_boardPtr->checkWin(); /* returns 1 if winner was found, else 0, after the current move. */
}
