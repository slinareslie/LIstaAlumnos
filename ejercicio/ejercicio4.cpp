#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    do
    {
        cout << "\nIngrese el tamanio de la matriz inicial entre 1-5:\n";
        cin >> n;
        if ((n > 5) && (n <= 0))
        {
            cout << "\nIngrese un valor valido";
        }
    } while ((n > 5) && (n <= 0));

    char ini[n][n];
    int nfin = n + (n - 1);
    char fin[nfin][nfin];

    int contchar = 97;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ini[i][j] = char(contchar);
            contchar++;
        }
    }
    cout << "\nLa matriz es:\n\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ini[i][j] << " ";
        }

        cout << "\n";
    }
    contchar = 97;

    for (int i = 0; i < nfin; i++)
    {
        for (int j = 0; j < nfin; j++)
        {
            fin[i][j] = '0';
        }
    }

    int a = n - 1, b = 0;
    for (int i = 0; i < n; i++)
    {
        int auxa = a;
        int auxb = b;
        for (int j = 0; j < n; j++)
        {
            fin[auxa][auxb] = ini[i][j];
            auxa--;
            auxb++;
        }
        a++;
        b++;
    }

    cout << "\nLa nueva matriz es:\n\n";

    for (int i = 0; i < nfin; i++)
    {
        for (int j = 0; j < nfin; j++)
        {
            cout << fin[i][j] << " ";
        }

        cout << "\n";
    }

    return 0;
}