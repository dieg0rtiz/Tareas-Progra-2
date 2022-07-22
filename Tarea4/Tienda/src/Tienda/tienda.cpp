#include "tienda.h"
#include "espacios.h"

using namespace std;

Tienda::Tienda() {

}

Tienda::Tienda(string nuevoNombre, string nuevaDireccionInternet, string nuevaDireccionFisica, string nuevoTelefono) {

    if (nuevoNombre.length()>= sizeof(this->nombre) ||
        nuevaDireccionInternet.length()>= sizeof(this->direccionInternet) ||
        nuevaDireccionFisica.length()>= sizeof(this->direccionFisica) ||
        nuevoTelefono.length()>= sizeof(this->telefono)
        )
    {
        // Escenario de excepción
        throw ExcepcionCantidadDeCaracteresTienda();
    }

    strncpy(this->nombre, nuevoNombre.c_str(),sizeof(this->nombre)-1);
    strncpy(this->direccionInternet, nuevaDireccionInternet.c_str(),sizeof(this->direccionInternet)-1);
    strncpy(this->direccionFisica, nuevaDireccionFisica.c_str(),sizeof(this->direccionFisica)-1);
    strncpy(this->telefono, nuevoTelefono.c_str(),sizeof(this->telefono)-1);
}

Tienda::~Tienda() {
    for (auto const& [id,producto] : this->indiceProductos) {
        delete producto;
    }
}

string Tienda::ObtenerNombre() {
    return this->nombre;
}

string Tienda::ObtenerDireccionFisica() {
    return this->direccionFisica;
}

string Tienda::ObtenerDireccionInternet() {
    return this->direccionInternet;
}

string Tienda::ObtenerTelefono() {
    return this->telefono;
}

void Tienda::ActualizarNombre(string nuevoNombre) {

    if (nuevoNombre.length()>= sizeof(this->nombre)) {
        // Escenario de excepción
        throw ExcepcionCantidadDeCaracteresTienda();
    }

    strncpy(this->nombre, nuevoNombre.c_str(),sizeof(this->nombre)-1);
}

void Tienda::ActualizarDireccionInternet(string nuevaDireccionInternet) {

    if (nuevaDireccionInternet.length()>= sizeof(this->direccionInternet)) {
        // Escenario de excepción
        throw ExcepcionCantidadDeCaracteresTienda();
    }

    strncpy(this->direccionInternet, nuevaDireccionInternet.c_str(),sizeof(this->direccionInternet)-1);
}

void Tienda::ActualizarDireccionFisica(string nuevaDireccionFisica) {

    if (nuevaDireccionFisica.length()>= sizeof(this->direccionFisica)) {
        // Escenario de excepción
        throw ExcepcionCantidadDeCaracteresTienda();
    }

    strncpy(this->direccionFisica, nuevaDireccionFisica.c_str(),sizeof(this->direccionFisica)-1);
}

void Tienda::ActualizarTelefono(string nuevoTelefono) {

    if (nuevoTelefono.length()>= sizeof(this->telefono)) {
        // Escenario de excepción
        throw ExcepcionCantidadDeCaracteresTienda();
    }

    strncpy(this->telefono, nuevoTelefono.c_str(),sizeof(this->telefono)-1);
}

void Tienda::AgregarProducto(int id, string nombre, int existencias) { 
    Producto *producto = new Producto(id, nombre, existencias);
    this->indiceProductos.insert( pair<int, Producto *>(producto->ObtenerID(), producto) );
}

void Tienda::AgregarProducto(Producto *producto) {
    this->indiceProductos.insert( pair<int, Producto *>(producto->ObtenerID(), producto) );
}

void Tienda::EliminarProducto(int id) {

    if (!this->VerificarProducto(id))
    {
        // Escenario de excepción
        throw ExcepcionProductoInexistente();
    }

    delete this->indiceProductos.at(id);
    this->indiceProductos.erase(id);
}

string Tienda::ObtenerInformacionProducto(int id) {

    if (!this->VerificarProducto(id))
    {
        // Escenario de excepción
        throw ExcepcionProductoInexistente();
    }

    return this->indiceProductos.at(id)->ObtenerInformacionProducto();
}

void Tienda::ActualizarExistenciasProducto(int id, int nuevaCantidad) {

    if (!this->VerificarProducto(id))
    {
        // Escenario de excepción
        throw ExcepcionProductoInexistente();
    }

    this->indiceProductos.at(id)->ActualizarExistencias(nuevaCantidad);
}

void Tienda::ActualizarNombreProducto(int id, string nuevoNombre) {

    if (!this->VerificarProducto(id))
    {
        // Escenario de excepción
        throw ExcepcionProductoInexistente();
    }

    this->indiceProductos.at(id)->ActualizarNombre(nuevoNombre);
}

string Tienda::ObtenerInformacionTienda() {
    stringstream strm("");

    strm << "Nombre: " << this->nombre << endl;
    strm << "Página Web: " << this->direccionInternet << endl;
    strm << "Dirección Física: " << this->direccionFisica << endl;
    strm << "Teléfono: " << this->telefono << endl;

    return strm.str();
}

string Tienda::ObtenerListaProductos() {
    stringstream strm("");

    strm << "ID            Nombre            Existencias" << endl;

    for (auto const& [id,producto] : this->indiceProductos) {
        strm << producto << endl;
    }

    return strm.str();
}

ostream& operator << (ostream &o, const Tienda *tienda) {

    o << "Nombre: " << tienda->nombre << endl;
    o << "Página Web: " << tienda->direccionInternet << endl;
    o << "Dirección Física: " << tienda->direccionFisica << endl;
    o << "Teléfono: " << tienda->telefono << endl;
    o << endl;
    o << "Lista de Productos: " <<  endl;
    o << "ID,Nombre,Existencias" << endl;

    for (auto const& [id,producto] : tienda->indiceProductos) {
        o << producto << endl;
    }

    return o;
}

int Tienda::ObtenerExistenciasProducto(int id) {
    return this->indiceProductos.at(id)->ObtenerExistencias();
}

int Tienda::GuardarDatos(string nombreArchivo) {

    ofstream archivoSalida;

    archivoSalida.open(nombreArchivo, ios::out|ios::binary);

    if (!archivoSalida.is_open()) {
        cerr << "No se pudo abrir archivo " + nombreArchivo + " para escribir los datos";
        return -1;
    }

    archivoSalida.write((char *) &this->nombre, sizeof(this->nombre));
    archivoSalida.write((char *) &this->direccionInternet, sizeof(this->direccionInternet));
    archivoSalida.write((char *) &this->direccionFisica, sizeof(this->direccionFisica));
    archivoSalida.write((char *) &this->telefono, sizeof(this->telefono));

    for (auto const& [id,producto] : this->indiceProductos) {
        archivoSalida.write((char *)producto, sizeof(Producto));
    }

    archivoSalida.close();

    return 0;
}

int Tienda::CargarDatos(string nombreArchivo) {

    ifstream archivoEntrada;

    archivoEntrada.open(nombreArchivo, ios::in|ios::binary);

    if (!archivoEntrada.is_open())
    {
        cerr << "No se pudo abrir archivo " + nombreArchivo + " para leer los datos";
        return -1;
    }

    archivoEntrada.seekg(0, std::ios::end);
    int cantidadBytesEnArchivo = archivoEntrada.tellg();
    int cantidadProductos = (cantidadBytesEnArchivo - 71) / sizeof(Producto);

    archivoEntrada.seekg(0, std::ios::beg);

    char nuevoNombre [sizeof(this->nombre)];
    archivoEntrada.read((char *)nuevoNombre,sizeof(this->nombre));
    this->ActualizarNombre(nuevoNombre);

    char nuevaDireccionInternet [sizeof(this->direccionInternet)];
    archivoEntrada.read(nuevaDireccionInternet,sizeof(this->direccionInternet));
    this->ActualizarDireccionInternet(nuevaDireccionInternet);

    char nuevaDireccionFisica [sizeof(this->direccionFisica)];
    archivoEntrada.read(nuevaDireccionFisica,sizeof(this->direccionFisica));
    this->ActualizarDireccionFisica(nuevaDireccionFisica);

    char nuevoTelefono [sizeof(this->telefono)];
    archivoEntrada.read(nuevoTelefono,sizeof(this->telefono));
    this->ActualizarTelefono(nuevoTelefono);

    for (int i=0; i < cantidadProductos; i++) {
        Producto *producto = new Producto();
        archivoEntrada.read((char *)producto, sizeof(Producto));
        this->AgregarProducto(producto);
    }

    archivoEntrada.close();

    return 0;
}

string Tienda::ObtenerDatosYProductos() {
    string datos {};
    datos += this->ObtenerInformacionTienda();
    datos += "\n\n";
    datos += this->ObtenerListaProductos();
    return datos;
}

bool Tienda::VerificarProducto(int idParaVerificar) {
    bool productoExiste = false;

    for (auto const& [id,producto] : this->indiceProductos) {
        if(idParaVerificar == id) {
            productoExiste = true;
            break;
        }
    }

    return productoExiste;
}
