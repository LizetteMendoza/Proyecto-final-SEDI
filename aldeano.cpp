#include"aldeano.h"

Aldeano::Aldeano(){}

Aldeano::Aldeano(const string& nombre, size_t edad, const string& genero, float salud){}
    
void Aldeano::setNombre(const string& nombre){
    this->nombre=nombre;
}
void Aldeano::setEdad(int edad){
    this->edad=edad;
}
void Aldeano::setGenero(const string& genero){
    this->genero=genero;
}
void Aldeano::setSalud(const float& salud){
    this->salud=salud;
}

string Aldeano::getnombre()const{
    return nombre;
}
size_t Aldeano::getEdad()const{
    return edad;
}
string Aldeano::getGenero(){
    return genero;
}
float Aldeano::getSalud()const{
    return salud;
}