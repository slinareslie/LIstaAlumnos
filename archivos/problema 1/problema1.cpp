#include <bits/stdc++.h>

using namespace std;

int main(){
    ifstream archivo;
    string nombreArchivo;
    string lineaTexto;
    string nombre;
    int codigo, cantidad, minimo, opc=0;
    float precio;
    string proveedor, necesidad="HACER PEDIDO";
    int n, i;

    
    do{
        cout<<"\tAPLICACION PARA SUPERMERCADO"<<endl;
        cout<<"\nQue desea hacer?\n1)Introducir articulos\n2)Comprobar cantidad\n3)Salir\n"<<endl;cin>>opc;
        system("cls");
        if(opc==1){
            ofstream archivoAlmacen("stock.txt",ios::app);

            if(!archivoAlmacen.is_open()){
                cout<<"No se puede abrir el archivo"<<endl;
            }
            else{
                cout<<endl<<"Digite el numero de productos a ingresar: ";cin>>n;
                for(int i=1;i<=n;i++){
                    cout<<"\nDatos del producto "<<i<<"): "<<endl;
                    fflush(stdin);
                    cout<<"\nNombre del producto:\t";getline(cin,nombre);
                    cout<<"\nCodigo del producto:\t";cin>>codigo;
                    cout<<"\nCantidad en el almacen:\t";cin>>cantidad;
                    cout<<"\nCantidad minima:\t";cin>>minimo;
                    cout<<"\nPrecio del producto:\t";cin>>precio;
                    fflush(stdin);
                    cout<<"\nNombre del proveedor:\t";getline(cin, proveedor);
                    if(cantidad<=minimo){
                        archivoAlmacen<<"\n"<<nombre<<"\t\t"<<codigo<<"\t"<<cantidad<<"\t"<<minimo<<"\t"<<precio<<"\t"<<proveedor<<"\t\t"<<necesidad;
                    }
                    else{
                        archivoAlmacen<<"\n"<<nombre<<"\t\t"<<codigo<<"\t"<<cantidad<<"\t"<<minimo<<"\t"<<precio<<"\t"<<proveedor;
                    }
                    
                }
                archivoAlmacen.close();
            }
        }
        else if(opc==2){
            archivo.open("stock.txt",ios::in);
            if(!archivo.is_open()){
                cout<<"\nError, archivo imposible de abrir\n";
            }
            else{
                cout<<"->Acceso exitoso para lectura de archivo: Stock.txt\n"<<endl;
                cout<<"PRODUCTO\tCODIGO\tSTOCK\tMINIMO\tPRECIO\tPROVEEDOR\tDETALLE"<<endl;

                while(!archivo.eof()){
                    getline(archivo, lineaTexto);
                    cout<<lineaTexto<<endl;
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