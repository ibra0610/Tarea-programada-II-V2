#include <iostream> 
#include "empleadoNomina.h" 

using namespace std; 

EmpleadoNomina::EmpleadoNomina(int _id_empleado, string _nombre, string _apellido, string _email, int _tipo_empleado, int _id_supervisor){
    this-> id_empleado = _id_empleado; 
    this->nombre = _nombre; 
    this-> apellido = _apellido; 
    this-> email = _email; 
    this-> tipo_empleado = _tipo_empleado; 
    this-> id_supervisor = _id_supervisor; 
} 

void EmpleadoNomina:: agregarSubordinado(Empleado *subordinado){
    this->subordinados.push_back(subordinado);
}

int EmpleadoNomina::de_id_empleado(){
    return this-> id_empleado; 
} 

string EmpleadoNomina::de_Nombre(){
    return this->nombre; 
}
 