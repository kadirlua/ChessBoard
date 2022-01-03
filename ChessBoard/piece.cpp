#include "piece.h"

Piece::Piece(Color color , int row, int col, double point) :
    m_color{ color },
    m_position{ std::make_pair(row, col) },
    m_point{ point }
{
}

void Piece::set_position(PiecePosition pos)
{
    m_position = pos;
}

void Piece::set_color(Color color)
{
    m_color = color;
}
