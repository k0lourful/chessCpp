#include "Board.hpp"

//Board::Board() {
////    squares = new Chessman **[8];
//
////    for (short i = 0; i < 8; ++i)
////        squares[i] = new Chessman *[8]{nullptr};
//
//}

Board::~Board() {
//    for (short i = 0; i < 8; ++i)
//        delete[] squares[i];
//    delete[] squares;
    for (short i = 0; i < 8; ++i)
        for (short j = 0; j < 8; ++j)
            delete squares[i][j];
}

bool Board::isStalemate(Chessman **chessmen, const short &n) {
    for (short i = 0; i < n; ++i) {
        int *coords = chessmen[i]->getCoordinates();
        int x = coords[0], y = coords[1];
        Chessman::TYPE type = chessmen[i]->getType();

        if (type == Chessman::TYPE::KING) {
            for (short k = -1; k < 2; ++k)
                for (short l = -1; l < 2; ++l)
                    if (!(k == 0 && l == 0) && x + k >= 1 && x + k <= 8 && y + l >= 1 && y + l <= 8) {
                        if (!squares[k - 1][l - 1]) return false;
                    }
        }

        if (type == Chessman::TYPE::ROOK) {
            if (!squares[x - 1 - 1][y - 1] || !squares[x - 1 + 1][y - 1] || !squares[x - 1][y - 1 - 1] ||
                !squares[x - 1][y - 1 + 1])
                return false;
        }

        if (type == Chessman::TYPE::BISHOP) {
            if (!squares[x - 1 - 1][y - 1 - 1] || !squares[x - 1 - 1][y - 1 + 1] || !squares[x - 1 + 1][y - 1 - 1] ||
                !squares[x - 1 + 1][y - 1 + 1])
                return false;
        }
    }

    return true;
}
