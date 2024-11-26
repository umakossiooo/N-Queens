#include <iostream>
#include <vector>
using namespace std;

// Función para verificar si una reina puede ser colocada en la posición (row, col)
bool esSeguro(vector<vector<int>> &tablero, int row, int col, int N) {
    // Revisar la columna actual hacia arriba
    for (int i = 0; i < row; i++)
        if (tablero[i][col] == 1)
            return false;

    // Revisar la diagonal superior izquierda
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (tablero[i][j] == 1)
            return false;

    // Revisar la diagonal superior derecha
    for (int i = row, j = col; i >= 0 && j < N; i--, j++)
        if (tablero[i][j] == 1)
            return false;

    return true;
}

// Función recursiva para resolver el problema N-Queens
bool resolverNQueens(vector<vector<int>> &tablero, int row, int N) {
    // Si se colocaron todas las reinas
    if (row >= N)
        return true;

    // Probar todas las columnas en la fila actual
    for (int col = 0; col < N; col++) {
        if (esSeguro(tablero, row, col, N)) {
            // Colocar la reina en (row, col)
            tablero[row][col] = 1;

            // Llamada recursiva para la siguiente fila
            if (resolverNQueens(tablero, row + 1, N))
                return true;

            // Backtracking: quitar la reina de (row, col)
            tablero[row][col] = 0;
        }
    }

    // Si no se puede colocar una reina en ninguna columna
    return false;
}

int main() {
    int N;
    cout << "Enter the value of N (4-8): ";
    cin >> N;

    // Validar entrada
    if (N < 4 || N > 8) {
        cout << "N has to be between 4 and 8." << endl;
        return 1;
    }

    // Crear un tablero NxN inicializado con ceros
    vector<vector<int>> tablero(N, vector<int>(N, 0));

    if (resolverNQueens(tablero, 0, N)) {
        cout << "Input= " << N << ":" << endl;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << tablero[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No solution found." << endl;
    }

    return 0;
}
