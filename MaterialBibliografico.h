#pragma once
#include <iostream>
using namespace std;



class MaterialBibliografico{

    //atributos privados
    private:
        string nombre;
        string isbn;
        string autor;
        bool prestado;
    public:
        //constructor
        MaterialBibliografico(string nombre, 
        string isbn, string autor, bool prestado);

        // destructor
        ~MaterialBibliografico();

        // getters
        string getNombre();
        string getIsbn();
        string getAutor();
        bool getPrestado();

        //setters
        void setNombre(string titulo);
        void setIsbn(string isbn);
        void setAutor(string autor);
        void setPrestado(bool prestado);

        //toString
       virtual string mostrarInformacion();

};


