#pragma once
#include "linkedList.h"

struct music {
    char* name;
    char* Artist;
    char* Album;
    char* Genre;
    char* Disc_Number;
    char* Track_Number;
    char* Year;
};

typedef struct music Music;


Liste readMusics(char* line,Liste l);
Liste trierParDate(Liste l);