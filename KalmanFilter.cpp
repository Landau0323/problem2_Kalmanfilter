//
// Created by 研究用 on 2017/08/15.
//

#include "KalmanFilter.h"
#include "paramters.h"
#include "vector.h"
#include "matrix.h"

#include <string>
#include <vector>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

KalmanFilter::KalmanFilter() {
    cout<<"Start Kalman filter"<<endl;

    //initialization of state vector
    vector <double> X(4);
    //input initial x and y
    cout<<"Input initial x and y:"<<endl;
    double x_input,y_input;
    cin>>x_input>>y_input;
    X[0]=x_input;
    X[1]=y_input;
    X[2]=0;
    X[3]=0;
    x.set_vector(X);

//cout<<"initial state vector:"<<endl;
//x.write();


    //initialization of covariance matrix for state vector
    vector<vector<double> > sigma(4);
    for(int i=0;i<4;i++) {
        sigma[i].resize(4);
        for(int j=0;j<4;j++){
            if(i!=j) sigma[i][j]=0.0;   //off-diagonal components are zero
        }
    }
    sigma[0][0]=sigma[1][1]=0.0000001;  //infinitesimal error
    sigma[2][2]=sigma[3][3]=1000;   //very large error
    Sigma.set_matrix(sigma);

//cout<<"initial covariance matrix"<<endl;
//Sigma.write();

    //parametrization of noise matrix in measurement
    vector<vector<double>> q(2);
    for(int i=0;i<2;i++) {
        q[i].resize(2);
        for(int j=0;j<2;j++){
            if(i!=j) q[i][j]=0.0;   //off-diagonal components are zero
            else q[i][j]=Q_xy;
        }
    }
    Q.set_matrix(q);

//cout<<"noise matrix in measurement"<<endl;
//Q.write();

    //parametrization of measurement matrix
    vector<vector<double>> c(2);
    for(int i=0;i<2;i++) {
        c[i].resize(4);
        for(int j=0;j<4;j++){
            if(i!=j) c[i][j]=0.0;   //off-diagonal components are zero
            else c[i][j]=1.0;
        }
    }
    C.set_matrix(c);

//cout<<"measurement matrix"<<endl;
//C.write();


    //parametrization of equation of motion
    vector<vector<double> > a(4);
    for(int i=0;i<4;i++) {
        a[i].resize(4);
        for(int j=0;j<4;j++){
            if(i!=j) a[i][j]=0.0;   //off-diagonal components are zero
            else a[i][j]=1.0;
        }
    }
    a[0][2]=a[1][3]=dt;
    A.set_matrix(a);

//cout<<"Matrix for equation of motion:"<<endl;
//A.write();

    //unit matrix
    vector<vector<double> > u(4);
    for(int i=0;i<4;i++) {
        u[i].resize(4);
        for(int j=0;j<4;j++){
            if(i!=j) u[i][j]=0.0;   //off-diagonal components are zero
            else u[i][j]=1.0;
        }
    }
    I.set_matrix(u);
}

void KalmanFilter::move() {
    cout<<"Movement"<<endl;
    //it needs no input because it is free motion

    //movement of mean value
    x = A * x;
//x.write();

    Matrix* pA_trans=new Matrix(A);
    pA_trans->transpose();
//    pA_trans->write();
    Sigma=A * Sigma *(*pA_trans);
//Sigma.write();
//    cout<<"Movement end"<<endl;

}

void KalmanFilter::measure() {

    cout<<"Measurement"<<endl;
    //input measured values
    double input_x,input_y;
    cout<<"Input measured values for x and y:";
    cin>>input_x>>input_y;
    vector<double> Z(2);
    Z[0]=input_x;
    Z[1]=input_y;

    Vector* pz=new Vector(Z);
//cout<<"measured position"<<endl;
//pz->write();

//C.write();
    Matrix* pC_trans=new Matrix(C);
    pC_trans->transpose();
//cout<<"Matrix C_trans"<<endl;
//pC_trans->write();

    Matrix* ptemp=new Matrix(C * Sigma * *pC_trans + Q);
    ptemp->inverse();
//ptemp->write();

    //Kalman gain
    Matrix* pK=new Matrix(Sigma * *pC_trans * *ptemp);
//cout<<"Kalman gain K"<<endl;
//pK->write();

    x=x + *pK * (*pz-(C * x));
    Sigma=(I - *pK* C)* Sigma;

}

void KalmanFilter::show_result() {
    x.write();
    Sigma.write();
    cout<<endl;
}
