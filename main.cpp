#include<iostream>
#include"videogame.h"

using namespace std;

int main(){

    Videogame v;
    string opc,op;
    vector<Civilizacion>civilizaciones;

    while(true){
        cout<<endl<<"1.-Nombre de usuario"<<endl;
        cout<<"2.-Agregar Civilizacion "<<endl;
        cout<<"3.-Insertar "<<endl;
        cout<<"4.-Inicializar "<<endl;
        cout<<"5.-Primer posicion"<<endl;
        cout<<"6.-Utima posicion"<<endl;
        cout<<"8.-Eliminar "<<endl;
        cout<<"7.-Ordenar "<<endl;
        cout<<"9.-Buscar"<<endl;
        cout<<"10.-Modificar"<<endl;
        cout<<"11.-Resumen "<<endl;
        cout<<"12.-Buscar civilizacion"<<endl;
        cout<<"13.-Respaldar"<<endl;
        cout<<"14.-Recuperar"<<endl;
        cout<<"0.-Salir "<<endl<<endl;
        cin>>opc; cin.ignore();

        if(opc=="1"){
            string usuario;
            cout<<"Ingrese nombre de usuario: ";
            getline(cin,usuario);
            v.setUsuario(usuario);
            cout<<v.getUsuario();
        }
        else if(opc=="2"){
            Civilizacion c;
            cin>> c; cin.ignore();

            v.agregarCivilizacion(c);
        }
        else if(opc=="3"){

            Civilizacion c;
            cin>> c; cin.ignore();
            cout<<"Posicion: ";
            size_t p;
            cin>>p; cin.ignore();
            if(p>=v.size()){
                cout<<"Posicion no valida"<<endl;
            }
            else{
                v.insertar(c,p);
            }
        }
        else if(opc=="4"){
            Civilizacion c;
            cin>> c; cin.ignore();

            size_t n;
            cout<<"n: ";
            cin>>n; cin.ignore();

            v.inicializar(c,n);

        }
        else if(opc=="5"){
            if(v.size()<1){
                cout<<"No hay civilizaciones"<<endl;
            }
            else{
                cout<<v.primerPosicion();
            }
            
        }
         else if(opc=="6"){
           if(v.size()<1){
                cout<<"No hay civilizaciones"<<endl;
            }
            else{
                cout<<v.UltimaPosicion();
           }

        }
        else if(opc=="7"){

            while (true)
            {
                cout<<"1.-Ordenar por Nombre"<<endl;
                cout<<"2.-Ordenar por Ubicacion en x"<<endl;
                cout<<"3.-Ordenar por Ubicacion en y"<<endl;
                cout<<"4.-Ordenar por Puntuacion"<<endl;
                cout<<"0.-Regresar al menu principal"<<endl;
                cin>>opc; cin.ignore();

                if(opc=="1"){
                    v.ordenar();
                    v.mostrar();
                }
                else if(opc=="2"){
                    v.ordenarUx();
                    v.mostrar();
                }
                else if(opc=="3"){
                    v.ordenarUy();
                    v.mostrar();
                }
                else if(opc=="4"){
                    v.ordenarPuntuacion();
                    v.mostrar();
                }
                else if(opc=="0"){
                    break;
                }
            }
        }
        else if(opc=="8"){

            Civilizacion c;
            string nombre;
            cout<<"Ingrese el nombre: ";
            getline(cin,nombre);
            c.setNombre(nombre);

            Civilizacion *ptr = v.buscar(c);
            if(ptr==nullptr){
                cout<<"No encontrado"<<endl;
            }
            else{
                v.eliminar(*ptr);
            }

        }
        else if(opc=="9"){
            Civilizacion c;
            string nombre;
            cout<<"Ingrese el nombre: ";
            getline(cin,nombre);
            c.setNombre(nombre);
            
            Civilizacion *ptr = v.buscar(c);
            if(ptr==nullptr){
                cout<<"No encontrado"<<endl;
            }
            else{
                cout<<*ptr<<endl;
            }
        }
         else if(opc=="10"){
            Civilizacion c;
            string nombre;
            cout<<"Ingrese el nombre: ";
            getline(cin,nombre);
            c.setNombre(nombre);

            Civilizacion *ptr = v.buscar(c);
            if(ptr==nullptr){
                cout<<"No encontrado"<<endl;
            }
            else{
                cout<<*ptr<<endl<<endl;
                do{
                    cout<<"Que desea editar?"<<endl;
                    cout<<"1.-Nombre"<<endl;
                    cout<<"2.-Posicion en x"<<endl;
                    cout<<"3.-Posicion en y"<<endl;
                    cout<<"4.-Puntuacion"<<endl;
                    cout<<"0.-Salir"<<endl;
                    cin>>opc; cin.ignore();
                    if(opc=="1"){
                        cout<<"Nombre: ";
                        string aux;
                        getline(cin,aux);
                        ptr->setNombre(aux);
                        cout<<*ptr<<endl<<endl;
                    }
                    else if(opc=="2"){
                        cout<<"Posicion en X: ";
                        float aux;
                        cin>>aux;
                        ptr->setUbicacionX(aux);
                        cout<<*ptr<<endl<<endl;
                    }
                    else if(opc=="3"){
                        cout<<"Posicion en Y:";
                        float aux;
                        cin>>aux;
                        ptr->setUbicacionY(aux);
                        cout<<*ptr<<endl<<endl;
                    }
                    else if(opc=="4"){
                        cout<<"Puntuacion: ";
                        float aux;
                        cin>>aux;
                        ptr->setPuntuacion(aux);
                        cout<<*ptr<<endl<<endl;
                    }
                    else if(opc=="0"){
                        break;
                    };
                }while(true);   
            }
        }
         else if(opc=="11"){
            cout<<endl<<"Usuario: ";
            cout<<v.getUsuario()<<endl;
            v.mostrar();

        }
        else if(opc=="12"){
            
            Civilizacion c;
            string nombre;
            cout<<"Ingrese el nombre: ";
            getline(cin,nombre);
            c.setNombre(nombre);
            
            Civilizacion *ptr = v.buscar(c);
            if(ptr==nullptr){
                cout<<"No encontrado"<<endl;
            }
            else{
                while(true){
                    cout<<endl;
                    cout<<"1.-Agregar aldeano"<<endl;
                    cout<<"2.-Eliminar aldeano"<<endl;
                    cout<<"3.-Clasificar aldeanos"<<endl;
                    cout<<"4.-Buscar aldeano"<<endl;
                    cout<<"5.-Modificar aldeano"<<endl;
                    cout<<"6.-Mostrar aldeanos"<<endl;
                    cout<<"0.-Salir"<<endl;
                    cin>>op; cin.ignore();
                
                    if(op=="1"){
                        Aldeano a;
                        float aux;
                        cin>>a; cin.ignore();
                        cout<<"1.-Agregar al inicio"<<endl;
                        cout<<"2.-Agregar al final"<<endl;
                        cin>>op; cin.ignore();
                        if(op=="1"){
                            ptr->agregarInicio(a);
                            aux=ptr->getPuntuacion();
                            aux=aux+100;
                            ptr->setPuntuacion(aux);
                        }
                        else if(op=="2"){
                            ptr->agregarFinal(a);
                        aux=ptr->getPuntuacion();
                        aux=aux+100;
                        ptr->setPuntuacion(aux);
                        } 
                    }
                    else if(op=="2"){
                        while(true){
                                cout<<endl;
                                cout<<"1.-Eliminar por nombre"<<endl;
                                cout<<"2.-Eliminar por edad"<<endl;
                                cout<<"3.-Eliminar por Salud ingresada"<<endl;
                                cout<<"0.-Salir"<<endl;
                                cin>>op; cin.ignore();
                            if(op=="1"){
                                cout<<"Ingrese el nombre del aldeano a eliminar: ";
                                string nombre;
                                getline(cin,nombre);
                                ptr->eliminarNombre(nombre);
                            }
                            else if(op=="2"){
                                ptr->eliminarEdad();
                            }
                            else if(op=="3"){
                                size_t edad;
                                cout<<"Ingrese la salud: ";
                                cin>>edad; cin.ignore();
                                ptr->eliminarEdad(edad);
                            }
                            else if(op=="0"){
                                break;
                            }
                        } 
                    }
                    else if(op=="3"){
                        cout<<endl;
                        cout<<"1.-Nombre"<<endl;
                        cout<<"2.-Edad"<<endl;
                        cout<<"3.-Salud"<<endl;
                        cin>>op; cin.ignore();
                        if(op=="1"){
                            ptr->ordenarNombre();
                        }
                        else if(op=="2"){
                            ptr->ordenarEdad();
                        }
                        else if(op=="3"){
                            ptr->ordenarSalud();
                        }
                    }
                    else if(op=="4"){
                        cout<<"Nombre: ";
                        string nombre;
                        getline(cin,nombre);
                        Aldeano a;
                        a.setNombre(nombre);

                        Aldeano *ptra = ptr->buscar(a);

                        if(ptra==nullptr){
                         cout<<"No encontrado"<<endl;
                         }
                        else{
                            cout<<*ptra<<endl;
                        }
                    }
                    else if(op=="5"){
                        cout<<"Nombre: ";
                        string nombre;
                        getline(cin,nombre);
                        Aldeano a;
                        a.setNombre(nombre);

                        Aldeano *ptra = ptr->buscar(a);

                        if(ptra==nullptr){
                         cout<<"No encontrado"<<endl;
                         }
                        else{
                            cout<<*ptra<<endl;
                            cout<<"Que desea modificar"<<endl;
                            cout<<"1.-Nombre"<<endl;
                            cout<<"2.-Edad"<<endl;
                            cout<<"3.-Genero"<<endl;
                            cout<<"4.-Salud"<<endl;
                            cin>>op; cin.ignore();
                            if(op=="1"){
                                string aux;
                                cout<<"Nombre: ";
                                getline(cin,aux);
                                ptra->setNombre(aux);
                            }
                            else if(op=="2"){
                                size_t aux;
                                cout<<"Edad: ";
                                cin>>aux; cin.ignore();
                                ptra->setEdad(aux);
                            }
                            else if(op=="3"){
                                string aux;
                                cout<<"Genero: ";
                                getline(cin,aux);
                                ptra->setGenero(aux);
                            }
                            else if(op=="4"){
                                float aux;
                                cout<<"Salud: ";
                                cin>>aux; cin.ignore();
                                ptra->setSalud(aux);
                            }
                        }
                        
                    } 
                    else if(op=="6"){
                        ptr->print();
                    }
                    else if(op=="0"){
                        break;
                    }
                }

                
            }
        }
        else if(opc=="13"){
            v.respaldar();
        }
        else if(opc=="14"){
        
            v.recuperarTodo();
        }
        else if(opc=="0"){
            break;
        }
    }

    return 0; 
}