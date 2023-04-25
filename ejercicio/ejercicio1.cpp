#include <bits/stdc++.h>

using namespace std;
int comprobar(int[][100], int, int, int);

int main()
{
    int tam = 0, n = 0;
    cout << "\nIngrese el tamanio de la rejilla cuadrangular mayor o igual a 5\n";
    cin >> tam;
    int matriz[100][100];
    int matriz1[100][100];
    string matrizGuia[100][100];
    cout << "\nIngrese la cantidad de generaciones\n";
    cin >> n;

    for (int i = 0; i < tam; i++)
    {
        for (int j = 0; j < tam; j++)
        {
            matriz[i][j] = 0;
        }
    }

    /*for (int i = 0; i < tam; i++)
    {
        for (int j = 0; j < tam; j++)
        {
            string aux = to_string(i) + to_string(j);
            matrizGuia[i][j] = aux;
        }
    }

    cout << "\n\n";
    for (int i = 0; i < tam; i++)
    {
        for (int j = 0; j < tam; j++)
        {
            cout << right << setw(4) << setfill(' ') << matrizGuia[i][j] << ' ';
        }

        cout << "\n";
    }


    system("pause");*/

    if (tam % 2 == 0)
    {
        int mid = (tam - 1) / 2;
        matriz[mid][mid] = 1;
        matriz[mid][mid - 1] = 1;
        matriz[mid + 1][mid - 2] = 1;
        matriz[mid + 1][mid + 1] = 1;
        matriz[mid + 1][mid + 2] = 1;
        matriz[mid + 2][mid] = 1;
        matriz[mid + 2][mid - 1] = 1;
    }
    else
    {
        int mid = (tam - 1) / 2;
        matriz[mid - 1][mid] = 1;
        matriz[mid - 1][mid - 1] = 1;
        matriz[mid][mid - 2] = 1;
        matriz[mid][mid + 1] = 1;
        matriz[mid][mid + 2] = 1;
        matriz[mid + 1][mid - 1] = 1;
        matriz[mid + 1][mid] = 1;
    }

    system("cls");
    cout << "Esta es la generacion : 1\n\n";
    for (int i = 0; i < tam; i++)
    {
        for (int j = 0; j < tam; j++)
        {
            cout << right << setw(4) << setfill(' ') << matriz[i][j] << ' ';
        }

        cout << "\n";
    }
    cout << "\n\n";
    system("pause");
    system("cls");

    for (int k = 1; k < n; k++)
    {
        cout << "Esta es la generacion: " << k + 1 << "\n\n";
        if (k % 2 == 0)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    matriz[i][j] = comprobar(matriz1, matriz1[i][j], i, j);
                }
            }

            for (int i = 0; i < tam; i++)
            {
                for (int j = 0; j < tam; j++)
                {
                    cout << right << setw(4) << setfill(' ') << matriz[i][j] << ' ';
                }

                cout << "\n";
            }
        }
        else
        { // se copia en matriz 1
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    matriz1[i][j] = comprobar(matriz, matriz[i][j], i, j);
                }
            }

            for (int i = 0; i < tam; i++)
            {
                for (int j = 0; j < tam; j++)
                {
                    cout << right << setw(4) << setfill(' ') << matriz1[i][j] << ' ';
                }

                cout << "\n";
            }
        }
        cout << "\n\n";
        system("pause");
        system("cls");
    }

    return 0;
}

int comprobar(int matriz[][100], int n, int x, int y)
{
    int cont = 0;

    for (int i = x - 1; i <= x + 1; i++)
    {
        for (int j = y - 1; j <= y + 1; j++)
        {
            if (i != x || j != y)
            {
                if (matriz[i][j] == 1)
                {
                    cont++;
                }
            }
        }
    }

    if (cont <= 1)
    {
        return 0;
    }
    else if (cont == 2 || cont == 3)
    {
        if (n == 1)
        {
            return 1;
        }
        else
        {
            if (cont == 3)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
    else
    {
        return 0;
    }
}