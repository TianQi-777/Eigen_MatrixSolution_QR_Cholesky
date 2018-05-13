# Eigen_MatrixSolution_QR_Cholesky
This is a small demo to learn Eigen library for QR,Cholesky decomposition and dynamic size matrix

## Problem Description
Let the linear equation Ax = b, under the premise that A is a square matrix.When A is a 100 × 100 random matrix, use QR and Cholesky decomposition to find the x  
Notes：Eigen fixed size matrix supports up to 50, we should use a dynamic size matrix

## Compile and Run
cd XX/XX(include eigenMatrix.cpp and CMakeLists.txt)  
mkdir build  
cd build  
cmake ..  
make -j2  
./eigenMatrix  
Notes: You can use IDE for better display
