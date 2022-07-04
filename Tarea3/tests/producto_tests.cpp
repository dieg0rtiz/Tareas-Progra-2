#include <gtest/gtest.h>
#include "../src/producto.h"

namespace {

    TEST(Producto_Test, Test_Metodos_Obtener_Por_Aparte) {

        ///AAA

        // Arrange - configiurar el escenario
        Producto *producto1 = new Producto(1, "manzana amarilla", 250);

        // Act - ejecute la operación
        int idActual = producto1->ObtenerID();
        int idEsperado = 1;

        string nombreActual = producto1->ObtenerNombre();
        string nombreEsperado = "manzana amarilla";

        int existenciasActual = producto1->ObtenerExistencias();
        int existenciasEsperado = 250;

        // Assert - valide los resultados
        EXPECT_EQ(idActual, idEsperado);
        EXPECT_EQ(nombreActual, nombreEsperado);
        EXPECT_EQ(existenciasActual, existenciasEsperado);
        delete producto1;
    }

    TEST(Producto_Test, Test_ActualizarExistencias) {

        ///AAA

        // Arrange - configiurar el escenario
        Producto *producto1 = new Producto(1, "manzana amarilla", 250);

        // Act - ejecute la operación
        producto1->ActualizarExistencias(125);
        int existenciasActual = producto1->ObtenerExistencias();
        int existenciasEsperado = 125;

        // Assert - valide los resultados
        EXPECT_EQ(existenciasActual, existenciasEsperado);
        delete producto1;
    }

    TEST(Producto_Test, Test_ObtenerInformacionProducto) {

        ///AAA

        // Arrange - configiurar el escenario
        Producto *producto1 = new Producto(1, "manzana amarilla", 250);

        // Act - ejecute la operación
        string actual = producto1->ObtenerInformacionProducto();
        string esperado = "1,manzana amarilla,250";

        // Assert - valide los resultados
        EXPECT_EQ(actual, esperado);
        delete producto1;
    }

    TEST(Producto_Test, Test_ID_Negativo) {
        /// AAA

        // Arrange - configurar el escenario

        // Act - ejecute la operación
        EXPECT_THROW({
            Producto *actual = new Producto(-1, "manzana amarilla", 250);
            delete actual;
        }, ExcepcionNumeroNegativo);

        // Assert - valide los resultados
    }

    TEST(Producto_Test, Test_Cantidad_Negativa_Constructor) {
        /// AAA

        // Arrange - configurar el escenario

        // Act - ejecute la operación
        EXPECT_THROW({
            Producto *actual = new Producto(1, "manzana amarilla", -250);
            delete actual;
        }, ExcepcionNumeroNegativo);

        // Assert - valide los resultados
    }

    TEST(Producto_Test, Test_Cantidad_Negativa_Actualizar) {
        /// AAA

        // Arrange - configurar el escenario
        Producto *actual = new Producto(1, "manzana amarilla", 250);

        // Act - ejecute la operación
        EXPECT_THROW({
            actual->ActualizarExistencias(-100);
        }, ExcepcionNumeroNegativo);

        delete actual;

        // Assert - valide los resultados
    }

    TEST(Producto_Test, Test_Cantidad_Caracteres_Producto_Constructor) {
        /// AAA

        // Arrange - configurar el escenario

        // Act - ejecute la operación
        EXPECT_THROW({
            Producto *actual = new Producto(1, "manzana amarilla grande", 250);
            delete actual;
        }, ExcepcionCantidadDeCaracteresProducto);

        // Assert - valide los resultados
    }

    TEST(Producto_Test, Test_Cantidad_Caracteres_Producto_Actualizar) {
        /// AAA

        // Arrange - configurar el escenario
        Producto *actual = new Producto(1, "manzana amarilla", 250);

        // Act - ejecute la operación
        EXPECT_THROW({
            actual->ActualizarNombre("manzana amarilla grande");            
        }, ExcepcionCantidadDeCaracteresProducto);

        delete actual;

        // Assert - valide los resultados  
    }
}