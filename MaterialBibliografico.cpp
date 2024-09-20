#include <iostream>
#include "MaterialBibliografico.h"
using namespace std;

//constructor
MaterialBibliografico::MaterialBibliografico(string titulo, 
        string isbn, string autor, bool prestado)
        {this -> titulo = titulo;this -> isbn = isbn;
        this -> autor = autor; this -> prestado = prestado;}

// destructor
MaterialBibliografico::~MaterialBibliografico(){
    cout<<"Se destruye el Material Bibliografico con ISBN"+isbn;}
//getters
string MaterialBibliografico::getTitulo(){
    return titulo;
}
string MaterialBibliografico::getIsbn(){
    return isbn;
}
string MaterialBibliografico::getAutor(){
    return autor;
}
bool MaterialBibliografico::getPrestado(){
    return prestado;
}

//setters
void MaterialBibliografico::setTitulo(string titulo){
    this -> titulo = titulo;
}
void MaterialBibliografico::setIsbn(string isbn){
    this -> isbn = isbn;
}
void MaterialBibliografico::setAutor(string autor){
    this -> autor = autor;
}
void MaterialBibliografico::setPrestado(bool prestado ){
    this -> prestado  = prestado;
}
//toSrtring
void MaterialBibliografico::mostrarInformacion(){
    cout << "Nombre: "+titulo+" ISBN: "+isbn+" Autor: "+autor;
}