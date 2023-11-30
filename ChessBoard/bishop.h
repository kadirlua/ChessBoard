#ifndef BISHOP_H_
#define BISHOP_H_

#include "piece.h"

//  bishop class declaration from piece base class
class Bishop : public Piece {
public:
    Bishop(Color, int row, int col) noexcept;
    std::vector<PiecePosition> PossibleMoves() const override;
    bool CheckPath(const std::vector<Piece*>& pieces,
        const PiecePosition& pos) const override;
private:
};

#endif