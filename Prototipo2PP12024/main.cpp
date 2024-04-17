#include <iostream>
#include <unistd.h>
#include <string>
#include "Portadas.h"
#include "Usuario.h"
#include <string>

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




    system("cls");
    portadas.dibujarPortada("creditos.txt");
    return 0;
    return 0;
}
