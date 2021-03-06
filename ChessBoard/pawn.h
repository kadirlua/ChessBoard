#ifndef PAWN_H_
#define PAWN_H_

#include "piece.h"

//  pawn class declaration from piece base class
class Pawn : public Piece {
public:
    Pawn(Color, int row, int col) noexcept;
    std::vector<PiecePosition> possible_moves() override;
    bool check_path(const std::vector<Piece*>& pieces,
        const PiecePosition& path) const override;
private:
};

#endif