#include<iostream>
#include<conio.h>
#include<iomanip>
using namespace std;
// ejemplo de ocupación
//	XXX00X0X
//	XXXXXXXX
//	000000X0
//	XXX0X0X0
// guarda todos los asientos, true será cuando estén ocupados y false cuando estén libres
bool asientos[4][8] = {
						{false,false,false,false,false,false,false,false},
						{false,false,false,false,false,false,false,false},
						{false,false,false,false,false,false,false,false},
						{false,false,false,false,false,false,false,false}
					 }; 


void mostrarLeyenda(string leyenda){
	cout << leyenda << endl;   
}

string pedirString(string leyenda){
    string salida = "";
    mostrarLeyenda(leyenda);  
    getline(cin, salida);
	return salida;
}

float pedirFloat(string leyenda){
    float salida = 0;
    mostrarLeyenda(leyenda);  
    cin >> salida;
	return salida;
}

int pedirInt(string leyenda){
    int salida = 0;
    mostrarLeyenda(leyenda);  
    cin >> salida;
	return salida;
}

int mostrarMenuYObtenerOpcion(string opciones[], int cantidadOpciones){
		int opcion;
		system("cls");
		for(int i = 0; i < cantidadOpciones; i++){
			mostrarLeyenda( opciones[i]);
		}	
		//leer opcion
		opcion = pedirFloat("Ingresá el número de opción");
		return opcion;
}

// dada una fila y columna muestra X si está ocupado
// y 0 si está libre
void mostrarAsiento(int fila, int columna){
	if (asientos[fila][columna]){
		// si asientos[fila][columna] es verdadero está ocupado
		cout << "X";
	}else{
		cout << "0";
	}
}

bool asientoExiste(int fila, int columna){
	// dada una fila y columna devuelve true si existe en la matriz
	// y false si no existe
	bool existe = false;
	if (fila < 4 && columna < 8 ){
		existe = true;  
 	}
	return existe;
}

void ocuparAsiento(int fila, int columna){
	
	if (asientoExiste(fila, columna)){
		if(asientos[fila][columna]){
			mostrarLeyenda("Asiento esta ocupado");
		}else{
			asientos[fila][columna] = true;
			mostrarLeyenda("Reserva realizada!");
		}
	}else{
		mostrarLeyenda("El asiento no existe");
	}
   	// si existe el asiento y está libre, mostrar "reserva realizada" y ocuparlo
	// si está ocupado mostrar "asiento ocupado"
	// si no existe el asiento mostrar "Asiento inexistente"
}

void liberarAsiento(int fila, int columna){
	
	if (asientoExiste(fila, columna)){
		asientos[fila][columna] = false;
		mostrarLeyenda("El asiento lo liberaste");	
	}else{
		mostrarLeyenda("El asiento no existe");	
	}
	// si existe el asiento liberarlo
	// si no existe mostrar "Asiento inexistente"
}

int contarAsientos(bool estado){
	
	int contador = 0;
	for(int i=0;i < 4;i++){
		for(int j=0;j < 8;j++){
			if(asientos[i][j] == estado){
				contador = contador + 1;
			}
		}
	}	

	// debe recorrer la matriz contando los asientos
	// si estado es false contará los que tienen false
	// si estado es true contará los que tienen true
	
	return contador;
}

int main(){
	
	setlocale(LC_ALL, "");
	
	int fila, columna;
	int ocupados = 0;
	int libres = 0;
		
	
	int opcion = 0;	
	string opcionesMenu[5]={"1- Ocupar asiento",							
							"2- Ocupación",
							"3- Liberar asiento",
							"4- Totales",
							"5- SALIR"};
	do{		
		system("cls");
		opcion = mostrarMenuYObtenerOpcion(opcionesMenu,5);
		switch(opcion){
			case 1:
			 	
			 	fila = pedirInt("ingrese la Fila");
			 	columna = pedirInt("ingrese la Columna");
			 	ocuparAsiento(fila, columna);
				// debe solicitar fila y columna
				// si existe el asiento y está libre, mostrar "reserva realizada" y ocuparlo
				// si está ocupado mostrar "asiento ocupado"
				// si no existe el asiento mostrar "Asiento inexistente"
				break;
			case 2:
				
				for(int i=0;i < 4;i++)
				{
					for(int j=0;j < 8;j++){
						mostrarAsiento(i,j);
					}
				  	cout<< endl;
				}
				// debe mostrar la ocupación de toda la matriz marcando con X los asientos ocupados
				// y con 0 los libres
				// ejemplo comentado arriba
				break;
			case 3:
				
				fila = pedirInt("ingrese la Fila");
			 	columna = pedirInt("ingrese la Columna");
			 	liberarAsiento( fila, columna);
				// debe solicitar fila y columna 
				// si existe el asiento liberarlo
				// si no existe mostrar "Asiento inexistente"
				break;
			case 4:
											
				ocupados = 	contarAsientos(true);
				libres = contarAsientos(false);
					
				mostrarLeyenda("El total de asientos ocupados es");
				cout << ocupados << endl;
				mostrarLeyenda("El total de asientos libres es");
				cout << libres << endl;
				
				// Mostrar la cantidad de asientos libres y ocupados que hay
				break;
			case 5:
				cout << endl << "-->Saliendo del sistema";
				break;			
			default:
				cout << endl << "-->Esa opcion no existe";
				break;
		}
	system("pause");
	}while(opcion != 5);
}
