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

