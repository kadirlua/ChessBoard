#include "king.h"
#include <algorithm>

King::King(Color color, int row, int col) noexcept :
    Piece{ color, row, col, 100 }
{
}

// calculate between two paths
double King::distance(const PiecePosition& path1, const PiecePosition& path2) const noexcept 
{
    double sonuc = (double)(((path2.first - path1.first) * (path2.first - path1.first)) +
        ((path2.second - path1.second) * (path2.second - path1.second)));

    return sonuc;
}

bool King::isClosertoKing(const std::vector<Piece*>& pieces, const PiecePosition& pos) const noexcept
{
    auto piecePos = get_position();

    for (size_t i = 0; i < pieces.size(); i++) {
        // the piece is our piece?
        if (pieces[i]->get_position() == piecePos) {
            continue;
        }

        for (int a = -1; a < 2; a++) {
            // row :
            for (int b = -1; b < 2; b++) {
                // column :
                if (pieces[i]->get_position() == std::make_pair(pos.first + a, pos.second + b)) {
                    //  check if it's a king instance
                    if (dynamic_cast<King*>(pieces[i]) != nullptr) {
                        return true;
                    }
                }
            }
        }

    }

    return false;
}

bool King::check_path(const std::vector<Piece*>& pieces, const PiecePosition& pos) const
{
    auto piecePos = get_position();
    auto pieceColor = get_color();

    // if the same position, return false
    if (piecePos == pos) {
        return false;
    }

    //  check the distance
    if (distance(piecePos, pos) > 2) {
        return false;
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

    if (isClosertoKing(pieces, pos)) {
        return false;
    }

    return true;
}

std::vector<PiecePosition> King::possible_moves()
{
    std::vector<PiecePosition> tmp;
    auto pos = get_position();

    if(pos.first - 1 >= 0 && pos.second - 1 >= 0)
        tmp.emplace_back(pos.first - 1 , pos.second - 1);
    if(pos.first - 1 >= 0 )
        tmp.emplace_back(pos.first - 1 , pos.second);
    if(pos.first - 1 >= 0 && pos.second + 1 <= 7)
        tmp.emplace_back(pos.first - 1 , pos.second + 1);

    if( pos.second + 1 <= 7)
        tmp.emplace_back(pos.first , pos.second + 1);
    if( pos.second - 1 >= 0)
        tmp.emplace_back(pos.first , pos.second - 1);

    if(pos.first + 1 <= 7 && pos.second - 1 >= 0)
        tmp.emplace_back(pos.first + 1 , pos.second - 1);
    if(pos.first + 1 <= 7 )
        tmp.emplace_back(pos.first + 1 , pos.second);
    if(pos.first + 1 <= 7 && pos.second + 1 <= 7)
        tmp.emplace_back(pos.first + 1 , pos.second + 1);
    std::sort(tmp.begin(), tmp.end());
    return tmp;
}