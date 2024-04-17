#include <iostream>
#include <unistd.h>
#include <string>
#include "Portadas.h"
#include "Usuario.h"
#include <string>
#include "Registros.h"

using namespace std;

int main()
{
    cout << "" << endl;
        Portadas portadas;
		portadas .dibujarPortada("portada1.txt");

    bool accesoUsuario;
    Usuario usuarioRegistrado;

    //Llama al login de acceso
    accesoUsuario = usuarioRegistrado.loginUsuario();
    if (accesoUsuario)


  {
    int opciones;
    bool repetir = true;
    do
    {
        //Limpia pantalla
        system("cls");
        //imprime en pantalla
	cout<<"\t\t\t+-------------------------------+"<<endl;
	cout<<"\t\t\t| Maria Florencia Ariaga Chiroy |"<<endl;
	cout<<"\t\t\t|          9959-23-6741         |"<<endl;
	cout<<"\t\t\t+-------------------------------+"<<endl;
	cout<<"\t\t\t| 1. Catalogos                  |"<<endl;
	cout<<"\t\t\t| 2. Informes                   |"<<endl;
	cout<<"\t\t\t| 3. Salir del sistema          |"<<endl;
	cout<<"\t\t\t+-------------------------------+"<<endl;
	cout<<"\t\t\t|Opcion a escoger:[1/2/3]       |"<<endl;
	cout<<"\t\t\t+-------------------------------+"<<endl;
	cout<<"\t\t\tIngresa tu Opcion: ";
        cin >> opciones;

        //Un switch para crear el meno tipo do while
        switch (opciones)
        {
        case 1:
            {

            	Registros registros;
				registros.menuRegistros();

				system("cls");

                break;
            }
        case 2:
            {

				system("cls");

                break;
            }

			case 3: repetir = false;
                break;
        }
    } while (repetir);
    }

    system("cls");
    portadas.dibujarPortada("creditos.txt");
    return 0;
    return 0;
}
