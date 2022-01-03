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
	void read_from_file(const std::string&);
	// create pieces for chess board
	void load_board();

	// return total white points
	double calculate_white_points() const;
	// return total black points
	double calculate_black_points() const;
private:
	std::vector<std::string> piecePositions;
	std::vector<Piece*> m_pieces;
};

#endif