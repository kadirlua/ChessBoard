#ifndef BISHOP_H_
#define BISHOP_H_

#include "piece.h"

//  bishop class declaration from piece base class
class Bishop : public Piece {
public:
    Bishop(Color, int row, int col) noexcept;
    std::vector<PiecePosition> possible_moves() override;
    bool check_path(const std::vector<Piece*>& pieces,
        const PiecePosition& path) const override;
private:
};

#endif