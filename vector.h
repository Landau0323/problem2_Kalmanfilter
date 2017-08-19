//
// Created by 研究用 on 2017/07/02.
//

#ifndef PROBLEM1_VECTOR_H
#define PROBLEM1_VECTOR_H

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

using namespace std;


class Vector {
public:
    vector<double> vec;

public:
    //コンストラクタ
    Vector();
    Vector(vector<double>);
    Vector(const Vector&);

    //セッター
    void set_vector(vector<double>);

    double norm();
    void write();

    Vector operator= (const Vector &A);
    
};

Vector operator+ (const Vector &A, const Vector &B);
Vector operator- (const Vector &A, const Vector &B);




#endif //PROBLEM1_VECTOR_H
