#ifndef REGISTROS_H
#define REGISTROS_H
#include "Usuario.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include<string>
using namespace std;


class Registros
{
	public:
		void menuRegistros();
        void agregarRegistros();
        void mostrarRegistros();
        void modificarRegistros();
        void buscarRegistros();
        void borrarRegistros();


	protected:

	private:
		 string id;
        string nombre;
        string tipobodega;
        string direccion;

};

#endif // REGISTROS_H
