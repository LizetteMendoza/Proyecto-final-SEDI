#ifndef CIVILIZACION_H
#define CIVILIZACION_H

#include<iostream>
#include"civilizacion.h"
#include<iomanip>
#include<list>
#include"aldeano.h"

using namespace std;

class Civilizacion
{
private:
    string nombre;
    float ubicacionX;
    float ubicacionY;
    float puntuacion;
    list<Aldeano>aldeanos;

public:
    Civilizacion();
    Civilizacion(const string &nombre, float ubicacionX, float ubicacionY, float puntuacion);

    void setNombre(const string&v);
    void setUbicacionX(float &v);
    void setUbicacionY(float &v);
    void setPuntuacion(float &v);

    string getNombre();
    float getUbicacionX();
    float getUbicacionY();
    float getPuntuacion();

    friend ostream& operator <<(ostream& out, const Civilizacion&c){
        out<<left;
        out<<setw(10)<<c.nombre;
        out<<setw(15)<<c.ubicacionX;
        out<<setw(15)<<c.ubicacionY;
        out<<setw(10)<<c.puntuacion;
        out<<endl;

        return out;
    }

    friend istream& operator>>(istream& in, Civilizacion&c){

        cout<<"Nombre: ";
        getline(cin,c.nombre);
        cout<<"Posicion en X :";
        cin>>c.ubicacionX;
        cout<<"Posicion en Y :";
        cin>>c.ubicacionY;
        cout<<"puntuacion:";
        cin>>c.puntuacion;

        return in;

    }

    bool operator ==(const Civilizacion&c){
        return nombre ==c.nombre;
    }

    bool operator ==(const Civilizacion&c)const {
        return nombre ==c.nombre;
    }

    bool operator <(const Civilizacion&c){
        return nombre <c.nombre;
    }

    bool operator <(const Civilizacion&c)const{
        return nombre <c.nombre;
    }

    void agregarFinal(const Aldeano& a);
    void agregarInicio(const Aldeano& a);
    void print();
    void eliminarNombre(const string& nombre);
    void eliminarEdad();
    void eliminarEdad(size_t edad);
    void ordenarNombre();
    void ordenarEdad();
    void ordenarSalud();

    Aldeano* buscar(const Aldeano &a);

    void respaldar_aldeanos();
    void recuperar_aldeanos();

};



#endif