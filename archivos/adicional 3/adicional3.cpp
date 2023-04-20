#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

class Empleado{
    private:
        string codigo;
        string apellido;
        string nombre;
        float sueldobase;
        float sueldoneto;
    public:
    Empleado(string co, string ape, string no, float sb, float sn){
        codigo=co;
        apellido=ape;
        nombre=no;
        sueldobase=sb;
        sueldoneto=sn;
    }
    void mostrar();
    char getApe();
};

void Empleado::mostrar(){
    cout<<codigo<<setw(18)<<nombre<<setw(18)<<apellido<<setw(20)<<sueldobase<<setw(20)<<sueldoneto<<endl;
}

char Empleado::getApe(){
    return apellido[0];
}

int main(){
    ifstream archivo;
    string nombre, apellido, codigo, s;
    float sueb, suen;
    int n, opc, cod;

    string no, ape, co;
    float sueb1, suen1;

    Empleado* emple[100];

    int flag=0;
    
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
                sleep(3);
                exit(0);
            }
            else{
                while(!archivo.eof()){
                    archivo>>co>>no>>ape>>sueb1>>suen1;
                    
                    Empleado* aux=new Empleado(co,ape,no,sueb1,suen1);
                    emple[flag]=aux;
                    flag++;
                }
                cout<<"CODIGO"<<setw(18)<<"NOMBRE"<<setw(18)<<"APELLIDO"<<setw(20)<<"SALARIO BASE"<<setw(20)<<"SALARIO NETO"<<endl;
                for(char i='A';i!='Z'+1;i++){
                    for(int j=0;j<flag;j++){
                        if(toupper(emple[j]->getApe())==i){
                            emple[j]->mostrar();
                        }
                    }
                }

            }
            cout<<"\n";
            archivo.close();

            system("pause");  
        }
        system("cls");
    }while(opc!=3&&opc!=2);     

    return 0;
}