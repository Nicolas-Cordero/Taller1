#include <iostream>
#include <sstream>
#include <fstream>
#include "Libro.h"
#include "Revista.h" // 
#include "MaterialBibliografico.h" // 
#include "Usuario.h"

#include "Libro.cpp"
#include "Revista.cpp" // 
#include "MaterialBibliografico.cpp" //
#include "Usuario.cpp"


using namespace std;

bool stringSonIguales(const string& cadena1, const string& cadena2) {
    return cadena1 == cadena2;
}


void imprimirBiblioteca(MaterialBibliografico* biblioteca [100], int contadorBiblioteca){
    int i = 0;
    while (biblioteca[i] != nullptr)
    {
        cout << to_string(i+1) << ") " << ") Nombre: " << biblioteca[i]->getNombre() << " - ISBN: " << biblioteca[i]->getIsbn() << endl;
        i++;
    }
}

void imprimirTodosLosUsuarios(Usuario* vectorUsuarios[100]){
    int i = 0;
    while (vectorUsuarios[i] != nullptr)
    {
        cout << to_string(i+1) << ") " << ") Nombre: " << vectorUsuarios[i]->getNombre() << " - ID: " << vectorUsuarios[i]->getId() << endl;
        i++;
    }
}

void crearUsuario(Usuario* vectorUsuarios[100], int contadorUsuarios){
    if (contadorUsuarios >= 100){
        cout << "No hay espacio en la base de datos de usuarios" << endl;
    }
    else{

        cout << "Ingrese el nombre del usuario: ";
        string nombre;
        cin >> nombre;
        cout << "Ingrese el ID del usuario: ";
        string id;
        cin >> id;
        Usuario* nuevoUsuario = new Usuario(nombre, id, 0); 
        vectorUsuarios[contadorUsuarios] = nuevoUsuario;
        contadorUsuarios++;
    }
}

bool buscarUsuarioPorNombre(Usuario* vectorUsuarios[100], int contadorUsuarios) {
    string nombreBuscado;
    cout << "Ingrese el nombre del usuario a buscar: ";
    cin >> nombreBuscado;   
    cout <<"Buscando usuario..."<< nombreBuscado << endl;   
    for (int i = 0; i < contadorUsuarios; i++) {


        if (stringSonIguales(vectorUsuarios[i]->getNombre(), nombreBuscado)) {
            cout << "Usuario encontrado: " << endl;
            cout << "NOMBRE: " << vectorUsuarios[i]->getNombre() << endl;
            cout << "ID: " << vectorUsuarios[i]->getId() << endl;
            cout << "Materiales prestados: " << vectorUsuarios[i]->getMaterialesPrestadosActuales() << endl;
            return true;
        }
        else{
            cout << "Usuario no encontrado." << endl;
            return false;
        }
    }
   
}



bool eliminarUsuarioPorNombre(Usuario* vectorUsuarios[100], int contadorUsuarios){
    string nombreBuscado;
    cout << "Ingrese el nombre del usuario a buscar: ";
    cin >> nombreBuscado;
    for (int i = 0; i < contadorUsuarios; i++){
        if (vectorUsuarios[i]->getNombre() == nombreBuscado){
            cout << "Usuario encontrado: " << "NOMBRE: " << vectorUsuarios[i]->getNombre();
            vectorUsuarios[i]->~Usuario();
            vectorUsuarios[i] = nullptr;
            cout << "--*USUARIO ELIMINADO*-";
            cout << endl;
            contadorUsuarios--;
            return true;
        }
    }
    cout << "Usuario no encontrado" << endl;
    return false;
}



void mostrarInformacionLibros(string nombreTxt,  MaterialBibliografico* biblioteca[100], int contadorBiblioteca){
    
    fstream myFile;
    myFile.open(nombreTxt, ios::in); // LEER
    
    if (myFile.is_open()){
        string line;
        int i = 0;
        while (getline(myFile, line)){
            // Cadena de ejemplo
            string datos = line;
            
            // Variables para almacenar los valores separados
            int parte6_int;
            string parte6_str;
            string parte1, parte2, parte3, parte4,parte7;
            bool parte5;
            if (parte1 == "revista"){
                int parte6;
            }
            else{
                string parte6;
            }
            
            // Usamos un stringstream para procesar la cadena
            stringstream ss(line);
            string temp;

            getline(ss, parte1, ',');
            getline(ss, parte2, ',');
            getline(ss, parte3, ',');
            getline(ss, parte4, ',');

            // Extraer el quinto dato y convertirlo a bool
            getline(ss, temp, ',');
            parte5 = (temp == "true");

            // Extraer el sexto dato, puede ser entero o string según la parte 1
            getline(ss, temp, ',');
            if (parte1 == "revista") {
                parte6_int = stoi(temp); // Convertir a entero si es "libro"
            } else  {
                parte6_str = temp; // Mantener como string si es "revista"
            }

            getline(ss, parte7, ',');

            if (parte1 == "libro"){
                // Es un libro
                Libro* nuevoLibro = new Libro(parte2, parte3, parte4, parte5, parte6_str, parte7);
                cout << "Libro N°" << i+1 << ") "<< nuevoLibro->mostrarInformacion() << endl;
            }
    
            i++;
        }
        myFile.close();
    } 
    
}

void mostrarInformacionRevistas(string nombreTxt,  MaterialBibliografico* biblioteca[100], int contadorBiblioteca){
    
    fstream myFile;
    myFile.open(nombreTxt, ios::in); // LEER
    
    if (myFile.is_open()){
        string line;
        int i = 0;
        while (getline(myFile, line)){
            // Cadena de ejemplo
            string datos = line;
            
            // Variables para almacenar los valores separados
            int parte6_int;
            string parte6_str;
            string parte1, parte2, parte3, parte4,parte7;
            bool parte5;
            if (parte1 == "revista"){
                int parte6;
            }
            else{
                string parte6;
            }
            
            // Usamos un stringstream para procesar la cadena
            stringstream ss(line);
            string temp;

            getline(ss, parte1, ',');
            getline(ss, parte2, ',');
            getline(ss, parte3, ',');
            getline(ss, parte4, ',');

            // Extraer el quinto dato y convertirlo a bool
            getline(ss, temp, ',');
            parte5 = (temp == "true");

            // Extraer el sexto dato, puede ser entero o string según la parte 1
            getline(ss, temp, ',');
            if (parte1 == "revista") {
                parte6_int = stoi(temp); // Convertir a entero si es "libro"
            } else  {
                parte6_str = temp; // Mantener como string si es "revista"
            }

            getline(ss, parte7, ',');

            if (parte1 == "revista"){
                // Es un libro
                Revista* nuevaRevista = new Revista(parte2, parte3, parte4, parte5, parte6_int, parte7);
                cout << "Revista N°" << i+1 << ") "<< nuevaRevista->mostrarInformacion() << endl;
            }
    
            i++;
        }
        myFile.close();
    } 
    
}

void prestamoDevolucion(MaterialBibliografico* biblioteca [100], int contadorBiblioteca){
    imprimirBiblioteca(biblioteca, contadorBiblioteca);

}

void leerBibliotecaTxt(string nombreTxt,  MaterialBibliografico* biblioteca[100], int contadorBiblioteca){
    fstream myFile;
    myFile.open(nombreTxt, ios::in); // LEER
    if (myFile.is_open()){
        string line;
        while (getline(myFile, line)){
            // Cadena de ejemplo
            string datos = line;
            
            // Variables para almacenar los valores separados
            int parte6_int;
            string parte6_str;
            string parte1, parte2, parte3, parte4,parte7;
            bool parte5;
            if (parte1 == "revista"){
                int parte6;
            }
            else{
                string parte6;
            }
            
            // Usamos un stringstream para procesar la cadena
            stringstream ss(line);
            string temp;

            getline(ss, parte1, ',');
            getline(ss, parte2, ',');
            getline(ss, parte3, ',');
            getline(ss, parte4, ',');

            // Extraer el quinto dato y convertirlo a bool
            getline(ss, temp, ',');
            parte5 = (temp == "true");

            // Extraer el sexto dato, puede ser entero o string según la parte 1
            getline(ss, temp, ',');
            if (parte1 == "revista") {
                parte6_int = stoi(temp); // Convertir a entero si es "libro"
            } else  {
                parte6_str = temp; // Mantener como string si es "revista"
            }

            getline(ss, parte7, ',');

            if (parte1 == "libro"){
                // Es un libro
                Libro* nuevoLibro = new Libro(parte2, parte3, parte4, parte5, parte6_str, parte7);
                biblioteca[contadorBiblioteca] = nuevoLibro;
                contadorBiblioteca++;
            }
            else{
                // Es una revista
                Revista* nuevaRevista = new Revista(parte2, parte3, parte4, parte5, parte6_int, parte7);
                biblioteca[contadorBiblioteca] = nuevaRevista;
                contadorBiblioteca++;
            }
    
        }
        myFile.close();
    } else {
        cout << endl;
        cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
        cout << "Error al abrir el archivo " + nombreTxt << endl;
        cout << "Esto es normal si es la primera vez que se ejecuta el programa." << endl;
        cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
        cout << endl;
    }
}


void leerUsuarioTxt(string nombreTxt,  Usuario* vectorUsuarios[100], int contadorUsuarios){
    fstream myFile;
    myFile.open(nombreTxt, ios::in); // LEER
    if (myFile.is_open()){
        string line;
        while (getline(myFile, line)){
            // Cadena de ejemplo
            string datos = line;
            
            // Variables para almacenar los valores separados
            int parte3_int;
            string parte1, parte2, parte3_str;
            stringstream ss(line);
            getline(ss, parte1, ',');
            getline(ss, parte2, ',');
            getline(ss, parte3_str, ',');
            parte3_int = stoi(parte3_str);


            // Es una revista
            Usuario* nuevoUsuario = new Usuario(parte1, parte2, parte3_int);
            vectorUsuarios[contadorUsuarios] = nuevoUsuario;
            contadorUsuarios++;
            
    
        }
        myFile.close();
    } else {
        cout << endl;
        cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
        cout << "Error al abrir el archivo " + nombreTxt << endl;
        cout << "Esto es normal si es la primera vez que se ejecuta el programa." << endl;
        cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
        cout << endl;
    }
}

void escribirTxtUsuario(string nombreTxt, Usuario* vectorUsuarios[100], bool append){

    fstream myFile;
    if (append){
        myFile.open(nombreTxt, ios::app); // AGREGAR
    }
    else{
        myFile.open(nombreTxt, ios::out); // SOBRE-ESCRIBIR
    }
    if (myFile.is_open()){
        int i = 0;
        while (vectorUsuarios[i] != nullptr){
            
            myFile << vectorUsuarios[i]->getNombre();
            myFile << "," << vectorUsuarios[i]->getId();
            myFile << "," << vectorUsuarios[i]->getMaterialesPrestadosActuales();
            myFile << endl;   
            i++;      
        }
        myFile.close();
    }
    else{
        cout << "Error al abrir el archivo usuarios" << endl;
    }
}

void escribirTxt(string nombreTxt, MaterialBibliografico* biblioteca[100], bool append){

    fstream myFile;
    if (append){
        myFile.open(nombreTxt, ios::app); // AGREGAR
    }
    else{
        myFile.open(nombreTxt, ios::out); // SOBRE-ESCRIBIR
    }
    if (myFile.is_open()){
        int i = 0;
        while (biblioteca[i] != nullptr){
            if (dynamic_cast<Libro*>(biblioteca[i])){
                // Es un libro
                myFile << "libro";
                myFile <<  "," << biblioteca[i]->getNombre();
                myFile <<  "," << biblioteca [i]->getIsbn();
                myFile <<  "," << biblioteca [i]->getAutor();
                myFile << "," << biblioteca [i]->getPrestado();
                myFile << "," << dynamic_cast<Libro*>(biblioteca[i])->getFechaPublicacion();  
                myFile << "," << dynamic_cast<Libro*>(biblioteca[i])->getResumen();
                myFile << endl;

                
            }
            else{
                // Es una revista
                myFile << "revista";
                myFile <<  "," << biblioteca[i]->getNombre();
                myFile  << "," << biblioteca[i]->getIsbn();
                myFile  << "," << biblioteca[i]->getAutor();
                myFile  << "," << biblioteca[i]->getPrestado();
                myFile  << "," << dynamic_cast<Revista*>(biblioteca[i])->getNumeroEdicion();
                myFile << "," << dynamic_cast<Revista*>(biblioteca[i])->getMesPublicacion();
                myFile << endl;
            }
            i++;
        }
        myFile.close();
    }
    else{
        cout << "Error al abrir el archivo" << endl;
    }
}

void agregarLibro(int contadorBiblioteca, MaterialBibliografico* biblioteca[100]) {
    // comprobar si hay espacio en la base de datos
if (contadorBiblioteca >= 100) {
    cout << "No hay espacio en la biblioteca" << endl;
}
else {
    // solicitar string nombre
    string nombre;
    cout << "Ingrese el nombre del libro: ";
    cin >> nombre;

    // solicitar string isbn
    string isbn;
    cout << "Ingrese el ISBN del libro: ";
    cin >> isbn;

    // solicitar string autor
    string autor;
    cout << "Ingrese el autor del libro: ";
    cin >> autor;

    // bool prestado
    bool prestado = false;


    // int fechaPublicacion
    string fechaPublicacion;
    cout << "Ingrese la fecha de publicación del libro: ";
    cin >> fechaPublicacion;

    // string resumen
    string resumen;
    cout << "Ingrese el resumen del libro: ";
    cin >> resumen;

    // crear el objeto
    MaterialBibliografico* nuevoLibro = new Libro(nombre, isbn, autor, prestado, fechaPublicacion, resumen);

    // agregar a la base de datos
    biblioteca[contadorBiblioteca] = nuevoLibro;
    contadorBiblioteca++;
}
}

void agregarRevista(int contadorBiblioteca, MaterialBibliografico* biblioteca[100]) {

// comprobar si hay espacio en la base de datos
if (contadorBiblioteca >= 100) {
    cout << "No hay espacio en la biblioteca" << endl;
}
else {
    // solicitar string nombre
    string nombre;
    cout << "Ingrese el nombre de la revista: ";
    cin >> nombre;

    // solicitar string isbn
    string isbn;
    cout << "Ingrese el ISBN de la revista: ";
    cin >> isbn;

    // solicitar string autor
    string autor;
    cout << "Ingrese el autor de la revista: ";
    cin >> autor;

    // bool prestado
    bool prestado = false;


    // int numeroEdicion
    int numeroEdicion;
    cout << "Ingrese el número de edición de la revista: ";
    cin >> numeroEdicion;

    // string mesPublicacion
    string mesPublicacion;
    cout << "Ingrese el mes de publicación de la revista: ";
    cin >> mesPublicacion;

    // crear el objeto
    MaterialBibliografico* nuevaRevista = new Revista(nombre, isbn, autor, prestado, numeroEdicion, mesPublicacion);

    // agregar a la base de datos
    biblioteca[contadorBiblioteca] = nuevaRevista;
    contadorBiblioteca++;
}
}

int main(){

    

    MaterialBibliografico* biblioteca[100];
    Usuario* vectorUsuarios[100];
    int contadorBiblioteca = 0;
    int contadorUsuarios = 0;
    bool programaCorriendo = true;

    leerBibliotecaTxt("biblioteca.txt", biblioteca, contadorBiblioteca);
    leerUsuarioTxt("usuarios.txt", vectorUsuarios, contadorUsuarios);
    

    cout << endl;
    cout << "/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/" << endl;
    cout << "Bienvenido al Programa!" << endl;
    cout << endl;
    cout << "Material Bibliográfico en la Base de Datos:" << endl;
    cout << endl;
    imprimirBiblioteca(biblioteca, contadorBiblioteca);
    cout << endl;
    cout << "/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/" << endl;


    // bucle del sistema
    while (programaCorriendo){
        
        cout << endl;
        cout << "/*-*-*-*-*-* Menú Principal *-*-*-*-*-*/" << endl;
        cout << endl;
        cout << "1) Agregar material bibliográfico a la biblioteca" << endl;
        cout << "2) Mostrar información de los materiales bibliográficos" << endl;
        cout << "3) Buscar material bibliográfico" << endl;
        cout << "4) Prestamo y devolución de material" << endl;
        cout << "5) Menu Usuarios" << endl;
        cout << "6) Guardar y salir del programa" << endl;
        cout << endl;
        cout << "/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/" << endl;

        int optionMenu0= -1;

        cin >> optionMenu0;

        switch (optionMenu0)
        {
        case 1:
            /* Agregar Material  Bibliográfico */
            
            cout << endl;
            cout << "/*-*-*-*-*-* Agregar Material Bibliográfico *-*-*-*-*-*/" << endl;
            cout << endl;
            cout << "1) Agregar nueva Revista" << endl;
            cout << "2) Agregar nuevo Libro" << endl;
            cout << endl;
            cout << "/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-/" << endl;
            cout << endl;


            int optionMenu1;
            cin >> optionMenu1;

            while(optionMenu1 != 1 && optionMenu1 != 2){
                cout << "/*-*-*-*-*-* Agregar Material Bibliográfico *-*-*-*-*-*/" << endl;
                cout << endl;
                cout << "1) Agregar nueva Revista" << endl;
                cout << "2) Agregar nuevo Libro" << endl;
                cout << endl;
                cout << "/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-/" << endl;
                cout << endl;

                cin >> optionMenu1;
            }

            switch (optionMenu1)
            {
            case 1:
                /* Agregar nueva Revista */
                cout << endl;
                cout << "/*-*-*-*-*-* Agregar Nueva Revista *-*-*-*-*-*/" << endl;
                agregarRevista(contadorBiblioteca, biblioteca);
                escribirTxt("biblioteca.txt", biblioteca, true);
                cout << endl;
                
            

                cout << "/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/" << endl;
                cout << endl;
                
                break;
            case 2:
                
                /* Agregar nuevo Libro */
                cout << endl;
                cout << "/*-*-*-*-*-* Agregar Nuevo Libro *-*-*-*-*-*/" << endl;
                cout << endl;
                agregarLibro(contadorBiblioteca, biblioteca);
                escribirTxt("biblioteca.txt", biblioteca, true);
                cout << "/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/" << endl;
                cout << endl;
            

                
                break;
            
            default:
                break;
            }


            break;

        case 2:
            /* Mostrar información */
            cout << endl;
            cout << "/*-*-*-*-*-* Mostrar Información *-*-*-*-*-*/" << endl;
            cout << endl;
            cout << "1) Mostrar todas las Revistas" << endl;
            cout << "2) Mostrar todos los libros" << endl;
            cout << endl;
            cout << "/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/" << endl;
            cout << endl;


            

            int optionMenu2;
            cin >> optionMenu2;

            while (optionMenu2 != 1 && optionMenu2 != 2){
                
                cout << endl;
                cout << "/*-*-*-*-*-* Mostrar Información *-*-*-*-*-*/" << endl;
                cout << endl;
                cout << "1) Mostrar todas las Revistas" << endl;
                cout << "2) Mostrar todos los libros" << endl;
                cout << endl;
                cout << "/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/" << endl;
                cout << endl;

     
                cin >> optionMenu2;
                
            }

            switch (optionMenu2)
            {
            case 1:
                /* Mostrar todas las Revistas */
                cout << endl;
                cout << "/*-*-*-*-*-* Mostrar todas las Revistas *-*-*-*-*-*/" << endl;
                cout << endl;
                mostrarInformacionRevistas("biblioteca.txt", biblioteca, contadorBiblioteca);
                cout << "/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-/" << endl;
                cout << endl;
                break;
            case 2:
                /* Mostrar todos los Libros */
                cout << endl;
                cout << "/*-*-*-*-*-* Mostrar todos los libros *-*-*-*-*-*/" << endl;
                cout << endl;
                mostrarInformacionLibros("biblioteca.txt", biblioteca, contadorBiblioteca);
                cout << "/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-/" << endl;
                cout << endl;
                break;
            
            default:
                break;
            }

            break;

        case 3:
            /* Buscar Material  */
            
            cout << endl;
			cout << "/*-*-*-*-*-* Buscar Material *-*-*-*-*-*/" << endl;
			cout << endl;
            cout << "1) Buscar por título" << endl;
            cout << "2) Buscar por autor" << endl;
            cout << endl;
            cout << "/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/" << endl;
            cout << endl;


            

            int optionMenu3;
            cin >> optionMenu3;

            while (optionMenu3 != 1 && optionMenu3 != 2){

                 cout << endl;
			    cout << "/*-*-*-*-*-* Buscar Material *-*-*-*-*-*/" << endl;
			    cout << endl;
                cout << "1) Buscar por título" << endl;
                cout << "2) Buscar por autor" << endl;
                cout << endl;
                cout << "/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/" << endl;
                cout << endl;


                

                cin >> optionMenu3;

            }

            switch (optionMenu3)
            {
            case 1:
                /* Buscar por título */
                cout << endl;
			    cout << "/*-*-*-*-*-* Buscar por título *-*-*-*-*-*/" << endl;
			    cout << endl;
                cout << "/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/" << endl;
                cout << endl;

                break;
            case 2:
                /* Buscar por autor */
                cout << endl;
			    cout << "/*-*-*-*-*-* Buscar por Autor *-*-*-*-*-*/" << endl;
			    cout << endl;
                cout << "/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-/" << endl;
                cout << endl;

                break;
            
            default:
                break;
            }

            break;

        case 4:
            /* Prestamo y devolución  */
            cout << endl;
			cout << "/*-*-*-*-*-* Prestamo y devolución *-*-*-*-*-*/" << endl;
			prestamoDevolucion(biblioteca, contadorBiblioteca); 
            cout << "/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/" << endl;
            cout << endl;


            // PARA NICO Y MARTINA: ACÁ MOSTRAR TODOS LOS LIBROS Y REVISTAS CON SU ISBN
            // EL USUARIO INGRESA EL ISBN Y DE CAMBIA EL ESTADO DE PRESTADO


        case 5:
            /* MENU USUARIOS  */
            cout << endl;
			cout << "/*-*-*-*-*-* MENU USUARIOS *-*-*-*-*-*/" << endl;
            cout << "1) Crear Usuario" << endl;
            cout << "2) Buscar Usuario" << endl;
            cout << "3) Eliminar Usuario" << endl;
            cout << "4) Imprimir Usuarios" << endl;
            cout << "/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/" << endl;

            int menuUsuarios;
            cin >> menuUsuarios;

        
            switch (menuUsuarios)
            {
            case 1:
                crearUsuario(vectorUsuarios, contadorUsuarios);
                escribirTxtUsuario("usuarios.txt", vectorUsuarios, true);
                break;
            case 2:
                buscarUsuarioPorNombre(vectorUsuarios, contadorUsuarios);
                break;
            case 3:
                // Eliminar Usuario (implementación pendiente)
                eliminarUsuarioPorNombre(vectorUsuarios, contadorUsuarios);
                break;
            case 4:
                // Imprimir Usuarios (implementación pendiente)
                imprimirTodosLosUsuarios(vectorUsuarios);
                break;
            default:
                break;
            }


            cout << "/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/" << endl;
            cout << endl;
            


            break;
        
        case 6:
            programaCorriendo = false;
            break;
        default:
            break;
        }

    }
    return 0;

};


    
