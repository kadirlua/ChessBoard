#ifndef QUEEN_H_
#define QUEEN_H_

#include "piece.h"

//  queen class declaration from piece base class
class Queen : public Piece {
public:
    Queen(Color, int row, int col) noexcept;
    std::vector<PiecePosition> possible_moves() override;
    bool check_path(const std::vector<Piece*>& pieces,
        const PiecePosition& path) const override;
private:
};

#endif