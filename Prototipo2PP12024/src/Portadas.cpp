#include "Portadas.h"
#include <fstream>
#include <unistd.h>
#include <fstream>
#include "Usuario.h"
#include <iostream>

using namespace std;

void Portadas::dibujarPortada(string nombreArchivo)
	{
        string line;
        ifstream myFile(nombreArchivo);
        if(myFile.is_open())
        {
            while( getline(myFile, line))
            {
                cout << line << endl;
            }
            myFile.close();
            system("pause");
        }
        else
        {
            cout << "Error FATAL: el archivo de portada no pudo ser cargado" << endl;
            system("pause");
        }
	}
