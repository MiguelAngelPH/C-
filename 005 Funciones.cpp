#include <iostream>
#include <string>
#include <wchar.h>
#include <iomanip>
#include <locale.h>
#include <math.h>

using namespace std;

void mostrarLeyenda(string leyenda){
	 cout << endl <<leyenda;
}

float pedirDato(string leyenda){
    float salida = 0;
    mostrarLeyenda(leyenda); 
    cin>> salida;
	return salida;
}

float promedio2(float n1, float n2){
	float salida = 0;
    salida = (n1+n2)/2;
	return salida;
}



int main(){
	setlocale(LC_ALL, "");
	

	
	
	float tempMax, tempMin, tempMed;

	mostrarLeyenda("Bienvenido al sistema");
	
	tempMax = pedirDato("Ingrese la temperatura máxima: ");
	tempMin = pedirDato("Ingrese la temperatura mínima: ");
	
	tempMed = promedio2(tempMax,tempMin);
	cout<<"La temperatura media es:  "<<tempMed<<endl;
	
	mostrarLeyenda("Gracias por utilizar nuestros servicios");
	
}
