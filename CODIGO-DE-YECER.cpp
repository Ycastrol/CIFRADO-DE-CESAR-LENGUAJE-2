#include <iostream> 
#include <string.h> 
#include <fstream>
#include <sstream>

using namespace std; 
  
int main() { 

	int  respuesta;
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
		    
			
		if(respuesta==1){
			cout<<"CODIFICAR"<<endl;	
		}
		
		if(respuesta==2){
			cout<<"DECODIFICAR"<<endl;
		}
		
		
	
	}while(respuesta!=3);
	return 0;
} 
