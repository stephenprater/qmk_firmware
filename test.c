#include <stdio.h>
#include <string.h>

#define RGBLED_NUM 64

enum { _MODS, _QWERTY, _RAISE, _LOWER, _KEEB, _COLEMAK };

// clang-format off
const char * led_maps[][RGBLED_NUM] = {
     [_MODS] = {
              "MODS   " , "_______" , "_______" , "_______" , "_______" , "_______" ,                                                  "_______"  , "_______" , "_______" , "_______" , "_______" , "_______" ,
              "MODS   " , "_______" , "_______" , "_______" , "_______" , "_______" ,                                                  "_______"  , "_______" , "_______" , "_______" , "_______" , "_______" ,
    "MODS   ","MODS   " , "_______" , "_______" , "_______" , "_______" , "_______" ,                                                  "_______"  , "_______" , "_______" , "_______" , "_______" , "_______" , "MODS   ",
              "MODS   " , "_______" , "_______" , "_______" , "_______" , "_______" , "MODS   " , "LOWER  " , "RAISE  "  , "MODS   " , "_______"  , "_______" , "_______" , "_______" , "_______" , "_______" ,
                                                  "ENCODE " , "MODS   " , "LOWER  " , "_______" , "MODS   " , "_______"  , "_______" , "RAISE  "  , "MODS   " , "ENCODE "
     },
     [_QWERTY] = {
              "_______" , "NUMERIC" , "NUMERIC" , "NUMERIC" , "NUMERIC" , "NUMERIC" ,                                                 "NUMERIC"  , "NUMERIC" , "NUMERIC" , "NUMERIC" , "NUMERIC" , "NUMERIC" ,
              "_______" , "QWERTY " , "QWERTY " , "QWERTY " , "QWERTY " , "QWERTY " ,                                                 "QWERTY "  , "QWERTY " , "QWERTY " , "QWERTY " , "QWERTY " , "QWERTY " ,
   "_______" ,"_______" , "QWERTY " , "QWERTY " , "QWERTY " , "QWERTY " , "QWERTY " ,                                                 "QWERTY "  , "QWERTY " , "QWERTY " , "QWERTY " , "QWERTY " , "QWERTY " ,"_______" ,
              "_______" , "QWERTY " , "QWERTY " , "QWERTY " , "QWERTY " , "QWERTY " , "_______" , "_______" , "_______" , "_______" , "QWERTY "  , "QWERTY " , "QWERTY " , "QWERTY " , "QWERTY " , "QWERTY " ,
                                                  "_______" , "_______" , "_______" , "QWERTY " , "_______" , "QWERTY " , "QWERTY " , "_______"  , "_______" , "_______"
     },
     [_RAISE] =  {
              "ADJUST " , "FKEY   " , "FKEY   " , "FKEY   " , "FKEY   " , "FKEY   " ,                                                 "FKEY   " , "FKEY   " , "FKEY   " , "FKEY   " , "FKEY   " , "FKEY   " ,
              "_______" , "CURSOR " , "CURSOR " , "CURSOR " , "MEDIA  " , "OFF    " ,                                                 "OFF    " , "EDIT   " , "EDIT   " , "OFF    " , "OFF    " , "OFF    " ,
   "_______" ,"_______" , "CURSOR " , "CURSOR " , "CURSOR " , "MEDIA  " , "LOCK   " ,                                                 "OFF    " , "EDIT   " , "EDIT   " , "EDIT   " , "OFF    " , "OFF    " , "MODS   " ,
              "_______" , "CURSOR " , "CURSOR " , "OFF    " , "MEDIA  " , "MEDIA  " , "_______" , "_______" , "_______" , "_______" , "OFF    " , "EDIT   " , "EDIT   " , "EDIT   " , "OFF    " , "OFF    " ,
                                                  "_______" , "_______" , "_______" , "_______" , "_______" , "_______" , "_______" , "_______" , "_______" , "_______"
    },
    [_LOWER] = {
              "OFF    " , "OFF    " , "OFF    " , "OFF    " , "OFF    " , "OFF    " ,                                                 "OFF    " , "OFF    " , "OFF    " , "OFF    " , "OFF    " , "OFF    " ,
              "SYMBOL " , "NUMERIC" , "NUMERIC" , "NUMERIC" , "NUMERIC" , "NUMERIC" ,                                                 "NUMERIC" , "NUMERIC" , "NUMERIC" , "NUMERIC" , "NUMERIC" , "SYMBOL " ,
   "_______" ,"SYMBOL2" , "SYMBOL " , "SYMBOL " , "SYMBOL " , "SYMBOL " , "SYMBOL " ,                                                 "SYMBOL " , "SYMBOL " , "SYMBOL " , "SYMBOL " , "SYMBOL " , "SYMBOL2" , "_______" ,
              "SYMBOL2" , "SYMBOL2" , "SYMBOL2" , "SYMBOL2" , "SYMBOL2" , "SYMBOL2" , "_______" , "_______" , "_______" , "_______" , "SYMBOL2" , "SYMBOL2" , "SYMBOL2" , "SYMBOL2" , "SYMBOL2" , "SYMBOL2" ,
                                                  "_______" , "_______" , "_______" , "_______" , "_______" , "_______" , "_______" , "_______" , "_______" , "_______"
    },
    [_KEEB] =  {
               "ADJUST " , "ADJUST " , "OFF    " , "OFF    " , "OFF    " , "ADJUST " ,                                                 "COLEMAK" , "QWERTY " , "OFF    " , "OFF    " , "OFF    " , "OFF    " ,
               "OFF    " , "OFF    " , "OFF    " , "OFF    " , "OFF    " , "OFF    " ,                                                 "OFF    " , "OFF    " , "OFF    " , "OFF    " , "OFF    " , "OFF    " ,
    "OFF    " ,"OFF    " , "KEYCTL " , "OFF    " , "OFF    " , "OFF    " , "OFF    " ,                                                 "OFF    " , "OFF    " , "OFF    " , "OFF    " , "OFF    " , "OFF    " , "OFF    "  ,
               "KEYCTL " , "KEYCTL " , "OFF    " , "OFF    " , "OFF    " , "OFF    " , "OFF    " , "OFF    " , "OFF    " , "OFF    " , "OFF    " , "OFF    " , "OFF    " , "OFF    " , "OFF    " , "OFF    " ,
                                                   "ENCODE " , "OFF    " , "OFF    " , "OFF    " , "OFF    " , "OFF    " , "OFF    " , "OFF    " , "OFF    " , "ENCODE "
    },
    [_COLEMAK] =  {
               "_______" , "NUMERIC" , "NUMERIC" , "NUMERIC" , "NUMERIC" , "NUMERIC" ,                                                 "NUMERIC" , "NUMERIC" , "NUMERIC" , "NUMERIC" , "NUMERIC" , "NUMERIC" ,
               "_______" , "COLEMAK" , "COLEMAK" , "COLEMAK" , "COLEMAK" , "COLEMAK" ,                                                 "COLEMAK" , "COLEMAK" , "COLEMAK" , "COLEMAK" , "COLEMAK" , "COLEMAK" ,
    "_______" ,"_______" , "COLEMAK" , "COLEMAK" , "COLEMAK" , "COLEMAK" , "COLEMAK" ,                                                 "COLEMAK" , "COLEMAK" , "COLEMAK" , "COLEMAK" , "COLEMAK" , "COLEMAK" , "_______" ,
               "_______" , "COLEMAK" , "COLEMAK" , "COLEMAK" , "COLEMAK" , "COLEMAK" , "_______" , "_______" , "_______" , "_______" , "COLEMAK" , "COLEMAK" , "COLEMAK" , "COLEMAK" , "COLEMAK" , "COLEMAK" ,
                                                   "_______" , "_______" , "_______" , "_______" , "_______" , "_______" , "_______" , "_______" , "_______" , "_______"
    },
};

// clang-format on
//

void rgblight_set_from_map(const char* map[]) {
    const char* first = map[0];
    int         start = 0;
    int         count = 1;
    for (int i = 1; i <= RGBLED_NUM; i++) {
        if (map[i] && strcmp(first, map[i]) == 0) {
            count += 1;
        } else {
            if (!(strcmp(first, "_______") == 0)) {
                printf("    {%2d, %2d, %7s}", start + 1, count + 1, first);
                if (start + 1 >= RGBLED_NUM) {
                    printf("\n");
                } else {
                    printf(",\n");
                }
            }
            first = map[i];
            start = i;
            count = 0;
        }
    }
}

void print_colors() {
    printf("#define MODS    HSV_AZURE\n"); // Exception
    printf("#define MEDIA   HSV_YELLOW\n");
    printf("#define FKEY    HSV_SPRINGGREEN\n");

    printf("#define QWERTY  90, 85, 130\n"); // Identifier / Function
    printf("#define NUMERIC HSV_PURPLE\n");  // String
    printf("#define SYMBOL  HSV_MAGENTA\n"); // Number
    printf("#define SYMBOL2 HSV_PINK\n");    // Float

    printf("#define COLEMAK HSV_GOLD\n");

    printf("#define CURSOR  HSV_TEAL\n");
    printf("#define EDIT    HSV_YELLOW\n");
    printf("#define APP     HSV_TURQUOISE\n");

    printf("#define ADJUST  HSV_ORANGE\n");
    printf("#define KEYCTL  HSV_CORAL\n");
    printf("#define LOCK    HSV_CHARTREUS\n");

    printf("#define LOWER   HSV_BLUE\n"); // BLUE
    printf("#define RAISE   HSV_RED\n");  // RED

    printf("#define ENCODER HSV_WHITE\n");
    printf("#define OFF     HSV_OFF\n");

    printf("\n\n");
}

int main() {
    print_colors();
    printf("const rgblight_segment_t PROGMEM mods_layer[] = RGBLIGHT_LAYER_SEGMENTS(\n");
    rgblight_set_from_map(led_maps[_MODS]);
    printf(");\n");
    printf("const rgblight_segment_t PROGMEM qwerty_layer[] = RGBLIGHT_LAYER_SEGMENTS(\n");
    rgblight_set_from_map(led_maps[_QWERTY]);
    printf(");\n");
    printf("const rgblight_segment_t PROGMEM raise_layer[] = RGBLIGHT_LAYER_SEGMENTS(\n");
    rgblight_set_from_map(led_maps[_RAISE]);
    printf(");\n");
    printf("const rgblight_segment_t PROGMEM lower_layer[] = RGBLIGHT_LAYER_SEGMENTS(\n");
    rgblight_set_from_map(led_maps[_LOWER]);
    printf(");\n");
    printf("const rgblight_segment_t PROGMEM adjust_layer[] = RGBLIGHT_LAYER_SEGMENTS(\n");
    rgblight_set_from_map(led_maps[_KEEB]);
    printf(");\n");
    printf("const rgblight_segment_t PROGMEM colemak_layer[] = RGBLIGHT_LAYER_SEGMENTS(\n");
    rgblight_set_from_map(led_maps[_COLEMAK]);
    printf(");\n");
}
