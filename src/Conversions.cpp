//
// Created by jordan on 28/10/17.
//

#include <complex>

#include "Conversions.h"

namespace jrc {

std::complex<double> y_from_gamma(const std::complex<double>& gamma) {
    return (1.0 - gamma) / (1.0 + gamma);
}

std::complex<double> z_from_gamma(const std::complex<double>& gamma) {
    return (1.0 + gamma) / (1.0 - gamma);
}

};
