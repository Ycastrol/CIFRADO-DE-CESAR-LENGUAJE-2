#include <iostream> 
#include <string.h> 
#include <fstream>
#include <sstream>

using namespace std;
void TextoCodificar(int n, string & cadena){
	for (int i = 0; i < cadena.length(); i++) { 
        if (cadena[i] >= 'a' && cadena[i] <= 'z') { 
          
            
        cadena[i]=cadena[i]-32;
            
        } 
		if (cadena[i] >= 'A' && cadena[i] <= 'Z') { 
            if (cadena[i] + n > 'Z') { 
                cadena[i] = 'A' - 'Z' + cadena[i] + n - 1; 
            } else if (cadena[i] + n < 'A') { 
                cadena[i] = 'Z' - 'A' + cadena[i] + n + 1; 
            } else { 
                cadena[i] += n; 
            } 
        } 
    }
}
		
void TextoDecodificar(int n, string & cadena){
	TextoCodificar(n, cadena);
} 
  
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
