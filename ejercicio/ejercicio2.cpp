#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tam, cont = 1, lap = 0;

    do
    {
        cout << "\nIngrese el tamanio impar de la matriz cuadrada\n";
        cin >> tam;
        if (tam % 2 == 0)
        {
            cout << "\nIngrese un numero impar...";
        }
    } while (tam % 2 == 0);

    int matriz[tam][tam];
    int ini = tam / 2;
    int inix = ini, iniy = ini + 1;
    matriz[ini][ini] = cont++;

    for (int i = 2; i < tam; i += 2)
    {
        for (int j = 0; j < i; j++)
        { // Arriba a abajo
            matriz[inix + j][iniy] = cont++;
        }
        for (int j = 0; j < i; j++)
        { // Derecha a izquierda
            matriz[inix + (i - 1)][iniy - 1 - j] = cont++;
        }
        for (int j = 0; j < i; j++)
        { // Abajo a arriba
            matriz[inix + (i - 2) - j][iniy - i] = cont++;
        }
        for (int j = 0; j < i; j++)
        { // Izquierda a derecha;
            matriz[inix - 1][iniy - (i - 1) + j] = cont++;
        }

        inix--;
        iniy++;
    }

    cout << "\n\n";
    for (int i = 0; i < tam; i++)
    {
        for (int j = 0; j < tam; j++)
        {
            cout << right << setw(5) << setfill(' ') << matriz[i][j] << ' ';
        }

        cout << "\n";
    }

    return 0;
}