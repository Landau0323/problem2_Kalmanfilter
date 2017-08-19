//
// Created by 研究用 on 2017/07/02.
//

#ifndef PROBLEM1_MATRIX_H
#define PROBLEM1_MATRIX_H

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

#include "vector.h"

using namespace std;


class Matrix {
public:
    vector< vector<double> > element;

public:
    Matrix(vector< vector<double> >);
    Matrix(const Matrix&);
    Matrix();

    void transpose();
    void inverse();

    void write();
    void set_matrix(vector<vector<double> >);

    ~Matrix();
};

Matrix operator+ (const Matrix &A, const Matrix &B);
Matrix operator- (const Matrix &A, const Matrix &B);
Matrix operator* (const Matrix &A, const Matrix &B);

Vector operator* (const Matrix &A, const Vector &B);

#endif //PROBLEM1_MATRIX_H
