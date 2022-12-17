#include<iostream>
#include<windows.h>
#include<conio.h>
#include<string>
#define reiniciarMenu cout<<"\n\t Da click para reiniciar el menu"; getch(); 
using namespace std;

//Definción de la estructura Datos.
struct Datos{ // Los atributos inicializados en cero o vacío.
    string nombre;
    int edad;
    float peso;
    double estatura;
};

struct Datos datos={"",0,0.0,0.0};

//Definición de la clase Nodo.
class Nodo{
    private:
        struct Datos persona;
        Nodo *siguiente;
    public:
        Nodo(Nodo *siguiente); // Constructor
        struct Datos regPersona();
        Nodo* regSiguiente();
        void modPersona(struct Datos _persona);       
        void modSiguiente(Nodo *_siguiente);
        void modNombrePersona(string _nombre);
        void modEdadPersona(int _edad);
        void modPesoPersona(float _peso);
        void modEstaturaPersona(double _estatura);
        string regNombrePersona();
        int regEdadPersona();
        float regPesoPersona();
        double regEstaturaPersona();
        void mostrarPersona();
};

// Constructor de la clase Nodo
Nodo::Nodo(Nodo *_siguiente){
    this->persona=datos;
    this->siguiente=_siguiente;
}

// Modificador de persona de la clase Nodo
void Nodo::modPersona(struct Datos _persona){
    this->persona=_persona;
}

//Modificador de siguiente de la clase Nodo
void Nodo::modSiguiente(Nodo *_siguiente){
    this->siguiente=_siguiente;
}

//Retornador de persona de la clase Nodo
struct Datos Nodo::regPersona(){
    return this->persona;
}

//Retornador de siguiente de la clase Nodo
Nodo* Nodo::regSiguiente(){
    return this->siguiente;
}

//Modificador del nombre de persona de la clase Nodo
void Nodo::modNombrePersona(string _nombre){
    this->persona.nombre=_nombre;
}

//Modificador de la edad de persona de la clase Nodo
void Nodo::modEdadPersona(int _edad){
    this->persona.edad=_edad;
}

//Modificador de el peso de persona de la clase Nodo
void Nodo::modPesoPersona(float _peso){
    this->persona.peso=_peso;
}

//Modificador de la estatura de persona de la clase Nodo
void Nodo::modEstaturaPersona(double _estatura){
    this->persona.estatura=_estatura;
}

//Retornador del nombre de persona de la clase Nodo
string Nodo::regNombrePersona(){
    return this->persona.nombre;
}

//Retornador de la edad de persona de la clase Nodo
int Nodo::regEdadPersona(){
    return this->persona.edad;
}

//Retornador del peso de persona de la clase Nodo
float Nodo::regPesoPersona(){
    return this->persona.peso;
}

//Retornador de la estatura de persona de la clase Nodo
double Nodo::regEstaturaPersona(){
    return this->persona.estatura;
}

//Mostrador de todos los campos de persona(Datos) de la clase Nodo
void Nodo::mostrarPersona(){
    cout<<"\n\t +-----------------------------------+";
    cout<<"\n\t | Nombre: "<<this->regNombrePersona();
    cout<<"\n\t | Edad: "<<this->regEdadPersona();
    cout<<"\n\t | Peso: "<<this->regPesoPersona();
    cout<<"\n\t | Estatura: "<<this->regEstaturaPersona();
    cout<<"\n\t +-----------------------------------+";
}

class Lista{
    private:
        Nodo* primero;
    public:
        Lista();
        void insertarNodo(Nodo _nuevo);
        void mostrarLista();
        void buscarNodo(string _nombre);
};

Lista::Lista(){
    this->primero=NULL;
}

void Lista::insertarNodo(Nodo _nuevo){
    Nodo *nuevo_nodo = new Nodo(NULL);
    nuevo_nodo->modPersona(_nuevo.regPersona());
    Nodo *aux1 = this->primero;
    Nodo *aux2;

    while((aux1!=NULL)&&(aux1->regEdadPersona()<_nuevo.regEdadPersona())){
        aux2=aux1;
        aux1=aux1->regSiguiente();
    }

    if(this->primero==aux1){
        this->primero = nuevo_nodo;
    }else{
        aux2->modSiguiente(nuevo_nodo);
    }

    nuevo_nodo->modSiguiente(aux1);
    cout<<"\n\t La siguiente persona ha sido insertada correctamente: ";
    nuevo_nodo->mostrarPersona();
}

void Lista::mostrarLista(){
    if(this->primero==NULL){
        cout<<"\n\t La lista esta vacia...";
    }else{
        Nodo* actual = new Nodo(NULL);
        actual=this->primero;
        while(actual!=NULL){
            actual->mostrarPersona();
            actual=actual->regSiguiente();
        }
    }
}

void Lista::buscarNodo(string _nombre){
    Nodo* actual = new Nodo(NULL);
    actual=this->primero;
    bool encontrado=false;
    while(actual!=NULL){
        if(actual->regNombrePersona().compare(_nombre)==0){
            cout<<"\n\t La persona ha sido encontrada en la lista.";
            actual->mostrarPersona();
            encontrado=true;
            break;
        }
        actual=actual->regSiguiente();
    }
    if(encontrado==false){
        cout<<"\n\t La persona de nombre "<<_nombre<<" no fue encontrada en la lista.";
    }
}

void menu();

//Instancia de Lista con alcance global
Lista lista_personas;

int main(){

    menu();

    cout<<"\n\n";
    return 0;
}


void menu(){
    
    int opcion;
    string nombre;
    int edad;
    float peso;
    double estatura;
    Nodo aux(NULL);

    do{
        system("title Gestor de personas");
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
                reiniciarMenu
                break;   
            case 5: 
                
                reiniciarMenu
                break;   
            case 6: break;   
            default:
                cout<<"\n\t La opcion debe ser un numero entre 1 y 6.";
                reiniciarMenu
                break;    
        }   
    }while(opcion!=6);

    cout<<"\n\t Fin del programa, vuelva pronto...";
    Sleep(3000);


}