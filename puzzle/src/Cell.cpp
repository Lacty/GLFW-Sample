
#include "Cell.hpp"


Cell::Cell(int number, lacty::Color color) :
number(number), color(color) {}


int Cell::getNumber() { return number; }

lacty::Color Cell::getColor() { return color; }