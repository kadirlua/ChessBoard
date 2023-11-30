#include "chessboard.h"
#include "pawn.h"
#include "bishop.h"
#include "rook.h"
#include "king.h"
#include "knight.h"
#include "queen.h"

#include <iostream>
#include <fstream>
#include <algorithm>

ChessBoard::~ChessBoard() {

    // release white and black pieces from memory
    for (auto elem : m_pieces)
        delete elem;
}

void ChessBoard::read_from_file(const std::string& fileName) {
    std::ifstream fileStream;
    std::string lines;

    fileStream.open(fileName);
    while (fileStream >> lines)
        piecePositions.push_back(lines);
}

double ChessBoard::calculate_white_points() const
{
    double total{};

    std::vector<Piece*> white_pieces, black_pieces;

    std::copy_if(m_pieces.begin(), m_pieces.end(), std::back_inserter(white_pieces),
        [](const Piece* piece) {
            return piece->GetColor() == Color::White;
        });

    std::copy_if(m_pieces.begin(), m_pieces.end(), std::back_inserter(black_pieces),
        [](const Piece* piece) {
            return piece->GetColor() == Color::Black;
        });

    for (const auto& elem : white_pieces)
    {
        bool isinDanger{};

        auto whitePos = elem->GetPosition();

        for (const auto& blackPiece : black_pieces)
        {
            auto blackPos = blackPiece->GetPosition();
            auto blackPossibleMoves = blackPiece->PossibleMoves();

            auto found = std::find(blackPossibleMoves.cbegin(), blackPossibleMoves.cend(), whitePos);

            if (found != blackPossibleMoves.cend())
            {
                // check if it is in danger
                if (blackPiece->CheckPath(m_pieces, whitePos))
                {
                    isinDanger = true;
                    break;
                }
            }
        }

        if (isinDanger)
            total += elem->GetPoint() / 2;
        else
            total += elem->GetPoint();
    }
    return total;
}

double ChessBoard::calculate_black_points() const
{
    double total{};

    std::vector<Piece*> white_pieces, black_pieces;

    std::copy_if(m_pieces.begin(), m_pieces.end(), std::back_inserter(white_pieces), 
        [](const Piece* piece) {
            return piece->GetColor() == Color::White;
        });

    std::copy_if(m_pieces.begin(), m_pieces.end(), std::back_inserter(black_pieces), 
        [](const Piece* piece) {
            return piece->GetColor() == Color::Black;
        });

    for (const auto& elem : black_pieces) 
    {
        bool isinDanger{};

        auto blackPos = elem->GetPosition();

        for (const auto& whitePiece : white_pieces)
        {
            auto whitePos = whitePiece->GetPosition();
            auto whitePossibleMoves = whitePiece->PossibleMoves();

            auto found = std::find(whitePossibleMoves.cbegin(), whitePossibleMoves.cend(), blackPos);

            if (found != whitePossibleMoves.cend())
            {
                // check if it is in danger
                if (whitePiece->CheckPath(m_pieces, blackPos))
                {
                    isinDanger = true;
                    break;
                }
            }
        }

        if (isinDanger)
            total += elem->GetPoint() / 2;
        else
            total += elem->GetPoint();
    }
    return total;
}

void ChessBoard::load_board() {

    for (int i = 0; i < (int)piecePositions.size(); i++)
    {
        int column = i % 8;
        int row = i / 8;

        if (piecePositions[i] == "ps") {
            m_pieces.push_back(new Pawn{ Color::Black, row, column });
        }
        else if (piecePositions[i] == "as") {
            m_pieces.push_back(new Knight{ Color::Black, row, column });
        }
        else if (piecePositions[i] == "fs") {
            m_pieces.push_back(new Bishop{ Color::Black, row, column });
        }
        else if (piecePositions[i] == "ks") {
            m_pieces.push_back(new Rook{ Color::Black, row, column });
        }
        else if (piecePositions[i] == "vs") {
            m_pieces.push_back(new Queen{ Color::Black, row, column });
        }
        else if (piecePositions[i] == "ss") {
            m_pieces.push_back(new King{ Color::Black, row, column });
        }
        else if (piecePositions[i] == "pb") {
            m_pieces.push_back(new Pawn{ Color::White, row, column });
        }
        else if (piecePositions[i] == "ab") {
            m_pieces.push_back(new Knight{ Color::White, row, column });
        }
        else if (piecePositions[i] == "fb") {
            m_pieces.push_back(new Bishop{ Color::White, row, column });
        }
        else if (piecePositions[i] == "kb") {
            m_pieces.push_back(new Rook{ Color::White, row, column });
        }
        else if (piecePositions[i] == "vb") {
            m_pieces.push_back(new Queen{ Color::White, row, column });
        }
        else if (piecePositions[i] == "sb") {
            m_pieces.push_back(new King{ Color::White, row, column });
        }
    }
}