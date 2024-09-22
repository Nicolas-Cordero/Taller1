#include <iostream>
#include "Usuario.h"
using namespace std;

//constructor
Usuario::Usuario(string nombre,string id,int materialesPrestadosActuales){
    this -> nombre = nombre;
    this -> id = id;
    this -> materialesPrestadosActuales = materialesPrestadosActuales;
    for (int i = 0; i < 5; i++){
        materialesPrestados[i] = nullptr;
    }
}
//destructor
Usuario::~Usuario(){
    cout << "Se destruye el Usuario con ID: "+getId() << endl;
}
//getters
string Usuario:: getNombre(){
    return nombre;
}
string Usuario:: getId(){
    return id;
}
int Usuario :: getMaterialesPrestadosActuales(){
    return materialesPrestadosActuales;
}
//setters
void Usuario::setNombre(string nombre){
    this -> nombre = nombre;

}
void Usuario::setId(string id){
    this -> id = id;

}
void Usuario:: prestarMaterial(MaterialBibliografico *material,MaterialBibliografico *materialesBibliograficosGeneral,int tamanioListaGeneral){
    
    for(int i = 0;i < tamanioListaGeneral;i++){
        //verificar que se encuentre en la lista general de material bibliografico
        if(materialesBibliograficosGeneral[i].getIsbn() == material->getIsbn()){

           if(materialesPrestadosActuales < 5){
                materialesPrestados[materialesPrestadosActuales] = material; 
                materialesPrestadosActuales++;
                cout << "Material prestado, título: "+material->getTitulo() << endl;
            }
            else{
                cout << "(Error) Excede el límite de libros que un usuario puede tener."<< endl;
            }
        }
    }

}
void Usuario::devolverMaterial(int indice){
    if(indice >= 0 && indice < materialesPrestadosActuales){
        cout << "Material devuelto: "<<materialesPrestados[indice]->getTitulo() << endl;
        for(int i = indice; i < materialesPrestadosActuales-1;i++){
            materialesPrestados[i] = materialesPrestados[i+1];
        }
        materialesPrestados[materialesPrestadosActuales-1] = nullptr;
        materialesPrestadosActuales--;
    }else{
        cout << "Índice inválido."<< endl;
    }

}

void Usuario::mostrarMaterialesPrestados(){
    if(materialesPrestadosActuales == 0){
        cout <<"No hay materiales prestados para el usuario "+getNombre()+"."<<endl;
    }
    else{
        cout << "Materiales Bibliograficos Prestados: "<<endl;
        for(int j = 0;j < materialesPrestadosActuales;j++){
            cout <<j+1<<")"<<materialesPrestados[j]->getTitulo()<<endl;
        }

    }

}


