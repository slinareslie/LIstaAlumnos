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
        cout << "\nIngrese la opcion deseada:\n\n"
             << "1)Insertar inicio\n"
             << "2)Insertar fin\n"
             << "3)Insertar antes de ...\n"
             << "4)Modificar\n"
             << "5)Mostrar\n"
             << "6)Insertar despues de ...\n"
             << "7)Eliminar alumno del inicio\n"
             << "8)Eliminar el final\n"
             << "9)Eliminar por codigo\n"
             << "10)Eliminar antes de ...\n"
             << "11)Eliminar despues de ...\n"
             << "12)Buscar por codigo\n"
             << "13)Salir\n\n";
        cin >> aux;
        if ((aux <= 0) || (aux > 13))
        {
            cout << "\nIngrese un numero valido...";
            cin >> aux;
        }
    } while ((aux <= 0) || (aux > 13));

    return aux;
}