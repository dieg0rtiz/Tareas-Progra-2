#include <gtest/gtest.h>
#include "../src/envio.h"
#include "../src/envioServicioPostal.h"
#include "../src/envioFedEX.h"

namespace {

    TEST(Envio_Servicio_Postal_Test, Primera_Clase_Test_1) {

        ///AAA

        // Arrange - configiurar el escenario
        EnvioServicioPostal* envio = new EnvioServicioPostal(1,1,1);

        // Act - ejecute la operación
        float actual = envio->CalcularValor();
        float esperada = 3;

        // Assert - valide los resultados
        EXPECT_EQ(esperada, actual);
    }

}