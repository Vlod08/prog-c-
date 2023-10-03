#include "../include/printing.hpp"

#include "../include/types.hpp"

#include <variant>
#include <iostream>
#include <stdio.h>


// On donne operator<< pour fraction_t. Notez qu'on renvoie une *reference*
// vers un std::ostream.
std::ostream &operator<<(std::ostream &o, fraction_t const &n) {
  return o << n.n << '/' << n.d;
}

// Implementez std::ostream &operator<<(std::ostream &o, number_t const &n)
// avec std::visit.

/*...Compléter ici ...*/
std::ostream& operator<<(std::ostream& o, number_t const &n) { 
std::visit([&](const auto& n){ o<<n; }, n); 
return o;}
