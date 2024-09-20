#pragma once
#include <iostream>
#include "MaterialBibliografico.h"
using namespace std;


class Libro : public MaterialBibliografico{
    private:
        string fechaPublicacion;
        string resumen;
    public:
        //constructor
        Libro(string nombre,string isbn,string autor,bool prestado,string fechaPublicacion, string resumen);

        //destructor
        ~Libro();

        // getters
        string getFechaPublicacion();
        string getResumen();

        // setters
        void setFechaPublicacion(string fechaPublicacion);
        void setResumen(string resumen);

        //toString
        virtual void mostrarInformacion();


};