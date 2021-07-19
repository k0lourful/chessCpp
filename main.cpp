#include <iostream>
#include "King.hpp"
#include "Rook.hpp"
#include "Bishop.hpp"
#include "Board.hpp"

extern Board board;

int main() {
    Chessman* whites[3] = {new King(Chessman::COLOUR::WHITE,0,0), new Rook(Chessman::COLOUR::WHITE, 0, 0),
                           new Bishop(Chessman::COLOUR::WHITE,0,0)};
    Chessman* blacks[3] = {new King(Chessman::COLOUR::BLACK,0,0), new Rook(Chessman::COLOUR::BLACK, 0, 0),
                           new Bishop(Chessman::COLOUR::BLACK,0,0)};

    std::cout << "White's turn\n";

    if(board.isStalemate(whites, 3))
        std::cout << "Stalemate! Draw!\n";

    if(whites[0]->isCheckmate())
        std::cout << "Checkmate! You lose!\n";
    else if(whites[0]->isCheck())
        std::cout << "Check!\n";

    return 0;
}
