#ifndef PAWN_H_
#define PAWN_H_

#include "piece.h"

//  pawn class declaration from piece base class
class Pawn : public Piece {
public:
    Pawn(Color, int row, int col) noexcept;
    std::vector<PiecePosition> PossibleMoves() const override;
    bool CheckPath(const std::vector<Piece*>& pieces,
        const PiecePosition& pos) const override;
};

#endif