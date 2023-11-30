#ifndef QUEEN_H_
#define QUEEN_H_

#include "piece.h"

//  queen class declaration from piece base class
class Queen : public Piece {
public:
    Queen(Color, int row, int col) noexcept;
    std::vector<PiecePosition> PossibleMoves() const override;
    bool CheckPath(const std::vector<Piece*>& pieces,
        const PiecePosition& pos) const override;
private:
};

#endif