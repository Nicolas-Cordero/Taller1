#include <iostream>
#include "revista.h"
using namespace std;

// Constructor
revista::revista(string nombre, string isbn, string autor, 
    bool prestado, int numeroEdicion, string mesPublicacion)
    :MaterialBibliografico(nombre, isbn, autor, prestado) {
    this -> numeroEdicion = numeroEdicion;
    this -> mesPublicacion = mesPublicacion;
}

// Destructor
revista::~revista() {
    cout<<"Se destruye la revista con ISBN"+getIsbn();
    }


// Getters
string revista::getNombre() {
    return MaterialBibliografico::getTitulo();
}
string revista::getIsbn() {
    return MaterialBibliografico::getIsbn();
}
string revista::getAutor() {
    return MaterialBibliografico::getAutor();
}
bool revista::getPrestado() {
    return MaterialBibliografico::getPrestado();
}
string revista::getNumeroEdicion() {
    return numeroEdicion;
}
string revista::getMesPublicacion() {
    return mesPublicacion;
}

// Setters
void revista::setNombre(string nombre) {
    MaterialBibliografico::setTitulo(nombre);
}
void revista::setIsbn(string isbn) {
    MaterialBibliografico::setIsbn(isbn);
}
void revista::setAutor(string autor) {
    MaterialBibliografico::setAutor(autor);
}
void revista::setPrestado(bool prestado) {
    MaterialBibliografico::setPrestado(prestado);
}
void revista::setNumeroEdicion(string numeroEdicion) {
    this->numeroEdicion = numeroEdicion;
}

void revista::setMesPublicacion(string mesPublicacion) {
    this->mesPublicacion = mesPublicacion;
}

// toString
void revista::mostrarInformacion() {
    string textPrestado;
    if (getPrestado() == true){
        textPrestado = "Si";
    } else{
        textPrestado = "No";
    cout << "Nombre: " << getNombre()+" ISBN: " + getIsbn()+" Autor: " + getAutor()+ "Prestado: " + 
    textPrestado+ "Número de edición: " + getNumeroEdicion()+"Mes de publicación: " + getMesPublicacion() << endl;
};
