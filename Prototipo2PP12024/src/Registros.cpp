#include "Registros.h"
#include <fstream>
#include <unistd.h>
#include <fstream>
#include "Usuario.h"
#include <iostream>
#include "Portadas.h"


using namespace std;

void Registros::menuRegistros()
{

    int opcion;
	bool repetir = true;

	do
    {
	system("cls");

	cout<<"\t\t\t+-------------------------------+"<<endl;
	cout<<"\t\t\t|         CRUD                  |"<<endl;
	cout<<"\t\t\t+-------------------------------+"<<endl;
	cout<<"\t\t\t| 1. Ingreso Registros          |"<<endl;
	cout<<"\t\t\t| 2. Modificar Registros        |"<<endl;
	cout<<"\t\t\t| 3. Buscar Registros           |"<<endl;
	cout<<"\t\t\t| 4. Borrar Registros           |"<<endl;
	cout<<"\t\t\t| 5. Salir                      |"<<endl;
	cout<<"\t\t\t+-------------------------------+"<<endl;

	cout<<"Ingresa una Opcion: ";
    cin>>opcion;

    //Elegir una opcion del Menu
    switch(opcion)
    {
    case 1:
        agregarRegistros();
        system("pause");
		break;
	case 2:
		modificarRegistros();
		system("pause");
		break;
	case 3:
		buscarRegistros();
		system("pause");
		break;
	case 4:
		borrarRegistros();
		system("cls");
		break;
		case 5:

		break;
		;
	default:
		cout<<"\n\t\t\t Opcion invalida.";
		}
    }while(repetir,opcion!= 5);

}

 void Registros::agregarRegistros()
{
	system("cls");      //limpia pantalla
	fstream file;       //creacion variable file de la libreria fstream
	cout<<"\n-----------------------------------------------------------------------------------------------";
	cout<<"\n----------------------------------- Agregar Registros--------------------------------------"<<endl;
	//Ingreso de datos
	cout<<"\t\t\tIngresa ID: ";
	cin>>id;
	cout<<"\t\t\tIngresa Nombre: ";
	cin>>nombre;
	cout<<"\t\t\tIngresa tipo: ";
	cin>>tipobodega;
	cout<<"\t\t\tIngresa direccion : ";
	cin>>direccion;

	file.open("Registros.txt", ios::app | ios::out);
	file<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< tipobodega <<std::left<<std::setw(15)<< direccion<< "\n";
	file.close();   //Cierra el archivo
}

 void Registros::mostrarRegistros(){
	system("cls");  //limpia pantalla
	fstream file;   //crea
	int total=0;
	cout<<"\n-------------------------Detalles Registros-------------------------"<<endl;
	file.open("Registros.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		file >> id >> nombre >> tipobodega >> direccion;
		while(!file.eof())
		{
			total++;
			cout<<"\n\n\t\t\tId : "<<id<<endl;
			cout<<"\t\t\t Nombre: "<<nombre<<endl;
			cout<<"\t\t\t tipo: "<<tipobodega<<endl;
			cout<<"\t\t\tdireccion: "<<direccion<<endl;
			file >> id >> nombre >> tipobodega >> direccion;
		}
		if(total==0)
		{
			cout<<"\n\t\t\tError..";
		}
	}
	file.close();
}

 void Registros::modificarRegistros()  //Creacion de la clase Jugador, modificarJugadores
{
	system("cls");
	fstream file,file1;
	string Registros_id;
	int found=0;
	cout<<"\n------------------------- \"Modificacion Registros\" -------------------------"<<endl;
	file.open("Registros.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tError..,";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese ID del Registro que quiere modificar: ";
		cin>>Registros_id;
		file1.open("Registros2.txt",ios::app | ios::out);
		file >> id >> nombre >> tipobodega >> direccion;
		while(!file.eof())
		{
			if(Registros_id!=id)
			{
			 file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< tipobodega<<std::left<<std::setw(15)<< direccion << "\n";
			}
			else
			{
				cout<<"\t\t\tIngrese Id : ";
				cin>>id;
				cout<<"\t\t\tIngrese Nombre : ";
				cin>>nombre;
				cout<<"\t\t\tIngrese tipo: ";
				cin>>tipobodega;
				cout<<"\t\t\tIngrese direccion: ";
				cin>>direccion;
                file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< tipobodega<<std::left<<std::setw(15)<< direccion << "\n";
				found++;
			}
			file >> id >> nombre >> tipobodega >> direccion;

		}
		file1.close();
		file.close();
		remove("Registros.txt");
		rename("Registros2.txt","Registros.txt");

	}
}

 void Registros::buscarRegistros()
{
	system("cls");
	fstream file;
	int found=0;
	file.open("Registros.txt",ios::in);
	if(!file)
	{
		cout<<"\n-------------------------Datos de Registros------------------------"<<endl;
		cout<<"\n\t\t\tERROR...";
	}
	else
	{
		string Registros_id;
		cout<<"\n-------------------------Datos de Registros------------------------"<<endl;
		cout<<"\nIngrese Id de Registroa buscar: ";
		cin>>Registros_id;
		file >> id >> nombre >> tipobodega>> direccion;
		while(!file.eof())
		{
			if(Registros_id==id)
			{
				cout<<"\n\n\t\t\t ID: "<<id<<endl;
				cout<<"\t\t\t Nombre: "<<nombre<<endl;
				cout<<"\t\t\t tipo: "<<tipobodega<<endl;
				cout<<"\t\t\t direccion: "<<direccion<<endl;
				found++;
			}
			file >> id >> nombre >> tipobodega >> direccion;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Registros no encontrado...";
		}
		file.close();
	}
}

 void Registros::borrarRegistros()
{
	system("cls");
	fstream file,file1;
	string Registros_id;
	int found=0;
	cout<<"\n-------------------------Detalles de Registros-------------------------"<<endl;
	file.open("Registros.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tERROR...";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el Id del Registro: ";
		cin>>Registros_id;
		file1.open("Registros2.txt",ios::app | ios::out);
		file >> id >> nombre >> tipobodega >> direccion;
		while(!file.eof())
		{
			if(Registros_id!= id)
			{
				file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< tipobodega <<std::left<<std::setw(15)<< direccion << "\n";
			}
			else
			{
				found++;
				cout << "\n\t\t\tAccion Realizada Correctamente";
			}
			file >> id >> nombre >> tipobodega>> direccion;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Id del Registro no encontrado...";
		}
		file1.close();
		file.close();
		remove("Registros.txt");
		rename("Registros2.txt","Registros.txt");
	}
}
