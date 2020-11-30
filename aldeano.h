#ifndef ALDEANOS_H
#define ALDEANOS_H

#include<iostream>
#include<iomanip>
using namespace std;

class Aldeano
{
private:
    string nombre;
    size_t edad;
    string genero;
    float salud ;
public:
    Aldeano();
    Aldeano(const string& nombre, size_t edad, const string& genero, float salud);
    
    void setNombre(const string& nombre);
    void setEdad(int edad);
    void setGenero(const string& genero);
    void setSalud(const float& salud);

    string getnombre()const;
    size_t getEdad()const;
    string getGenero();
    float getSalud()const;

    friend ostream& operator <<(ostream& out, const Aldeano &a){
        out<<left;
        out<<setw(10)<<a.nombre;
        out<<setw(8)<<a.edad;
        out<<setw(8)<<a.genero;
        out<<setw(10)<<a.salud;

        return out;
    }

    friend istream& operator>>(istream& in, Aldeano&a){

        cout<<"Nombre: ";
        getline(cin,a.nombre);
        cout<<"Edad: ";
        cin>>a.edad; cin.ignore();
        cout<<"Genero: ";
        getline(cin,a.genero);
        cout<<"Salud: ";
        cin>>a.salud; 

        return in;

    }

    bool operator <(const Aldeano&a){
        return nombre<a.getnombre();
    }

    bool operator ==(const Aldeano&a){
        return nombre==a.getnombre();
    }

};

#endif
