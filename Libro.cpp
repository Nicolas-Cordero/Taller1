#include "Libro.h"
#include <iostream>
using namespace std;

//constructor
Libro::Libro(string nombre,string isbn,string autor,bool prestado,string fechaPublicacion,string resumen):MaterialBibliografico(nombre,isbn,autor,prestado){
    this -> fechaPublicacion = fechaPublicacion;
    this -> resumen = resumen;
}

//destructor
Libro::~Libro(){cout << "Se destruye el Libro con isbn "+getIsbn()+" y fecha de publicacion "+fechaPublicacion<<endl;}

// getters
string Libro:: getFechaPublicacion(){
    return fechaPublicacion;

}
string Libro::getResumen(){
    return resumen;

}

// setters
void Libro::setFechaPublicacion(string fechaPublicacion){
    this -> fechaPublicacion = fechaPublicacion;

}
void Libro::setResumen(string resumen){
    this -> resumen  = resumen;

}

//toString
void Libro::mostrarInformacion(){
    cout << "Fecha de Publicacion: "+fechaPublicacion+" Resumen: "+resumen << endl;

}
