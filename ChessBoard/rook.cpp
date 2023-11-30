#include "rook.h"
#include <algorithm>

Rook::Rook(Color color, int row, int col) noexcept :
    Piece{ color, row, col, 5 }
{ 
}

bool Rook::CheckPath(const std::vector<Piece*>& pieces, const PiecePosition& pos) const
{
    auto piecePos = GetPosition();
    auto pieceColor = GetColor();

    if (piecePos == pos) {
        return false;
    }

    // check left, right, up, down positions
    if (pos.first != piecePos.first && pos.second != piecePos.second) {
        return false;
    }

    if (pos.first == piecePos.first) {
        // moves right/left
        for (size_t i = 0; i < pieces.size(); i++) {
            if (pieces[i]->GetPosition() == piecePos) {
                continue;
            }

            if (pos.second < piecePos.second) {
                // goes left:
                if (pieces[i]->GetPosition().first == piecePos.first &&
					pieces[i]->GetPosition().second < piecePos.second) {
                    
                    if (pos.second < pieces[i]->GetPosition().second) {
                        // there is a piece
                        return false;
                    }

                }

            }
            else {
                // right move
                if (pieces[i]->GetPosition().first == piecePos.first &&
					pieces[i]->GetPosition().second > piecePos.second) {
                    
                    if (pos.second > pieces[i]->GetPosition().second) {
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
            if (pieces[i]->GetPosition() == piecePos) {
                continue;
            }

            if (pos.first < piecePos.first) {
                // moves up:
                if (pieces[i]->GetPosition().first > pos.first
                    && pieces[i]->GetPosition().second == pos.second
                    && piecePos.first > pieces[i]->GetPosition().first) {
                    // there is a piece
                    return false;
                }
            }
            else {
                // moves down

                if (pieces[i]->GetPosition().first < pos.first
                    && pieces[i]->GetPosition().first > piecePos.first
                    && pos.second == pieces[i]->GetPosition().second) {
                    // there is a piece
                    return false;
                }
            }
        }
    }

    // if there is the same team in destination, return false
    for (size_t k = 0; k < pieces.size(); k++) {
        if (pieces[k]->GetPosition() == piecePos) {
            continue;
        }
        if (pieces[k]->GetPosition() == pos) {
            if (pieceColor == pieces[k]->GetColor()) {
                return false;
            }
        }
    }

    return true;
}

std::vector<PiecePosition> Rook::PossibleMoves() const
{
    std::vector<PiecePosition> tmp;
    auto pos = GetPosition();

    for (int i = 1; i <= pos.second; i++) {
        tmp.emplace_back(pos.first, pos.second - i);
    }

    for (int i = 1; i <= 7 - pos.second; i++) {
        tmp.emplace_back(pos.first, pos.second + i);
    }

    for (int i = 1; i <= pos.first; i++) {
        tmp.emplace_back(pos.first - i, pos.second );
    }

    for (int i = 1; i <= 7 - pos.first; i++) {
        tmp.emplace_back(pos.first + i, pos.second);
    }
    std::sort(tmp.begin(), tmp.end());
    return tmp;
}