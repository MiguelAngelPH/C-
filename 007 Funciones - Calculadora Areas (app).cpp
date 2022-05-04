#include<iostream>
#include <string>
#include <wchar.h>
#include <locale.h>
using namespace std;

void mostrarLeyenda(string leyenda);

float pedirDato(string leyenda);

float calcularAreaFigura(float dato1, float dato2, string figura);

int main() {
	setlocale(LC_ALL, "");
	int opcion = 0;
	int lado, lado2, base, altura, radio;
	while (opcion != 5) {
		system("cls");
		// mostrar el menu		
		mostrarLeyenda("1-CALCULAR EL AREA DE UN CUADRADO");
		mostrarLeyenda("2-CALCULAR EL AREA DE UN TRIANGULO");
		mostrarLeyenda("3-CALCULAR EL AREA DE UN CIRCULO");
		mostrarLeyenda("4-CALCULAR EL AREA DE UN RECTANGULO");
		mostrarLeyenda("5-Salir");		
		//leer opcion
		opcion = pedirDato("Ingresa el numero de opcion:  ");	
		switch(opcion){
			case 1:
				mostrarLeyenda("1-CALCULAR EL AREA DE UN CUADRADO");
				lado = pedirDato("Ingrese el lado del cuadrado:  ");
				cout << "El area de un cuadrado es: "<< calcularAreaFigura( lado,  0,  "CUADRADO")  << endl;
				break;
			case 2:
				mostrarLeyenda("2-CALCULAR EL AREA DE UN TRIANGULO");
				base = pedirDato("Ingrese la base del triangulo:  ");
				altura = pedirDato("Ingrese la altura del triangulo:  ");
				cout << "El area del triangulo es: " << calcularAreaFigura( base,  altura,  "TRIANGULO") << endl;
				break;
			case 3:
				mostrarLeyenda("3-CALCULAR EL AREA DE UN CIRCULO");
				radio	= pedirDato("Ingrese el radio del circulo:  ");				
				cout << "El área del circulo es: " << calcularAreaFigura( radio,  0,  "CIRCULO")  << endl;
				break;
			case 4:
				mostrarLeyenda("2-CALCULAR EL AREA DE UN RECTANGULO");
				lado =  pedirDato("Ingrese el lado 1 del rectángulo:  ");
				lado2 =  pedirDato("Ingrese el lado 2 del rectángulo:  ");
				cout << "El área del rectángulo es: " << calcularAreaFigura( lado,  lado2,  "RECTANGULO") << endl;
				break;
			case 5:
				mostrarLeyenda("Adios...""");
				break;
			default:
				mostrarLeyenda("No vale!""");
				break;
				
		}
		system("pause");
	}
}

void mostrarLeyenda(string leyenda){
	 cout << endl <<leyenda;
}


float pedirDato(string leyenda){
    float salida = 0;
    mostrarLeyenda(leyenda); 
    cin>> salida;
	return salida;
}


float calcularAreaFigura(float dato1, float dato2, string figura){
	float area = 0;	
	if(figura == "CUADRADO") area = dato1 * dato1 ;
	if(figura == "TRIANGULO") area = dato1 * dato2 / 2 ;
	if(figura == "CIRCULO") area = 3.1421  * dato1 * dato1 ;
	if(figura == "RECTANGULO") area = dato1 * dato2;
	return area;	
}
