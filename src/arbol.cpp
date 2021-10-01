#include <map>
#include "arbol.h"
#include "empleado.h"
#include "empleadoHoras.h"
#include "empleadoNomina.h"
#include <iostream>
#include <sstream> 

using namespace std; 

Arbol::Arbol(){
    this->jefe=nullptr; 
} 

Arbol::~Arbol(){
    if(this->jefe!=nullptr){
        delete this->jefe; 
    } 
} 

void Arbol::agregarEmpleado(int id_empleado, string nombre, string apellido, string email, int tipo_empleado, int id_supervisor){

    if(tipo_empleado ==1){

        EmpleadoNomina *trabajador = new EmpleadoNomina(id_empleado,nombre,apellido,email,tipo_empleado,id_supervisor); 

        if(id_empleado==0){

            this->jefe = trabajador; 

        }else{

            Empleado *supervisor = this->planilla.at(id_supervisor);
            supervisor->agregarSubordinado(trabajador); 

        }

        this->planilla.insert(pair<int,Empleado *>(id_empleado, trabajador)); 
    }

    if(tipo_empleado == 2){

        EmpleadoHoras *trabajador = new EmpleadoHoras(id_empleado,nombre,apellido,email,tipo_empleado,id_supervisor);
        
        if(id_supervisor==0){

            this->jefe = trabajador;

        }else{

            Empleado *supervisor = this->planilla.at(id_supervisor); 
            supervisor->agregarSubordinado(trabajador); 

        }

        this->planilla.insert(pair<int,Empleado *>(id_empleado,trabajador));
    }
}

ostream& operator << (ostream &output, const Arbol &arbol)
{
    Empleado* jefe = arbol.jefe;
    output << *(jefe);

    return output;
}

istream& operator >> (istream &input, Arbol &arbol){
    string hilera = ""; 

    int idEmpleado, tipoEmpleado, idSupervisor;
    string nombre, apellido, email; 

    while (getline(input,hilera)){
        idEmpleado = 0;
        tipoEmpleado= 0;
        idSupervisor = 0;
        nombre = ""; 
        apellido = ""; 
        email = ""; 

        istringstream stream (hilera); 
        stream >> idEmpleado >> nombre >> apellido >> email >> tipoEmpleado >> idSupervisor; 

        arbol.agregarEmpleado(idEmpleado, nombre, apellido, email, tipoEmpleado, idSupervisor);
    }

    return input;
}