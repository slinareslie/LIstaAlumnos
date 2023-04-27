#include "menu.h"
#include "a_desordenados.h"
#include "a_ordenados.h"
#include "alumno.h"

using namespace std;

int main()
{
    int opc, opc1;
    int n = 0;
    string trash;
    do
    {
        opc = menu_principal();
        system("cls");
        if (opc == 1)
        {
            do
            {
                opc1 = menu_ordenados();
                system("cls");
                if (opc1 == 1)
                {
                    insertar_o(alumno, n, 10);
                }
                else if (opc1 == 2)
                {
                    cout << "\nIngrese el codigo del alumno que desea eliminar:\n";
                    cin >> trash;
                    system("cls");
                    eliminar_o(alumno, n, trash);
                }
                else if (opc1 == 3)
                {
                    cout << "\nIngrese el codigo del alumno que desea modificar:\n";
                    cin >> trash;
                    system("cls");
                    modificar_o(alumno, n, trash);
                }
                else if (opc1 == 4)
                {
                    mostrar_o(alumno, n);
                }
                cout << "\n\n";
                if (opc1 != 5)
                {
                    system("pause");
                }
                system("cls");
            } while (opc1 != 5);
        }
        else if (opc == 2)
        {
            do
            {
                opc1 = menu_desordenados();
                system("cls");
                if (opc1 == 1)
                {
                    insertar_d(alumno, n, 10);
                }
                else if (opc1 == 2)
                {
                    cout << "\nIngrese el codigo del alumno que desea eliminar:\n";
                    cin >> trash;
                    system("cls");
                    eliminar_d(alumno, n, trash);
                }
                else if (opc1 == 3)
                {
                    cout << "\nIngrese el codigo del alumno que desea modificar:\n";
                    cin >> trash;
                    system("cls");
                    modificar_d(alumno, n, trash);
                }
                else if (opc1 == 4)
                {
                    mostrar_d(alumno, n);
                }
                cout << "\n\n";
                if (opc1 != 5)
                {
                    system("pause");
                }
                system("cls");
            } while (opc1 != 5);
        }

        system("cls");
    } while (opc != 3);

    cout << "\nTenga un buen dia, hasta luego...\n";

    return 0;
}