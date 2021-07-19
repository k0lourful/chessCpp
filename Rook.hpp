#pragma once

#include "Chessman.hpp"

class Rook : public Chessman {
public:
    Rook(const COLOUR &c, const short &mX, const short &mY) : Chessman(c, mX, mY) { type = ROOK; }
};
