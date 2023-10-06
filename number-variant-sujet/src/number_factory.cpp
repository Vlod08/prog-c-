
#include "../include/number_factory.hpp"
#include "../include/types.hpp"
#include <string.h>
#include <sstream>
#include <complex>


// Implementez ici
number_t number_factory(std::string const &kind, std::string const &text)
{	
	if(kind == "real"){number_t ret = std::stod(text);  return ret;}
	
	else if(kind == "complex"){
		std::istringstream is(text);
		
		double real, image;
		is>>real>>image;
		return std::complex<double> {real, image};
		
	}
	
	else if (kind == "integer") {number_t ret = std::stoi(text); return ret;}
	
	else if (kind == "fraction"){
		std::istringstream is(text);
		fraction_t f;
		is>>f.n>>f.d ;
		number_t frac =f;
		return frac;}
	
	else {return {};}
}

/*...Compléter ici ...*/


