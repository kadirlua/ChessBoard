#include "piece.h"

Piece::Piece(Color color , int row, int col, double point) :
    m_color{ color },
    m_position{ std::make_pair(row, col) },
    m_point{ point }
{
}

void Piece::SetPosition(PiecePosition pos)
{
    m_position = pos;
}

void Piece::SetColor(Color color)
{
    m_color = color;
}
