#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"

//  knight class declaration from piece base class
class Knight : public Piece {
public:
    Knight(Color, int row, int col) noexcept;
    std::vector<PiecePosition> possible_moves() override;
    bool check_path(const std::vector<Piece*>& pieces,
        const PiecePosition& path) const override;
private:

};

#endif