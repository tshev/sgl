#include <cstdint>
#include <sgl/sgl.h>
#include "wip_class_datetime.h"

int main() {
    sgl::datetime x(2018, 11, 21, 14, 0, 0);
    std::cout << x.year() << " " << x.month() << " " << x.day() << " " << x.hour() << std::endl;

    sgl::datetime y(1995, 3, 3);
    auto delta = x - y;
    std::cout << delta << std::endl;
}
