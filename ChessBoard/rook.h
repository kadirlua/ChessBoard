#ifndef ROOK_H_
#define ROOK_H_

#include "piece.h"

//  rook class declaration from piece base class
class Rook : public Piece {
public:
    Rook(Color, int row, int col) noexcept;
    std::vector<PiecePosition> possible_moves() override;
    bool check_path(const std::vector<Piece*>& pieces,
        const PiecePosition& path) const override;
private:
};

#endif