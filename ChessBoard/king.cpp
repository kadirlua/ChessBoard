#include "king.h"
#include <algorithm>

King::King(Color color, int row, int col) noexcept :
    Piece{ color, row, col, 100 }
{
}

// calculate between two paths
double King::Distance(const PiecePosition& path1, const PiecePosition& path2) const noexcept
{
    double result = (double)(((path2.first - path1.first) * (path2.first - path1.first)) +
        ((path2.second - path1.second) * (path2.second - path1.second)));

    return result;
}

bool King::isClosertoKing(const std::vector<Piece*>& pieces, const PiecePosition& pos) const noexcept
{
    auto piecePos = GetPosition();

    for (auto* piece : pieces) {
        // the piece is our piece?
        if (piece->GetPosition() == piecePos) {
            continue;
        }

        for (int a = -1; a < 2; a++) {
            // row :
            for (int b = -1; b < 2; b++) {
                // column :
                if (piece->GetPosition() == std::make_pair(pos.first + a, pos.second + b)) {
                    //  check if it's a king instance
                    if (dynamic_cast<King*>(piece) != nullptr) {
                        return true;
                    }
                }
            }
        }

    }

    return false;
}

bool King::CheckPath(const std::vector<Piece*>& pieces, const PiecePosition& pos) const
{
    auto piecePos = GetPosition();
    auto pieceColor = GetColor();

    // if the same position, return false
    if (piecePos == pos) {
        return false;
    }

    //  check the Distance
    if (Distance(piecePos, pos) > 2) {
        return false;
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

    if (isClosertoKing(pieces, pos)) {
        return false;
    }

    return true;
}

std::vector<PiecePosition> King::PossibleMoves() const
{
    std::vector<PiecePosition> tmp;
    auto pos = GetPosition();

    if (pos.first - 1 >= 0 && pos.second - 1 >= 0) {
		tmp.emplace_back(pos.first - 1 , pos.second - 1);
	}
    if (pos.first - 1 >= 0) {
		tmp.emplace_back(pos.first - 1 , pos.second);
	}
    if (pos.first - 1 >= 0 && pos.second + 1 <= 7) {
		tmp.emplace_back(pos.first - 1 , pos.second + 1);
	}

    if (pos.second + 1 <= 7) {
		tmp.emplace_back(pos.first , pos.second + 1);
	}
    if (pos.second - 1 >= 0) {
		tmp.emplace_back(pos.first , pos.second - 1);
	}

    if (pos.first + 1 <= 7 && pos.second - 1 >= 0) {
		tmp.emplace_back(pos.first + 1 , pos.second - 1);
	}
    if (pos.first + 1 <= 7) {
		tmp.emplace_back(pos.first + 1 , pos.second);
	}
    if (pos.first + 1 <= 7 && pos.second + 1 <= 7) {
		tmp.emplace_back(pos.first + 1 , pos.second + 1);
	}
    std::sort(tmp.begin(), tmp.end());
    return tmp;
}