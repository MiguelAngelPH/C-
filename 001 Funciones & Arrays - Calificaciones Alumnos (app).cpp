#include <sstream>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//string alumnos[4]={"","","",""};
//float notas[4][3];
//int cantidad = 4;


int const maximo = 2;
string alumnos[maximo];
float notas[maximo][3];
int cantidad = 0;

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

int obtenerPosicionAlumno(string alumno){
	
	int posicion = -1;
	for(int i=0;i<cantidad;i++){
		if (alumno == alumnos[i]){
			posicion = i;
			break;
		
		}
	}	
	// devolver la posición del alumno en el array o -1 si no existe
	return posicion;
}


void cargarnotas(string alumno){
	int posiAlumno = 0;
	if (cantidad < maximo){
		posiAlumno = obtenerPosicionAlumno(alumno);
		if (posiAlumno == -1){
			alumnos[cantidad] = alumno;
			notas[cantidad][0] = pedirFloat("Ingrese la nota 1 :");
			notas[cantidad][1] = pedirFloat("Ingrese la nota 2 :");
			notas[cantidad][2] = pedirFloat("Ingrese la nota 3 :");
			cantidad = cantidad + 1;
		}else{
			mostrarLeyenda("El Alumno ya existe! Utiliza la opción modificar}");
		}
	}else{
		mostrarLeyenda("El curso esta lleno");	
	}
	

/*
	Si la cantidad ingresada hasta el momento es igual a 5 deberá mostrar “El curso está completo”. 
	Si la cantidad ingresada es menor a 5 deberá solicitar nombre y apellido del alumno y, 
	si el alumno existe mostrar  "El alumno ya existe, si lo desea elija Modificar", 
	caso contrario permitir el ingreso de las 3 notas. Deberá guardar en 
	la posición correspondiente al próximo libre el nombre del alumno y cada una de sus notas.
*/
	
}


void modificarnotas(string alumno){
	int posiAlumno = 0;
	posiAlumno = obtenerPosicionAlumno(alumno);
	if ( posiAlumno > -1 ){
		
		notas[posiAlumno][0] = pedirFloat("Ingrese la nota 1 :");
		notas[posiAlumno][1] = pedirFloat("Ingrese la nota 2 :");
		notas[posiAlumno][2] = pedirFloat("Ingrese la nota 3 :");
	}else{
		mostrarLeyenda("El Alumno no existe! Utiliza la opción agregar Alumno}");	
	}
	
/*
Deberá solicitar nombre y apellido del alumno y, si el alumno no existe mostrar 
"El alumno no existe, si lo desea elija Ingresar",
 caso contrario permitir ingresar las 3 notas y reemplazarlas en la posición del alumno
*/
}

void listarNotas(){
	
	mostrarLeyenda( "Listado de notas del curso");
	mostrarLeyenda( "-------------------------------------------------------------------------------");
	mostrarLeyenda( "Alumno                                Nota1      Nota2      Nota3      Promedio");
	mostrarLeyenda( "-------------------------------------------------------------------------------");
	
	for(int i=0;i<cantidad;i++){
		cout <<left<<setw(38)<<alumnos[i]
			 <<left<<setw(11)<<notas[i][0]
			 <<left<<setw(11)<<notas[i][1]
			 <<left<<setw(11)<<notas[i][2]  
			 <<left<<setw(11)<<(notas[i][0] + notas[i][1] + notas[i][2]) / 3
			 <<endl;
	}	
	
	mostrarLeyenda( "-------------------------------------------------------------------------------");
		
	/*
	Listado de notas con promedio por alumno
	nombre alumno, nota1, nota2, nota3, promedio
	*/
}

void incicializarDatos(){
	/*
	limpiar los datos de array y matriz
	*/
}

int main()
{
	setlocale(LC_ALL, "");
	 incicializarDatos();
	// declaraciones
	string nombreAlumno= "";	
	int opcion;
	string opcionesMenu[4]={
							"1 - Ingresar Alumno y notas",
							"2 - Modificar Notas Alumno",
							"3 - Listado de notas",
							"4- Salir"
							};
							
		
	do{
		// menu de opciones
		opcion = mostrarMenuYObtenerOpcion(opcionesMenu,4);
		switch(opcion){
			case 1:
				nombreAlumno = pedirString("Ingrese el nombre del Alumno: ");
				cargarnotas(nombreAlumno);
				
				// llamar a la función que corresponda
				break;
			case 2:	
				nombreAlumno = pedirString("Ingrese el nombre del Alumno: ");
				modificarnotas(nombreAlumno);
			
				// llamar a la función que corresponda	
				break;			
			case 3:		
				
				listarNotas();
				// llamar a la función que corresponda
				break;
			case 4:		
				break;
			default:
				cout << endl << "-->Esa opcion no existe";
				break;
		}
		system("pause");
	}while(opcion !=4);	
		
	
}
