#pragma once

#include <complex>
#include <variant>

/// Represente la fraction n/d
struct fraction_t {
  double n;
  double d;

  // Operateur de conversion explicite vers un double
  inline explicit operator double() const { return n / d; }
};

/// Type polymorphe pour representer un nombre.

using number_t = std::variant<int,double>;
