#include <iostream>
#include <thread>   // Para std::this_thread::sleep_for / es usado para temas netamente esteticos
#include <chrono>   // Para std::chrono::milliseconds / es usado para temas netamente esteticos
#include "Libro.h"
#include "revista.h" // Include the header file for Revista
#include "MaterialBibliografico.h" // Include the header file for MaterialBibliografico
#include "Usuario.h"


using namespace std;


// esta función tiene un rol netamente estético y no interfiere con los requerimientos del programa



int main(){
    //esto no se toca (recordatorio de: martina, para: martina)
    //biblioteca

    /// PARA DESPUES
    //MaterialBibliografico *biblioteca[100];
    //int cantActualEnBiblioteca = 0; 

    /*Crear menú con 4 opciones:
     1) Agregar material bibliografico a la biblioteca
     2) Mostrar información de los materiales bibliográficos
     3) Buscar Material Bibliografico
     4) Prestamo y devolución de Material

    */


    // bucle del sistema
    while (true){
        int x;
        cout << "Ingrese el valor de x";
        cin >> x;
        cout <<"El valor de X actualmente es -> "+to_string(x);
    }

    return 0;

};


    
