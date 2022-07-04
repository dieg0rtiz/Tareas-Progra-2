#ifndef ExcepcionCantidadDeCaracteresTienda_H
#define ExcepcionCantidadDeCaracteresTienda_H

#include <string>
#include <exception>

using namespace std;

class ExcepcionCantidadDeCaracteresTienda : public std::exception
{
    public:
    ExcepcionCantidadDeCaracteresTienda() noexcept = default;
    ~ExcepcionCantidadDeCaracteresTienda() = default;

    virtual const char* what() const noexcept {
        string mensajeError {};
        mensajeError = mensajeError + "La cantidad de caracteres permitida ha sido excedida. \n" +
                                      "Para el nombre de la tienda permiten máximo 16 caracteres. \n" +
                                      "Para la dirección de internet permiten máximo 24 caracteres. \n" +
                                      "Para la dirección física permiten máximo 24 caracteres. \n" +
                                      "Para el número de teléfono permiten máximo 8 caracteres. \n";

        return mensajeError.c_str();
    }

};

#endif