#define _CRT_SECURE_NO_WARNINGS


#include "iProduct.h"

namespace sdds {

    iProduct::~iProduct() {


    };

    std::ostream& operator<<(std::ostream& os, const iProduct& product) {

        return product.display(os);


    };

    std::istream& operator>>(std::istream& istr, iProduct& product) {

        return product.read(istr);

    };


}