#include <sstream>
#include <iostream>
#include <string>
using namespace std;
const int tamanio = 3;


string tribunas[tamanio]		= {"superior","media","inferior"};
int capacidades[tamanio] 		= {5,4,2};
float  precios[tamanio]   		= {100,200,250};
int  cantidadVendidas[tamanio]  = {0,0,0};


void mostrarLeyenda(string leyenda){
	cout << leyenda << endl;   
}

void mostrarLeyendaSinSalto(string leyenda){
	cout << leyenda ;   
}
string pedirString(string leyenda){
    string salida = "";
    mostrarLeyenda(leyenda); 
	cin.ignore();
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
		opcion = pedirInt("Ingresá el número de opción");
		return opcion;
}

string intToString(int num){
	string numStr;
	stringstream ss;
	ss << num;
	numStr = ss.str();
	return numStr;
}


int obtenerPosicionTribuna(string tribuna){
	int posicion = -1;
	for (int i = 0;i<tamanio;i++){
		if (tribuna == tribunas[i]){
			posicion = i;
			break;		
		}
	} 
	
	// buscar la tribuna y devolver la posición en el array
	return posicion;
}

void ventaTribuna(string tribuna){
	int posicion, entradas, costo;
	posicion = obtenerPosicionTribuna(tribuna);
	
	if(posicion == -1){
		mostrarLeyenda("La tribuna "+tribuna+" no existe");
	}else{
		
		entradas = pedirInt("ingrese la cantidad a comprar:  ");
		
		
		if(entradas <= capacidades[posicion] && entradas > 0 ){
			
			if (capacidades[posicion] > 0 && capacidades[posicion] <= 5 ){
				costo = precios[posicion] * entradas;
				cantidadVendidas[posicion] = cantidadVendidas[posicion] + entradas;//aca agregue la cantidad de entradas que se van vendiendo
				mostrarLeyenda("La cantidad de entradas tiene un costo de ");
				cout<< costo;
				capacidades[posicion] = capacidades[posicion] - entradas;
			}else{
				mostrarLeyenda("No quedan mas entradas");
			}
		}else{
			mostrarLeyenda("Se rebaso la capacidad de la tribuna : "+tribuna+". Intenta con menos");
		}
	}
		
	// validar si la tribuna existe y si tiene lugar
	// realizar la venta
	// actualizar la capacidad
	// si tiene lugar en dicha tribuna y el motrar monto
	// Cuando se termina de cargar una venta o se informa que no hay lugar se debe volver al menú inicial
    // Al finalizar las ventas, el sistema mostrará cada tribuna con su total vendido en cantidad y monto.	
	
}

void totalizar(string leyenda){
	
	float totalesSuperior, totalesInferior, totalesMedia;
	
	mostrarLeyenda("Resumen de Ventas");
	mostrarLeyenda("-----");
	
		mostrarLeyenda("TRIBUNA SUPERIOR");
		totalesSuperior = cantidadVendidas[0] * precios[0];
		cout << "Entradas Vendidas: " << cantidadVendidas[0] <<  " con " << "Total de $ " << totalesSuperior<< endl;
		
		mostrarLeyenda("TRIBUNA MEDIA");
		totalesMedia = cantidadVendidas[1] * precios[1];
		cout << "Entradas Vendidas: " << cantidadVendidas[1] <<  " con " << "Total de $ " << totalesMedia<< endl;
		
		mostrarLeyenda("TRIBUNA INFERIOR");
		totalesInferior = cantidadVendidas[2] * precios[2];
		cout << "Entradas Vendidas: " << cantidadVendidas[2] <<  " con " << "Total de $ " << totalesInferior<< endl;
			
		
		
	// mostrar los totales
}

int main()
{
	setlocale(LC_ALL, "");
	
	string tribu;
	// declaraciones
	
	int opcion;
	
	string opcionesMenu[2]={"1- Ingresar Venta",							
							"2- Salir y totalizar"
							};
	do{
		// menu de opciones
		opcion = mostrarMenuYObtenerOpcion(opcionesMenu,2);
		switch(opcion){
			case 1:	
				tribu = pedirString("Ingrese la tribuna");	
				obtenerPosicionTribuna(tribu);
				ventaTribuna(tribu);
				
				
				break;
			case 2:		
				   // prueba para ver como se me van cargando los vectores
					for(int i = 0; i < 3; i++){
					cout << "vector capacidades: " << capacidades[i]<< endl;
					}
				cout << "----"<< endl;;
				
				totalizar("totales");
				
				cout << endl << "-->Saliendo del sistema";
				break;			
			default:
				cout << endl << "-->Esa opcion no existe";
				break;
		}
		system("pause");
	}while(opcion !=2);	
		
	
}
