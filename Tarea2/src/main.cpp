#include "organizacion.h"
#include "empleado.h"
#include "empleadoAsalariado.h"
#include "empleadoPorHoras.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {

    
    string linea{};
    
    // Creando organizacion, vacía por el momento
    Organizacion *organizacion = new Organizacion();

    // Abriendo el archivo personas.txt
    ifstream ifsPersonas("personas.txt", std::ifstream::in);

    if (!ifsPersonas.is_open()) {
        std::cerr << "Error leyendo archivo personas.txt" << std::endl;
        return -1;   
    }
    
    // Agregando las personas a la organizacion
    while (getline(ifsPersonas,linea)) {
        int nuevoID{0};
        string nuevoNombre{};
        string nuevoApellido{};
        string nuevoEmail{};
        int nuevoTipoEmpleado{0};
        int nuevoIDSupervisor{0};
        
        istringstream strm(linea);
        strm >> nuevoID >> nuevoNombre >> nuevoApellido >> nuevoEmail >> nuevoTipoEmpleado >> nuevoIDSupervisor;

        if(nuevoTipoEmpleado == 1) {
            EmpleadoAsalariado *nuevoEmpleado = new EmpleadoAsalariado(linea);
            organizacion->AgregarEmpleado(nuevoEmpleado);

        }

        else if (nuevoTipoEmpleado == 2) {
            EmpleadoPorHoras *nuevoEmpleado = new EmpleadoPorHoras(linea);
            organizacion->AgregarEmpleado(nuevoEmpleado);
        }
        
    }

    // Cerrando el archivo personas.txt
    ifsPersonas.close();


    // Abriendo el archivo nomina.txt
    ifstream ifsNomina("nomina.txt", std::ifstream::in);

    if (!ifsNomina.is_open()) {
        std::cerr << "Error leyendo archivo nomina.txt" << std::endl;
        return -1;   
    }

    //Agregando los datos de pago para los empleados de nómina
    while (getline(ifsNomina,linea)) {
        istringstream strm(linea);
        organizacion->AgregarDatosDePago(linea);          
    }

    // Cerrando el archivo nomina.txt
    ifsNomina.close();

    // Abriendo el archivo horastrabajadas.txt
    ifstream ifsHoras("horastrabajadas.txt", std::ifstream::in);

    if (!ifsHoras.is_open()) {
        std::cerr << "Error leyendo archivo horastrabajadas.txt" << std::endl;
        return -1;   
    }

    //Agregando los datos de pago para los empleados por hora
    while (getline(ifsHoras,linea)) {
        istringstream strm(linea);
        organizacion->AgregarDatosDePago(linea);          
    }

    // Cerrando el archivo horastrabajadas.txt
    ifsHoras.close();
    
    // Imprimiendo el reporte final en formato .csv
    organizacion->ImprimirReporte();

    // Borrando la organización;
    delete organizacion;

    return 0;
}