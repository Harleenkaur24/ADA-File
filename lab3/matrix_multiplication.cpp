#include<iostream>
#include<fstream>
#include<time.h>
#include<vector>
using namespace std;
void WriteDataToFile(int i, double avgTime){
    ofstream fout("data.txt", ios::app);
    if(fout.is_open()){
        fout<<i<<","<<avgTime<<endl;
        fout.close();
    }
    else{
        cout<<"Unable to open file for writing data. "<<endl;
    }
}
void WriteToFile(int i, double avgTime){
    ofstream fout("data1.txt", ios::app);
    if(fout.is_open()){
        fout<<i<<","<<avgTime<<endl;
        fout.close();
    }
    else{
        cout<<"Unable to open file for writing data. "<<endl;
    }
}
typedef vector<vector<int>> Matrix;

Matrix add_matrices(const Matrix& A, const Matrix& B){
    int n = A.size();
    int m = A[0].size();
    Matrix result(n, vector<int>(m,0));

    for(int i=0;i<n;++i){
        for(int j=0;j<m;j++){
            result[i][j]=A[i][j]+B[i][j];
        }
    }
    return result;
}

Matrix combine_matrices(const Matrix& C11, const Matrix& C12, const Matrix& C21, const Matrix& C22){
    int n = C11.size();
    int m = C11[0].size();
    Matrix result(2*n,vector<int>(2*m,0));

    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            result[i][j]=C11[i][j];
            result[i][j+m]=C12[i][j];
            result[i+n][j]=C21[i][j];
            result[i+n][j+m]=C22[i][j];
        }
    } 
    return result;
}

Matrix matrix_multiply(const Matrix& A,const Matrix& B){
    int n=A.size();
    if(n==1){
        return {{A[0][0]*B[0][0]}};
    }
    Matrix A11(n/2,vector<int>(n/2));
    Matrix A12(n/2,vector<int>(n/2));
    Matrix A21(n/2,vector<int>(n/2));
    Matrix A22(n/2,vector<int>(n/2));

    Matrix B11(n/2,vector<int>(n/2));
    Matrix B12(n/2,vector<int>(n/2));
    Matrix B21(n/2,vector<int>(n/2));
    Matrix B22(n/2,vector<int>(n/2));

    for(int i=0;i<n/2;++i){
        for(int j=0;j<n/2;++j){
            A11[i][j]=A[i][j];
            A12[i][j]=A[i][j+n/2];
            A21[i][j]=A[i+ (n/2)][j];
            A22[i][j]=A[i+ (n/2)][j+ (n/2)];

            B11[i][j]=B[i][j];
            B12[i][j]=B[i][j+ (n/2)];
            B21[i][j]=B[i+ (n/2)][j];
            B22[i][j]=B[i+(n/2)][j+(n/2)];
        }
    }
    Matrix P1 = matrix_multiply(A11,B11);
    Matrix P2 = matrix_multiply(A12,B21);
    Matrix P3 = matrix_multiply(A11,B12);
    Matrix P4 = matrix_multiply(A11,B22);
    Matrix P5 = matrix_multiply(A21,B11);
    Matrix P6 = matrix_multiply(A21,B21);
    Matrix P7 = matrix_multiply(A22,B21);
    Matrix P8 = matrix_multiply(A22,B22);

    Matrix C11 = add_matrices(P1,P2);
    Matrix C12 = add_matrices(P3,P4);
    Matrix C21 = add_matrices(P5,P6);
    Matrix C22 = add_matrices(P7,P8);

    return combine_matrices(C11,C12,C21,C22);
}
void print_matrix(const Matrix& mat) {
    for (size_t i = 0; i < mat.size(); ++i) {
        for (size_t j = 0; j < mat[i].size(); ++j) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}
void initialize_random_matrix(Matrix& c,int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            c[i][j]=rand();
        }
    }
}
void complexity(){
    for(int i=2;i<200;i=2*i){
        int n=i*i*i;
        WriteToFile(i,n);
    }
}
int main(){
    double avgtime,time1,time2;
    for(int i=2;i<200;i=2*i){
    Matrix A(i,vector<int>(i,0));
    Matrix B(i,vector<int>(i,0));

    initialize_random_matrix(A,i);
    initialize_random_matrix(B,i);
    time1=(double)clock();
    for(int j=0;j<10;j++){
    Matrix result = matrix_multiply(A,B);
   // print_matrix(result);
    }
    time2=(double)clock();
    avgtime=(double)(time2-time1)/10;
    cout<<avgtime<<" ";
    WriteDataToFile(i,avgtime*500);
    }
    complexity();
    return 0;
}
