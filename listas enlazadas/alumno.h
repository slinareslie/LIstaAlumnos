#ifndef ALUMNO_H
#define ALUMNO_H

#include <string>

using namespace std;

struct Alumno
{
    string codigo = "0";
    string apellido;
    string nombre;
    float nota1, nota2, promedio = (nota1 + nota2) / 2;
    Alumno *sig;
    Alumno(Alumno *_sig = NULL) {}

} alumno[10];

#endif