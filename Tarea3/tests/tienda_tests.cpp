#include <gtest/gtest.h>
#include "../src/tienda.h"

namespace {

    TEST(Tienda_Test, Test_Metodos_Obtener_Por_Aparte) {

        ///AAA

        // Arrange - configiurar el escenario
        Tienda *tienda = new Tienda("Mi Tienda", "mitienda.com", "Avenida X Calle Y", "88888888");
        tienda->AgregarProducto(1, "manzana amarilla grande", 250);
        tienda->AgregarProducto(2, "manzana roja grande", 125);

        // Act - ejecute la operación
        string nombreActual = tienda->ObtenerNombre();
        string nombreEsperado = "Mi Tienda";

        string direccionInternetActual = tienda->ObtenerDireccionInternet();
        string direccionInternetEsperada = "mitienda.com";

        string direccionFisicaActual = tienda->ObtenerDireccionFisica();
        string direccionFisicaEsperada = "Avenida X Calle Y";

        string telefonoActual = tienda->ObtenerTelefono();
        string telefonoEsperado = "88888888";

        // Assert - valide los resultados
        EXPECT_EQ(nombreActual, nombreEsperado);
        EXPECT_EQ(direccionInternetActual, direccionInternetEsperada);
        EXPECT_EQ(direccionFisicaActual, direccionFisicaEsperada);
        delete tienda;
    }

    TEST(Tienda_Test, Test_ObtenerInformacionProducto) {

        ///AAA

        // Arrange - configiurar el escenario
        Tienda *tienda = new Tienda("Mi Tienda", "mitienda.com", "Avenida X Calle Y", "88888888");
        tienda->AgregarProducto(1, "manzana amarilla grande", 250);
        tienda->AgregarProducto(2, "manzana roja grande", 125);

        // Act - ejecute la operación
        string infoProducto1Actual = tienda->ObtenerInformacionProducto(1);
        string infoProducto1Esperado = "1,manzana amarilla gra\xFA,250";

        // Assert - valide los resultados
        EXPECT_EQ(infoProducto1Actual, infoProducto1Esperado);
        delete tienda;
    }

    TEST(Tienda_Test, Test_ObtenerInformacionTienda) {

        ///AAA

        // Arrange - configiurar el escenario
        Tienda *tienda = new Tienda("Mi Tienda", "mitienda.com", "Avenida X Calle Y", "88888888");
        tienda->AgregarProducto(1, "manzana amarilla grande", 250);
        tienda->AgregarProducto(2, "manzana roja grande", 125);

        // Act - ejecute la operación
        string infoTiendaActual = tienda->ObtenerInformacionTienda();
        stringstream  strm("");
        strm << "Nombre: Mi Tienda" << endl 
             << "Página Web: mitienda.com" << endl 
             << "Dirección Física: Avenida X Calle Y" << endl 
             << "Teléfono: 88888888" << endl;
        string infoTiendaEsperada = strm.str();

        // Assert - valide los resultados
        EXPECT_EQ(infoTiendaActual, infoTiendaEsperada);
        delete tienda;
    }

    TEST(Tienda_Test, Test_ObtenerListaProductos) { // Esto también verifica que el método AgregarProducto funciona

        ///AAA

        // Arrange - configiurar el escenario
        Tienda *tienda = new Tienda("Mi Tienda", "mitienda.com", "Avenida X Calle Y", "88888888");
        tienda->AgregarProducto(1, "manzana amarilla", 250);
        tienda->AgregarProducto(2, "manzana roja", 125);
        tienda->AgregarProducto(3, "manzana verde", 75);

        // Act - ejecute la operación
        string listaProductosActual = tienda->ObtenerListaProductos();
        stringstream  strm("");
        strm << "ID,Nombre,Existencias" << endl 
             << "1,manzana amarilla,250" << endl 
             << "2,manzana roja,125" << endl 
             << "3,manzana verde,75" << endl;
        string listaProductorEsperada = strm.str();

        // Assert - valide los resultados
        EXPECT_EQ(listaProductosActual, listaProductorEsperada);
        delete tienda;
    }

    TEST(Tienda_Test, Test_EliminarProducto) { // Se verifica al obtener la lista de productos luego de usar el método para eliminar alguno

        ///AAA

        // Arrange - configiurar el escenario
        Tienda *tienda = new Tienda("Mi Tienda", "mitienda.com", "Avenida X Calle Y", "88888888");
        tienda->AgregarProducto(1, "manzana amarilla", 250);
        tienda->AgregarProducto(2, "manzana roja", 125);
        tienda->AgregarProducto(3, "manzana verde", 75);
        tienda->EliminarProducto(2);

        // Act - ejecute la operación
        string listaProductosActual = tienda->ObtenerListaProductos();
        stringstream  strm("");
        strm << "ID,Nombre,Existencias" << endl 
             << "1,manzana amarilla,250" << endl
             << "3,manzana verde,75" << endl;
        string listaProductorEsperada = strm.str();

        // Assert - valide los resultados
        EXPECT_EQ(listaProductosActual, listaProductorEsperada);
        delete tienda;
        
    }

    TEST(Tienda_Test, Test_ActualizarExistencias) { // Esto también verifica que el método ObtenerExistenciasProducto funciona

        ///AAA

        // Arrange - configiurar el escenario
        Tienda *tienda = new Tienda("Mi Tienda", "mitienda.com", "Avenida X Calle Y", "88888888");
        tienda->AgregarProducto(1, "manzana amarilla", 250);
        tienda->AgregarProducto(2, "manzana roja", 125);
        tienda->AgregarProducto(3, "manzana verde", 75);

        // Act - ejecute la operación
        tienda->ActualizarExistenciasProducto(2,150);
        int existenciasActual = tienda->ObtenerExistenciasProducto(2);
        int existenciasEsperado = 150;

        // Assert - valide los resultados
        EXPECT_EQ(existenciasActual, existenciasEsperado);
        delete tienda;
    }
}