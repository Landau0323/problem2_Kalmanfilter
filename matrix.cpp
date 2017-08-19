//
// Created by 研究用 on 2017/07/02.
//

#include "matrix.h"

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

//constructor, setting matrix element
Matrix::Matrix(vector<vector <double>> f){
    //setting size of matrix
    int tate=f.size();
    int yoko=f[0].size();
    element.resize(tate);
    for(int i=0;i<element.size();i++){
        element[i].resize(yoko);
    }

    //setting matrix element
    for(int i=0;i<tate;i++){
        for(int j=0;j<yoko;j++){
            element[i][j]=f[i][j];
//cout<<"element["<<i<<","<<j<<"]="<<element[i][j]<<endl;
        }
    }
}

//transposing matrix
void Matrix::transpose() {
    int tate=element.size();
    int yoko=element[0].size();
    double temp[tate][yoko];
    for(int i=0;i<tate;i++){
        for(int j=0;j<yoko;j++){
            temp[i][j]=element[i][j];
        }
    }
    //resizing matrix
    element.resize(yoko);
    for(int i=0;i<element.size();i++){
        element[i].resize(tate);
    }

    for(int i=0;i<yoko;i++){
        for(int j=0;j<tate;j++){
            element[i][j]=temp[j][i];
//cout<<"transpose: ["<<i<<","<<j<<"]="<<element[i][j]<<endl;
        }
    }

}

//writing matrix element
void Matrix::write() {
    int tate=element.size();
    int yoko=element[0].size();

    if(tate==1 && yoko==1){
        cout<<element[0][0]<<endl;
    }
    else {
        cout<<"covariance matrix (x,y,vx,vy;4*4 matrix):"<<endl;
        for (int i = 0; i < tate; i++) {
            for (int j = 0; j < yoko; j++) {
                cout<<element[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}

//inverse matrix (掃きだし法)
void Matrix::inverse() {
    int n = element.size();
    if(n != element[0].size()){
        cout<<"正方行列ではない！"<<endl;
    }

    //create unit matrix
    double inv[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                inv[i][j]=1;
            }
            else{
                inv[i][j]=0;
            }
        }
    }

    double buf,ratio;
    for(int i=0;i<n;i++){
        buf=element[i][i];
        //まず対角成分を1にする
        for(int j=0;j<n;j++){
            element[i][j]/=buf;
            inv[i][j]/=buf;
        }

        //他の行にある成分を0にする
        for(int k=0;k<n;k++){
            if(k==i){continue;}
            ratio=element[k][i];
            for(int j=0;j<n;j++){
                element[k][j]-=ratio*element[i][j];
                inv[k][j]-=ratio*inv[i][j];
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            element[i][j]=inv[i][j];
//cout<<"inverse:element("<<i<<","<<j<<")="<<element[i][j]<<endl;
        }
    }

}

Matrix::~Matrix() {
//    cout<<"Matrix deleted!"<<endl;

}

Matrix::Matrix() {

}

Matrix::Matrix(const Matrix &M) {
    element.resize(M.element.size());
    for(int i=0;i<element.size();i++){
        element[i].resize(M.element[i].size());
        for(int j=0;j<element[i].size();j++) element[i][j]=M.element[i][j];
    }
}

void Matrix::set_matrix(vector<vector<double> > M) {
//    cout<<"Setter for matrix"<<endl;
    element.resize(M.size());
    for(int i=0;i<element.size();i++){
        element[i].resize(M[i].size());
        for(int j=0;j<element[i].size();j++) element[i][j]=M[i][j];
    }
}

//sum of two matrices
Matrix operator+ (const Matrix &A, const Matrix &B) {
    if (A.element[0].size() != B.element[0].size() || A.element.size() != B.element.size()) {
        cout << "Matrix sum can not be defined!" << endl;
    }

    vector<vector<double> > temp;
    vector<double> temp2;
    temp2.push_back(0);
    temp.push_back(temp2);
    Matrix result(temp);

    int tate = A.element.size();
    int yoko = A.element[0].size();
    result.element.resize(tate);
    for (int i = 0; i < tate; i++) {
        result.element[i].resize(yoko);
        for (int j = 0; j < yoko; j++) {
            result.element[i][j] = A.element[i][j] + B.element[i][j];
        }
    }
    return result;
}

//difference of two matrices
Matrix operator- (const Matrix &A, const Matrix &B) {
    if (A.element[0].size() != B.element[0].size() || A.element.size() != B.element.size()) {
        cout << "Matrix difference can not be defined!" << endl;
    }

    vector<vector<double> > temp;
    vector<double> temp2;
    temp2.push_back(0);
    temp.push_back(temp2);
    Matrix result(temp);

    int tate = A.element.size();
    int yoko = A.element[0].size();
    result.element.resize(tate);
    for (int i = 0; i < tate; i++) {
        result.element[i].resize(yoko);
        for (int j = 0; j < yoko; j++) {
            result.element[i][j] = A.element[i][j] - B.element[i][j];
        }
    }
    return result;
}


//product of two matrices
Matrix operator* (const Matrix &A, const Matrix &B){
    if(A.element[0].size()!=B.element.size()){
        cout<<"Matrix product can not be defined!"<<endl;
    }

    vector<vector<double> > temp;
    vector<double> temp2;
    temp2.push_back(0);
    temp.push_back(temp2);
    Matrix result(temp);

    int tate=A.element.size();
    int yoko=B.element[0].size();
//cout<<tate<<" "<<yoko<<endl;
    result.element.resize(tate);
    for(int i=0;i<tate;i++){
        result.element[i].resize(yoko);
        for(int j=0;j<yoko;j++){
            result.element[i][j]=0;
            for(int k=0;k<A.element[0].size();k++){
                result.element[i][j]+=A.element[i][k]*B.element[k][j];
//cout<< "k="<<k<<", A="<<A.element[i][k]<<", B="<< B.element[k][j] <<result.element[i][j]<<endl;
            }
//cout<< "product: [" <<i<< "]["<<j<< "]=" <<result.element[i][j]<<endl;

        }
    }

    return result;
}

Vector operator* (const Matrix &A, const Vector &B){
    int tate=A.element.size();
    int yoko=A.element[0].size();
    if(yoko!= B.vec.size()) cout<<"Product can not be defined!";

    vector<double> temp;
    Vector result(temp);
    result.vec.resize(tate);

    for(int i=0;i<tate;i++){
        double seki=0;
        for(int k=0;k<yoko;k++){
            seki+=A.element[i][k]*B.vec[k];
        }
        result.vec[i]=seki;
    }
    return result;
}