#include "tienda.h"

using namespace std;

int main() {
    Tienda *tienda1 = new Tienda("Mi Tienda", "mitienda.com", "Avenida X Calle Y", "1234567"); // ahora solo 7 digitos
    tienda1->AgregarProducto(1, "manzana amarilla", 250);
    tienda1->AgregarProducto(2, "manzana roja", 125);
    tienda1->AgregarProducto(3, "manzana verde", 75);
    tienda1->GuardarDatos("MiTienda");

    Tienda *tienda2 = new Tienda();
    tienda2->CargarDatos("MiTienda");

    cout << " ----- Tienda 1 -----" << endl;
    cout << tienda1;
    cout << endl;
    cout << " ----- Tienda 2 -----" << endl;
    cout << tienda2;
    cout << endl;
    cout << tienda2->ObtenerTelefono();

    return 0;
}