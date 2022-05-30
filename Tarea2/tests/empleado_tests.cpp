#include <gtest/gtest.h>
#include "../src/empleado.h"
#include "../src/empleadoPorHoras.h"
#include "../src/empleadoAsalariado.h"

#include <string>
#include <sstream>

namespace {

    TEST(EmpleadoAsalariado_Test, Test_Calcular_Pago) {

        ///AAA

        // Arrange - configiurar el escenario
        EmpleadoAsalariado *empleado = new EmpleadoAsalariado("1 Denis Tyler denis_tyler@biz.com 1 1");
        empleado->AgregarDatosDePago("1 4600.98");

        // Act - ejecute la operación
        float pagoActual = empleado->CalcularPago();
        float pagoEsperado = 4600.98*93/100;

        // Assert - valide los resultados
        EXPECT_FLOAT_EQ(pagoActual, pagoEsperado);
        delete empleado;

    }

    TEST(EmpleadoAsalariado_Test, Test_Calcular_Impuestos) {

        ///AAA

        // Arrange - configiurar el escenario
        EmpleadoAsalariado *empleado = new EmpleadoAsalariado("1 Denis Tyler denis_tyler@biz.com 1 1");
        empleado->AgregarDatosDePago("1 4600.98");

        // Act - ejecute la operación
        float impuestosActual = empleado->CalcularImpuestos();
        float impuestosEspoerado = 4600.98*7/100;

        // Assert - valide los resultados
        EXPECT_FLOAT_EQ(impuestosActual, impuestosEspoerado);
        delete empleado;

    }

    TEST(EmpleadoPorHoras_Test, Test_Calcular_Pago) {

        ///AAA

        // Arrange - configiurar el escenario
        EmpleadoPorHoras *empleado = new EmpleadoPorHoras("451 Ryan Webster Ryan_Webster6612@hourpy.biz 2 214");
        empleado->AgregarDatosDePago("451 42.26 55");

        // Act - ejecute la operación
        float pagoActual = empleado->CalcularPago();
        float pagoEsperado = 42.26*55;

        // Assert - valide los resultados
        EXPECT_FLOAT_EQ(pagoActual, pagoEsperado);
        delete empleado;

    }

    TEST(EmpleadoPorHoras_Test, Test_Calcular_Impuestos) {

        ///AAA

        // Arrange - configiurar el escenario
        EmpleadoPorHoras *empleado = new EmpleadoPorHoras("451 Ryan Webster Ryan_Webster6612@hourpy.biz 2 214");
        empleado->AgregarDatosDePago("451 42.26 55");

        // Act - ejecute la operación
        float impuestosActual = empleado->CalcularImpuestos();
        float impuestosEspoerado = 0;

        // Assert - valide los resultados
        EXPECT_FLOAT_EQ(impuestosActual, impuestosEspoerado);
        delete empleado;

    }

    TEST(Empleados_Test, Test_Obtener_ID) {

        ///AAA

        // Arrange - configiurar el escenario
        EmpleadoPorHoras *empleado = new EmpleadoPorHoras("451 Ryan Webster Ryan_Webster6612@hourpy.biz 2 214");

        // Act - ejecute la operación
        int actual = empleado->ObtenerID();
        int esperado = 451;

        // Assert - valide los resultados
        EXPECT_EQ(actual, esperado);
        delete empleado;

    }
}