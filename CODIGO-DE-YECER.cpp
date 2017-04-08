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
	int bandera=0,size;
	string respuesta;
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
			cout<<"CODIFICAR"<<endl;
		}
		
		if(respuesta[0]==98 || respuesta[0]==66){
			cout<<"DECODIFICAR"<<endl;
		}
		
		
	
	}while(respuesta[0]!=99 && respuesta[0]!=67);
	return 0;
} 
