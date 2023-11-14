#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

struct Pelicula {
    int id;
    std::string titulo;
    std::string genero;
    int duracion;
    std::string director;
    std::string fechaLanzamiento;
    float precio;
};

// Función para leer las películas desde un archivo CSV
void leerArchivoCSV(const std::string& nombreArchivo, Pelicula* peliculas, int tamano) {
    std::ifstream archivo(nombreArchivo);
    std::string linea;

    for (int i = 0; i < tamano; i++) {
        std::getline(archivo, linea);
        std::istringstream ss(linea);
        std::string campo;

        std::getline(ss, campo, ',');
        peliculas[i].id = std::stoi(campo);

        std::getline(ss, peliculas[i].titulo, ',');

        std::getline(ss, peliculas[i].genero, ',');

        std::getline(ss, campo, ',');
        peliculas[i].duracion = std::stoi(campo);

        std::getline(ss, peliculas[i].director, ',');

        std::getline(ss, peliculas[i].fechaLanzamiento, ',');

        std::getline(ss, campo);
        peliculas[i].precio = std::stof(campo);
    }

    archivo.close();
}

// Función para filtrar las películas por género
void filtrarPorGenero(Pelicula* peliculas, int tamano, const std::string& genero) {
    for (int i = 0; i < tamano; i++) {
        if (peliculas[i].genero == genero) {
        }
    }
}

// Función para filtrar las películas por duración
void filtrarPorDuracion(Pelicula* peliculas, int tamano, int duracionMinima, int duracionMaxima) {
    for (int i = 0; i < tamano; i++) {
        if (peliculas[i].duracion >= duracionMinima && peliculas[i].duracion <= duracionMaxima) {
        }
    }
}

// Función para filtrar las películas por director
void filtrarPorDirector(Pelicula* peliculas, int tamano, const std::string& director) {
    for (int i = 0; i < tamano; i++) {
        if (peliculas[i].director == director) {
        }
    }
}

// Función para filtrar las películas por fecha de lanzamiento
void filtrarPorFechaLanzamiento(Pelicula* peliculas, int tamano, const std::string& fechaLanzamiento) {
    for (int i = 0; i < tamano; i++) {
        if (peliculas[i].fechaLanzamiento < fechaLanzamiento) {
        }
    }
}

// Función para filtrar las películas por precio
void filtrarPorPrecio(Pelicula* peliculas, int tamano, float precioMinimo, float precioMaximo) {
    for (int i = 0; i < tamano; i++) {
        if (peliculas[i].precio >= precioMinimo && peliculas[i].precio <= precioMaximo) {
        }
    }
}
// Función para ordenar las películas por precio 
void ordenarPorPrecio(Pelicula* peliculas, int tamano) { 
    std::sort(peliculas, peliculas + tamano, [](const Pelicula& pelicula1, const Pelicula& pelicula2) { 
        return pelicula1.precio < pelicula2.precio; }); 
}
// Función para ordenar las películas por duración
void ordenarPorDuracion(Pelicula* peliculas, int tamano) {
    std::sort(peliculas, peliculas + tamano, [](const Pelicula& pelicula1, const Pelicula& pelicula2) {
        return pelicula1.duracion < pelicula2.duracion; });
}
// Función para ordenar las películas por fecha de lanzamiento
void ordenarPorFechaLanzamiento(Pelicula* peliculas, int tamano) {
    std::sort(peliculas, peliculas + tamano, [](const Pelicula& pelicula1, const Pelicula& pelicula2) {
        return pelicula1.fechaLanzamiento < pelicula2.fechaLanzamiento; });
}
// Función para ordenar las películas por ID
void ordenarPorID(Pelicula* peliculas, int tamano) {
    std::sort(peliculas, peliculas + tamano, [](const Pelicula& pelicula1, const Pelicula& pelicula2) {
        return pelicula1.id < pelicula2.id; });
}

int main() {
    std::string nombreArchivo = "movies.csv";
    int tamano = 10;

    //Tamaño del arreglo de películas 
    Pelicula* peliculas = new Pelicula[tamano];

    // Leer las películas desde el archivo CSV
    leerArchivoCSV(nombreArchivo, peliculas, tamano);

    int filtrador;
    std::cout << "1. Filtrar por genero\n";
    std::cout << "2. Filtrar por duración\n";
    std::cout << "3. Filtrar por director\n";
    std::cout << "4. Filtrar por fecha de lanzamiento\n";
    std::cout << "5. Filtrar por precio\n";
    std::cin >> filtrador;
    switch (filtrador)
    {
    case 1:
        // Filtrar por género
        std::cout << "Ingrese el genero: ";
        std::string genero;
        std::cin >> genero;
        filtrarPorGenero(peliculas, tamano, genero);
        break;
    case 2:
        // Filtrar por duración
        std::cout << "Ingrese la duracion minima: ";
        int duracionMinima;
        std::cin >> duracionMinima;
        std::cout << "Ingrese la duracion maxima: ";
        int duracionMaxima;
        std::cin >> duracionMaxima;
        filtrarPorDuracion(peliculas, tamano, duracionMinima, duracionMaxima);
        break;
    case 3:
        // Filtrar por director
        std::cout << "Ingrese el director: ";
        std::string director;
        std::cin >> director;
        filtrarPorDirector(peliculas, tamano, director);
        break;
    case 4:
        // Filtrar por fecha de lanzamiento
        std::cout << "Ingrese la fecha de lanzamiento (YYYY-MM-DD): ";
        std::string fechaLanzamiento;
        std::cin >> fechaLanzamiento;
        filtrarPorFechaLanzamiento(peliculas, tamano, fechaLanzamiento);
        break;
    case 5:
        // Filtrar por precio
        std::cout << "Ingrese el precio minimo: ";
        float precioMinimo;
        std::cin >> precioMinimo;
        std::cout << "Ingrese el precio maximo: ";
        float precioMaximo;
        std::cin >> precioMaximo;
        filtrarPorPrecio(peliculas, tamano, precioMinimo, precioMaximo);
        break;
    default:
        break;
    }
    int orden;
    std::cout << "1. Ordenar por precio\n";
    std::cout << "2. Ordenar por duracion\n";
    std::cout << "3. Ordenar por fecha de lanzamiento\n";
    std::cout << "4. Ordenar por ID\n";
    std::cin >> orden;
    switch (orden)
    {
    case 1:
        // Ordenar por precio
        ordenarPorPrecio(peliculas, tamano);
        break;
    case 2:
        // Ordenar por duración
        ordenarPorDuracion(peliculas, tamano);
        break;
    case 3:
        // Ordenar por fecha de lanzamiento
        ordenarPorFechaLanzamiento(peliculas, tamano);
        break;
    case 4:
        // Ordenar por ID
        ordenarPorID(peliculas, tamano);
        break;
    default:
        break;
        
    }
    // Imprimir las películas filtradas y ordenadas
    for (int i = 0; i < tamano; i++) {
        std::cout << "ID: " << peliculas[i].id << std::endl;
        std::cout << "Titulo: " << peliculas[i].titulo << std::endl;
        std::cout << "Genero: " << peliculas[i].genero << std::endl;
        std::cout << "Duracion: " << peliculas[i].duracion << std::endl;
        std::cout << "Director: " << peliculas[i].director << std::endl;
        std::cout << "Precio: " << peliculas[i].precio << std::endl;
        std::cout << "Fecha de lanzamiento: " << peliculas[i].fechaLanzamiento << std::endl;
        std::cout << "-------------------------" << std::endl;
        std::cout << std::endl;
    }
    
    delete[] peliculas;
    
    system("pause");
    return 0;
}