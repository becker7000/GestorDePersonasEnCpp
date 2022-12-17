#include<iostream>
#include<conio.h>
#include<windows.h>
#define reiniciarMenu cout<<"\n\t Da click para reiniciar el menu"; getch(); 
using namespace std;

//Estructuras:
struct Nodo{
    int dato; // Dato que voy a guardar en la lista
    Nodo* siguiente; // Apuntador al siguiente Nodo
};

//Función insertarLista:
void menu();
void insertarLista(Nodo *&,int);
void mostrarLista(Nodo* lista);
void buscarLista(Nodo* lista,int dato);
void eliminarNodo(Nodo *&, int);

// Variables globales:
Nodo* lista=NULL;

int main(){

    menu();  

    cout<<"\n\n";
    return 0;
}

void menu(){

    int opcion,dato;

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
        cout<<"\n\t | 4) Eliminar persona               |";
        cout<<"\n\t | 5) Salir                          |";
        cout<<"\n\t +-----------------------------------+";
        cout<<"\n\t Opcion> ";
        cin>>opcion;

        switch(opcion){
            case 1: 
                cout<<"\n\t Cargando la lista...";
                Sleep(3000);
                mostrarLista(lista);
                reiniciarMenu
                break;
            case 2:
                cout<<"\n\t Escribe una edad: ";
                cin>>dato;
                insertarLista(lista,dato);
                reiniciarMenu
                break;
            case 3: 
                cout<<"\n\t Escribe la edad de la persona a buscar: ";
                cin>>dato;
                buscarLista(lista,dato);
                reiniciarMenu
                break;    
            case 4:
                cout<<"\n\t Escribe la edad de la persona a eliminar: ";
                cin>>dato;
                eliminarNodo(lista,dato);
                reiniciarMenu
                break;   
            case 5: break;   
            default:
                cout<<"\n\t La opcion debe ser un numero entre 1 y 4.";
                reiniciarMenu
                break;    
        }   
    }while(opcion!=5);

    cout<<"\n\t Fin del programa, vuelva pronto...";
    Sleep(3000);

}

void insertarLista(Nodo *&lista, int n){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;

    Nodo *aux1 = lista;
    Nodo *aux2;

    while((aux1!=NULL)&&(aux1->dato<n)){
        aux2=aux1;
        aux1=aux1->siguiente;
    }

    if(lista==aux1){
        lista = nuevo_nodo;
    }else{
        aux2->siguiente = nuevo_nodo;
    }

    nuevo_nodo->siguiente=aux1;
    cout<<"\n\t Elemento "<<n<<" insertado correctamente...";
}

void mostrarLista(Nodo* lista){
    if(lista==NULL){
        cout<<"\n\t La lista esta vacia.";
    }else{
        Nodo* actual = new Nodo();
        actual=lista;
        while(actual!=NULL){
            cout<<"\n\t Dato: "<<actual->dato<<" -> ";
            actual=actual->siguiente;
        }
    }
}

// Usamos el algoritmo de busqueda secuencial:
void buscarLista(Nodo *lista, int dato){
    Nodo* actual = new Nodo();
    actual=lista;
    bool encontrado=false;
    while(actual!=NULL){
        if(actual->dato==dato){
            cout<<"\n\t Dato "<<actual->dato<<" encontrado en la lista.";
            encontrado=true;
            break;
        }
        actual=actual->siguiente;
    }
    if(encontrado==false){
        cout<<"\n\t El dato "<<dato<<" no fue encontrado en la lista.";
    }
}

void eliminarNodo(Nodo *&lista, int n){
    if(lista!=NULL){  // Preguntamos si la lista está vacía
        Nodo *aux_borrar;
        Nodo *anterior=NULL;
        aux_borrar = lista;

        while((aux_borrar!=NULL)&&(aux_borrar->dato!=n)){
            anterior=aux_borrar;
            aux_borrar=aux_borrar->siguiente;

        }

        if(aux_borrar==NULL){
            cout<<"\n\t El elemento no ha sido encontrado";
        }else if(anterior==NULL){
            cout<<"\n\t El primer elemento de la lista ha sido borrado...";
            lista=lista->siguiente;
            delete aux_borrar;
        }else{
            cout<<"\n\t El elemento seleccionado ha sido borrado...";
            anterior->siguiente = aux_borrar->siguiente;
            delete aux_borrar;
        }

    }else{
        cout<<"\n\t La lista esta vacia";
    }
}