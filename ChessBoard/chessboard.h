#ifndef CHESSBOARD_H_
#define CHESSBOARD_H_

#include <string>
#include <vector>

class Piece;	//incomplete type declaration

class ChessBoard {
public:
	ChessBoard() = default;	// default constructor
	virtual ~ChessBoard();	// destructor
	// load from file
	void ReadFromFile(const std::string& fileName);
	// create pieces for chess board
	void LoadBoard();

	// return total white points
	double CalculateWhitePoints() const;
	// return total black points
	double CalculateBlackPoints() const;
private:
	std::vector<std::string> m_piecePositions;
	std::vector<Piece*> m_pieces;
};

#endif