#include<iostream>
#include <string>
#include <wchar.h>
#include <locale.h>
using namespace std;
int main(){


string matriz_nombres[3][4]={{"Juan","Carla","Oscar","Lucio"},
                           {"Ramon","Pedro","Mariana","joaquin"},
							{"Alma","Nicolas","Pepe","lola"}};    
    
    
    string nombre;
    bool bandera = false;
    
    
    cout<< "ingrese un nombre para buscarlo en la base de datos:"<<endl;
    cin>> nombre;
    cout<< "El nombre que ingreso es: "<< nombre << endl;
    
    
    for (int i = 0; i < 3 ; i++)
    {
        for (int j = 0; j < 4 ; j++)
        {
        	if (nombre == matriz_nombres[i][j]){
	    		bandera = true;
        		break;
        		
            }
			
                                   
        }
    }
    
    if (bandera){
	
    	cout<<"El nombre si existe"<<  << endl;
	}else{
	
    	cout<<"El nombre que ingreso no existe"<<endl;
	}

}
