# problem2_Kalmanfilter
This is a program for localization of free moving particle on a plane.
Input is initial position and measured positions, in terms of (x,y).
Though velocity is not observed, this code specifies it from the time-evolution of the position.
For test, please use the following test cases below.

test case 1: initial position (4 12)

six measurements (5 10) (6 8) (7 6) (8 4) (9 2) (10 0)

->result:vx is 1/dt=10, vy is -2/dt=-20.

test case 2: initial position (-4 8)

four measurements (1 4) (6 0) (11 -4) (16 -8)

->result: vx is 5/dt=50, vy is -4/dt=-40.

test case 3: initial position (1 19)

four measurements (1 17) (1 15) (1 13) (1 11)

->result: vx is 0, vy is -2/dt=-20.

test case 4: initial position (1 19)

four measurements (2 17) (0 15) (2 13) (0 11)

->result: vx is 0, vy is -2/dt=-20.
