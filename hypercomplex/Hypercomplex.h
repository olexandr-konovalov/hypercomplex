// Copyright 2020 <Maciej Bak>
/*
###############################################################################
#
#   Hypercomplex library: header file
#
#   AUTHOR: Maciej_Bak
#   AFFILIATION: Swiss_Institute_of_Bioinformatics
#   CONTACT: wsciekly.maciek@gmail.com
#   CREATED: 22-10-2020
#   LICENSE: MIT
#
###############################################################################
*/

// mark that we included this header
#ifndef HYPERCOMPLEX_HYPERCOMPLEX_H_
#define HYPERCOMPLEX_HYPERCOMPLEX_H_

/*
Main class of the library
*/
class Hypercomplex {
 private:
    unsigned int d;  // dimension
    float *arr;  // elements
 public:
    explicit
        Hypercomplex(unsigned int arg_d, float* arg_arr);  // main constructor
    Hypercomplex(const Hypercomplex& H);  // copy constructor
    Hypercomplex() = delete;  // forbid default constructor | c++11
    ~Hypercomplex();  // destructor
    float _() const { return d; }  // get space dimension
    Hypercomplex operator~ () const;  // conjugate operator
    Hypercomplex operator- () const;  // negation operator
    Hypercomplex& operator= (const Hypercomplex &H);  // assignment operator
    float& operator[] (unsigned int i);  // element access operator
    const float& operator[] (unsigned int i) const;  // element access operator
    Hypercomplex& operator+= (const Hypercomplex &H);
    Hypercomplex& operator-= (const Hypercomplex &H);
};

/*
Operators
*/
bool operator== (const Hypercomplex &H1, const Hypercomplex &H2);
bool operator!= (const Hypercomplex &H1, const Hypercomplex &H2);
Hypercomplex operator+ (const Hypercomplex &H1, const Hypercomplex &H2);
Hypercomplex operator- (const Hypercomplex &H1, const Hypercomplex &H2);

#endif  // HYPERCOMPLEX_HYPERCOMPLEX_H_
