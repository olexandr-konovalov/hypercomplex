// Copyright 2020 <Maciej Bak>
/*
###############################################################################
#
#   Hypercomplex library: implementation file
#
#   AUTHOR: Maciej_Bak
#   AFFILIATION: Swiss_Institute_of_Bioinformatics
#   CONTACT: wsciekly.maciek@gmail.com
#   CREATED: 22-10-2020
#   LICENSE: MIT
#
###############################################################################
*/

#include <cstdlib>
#include "Hypercomplex.h" // NOLINT

// Hypercomplex main constructor
Hypercomplex::Hypercomplex(unsigned int d, float* arr) {
    float * temparr = new float[d];
    for (unsigned int i=0; i < d; i++) {
        temparr[i] = arr[i];
    }
    this->d = d;
    this->arr = temparr;
}

// Hypercomplex copy constructor
Hypercomplex::Hypercomplex(const Hypercomplex& H) {
    float * temparr = new float[H.d];
    for (unsigned int i=0; i < H.d; i++) {
        temparr[i] = H.arr[i];
    }
    this->d = H.d;
    this->arr = temparr;
}

// Hypercomplex destructor
Hypercomplex::~Hypercomplex() {
    delete[] arr;
}

// ~ operator
Hypercomplex Hypercomplex::operator~ () {
    float * temparr = new float[d];
    temparr[0] = arr[0];
    for (unsigned int i=1; i < d; i++) {
        temparr[i] = -arr[i];
    }
    Hypercomplex H = Hypercomplex(d, temparr);
    delete[] temparr;
    return H;
}

// - unary operator
Hypercomplex Hypercomplex::operator- () {
    float * temparr = new float[d];
    for (unsigned int i=0; i < d; i++) {
        temparr[i] = -arr[i];
    }
    Hypercomplex H = Hypercomplex(d, temparr);
    delete[] temparr;
    return H;
}

Hypercomplex& Hypercomplex::operator= (const Hypercomplex &H) {
    // self-assignment guard
    if (this == &H) return *this;
    // reassign
    d = H.d;
    delete[] arr;
    float * temparr = new float[d];
    for (unsigned int i=0; i < d; i++) {
        temparr[i] = H.arr[i];
    }
    // return the existing object so we can chain this operator
    return *this;
}

// overloaded == operator
bool Hypercomplex::operator ==(const Hypercomplex& H) {
    if (d != H.d) {
        return false;
    }
    for (unsigned int i=0; i < d; i++) {
        if (arr[i] != H.arr[i]) {
            return false;
        }
    }
    return true;
}

// overloaded != operator
bool Hypercomplex::operator !=(const Hypercomplex& H) {
    if (d != H.d) {
        return true;
    }
    for (unsigned int i=0; i < d; i++) {
        if (arr[i] != H.arr[i]) {
            return true;
        }
    }
    return false;
}

// overloaded [] operator
float& Hypercomplex::operator[](unsigned int i) {
    return arr[i];
}