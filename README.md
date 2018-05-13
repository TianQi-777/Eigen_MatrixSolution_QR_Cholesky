# Eigen_MatrixSolution_QR_Cholesky
This is a small demo to learn Eigen library for QR,Cholesky decomposition and dynamic size matrix.

## Problem Description
Let the linear equation **Ax = b**, under the premise that **A** is a square matrix.When **A** is a 100 × 100 random matrix, use QR and Cholesky decomposition to find the x.  
Notes：Eigen fixed size matrix supports up to 50, we should use a dynamic size matrix.

## Additional Prerequisites for this demo
Besides,to build this demo, you need the followings:  

**Eigen3**  
Download and install instructions can be found at: http://eigen.tuxfamily.org.  

**C++11 or C++0x Compiler**  
Use the some functionalities of C++11.  

## Build and Run
```
cd XX/XX(include eigenMatrix.cpp and CMakeLists.txt)  
mkdir build  
cd build  
cmake ..  
make -j2  
./eigenMatrix  
```
Notes: You can use IDE for better display.

