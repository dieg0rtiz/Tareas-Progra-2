#include <gtest/gtest.h>
#include "../src/organizacion.h"
#include "../src/empleadoPorHoras.h"
#include "../src/empleadoAsalariado.h"

#include <string>
#include <sstream>

namespace {

    TEST(Organizacion_Test, Test_CalcularSubTotalAPagar) {

        ///AAA

        // Arrange - configiurar el escenario
        Organizacion *organizacion = new Organizacion();
        EmpleadoAsalariado *empleado1 = new EmpleadoAsalariado("1 Denis Tyler denis_tyler@biz.com 1 1");
        EmpleadoPorHoras *empleado2 = new EmpleadoPorHoras("2 Clarissa Parker clarissa_parker@biz.com 2 1");
        organizacion->AgregarEmpleado(empleado1);
        organizacion->AgregarEmpleado(empleado2);
        organizacion->AgregarDatosDePago("1 4600.98");
        organizacion->AgregarDatosDePago("2 42.26 55");

        // Act - ejecute la operación
        float subtotalActual = organizacion->CalcularSubTotalAPagar();
        float subtotalEsperado = 4600.98*93/100 + 42.26*55;

        // Assert - valide los resultados
        EXPECT_FLOAT_EQ(subtotalActual, subtotalEsperado);
        delete organizacion;

    }

    TEST(Organizacion_Test, Test_CalcularImpuestosTotales) {

        ///AAA

        // Arrange - configiurar el escenario
        Organizacion *organizacion = new Organizacion();
        EmpleadoAsalariado *empleado1 = new EmpleadoAsalariado("1 Denis Tyler denis_tyler@biz.com 1 1");
        EmpleadoPorHoras *empleado2 = new EmpleadoPorHoras("2 Clarissa Parker clarissa_parker@biz.com 2 1");
        organizacion->AgregarEmpleado(empleado1);
        organizacion->AgregarEmpleado(empleado2);
        organizacion->AgregarDatosDePago("1 4600.98");
        organizacion->AgregarDatosDePago("2 42.26 55");

        // Act - ejecute la operación
        float impuestosTotaleslActual = organizacion->CalcularImpuestosTotales();
        float impuestosTotalesEsperado = 4600.98*7/100 + 0;

        // Assert - valide los resultados
        EXPECT_FLOAT_EQ(impuestosTotaleslActual, impuestosTotalesEsperado);
        delete organizacion;

    }

}