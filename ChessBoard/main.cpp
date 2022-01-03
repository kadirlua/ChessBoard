// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "chessboard.h"

int main()
{
    // iterate each file in for loop
    for (int i = 1; i <= 3; i++)
    {
        //  get filename
        std::string filename{"board"};
        filename.append(std::to_string(i));
        filename.append(".txt");

        ChessBoard chess;    // create an instance of a chess object
        chess.read_from_file(filename);   //load chess board from the file
        chess.load_board();  // create pieces

        // print contents
        std::cout << filename << " black points: " << chess.calculate_black_points() << "\t";
        std::cout << " white points: " << chess.calculate_white_points() << "\n";
    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
