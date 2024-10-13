#include <iostream>
#include "Revista.h"
using namespace std;

// Constructor
Revista::Revista(string nombre, string isbn, string autor, 
    bool prestado, int numeroEdicion, string mesPublicacion)
    :MaterialBibliografico(nombre, isbn, autor, prestado) {
    this -> numeroEdicion = numeroEdicion;
    this -> mesPublicacion = mesPublicacion;
}

// Destructor
Revista::~Revista() {
    cout<<"Se destruye la revista con ISBN"+getIsbn();
    }


// Getters
string Revista::getNombre() {
    return MaterialBibliografico::getTitulo();
}
string Revista::getIsbn() {
    return MaterialBibliografico::getIsbn();
}
string Revista::getAutor() {
    return MaterialBibliografico::getAutor();
}
bool Revista::getPrestado() {
    return MaterialBibliografico::getPrestado();
}
string Revista::getNumeroEdicion() {
    return numeroEdicion;
}
string Revista::getMesPublicacion() {
    return mesPublicacion;
}

// Setters
void Revista::setNombre(string nombre) {
    MaterialBibliografico::setTitulo(nombre);
}
void Revista::setIsbn(string isbn) {
    MaterialBibliografico::setIsbn(isbn);
}
void Revista::setAutor(string autor) {
    MaterialBibliografico::setAutor(autor);
}
void Revista::setPrestado(bool prestado) {
    MaterialBibliografico::setPrestado(prestado);
}
void Revista::setNumeroEdicion(string numeroEdicion) {
    this->numeroEdicion = numeroEdicion;
}

void Revista::setMesPublicacion(string mesPublicacion) {
    this->mesPublicacion = mesPublicacion;
}

// toString
void Revista::mostrarInformacion() {
    string textPrestado;
    if (getPrestado() == true){
        textPrestado = "Si";
    } else{
        textPrestado = "No";
    cout << "Nombre: " << getNombre()+" ISBN: " + getIsbn()+" Autor: " + getAutor()+ "Prestado: " + 
    textPrestado+ "Número de edición: " + getNumeroEdicion()+"Mes de publicación: " + getMesPublicacion() << endl;
};
