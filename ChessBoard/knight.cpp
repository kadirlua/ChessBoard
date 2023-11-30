#include "knight.h"
#include <algorithm>

Knight::Knight(Color color, int row, int col) noexcept :
    Piece{ color, row, col, 3 }
{
}

bool Knight::CheckPath(const std::vector<Piece*>& pieces, const PiecePosition& pos) const
{
    auto piecePos = GetPosition();
    auto pieceColor = GetColor();

    // is there a piece in destination?
    for (auto* piece : pieces) {
        if (piece->GetPosition() == piecePos) {
            continue;
        }
        if (piece->GetPosition() == pos) {
            if (piece->GetColor() == pieceColor) {
                return false;
            }
        }
    }

    // if the same position, return false
    if (piecePos == pos) {
        return false;
    }

    // possible moves
    if (std::make_pair(piecePos.first - 2, piecePos.second - 1) == pos) {
        return true;
    }
    else if (std::make_pair(piecePos.first - 2, piecePos.second + 1) == pos) {
        return true;
    }
    else if (std::make_pair(piecePos.first - 1, piecePos.second - 2) == pos) {
        return true;
    }
    else if (std::make_pair(piecePos.first - 1, piecePos.second + 2) == pos) {
        return true;
    }
    else if (std::make_pair(piecePos.first + 1, piecePos.second - 2) == pos) {
        return true;
    }
    else if (std::make_pair(piecePos.first + 1, piecePos.second + 2) == pos) {
        return true;
    }
    else if (std::make_pair(piecePos.first + 2, piecePos.second - 1) == pos) {
        return true;
    }
    else if (std::make_pair(piecePos.first + 2, piecePos.second + 1) == pos) {
        return true;
    }

    return false;
}

std::vector<PiecePosition> Knight::PossibleMoves() const
{
    std::vector<PiecePosition> tmp;
    auto pos = GetPosition();

    if(pos.first - 2 >= 0 && pos.second + 1 <= 7)
        tmp.emplace_back(pos.first - 2 , pos.second + 1);
    if(pos.first - 2 >= 0 && pos.second - 1 >= 0)
        tmp.emplace_back(pos.first - 2 , pos.second - 1);
    if(pos.first - 1 >= 0 && pos.second - 2 >= 0)
        tmp.emplace_back(pos.first - 1 , pos.second - 2);
    if(pos.first - 1 >= 0 && pos.second + 2 <= 7)
        tmp.emplace_back(pos.first - 1 , pos.second + 2);
    if(pos.first + 1 <= 7 && pos.second - 2 >= 0)
        tmp.emplace_back(pos.first + 1 , pos.second - 2);
    if(pos.first + 1 <= 7 && pos.second + 2 <= 7)
        tmp.emplace_back(pos.first + 1 , pos.second + 2);
    if(pos.first + 2 <= 7 && pos.second - 1 >= 0)
        tmp.emplace_back(pos.first + 2 , pos.second - 1);
    if(pos.first + 2 <= 7 && pos.second + 1 <= 7)
        tmp.emplace_back(pos.first + 2 , pos.second + 1);
    std::sort(tmp.begin(), tmp.end());

    return tmp;
}