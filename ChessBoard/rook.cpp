#include "rook.h"
#include <algorithm>

Rook::Rook(Color color, int row, int col) noexcept :
    Piece{ color, row, col, 5 }
{ 
}

bool Rook::check_path(const std::vector<Piece*>& pieces, const PiecePosition& pos) const
{
    auto piecePos = get_position();
    auto pieceColor = get_color();

    if (piecePos == pos) {
        return false;
    }

    // check left, right, up, down positions
    if (!(pos.first == piecePos.first || pos.second == piecePos.second)) {
        return false;
    }

    if (pos.first == piecePos.first) {
        // moves right/left

        for (size_t i = 0; i < pieces.size(); i++) {
            if (pieces[i]->get_position() == piecePos) {
                continue;
            }

            if (pos.second < piecePos.second) {
                // goes left:

                if (pieces[i]->get_position().first == piecePos.first && 
                    pieces[i]->get_position().second < piecePos.second) {
                    
                    if (pos.second < pieces[i]->get_position().second) {
                        // there is a piece
                        return false;
                    }

                }

            }
            else {
                // right move

                if (pieces[i]->get_position().first == piecePos.first && 
                    pieces[i]->get_position().second > piecePos.second) {
                    
                    if (pos.second > pieces[i]->get_position().second) {
                        // there is a piece
                        return false;
                    }

                }

            }
        }

    }
    else if (pos.second == piecePos.second) {
        // moves up/down

        for (size_t i = 0; i < pieces.size(); i++) {
            if (pieces[i]->get_position() == piecePos) {
                continue;
            }

            if (pos.first < piecePos.first) {
                // moves up:

                if (pieces[i]->get_position().first > pos.first
                    && pieces[i]->get_position().second == pos.second
                    && piecePos.first > pieces[i]->get_position().first) {
                    // there is a piece
                    return false;
                }
            }
            else {
                // moves down

                if (pieces[i]->get_position().first < pos.first
                    && pieces[i]->get_position().first > piecePos.first
                    && pos.second == pieces[i]->get_position().second) {
                    // there is a piece
                    return false;
                }
            }
        }
    }

    // if there is the same team in destination, return false
    for (size_t k = 0; k < pieces.size(); k++) {
        if (pieces[k]->get_position() == piecePos) {
            continue;
        }
        if (pieces[k]->get_position() == pos) {
            if (pieceColor == pieces[k]->get_color()) {
                return false;
            }
        }
    }

    return true;
}

std::vector<PiecePosition> Rook::possible_moves()
{
    std::vector<PiecePosition> tmp;
    auto pos = get_position();

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