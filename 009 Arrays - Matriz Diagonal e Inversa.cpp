#include <iostream>
#include <string>
#include <wchar.h>
#include <iomanip>
#include <locale.h>
using namespace std;
// Constantes de máximo tamañio de matriz
int const MAX_COL = 100;
int const MAX_FIL = 100;

int main()
	{
	
	setlocale(LC_ALL, "");
	// creo la matriz con los máximos, asi despues yo elijo el tamaño facilmente
	int numeros[MAX_FIL][MAX_COL];		
	// Variables que definirán el área utilizable
	int FILAS = 0;	int COLS = 0; 
	// le pido al usuario el tamaño
	int contador = 0;
	cout<< "Ingrese tamaño de la matriz :";	
	cin >> FILAS;
	COLS = FILAS;
	if (FILAS > MAX_FIL ){
		cout<< "EL tamaño no puede superar :"<<MAX_FIL<<endl;	
	}else{		
		// cargo los valores	
		for (int i = 0; i < FILAS ; i++)
		{
			for (int j = 0; j < COLS ; j++)
			{								
				contador = contador + 1 ;
				numeros[i][j]= contador ;
								
			}
		}		
		
		cout<< "La matriz entera " <<endl;
		for (int i = 0; i < FILAS ; i++)
	    {    	
			for (int j = 0; j < COLS ; j++){
				cout<<setw(2) <<numeros[i][j] << "|" ;		
			}
			cout<< endl;	
	    }
	
	    //es donde se carga la diagonal.	
		cout<< "La diagonal es:  " <<endl;
		for (int i = 0; i < FILAS ; i++)
	    {    	
			for (int j = 0; j < COLS ; j++){
			
				if (i==j){
					cout << setw(2) <<numeros[i][j]  ;		
				}else{
		        	cout << "--";
				}	    					
		    }
			cout<<endl;	
	    }
	
	    //donde se carga la diagonal inversa.
	    cout<< "La 2da diagonal es:  " <<endl;
		for (int i = 0; i < FILAS ; i++)
	    {    	
			for (int j = 0; j < COLS ; j++){
			
				if (j == COLS - 1 - i) {					
					cout << setw(2) << numeros[i][j]  ;			
				}else{
		        	cout << "--";
				}	    
				
		    }
			cout<<endl;	
		}	
	}
}
