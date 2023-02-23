#include <iostream>
#include <fstream>
#include <ctime>
#include <conio.h>
#include <stdlib.h>
/**********************************************************************

Taller 1
Febrero 13/2023
Natalia Catalina Guzmán Fuentes

Ejercicio 02:
- Capturar datos de los clientes para ser impresos en la factura
- Crear una estructura de datos que encapsule los datos de los usuarios
- Se require que el uso de la estructura sea a través de punteros
- Imprimir las facturas en un fichero de texto  
 
 **********************************************************************/
using namespace std;

//Se crea un TDA para la captura de datos de cada usuario 
struct cliente{
	string nombre;
	string apellido;
	int edad;
	long long cedula;
	long long celular;
};
//Firmas de las funciones a usar
void pedir_datos ();

//Función principal 
int main() {
	
	pedir_datos();
	
	return 0;
}

void pedir_datos ()
{
	//Declaración de variables 
	int n=0, i;
	
	//Se solicita el número de usuarios a registrar inicialmente 
	cout<<">> Bienvenido al sistema informatico que captura datos para ser impresos en la factura de los clientes "<<endl;
	cout<<endl<<"Cuantos clientes desea ingresar al sistema? "<<endl;
	cout<<">> ";
	cin>>n;
	
	//Se declara una variable de tipo cliente y se crea un vector del TDA de tamaño n
	cliente usuario[n];
	//Se declara una variable de tipo puntero 
	cliente *puntero_usuario = usuario; 
	
	//Se crea un ciclo para capturar todos los datos de los usuarios a registrar mediante un puntero 
	//Se solicita y almacena cada dato
	
	ofstream fichero_escritura("factura_cliente.txt");
	if(fichero_escritura.is_open()){
	for(i=0; i<n; i++)
	{
		cout<<endl<<"Ingrese los datos del cliente #"<<i+1<<": "<<endl;
		cout<<endl<<"Ingrese el nombre: "<<endl;
		cout<<">> ";
		cin>>(puntero_usuario+i)->nombre;
		fichero_escritura<<(puntero_usuario+i)->nombre<<endl;
		
		cout<<endl;
		cout<<"Ingrese el apellido "<<endl;
		cout<<">> ";
		cin>>(puntero_usuario+i)->apellido;
		fichero_escritura<<(puntero_usuario+i)->apellido<<endl;
		
		cout<<endl;
		cout<<"Digite la edad: "<<endl;
		cout<<">> ";
		cin>>(puntero_usuario+i)->edad;
		fichero_escritura<<(puntero_usuario+i)->edad<<endl;
		
		cout<<endl;
		cout<<"Digite el numero de cedula: "<<endl;
		cout<<">> ";
		cin>>(puntero_usuario+i)->cedula;
		fichero_escritura<<(puntero_usuario+i)->cedula<<endl;
		
		cout<<endl;
		cout<<"Digite el numero de celular: "<<endl;
		cout<<">> ";
		cin>>(puntero_usuario+i)->celular;
		fichero_escritura<<(puntero_usuario+i)->celular<<endl;
	
	}
}else {
		cout<<"No tiene permisos de escritura!!!"<<endl;
}
		fichero_escritura.close();
}
