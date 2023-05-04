#include "menu.h"
#include "funcionesLista.h"
#include "alumno.h"

using namespace std;

int main()
{
    int opc, opc1;
    int n = 1;
    string trash;
    Alumno *P = NULL, *R = NULL;
    do
    {
        opc = menu_principal();
        system("cls");
        switch (opc)
        {
        case 1:
            do
            {
                opc1 = menu_lista();
                system("cls");
                switch (opc1)
                {
                case 1:
                    insertar_i(P, R);
                    n++;
                    break;
                case 2:
                    insertar_f(P, R);
                    n++;
                    break;
                case 3:
                    insertar_a(P);
                    n++;
                    break;
                case 4:
                    modificar(P);
                    system("pause");
                    break;
                case 5:
                    mostrar(P, n);
                    system("pause");
                    break;
                case 6:
                    break;
                case 7:
                    break;
                case 8:
                    break;
                case 9:
                    break;
                case 10:
                    break;
                case 11:
                    break;
                case 12:
                    break;
                default:
                    break;
                }
                system("cls");
            } while (opc1 != 13);
            break;
        default:
            break;
        }

        system("cls");
    } while (opc != 2);

    cout << "\nTenga un buen dia, hasta luego...\n";

    return 0;
}