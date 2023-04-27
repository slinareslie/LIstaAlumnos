#include "alumno.h"
#include <iostream>
#include <iomanip>

using namespace std;

void ver_alumno(Alumno, int);
void ver_aux(Alumno, int);
void insertar_d(Alumno[], int &, int);
void eliminar_d(Alumno[], int &, string);
void modificar_d(Alumno[], int &, string);
void mostrar_d(Alumno[], int);

void ver_alumno(Alumno x, int i)
{
    cout << setfill('=') << setw(79) << "=" << endl;
    cout << setfill(' ') << left << setw(5) << "No"
         << setw(15) << "codigo"
         << setw(35) << "Apellidos y Nombres"
         << setw(8) << "nota1"
         << setw(8) << "nota2"
         << setw(10) << "promedio" << endl;
    cout << setfill('=') << setw(79) << "=" << endl;
    cout << setfill(' ');

    cout << setw(5) << i + 1
         << setw(15) << x.codigo
         << setw(35) << x.apellido + ", " + x.nombre
         << setw(8) << x.nota1
         << setw(8) << x.nota2
         << setw(10) << x.promedio << endl;

    cout << setfill('=') << setw(79) << "=" << endl;
}

void ver_aux(Alumno x, int i)
{
    cout << setw(5) << i + 1
         << setw(15) << x.codigo
         << setw(35) << x.apellido + ", " + x.nombre
         << setw(8) << x.nota1
         << setw(8) << x.nota2
         << setw(10) << x.promedio << endl;
}

void insertar_d(Alumno x[], int &n, int max)
{
    int i = 0;
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
        if (n > 0)
        {
            while ((i <= n) && (flag))
            {
                if (x[i].codigo == aux)
                {
                    flag = false;
                    cout << "\nEste codigo de estudiante ya existe, necesitara volver a entrar a la opcion...\n\n";
                }
                else
                {
                    i++;
                }
            }
        }
        if (flag)
        {
            x[n].codigo = aux;
            cin.ignore();
            cout << "\nIngrese los apellidos del estudiante: \n";
            getline(cin, x[n].apellido);
            cout << "\nIngrese el nombre del estudiante: \n";
            getline(cin, x[n].nombre);
            cout << "\nIngrese la nota 1: \n";
            cin >> x[n].nota1;
            cout << "\nIngrese la nota 2: \n";
            cin >> x[n].nota2;
            x[n].promedio = (x[n].nota1 + x[n].nota2) / 2;
            n++;
        }
    }
}

void eliminar_d(Alumno x[], int &n, string codigo)
{
    bool flag = true;
    int i = 0;
    int opc;

    if (n > 0)
    {
        while ((i <= n) && (flag))
        {
            if (x[i].codigo == codigo)
            {
                flag = false;
                system("cls");
                ver_alumno(x[i], i);
                cout << "Estas seguro de eliminar el alumno?\n\n1)Si\n2)NO\n\n";
                cin >> opc;
                if (opc == 1)
                {
                    for (int j = 0; j < n - 1; j++)
                    {
                        x[j] = x[j + 1];
                    }
                    n--;
                    cout << "\n\nEl alumno se elimino correctamente\n\n";
                }
            }
            else
            {
                i++;
            }
        }
        if (flag)
        {
            cout << "\nNO se encontró el codigo ingresado...\n\n";
        }
    }
    else
    {
        cout << "\nNO existe ningun alumno registrado...\n\n";
    }
}

void modificar_d(Alumno x[], int &n, string codigo)
{
    if (n > 0)
    {
        int k = 0;
        int i = 0;
        bool flag = true;
        bool flag1 = true;
        while ((i <= n) && flag)
        {
            if (x[i].codigo == codigo)
            {
                int opc = 0;
                flag = false;
                do
                {
                    ver_alumno(x[i], i);
                    cout << "\n\nIngrese que dato desea cambiar:\n\n1)Codigo\n2)Apellidos\n3)Nombres\n4)Nota 1\n5)Nota 2\n6)Salir\n\n";
                    cin >> opc;
                    string a;
                    float b;
                    system("cls");
                    ver_alumno(x[i], i);

                    if (opc == 1)
                    {
                        cout << "\n\nIngrese el nuevo codigo:\n";
                        cin >> a;

                        while ((k <= n) && (flag1))
                        {
                            if (x[i].codigo == a)
                            {
                                flag1 = false;
                            }
                            else if (x[k].codigo == a)
                            {
                                flag1 = false;
                                cout << "\nEste codigo de estudiante ya existe, necesitara volver a entrar a la opcion...\n\n";
                            }
                            else
                            {
                                k++;
                            }
                        }

                        if (flag1)
                        {
                            x[i].codigo = a;
                            system("cls");
                            cout << "\tLos nuevos datos del alumno son:\n\n";
                            ver_alumno(x[i], i);
                        }
                    }
                    else if (opc == 2)
                    {
                        cout << "\n\nIngresa el nuevo apellido:\n";
                        cin >> a;
                        x[i].apellido = a;
                        system("cls");
                        cout << "\tLos nuevos datos del alumno son:\n\n";
                        ver_alumno(x[i], i);
                    }
                    else if (opc == 3)
                    {
                        cout << "\n\nIngresa el nuevo nombre:\n";
                        cin >> a;
                        x[i].nombre = a;
                        system("cls");
                        cout << "\tLos nuevos datos del alumno son:\n\n";
                        ver_alumno(x[i], i);
                    }
                    else if (opc == 4)
                    {
                        cout << "\n\nIngresa la nueva nota 1:\n";
                        cin >> b;
                        x[i].nota1 = b;
                        x[i].promedio = (x[i].nota1 + x[i].nota2) / 2;
                        system("cls");
                        cout << "\tLos nuevos datos del alumno son:\n\n";
                        ver_alumno(x[i], i);
                    }
                    else if (opc == 5)
                    {
                        cout << "\n\nIngresa la nueva nota 2:\n";
                        cin >> b;
                        x[i].nota2 = b;
                        x[i].promedio = (x[i].nota1 + x[i].nota2) / 2;
                        system("cls");
                        cout << "\tLos nuevos datos del alumno son:\n\n";
                        ver_alumno(x[i], i);
                    }
                    else if (opc <= 0 && opc > 5)
                    {
                        cout << "\nIngrese un numero valido...\n";
                        cin >> opc;
                    }
                } while (opc <= 0 && opc > 5);
            }
            else
            {
                i++;
            }
        }
        if (flag)
        {
            cout << "\nNO se encontró el codigo del alumno ingresado...\n\n";
        }
    }
    else
    {
        cout << "\nNO existe ningun alumno registrado...\n\n";
    }
}

void mostrar_d(Alumno x[], int n)
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