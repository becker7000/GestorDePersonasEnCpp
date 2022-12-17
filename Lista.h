#include "Nodo.h"

//Definición de la clase Lista
class Lista{
    private:
        Nodo* primero;
    public:
        Lista();
        void insertarNodo(Nodo _nuevo);
        void mostrarLista();
        void buscarNodo(string _nombre);
        void modificarNodo(string _nombre);
        void eliminarNodo(string _nombre);
        void guardarListaEnArchivo(string _nombre_archivo);
};

//Constructor de lista
Lista::Lista(){
    this->primero=NULL;
}

//Definición de insertarNodo de la clase Lista
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

//Definición de mostrarLista de la clase Lista
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

//Definición de buscarNodo de la clase Lista
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

//Definción de modificarNodo de la clase Lista
void Lista::modificarNodo(string _nombre){
    Nodo* actual = new Nodo(NULL);
    actual=this->primero;
    bool encontrado=false;
    string nombre;
    int edad;
    float peso;
    double estatura;
    while(actual!=NULL){
        if(actual->regNombrePersona().compare(_nombre)==0){
            cout<<"\n\t La persona ha sido encontrada en la lista.";
            actual->mostrarPersona();
            cout<<"\n\t Ingrese los nuevos datos de la nueva persona.";
            cout<<"\n\t Nombre: "; cin>>nombre;
            cout<<"\n\t Edad: "; cin>>edad;
            cout<<"\n\t Peso: "; cin>>peso;
            cout<<"\n\t Estatura: "; cin>>estatura;
            actual->modNombrePersona(nombre);
            actual->modEdadPersona(edad);
            actual->modPesoPersona(peso);
            actual->modEstaturaPersona(estatura);
            cout<<"\n\t Los datos de la persona han sido modificados.";
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

//Definición de eliminarNodo de la clase Lista
void Lista::eliminarNodo(string _nombre){
   if(this->primero!=NULL){  // Preguntamos si la lista está vacía
        Nodo *aux_borrar;
        Nodo *anterior=NULL;
        aux_borrar = this->primero;

        while((aux_borrar!=NULL)&&(aux_borrar->regNombrePersona().compare(_nombre)!=0)){
            anterior=aux_borrar;
            aux_borrar=aux_borrar->regSiguiente();
        }

        if(aux_borrar==NULL){
            cout<<"\n\t El elemento no ha sido encontrado";
        }else if(anterior==NULL){
            cout<<"\n\t El primer elemento de la lista ha sido borrado...";
            this->primero=this->primero->regSiguiente();
            delete aux_borrar;
        }else{
            cout<<"\n\t El elemento seleccionado ha sido borrado...";
            anterior->modSiguiente(aux_borrar->regSiguiente());
            delete aux_borrar;
        }

    }else{
        cout<<"\n\t La lista esta vacia";
    }
}

//Definición de la guardarListaEnArchivo de la clase Lista
void Lista::guardarListaEnArchivo(string _nombre_archivo){
    string nombre_archivo=_nombre_archivo;
    ofstream archivo;
    //Abrimos el archivo donde vamos a guardar
    archivo.open(nombre_archivo.c_str(),fstream::out);    
    //Empezamos a recorrer la lista escribiendo sobre el archivo
    if(this->primero==NULL){
        cout<<"\n\t La lista esta vacia...";
    }else{
        Nodo* actual = new Nodo(NULL);
        actual=this->primero;
        cout<<"\n\t Guardando archivo...";
        Sleep(3000);
        while(actual!=NULL){
            archivo<<"\n\t +-----------------------------------+";
            archivo<<"\n\t | Nombre: "<<actual->regNombrePersona();
            archivo<<"\n\t | Edad: "<<actual->regEdadPersona();
            archivo<<"\n\t | Peso: "<<actual->regPesoPersona();
            archivo<<"\n\t | Estatura: "<<actual->regEstaturaPersona();
            archivo<<"\n\t +-----------------------------------+";
            actual=actual->regSiguiente(); 
        }
    }
    archivo.close();
    cout<<"\n\t La lista ha sido guardada en: "<<_nombre_archivo<<" correctamente...";
}
