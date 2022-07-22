#ifndef EXCEPCIONPRODUCTOINEXISTENTE_H
#define EXCEPCIONPRODUCTOINEXISTENTE_H

#include <string>
#include <exception>

using namespace std;

class ExcepcionProductoInexistente : public std::exception
{
    public:
    ExcepcionProductoInexistente() noexcept = default;
    ~ExcepcionProductoInexistente() = default;

    virtual const char* what() const noexcept {
        string mensajeError {};
        mensajeError = mensajeError + "El ID ingresado no corresponden a ningún producto.";
        const char* charMensaje = mensajeError.c_str();
        return charMensaje;
    }

};

#endif // EXCEPCIONPRODUCTOINEXISTENTE_H
