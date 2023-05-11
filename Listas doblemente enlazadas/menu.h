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
        cout << "\nIngrese la opcion deseada:\n\n1)Lista doblemente enlazada\n2)Salir\n\n";
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
             << "4)Inserta despues de...\n"
             << "5)Eliminar inicio\n"
             << "6)Eliminar final\n"
             << "7)Eliminar nodo específico\n"
             << "8)Modificar\n"
             << "9)Mostrar\n"
             << "10)Salir\n\n";
        cin >>
            aux;
        if ((aux <= 0) || (aux > 10))
        {
            cout << "\nIngrese un numero valido...";
            cin >> aux;
        }
    } while ((aux <= 0) || (aux > 10));

    return aux;
}