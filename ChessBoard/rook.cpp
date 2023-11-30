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
        for (auto* piece : pieces) {
            if (piece->GetPosition() == piecePos) {
                continue;
            }

            if (pos.second < piecePos.second) {
                // goes left:
                if (piece->GetPosition().first == piecePos.first &&
					piece->GetPosition().second < piecePos.second) {
                    if (pos.second < piece->GetPosition().second) {
                        // there is a piece
                        return false;
                    }
                }
            }
            else {
                // right move
                if (piece->GetPosition().first == piecePos.first &&
					piece->GetPosition().second > piecePos.second) {
                    if (pos.second > piece->GetPosition().second) {
                        // there is a piece
                        return false;
                    }
                }
            }
        }
    }
    else if (pos.second == piecePos.second) {
        // moves up/down
        for (auto* piece : pieces) {
            if (piece->GetPosition() == piecePos) {
                continue;
            }
            if (pos.first < piecePos.first) {
                // moves up:
                if (piece->GetPosition().first > pos.first
                    && piece->GetPosition().second == pos.second
                    && piecePos.first > piece->GetPosition().first) {
                    // there is a piece
                    return false;
                }
            }
            else {
                // moves down
                if (piece->GetPosition().first < pos.first
                    && piece->GetPosition().first > piecePos.first
                    && pos.second == piece->GetPosition().second) {
                    // there is a piece
                    return false;
                }
            }
        }
    }

    // if there is the same team in destination, return false
    for (auto* piece : pieces) {
        if (piece->GetPosition() == piecePos) {
            continue;
        }
        if (piece->GetPosition() == pos) {
            if (pieceColor == piece->GetColor()) {
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