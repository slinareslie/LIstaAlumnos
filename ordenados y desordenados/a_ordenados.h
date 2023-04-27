#include "alumno.h"
#include <iostream>
#include <iomanip>

using namespace std;

int ordenar(Alumno[], int);
int buscar(Alumno[], int, string);
void insertar_o(Alumno[], int &, int);
void eliminar_o(Alumno[], int &, string);
void modificar_o(Alumno[], int &, string);
void mostrar_o(Alumno[], int);

int ordenar(Alumno x[], int n)
{
    Alumno temp;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (x[i].codigo > x[j].codigo)
            {
                temp = x[i];
                x[i] = x[j];
                x[j] = temp;
            }
        }
    }
}

int buscar(Alumno x[], int n, string codigo)
{
    int ini = 0, fin = n - 1;
    while (ini <= fin)
    {
        int met = (ini + fin) / 2;
        if (x[met].codigo == codigo)
        {
            return met;
        }
        else if (x[met].codigo < codigo)
        {
            ini = met + 1;
        }
        else
        {
            fin = met - 1;
        }
    }
    return -(ini + 1);
}

void insertar_o(Alumno x[], int &n, int max)
{
    bool flag = true;
    string aux;
    if (n == max)
    {
        cout << "\nNo hay espacio para agregar otro alumno...\n";
    }
    else
    {
        cout << "\nIngrese el codigo del estudiante (anio-numero): \n";
        cin >> aux;
        int pos = buscar(x, n, aux);
        if (pos >= 0)
        {
            flag = false;
            cout << "\nEste codigo de estudiante ya existe, necesitara volver a entrar a la opcion...\n\n";
        }
        if (flag)
        {
            if (pos < 0)
            {
                pos = -(pos + 1);
            }
            for (int i = n; i > pos; i--)
            {
                x[i] = x[i - 1];
            }
            x[pos].codigo = aux;
            cin.ignore();
            cout << "\nIngrese los apellidos del estudiante: \n";
            getline(cin, x[pos].apellido);
            cout << "\nIngrese el nombre del estudiante: \n";
            getline(cin, x[pos].nombre);
            cout << "\nIngrese la nota 1: \n";
            cin >> x[pos].nota1;
            cout << "\nIngrese la nota 2: \n";
            cin >> x[pos].nota2;
            x[pos].promedio = (x[pos].nota1 + x[pos].nota2) / 2;
            n++;
        }
    }
}

void eliminar_o(Alumno x[], int &n, string codigo)
{
    int opc, pos;

    if (n > 0)
    {
        pos = buscar(x, n, codigo);

        if (pos < 0)
        {
            cout << "\nNO se encontró el codigo ingresado...\n\n";
        }
        else
        {
            system("cls");
            ver_alumno(x[pos], pos);
            cout << "Estas seguro de eliminar el alumno?\n\n1)Si\n2)NO\n\n";
            cin >> opc;
            if (opc == 1)
            {
                for (int j = pos; j < n - 1; j++)
                {
                    x[j] = x[j + 1];
                }
                n--;
                cout << "\n\nEl alumno se elimino correctamente\n\n";
            }
        }
    }
    else
    {
        cout << "\nNO existe ningun alumno registrado...\n\n";
    }
}

void modificar_o(Alumno x[], int &n, string codigo)
{
    int pos = buscar(x, n, codigo);
    int k = 0;
    bool flag = true;
    int opc;
    if (n > 0)
    {
        if (pos < 0)
        {
            cout << "\nNO se encontró el codigo ingresado...\n\n";
        }
        else
        {
            do
            {
                ver_alumno(x[pos], pos);
                cout << "\n\nIngrese que dato desea cambiar:\n\n1)Codigo\n2)Apellidos\n3)Nombres\n4)Nota 1\n5)Nota 2\n6)Salir\n\n";
                cin >> opc;
                string a;
                float b;
                system("cls");
                ver_alumno(x[pos], pos);

                if (opc == 1)
                {
                    cout << "\n\nIngrese el nuevo codigo:\n";
                    cin >> a;

                    if (buscar(x, n, a) == pos)
                    {
                        flag = false;
                    }
                    else if (buscar(x, n, a) >= 0)
                    {
                        flag = false;
                        cout << "\nEste codigo de estudiante ya existe, necesitara volver a entrar a la opcion...\n\n";
                    }

                    if (flag)
                    {
                        x[pos].codigo = a;
                        ordenar(alumno, n);
                        system("cls");
                        cout << "\tLos nuevos datos del alumno son:\n\n";
                        ver_alumno(x[buscar(alumno, n, a)], buscar(alumno, n, a));
                    }
                }
                else if (opc == 2)
                {
                    cout << "\n\nIngresa el nuevo apellido:\n";
                    cin >> a;
                    x[pos].apellido = a;
                    system("cls");
                    cout << "\tLos nuevos datos del alumno son:\n\n";
                    ver_alumno(x[pos], pos);
                }
                else if (opc == 3)
                {
                    cout << "\n\nIngresa el nuevo nombre:\n";
                    cin >> a;
                    x[pos].nombre = a;
                    system("cls");
                    cout << "\tLos nuevos datos del alumno son:\n\n";
                    ver_alumno(x[pos], pos);
                }
                else if (opc == 4)
                {
                    cout << "\n\nIngresa la nueva nota 1:\n";
                    cin >> b;
                    x[pos].nota1 = b;
                    x[pos].promedio = (x[pos].nota1 + x[pos].nota2) / 2;
                    system("cls");
                    cout << "\tLos nuevos datos del alumno son:\n\n";
                    ver_alumno(x[pos], pos);
                }
                else if (opc == 5)
                {
                    cout << "\n\nIngresa la nueva nota 2:\n";
                    cin >> b;
                    x[pos].nota2 = b;
                    x[pos].promedio = (x[pos].nota1 + x[pos].nota2) / 2;
                    system("cls");
                    cout << "\tLos nuevos datos del alumno son:\n\n";
                    ver_alumno(x[pos], pos);
                }
                else if (opc <= 0 && opc > 5)
                {
                    cout << "\nIngrese un numero valido...\n";
                    cin >> opc;
                }
            } while (opc <= 0 && opc > 5);
        }
    }
    else
    {
        cout << "\nNO existe ningun alumno registrado...\n\n";
    }
}

void mostrar_o(Alumno x[], int n)
{
    if (n > 0)
    {
        cout << "\nEl registro de alumnos es:\n\n";
        cout << setfill('=') << setw(79) << "=" << endl;
        cout << setfill(' ') << left << setw(5) << "No"
             << setw(15) << "codigo"
             << setw(35) << "Apellidos y Nombres"
             << setw(8) << "nota1"
             << setw(8) << "nota2"
             << setw(10) << "promedio" << endl;
        cout << setfill('=') << setw(79) << "=" << endl;
        cout << setfill(' ');

        for (int i = 0; i < n; i++)
        {
            ver_aux(x[i], i);
        }

        cout << setfill('=') << setw(79) << "=" << endl;
    }
    else
    {
        cout << "\nNO hay ningun alumno registrado...\n\n";
    }
}