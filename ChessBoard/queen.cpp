#include "queen.h"
#include "rook.h"
#include "bishop.h"
#include <algorithm>

Queen::Queen(Color color, int row, int col) noexcept :
    Piece{ color, row, col, 9 }
{ 
}

bool Queen::check_path(const std::vector<Piece*>& pieces, const PiecePosition& pos) const
{
    auto piecePos = get_position();
    auto pieceColor = get_color();

    return Rook{ pieceColor, piecePos.first, piecePos.second }.check_path(pieces, pos)
        || Bishop{ pieceColor, piecePos.first, piecePos.second }.check_path(pieces, pos);
}

std::vector<PiecePosition> Queen::possible_moves()
{
    std::vector<PiecePosition> tmp;
    auto pos = get_position();

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
