#include "queen.h"
#include "rook.h"
#include "bishop.h"
#include <algorithm>

Queen::Queen(Color color, int row, int col) noexcept :
    Piece{ color, row, col, 9 }
{ 
}

bool Queen::CheckPath(const std::vector<Piece*>& pieces, const PiecePosition& pos) const
{
    auto piecePos = GetPosition();
    auto pieceColor = GetColor();

    return Rook{ pieceColor, piecePos.first, piecePos.second }.CheckPath(pieces, pos)
        || Bishop{ pieceColor, piecePos.first, piecePos.second }.CheckPath(pieces, pos);
}

std::vector<PiecePosition> Queen::PossibleMoves() const
{
    std::vector<PiecePosition> tmp;
    auto pos = GetPosition();

    for(int i = 1 ; i <= pos.first ; i++){
        if(pos.first - i >= 0 && pos.second - i >= 0)
            tmp.emplace_back(pos.first - i, pos.second - i);
        if(pos.first - i >= 0 && pos.second + i <= 7)
            tmp.emplace_back(pos.first - i, pos.second + i);

    }

    for(int i = 1 ; i <= 7 - pos.first ; i++){
        if(pos.first + i <= 7 && pos.second + i <= 7)
            tmp.emplace_back(pos.first + i, pos.second + i);
        if(pos.first + i <= 7 && pos.second - i >= 0)
            tmp.emplace_back(pos.first + i, pos.second - i);

    }

    for(int i = 1 ; i <= pos.second ; i++){
        tmp.emplace_back(pos.first, pos.second - i);
    }

    for(int i = 1 ; i <= 7 - pos.second ; i++){
        tmp.emplace_back(pos.first, pos.second + i);
    }

    for(int i = 1 ; i <= pos.first ; i++){
        tmp.emplace_back(pos.first - i, pos.second );
    }

    for(int i = 1 ; i <= 7 - pos.first ; i++){
        tmp.emplace_back(pos.first + i, pos.second);
    }
    std::sort(tmp.begin(), tmp.end());
    return tmp;
}
