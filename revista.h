#pragma once
#include <iostream>
#include "MaterialBibliografico.h"
using namespace std;


class Revista: public MaterialBibliografico{
    private:
        string numeroEdicion;
        string mesPublicacion;
    public:
        //constructor
        Revista(string nombre, string isbn, 
        string autor, bool prestado, 
        int numeroEdicion, string mesPublicacion);

        // destructor}
        ~Revista();

        //getters
        // getters
        string getNombre();
        string getIsbn();
        string getAutor();
        bool getPrestado();
        string getNumeroEdicion();
        string getMesPublicacion();

        //setters
        void setNombre(string nombre);
        void setIsbn(string isbn);
        void setAutor(string autor);
        void setPrestado(bool prestado);
        void setNumeroEdicion(string numeroEdicion);
        void setMesPublicacion(string mesPublicacion);

        //toString
         virtual void mostrarInformacion();
};
