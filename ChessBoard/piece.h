#ifndef PIECE_H_
#define PIECE_H_

#include <utility>
#include <vector>

//  piece color (white and black)
enum class Color{
    White,
    Black
};

//  piece position (x and y coordinates)
using PiecePosition = std::pair<int, int>;

//  piece class declaration
class Piece {
public:
    explicit Piece(Color, int row, int col, double);   // constructor
	virtual ~Piece() = default;

    //  get piece position in x and y coordinates
    PiecePosition GetPosition() const {
        return m_position;
    }

    //  set piece position
    void SetPosition(PiecePosition pos);

    //  get piece color white or black
    Color GetColor() const {
        return m_color;
    }

    //  set piece color
    void SetColor(Color color);

    //  get piece point
    double GetPoint() const {
        return m_point;
    }

    //  check a piece for destination path which is in danger or not
    virtual bool CheckPath(const std::vector<Piece*>& pieces,
        const PiecePosition& path) const = 0;

    //  possible moves for a piece
    virtual std::vector<PiecePosition> PossibleMoves() = 0;
private:
    Color m_color;  // piece color
    PiecePosition m_position;   // piece position in x and y coordinates
    double m_point; // piece point
};

#endif