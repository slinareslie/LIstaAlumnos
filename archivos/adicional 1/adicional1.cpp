#include <bits/stdc++.h>

using namespace std;

int main(){
    ifstream archivo;
    string nombre, apellido;
    int pri,seg,ter,cua,tot, opc, n;
    
    string no, ape;
    int pri1,seg1,ter1,cua1,tot1;

    do{
        cout<<"\tEXAMEN DE ADMISION UNI1"<<endl;
        cout<<"\nQue desea hacer?\n1)Introducir estudiante\n2)Mostrar estudiantes\n3)Salir\n"<<endl;cin>>opc;
        system("cls");
        if(opc==1){
            ofstream archivo("uni1.txt",ios::app);

            if(!archivo.is_open()){
                cout<<"No se puede abrir el archivo"<<endl;
            }
            else{
              cout<<endl<<"Numero de estudiantes a ingresar: ";cin>>n;
              for(int i=1;i<=n;i++){
                cout<<"\nDatos del alumno "<<i<<"): "<<endl;
                fflush(stdin);
                cout<<"\nNombre del alumno:\t";getline(cin,nombre);
                fflush(stdin);
                cout<<"Apellido del alumno:\t";getline(cin, apellido);
                do{
                    cout<<"Primera nota:\t\t";cin>>pri;
                    if((pri<1||pri>25)){
                        cout<<"\nIngrese un numero entre 1 y 25"<<endl;
                    }
                }while(pri<1||pri>25);
                do{
                    cout<<"Segunda nota:\t\t";cin>>seg;
                    if((seg<1||seg>25)){
                        cout<<"\nIngrese un numero entre 1 y 25"<<endl;
                    }
                }while(seg<1||seg>25);
                do{
                    cout<<"Tercera nota:\t\t";cin>>ter;
                    if((ter<1||ter>25)){
                        cout<<"\nIngrese un numero entre 1 y 25"<<endl;
                    }
                }while(ter<1||ter>25);
                do{
                    cout<<"Cuarta nota:\t\t";cin>>cua;
                    if((cua<1||cua>25)){
                        cout<<"\nIngrese un numero entre 1 y 25"<<endl;
                    }
                }while(cua<1||cua>25);                                                
                archivo<<"\n"<<nombre<<" "<<apellido<<" "<<pri<<" "<<" "<<seg<<" "<<" "<<ter<<" "<<cua<<" "<<pri+seg+ter+cua;
              } 
            }
        }
        else if(opc==2){
            ifstream archivo("uni1.txt",ios::in);
            if(!archivo.is_open()){
                cout<<"\nError, archivo imposible de abrir\n";
            }
            else{
                cout<<"->Acceso exitoso de lectura del archivo: uni1.txt\n"<<endl;
                cout<<"NOMBRE\t\tAPELLIDO\tPRIMERA\tSEGUNDA\tTERCERA\tCUARTA\tTOTAL"<<endl;                

                while(!archivo.eof()){
                    archivo>>no>>ape>>pri1>>seg1>>ter1>>cua1>>tot1;

                    cout<<no<<"\t"<<ape<<"\t\t"<<pri1<<"\t"<<seg1<<"\t"<<ter1<<"\t"<<cua1<<"\t"<<tot1<<endl;
                }
            }
            cout<<"\n";
            system("pause");
        }
        system("cls");
    }while(opc!=3);

    return 0;
}