#include "tienda.h"

using namespace std;

Tienda::Tienda() {

}

Tienda::Tienda(string nuevoNombre, string nuevaDireccionInternet, string nuevaDireccionFisica, string nuevoTelefono) {
    strcpy(this->nombre, nuevoNombre.c_str());
    strcpy(this->direccionInternet, nuevaDireccionInternet.c_str());
    strcpy(this->direccionFisica, nuevaDireccionFisica.c_str());
    strcpy(this->telefono, nuevoTelefono.c_str());
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
    strcpy(this->nombre, nuevoNombre.c_str());
}

void Tienda::ActualizarDireccionInternet(string nuevaDireccionInternet) {
    strcpy(this->direccionInternet, nuevaDireccionInternet.c_str());
}

void Tienda::ActualizarDireccionFisica(string nuevaDireccionFisica) {
    strcpy(this->direccionFisica, nuevaDireccionFisica.c_str());
}

void Tienda::ActualizarTelefono(string nuevoTelefono) {
    strcpy(this->telefono, nuevoTelefono.c_str());
}

void Tienda::AgregarProducto(int id, string nombre, int existencias) {
    Producto *producto = new Producto(id, nombre, existencias);
    this->indiceProductos.insert( pair<int, Producto *>(producto->ObtenerID(), producto) );
}

void Tienda::AgregarProducto(Producto *producto) {
    this->indiceProductos.insert( pair<int, Producto *>(producto->ObtenerID(), producto) );
}

void Tienda::EliminarProducto(int id) {
    delete this->indiceProductos.at(id);
    this->indiceProductos.erase(id);
}

string Tienda::ObtenerInformacionProducto(int id) {
    return this->indiceProductos.at(id)->ObtenerInformacionProducto();
}

void Tienda::ActualizarExistenciasProducto(int id, int nuevaCantidad) {
    this->indiceProductos.at(id)->ActualizarExistencias(nuevaCantidad);
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

    strm << "ID,Nombre,Existencias" << endl;

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

    string nombreArchivoExtension = nombreArchivo + ".dat";
    ofstream archivoSalida;
    
    archivoSalida.open(nombreArchivoExtension, ios::out|ios::binary);

    if (!archivoSalida.is_open()) {
        cerr << "No se pudo abrir archivo " + nombreArchivoExtension + " para escribir los datos";
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
    
    string nombreArchivoExtension = nombreArchivo + ".dat";
    ifstream archivoEntrada;

    archivoEntrada.open(nombreArchivoExtension, ios::in|ios::binary);

    if (!archivoEntrada.is_open())
    {
        cerr << "No se pudo abrir archivo " + nombreArchivoExtension + " para leer los datos";
        return -1;
    }

    archivoEntrada.seekg(0, std::ios::end);
    int cantidadBytesEnArchivo = archivoEntrada.tellg();
    int cantidadProductos = (cantidadBytesEnArchivo - 71) / sizeof(Producto);

    archivoEntrada.seekg(0, std::ios::beg);

    char nuevoNombre [15];
    archivoEntrada.read((char *)nuevoNombre,15);
    this->ActualizarNombre(nuevoNombre);

    char nuevaDireccionInternet [24];
    archivoEntrada.read(nuevaDireccionInternet,24);
    this->ActualizarDireccionInternet(nuevaDireccionInternet);

    char nuevaDireccionFisica [24];
    archivoEntrada.read(nuevaDireccionFisica,24);
    this->ActualizarDireccionFisica(nuevaDireccionFisica);

    char nuevoTelefono [8];
    archivoEntrada.read(nuevoTelefono,8);
    this->ActualizarTelefono(nuevoTelefono);

    for (int i=0; i < cantidadProductos; i++) {
        Producto *producto = new Producto();
        archivoEntrada.read((char *)producto, sizeof(Producto));
        this->AgregarProducto(producto);
    }

    archivoEntrada.close();

    return 0;
}