#ifndef KING_H_
#define KING_H_

#include "piece.h"

//  king class declaration from piece base class
class King : public Piece {
public:
    King(Color, int row, int col) noexcept;
    std::vector<PiecePosition> PossibleMoves() const override;
    bool CheckPath(const std::vector<Piece*>& pieces,
        const PiecePosition& pos) const override;
private:
    double distance(const PiecePosition& path1, const PiecePosition& path2) const noexcept;
    bool isClosertoKing(const std::vector<Piece*>& pieces, const PiecePosition& pos) const noexcept;
};

#endif