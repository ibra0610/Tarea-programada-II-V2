#ifndef EMPLEADO_H 
#define EMPLEADO_H 
#include <iostream> 

using namespace std; 

class Empleado{

    protected: 
    Empleado() { }

    public: 
    ~Empleado() {} 
    void agregarSubordinado(Empleado *subordinado);
    virtual int de_id_empleado() = 0;
    virtual string de_Nombre() =0;  

    friend ostream& operator << (ostream &output, const Empleado &empleado);
}; 

#endif