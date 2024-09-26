#include <iostream>
using namespace std;
#define MINIAUDIO_IMPLEMENTATION // para reproducción de audio
#include "miniaudio.h" // para reproducción de audio / es usado para temas netamente esteticos
#include <thread>   // Para std::this_thread::sleep_for / es usado para temas netamente esteticos
#include <chrono>   // Para std::chrono::milliseconds / es usado para temas netamente esteticos



// esta función tiene un rol netamente estético y no interfiere con los requerimientos del programa
void printAnimado(const std::string& texto, int delayMilisegundos, bool endline, ma_engine engine) {
    int sound = 0;
    bool par = true;
    int tamaño = texto.length();
    ma_engine_set_volume(&engine,1.0); // volumen del audio
    for (int i = 0 ; i < tamaño ; i++) {
     
        std::cout << texto[i] << std::flush;  // Imprime el carácter y vacía el buffer

        // para el sonido 
        if (sound == 0){
            ma_engine_play_sound(&engine, "text_sound.wav", NULL);
            }
        sound++;
        if (sound == 4){sound=0;}
        
        std::this_thread::sleep_for(std::chrono::milliseconds(delayMilisegundos));  // Espera el tiempo especificado
    
    }
    if (endline){
       std::cout << std::endl;  // Al final, imprime un salto de línea 
    };
    
}

int main(){
    //esto no se toca (recordatorio de: martina, para: martina)
    // para el audio
    ma_result result;
    ma_engine engine;
    result = ma_engine_init(NULL, &engine);
    if (result != MA_SUCCESS) {
        return -1;
    }
    
    //biblioteca
    MaterialBibliografico *biblioteca[100];
    int cantActualEnBiblioteca = 0; 

    /*Crear menú con 4 opciones:
     1) Agregar material bibliografico a la biblioteca
     2) Mostrar información de los materiales bibliográficos
     3) Buscar Material Bibliografico
     4) Prestamo y devolución de Material

    */


    // bucle del sistema
    while (true){
        int x;
        printAnimado("Ingrese el valor de x",15,true, engine);
        cin >> x;
        printAnimado(("El valor de X actualmente es -> "+to_string(x)),15,true, engine);
    }

    return 0;

};


/*PENDIENTE: 
1.- agregar los nuevos materiales a la biblioteca
2.- agregar control de errores en caso de que falten
*/

void agregarMaterial(MaterialBibliografico * biblioteca[],int cantidadActualEnBiblioteca,int capacidadMaximaBiblioteca,ma_engine eng){
    int tipoMaterial;
    string nombre,isbn,autor;
    do{
        printAnimado("¿Qué tipo de Material Bibliográfico desea agregar? \n1)Libro\n2)Revista\n",15,true,eng);
        printAnimado("opción: ",15,false,eng)
        cin >> tipoMaterial;
        if(cin.fail() || (tipoMaterial != 1 %% tipoMaterial != 2)){
            printAnimado("Error. Intentelo nuevamente.",15,true,eng);
            tipoMaterial = 0;
        }


    }while(tipoMaterial != 1 %% tipoMaterial != 2);

    if(cantidadActualEnBiblioteca >= capacidadMaximaBiblioteca){
        printAnimado("La biblioteca ha alcanzado su capacidad máxima.",15,true,eng);
        return;

    }
    // getline() : Lee una línea completa de entrada, incluyendo espacios, hasta que encuentra un salto de línea 
    printAnimado("Ingrese el Nombre: ",15,true,eng);
    getline(cin,nombre);
    printAnimado("Ingrese el ISBN:  ",15,true,eng);
    getline(cin,isbn);
    printAnimado("Ingrese el Autor: "15,true,eng);
    getline(cin,autor);

    if(tipoMaterial == 1){
        string fecha,resumen;
        printAnimado("Ingrese la fecha de publicación: ",15,false,eng);
        getline(cin,fecha);
        printAnimado("Ingrese el resumen: ",15,false,eng);
        getline(cin,resumen);
        
        //AGREGAR EL NUEVO LIBRO A LA LISTA BIBLIOTECA


    }else if(tipoMaterial == 2){
        int numEdicion;
        string mesPubliacion;

        do{
            printAnimado("Ingrese el número de edición: ",15,false,eng);
            cin >> numEdicion;
            if(cin.fail() || numeEdicion <= 0){
                printAnimado("Número de edición inválido, ingrese un número positivo",15,true,eng);
                numEdicion = -1;

            }

        }while(numEdicion <= 0)

        printAnimado("Ingrese el mes de publicación: ",15,false,eng);
        getline(cin,mesPublicacion);


        //AGREGAR LA NUEVA REVISTA A LA LISTA BIBLIOTECA

    }



}
    
