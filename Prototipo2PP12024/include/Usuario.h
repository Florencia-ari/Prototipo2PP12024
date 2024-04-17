#ifndef USUARIO_H
#define USUARIO_H
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include<string>


using namespace std;


class Usuario
{
	 public:

        bool loginUsuario();
        bool buscarLoginUsuario(string user, string passw);

    protected:

    private:
		string id;
        string nombre;
        string contrasena;
};

#endif // USUARIO_H
