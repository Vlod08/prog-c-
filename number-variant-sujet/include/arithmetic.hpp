#pragma once

#include "types.hpp"

#include <variant>

// Declarer les operateurs arithmetiques pour number_t ici

number_t operator+(fraction_t const &, number_t const &);
number_t operator-(fraction_t const &, number_t const &);
number_t operator*(fraction_t const &, number_t const &);
number_t operator/(fraction_t const &, number_t const &);

number_t operator+(number_t const &, number_t const &);
number_t operator-(number_t const &, number_t const &);
number_t operator*(number_t const &, number_t const &);
number_t operator/(number_t const &, number_t const &);

fraction_t operator+(fraction_t const &, fraction_t const &);
fraction_t operator-(fraction_t const &, fraction_t const &);
fraction_t operator*(fraction_t const &, fraction_t const &);
fraction_t operator/(fraction_t const &, fraction_t const &);

fraction_t operator+(fraction_t const &, double const &);
fraction_t operator-(fraction_t const &, double const &);
fraction_t operator*(fraction_t const &, double const &);
fraction_t operator/(fraction_t const &, double const &);

fraction_t operator+(double const &, fraction_t const &);
fraction_t operator-(double const &, fraction_t const &);
fraction_t operator*(double const &, fraction_t const &);
fraction_t operator/(double const &, fraction_t const &);

std::complex<double> operator+(fraction_t const &,
                               std::complex<double> const &);
std::complex<double> operator-(fraction_t const &,
                               std::complex<double> const &);
std::complex<double> operator*(fraction_t const &,
                               std::complex<double> const &);
std::complex<double> operator/(fraction_t const &,
                               std::complex<double> const &);

std::complex<double> operator+(std::complex<double> const &,
                               fraction_t const &);
std::complex<double> operator-(std::complex<double> const &,
                               fraction_t const &);
std::complex<double> operator*(std::complex<double> const &,
                               fraction_t const &);
std::complex<double> operator/(std::complex<double> const &,
                               fraction_t const &);

/*...Compléter ici ...*/
