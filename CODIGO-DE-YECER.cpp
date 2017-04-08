#include <iostream> 
#include <string.h> 
#include <fstream>
#include <sstream>
#include "CodCesar.h"

using namespace std;

  
int main() { 
	int bandera=0,size,n;
	char *Archivo;
	CodCesar variable;
	string  numerotemporal,respuesta,cadena,NomArchivo;
	do{
		do{
		    cout<<"\t_________________________________________________________\n";
		    cout<<"\t� CODIFICACION Y DECODIFICACION DE ARCHIVOS!!!!!.        �\n";
		    cout<<"\t� Seleccione la accion que desee tomar:                  �\n";
		    cout<<"\t�                                                        �\n";
		    cout<<"\t� A) Crear un archivo para guardar un mensaje codificado.�\n";
		    cout<<"\t� B) Decodificar los mensajes ocultos en los archivos.   �\n";
		    cout<<"\t� C) Salir.                                              �\n";
		    cout<<"\t�________________________________________________________�\n";
		    cout<<" Opcion:";
		    cin>>respuesta;
			size=respuesta.size();
			if(size>1){
				cout<<"OPCION INVALIDA"<<endl;
				bandera=1;						
			}
			
			else if((respuesta[0]!=97 && respuesta[0]!=98 && respuesta[0]!=99 &&respuesta[0]!=65 && respuesta[0]!=66 &&respuesta[0]!=67)){
				cout<<"OPCION INVALIDA"<<endl;
				bandera=1;	
			}
		    system("pause");
		    system("cls");
		}while(bandera==1);    
			
		if(respuesta[0]==97 || respuesta[0]==65){
			do{
		    	fflush(stdin);
			    bandera=0;
			    cout<<"Ingrese el Nombre del archivo que desea crear\n(o modificar en caso de estar creado)\n\nNombre: ";
			    getline(cin, NomArchivo);
				size=NomArchivo.size();
			    for(int x=0;x<size;x++){
			    	if ((NomArchivo[x]=='|' || NomArchivo[x]=='<'|| NomArchivo[x]=='?' || NomArchivo[x]=='*'|| NomArchivo[x]=='>'|| NomArchivo[x]=='"' || NomArchivo[x]=='/' ||NomArchivo[x]==':' ) && bandera==0){
			    		cout<<"Este nombre no puede tener ninguno de estos caracteres\n";
						cout<<"caracteres invalidos: <,>,?,:,|,/,*,\" ";	
			    		system("pause");
			    		system("cls");
						bandera=1;
					}
				}	
					    
			}while(bandera==1);
		    Archivo=strdup(NomArchivo.c_str());
		    do{
				bandera=0;
				cout << "Introduce el numero de desplazamiento deseado: "; 
			    cin >> numerotemporal; 
				size=numerotemporal.size();
				    
				for(int x=0;x<size;x++){
					
				    if(numerotemporal[x]<48 || numerotemporal[x]>57){
				    	bandera=1;
				    	cout<<"DATO INVALIDO\n";
					}
					else{
						istringstream(numerotemporal)>>n;
						
					}
				}
			}while(bandera==1);
			variable.setNumero(n);
			system("cls");
		    cout << "Ingrese su mensaje a ocultar\npara finalizar, escriba :SACAME en la ultima linea\n\n" << endl; 
		    ofstream VaciarArchivo(Archivo,std::ios::trunc);
		    VaciarArchivo.close();
			
			do{
			
			    getline(cin, cadena); 
			    
				if(cadena==""){
			    	cadena=" ";
				}
				if(cadena==":SACAME"){
		    		bandera=1;
					cadena="";
				}	
			
				variable.TextoCodificar(-(variable.getNumero()), cadena); 
				variable.setMensaje(cadena);
			    ofstream LlenarArchivo(Archivo,std::ios::app);
			    LlenarArchivo<<variable.getMensaje()<<endl;
			    LlenarArchivo.close();
		    
		    
		 	}while(bandera!=1);
		
		    
		 
		    
		    ifstream LeerArchivo(Archivo);
			string Leer;
			cout<<"Mensaje Codificado:";
		 	while(getline(LeerArchivo,Leer)) {
		  		cout << Leer<<endl;
		 	}
		 	LeerArchivo.clear();
			LeerArchivo.close();
			system("pause");	
			system("cls");
		}
		
		if(respuesta[0]==98 || respuesta[0]==66){
			cout<<"DECODIFICAR"<<endl;
		}
		
		
	
	}while(respuesta[0]!=99 && respuesta[0]!=67);
	return 0;
} 
