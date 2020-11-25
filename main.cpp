#include <iostream>
#include <iomanip>
using namespace std;
void t1()
{
    int k;
    cout << "¬ведите 1 - преобразовать двумерный массив в одномерный или 2 - преобразовать одномерный массив в двумерный: ";
    cin >> k;
    if (k == 1) {
        double** arr;
        int n, m;
        cout << "¬ведите кол-во строк: ";
        cin >> n;
        cout << "¬ведите кол-во столбцов: ";
        cin >> m;
        arr = new double* [n];
        for (int i = 0; i < n; i++)
            arr[i] = new double[m];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                cout << "¬ведите элемент массива: ";
                cin >> arr[i][j];
            }
        int* a = new int[n * m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i * (m)+j] = arr[i][j];
            }
        }
        cout << "ƒвумерный массив" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cout << arr[i][j] << "  ";
            cout << endl;
        }
        cout << "ќдномерный массив" << endl;
        for (int i = 0; i < n * m; i++) {
            cout << a[i] << "   ";
        }
    }
    else {
        double **arr;
        int m, n;
        cout << "¬ведите кол-во строк в двумерном массиве: ";
        cin >> m;
        cout << "¬ведите кол-во столбцов в двумерном массиве: ";
        cin >> n;
        arr = new double* [m];
        for (int i = 0; i < m; i++)
            arr[i] = new double[n];
        int* a = new int[m * n];
        for (int i = 0; i < m * n; i++) {
            cout << "¬ведите элемент массива: ";
            cin >> a[i];
        }
        for (int i = 0; i < m * n; i++) {
            arr[i / n][i % n] = a[i];
        }
        cout << "ќдномерный массив" << endl;
        for (int i = 0; i < n * m; i++) {
            cout << a[i] << "   ";
        }
        cout << endl << "ƒвумерный массив" << endl;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                cout << arr[i][j] << "  ";
            cout << endl;
        }
    }
}
void t2() {
    int n, m;
    cout << "¬ведите n и m: ";
    cin >> n >> m;
    int **a;
    a = (int**) malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        a[i] = (int*) malloc(m * sizeof(int));
    }
    int i=0, j, k = 0, p=1;
    while (i < n * m) {
        k++;
        for (j = k - 1; j < m - k + 1; j++) {
            a[k - 1][j] = p++;
            i++;
        }
        for (j = k; j < n - k + 1; j++) {
            a[j][m - k] = p++;
            i++;
        }
        for (j = m - k - 1; j >= k - 1; j--){
            a[n - k][j] = p++;
            i++;
        }
        for (j = n - k - 1; j >= k; j--){
            a[j][k - 1] = p++;
            i++;
        }
     }

    for (int q = 0; q < n; q++) {
        for (int w = 0; w < m; w++) {
            cout << "   " << a[q][w];
        }
        cout << endl;
    }
    cout << endl;
    for(i = 0; i <= n - 1; i++){
        for(j = 0; j <= m - 1; j++) {
            a[i][j] = abs(i - j) + 1;
        }
    }
    for (int q = 0; q < n; q++) {
        for (int w = 0; w < m; w++) {
            cout << "   " << a[q][w];
        }
        cout << endl;
    }
}
void t4() {
    int n, m, i, j, k, t, x=0, y=0;
    cout << "¬ведите n и m: ";
    cin >> n >> m;
    int **a;
    a = (int**) malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        a[i] = (int*) malloc(m * sizeof(int));
    }
    cout << "¬ведите элементы массива: ";
    for (i = 0; i <= n - 1; i++){
        for (j = 0; j <= m - 1; j++){
            cin >> a[i][j];
        }
    }
    for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++)
                cout << a[i][j] << "  ";
            cout << endl;
    }
    cout << endl;
    for (i = 0; i < m - 1; i++) {
        for (j = 0; j < m - 1 - i; j++){
            for (k = 0; k <= n - 1; k++){
                x += a[k][j];
                y += a[k][j + 1];
            }
            if(x > y){
                for (k = 0; k <= n - 1; k++){
                    t = a[k][j];
                    a[k][j] = a[k][j + 1] ;
                    a[k][j + 1] = t;
                }
            }
            x = 0; y = 0;
        }
    }
    for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cout << a[i][j] << "  ";
            cout << endl;
    }
}
void g(double** a, int n) {
    double k;
    for (int i = 0; i < n; i++) {
        k = a[i][i];
        for (int j = i; j < n + 1; j++) {
            a[i][j] /= k;
        }
        for (int c = i + 1; c < n; c++) {
            double m = a[c][i];
            for (int g = i; g < n + 1; g++) {
                a[c][g] -= a[i][g] * m;
            }
        }
    }
}
void t5() {
    int n;
    setlocale(LC_ALL, "Russian");
    cout << "¬ведите кол-во  уравнений в системе: ";
    cin >> n;
    double **a;
    a = new double* [n];
    for (int i = 0; i < n; i++) {
        a[i] = new double [n + 1];
    }
    cout << "¬ведите коэф. при X, начина€ с ’1, и чему равны уравнени€: ";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    g(a, n);
    double k;
    // обратный ход
    for (int i = n - 1; i >= 0; i--) {
        for (int c = i; c > 0; c--) {
            double m = a[c-1][i];
            for (int g = i; g < n + 1; g++) {
                a[c-1][g] -= a[i][g] * m;
            }
        }
    }
    cout << "X1 = " << a[0][3] << endl;
    cout << "X2 = " << a[1][3] << endl;
    cout << "X3 = " << a[2][3] << endl;
}
int main() {
    setlocale(LC_ALL, "Russian");
    int x = 10;
    while (x) {
        cout << "¬ведите номер задачи: ";
        cin >> x;
        if (x == 1) t1();
        if (x == 2) t2();
        if (x == 4) t4();
        if (x == 5) t5();
    }
}
