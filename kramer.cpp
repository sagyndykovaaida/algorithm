#include <iostream>
#include <cmath>
using namespace std;

const int MAX_SIZE = 10;

double det(double mat[MAX_SIZE][MAX_SIZE], int n) {
    double d = 0;
    if (n == 1) {
        return mat[0][0];
    }
    if (n == 2) {
        return mat[0][0]*mat[1][1] - mat[0][1]*mat[1][0];
    }
    for (int k = 0; k < n; k++) {
        double temp[MAX_SIZE][MAX_SIZE];
        int i, j;
        for (i = 1; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (j < k) {
                    temp[i-1][j] = mat[i][j];
                } else if (j > k) {
                    temp[i-1][j-1] = mat[i][j];
                }
            }
        }
        d += mat[0][k]*pow(-1.0, k)*det(temp, n-1);
    }
    return d;
}

int main() {
    double A[MAX_SIZE][MAX_SIZE], b[MAX_SIZE], x[MAX_SIZE];
    int n;
    cout << "size of the matrix: ";
    cin >> n;
    cout << "elements of the matrix A: ";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }
    cout << "elements of the vector b: ";
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    double D = det(A, n);
    if (D == 0) {
        cout << "No unique solution exists." << endl;
    } else {
        for (int k = 0; k < n; k++) {
            double Ak[MAX_SIZE][MAX_SIZE];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (j == k) {
                        Ak[i][j] = b[i];
                    } else {
                        Ak[i][j] = A[i][j];
                    }
                }
            }
            x[k] = det(Ak, n)/D;
        }
        cout << "The solution is: ";
        for (int i = 0; i < n; i++) {
            cout << x[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
