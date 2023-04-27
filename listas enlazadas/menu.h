#include <iostream>
#include <cstdlib>

using namespace std;

int menu_principal();
int menu_lista();

int menu_principal()
{
    int aux;
    do
    {
        cout << "\n\t\tREGISTRO DE ALUMNOS\n\n";
        cout << "\nIngrese la opcion deseada:\n\n1)Lista enlazada\n2)Salir\n\n";
        cin >> aux;
        if ((aux <= 0) && (aux > 2))
        {
            cout << "\nIngrese un numero valido...";
            cin >> aux;
        }
    } while ((aux <= 0) && (aux > 2));

    return aux;
}

int menu_lista()
{
    int aux;
    do
    {
        cout << "\n\t\tLISTA ENLAZADA\n\n";
        cout << "\nIngrese la opcion deseada:\n\n1)Insertar inicio\n2)Insertar fin\n3)Insertar antes de ...\n4)Modificar\n5)Mostrar\n6)Salir\n\n";
        cin >> aux;
        if ((aux <= 0) || (aux > 6))
        {
            cout << "\nIngrese un numero valido...";
            cin >> aux;
        }
    } while ((aux <= 0) || (aux > 6));

    return aux;
}