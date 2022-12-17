#include<iostream>
#include<windows.h>
#include<conio.h>
#include<string>
#include<fstream>
#define reiniciarMenu cout<<"\n\t Da click para reiniciar el menu"; getch(); 
using namespace std;
#include "Lista.h"

void intro();
void menu();

//Instancia de Lista con alcance global
Lista lista_personas;

int main(){

    intro();
    menu();

    cout<<"\n\n";
    return 0;
}

void intro(){
    system("title Sistema gestor de listas de personas");
    Sleep(3000);
    cout<<"\n\t Iniciando...";
    Sleep(3000);
    cout<<"\n\t Bienvenidos...";
    Sleep(3000);
}

void menu(){
    
    int opcion,edad,opcion_orden;
    string nombre,nombre_archivo;
    float peso;
    double estatura;
    Nodo aux(NULL);

    do{
        system("cls");
        cout<<"\n\t +-----------------------------------+";
        cout<<"\n\t | Bienvenido al gestor de personas  |";
        cout<<"\n\t |-----------------------------------|";
        cout<<"\n\t | Selecciona una opcion:            |";
        cout<<"\n\t | 1) Mostrar lista                  |";
        cout<<"\n\t | 2) Insertar persona               |";
        cout<<"\n\t | 3) Buscar persona                 |";
        cout<<"\n\t | 4) Modificar persona              |";
        cout<<"\n\t | 5) Eliminar persona               |";
        cout<<"\n\t | 6) Ordernar lista                 |";
        cout<<"\n\t | 7) Guardar lista                  |";
        cout<<"\n\t | 8) Salir                          |";
        cout<<"\n\t +-----------------------------------+";
        cout<<"\n\t Opcion> ";
        cin>>opcion;

        switch(opcion){
            case 1: 
                cout<<"\n\t Cargando la lista...";
                Sleep(3000);
                lista_personas.mostrarLista();
                reiniciarMenu
                break;
            case 2:
                cout<<"\n\t Ingrese los datos de la nueva persona.";
                cout<<"\n\t Nombre: "; cin>>nombre;
                cout<<"\n\t Edad: "; cin>>edad;
                cout<<"\n\t Peso: "; cin>>peso;
                cout<<"\n\t Estatura: "; cin>>estatura;
                aux.modNombrePersona(nombre);
                aux.modEdadPersona(edad);
                aux.modPesoPersona(peso);
                aux.modEstaturaPersona(estatura);
                lista_personas.insertarNodo(aux);
                reiniciarMenu
                break;
            case 3: 
                cout<<"\n\t Escribe el nombre de la persona a buscar: ";
                cin>>nombre;
                lista_personas.buscarNodo(nombre);
                reiniciarMenu
                break;    
            case 4:
                cout<<"\n\t Escribe el nombre de la persona a modificar: ";
                cin>>nombre;
                lista_personas.modificarNodo(nombre);
                reiniciarMenu
                break;   
            case 5: 
                cout<<"\n\t Escribe el nombre de la persona a eliminar: ";
                cin>>nombre;
                lista_personas.eliminarNodo(nombre);
                reiniciarMenu
                break;   
            case 6:
                cout<<"\n\t +--------------------------+";
                cout<<"\n\t | 1) Ordenar por nombre    |";
                cout<<"\n\t | 2) Ordenar por edad      |";
                cout<<"\n\t | 3) Ordenar por peso      |";
                cout<<"\n\t | 4) Ordenar por estatura  |";
                cout<<"\n\t +--------------------------+";
                cout<<"\n\t Opcion de ordenamiento> ";
                cin>>opcion_orden;
                switch(opcion_orden){
                    case 1: case 2: 
                    case 3: case 4:
                        // Por el momento sólo cuenta con ordenamiento por edad.
                        cout<<"\n\t Ordenamiento por edades: ";
                        lista_personas.mostrarLista();
                        break;
                    default:
                        cout<<"\n\t La opcion de ordenamiento debe ser un numero entre 1 y 4.";
                        break;    
                }
                reiniciarMenu
                break;   
            case 7: 
                cout<<"\n\t Nombra del archivo (ejemplo.txt): ";
                cin>>nombre_archivo;
                lista_personas.guardarListaEnArchivo(nombre_archivo);
                reiniciarMenu
                break;   
            case 8: break;   
            default:
                cout<<"\n\t La opcion debe ser un numero entre 1 y 8.";
                reiniciarMenu
                break;    
        }   
    }while(opcion!=8);

    cout<<"\n\t Fin del programa, vuelva pronto...";
    Sleep(3000);


}