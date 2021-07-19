//#include "Chessman.hpp"
#include "Board.hpp"
extern Board board;

Chessman::Chessman(const COLOUR &c, const short &mX, const short &mY) : colour(c) {
    x = mX > 8 ? 8 : mX;
    y = mY > 8 ? 8 : mY;
}

int *Chessman::getCoordinates() const {
    int* coords = new int[2]{x,y};
    return coords;
}

bool Chessman::isCheck() const {
    if(type != KING)
        return false;

    for (short i = 0; i < 8; ++i) {
        if (i != y - 1 && board.squares[x - 1][i]) {
            if (board.squares[x - 1][i]->getType() == ROOK)
                return true;
        }
        if (i != x - 1 && board.squares[i][y - 1]) {
            if (board.squares[i][y - 1]->getType() == ROOK)
                return true;
        }
    }

    for (short k = 1; k < 8; ++k) {
        if (x - 1 - k >= 0 && y - 1 - k >= 0 && board.squares[x - 1 - k][y - 1 - k]->getType() == BISHOP)
            return true;
        if (x - 1 - k >= 0 && y - 1 + k < 8 && board.squares[x - 1 - k][y - 1 + k]->getType() == BISHOP)
            return true;
        if (x - 1 + k < 8 && y - 1 - k >= 0 && board.squares[x - 1 + k][y - 1 - k]->getType() == BISHOP)
            return true;
        if (x - 1 + k < 8 && y - 1 + k < 8 && board.squares[x - 1 + k][y - 1 + k]->getType() == BISHOP)
            return true;
    }

    return false;
}

bool Chessman::isCheckmate() {
    if(type != KING)
        return false;

    if (isCheck()) {
        short oldX = x, oldY = y;
        for (short i = -1; i < 2; ++i)
            for (short j = -1; j < 2; ++j)
                if (!(i == 0 && j == 0) && oldX + i >= 1 && oldX + i <= 8 && oldY + j >= 1 && oldY + j <= 8) {
                    x = oldX + i;
                    y = oldY + j;
                    if (isCheck()) return true;
                }
        x = oldX;
        y = oldY;
    }

    return false;
}

