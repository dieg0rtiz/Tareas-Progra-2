#include <gtest/gtest.h>
#include "../src/envio.h"
#include "../src/envioServicioPostal.h"
#include "../src/envioFedEX.h"

namespace {

    TEST(Envio_Servicio_Postal, Primera_Clase_Test_0kg_1km) {

        ///AAA

        // Arrange - configiurar el escenario
        EnvioServicioPostal* envio = new EnvioServicioPostal(0,1,1);

        // Act - ejecute la operación
        float actual = envio->CalcularValor();
        float esperada = 0.300*1;

        // Assert - valide los resultados
        EXPECT_FLOAT_EQ(esperada, actual);
        delete envio;
    }

    TEST(Envio_Servicio_Postal, Primera_Clase_Test_1kg_2km) {

        ///AAA

        // Arrange - configiurar el escenario
        EnvioServicioPostal* envio = new EnvioServicioPostal(1,2,1);

        // Act - ejecute la operación
        float actual = envio->CalcularValor();
        float esperada = 0.300*2;

        // Assert - valide los resultados
        EXPECT_FLOAT_EQ(esperada, actual);
        delete envio;
    }

    TEST(Envio_Servicio_Postal, Primera_Clase_Test_3kg_4km) {

        ///AAA

        // Arrange - configiurar el escenario
        EnvioServicioPostal* envio = new EnvioServicioPostal(3,4,1);

        // Act - ejecute la operación
        float actual = envio->CalcularValor();
        float esperada = 0.300*4;

        // Assert - valide los resultados
        EXPECT_FLOAT_EQ(esperada, actual);
        delete envio;
    }

    TEST(Envio_Servicio_Postal, Primera_Clase_Test_4kg_5km) {

        ///AAA

        // Arrange - configiurar el escenario
        EnvioServicioPostal* envio = new EnvioServicioPostal(4,5,1);

        // Act - ejecute la operación
        float actual = envio->CalcularValor();
        float esperada = 0.450*5;

        // Assert - valide los resultados
        EXPECT_FLOAT_EQ(esperada, actual);
        delete envio;
    }

    TEST(Envio_Servicio_Postal, Primera_Clase_Test_6kg_1km) {

        ///AAA

        // Arrange - configiurar el escenario
        EnvioServicioPostal* envio = new EnvioServicioPostal(6,1,1);

        // Act - ejecute la operación
        float actual = envio->CalcularValor();
        float esperada = 0.450*1;

        // Assert - valide los resultados
        EXPECT_FLOAT_EQ(esperada, actual);
        delete envio;
    }

    TEST(Envio_Servicio_Postal, Primera_Clase_Test_8kg_8km) {

        ///AAA

        // Arrange - configiurar el escenario
        EnvioServicioPostal* envio = new EnvioServicioPostal(8,8,1);

        // Act - ejecute la operación
        float actual = envio->CalcularValor();
        float esperada = 0.450*8;

        // Assert - valide los resultados
        EXPECT_FLOAT_EQ(esperada, actual);
        delete envio;
    }

    TEST(Envio_Servicio_Postal, Primera_Clase_Test_9kg_1km) {

        ///AAA

        // Arrange - configiurar el escenario
        EnvioServicioPostal* envio = new EnvioServicioPostal(9,1,1);

        // Act - ejecute la operación
        float actual = envio->CalcularValor();
        float esperada = 0.600*1;

        // Assert - valide los resultados
        EXPECT_FLOAT_EQ(esperada, actual);
        delete envio;
    }

    TEST(Envio_Servicio_Postal, Primera_Clase_Test_12kg_10km) {

        ///AAA

        // Arrange - configiurar el escenario
        EnvioServicioPostal* envio = new EnvioServicioPostal(12,10,1);

        // Act - ejecute la operación
        float actual = envio->CalcularValor();
        float esperada = 0.600*10;

        // Assert - valide los resultados
        EXPECT_FLOAT_EQ(esperada, actual);
        delete envio;
    }

    TEST(Envio_Servicio_Postal, Segunda_Clase_Test_0kg_1km) {

        ///AAA

        // Arrange - configiurar el escenario
        EnvioServicioPostal* envio = new EnvioServicioPostal(0,1,2);

        // Act - ejecute la operación
        float actual = envio->CalcularValor();
        float esperada = 0.0280*1;

        // Assert - valide los resultados
        EXPECT_FLOAT_EQ(esperada, actual);
        delete envio;
    }

    TEST(Envio_Servicio_Postal, Segunda_Clase_Test_1kg_2km) {

        ///AAA

        // Arrange - configiurar el escenario
        EnvioServicioPostal* envio = new EnvioServicioPostal(1,2,2);

        // Act - ejecute la operación
        float actual = envio->CalcularValor();
        float esperada = 0.0280*2;

        // Assert - valide los resultados
        EXPECT_FLOAT_EQ(esperada, actual);
        delete envio;
    }

    TEST(Envio_Servicio_Postal, Segunda_Clase_Test_3kg_4km) {

        ///AAA

        // Arrange - configiurar el escenario
        EnvioServicioPostal* envio = new EnvioServicioPostal(3,4,2);

        // Act - ejecute la operación
        float actual = envio->CalcularValor();
        float esperada = 0.0280*4;

        // Assert - valide los resultados
        EXPECT_FLOAT_EQ(esperada, actual);
        delete envio;
    }

    TEST(Envio_Servicio_Postal, Segunda_Clase_Test_4kg_5km) {

        ///AAA

        // Arrange - configiurar el escenario
        EnvioServicioPostal* envio = new EnvioServicioPostal(4,5,2);

        // Act - ejecute la operación
        float actual = envio->CalcularValor();
        float esperada = 0.0530*5;

        // Assert - valide los resultados
        EXPECT_FLOAT_EQ(esperada, actual);
        delete envio;
    }

    TEST(Envio_Servicio_Postal, Segunda_Clase_Test_6kg_1km) {

        ///AAA

        // Arrange - configiurar el escenario
        EnvioServicioPostal* envio = new EnvioServicioPostal(6,1,2);

        // Act - ejecute la operación
        float actual = envio->CalcularValor();
        float esperada = 0.0530*1;

        // Assert - valide los resultados
        EXPECT_FLOAT_EQ(esperada, actual);
        delete envio;
    }

    TEST(Envio_Servicio_Postal, Segunda_Clase_Test_8kg_8km) {

        ///AAA

        // Arrange - configiurar el escenario
        EnvioServicioPostal* envio = new EnvioServicioPostal(8,8,2);

        // Act - ejecute la operación
        float actual = envio->CalcularValor();
        float esperada = 0.0530*8;

        // Assert - valide los resultados
        EXPECT_FLOAT_EQ(esperada, actual);
        delete envio;
    }

    TEST(Envio_Servicio_Postal, Segunda_Clase_Test_9kg_1km) {

        ///AAA

        // Arrange - configiurar el escenario
        EnvioServicioPostal* envio = new EnvioServicioPostal(9,1,2);

        // Act - ejecute la operación
        float actual = envio->CalcularValor();
        float esperada = 0.0750*1;

        // Assert - valide los resultados
        EXPECT_FLOAT_EQ(esperada, actual);
        delete envio;
    }

    TEST(Envio_Servicio_Postal, Segunda_Clase_Test_12kg_10km) {

        ///AAA

        // Arrange - configiurar el escenario
        EnvioServicioPostal* envio = new EnvioServicioPostal(12,10,2);

        // Act - ejecute la operación
        float actual = envio->CalcularValor();
        float esperada = 0.0750*10;

        // Assert - valide los resultados
        EXPECT_FLOAT_EQ(esperada, actual);
        delete envio;
    }

    TEST(Envio_Servicio_Postal, Tercera_Clase_Test_0kg_1km) {

        ///AAA

        // Arrange - configiurar el escenario
        EnvioServicioPostal* envio = new EnvioServicioPostal(0,1,3);

        // Act - ejecute la operación
        float actual = envio->CalcularValor();
        float esperada = 0.0120*1;

        // Assert - valide los resultados
        EXPECT_FLOAT_EQ(esperada, actual);
        delete envio;
    }

    TEST(Envio_Servicio_Postal, Tercera_Clase_Test_1kg_2km) {

        ///AAA

        // Arrange - configiurar el escenario
        EnvioServicioPostal* envio = new EnvioServicioPostal(1,2,3);

        // Act - ejecute la operación
        float actual = envio->CalcularValor();
        float esperada = 0.0120*2;

        // Assert - valide los resultados
        EXPECT_FLOAT_EQ(esperada, actual);
        delete envio;
    }

    TEST(Envio_Servicio_Postal, Tercera_Clase_Test_3kg_4km) {

        ///AAA

        // Arrange - configiurar el escenario
        EnvioServicioPostal* envio = new EnvioServicioPostal(3,4,3);

        // Act - ejecute la operación
        float actual = envio->CalcularValor();
        float esperada = 0.0120*4;

        // Assert - valide los resultados
        EXPECT_FLOAT_EQ(esperada, actual);
        delete envio;
    }

    TEST(Envio_Servicio_Postal, Tercera_Clase_Test_4kg_5km) {

        ///AAA

        // Arrange - configiurar el escenario
        EnvioServicioPostal* envio = new EnvioServicioPostal(4,5,3);

        // Act - ejecute la operación
        float actual = envio->CalcularValor();
        float esperada = 0.0120*5;

        // Assert - valide los resultados
        EXPECT_FLOAT_EQ(esperada, actual);
        delete envio;
    }

    TEST(Envio_Servicio_Postal, Tercera_Clase_Test_6kg_1km) {

        ///AAA

        // Arrange - configiurar el escenario
        EnvioServicioPostal* envio = new EnvioServicioPostal(6,1,3);

        // Act - ejecute la operación
        float actual = envio->CalcularValor();
        float esperada = 0.0120*1;

        // Assert - valide los resultados
        EXPECT_FLOAT_EQ(esperada, actual);
        delete envio;
    }

    TEST(Envio_Servicio_Postal, Tercera_Clase_Test_8kg_8km) {

        ///AAA

        // Arrange - configiurar el escenario
        EnvioServicioPostal* envio = new EnvioServicioPostal(8,8,3);

        // Act - ejecute la operación
        float actual = envio->CalcularValor();
        float esperada = 0.0120*8;

        // Assert - valide los resultados
        EXPECT_FLOAT_EQ(esperada, actual);
        delete envio;
    }

    TEST(Envio_Servicio_Postal, Tercera_Clase_Test_9kg_1km) {

        ///AAA

        // Arrange - configiurar el escenario
        EnvioServicioPostal* envio = new EnvioServicioPostal(9,1,3);

        // Act - ejecute la operación
        float actual = envio->CalcularValor();
        float esperada = 0.0120*1;

        // Assert - valide los resultados
        EXPECT_FLOAT_EQ(esperada, actual);
        delete envio;
    }

    TEST(Envio_Servicio_Postal, Tercera_Clase_Test_12kg_10km) {

        ///AAA

        // Arrange - configiurar el escenario
        EnvioServicioPostal* envio = new EnvioServicioPostal(12,10,3);

        // Act - ejecute la operación
        float actual = envio->CalcularValor();
        float esperada = 0.0120*10;

        // Assert - valide los resultados
        EXPECT_FLOAT_EQ(esperada, actual);
        delete envio;
    }

    TEST(Envio_FedEX, Test_5kg_100km) {

        ///AAA

        // Arrange - configiurar el escenario
        EnvioFedEX* envio = new EnvioFedEX(5,100);

        // Act - ejecute la operación
        float actual = envio->CalcularValor();
        float esperada = 35.00;

        // Assert - valide los resultados
        EXPECT_FLOAT_EQ(esperada, actual);
        delete envio;
    }

    TEST(Envio_FedEX, Test_10kg_500km) {

        ///AAA

        // Arrange - configiurar el escenario
        EnvioFedEX* envio = new EnvioFedEX(10,500);

        // Act - ejecute la operación
        float actual = envio->CalcularValor();
        float esperada = 35.00;

        // Assert - valide los resultados
        EXPECT_FLOAT_EQ(esperada, actual);
        delete envio;
    }

    TEST(Envio_FedEX, Test_25kg_500km) {

        ///AAA

        // Arrange - configiurar el escenario
        EnvioFedEX* envio = new EnvioFedEX(25,500);

        // Act - ejecute la operación
        float actual = envio->CalcularValor();
        float esperada = 35.00 + 10.00;

        // Assert - valide los resultados
        EXPECT_FLOAT_EQ(esperada, actual);
        delete envio;
    }

    TEST(Envio_FedEX, Test_10kg_550km) {

        ///AAA

        // Arrange - configiurar el escenario
        EnvioFedEX* envio = new EnvioFedEX(10,550);

        // Act - ejecute la operación
        float actual = envio->CalcularValor();
        float esperada = 35.00 + 15.00;

        // Assert - valide los resultados
        EXPECT_FLOAT_EQ(esperada, actual);
        delete envio;
    }

    TEST(Envio_FedEX, Test_30kg_600km) {

        ///AAA

        // Arrange - configiurar el escenario
        EnvioFedEX* envio = new EnvioFedEX(30,600);

        // Act - ejecute la operación
        float actual = envio->CalcularValor();
        float esperada = 35.00 + 15.00 + 10.00;

        // Assert - valide los resultados
        EXPECT_FLOAT_EQ(esperada, actual);
        delete envio;
    }

    TEST(Monto_Total_Envios, Test) {

        ///AAA

        // Arrange - configiurar el escenario
        vector<Envio *> envios;

        EnvioServicioPostal* envio1 = new EnvioServicioPostal(3,4,1); // 0.300*4
        envios.push_back(envio1);

        EnvioServicioPostal* envio2 = new EnvioServicioPostal(8,8,2); // 0.0530*8
        envios.push_back(envio2);

        EnvioServicioPostal* envio3 = new EnvioServicioPostal(12,10,3); // 0.0120*10
        envios.push_back(envio3);

        EnvioFedEX* envio4 = new EnvioFedEX(30,600); // 35.00 + 15.00 + 10.00
        envios.push_back(envio4);

        EnvioFedEX* envio5 = new EnvioFedEX(25,500); // 35.00 + 10.00
        envios.push_back(envio5);

        // Act - ejecute la operación
        float actual = 0;

        for (Envio* envio : envios) {
            actual += envio->CalcularValor();
            delete envio;
        }

        float esperada = 0.300*4 + 0.0530*8 + 0.0120*10 + 35.00 + 15.00 + 10.00 + 35.00 + 10.00;

        // Assert - valide los resultados
        EXPECT_FLOAT_EQ(esperada, actual);
    }
}