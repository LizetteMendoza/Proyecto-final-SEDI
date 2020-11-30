
#include"civilizacion.h"
#include<iomanip>
#include<algorithm>
#include<fstream>

Civilizacion::Civilizacion(){}
Civilizacion::Civilizacion(const string &nombre, float ubicacionX, float ubicacionY, float puntuacion){
    this->nombre = nombre;
    this->ubicacionX = ubicacionX;
    this->ubicacionY = ubicacionY;
    this->puntuacion = puntuacion;
}

void Civilizacion::setNombre(const string&v){
    nombre = v;
}

void Civilizacion::setUbicacionX(float &v){
    ubicacionX = v;
}

void Civilizacion::setUbicacionY(float &v){
    ubicacionY = v;
}

void Civilizacion::setPuntuacion(float &v){
    puntuacion = v;
}

string Civilizacion::getNombre(){
    return nombre;
}

float Civilizacion::getUbicacionX(){
    return ubicacionX;
}

float Civilizacion::getUbicacionY(){
    return ubicacionY;
}

float Civilizacion::getPuntuacion(){
    return puntuacion;
}


void Civilizacion::agregarFinal(const Aldeano& a){
    aldeanos.push_back(a);
}

void Civilizacion::agregarInicio(const Aldeano& a){
    aldeanos.push_front(a);
}

void Civilizacion::print(){
    cout<<left;
        cout<<setw(10)<<"Nombre";
        cout<<setw(8)<<"Edad";
        cout<<setw(8)<<"Genero";
        cout<<setw(10)<<"Salud";
        cout<<endl;
    for(auto it=aldeanos.begin(); it !=aldeanos.end(); it++){
        cout<<*it<<endl;
    }
}

void Civilizacion::eliminarNombre(const string& nombre){
    for ( auto it= aldeanos.begin(); it!=aldeanos.end(); it++){
        Aldeano &a =*it;
        if(nombre==a.getnombre()){
            aldeanos.erase(it);
            break;
        }
    }
    
}

bool comparador(const Aldeano&a){
    return a.getEdad()>=60;
}

void Civilizacion::eliminarEdad(){
    aldeanos.remove_if(comparador);
}

void Civilizacion::eliminarEdad(size_t edad){
    aldeanos.remove_if([edad](const Aldeano& a){return a.getSalud()<edad;});
}

void Civilizacion::ordenarNombre(){
    aldeanos.sort();
}

bool compradorEdad(const Aldeano& a1, const Aldeano& a2){
    return a1.getEdad()>a2.getEdad();
}

void Civilizacion::ordenarEdad(){
     aldeanos.sort(compradorEdad);
}

void Civilizacion::ordenarSalud(){
    aldeanos.sort([](const Aldeano& a1, const Aldeano& a2 ){return a1.getSalud()>a2.getSalud();});
}

Aldeano* Civilizacion::buscar(const Aldeano &a){
    auto it = find(aldeanos.begin(), aldeanos.end(),a);

    if(it==aldeanos.end()){
       return nullptr;
   }
   else{
       return &(*it);
   }
}

void Civilizacion::respaldar_aldeanos(){
    ofstream archivo(getNombre()+".txt");

     for ( auto it= aldeanos.begin(); it!=aldeanos.end(); it++) {
        Aldeano &aldeano = *it; 
        archivo << aldeano.getnombre() << endl;
        archivo << aldeano.getEdad()   << endl;
        archivo << aldeano.getGenero() << endl;
        archivo << aldeano.getSalud()  << endl;
    }
    archivo.close();

}

void Civilizacion::recuperar_aldeanos(){
    ifstream archivo(getNombre()+".txt");
    if(archivo.is_open()){
        string temp;
        size_t edad;
        float salud;
        Aldeano a;

        while(true){
            getline(archivo,temp);
            if(archivo.eof());
            a.setNombre(nombre);

            getline(archivo,temp);
            edad=stoi(temp);
            a.setEdad(edad);
            
            getline(archivo,temp);
            a.setGenero(temp);

            getline(archivo,temp);
            salud=stof(temp);
            a.setSalud(salud);
            
            agregarInicio(a);

        }
    }
    archivo.close();
}



