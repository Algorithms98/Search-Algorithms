//
// Created by PRINCE NDHLOVU on 9/30/20.
//

#include "Edges.h"

Edges::Edges() {

    id = 0;
    weight = 0.0;
}

Edges::Edges(int num) {

    id = num;
    weight = 0.0;
}

Edges::Edges(int num, double w) {

    id = num;
    weight = w;
}

Edges::~Edges() {

}

void Edges::setId(int num) {

    id = num;
}

void Edges::setWeight(double w) {

    weight = w;
}
