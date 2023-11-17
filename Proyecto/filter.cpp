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
void leerArchivoCSV(const std::string& nombreArchivo, Pelicula*& original, int& tamano) {
    std::ifstream archivo(nombreArchivo);
    std::string linea;
    std::getline(archivo, linea); // Ignorar la primera línea de encabezado

    int i = 0;
    while (std::getline(archivo, linea)) {
        if (i >= tamano) {
            // Si se alcanza el tamaño máximo, se duplica el tamaño del arreglo
            int nuevoTamano = tamano * 2;
            Pelicula* nuevasPeliculas = new Pelicula[nuevoTamano];

            // Se copian las películas existentes al nuevo arreglo
            for (int j = 0; j < tamano; j++) {
                nuevasPeliculas[j] = original[j];
            }

            delete[] original;

            original = nuevasPeliculas;
            tamano = nuevoTamano;
        }

        std::istringstream ss(linea);
        std::string campo;

        std::getline(ss, campo, ';');
        original[i].id = std::stoi(campo);

        std::getline(ss, original[i].titulo, ';');

        std::getline(ss, original[i].genero, ';');

        std::getline(ss, campo, ';');
        original[i].duracion = std::stoi(campo);

        std::getline(ss, original[i].director, ';');

        std::getline(ss, original[i].fechaLanzamiento, ';');

        std::getline(ss, campo);
        original[i].precio = std::stof(campo);

        i++;
    }

    archivo.close();
}

void imprimirPelicula(Pelicula pelicula) {
    std::cout << "ID: " << pelicula.id << std::endl;
    std::cout << "Titulo: " << pelicula.titulo << std::endl;
    std::cout << "Genero: " << pelicula.genero << std::endl;
    std::cout << "Duracion: " << pelicula.duracion << std::endl;
    std::cout << "Director: " << pelicula.director << std::endl;
    std::cout << "Precio: " << pelicula.precio << std::endl;
    std::cout << "Fecha de lanzamiento: " << pelicula.fechaLanzamiento << std::endl;
    std::cout << "-------------------------" << std::endl;
}

// Función para filtrar las películas por género
void filtrarPorGenero(Pelicula* original, Pelicula* objetivo, int tamano, const std::string& genero) {
    int contador = 0;
    std::cout << std::endl;

    for (int i = 0; i < tamano; i++) {
        if (original[i].genero == "(no genres listed)") continue;
        size_t encontrado = original[i].genero.find(genero);
        if (encontrado != std::string::npos) {
            objetivo[contador] = original[i];
            contador++;
            continue;
        }
    }
}

// Función para filtrar las películas por duración
void filtrarPorDuracion(Pelicula* original, Pelicula* objetivo, int tamano, int duracionMinima, int duracionMaxima) {
    int contador = 0;
    for (int i = 0; i < tamano; i++) {
        if (original[i].duracion >= duracionMinima && original[i].duracion <= duracionMaxima) {
            objetivo[contador] = original[i];
            contador++;
        }
    }
}

// Función para filtrar las películas por director
void filtrarPorDirector(Pelicula* original, Pelicula* objetivo, int tamano, const std::string& director) {
    int contador = 0;
    for (int i = 0; i < tamano; i++) {
        if (original[i].director == director) {
            objetivo[contador] = original[i];
            contador++;
        }
    }
}

// Función para filtrar las películas por fecha de lanzamiento
void filtrarPorFechaLanzamiento(Pelicula* original, Pelicula* objetivo, int tamano, const std::string& fechaLanzamiento) {
    int contador = 0;
    for (int i = 0; i < tamano; i++) {
        if (original[i].fechaLanzamiento < fechaLanzamiento) { 
            objetivo[contador] = original[i];
            contador++;
        }
    }
}

// Función para filtrar las películas por precio
void filtrarPorPrecio(Pelicula* original, Pelicula* objetivo, int tamano, float precioMinimo, float precioMaximo) {
    int contador = 0;
    for (int i = 0; i < tamano; i++) {
        if (original[i].precio >= precioMinimo && original[i].precio <= precioMaximo) {
            objetivo[contador] = original[i];
            contador++;
        }
    }
}

// Función para ordenar las películas por ID
void ordenarPorID(Pelicula* original, int tamano) {
    std::sort(original, original + tamano, [](const Pelicula& pelicula1, const Pelicula& pelicula2) {
        return pelicula1.id < pelicula2.id; });
}

void ordenarPorDuracion(Pelicula* original, int tamano) {
    std::sort(original, original + tamano, [](const Pelicula& pelicula1, const Pelicula& pelicula2) {
        return pelicula1.duracion < pelicula2.duracion; });
}
void ordenarPorPrecio(Pelicula* original, int tamano) {
    std::sort(original, original + tamano, [](const Pelicula& pelicula1, const Pelicula& pelicula2) {
        return pelicula1.precio < pelicula2.precio; });
}
void ordenarPorFechaLanzamiento(Pelicula* original, int tamano) {
    std::sort(original, original + tamano, [](const Pelicula& pelicula1, const Pelicula& pelicula2) {
        return pelicula1.fechaLanzamiento < pelicula2.fechaLanzamiento; });
}

int main() {
    std::string nombreArchivo = "movies.csv";
    int tamano = 1000;

    //Tamaño del arreglo de películas 
    Pelicula* original = new Pelicula[tamano];
    Pelicula* filtradas = new Pelicula[tamano];

    // Leer las películas desde el archivo CSV
    leerArchivoCSV(nombreArchivo, original, tamano);

    int filtrador;
    std::cout << "1. Filtrar por genero\n";
    std::cout << "2. Filtrar por duración\n";
    std::cout << "3. Filtrar por director\n";
    std::cout << "4. Filtrar por fecha de lanzamiento\n";
    std::cout << "5. Filtrar por precio\n";
    std::cin >> filtrador;

    int orden;
    std::cout << "1. Ordenar por precio\n";
    std::cout << "2. Ordenar por duracion\n";
    std::cout << "3. Ordenar por fecha de lanzamiento\n";
    std::cout << "4. Ordenar por ID\n";

    std::cin >> orden;

    std::string genero;
    std::string director;
    std::string fechaLanzamiento;

    float duracionMinima;
    float duracionMaxima;
    float precioMinimo;
    float precioMaximo;

    switch (filtrador)
    {
    case 1:
        // Filtrar por género
        std::cout << "Ingrese el genero: ";
        std::cin >> genero;
        filtrarPorGenero(original, filtradas, tamano, genero);
        break;
    case 2:
        // Filtrar por duración
        std::cout << "Ingrese la duracion minima: ";
        std::cin >> duracionMinima;
        std::cout << "Ingrese la duracion maxima: ";
        std::cin >> duracionMaxima;
        filtrarPorDuracion(original, filtradas, tamano, duracionMinima, duracionMaxima);
        break;
    case 3:
        // Filtrar por director
        std::cout << "Ingrese el director: ";
        std::cin >> director;
        filtrarPorDirector(original, filtradas, tamano, director);
        break;
    case 4:
        // Filtrar por fecha de lanzamiento
        std::cout << "Ingrese la fecha de lanzamiento (YYYY-MM-DD): ";
        std::cin >> fechaLanzamiento;
        filtrarPorFechaLanzamiento(original, filtradas, tamano, fechaLanzamiento);
        break;
    case 5:
        // Filtrar por precio
        std::cout << "Ingrese el precio minimo: ";
        std::cin >> precioMinimo;
        std::cout << "Ingrese el precio maximo: ";
        std::cin >> precioMaximo;
        filtrarPorPrecio(original, filtradas, tamano, precioMinimo, precioMaximo);
        break;
    default:
        break;
    }
    switch (orden)
    {
    case 1:
        // Ordenar por precio
        ordenarPorPrecio(filtradas, tamano);
        break;
    case 2:
        // Ordenar por duración
        ordenarPorDuracion(filtradas, tamano);
        break;
    case 3:
        // Ordenar por fecha de lanzamiento
        ordenarPorFechaLanzamiento(filtradas, tamano);
        break;
    case 4:
        // Ordenar por ID
        ordenarPorID(filtradas, tamano);
        break;
    default:
        break;
        
    }
    // Imprimir las películas filtradas y ordenadas
    for (int i = 0; i < tamano; i++) {
        if (filtradas[i].id == 0) continue;
        imprimirPelicula(filtradas[i]);
    }
    
    delete[] original;
    delete[] filtradas;
    
    system("pause");
    return 0;
}