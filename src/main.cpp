#include <iostream> 
#include "arbol.h"
#include <fstream>

using namespace std; 

int main(){

    ifstream lectorArbol("Personas.txt", ifstream::in);

    if(!lectorArbol.is_open()){
        cerr<< "Error leyendo archivo Personas.txt" << endl; 
        return -1; 
    } 

    Arbol *arbol = new Arbol();

    lectorArbol >> *arbol;

    ofstream archivoSalida; 

    archivoSalida.open("Reporte.txt",ios::out); 

    if(archivoSalida.fail()){
        cerr<< "No se pudo crear archivo Reporte.txt"; 
    }

    archivoSalida << *arbol;

    archivoSalida.close(); 
    
    delete arbol; 

    return 0; 
    
}