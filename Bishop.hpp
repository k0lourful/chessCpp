#pragma once

#include "Chessman.hpp"

class Bishop : public Chessman {
public:
    Bishop(const COLOUR &c, const short &mX, const short &mY) : Chessman(c, mX, mY) { type = BISHOP; }
};
