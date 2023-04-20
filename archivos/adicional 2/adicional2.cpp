#include <bits/stdc++.h>

using namespace std;

int main(){
    ifstream archivo;
    string nombre, apellido, codigo, s;
    float sueb, suen;
    int n, opc, cod;

    string no, ape, co;
    float sueb1, suen1;

    do{
        cout<<"\tBASE DE EMPLEADOS"<<endl;
        cout<<"\nQue desea hacer?\n1)Introducir empleados\n2)Mostrar empleados\n3)Salir\n"<<endl;cin>>opc;
        system("cls");
        if(opc==1){
            ofstream archivo("planilla.txt",ios::app);
            if(!archivo.is_open()){
                cout<<"No se puede abrir el archivo"<<endl;
            }
            else{
                cout<<endl<<"Digite el numero de empleados a ingresar: ";cin>>n;
                for(int i=1;i<=n;i++){
                    cout<<"\nDatos del empleado "<<i<<"): "<<endl;
                    fflush(stdin);
                    cout<<"\nIngrese su nombre:\t\t";getline(cin, nombre);
                    fflush(stdin);
                    cout<<"Ingrese su apellido:\t\t";getline(cin, apellido);
                    cout<<"Ingrese un codigo de 3 digitos:\t";cin>>cod;
                    s=to_string(cod);
                    cout<<"Ingrese su salario:\t\t";cin>>sueb;
                    codigo.push_back(toupper(nombre[0]));codigo.push_back(toupper(nombre[1]));codigo.push_back('-');
                    codigo.push_back(s[0]);codigo.push_back(s[1]);codigo.push_back(s[2]);
                    archivo<<"\n"<<codigo<<" "<<nombre<<" "<<apellido<<" "<<sueb<<" "<<(sueb*0.97)-60;
                    codigo="\0";
                }
                archivo.close();
            }
        } 
        else if(opc==2){
            ifstream archivo("planilla.txt",ios::in);
            if(!archivo.is_open()){
                cout<<"\nError, archivo imposible de abrir\n";
            }
            else{
                cout<<"->Acceso exitoso de lectura del archivo: Estudiantes.txt\n"<<endl;
                cout<<"CODIGO"<<setw(18)<<"NOMBRE"<<setw(18)<<"APELLIDO"<<setw(20)<<"SALARIO BASE"<<setw(20)<<"SALARIO NETO"<<endl;
                while(!archivo.eof()){
                    archivo>>co>>no>>ape>>sueb1>>suen1;
                    
                    cout<<co<<setw(18)<<no<<setw(18)<<ape<<setw(20)<<sueb1<<setw(20)<<suen1<<endl;
                }
            }
            cout<<"\n";
            archivo.close();

            system("pause");  
        }
        system("cls");
    }while(opc!=3);

    return 0;
}