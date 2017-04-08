#include <iostream> 
#include <string.h> 
#include <fstream>
#include <sstream>

using namespace std;

  
int main() { 
	int bandera=0,size;
	string respuesta;
	do{
		do{
		    cout<<"\t_________________________________________________________\n";
		    cout<<"\tº CODIFICACION Y DECODIFICACION DE ARCHIVOS!!!!!.        º\n";
		    cout<<"\tº Seleccione la accion que desee tomar:                  º\n";
		    cout<<"\tº                                                        º\n";
		    cout<<"\tº A) Crear un archivo para guardar un mensaje codificado.º\n";
		    cout<<"\tº B) Decodificar los mensajes ocultos en los archivos.   º\n";
		    cout<<"\tº C) Salir.                                              º\n";
		    cout<<"\tº________________________________________________________º\n";
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
			cout<<"CODIFICAR"<<endl;
		}
		
		if(respuesta[0]==98 || respuesta[0]==66){
			cout<<"DECODIFICAR"<<endl;
		}
		
		
	
	}while(respuesta[0]!=99 && respuesta[0]!=67);
	return 0;
} 
