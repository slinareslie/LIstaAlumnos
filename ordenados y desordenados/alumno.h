#ifndef alumno_h
#define alumno_h

#include <string>

using namespace std;

struct Alumno
{
    string codigo = "0";
    string apellido;
    string nombre;
    float nota1, nota2, promedio = (nota1 + nota2) / 2;

} alumno[10];

#endif