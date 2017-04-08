#include <iostream>
#ifndef CodCesar_H
#define CodCesar_H

using namespace std;

class CodCesar{
	public:

		void setNumero(int n){
			numero= n;	
		}
		int getNumero(){
			return numero;
		}
		void setMensaje(string n){
			texto = n;
		}
		string getMensaje(){
			return texto;
		}
		
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
		    this->texto=cadena;
		}
		
		void TextoDecodificar(int n, string & cadena){
			TextoCodificar(n, cadena);
		}
	private:
		int numero;
		string texto;		
};

#endif

