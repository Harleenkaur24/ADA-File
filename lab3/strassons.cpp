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

Matrix strassen_multiply(const Matrix& A,const Matrix& B){
    int n = A.size();
    if(n == 1){
        return {{A[0][0]*B[0][0]}};
    }

    int newSize = n / 2;

    Matrix A11(newSize, vector<int>(newSize));
    Matrix A12(newSize, vector<int>(newSize));
    Matrix A21(newSize, vector<int>(newSize));
    Matrix A22(newSize, vector<int>(newSize));

    Matrix B11(newSize, vector<int>(newSize));
    Matrix B12(newSize, vector<int>(newSize));
    Matrix B21(newSize, vector<int>(newSize));
    Matrix B22(newSize, vector<int>(newSize));

    // Partitioning input matrices into submatrices
    for(int i = 0; i < newSize; ++i){
        for(int j = 0; j < newSize; ++j){
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // Strassen's matrix multiplication steps
    Matrix P1 = strassen_multiply(add_matrices(A11, A22), add_matrices(B11, B22));
    Matrix P2 = strassen_multiply(add_matrices(A21, A22), B11);
    Matrix P3 = strassen_multiply(A11, add_matrices(B12, B22));
    Matrix P4 = strassen_multiply(A22, add_matrices(B21, B11));
    Matrix P5 = strassen_multiply(add_matrices(A11, A12), B22);
    Matrix P6 = strassen_multiply(add_matrices(A21, A11), add_matrices(B11, B12));
    Matrix P7 = strassen_multiply(add_matrices(A12, A22), add_matrices(B21, B22));

    // Calculating submatrices of the result
    Matrix C11 = add_matrices(add_matrices(P1, P4), add_matrices(P7, P5));
    Matrix C12 = add_matrices(P3, P5);
    Matrix C21 = add_matrices(P2, P4);
    Matrix C22 = add_matrices(add_matrices(P1, P3), add_matrices(P6, P2));

    // Combining submatrices to get the result
    return combine_matrices(C11, C12, C21, C22);
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
            Matrix result = strassen_multiply(A,B);
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
