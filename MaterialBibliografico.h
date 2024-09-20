#pragma once
#include <iostream>
using namespace std;



class MaterialBibliografico{

    //atributos privados
    private:
        string titulo;
        string isbn;
        string autor;
        bool prestado;
    public:
        //constructor
        MaterialBibliografico(string titulo, 
        string isbn, string autor, bool prestado);

        // destructor
        ~MaterialBibliografico();

        // getters
        string getTitulo();
        string getIsbn();
        string getAutor();
        bool getPrestado();

        //setters
        void setTitulo(string titulo);
        void setIsbn(string isbn);
        void setAutor(string autor);
        void setPrestado(bool prestado);

        //toString
       virtual void mostrarInformacion();

};


