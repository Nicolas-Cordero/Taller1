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

    // para el audio
    ma_result result;
    ma_engine engine;
    result = ma_engine_init(NULL, &engine);
    if (result != MA_SUCCESS) {
        return -1;
    }
    
    // bucle del sistema
    while (true){
        int x;
        printAnimado("Ingrese el valor de x",15,true, engine);
        cin >> x;
        printAnimado(("El valor de X actualmente es -> "+to_string(x)),15,true, engine);
    }

    return 0;

};
    
