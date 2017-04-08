#include <iostream> 
#include <string.h> 
#include <fstream>
#include <sstream>
#include "CodCesar.h"
using namespace std; 
  
int main() { 
    int n,bandera=0,size;
	char *Archivo; 
    CodCesar variable;
	string  numerotemporal,respuesta,cadena,NomArchivo;
    
	do{
		do{
			fflush(stdin); //LIMPIA EL BUFFER
		    bandera=0;
		    cout<<"\t_________________________________________________________\n";  //IMPRIMIR EL MENU
		    cout<<"\tº CODIFICACION Y DECODIFICACION DE ARCHIVOS!!!!!.        º\n";
		    cout<<"\tº Seleccione la accion que desee tomar:                  º\n";
		    cout<<"\tº                                                        º\n";
		    cout<<"\tº A) Crear un archivo para guardar un mensaje codificado.º\n";
		    cout<<"\tº B) Decodificar los mensajes ocultos en los archivos.   º\n";
		    cout<<"\tº C) Salir.                                              º\n";
		    cout<<"\tº________________________________________________________º\n";
		    cout<<"\n Opcion:";
		    cin>>respuesta;						
			size=respuesta.size();
			if(size>1){  //VALIDACION DE LA VARIABLE RESPUESTA
				cout<<"OPCION INVALIDA"<<endl;
				bandera=1;						
			}
			
			else if((respuesta[0]!=97 && respuesta[0]!=98 && respuesta[0]!=99 &&respuesta[0]!=65 && respuesta[0]!=66 &&respuesta[0]!=67)){
				cout<<"OPCION INVALIDA"<<endl;
				bandera=1;	
			}
		    system("pause");
		    system("cls");
		}while(bandera==1); //#########
			
		if(respuesta[0]==97 || respuesta[0]==65){  // CASO PARA CUANDO LA RESPUESTA ES A O a CODIFICAR
			do{
		    	fflush(stdin);
			    bandera=0;
			    cout<<"Ingrese el Nombre del archivo que desea crear\n(o modificar en caso de estar creado)\n\nNombre: ";
			    getline(cin, NomArchivo);
				size=NomArchivo.size();
			    for(int x=0;x<size;x++){  //VALIDACION DE SIGNOS ACEPTADOS EN EL ARCHIVO
			    	if ((NomArchivo[x]=='|' || NomArchivo[x]=='<'|| NomArchivo[x]=='?' || NomArchivo[x]=='*'|| NomArchivo[x]=='>'|| NomArchivo[x]=='"' || NomArchivo[x]=='/' ||NomArchivo[x]==':' ) && bandera==0){
			    		cout<<"Este nombre no puede tener ninguno de estos caracteres\n";
						cout<<"caracteres invalidos: <,>,?,:,|,/,*,\" ";	
			    		system("pause");
			    		system("cls");
						bandera=1;
					}
				}		    
			}while(bandera==1);
		    Archivo=strdup(NomArchivo.c_str());  //DUPLICAR LO DE LA VARIABLE NomArchivo EN LA VARIABLE ARCHIVO
		    do{
				bandera=0;
				cout << "Introduce el numero de desplazamiento deseado: "; //NUMERO PARA CODIFICAR
			    cin >> numerotemporal; 
				size=numerotemporal.size(); 
				for(int x=0;x<size;x++){  //VALIDACION PARA DATO SOLO ENTERO
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
			system("cls");  //INICIA EL SMS QUE VA A SER CODIFICADO
		    cout << "Ingrese su mensaje a ocultar\npara finalizar, escriba :SACAME en la ultima linea\n\n" << endl; 
		    ofstream VaciarArchivo(Archivo,std::ios::trunc); //CREA EL ARCHIVO Y EN CASO DE EXISTIR LO VACIA
		    VaciarArchivo.close(); //CERRAR EL ARCHIVO
			
			do{
			    getline(cin, cadena); 
				if(cadena==""){
			    	cadena=" ";
				}
				if(cadena==":SACAME"){ //ESCIBIR EL SMS HASTA INGRESAR LA PALABRA :SACAME PARA ACEPTAR
		    		bandera=1;         //Y ANULA LA CADENA PARA QUE NO SE VEA EL :SACAME EN EL ARCHIVO
					cadena="";
				}	
				variable.TextoCodificar(-(variable.getNumero()), cadena); //METODO PARA CODIFICAR EL TEXTO
				variable.setMensaje(cadena);
			    ofstream LlenarArchivo(Archivo,std::ios::app); //AGREGA EL TEXTO AL ARCHIVO
			    LlenarArchivo<<variable.getMensaje()<<endl;    //DESDE LA CLASE
			    LlenarArchivo.close();
		 	}while(bandera!=1);
		    ifstream LeerArchivo(Archivo);
			string Leer;
			cout<<"Mensaje Codificado:";  //MUESTRA EL SMS YA CODIFICADO
		 	while(getline(LeerArchivo,Leer)) {
		  		cout << Leer<<endl;
		 	}
		 	LeerArchivo.clear();
			LeerArchivo.close();
			system("pause");	
			system("cls");	    //#############
		}
		
		
		if(respuesta[0]==98 || respuesta[0]==66){   // CASO PARA CUANDO LA RESPUESTA ES b O b DECODIFICAR
			do{
		    	fflush(stdin);
			    bandera=0;
			    cout<<"Ingrese el Nombre del archivo que desea revelar:";  //BUSCAR EL ARCHIVO PARA DECODIFICAR
			    getline(cin, NomArchivo);
				size=NomArchivo.size();
			    for(int x=0;x<size;x++){
			    	if ((NomArchivo[x]=='|' || NomArchivo[x]=='<'|| NomArchivo[x]=='?' || NomArchivo[x]=='*'|| NomArchivo[x]=='>'|| NomArchivo[x]=='"' || NomArchivo[x]=='/' ||NomArchivo[x]==':' ) && bandera==0){
			    		cout<<"Este nombre no puede tener ninguno de estos caracteres\n";
						cout<<"caracteres invalidos: <,>,?,:,|,/,*,\" ";	//VALIDACION DE SIGNOS ACEPTADOS EN EL ARCHIVO
			    		system("pause");
			    		system("cls");
						bandera=1;
					}
				}
			}while(bandera==1);
		    Archivo=strdup(NomArchivo.c_str());//DUPLICAR LO DE LA VARIABLE NomArchivo EN LA VARIABLE ARCHIVO
			ifstream MostrarTexto(Archivo);
			if(MostrarTexto.is_open()){
				string salida;
				do{
					bandera=0;
					cout << "Introduce el numero de desplazamiento deseado:"; //VALIDACION DE LA VARIABLE
				    cin >> numerotemporal; 									//numerotemporal PARA QUE SOLO	
					size=numerotemporal.size();								//TENGA NUMEROS ENTEROS
					    
					for(int x=0;x<size;x++){
					    if(numerotemporal[x]<48 || numerotemporal[x]>57){
					    	bandera=1;
					    	cout<<"DATO INVALIDO\n";	
						}
						else{
							istringstream(numerotemporal)>>n;	//TRANSFORMACION DEL STRING A INT
						}
					}
				}while(bandera==1);
				variable.setNumero(n);
				cout<<"Texto Revelado:";
			 	while(getline(MostrarTexto,salida)) {
			 		variable.TextoDecodificar(variable.getNumero(), salida); //PROCESO
			  		cout << salida<<endl;									//PARA DECODIFICAR
			 	}
			}else{
				cout<<"\nEL ARCHIVO NO SE ENCONTRO\n\n"; //MENSAJE EN CASO DE NO ENCONTRARSE EL ARCHIVO
			}
			system("pause");	
			system("cls");	
		}
	}while(respuesta[0]!=99&& respuesta[0]!=67);
 	cout<<"MUCHAS GRACIAS...\nADIOS\n\n"; //MENSAJE DE SALIDA DEL PROGRAMA
 	system("PAUSE");
} 
