#include<iostream>
#include <string>
using namespace std;
int main() {
	
	int opcion = 0;
	int habitacion = 0;
	string habitaciones[20] ={"libre", "libre","libre","libre","libre","libre","libre","libre","libre","libre","libre","libre","libre",
	"libre","libre","libre","libre","libre","libre","libre"};
	
	
	while (opcion!= 4){
		system ("cls");

		cout << "1-Ocupar habitacion" << endl;
		cout << "2-Desocupar habitacion" << endl;
		cout << "3-Mostrar ocupacion" << endl;
		cout << "4-Salir" << endl;
		cin  >> opcion;
	

	
		switch(opcion){
			case 1:
				cout << "Por favor ingrese numero de habitacion a ocupar" << endl;
				cin >> habitacion;
				if (habitacion >= 0 && habitacion <20){ 
					if ( habitaciones[habitacion] == "libre" ){
						  habitaciones[habitacion] = "ocupado" ;
						  cout<< "la habitacion se ocupo con exito"	<< endl;
					}else{
						cout<< "la habitacion ya esta ocupada"	<< endl;
					}
				}else{
					
					cout<< "No existe tal habitacion" << endl;
				}
				break;
			case 2:
				cout << "Por favor ingrese numero de habitacion a Desocupar" << endl;
				cin >> habitacion;
				if (habitacion >= 0 && habitacion <20){ 
				
						  habitaciones[habitacion] = "libre" ;
						  cout<< "la habitacion quedo desocupada"	<< endl;
			
				}else{
					
					cout<< "No existe tal habitacion" << endl;
				}
		
				break;
			case 3:
				for (int i=0; i<20;i++){
					cout << "habitacion :" << i << ": " << habitaciones[i] << endl;
				}
				break;
			case 4:
				cout << "Salir" << endl;
				break;
			default:
				cout << "Verifique la opcion ingresada! " << endl;
				break;
			
			
		}
		system("pause");
		
	}
}
