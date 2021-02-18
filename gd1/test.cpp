#include <iostream>
#define GROUPDATA_EXCEPTION
#define GROUPDATA_WARNING

#include  <cmath>
#include "group.hpp"


int main(void){

    gd::Group<double, 10> gr1={0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 2.23};
    gd::Group<double, 10> gr2={3.1, 3.6, 6.6, 7.2, 1.1, 3.3, 7.3};

    gr1=gr2.range(2, 9);

    std::cout<<gr1<<std::endl;

}
