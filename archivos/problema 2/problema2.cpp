#include <bits/stdc++.h>

using namespace std;

int main(){
    ifstream archivo;
    string nombre,apellido, codigo, texto;
    float nota;
    int ciclo;
    int opc=0, n;

    string no, ape, co, lin;
    float notaa, alta;
    int ci;

    string no1, ape1, co1, lin1;
    float notaa1, alta1, notp=0;
    int ci1, conta=0;

    do{
        cout<<"\tREGISTRO DE NOTAS ESIS"<<endl;
        cout<<"\nQue desea hacer?\n1)Introducir estudiante\n2)Mostrar estudiantes\n3)Nota mas alta\n4)Promedio por ciclo\n5)Promedio ESIS\n6)Salir\n"<<endl;cin>>opc;
        system("cls");
        if(opc==1){
            ofstream archivo("estudiantes.txt",ios::app);

            if(!archivo.is_open()){
                cout<<"No se puede abrir el archivo"<<endl;
            }
            else{
                cout<<endl<<"Numero de estudiantes a ingresar: ";cin>>n;
                for(int i=1;i<=n;i++){
                    cout<<"\nDatos del alumno "<<i<<"): "<<endl;
                    fflush(stdin);
                    cout<<"\nCodigo del alumno:\t";getline(cin,codigo);
                    fflush(stdin);
                    cout<<"Nombre del alumno:\t";getline(cin,nombre);
                    fflush(stdin);
                    cout<<"Apellido del alumno:\t";getline(cin,apellido);
                    cout<<"Ciclo al que pertenece:\t";cin>>ciclo;
                    cout<<"Nota del estudiante:\t";cin>>nota;

                    archivo<<"\n"<<codigo<<" "<<nombre<<" "<<apellido<<" "<<ciclo<<" "<<nota;
                }
                archivo.close();
            }
        }
        else if(opc==2){
            ifstream archivo("estudiantes.txt",ios::in);
            if(!archivo.is_open()){
                cout<<"\nError, archivo imposible de abrir\n";
            }
            else{
                cout<<"->Acceso exitoso de lectura del archivo: Estudiantes.txt\n"<<endl;
                cout<<"CODIGO\t\tNOMBRE\t\tAPELLIDO\tCICLO\tNOTA"<<endl;

                while(!archivo.eof()){
                    archivo>>co>>no>>ape>>ci>>notaa;

                    cout<<co<<"\t"<<no<<"\t"<<ape<<"\t\t"<<ci<<"\t"<<notaa<<"\t"<<endl;
                }
            }
            cout<<"\n";
            archivo.close();

            system("pause");            
        }
        else if(opc==3){
            ifstream archivo("estudiantes.txt",ios::in);
            if(!archivo.is_open()){
                cout<<"\nError, archivo imposible de abrir\n";
            }
            else{
                cout<<"->Acceso exitoso de lectura del archivo: Estudiantes.txt\n"<<endl;
                cout<<"CODIGO\t\tNOMBRE\t\tAPELLIDO\tCICLO\tNOTA"<<endl;
                while(!archivo.eof()){
                    archivo>>co>>no>>ape>>ci>>notaa;
                    if(notaa>=alta){
                        alta=notaa;
                        co1=co;
                        no1=no;
                        ape1=ape;
                        ci1=ci;
                        notaa1=notaa;
                    }
                }
                cout<<co1<<"\t"<<no1<<"\t"<<ape1<<"\t\t"<<ci1<<"\t"<<notaa1<<"\t"<<endl;
                system("pause");
            }
        }
        else if(opc==4){
            for(int i=1;i<=10;i++){
                ifstream archivo("estudiantes.txt",ios::in);
                if(!archivo.is_open()){
                    cout<<"\nError, archivo imposible de abrir\n";
                }
                else{
                    if(i==1){
                        cout<<"->Acceso exitoso de lectura del archivo: Estudiantes.txt\n"<<endl;
                    }
                    while(!archivo.eof()){
                        archivo>>co>>no>>ape>>ci>>notaa;
                        if(ci==i){
                            notp+=notaa;
                            conta++;
                        }
                    }
                    if(conta!=0){
                        cout<<"NOTA PROMEDIO DEL "<<i<<" CICLO ES: "<<notp/conta<<endl; 
                    } 
                }
                conta=0;
                notp=0;
            }
            cout<<"\n";
            system("pause");
        }
        else if(opc==5){
            ifstream archivo("estudiantes.txt",ios::in);
            if(!archivo.is_open()){
                cout<<"\nError, archivo imposible de abrir\n";
            }
            else{
                cout<<"->Acceso exitoso de lectura del archivo: Estudiantes.txt\n"<<endl;
                while(!archivo.eof()){
                    archivo>>co>>no>>ape>>ci>>notaa;
                    notp+=notaa;
                    conta++;
                }
                cout<<"NOTA PROMEDIO DE ESIS: "<<notp/conta<<endl;
            }
            cout<<"\n";
            system("pause");
        }
        system("cls");
    }while(opc!=6);

    return 0;
}