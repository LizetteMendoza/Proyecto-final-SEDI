#include<iostream>
#include<algorithm>
#include<fstream>
#include"videogame.h"
#include<iomanip>

Civilizacion cn;
Videogame::Videogame(const string &usuario){
    this-> usuario= usuario;
}

void Videogame::setUsuario(const string&v){
    usuario=v;
}
string Videogame::getUsuario(){
    return usuario;
}

Videogame::Videogame(){}
void Videogame::agregarCivilizacion(const Civilizacion&c){
    civilizaciones.push_back(c);
}

void Videogame::mostrar(){

    cout<<left;
        cout<<setw(10)<<"Nombre";
        cout<<setw(15)<<"Posicion en X";
        cout<<setw(15)<<"Posicion en Y";
        cout<<setw(10)<<"Puntuacion";
        cout<<endl;

    for (size_t i = 0; i < civilizaciones.size(); i++)
    {
        Civilizacion &c = civilizaciones[i];
        cout<< c;
    }
    
}

void Videogame::insertar(const Civilizacion &c, size_t pos){
    civilizaciones.insert(civilizaciones.begin()+pos, c);
}

size_t Videogame::size(){
    return civilizaciones.size();
}

void Videogame::inicializar(const Civilizacion&c, size_t n){
    civilizaciones = vector<Civilizacion>(n,c);
}

void Videogame::eliminar(Civilizacion&c){
    auto it = find(civilizaciones.begin(),civilizaciones.end(),c);
    civilizaciones.erase(it);
}

void Videogame::ordenar(){
    sort(civilizaciones.begin(),civilizaciones.end());
}


void Videogame::ordenarNombre(){
    sort(civilizaciones.begin(),civilizaciones.end(),[]( Civilizacion c1, Civilizacion c2){return c1.getNombre()<c2.getNombre();});
}
void Videogame::ordenarUx(){
    sort(civilizaciones.begin(),civilizaciones.end(),[](Civilizacion c1, Civilizacion c2){return c1.getUbicacionX()<c2.getUbicacionX();});
}
void Videogame::ordenarUy(){
    sort(civilizaciones.begin(),civilizaciones.end(),[]( Civilizacion c1, Civilizacion c2){return c1.getUbicacionY()<c2.getUbicacionY();});
}

void Videogame::ordenarPuntuacion(){
    sort(civilizaciones.begin(),civilizaciones.end(),[]( Civilizacion c1, Civilizacion c2){return c1.getPuntuacion()>c2.getPuntuacion();});
}

Civilizacion* Videogame::buscar(const Civilizacion &c){
   auto it = find(civilizaciones.begin(),civilizaciones.end(),c);

   if(it==civilizaciones.end()){
       return nullptr;
   }
   else{
       return &(*it);
   }
}

Civilizacion Videogame::primerPosicion(){

    return civilizaciones.front(); 
}

Civilizacion Videogame::UltimaPosicion(){
    return civilizaciones.back(); 
}

void Videogame::modificar(Civilizacion &c, const Civilizacion &cn){

    auto it = find(civilizaciones.begin(),civilizaciones.end(),c);

    civilizaciones.insert(it,cn);

}

/*void Videogame::modificarPorEleccion(Civilizacion &c,  const Civilizacion &cn){
    auto it = find(civilizaciones.begin(),civilizaciones.end(),c);
    string nombre;
    cout<<"nombre";
    getline(cin,nombre);
}*/

void Videogame::respaldar(vector<Civilizacion>&civilizaciones){
     ofstream archivo("Civilizaciones.txt");
     if(archivo.is_open()){
         for (size_t i = 0; i < civilizaciones.size(); i++)
         {
             Civilizacion &c= civilizaciones[i];
             archivo<<c.getNombre()<<endl;
             c.respaldar_aldeanos();
         }
         archivo.close();
     }
}
void Videogame::respaldar(){
    respaldar(civilizaciones);
}


void Videogame::recuperar(vector<Civilizacion>&civilizaciones){
    ifstream archivo("Civilizaciones.txt");
    if(archivo.is_open()){
        string  temp;

        
        while (true)
        {
            Civilizacion c;
            getline(archivo,temp);
            if(archivo.eof()){
                break;
            }
            c.setNombre(temp);
        
            cout<<c.getNombre()<<endl;
            

            ifstream archivo(c.getNombre()+".txt");
            if(archivo.is_open()){
                    string temp;
                    size_t edad;
                    float salud;
                    Aldeano a;

                    cout<<left;
                    cout<<setw(10)<<"Nombre";
                    cout<<setw(8)<<"Edad";
                    cout<<setw(8)<<"Genero";
                    cout<<setw(10)<<"Salud";
                    cout<<endl;
                    
                    while(true){
                        getline(archivo,temp);
                        if(archivo.eof()){
                            break;
                        }
                        a.setNombre(temp);

                        getline(archivo,temp);
                        edad=stoi(temp);
                        a.setEdad(edad);
                        
                        getline(archivo,temp);
                        a.setGenero(temp);

                        getline(archivo,temp);
                        salud=stof(temp);
                        a.setSalud(salud);
                        
                        c.agregarInicio(a);
                        
                        cout<<a;
                        cout<<endl;
                    }
                    agregarCivilizacion(c);  
                }  
               cout<<endl; 
            }
            
        }
    archivo.close();
}

void Videogame::recuperarTodo(){
    recuperar(civilizaciones);
}


