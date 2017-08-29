#include <iostream>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <cstdlib>
using namespace std;

double random(double a, double b) {
    return a + (b-a)*rand()/RAND_MAX;
}

class Matrix {
private:
    int m_cols, m_rows;
    double* m_pdata;
public:
    Matrix();
    Matrix(double* , int , int );
    Matrix(int );
    void printMatrix();
    //friend Matrix& multiplyMatrix1(Matrix&, Matrix& );
    friend void multiplyMatrix_Naive(Matrix&, Matrix& );
    ~Matrix();
};

Matrix::Matrix() {};

Matrix::Matrix(double *pdata, int cols, int rows) {
    m_cols = cols;
    m_rows = rows;
    m_pdata = new double [m_cols*m_rows];
    if (pdata!=NULL) {
        for (int i=0; i<m_rows; i++) {
            for (int j=0; j<m_cols; j++) {
                m_pdata[i*m_cols+j] = pdata[i*m_cols+j];
            }
        }
    }
    else {
        for (int i=0; i<m_rows; i++) {
            for (int j=0; j<m_cols; j++) {
                m_pdata[i*m_cols+j] = 0;
            }
        }
    }
}

Matrix::Matrix(int size) {
    m_cols = size;
    m_rows = size;
    m_pdata = new double [m_cols*m_rows];
    for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++) {
            m_pdata[i*m_cols+j] = random(-10.0, 10.0);
        }
    }
}

void Matrix::printMatrix() {
    for (int i=0; i<m_rows; i++) {
        for (int j=0; j<m_cols; j++) {
            cout << setw(7) << setprecision(2) << fixed << m_pdata[i*m_cols+j] << " ";
        }
        cout << endl;
    }
}

void multiplyMatrix_Naive(Matrix& A, Matrix& B) { //3 loops -> O(n^3)
    Matrix result(NULL,A.m_rows,B.m_cols);
    for(int i = 0; i < A.m_rows; i++) {
        for(int j = 0; j < B.m_cols; j++) {
            for(int k = 0; k < A.m_cols; k++) {
                result.m_pdata[i*result.m_cols+j] += A.m_pdata[i*A.m_cols+k] * B.m_pdata[k*B.m_cols+j];
            }
        }
    }
    cout << endl;
    cout << "Multiplied Matrix:\n";
    result.printMatrix();
}


Matrix::~Matrix() {
    delete m_pdata;
    m_pdata = NULL;
}

int main() {
    srand(time(0));

    Matrix a(2);
    Matrix b(2);

    cout << "Matrix A:" << endl; a.printMatrix(); cout << endl;
    cout << "Matrix B:" << endl; b.printMatrix(); cout << endl;

    multiplyMatrix_Naive(a,b);
    //c.printMatrix(); cout << endl;



    return 0;
}