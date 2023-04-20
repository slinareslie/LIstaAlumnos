#include <iostream>
#include <cstdlib>

using namespace std;

int menu_principal();
int menu_ordenados();
int menu_desordenados();

int menu_principal()
{
    int aux;
    do
    {
        cout << "\n\t\tREGISTRO DE ALUMNOS\n\n";
        cout << "\nIngrese la opcion deseada:\n\n1)Arreglos ordenados\n2)Arreglos desordenados\n3)Salir\n\n";
        cin >> aux;
        if ((aux <= 0) && (aux > 3))
        {
            cout << "\nIngrese un numero valido...";
            cin >> aux;
        }
    } while ((aux <= 0) && (aux > 3));

    return aux;
}

int menu_ordenados()
{
    int aux;
    do
    {
        cout << "\n\t\tARREGLOS ORDENADOS\n\n";
        cout << "\nIngrese la opcion deseada:\n\n1)Insertar\n2)Eliminar\n3)Modificar\n4)Mostrar\n5)Salir\n\n";
        cin >> aux;
        if ((aux <= 0) || (aux > 5))
        {
            cout << "\nIngrese un numero valido...";
            cin >> aux;
        }
    } while ((aux <= 0) || (aux > 5));

    return aux;
}

int menu_desordenados()
{
    int aux;
    do
    {
        cout << "\n\t\tARREGLOS DESORDENADOS\n\n";
        cout << "\nIngrese la opcion deseada:\n\n1)Insertar\n2)Eliminar\n3)Modificar\n4)Mostrar\n5)Salir\n\n";
        cin >> aux;
        if ((aux <= 0) || (aux > 5))
        {
            cout << "\nIngrese un numero valido...";
            cin >> aux;
        }
    } while ((aux <= 0) || (aux > 5));

    return aux;
}