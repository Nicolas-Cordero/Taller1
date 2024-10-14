#include <iostream>
#include "Libro.h"

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

string Libro::getNombre(){
    return MaterialBibliografico::getNombre();
}

string Libro::getIsbn(){
    return MaterialBibliografico::getIsbn();
}

string Libro::getAutor(){
    return MaterialBibliografico::getAutor();
}

bool Libro::getPrestado(){
    return MaterialBibliografico::getPrestado();
}



//toString
string Libro::mostrarInformacion() {
    string textPrestado;
    if (getPrestado() == true){
        textPrestado = "Si";
    } else{
        textPrestado = "No";
    return getNombre() + "," + getIsbn() + "," + getAutor() + "," + 
    textPrestado + "," + getFechaPublicacion() + "," + getResumen();
}
};