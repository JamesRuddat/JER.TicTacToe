#pragma once

class TicTacToe
{
private:
	char m_board[9] {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
	int m_numTurns = 0;
	char m_playerTurn = 'x';
	char m_winner = ' ';

public:
	void DisplayBoard()
	{
		std::cout << m_board[0] << "|" << m_board[1] << "|" << m_board[2] << "\n"
			<< "------" << "\n"
			<< m_board[3] << "|" << m_board[4] << "|" << m_board[5] << "\n"
			<< "------" << "\n"
			<< m_board[6] << "|" << m_board[7] << "|" << m_board[8] << "\n";
	}

	bool IsOver()
	{
		if (m_numTurns == 9) return true;
		else if (m_board[0] && m_board[1] && m_board[2] == 'x') {
			m_winner = 'x';
			return true;
		}
		else if (m_board[3] && m_board[4] && m_board[5] == 'x') {
			m_winner = 'x';
			return true;
		}
		else if (m_board[6] && m_board[7] && m_board[8] == 'x') {
			m_winner = 'x';
			return true;
		}
		else if (m_board[0] && m_board[4] && m_board[8] == 'x') {
			m_winner = 'x';
			return true;
		}
		else if (m_board[2] && m_board[4] && m_board[6] == 'x') {
			m_winner = 'x';
			return true;
		}
		else if (m_board[0] && m_board[1] && m_board[2] == 'o') {
			m_winner = 'o';
			return true;
		}
		else if (m_board[3] && m_board[4] && m_board[5] == 'o') {
			m_winner = 'o';
			return true;
		}
		else if (m_board[6] && m_board[7] && m_board[8] == 'o') {
			m_winner = 'o';
			return true;
		}
		else if (m_board[0] && m_board[4] && m_board[8] == 'o') {
			m_winner = 'o';
			return true;
		}
		else if (m_board[2] && m_board[4] && m_board[6] == 'o') {
			m_winner = 'o';
			return true;
		}
		else return false;
	}

	char GetPlayerTurn()
	{
		return m_playerTurn;
	}

	bool IsValidMove(int position)
	{
		if (m_board[position - 1] == ' ') return true; //offset from 0
		else return false;
	}

	void Move(int position)
	{
		m_board[position - 1] = m_playerTurn; //offset from 0
		m_numTurns++;
		if (m_playerTurn == 'x') m_playerTurn = 'o';
		else m_playerTurn = 'x';
	}

	void DisplayResult()
	{
		if (m_numTurns == 9 || m_winner == ' ') std::cout << "The game is a tie.\n" << "\n";
		if (m_winner != ' ') std::cout << "The winner is " << m_playerTurn << "\n";
	}
};