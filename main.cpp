#include <iostream>
#include <vector>
using namespace std;

// Función para verificar si una reina puede ser colocada en la posición (row, col)
bool esSeguro(vector<vector<int>> &tablero, int row, int col, int N) {
    for (int i = 0; i < row; i++)
        if (tablero[i][col] == 1)
            return false;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (tablero[i][j] == 1)
            return false;

    for (int i = row, j = col; i >= 0 && j < N; i--, j++)
        if (tablero[i][j] == 1)
            return false;

    return true;
}

// Función recursiva para resolver el problema N-Queens
bool resolverNQueens(vector<vector<int>> &tablero, int row, int N) {
    if (row >= N)
        return true;

    for (int col = 0; col < N; col++) {
        if (esSeguro(tablero, row, col, N)) {
            tablero[row][col] = 1;

            if (resolverNQueens(tablero, row + 1, N))
                return true;

            tablero[row][col] = 0;
        }
    }
    return false;
}

int main() {
    int N;

    // Leer entrada estándar
    if (!(cin >> N)) {
        cerr << "Error al leer el valor de N. Asegúrate de proporcionar un número válido." << endl;
        return 1;
    }

    // Validar entrada
    if (N < 4 || N > 8) {
        cerr << "N debe estar entre 4 y 8." << endl;
        return 1;
    }

    // Crear un tablero NxN inicializado con ceros
    vector<vector<int>> tablero(N, vector<int>(N, 0));

    if (resolverNQueens(tablero, 0, N)) {
        cout << "Input:\n" << N << endl;
        cout << "Output:\n";
        for (int i = 0; i < N; i++) {
            cout << "{ ";
            for (int j = 0; j < N; j++) {
                cout << tablero[i][j];
                if (j < N - 1)
                    cout << ", ";
            }
            cout << " }" << endl;
        }
    } else {
        cerr << "No se encontró solución para N = " << N << "." << endl;
    }

    return 0;
}
