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
    Alumno *ant, *sig;
    Alumno(Alumno *_ant = NULL, Alumno *_sig = NULL) {}

} alumno[2];

#endif