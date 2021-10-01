#include "empleadoHoras.h" 
#include <iostream> 

using namespace std; 

EmpleadoHoras :: EmpleadoHoras (int _id_empleado, string _nombre, string _apellido, string _email, int _tipo_empleado, int _id_supervisor){
    this-> id_empleado = _id_empleado; 
    this-> nombre = _nombre; 
    this-> apellido = _apellido; 
    this-> email = _email; 
    this-> tipo_empleado = _tipo_empleado; 
    this-> id_supervisor = _id_supervisor;
} 

EmpleadoHoras::~EmpleadoHoras(){
    for(Empleado* subordinado : this->subordinados){
        delete subordinado; 
    }
}

void EmpleadoHoras:: agregarSubordinado(Empleado *subordinado){
    this->subordinados.push_back(subordinado);
}

int EmpleadoHoras:: de_id_empleado(){
    return this->id_empleado; 
}

string EmpleadoHoras :: de_Nombre(){
    return this -> nombre; 
} 

ostream& operator << (ostream &output, const EmpleadoHoras &empleado){
    output << "Nombre: ";
    output << empleado.nombre;
    output << "Apellido: "; 
    output << empleado.apellido;
    output << "Id empleado: "; 
    output << empleado.id_empleado;
    output << "Id supervisor: "; 
    output << empleado.id_supervisor; 
    output<< endl; 

    //for(EmpleadoHoras *subordinados : empleado.subordinados){
    //    output << *subordinados;
   // }

    return output;
}
