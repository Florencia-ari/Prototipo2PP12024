#include "Usuario.h"

#include<iostream>
#include "Portadas.h"
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>

using namespace std;

bool Usuario::loginUsuario()
{
    string u, contra;
    int contador=0;
    bool ingresa=false;

    do{
        system("cls");
        cout<<"+--------------------------------------------+"<<endl;
        cout<<"|           AUTENTICACION DE USUARIO         |"<<endl;
        cout<<"+--------------------------------------------+"<<endl;
        cout<<"| Solo tiene 3 intentos                      |"<<endl;
        cout<<"+--------------------------------------------+"<<endl;
        cout<<"Nombre de usuario: ";
        getline(cin, u);
        cout<<"contrasena: ";
        char caracter;
        caracter= getch();
        contra="";
        while (caracter !=13)
        {
            if(caracter !=8)
            {
			contra.push_back(caracter);
                cout<<"*";
            } else
            {
                if (contra.length() > 0)
                {
                    cout<<"\b \b";
                    contra = contra.substr(0, contra.length()-1);
                }
            }
            caracter = getch();
        }

        if (buscarLoginUsuario(u, contra)){
            ingresa=true;
        } else {
            cout<<"\nEl usuario y/o contrasena incorrectos"<<endl;
            cin.get();
            contador++;
        }
    } while (ingresa==false && contador<3);
    if (ingresa==false){
        cout<<"No puede ingresar al sistema"<<endl;
		cout<<"Contrasena y/o Usuario Incorrectos"<<endl;

        cin.get();
    } else {
        cout<<"\n\n***************  BIENVENIDO ***************"<<endl;
		cout<<"\n\nPrograma realizado por Maria Florencia Ariaga Chiroy"<<endl;

        cin.get();
    }
    return ingresa;
}

bool Usuario::buscarLoginUsuario(string user, string passw)
{
    system ("cls");
    fstream file;
    int found=0;
    file.open("Usuario.txt", ios::in);
    if (!file)
    {
    }
    else
    {
        file >> id >> nombre>> contrasena;
        while(!file.eof())
        {
            if(user==nombre)
            {
                if (passw == contrasena)
                {
                    found++;
                }
            }
            file >> id >> nombre >> contrasena;
        }
        if(found==0)
        {
            return false;
        }
        else
            return true;

        file.close();}
}
