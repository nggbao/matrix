#include <iostream>
#include <iomanip>
using namespace std;

class Matrix {
private:
    int m_cols, m_rows;
    double* m_pdata;

public:
    Matrix();
    Matrix(double*, int, int);
    friend Matrix& addMatrix(const Matrix, const Matrix, int);
    void printMatrix();

};

Matrix::Matrix() {
    //do nothing
}

Matrix::Matrix(double *pdata, int cols, int rows) {
    m_cols = cols;
    m_rows = rows;
    m_pdata = new double [cols*rows];
    if (pdata!=NULL) {
        for (int i=0; i<rows; i++) {
            for (int j=0; j<cols; j++) {
                m_pdata[i*cols+j] = pdata[i*cols+j];
            }
        }
    }
}

Matrix& addMatrix(const Matrix A, const Matrix B, int size) {
    Matrix C(NULL,size,size);
    for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++) {
            C.m_pdata[i*size+j] = 0;
        }
    }
    int r=0;
    while (r<size) {
        int c=0;
        while (c<size) {
            C.m_pdata[r*size+c] = A.m_pdata[r*size+c] + B.m_pdata[r*size+c];
            c++;
        }
        r++;
    }
    return C;
}

void Matrix::printMatrix() {
    for (int i=0; i<m_rows; i++) {
        for (int j=0; j<m_cols; j++) {
            cout << setw(5) << m_pdata[i*m_cols+j];
        }
        cout << endl;
    }
}
int main() {
    double arr1[2][2] = {1,2,3,4};
    double arr2[2][2] = {5,6,7,8};

    Matrix m1((double*)arr1,2,2);
    m1.printMatrix(); cout << endl;
    Matrix m2((double*)arr2,2,2);
    m2.printMatrix(); cout << endl;

    Matrix m3;
    m3 = addMatrix(m1,m2,2);
    m3.printMatrix();

    return 0;
}