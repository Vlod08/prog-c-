#include "../include/arithmetic.hpp"

#include "../include/printing.hpp"

#include "../include/types.hpp"

#include "../include/number_factory.hpp"


#include <cassert>
#include <cmath>
#include <complex>
#include <iostream>
#include <sstream>
#include <variant>


// Comparaison approximative pour les doubles
bool approx_eq(double a, double b) { return std::abs(a - b) < 0.001; }

int main() {

  { // On verifie le contenu des number_t
    number_t d = 2.5;
    number_t i = 2;

    assert(std::holds_alternative<double>(d));
    assert(std::holds_alternative<int>(i));

    assert(approx_eq(std::get<double>(d), 2.5));
    assert(std::get<int>(i) == 2);
  }

  { // On verifie l'affichage dans un stream
    number_t d = 2.5;
    number_t i = 2;

    std::ostringstream oss;
    oss << d << ' ' << i;
    assert(oss.str() == "2.5 2");
  }

  { // On verifie que tout fonctionne avec fraction_t
    number_t val = fraction_t{2.5, 3.5};
    assert(std::holds_alternative<fraction_t>(val));
    std::ostringstream oss;
    oss << val;
    assert(oss.str() == "2.5/3.5");

    assert(approx_eq(double(fraction_t{1, 2} * fraction_t{2, 3}),
                     double(fraction_t{2, 6})));

    assert(approx_eq(double(fraction_t{1, 2} + fraction_t{2, 3}),
                     double(fraction_t{3 + 4, 6})));
  }

  // Verification des operateurs arithmetiques

  {
    number_t val =
        number_t{fraction_t{2., 2.}} * number_t{std::complex<double>{2, 3}};

    assert(std::holds_alternative<std::complex<double>>(val));
    assert(std::get<std::complex<double>>(val) == std::complex<double>(2., 3.));
  }

  {
    number_t val = number_t{fraction_t{2., 3.}} + number_t{1.};
    assert(std::holds_alternative<fraction_t>(val));
    assert(approx_eq(double(std::get<fraction_t>(val)), 5. / 3.));
  }

  // Tests sur number_factory

  {
    number_t val = number_factory("integer", "2");
    assert(std::holds_alternative<int>(val));
    assert(approx_eq(std::get<int>(val), 2));
  }

  {
    number_t val = number_factory("real", "2.5");
    assert(std::holds_alternative<double>(val));
    assert(std::get<double>(val) == 2.5);
  }

  {
    number_t val = number_factory("complex", "2.5 2.2");
    assert(std::holds_alternative<std::complex<double>>(val));
    assert(std::get<std::complex<double>>(val) ==
           std::complex<double>(2.5, 2.2));
  }

  {
    number_t val = number_factory("fraction", "2.5 2.2");
    assert(std::holds_alternative<fraction_t>(val));
    assert(approx_eq(double(std::get<fraction_t>(val)),
                     double(fraction_t{2.5, 2.2})));
  }

  return 0;
}
