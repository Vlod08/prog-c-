

#include "../include/arithmetic.hpp"

#include "../include/types.hpp"


#include <iostream>
#include <stdio.h>

// Definir les operateurs arithmetiques pour number_t ici

/*...Compléter ici ...*/

number_t operator+(number_t const& n1,number_t const& n2)
{
	return std::visit([](auto const& arg, auto const& arg2) -> number_t{ return arg + arg2;},n1,n2);
}

number_t operator-(number_t const& n1,number_t const& n2)
{
	return std::visit([](auto const& arg, auto const& arg2) -> number_t{ return arg - arg2;},n1,n2);
}
number_t operator*(number_t const& n1,number_t const& n2)
{
	return std::visit([](auto const& arg, auto const& arg2) -> number_t{ return arg * arg2;},n1,n2);
}
number_t operator/(number_t const& n1,number_t const& n2)
{
	return std::visit([](auto const& arg, auto const& arg2) -> number_t{ return arg / arg2;},n1,n2);
}

// ===
// Operateurs arithmetiques pour fraction_t
// ===

// ---
// fraction & fraction

// Definir les operateurs ici:
/*...Compléter ici ...*/

fraction_t operator+(fraction_t const& f1, fraction_t const& f2 ){
	fraction_t res;
	res.d = f1.d * f2.d;
	res.n = (res.d/f1.d)*f1.n;
	res.n += (res.d/f2.d)*f2.n;
	return res;
}

fraction_t operator-(fraction_t const& f1, fraction_t const& f2 ){
	fraction_t res;
	res.d = f1.d * f2.d;
	res.n = (res.d/f1.d)*f1.n;
	res.n -= (res.d/f2.d)*f2.n;
	return res;
}

fraction_t operator*(fraction_t const& f1, fraction_t const& f2 ){
	fraction_t res;
	res.d = f1.d * f2.d;
	res.n = f1.n * f2.n;
	return res;
}

fraction_t operator/(fraction_t const& f1, fraction_t const& f2 ){
	fraction_t res;
	res.d = f1.d * f2.n;
	res.n = f1.n * f2.d;
	return res;
}


// ---
// fraction_t & double - les double sont convertis en fraction_t

fraction_t operator+(fraction_t const &f, double const &d) {
  return f + fraction_t{d, 1.};
}

fraction_t operator-(fraction_t const &f, double const &d) {
  return f - fraction_t{d, 1.};
}

fraction_t operator*(fraction_t const &f, double const &d) {
  return f * fraction_t{d, 1.};
}

fraction_t operator/(fraction_t const &f, double const &d) {
  return f / fraction_t{d, 1.};
}

fraction_t operator+(double const &d, fraction_t const &f) {
  return fraction_t{d, 1.} + f;
}

fraction_t operator-(double const &d, fraction_t const &f) {
  return fraction_t{d, 1.} - f;
}

fraction_t operator*(double const &d, fraction_t const &f) {
  return fraction_t{d, 1.} * f;
}

fraction_t operator/(double const &d, fraction_t const &f) {
  return fraction_t{d, 1.} / f;
}

// ---
// fraction_t & std::complex<double> - Les fraction_t sont converties en double

std::complex<double> operator+(fraction_t const &f,
                               std::complex<double> const &c) {
  return double(f) + c;
}

std::complex<double> operator-(fraction_t const &f,
                               std::complex<double> const &c) {
  return double(f) - c;
}

std::complex<double> operator*(fraction_t const &f,
                               std::complex<double> const &c) {
  return double(f) * c;
}

std::complex<double> operator/(fraction_t const &f,
                               std::complex<double> const &c) {
  return double(f) / c;
}

std::complex<double> operator+(std::complex<double> const &c,
                               fraction_t const &f) {
  return c + double(f);
}

std::complex<double> operator-(std::complex<double> const &c,
                               fraction_t const &f) {
  return c - double(f);
}

std::complex<double> operator*(std::complex<double> const &c,
                               fraction_t const &f) {
  return c * double(f);
}

std::complex<double> operator/(std::complex<double> const &c,
                               fraction_t const &f) {
  return c / double(f);
}


