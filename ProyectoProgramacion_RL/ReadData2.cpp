#include <iostream>
#include <fstream>
#include <string>

struct Pelicula {
    int id;
    std::string titulo;
    std::string genero;
    int duracion;
    std::string director;
    std::string estado;
};

void leerArchivoCSV(const std::string& movies) {
    std::ifstream archivo(movies);
    if (!archivo.is_open()) {
        std::cout << "No se pudo abrir el archivo CSV." << std::endl;
        return;
    }

    std::string linea;
    std::getline(archivo, linea); // Ignorar la primera línea de encabezado

    while (std::getline(archivo, linea)) {
        std::string valor;
        std::size_t delimiterPos;

        // Leer el ID
        delimiterPos = linea.find(';');
        valor = linea.substr(0, delimiterPos);
        int id = std::stoi(valor);
        linea.erase(0, delimiterPos + 1);

        // Leer el título
        delimiterPos = linea.find(';');
        valor = linea.substr(0, delimiterPos);
        std::string titulo = valor;
        linea.erase(0, delimiterPos + 1);

        // Leer el género
        delimiterPos = linea.find(';');
        valor = linea.substr(0, delimiterPos);
        std::string genero = valor;
        linea.erase(0, delimiterPos + 1);

        // Leer la duración
        delimiterPos = linea.find(';');
        valor = linea.substr(0, delimiterPos);
        int duracion = std::stoi(valor);
        linea.erase(0, delimiterPos + 1);

        // Leer el director
        delimiterPos = linea.find(';');
        valor = linea.substr(0, delimiterPos);
        std::string director = valor;
        linea.erase(0, delimiterPos + 1);

        // Leer el estado
        std::string estado = linea;

        // Realizar cualquier operación con los valores leídos
        // Por ejemplo, puedes imprimirlos en la consola
        std::cout << "Pelicula:" << std::endl;
        std::cout << "ID: " << id << std::endl;
        std::cout << "Título: " << titulo << std::endl;
        std::cout << "Género: " << genero << std::endl;
        std::cout << "Duración: " << duracion << std::endl;
        std::cout << "Director: " << director << std::endl;
        std::cout << "Estado: " << estado << std::endl;
        std::cout << std::endl;
    }
    archivo.close();
}

int main() {
    std::string nombreArchivo = "movies.csv";
    leerArchivoCSV(nombreArchivo);

    system("pause");
    return 0;
}