#include <iostream>
#include <thread>   // Para std::this_thread::sleep_for / es usado para temas netamente esteticos
#include <chrono>   // Para std::chrono::milliseconds / es usado para temas netamente esteticos
#include "Libro.h"
#include "revista.h" // Include the header file for Revista
#include "MaterialBibliografico.h" // Include the header file for MaterialBibliografico
#include "Usuario.h"


using namespace std;


// esta función tiene un rol netamente estético y no interfiere con los requerimientos del programa
void printAnimado(const std::string& texto, int delayMilisegundos, bool endline) {
    int tamaño = texto.length();
    for (int i = 0 ; i < tamaño ; i++) {
     
        std::cout << texto[i] << std::flush;  // Imprime el carácter y vacía el buffer

        
        std::this_thread::sleep_for(std::chrono::milliseconds(delayMilisegundos));  // Espera el tiempo especificado
    
    }
    if (endline){
       std::cout << std::endl;  // Al final, imprime un salto de línea 
    };
    
}

// Forward declaration of printAnimado
void printAnimado(const std::string& texto, int delayMilisegundos, bool endline);

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
        printAnimado("Ingrese el valor de x",15,true);
        cin >> x;
        printAnimado(("El valor de X actualmente es -> "+to_string(x)),15,true);
    }

    return 0;

};

void agregarMaterial(MaterialBibliografico * biblioteca[],int cantidadActualEnBiblioteca,int capacidadMaximaBiblioteca){
    int tipoMaterial;
    string nombre,isbn,autor;
    do{
        printAnimado("¿Qué tipo de Material Bibliográfico desea agregar? \n1)Libro\n2)Revista\n",15,true);
        printAnimado("opción: ",15,false);
        cin >> tipoMaterial;
        if(cin.fail() || (tipoMaterial != 1 && tipoMaterial != 2)){
            printAnimado("Error. Intentelo nuevamente.",15,true);
            tipoMaterial = 0;
        }


    }while(tipoMaterial != 1 && tipoMaterial != 2);

    if(cantidadActualEnBiblioteca >= capacidadMaximaBiblioteca){
        printAnimado("La biblioteca ha alcanzado su capacidad máxima.",15,true);
        return;

    }
    // getline() : Lee una línea completa de entrada, incluyendo espacios, hasta que encuentra un salto de línea 
    printAnimado("Ingrese el Nombre: ",15,true);
    getline(cin,nombre);
    printAnimado("Ingrese el ISBN:  ",15,true);
    getline(cin,isbn);
    printAnimado("Ingrese el Autor: ",15,true);
    getline(cin,autor);

    if(tipoMaterial == 1){
        bool prestado =true;
        string fecha,resumen;
        printAnimado("Ingrese la fecha de publicación: ",15,false);
        getline(cin,fecha);
        printAnimado("Ingrese el resumen: ",15,false);
        getline(cin,resumen);
        
        //AGREGAR EL NUEVO LIBRO A LA LISTA BIBLIOTECA
        MaterialBibliografico *nuevoMaterial = new Libro(nombre,isbn,autor,prestado,fecha,resumen);
        biblioteca[cantidadActualEnBiblioteca] = nuevoMaterial;
        cantidadActualEnBiblioteca++;


    }else if(tipoMaterial == 2){
        bool prestado = true;
        int numEdicion;
        string mesPublicacion;

        do{
            printAnimado("Ingrese el número de edición: ",15,false);
            cin >> numEdicion;
            if(cin.fail() || numEdicion <= 0){
                printAnimado("Número de edición inválido, ingrese un número positivo",15,true);
                numEdicion = -1;

            }

        }while(numEdicion <= 0);

        printAnimado("Ingrese el mes de publicación: ",15,false);
        getline(cin,mesPublicacion);


        //AGREGAR LA NUEVA REVISTA A LA LISTA BIBLIOTECA
        MaterialBibliografico *nuevoMaterial = new revista(nombre,isbn,autor,prestado,numEdicion,mesPublicacion);
        biblioteca[cantidadActualEnBiblioteca] = nuevoMaterial;
        cantidadActualEnBiblioteca++;

    }



}
    
