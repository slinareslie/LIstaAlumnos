#include "alumno.h"
#include <iostream>
#include <iomanip>

using namespace std;

void ver_alumno(Alumno *&, Alumno *&, int);
Alumno *buscar(Alumno *, string);
int cont_buscar(Alumno *, string);
bool listaVacia(Alumno *);
void insertar_i(Alumno *&, Alumno *&);
void insertar_f(Alumno *&, Alumno *&);
void insertar_a(Alumno *&, Alumno *&);
void insertar_d(Alumno *&, Alumno *&);
void eliminar_i(Alumno *&p, Alumno *&f);
void eliminar_f(Alumno *&p, Alumno *&f);
void eliminar_x(Alumno *&p, Alumno *&f);
void modificar(Alumno *&);
void mostrar(Alumno *&, int);
void insertar_d(Alumno *&);

void ver_alumno(Alumno *&p, Alumno *&x, int i)
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

    cout << setw(5) << (cont_buscar(p, x->codigo))
         << setw(15) << x->codigo
         << setw(35) << x->apellido + ", " + x->nombre
         << setw(8) << x->nota1
         << setw(8) << x->nota2
         << setw(10) << x->promedio << endl;

    cout << setfill('=') << setw(79) << "=" << endl;
}

Alumno *buscar(Alumno *p, string x)
{
    Alumno *r = p;
    if (p != NULL)
    {
        while (r != NULL)
        {
            if (r->codigo == x)
            {
                return r;
            }
            r = r->sig;
        }
        return NULL;
    }
    else
    {
        return NULL;
    }
}

int cont_buscar(Alumno *p, string x)
{
    Alumno *r = new Alumno();
    int i = 1;
    r = p;
    while (r->sig != NULL)
    {
        if (r->codigo == x)
        {
            return i;
        }
        else
        {
            r = r->sig;
        }
        i++;
    }
    return 0;
}

bool listaVacia(Alumno *p)
{
    return (p == NULL) ? true : false;
}

void insertar_i(Alumno *&p, Alumno *&f)
{
    string codigo_n;
    cout << "\nIngrese el codigo del estudiante (anio-numero): \n";
    cin >> codigo_n;
    Alumno *aux = buscar(p, codigo_n);
    if (aux != NULL)
    {
        cout << "El codigo: " << codigo_n << " ya existe en el registro...\n\n";
        system("pause");
    }
    else
    {
        Alumno *x = new Alumno();
        x->codigo = codigo_n;
        cin.ignore();
        cout << "\nIngrese los apellidos del estudiante: \n";
        getline(cin, x->apellido);
        cout << "\nIngrese el nombre del estudiante: \n";
        getline(cin, x->nombre);
        cout << "\nIngrese la nota 1: \n";
        cin >> x->nota1;
        cout << "\nIngrese la nota 2: \n";
        cin >> x->nota2;
        x->promedio = (x->nota1 + x->nota2) / 2;
        x->sig = p;
        x->ant = NULL;
        if (p == NULL)
        {
            p = x;
            f = x;
        }
        else
        {
            p->ant = x;
            p = x;
        }
    }
}

void insertar_f(Alumno *&p, Alumno *&f)
{
    string codigo_n;
    cout << "\nIngrese el codigo del estudiante (anio-numero): \n";
    cin >> codigo_n;
    Alumno *aux = buscar(p, codigo_n);
    if (aux != NULL)
    {
        cout << "El codigo: " << codigo_n << " ya existe en el registro...\n\n";
        system("pause");
    }
    else
    {
        Alumno *x = new Alumno();
        x->codigo = codigo_n;
        cin.ignore();
        cout << "\nIngrese los apellidos del estudiante: \n";
        getline(cin, x->apellido);
        cout << "\nIngrese el nombre del estudiante: \n";
        getline(cin, x->nombre);
        cout << "\nIngrese la nota 1: \n";
        cin >> x->nota1;
        cout << "\nIngrese la nota 2: \n";
        cin >> x->nota2;
        x->promedio = (x->nota1 + x->nota2) / 2;

        x->sig = NULL;
        x->ant = f;
        if (listaVacia(p))
        {
            p = x;
        }
        else
        {
            f->sig = x;
        }
        f = x;
    }
}

void insertar_a(Alumno *&p, Alumno *&f)
{
    if (p != NULL)
    {
        string trash;
        cout << "Inserte el codigo del estudiante que esta delante: \n";
        cin >> trash;
        Alumno *x = new Alumno();
        Alumno *act = p;

        while (act != NULL && act->codigo != trash)
        {
            act = act->sig;
        }

        if (act != NULL)
        {
            cout << "\nIngrese el codigo del nuevo estudiante: \n";
            cin >> x->codigo;
            cin.ignore();
            cout << "\nIngrese los apellidos del estudiante: \n";
            getline(cin, x->apellido);
            cout << "\nIngrese el nombre del estudiante: \n";
            getline(cin, x->nombre);
            cout << "\nIngrese la nota 1: \n";
            cin >> x->nota1;
            cout << "\nIngrese la nota 2: \n";
            cin >> x->nota2;
            x->promedio = (x->nota1 + x->nota2) / 2;

            x->sig = act;
            x->ant = act->ant;

            if (act->ant != NULL)
            {
                act->ant->sig = x;
            }
            else
            {
                p = x;
            }
            act->ant = x;
        }
        else
        {
            cout << "\n\nEl codigo: " << trash << " no existe en el registro...\n\n";
            system("pause");
        }
    }
    else
    {
        cout << "\nNO hay ningun alumno registrado...\n\n";
        system("pause");
    }
}

void insertar_d(Alumno *&p, Alumno *&f)
{
    if (p != NULL)
    {
        string trash;
        cout << "Inserte el codigo del estudiante que esta antes: \n";
        cin >> trash;
        Alumno *x = new Alumno();
        Alumno *act = p;

        while (act != NULL && act->codigo != trash)
        {
            act = act->sig;
        }

        if (act != NULL)
        {
            cout << "\nIngrese el codigo del nuevo estudiante: \n";
            cin >> x->codigo;
            cin.ignore();
            cout << "\nIngrese los apellidos del estudiante: \n";
            getline(cin, x->apellido);
            cout << "\nIngrese el nombre del estudiante: \n";
            getline(cin, x->nombre);
            cout << "\nIngrese la nota 1: \n";
            cin >> x->nota1;
            cout << "\nIngrese la nota 2: \n";
            cin >> x->nota2;
            x->promedio = (x->nota1 + x->nota2) / 2;

            x->sig = act->sig;
            x->ant = act;

            if (act->sig != NULL)
            {
                act->sig->ant = x;
            }
            else
            {
                f = x;
            }
            act->sig = x;
        }
        else
        {
            cout << "\n\nEl codigo: " << trash << " no existe en el registro...\n\n";
            system("pause");
        }
    }
    else
    {
        cout << "\nNO hay ningun alumno registrado...\n\n";
        system("pause");
    }
}

void eliminar_i(Alumno *&p, Alumno *&f)
{
    if (!listaVacia(p))
    {
        Alumno *q = p;
        if (p == f)
        {
            delete p;
            p = f = NULL;
        }
        else
        {
            p = p->sig;
            p->ant = NULL;
            delete q;
        }
        cout << "El nodo del inicio de la lista ha sido eliminado exitosamente.\n\n";
    }
    else
    {
        cout << "La lista esta vacia.\n\n";
    }
}

void eliminar_f(Alumno *&p, Alumno *&f)
{
    if (listaVacia(p))
    {
        cout << "La lista está vacía, no se puede eliminar nada...\n\n";
        system("pause");
    }
    else if (p == f)
    {
        Alumno *aux = f;
        p = NULL;
        f = NULL;
        delete aux;
    }
    else
    {
        Alumno *q = new Alumno();
        q = f->ant;
        q->sig = NULL;
        delete f;
        f = q;
    }
}

void eliminar_x(Alumno *&p, Alumno *&f)
{
    string codigo;
    cout << "\n\nIngrese el codigo del estudiante que desea eliminar: ";
    cin >> codigo;
    Alumno *q = NULL;
    Alumno *r = buscar(p, codigo);
    if (r == NULL)
    {
        cout << "\n\nEl codigo: " << codigo << " no existe en el registro...\n\n";
        system("pause");
        return;
    }
    else if (r == p && r == f)
    {
        p = NULL;
        f = NULL;
    }
    else if (r == p)
    {
        p = p->sig;
        p->ant = NULL;
    }
    else if (r == f)
    {
        q = f->ant;
        f = q;
        f->sig = NULL;
    }
    else
    {
        q = r->ant;
        q->sig = r->sig;
        r->sig->ant = q;
    }
    delete r;
    cout << "\n\nEl codigo: " << codigo << " ha sido eliminado del registro...\n\n";
    system("pause");
}

void modificar(Alumno *&p)
{
    if (p != NULL)
    {
        string trash;
        cout << "Inserte el codigo del estudiante a modificar:\n";
        cin >> trash;
        Alumno *x = buscar(p, trash);
        int opc;
        if (x != NULL)
        {
            system("cls");
            do
            {
                ver_alumno(p, x, cont_buscar(p, trash));
                cout << "\n\nIngrese que dato desea modificar:\n\n1)Codigo\n2)Apellidos\n3)Nombres\n4)Nota 1\n5)Nota 2\n6)Salir\n\n";
                cin >> opc;
                string a;
                float b;
                system("cls");
                ver_alumno(p, x, cont_buscar(p, trash));
                Alumno *aux = buscar(p, a);
                switch (opc)
                {
                case 1:
                    cout << "\n\nIngrese el nuevo codigo:\n";
                    cin >> a;
                    if (aux != NULL)
                    {
                        cout << "El codigo: " << a << " ya existe en el registro...";
                    }
                    else
                    {
                        x->codigo = a;
                        system("cls");
                        cout << "\tLos nuevos datos del alumno son:\n\n";
                        ver_alumno(p, x, cont_buscar(p, trash));
                    }
                    break;
                case 2:
                    cout << "\n\nIngresa el nuevo apellido:\n";
                    cin >> a;
                    x->apellido = a;
                    system("cls");
                    cout << "\tLos nuevos datos del alumno son:\n\n";
                    ver_alumno(p, x, cont_buscar(p, trash));
                    break;
                case 3:
                    cout << "\n\nIngresa el nuevo nombre:\n";
                    cin >> a;
                    x->nombre = a;
                    system("cls");
                    cout << "\tLos nuevos datos del alumno son:\n\n";
                    ver_alumno(p, x, cont_buscar(p, trash));
                    break;
                case 4:
                    cout << "\n\nIngresa la nueva nota 1:\n";
                    cin >> b;
                    x->nota1 = b;
                    x->promedio = (x->nota1 + x->nota2) / 2;
                    system("cls");
                    cout << "\tLos nuevos datos del alumno son:\n\n";
                    ver_alumno(p, x, cont_buscar(p, trash));
                    break;
                case 5:
                    cout << "\n\nIngresa la nueva nota 2:\n";
                    cin >> b;
                    x->nota2 = b;
                    x->promedio = (x->nota1 + x->nota2) / 2;
                    system("cls");
                    cout << "\tLos nuevos datos del alumno son:\n\n";
                    ver_alumno(p, x, cont_buscar(p, trash));
                    break;
                case 6:
                    break;
                default:
                    cout << "\nIngrese un numero valido...\n\n";
                }

            } while (opc <= 0 && opc > 6);
        }
        else
        {
            cout << "El codigo: " << trash << " no existe en el registro...\n\n";
            system("pause");
        }
    }
    else
    {
        cout << "\nNO hay ningun alumno registrado...\n\n";
        system("pause");
    }
}

void mostrar(Alumno *&p, int n)
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

        Alumno *q = new Alumno();
        q = p;

        int i = 1;
        while (q != NULL)
        {
            cout << setw(5) << i
                 << setw(15) << q->codigo
                 << setw(35) << q->apellido + ", " + q->nombre
                 << setw(8) << q->nota1
                 << setw(8) << q->nota2
                 << setw(10) << q->promedio << endl;

            q = q->sig;
            i++;
        }

        cout << setfill('=') << setw(79) << "=" << endl;
    }
    else
    {
        cout << "\nNO hay ningun alumno registrado...\n\n";
    }
}