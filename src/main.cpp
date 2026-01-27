#include <bn_core.h>
#include <bn_backdrop.h>
#include <bn_color.h>
#include <bn_sprite_ptr.h>
#include <bn_random.h>
#include <bn_vector.h>
#include <bn_keypad.h>

#include "bn_sprite_items_ladybug.h"

int main()
{
    bn::core::init();

    bn::random rng = bn::random();

    bn::backdrop::set_color(bn::color(30, 3, 5));

    bn::vector<bn::sprite_ptr, 50> bugs = {};

    // bn::sprite_ptr ladybug = bn::sprite_items::ladybug.create_sprite();

    while (true)
    {
        for(bn::sprite_ptr& ladybug : bugs){
            bn:: fixed new_x = ladybug.x() + rng.get_fixed(-1,1);
            bn:: fixed new_y = ladybug.y() + rng.get_fixed(-1,1);

            ladybug.set_x(new_x);
            ladybug.set_y(new_y);
        }
        

        if(bn::keypad::a_pressed()) {
            bugs.push_back(bn::sprite_items::ladybug.create_sprite());
        }

        rng.update();
        bn::core::update();
    }
}