#pragma once
#include "Chessman.hpp"

class Board {

public:
    Chessman *squares[8][8]{{nullptr}};

    bool isStalemate(Chessman** chessmen, const short& n);
//    Board();

    ~Board();
};
