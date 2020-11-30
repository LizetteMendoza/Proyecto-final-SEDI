#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#include"civilizacion.h"
#include<vector>

class Videogame
{
private:
    string usuario;
    vector<Civilizacion>civilizaciones;
public:
    Videogame();
    Videogame(const string &usuario);
    void agregarCivilizacion(const Civilizacion&c);
    void mostrar();
    void insertar(const Civilizacion &c, size_t pos);
    void setUsuario(const string&v);
    string getUsuario();


    size_t size();
    void inicializar(const Civilizacion&c, size_t n);
    void eliminar(Civilizacion &c);
    void ordenar();
    void ordenarNombre();
    void ordenarUx();
    void ordenarUy();
    void ordenarPuntuacion();
    Civilizacion* buscar(const Civilizacion &c);
    Civilizacion primerPosicion();
    Civilizacion UltimaPosicion();
    void modificar(Civilizacion &c, const Civilizacion &cn);
    void modificarPorEleccion(Civilizacion &c, const Civilizacion &cn);

    friend Videogame& operator<<(Videogame &v, const Civilizacion &c){
        v.agregarCivilizacion(c);

        return v;
    }

    void respaldar(vector<Civilizacion>&civilizaciones);
    void respaldar();

    void recuperar(vector<Civilizacion>&civilizaciones);
    void recuperarTodo();

};




#endif