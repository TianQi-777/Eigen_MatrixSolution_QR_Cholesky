#include <iostream>
using namespace std;
#include <ctime>
// Eigen 部分
#include <Eigen/Core>
// 稠密矩阵的代数运算（逆，特征值等）
#include <Eigen/Dense>

#define MATRIX_SIZE 100

int main( int argc, char** argv )
{
    //动态矩阵
    Eigen::MatrixXd matrix_x;

    // 解方程
    // 我们求解 matrix_NN * x = v_Nd 这个方程
    // N的大小在前边的宏里定义，它由随机数生成
    // 直接求逆自然是最直接的，但是求逆运算量大

    Eigen::Matrix< double, MATRIX_SIZE, MATRIX_SIZE > matrix_NN;
    matrix_NN = Eigen::MatrixXd::Random( MATRIX_SIZE, MATRIX_SIZE );  //MatrixXd为动态矩阵
    cout<<"matrix_NN=\n"<<matrix_NN<<endl;
    Eigen::Matrix< double, MATRIX_SIZE, MATRIX_SIZE > semidefinite_matrix_NN=matrix_NN.transpose()*matrix_NN; //A^T*A生成正定阵
    cout<<"semidefinite_matrix_NN=\n"<<semidefinite_matrix_NN<<endl;

    Eigen::Matrix< double, MATRIX_SIZE,  1> v_Nd;
    v_Nd = Eigen::MatrixXd::Random( MATRIX_SIZE,1 );
    cout<<"\nv_Nd=\n"<<v_Nd.transpose()<<endl;


    clock_t time_stt = clock(); // 计时
    // 直接求逆
    Eigen::Matrix<double,MATRIX_SIZE,1> x = semidefinite_matrix_NN.inverse()*v_Nd;
    cout <<"\ntime use in normal inverse is " << 1000* (clock() - time_stt)/(double)CLOCKS_PER_SEC << "ms"<< endl;
    cout<<"直接求逆：x=\n"<<x.transpose()<<endl;

	// QR分解
    time_stt = clock();
    x = semidefinite_matrix_NN.colPivHouseholderQr().solve(v_Nd);
    cout <<"\ntime use in Qr decomposition is " <<1000*  (clock() - time_stt)/(double)CLOCKS_PER_SEC <<"ms" << endl;
    cout<<"QR分解：x=\n"<<x.transpose()<<endl;

    // Cholesky分解(一定要针对正定阵)
    time_stt = clock();
    x = semidefinite_matrix_NN.llt().solve(v_Nd);
    cout <<"\ntime use in Cholesky decomposition is " <<1000*  (clock() - time_stt)/(double)CLOCKS_PER_SEC <<"ms" << endl;
    cout<<"Cholesky分解：x=\n"<<x.transpose()<<endl;

    //改进的Cholesky分解(一定要针对正定阵)
    x = semidefinite_matrix_NN.ldlt().solve(v_Nd);
    cout<<"\nldlt分解：x=\n"<<x.transpose()<<endl;
    //LU分解
    x = semidefinite_matrix_NN.lu()  .solve(v_Nd);
    cout<<"lu分解：x=\n"<<x.transpose()<<endl;

    return 0;
}
