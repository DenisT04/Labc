#include "painter.hpp"
#include <iostream>

// Constructor implicit
Painter::Painter() {}

// Constructor de copiere
Painter::Painter(const Painter& other) {}

// Operator de atribuire
Painter& Painter::operator=(const Painter& other) {
    return *this;
}

// Restul metodelor rămân la fel (DrawBoard, DisplayMessage, etc.)
