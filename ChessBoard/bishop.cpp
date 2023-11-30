#include "bishop.h"
#include <algorithm>

Bishop::Bishop(Color color, int row, int col) noexcept :
    Piece{ color, row, col, 3 }
{
}

bool Bishop::CheckPath(const std::vector<Piece*>& pieces, const PiecePosition& pos) const
{
    auto piecePos = GetPosition();
    auto pieceColor = GetColor();

    // if the same position, return false
    if (piecePos == pos) {
        return false;
    }

    // check if there is a piece in destination :
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

    // x decrease : left or right up
    if (piecePos.first - pos.first > 0) {
        if (piecePos.second - pos.second > 0) {
            // go to left up.
            if ((piecePos.first - pos.first != piecePos.second - pos.second)) {
                return false;
            }
            for (int i = piecePos.first - 1, j = piecePos.second - 1; i > pos.first; i--, j--) {
                for (auto* piece : pieces) {
                    if (piece->GetPosition() == std::make_pair(i, j)) {
                        return false;
                    }
                }
            }
        }
        else {
            // go to right up.
            if ((pos.first - piecePos.first != piecePos.second - pos.second)) {
                return false;
            }
            for (int i = piecePos.first - 1, j = piecePos.second + 1; i > pos.first; i--, j++) {
                for (auto* piece : pieces) {
                    if (piece->GetPosition() == std::make_pair(i, j)) {
                        return false;
                    }
                }
            }
        }
    }
    else {
        // x increases : left or right down
        if (piecePos.second - pos.second > 0) {
            // go to left down.

            if ((piecePos.first - pos.first != pos.second - piecePos.second)) {
                return false;
            }

            for (int i = piecePos.first + 1, j = piecePos.second - 1; i < pos.first; i++, j--) {
                for (auto* piece : pieces) {
                    if (piece->GetPosition() == std::make_pair(i, j)) {
                        return false;
                    }
                }
            }
        }
        else {
            // go to right down.
            if ((piecePos.first - pos.first != piecePos.second - pos.second)) {
                return false;
            }
            for (int i = piecePos.first + 1, j = piecePos.second + 1; i < pos.first; i++, j++) {
                for (auto* piece : pieces) {
                    if (piece->GetPosition() == std::make_pair(i, j)) {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

std::vector<PiecePosition> Bishop::PossibleMoves() const
{
    std::vector<PiecePosition> tmp;
    auto pos = GetPosition();

    for (int i = 1 ; i <= pos.first ; i++) {
        if (pos.first - i >= 0 && pos.second - i >= 0) {
			tmp.emplace_back(pos.first - i, pos.second - i);
		}
        if (pos.first - i >= 0 && pos.second + i <= 7) {
			tmp.emplace_back(pos.first - i, pos.second + i);
		}
    }

    for (int i = 1 ; i <= 7 - pos.first ; i++){
        if (pos.first + i <= 7 && pos.second + i <= 7) {
			tmp.emplace_back(pos.first + i, pos.second + i);
		}
        if (pos.first + i <= 7 && pos.second - i >= 0) {
			tmp.emplace_back(pos.first + i, pos.second - i);
		}
    }
    std::sort(tmp.begin(), tmp.end());
    return tmp;
}