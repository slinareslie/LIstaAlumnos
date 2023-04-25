#include <iostream>
using namespace std;

void generarCuadradoMagico(int n)
{
    int cuadrado[n][n] = {}, num = 1, i = 0, j = n / 2;

    while (num <= n * n)
    {
        cuadrado[i][j] = num++;
        if (cuadrado[(i + n - 1) % n][(j + 1) % n] != 0)
        {
            j = (j + n - 1) % n;
        }
        else
        {
            i = (i + n - 1) % n;
            j = (j + 1) % n;
        }
    }

    cout << "Cuadrado magico de dimension " << n << ":" << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << cuadrado[i][j] << "\t";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cout << "Ingrese la dimension del cuadrado magico (debe ser un numero impar): ";
    cin >> n;

    if (n % 2 == 0)
    {
        cout << "La dimension debe ser un numero impar." << endl;
    }
    else
    {
        generarCuadradoMagico(n);
    }

    return 0;
}