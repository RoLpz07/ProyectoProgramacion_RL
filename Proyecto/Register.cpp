#include <iostream>
#include <fstream>
#include <string>

struct Usuario {
    std::string cedula;
    std::string nombre;
    std::string apellido;
};

void crearUsuario(const std::string& archivo) {
    Usuario usuario;

    std::cout << "Ingrese la cedula: ";
    std::cin >> usuario.cedula;

    std::cout << "Ingrese el nombre: ";
    std::cin >> usuario.nombre;

    std::cout << "Ingrese el apellido: ";
    std::cin >> usuario.apellido;

    std::ofstream archivoCSV(archivo, std::ios::app);
    archivoCSV << usuario.cedula << "," << usuario.nombre << "," << usuario.apellido << std::endl;
    archivoCSV.close();
}

int main() {
    std::string archivo = "Users.csv";
    crearUsuario(archivo);

    return 0;
}