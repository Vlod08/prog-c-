#pragma once

#include "types.hpp"

#include <ostream>

// Declaration des operator<< pour fraction_t et number_t.
// Vous devez les definir dans printing.cpp.

std::ostream &operator<<(std::ostream &, fraction_t const &);

std::ostream &operator<<(std::ostream &, number_t const &);
