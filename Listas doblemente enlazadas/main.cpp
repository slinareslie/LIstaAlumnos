#include "menu.h"
#include "funcionesLista.h"
#include "alumno.h"

using namespace std;

int main()
{
    int opc, opc1;
    int n = 1;
    string trash;
    Alumno *P = NULL, *F = NULL;
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
                    insertar_i(P, F);
                    n++;
                    break;
                case 2:
                    insertar_f(P, F);
                    n++;
                    break;
                case 3:
                    insertar_a(P, F);
                    n++;
                    break;
                case 4:
                    insertar_d(P, F);
                    n++;
                    break;
                case 5:
                    eliminar_i(P, F);
                    system("pause");
                    break;
                case 6:
                    eliminar_f(P, F);
                    system("pause");
                    break;
                case 7:
                    eliminar_x(P, F);
                    system("pause");
                    break;
                case 8:
                    modificar(P);
                    system("pause");
                    break;
                case 9:
                    mostrar(P, n);
                    system("pause");
                    break;
                }
                system("cls");
            } while (opc1 != 7);
            break;
        default:
            break;
        }

        system("cls");
    } while (opc != 2);

    cout << "\nTenga un buen dia, hasta luego...\n";

    return 0;
}