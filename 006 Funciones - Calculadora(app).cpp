#include<iostream>
#include <string>
#include <wchar.h>
#include <locale.h>
#include <math.h>
#include <iomanip>

using namespace std;

void mostrarLeyenda(string leyenda){
	 cout << endl <<leyenda << endl;
}
float pedirDato(string leyenda){
    float salida = 0;
    mostrarLeyenda(leyenda); 
    cin>> salida;
	return salida;
}

float raices(float n1){
	float salida = 0;
    salida = sqrt(n1);
	return salida;
}

float coseno(float n2){
	float salida = 0;
    salida = cos(n2);
	return salida;
}



int main() {
	setlocale(LC_ALL, "");
	int opcion = 0;
	float num, resultado;
		
		
	
		while (opcion != 3) {
		system("cls");
		
		mostrarLeyenda("UNO para calcular raiz cuadrada de un numero");
		mostrarLeyenda("DOS para calcular coseno");
		mostrarLeyenda("TRES para SALIR");
		mostrarLeyenda("++++INGRESA TU OPCION++++");

		cin >> opcion;
		switch(opcion){
			case 1:
				num = pedirDato("Raiz cuadrada de: ");
				resultado = raices(num);
				cout << "la raiz cuadrada de tu número es: "<< resultado << endl;
				break;
			case 2:
				num = pedirDato("El coseno de un numero es: ");
				resultado = coseno(num);
				cout << "el coseno tu número es: "<< resultado << endl;
				break;
			case 3:
				cout << "Adios" << endl;
				break;
			default:
				cout << "No vale!""" << endl;
				break;
				
		}
		system("pause");
	}
}
