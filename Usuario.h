#pragma once
#include <iostream>
#include "MaterialBibliografico.h"
using namespace std;

class Usuario{
    private:
        //atributos
        string nombre;
        string id;
        MaterialBibliografico *materialesPrestados[5];
        int materialesPrestadosActuales;
    public:
        //constructor
        Usuario(string nombre,string id,int materialesPrestadosActuales);
        //destructor
        ~Usuario();
        //getters
        string getNombre();
        string getId();
        int getMaterialesPrestadosActuales();
        //setters
        void setNombre(string nombre);
        void setId(string id);

        void prestarMaterial(MaterialBibliografico * material,MaterialBibliografico *materialesBibliograficosGeneral,int tamanioListaGeneral);
        void devolverMaterial(int indice);
        void mostrarMaterialesPrestados();


};