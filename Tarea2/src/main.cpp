#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "organizacion.h"
#include "empleado.h"

using namespace std;

int main() {

    string linea;
    int idEmpleado = 0;
    float pagoMensualBruto = 0;
    float montoPorHora = 0;
    int horasTrabajadas = 0;

    // Abriendo el archivo personas.txt, creando los empleados y agregándolos a la organización
    ifstream ifsPersonas("personas.txt", std::ifstream::in);

    if (!ifsPersonas.is_open()) {
        std::cerr << "Error leyendo archivo personas.txt" << std::endl;
        return -1;
    }

    // Agregando el director
    Empleado *director = new Empleado(&ifsPersonas);
    Organizacion *organizacion = new Organizacion(director);

    // Agregando el resto de los empleados
    while (getline(ifsPersonas,linea)) {
        Empleado *nuevoEmpleado = new Empleado(&ifsPersonas);
        organizacion->AgregarEmpleado(nuevoEmpleado, nuevoEmpleado->ObtenerIDSupervisor());
    }

    ifsPersonas.close();

    // Abriendo el archivo nominaa.txt y asignando el pago a los empleados asalariados
    ifstream ifsNomina("nomina.txt", std::ifstream::in);

    if (!ifsNomina.is_open()) {
        std::cerr << "Error leyendo archivo nomina.txt" << std::endl;
        return -1;
    }

    // Asignando el pago del primer empleado en el archivo
    ifsNomina >> idEmpleado >> pagoMensualBruto;
    organizacion->ObtenerEmpleado(idEmpleado)->AsignarPagoMensualBruto(pagoMensualBruto);
    organizacion->ObtenerEmpleado(idEmpleado)->CalcularPago();

    // Asignando el pago del resto de los empleados asalariados
    while (getline(ifsNomina,linea)) {
        ifsNomina >> idEmpleado >> pagoMensualBruto;
        organizacion->ObtenerEmpleado(idEmpleado)->AsignarPagoMensualBruto(pagoMensualBruto);
        organizacion->ObtenerEmpleado(idEmpleado)->CalcularPago();
    }

    ifsNomina.close();

    // Abriendo el archivo horastrabajadas.txt y asignando el pago a los empleados por hora
    ifstream ifsHorasTrabajadas("horastrabajadas.txt", std::ifstream::in);

    if (!ifsHorasTrabajadas.is_open()) {
        std::cerr << "Error leyendo archivo horastrabajadas.txt" << std::endl;
        return -1;
    }

    // Asignando el pago del primer empleado en el archivo
    ifsHorasTrabajadas >> idEmpleado >> montoPorHora >> horasTrabajadas;
    organizacion->ObtenerEmpleado(idEmpleado)->AsignarMontoPorHoras(montoPorHora);
    organizacion->ObtenerEmpleado(idEmpleado)->AsignarHorasLaboradas(horasTrabajadas);
    organizacion->ObtenerEmpleado(idEmpleado)->CalcularPago();

    // Asignando el pago del resto de los empleados por hora
    while (getline(ifsHorasTrabajadas,linea)) {
        ifsHorasTrabajadas >> idEmpleado >> montoPorHora >> horasTrabajadas;
        organizacion->ObtenerEmpleado(idEmpleado)->AsignarMontoPorHoras(montoPorHora);
        organizacion->ObtenerEmpleado(idEmpleado)->AsignarHorasLaboradas(horasTrabajadas);
        organizacion->ObtenerEmpleado(idEmpleado)->CalcularPago();
    }

    ifsHorasTrabajadas.close();

    organizacion->ImprimirReporte();

    cout << "Reporte" << std::endl;
    cout << "ID_Empleado,Nombre_Completo_Empleado,Nombre_Completo_Supervisor,Monto_A_Pagar" << std::endl;
    cout << organizacion;
    cout << std::endl;
    cout << "Resumen" << std::endl;
    cout << "Subtotal: " << organizacion->ObtenerSubTotalAPagar() << " "
        << "Impuestos a Retener: " << organizacion->ObtenerImpuestosTotales() << " "
        << "Total: " << organizacion->ObtenerSubTotalAPagar() + organizacion->ObtenerImpuestosTotales()
         << std::endl;

    delete organizacion;
}