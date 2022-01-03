#include "pawn.h"
#include <algorithm>

Pawn::Pawn(Color color, int row, int col) noexcept :
    Piece{ color, row, col, 1 }
{ 
}

bool Pawn::check_path(const std::vector<Piece*>& pieces, const PiecePosition& pos) const
{
    auto piecePos = get_position();
    auto pieceColor = get_color();

    // if the same position, return false
    if (piecePos == pos)
        return false;

    int direction{1};
    int startPoint{1};

    if (pieceColor == Color::Black)
    {
        direction = -1;
        startPoint = 6;
    }

    // cannot go back
    if (direction == 1 && piecePos.first > pos.first) {
        return false;
    }
    else if (direction == -1 && piecePos.first < pos.first) {
        return false;
    }

    if ((pos != std::make_pair(piecePos.first + (1 * direction), piecePos.second))
        && !((pos == std::make_pair(piecePos.first + (2 * direction), piecePos.second)) && piecePos.first == startPoint)
        && (pos != std::make_pair(piecePos.first + (1 * direction), piecePos.second - (1 * direction)))
        && (pos != std::make_pair(piecePos.first + (1 * direction), piecePos.second + (1 * direction))))
    {
        return false;
    }

    int forwardLimit = 1;
    // if the piece is in the start point
    if (piecePos.first == startPoint) {
        forwardLimit = 2;
    }

    int dist = (pos.first - piecePos.first) * direction;

    if (forwardLimit < dist)
    {
        return false;
    }

    // moving forward
    if (pos.second == piecePos.second) {

        for (size_t i = 0; i < pieces.size(); i++) {
            if (pieces[i]->get_position() == piecePos) {
                continue;
            }
            if (pieces[i]->get_position() ==
                std::make_pair(piecePos.first + (1 * direction), piecePos.second)) {
                return false;
            }
            if (dist > 1 && pieces[i]->get_position() ==
                std::make_pair(piecePos.first + (2 * direction), piecePos.second)) {
                return false;
            }
        }
    }

    // if it goes diagonally
    if (pos == std::make_pair(piecePos.first + (1 * direction), piecePos.second - (1 * direction))) {

        // if the diagonal is full
        for (size_t i = 0; i < pieces.size(); i++) {
            if (pieces[i]->get_position() == piecePos) {
                continue;
            }
            if (pieces[i]->get_position() == std::make_pair(piecePos.first + (1 * direction), 
                piecePos.second - (1 * direction))) {
                if (pieces[i]->get_color() == pieceColor) {
                    return false;
                }
                else {
                    return true;
                }
            }
        }
    }
    else if (pos == std::make_pair(piecePos.first + (1 * direction), piecePos.second + (1 * direction))) {
        // if the diagonal is full
        for (size_t i = 0; i < pieces.size(); i++) {
            if (pieces[i]->get_position() == piecePos) {
                continue;
            }
            if (pieces[i]->get_position() == std::make_pair(piecePos.first + (1 * direction), 
                piecePos.second + (1 * direction))) {
                if (pieces[i]->get_color() == pieceColor) {
                    return false;
                }
                else {
                    return true;
                }
            }
        }
    }
    return true;
}

std::vector<PiecePosition> Pawn::possible_moves()
{
    std::vector<PiecePosition> tmp;
    auto pos = get_position();
    if(get_color() == Color::Black)
    {
        if(pos.first + 1 <= 7 && pos.second + 1 <= 7)
            tmp.emplace_back(pos.first + 1 , pos.second + 1);
        if(pos.first - 1 >= 0 && pos.second + 1 <= 7)
            tmp.emplace_back(pos.first - 1 , pos.second + 1);
    }
    else{
        if(pos.first + 1 <= 7 && pos.second -1 >= 0)
            tmp.emplace_back(pos.first + 1, pos.second - 1);
        if(pos.first - 1 >= 0 && pos.second - 1 >= 0)
            tmp.emplace_back(pos.first - 1 , pos.second - 1);
    }
    std::sort(tmp.begin(), tmp.end());
    return tmp;
}