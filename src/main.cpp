#include "bn_core.h"
#include "bn_backdrop.h"
#include "bn_color.h"

int main() {
    bn::core::init();

    bn::backdrop::set_color(bn::color(30, 10, 5));

    while(true) {
        bn::core::update();
    }
}