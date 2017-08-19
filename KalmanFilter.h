//
// Created by 研究用 on 2017/08/15.
//

#ifndef PROBLEM2_KALMANFILTER_KALMANFILTER_H
#define PROBLEM2_KALMANFILTER_KALMANFILTER_H

#include <string>
#include <limits>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

#include "vector.h"
#include "matrix.h"

using namespace std;


class KalmanFilter {
private:
    Vector x;   //mean of state vector
    Matrix Sigma, A,C,Q,I;  //covariance matrix,
                            //matrix for equation of motion
                            //measurement matrix, noise matrix, unit matrix

public:
    KalmanFilter(); //constructor
    void move();
    void measure();
    void show_result();

};


#endif //PROBLEM2_KALMANFILTER_KALMANFILTER_H
