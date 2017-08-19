//
// Created by 研究用 on 2017/07/02.
//

#include "vector.h"

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

Vector::Vector(vector<double> v){
    vec=v;
}

void Vector::write() {
    cout<<"state vector (x,y,vx,vy):(";
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<" ";
    }
    cout<<")"<<endl;
}

double Vector::norm(){
    double squa=0;
    for(int i=0;i<vec.size();i++){
        squa+=vec[i]*vec[i];
    }
    return sqrt(squa);
}

Vector Vector::operator=(const Vector &A) {
    for(int i=0;i<A.vec.size();i++){
        vec[i]=A.vec[i];
    }
    return *this;
}

Vector::Vector() {

}

Vector::Vector(const Vector &v) {
    vec.resize(v.vec.size());
    for(int i=0;i<vec.size();i++) vec[i]=v.vec[i];
}

void Vector::set_vector(vector<double> a) {
//    cout<<"Setter for vector"<<endl;
    vec.resize(a.size());
    for(int i=0;i<a.size();i++) vec[i]=a[i];
}

//sum of two vectors
Vector operator+ (const Vector &A, const Vector &B) {
    if (A.vec.size() != B.vec.size()) {
        cout << "Vector sum can not be defined!" << endl;
    }

    vector<double> temp;
    Vector result(temp);
    result.vec.resize(A.vec.size());

    for (int i = 0; i < A.vec.size(); i++) {
        result.vec[i]= A.vec[i] + B.vec[i];
    }
    return result;
}

//difference of two matrices
Vector operator- (const Vector &A, const Vector &B) {
    if (A.vec.size() != B.vec.size()) {
        cout << "Vector sum can not be defined!" << endl;
    }

    vector<double> temp;
    Vector result(temp);
    result.vec.resize(A.vec.size());

    for (int i = 0; i < A.vec.size(); i++) {
        result.vec[i]= A.vec[i] - B.vec[i];
    }
    return result;
}

