#pragma once

class Chessman {
public:
    enum COLOUR : unsigned short {
        WHITE, BLACK
    };

    enum TYPE : unsigned short {
        KING, BISHOP, ROOK
    };

    Chessman(const COLOUR &c, const short &mX, const short &mY);
    //    int move(const int& coordX, const int& coordY);

    TYPE getType() const {return type;}
    int* getCoordinates() const;

    bool isCheck() const;
    bool isCheckmate();

protected:
    short x, y;
    COLOUR colour;
    TYPE type;
};
