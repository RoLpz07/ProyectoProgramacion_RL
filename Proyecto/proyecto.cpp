#include<iostream>
#include<fstream>
#include<sstream>
#include <algorithm>
#define Archivo "movies.csv"
using namespace std;
struct Movies
{
	string Id;
	string NameMovie;
	string Genero;
	string Duracion;
	string Director;
	string Precio;
	string Lanzamiento;
	string NombreRentador;
	string FechaRenta;
	string Estado;
}peliculas;

struct Pelicula {
    int id;
    string titulo;
    string genero;
    int duracion;
    string director;
    string fechaLanzamiento;
    float precio;
};


struct Usuario {
	string id;
    string cedula;
    string nombre;
    string apellido;
	string telefono;
};

void Mostrar()
{
	ifstream file(Archivo);
    string linea;
    char delimitador = ';'  ; 
	Movies movie;
    getline(file,linea);
    while (getline(file,linea))
    {
	    
        stringstream stream(linea);
        getline(stream, movie.Id, delimitador);
        getline(stream, movie.NameMovie, delimitador);
        getline(stream, movie.Genero, delimitador);
        getline(stream, movie.Duracion, delimitador);
        getline(stream, movie.Director, delimitador);
        getline(stream, movie.Precio, delimitador);
        getline(stream, movie.Lanzamiento, delimitador);
        getline(stream, movie.NombreRentador, delimitador);
        getline(stream, movie.FechaRenta, delimitador);
        getline(stream, movie.Estado, delimitador);
		
		
		cout<<"================================"<<endl;      
	    cout<<"Id: "<<movie.Id<<endl;
        cout<<"Nombre de la pelicula: "<<movie.NameMovie<<endl;
        cout<<"Genero: "<<movie.Genero<<endl;
        cout<<"Duracion: "<<movie.Duracion<<endl;
        cout<<"Director: "<<movie.Director<<endl;
        cout<<"Precio: "<<movie.Precio<<endl;
        cout<<"FechaLanzamiento: "<<movie.Lanzamiento<<endl;
        cout<<"Rentada a: "<<movie.NombreRentador<<endl;
        cout<<"Rentada el: "<<movie.FechaRenta<<endl;
        cout<<"Estado: "<<movie.Estado<<endl;
        	
	}
    file.close();

}
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

void crearUsuario(const std::string& archivo) {
    static int ultimoID = 0; // Variable estática para almacenar el último ID asignado
    Usuario usuario;

    // Incrementa el ID y asigna al usuario
    usuario.id = ++ultimoID;

    std::cout << "Ingrese la cedula: ";
    std::cin >> usuario.cedula;

    std::cout << "Ingrese el nombre: ";
    std::cin >> usuario.nombre;

    std::cout << "Ingrese el apellido: ";
    std::cin >> usuario.apellido;

    std::cout << "Ingrese el telefono: ";
    std::cin >> usuario.telefono;

    std::ofstream archivoCSV(archivo, std::ios::app); // Usa std::ios::app para agregar al final del archivo
    archivoCSV << usuario.id << "," << usuario.cedula << "," << usuario.nombre << "," << usuario.apellido << "," << usuario.telefono << std::endl;
    archivoCSV.close();
}
void borrarCuentaPorCedula(const std::string& archivo) {
    std::string cedula;

    // Solicita la cédula al usuario
    std::cout << "Ingrese la cedula del usuario que desea eliminar: ";
    std::cin >> cedula;

    std::ifstream inputFile(archivo);
    std::ofstream outputFile("temp.csv");

    // Lee cada línea del archivo
    std::string linea;
    while (std::getline(inputFile, linea)) {
        std::istringstream iss(linea);
        std::string cedulaUsuario;
        std::getline(iss, cedulaUsuario, ',');

        // Si la cédula del usuario es diferente a la cédula especificada, escribe la línea en el archivo temporal
        if (cedulaUsuario != cedula) {
            outputFile << linea << std::endl;
        }
    }

    inputFile.close();
    outputFile.close();

    // Reemplaza el archivo original con el archivo temporal
    std::remove(archivo.c_str());
    std::rename("temp.csv", archivo.c_str());
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

void create()
{
    // file pointer
    fstream fout;
    ifstream file(Archivo);
    string linea;
    fout.open(Archivo, ios::out | ios::app);
    int C=0;
    getline(file,linea);
    while (getline(file,linea))
    {
        C++;
    }
    int x;
	cout<<"Ingrese el numero de peliculas a agregar: "<<endl; cin>>x;
	cout<<'\n';

    for (int i = 0; i < x; i++)
    {
    
	cout << "Escriba los detalles de la pelicula "<<i+1 << endl;
	
	cout << "id: " <<endl ;
    cin >> peliculas.Id;
	cout << "nombre: "<<endl;
    cin >> peliculas.NameMovie;
    cout <<"Genero: "<< endl ;
    cin >> peliculas.Genero;
    cout << "Duracion: "<< endl;
    cin >> peliculas.Duracion;
    cout << "Director: "<< endl;
    cin >> peliculas.Director;
    cout << "Precio: "<<endl;
    cin >>peliculas.Precio;
    cout  << "Fecha de lanzamiento"<<endl;
    cin >> peliculas.Lanzamiento;
    
    
    
    
    
    
    cout << endl;
  
        // Insert the data to file
        fout << peliculas.Id << ";"
            << peliculas.NameMovie << ";"
            << peliculas.Genero << ";"
            << peliculas.Duracion << ";"
            << peliculas.Director << ";"
            << peliculas.Precio << ";"
			<< peliculas.Lanzamiento << ";"
            << "\n";
    }
    
    fout.close();
    file.close();
    
}



	// Funci�n para realizar consultas sobre el estado de renta de una pel�cula
void ConsultID()
{
		int contador;
    	char delimitador = ';';
    	Movies movie;
		string linea;
  		ifstream archivo(Archivo, ios::in);
    	string num_buscar;
    	

       
        
		
			
		cout<<"Ingrese id de la pelicula: "<<endl;
		cin>>num_buscar;
		
        
		
		bool existe = false;
        getline(archivo,linea);
        while (getline(archivo,linea))
        {
             
            stringstream stream(linea);
            
	        getline(stream, movie.Id, delimitador);
	        getline(stream, movie.NameMovie, delimitador);
	        getline(stream, movie.Genero, delimitador);
	        getline(stream, movie.Duracion, delimitador);
	        getline(stream, movie.Director, delimitador);
	        getline(stream, movie.Precio, delimitador);
	        getline(stream, movie.Lanzamiento, delimitador);
	        getline(stream, movie.NombreRentador, delimitador);
	        getline(stream, movie.FechaRenta, delimitador);
	        getline(stream, movie.Estado, delimitador);

            if(num_buscar.compare(movie.Id) == 0){
                existe = true;
            cout<<"================================"<<endl;      
	    	cout<<"Nombre de la pelicula: "<<movie.NameMovie<<endl;
        	if (movie.Estado == "RENTADA") {
            cout << "Estado: " << movie.Estado << " Por " << movie.NombreRentador << "." <<endl;
        	}
		 	else {
            cout << "Estado: " << "DISPONIBLE" <<endl;
        	}
               
                
           	 }
            else 
			{
				contador=1;
			}
       	}
		 if(contador==1 && existe==false)
		 {
		 	cout<<"PELICULA NO REGISTRADA"<<endl;
		 }  
       	
       	archivo.close();
		   }
		   
		   
       	 
void ConsultName()
{
	char delimitador = ';';
	int contador;
    	Movies movie;
		string linea;
  		ifstream archivo(Archivo, ios::in);
    	string nombre_buscar;
    	

       
        
		
			
		cout<<"Ingrese nombre de la pelicula: "<<endl;
		cin.ignore();// esto elimina los espacios en blaco para que se pueda ejecutar bien el getline
		getline(cin,nombre_buscar);// lee el nombre de la pelicula completo con espacios
		
        
		
		bool existe = false;
        getline(archivo,linea);
        while (getline(archivo,linea))
        {
             
            stringstream stream(linea);
            
	        getline(stream, movie.Id, delimitador);
	        getline(stream, movie.NameMovie, delimitador);
	        getline(stream, movie.Genero, delimitador);
	        getline(stream, movie.Duracion, delimitador);
	        getline(stream, movie.Director, delimitador);
	        getline(stream, movie.Precio, delimitador);
	        getline(stream, movie.Lanzamiento, delimitador);
	        getline(stream, movie.NombreRentador, delimitador);
	        getline(stream, movie.FechaRenta, delimitador);
	        getline(stream, movie.Estado, delimitador);

            if(nombre_buscar.compare(movie.NameMovie) == 0){
                existe = true;
            cout<<"================================"<<endl;
			cout<<"ID: "<<movie.Id<<endl;      
	    	cout<<"Nombre de la pelicula: "<<movie.NameMovie<<endl;
        	if (movie.Estado == "RENTADA") {
            cout << "Estado: " << movie.Estado << " Por " << movie.NombreRentador << "." <<endl;
        	}
		 	else {
            cout << "Estado: " << "DISPONIBLE" <<endl;
        	}
               
                
           	 }
           	 else
				{
				
			
				contador=1;
			
				}
           	 
            
       	}
       	
		if(contador==1 && existe==false)
		 {
		 	cout<<"PELICULA NO REGISTRADA"<<endl;
		 }   
       	
       	archivo.close();
		   }
void borrarPeliculaPorID(const std::string& archivo, const std::string& idPelicula) {
    std::ifstream inputFile(archivo);
    std::ofstream outputFile("temp.csv");
    std::string linea;
    while (std::getline(inputFile, linea)) {
        std::istringstream iss(linea);
        std::string id;
        std::getline(iss, id, ';');

        // Elimina los espacios en blanco adicionales alrededor del ID
        id.erase(std::remove_if(id.begin(), id.end(), [](unsigned char c) { return std::isspace(c); }), id.end());

        // Si el ID de la película es diferente al ID especificado, escribe la línea en el archivo temporal
        if (id != idPelicula) {
            outputFile << linea << std::endl;
        }
    }

    inputFile.close();
    outputFile.close();

    // Reemplaza el archivo original con el archivo temporal
    std::remove(archivo.c_str());
    std::rename("temp.csv", archivo.c_str());
}
int main()
{
	std::string nombreArchivo = "movies.csv";
    int tamano = 1000;
    std::string archivo = "Users.csv";

    //Tamaño del arreglo de películas 
    Pelicula* original = new Pelicula[tamano];
    Pelicula* filtradas = new Pelicula[tamano];

	int filtrador;
    int orden;
		std::string idPelicula;
        std::string genero;
        std::string director;
        std::string fechaLanzamiento;
		int i;
        float duracionMinima;
        float duracionMaxima;
        float precioMinimo;
        float precioMaximo;
	int k, p, y;
	leerArchivoCSV(Archivo, original, tamano);
	while(true)
	{
	
		
		
		
			cout << "Menu" << endl;
			cout << "(1) Mostrar peliculas" << endl;
			cout << "(2) Agregar peliculas" << endl;
			cout << "(3) Realizar consulta de estado de las peliculas"<<endl;
			cout << "(4) Filtrar y ordenar las peliculas"<< endl;
			cout << "(5) Crear usuario"<< endl;
			cout << "(6) Eliminar pelicula"<< endl;
			cout << "(7) Eliminar usuario"<< endl;
			cout << "(8) finalizar programa"<< endl;

		cin>>p;
		switch(p)
		{
			case 1:
				Mostrar();
				break;
			case 2:
				create();
				break;
			
			case 3:
				
				cout<<"Como desea buscar la pelicula:  "<<endl;
				cout<< "(1)ID "<<endl;
				cout<< "(2)Nombre "<<endl;
				
        		cin>>k;
				
				if(1==k)
				{
					ConsultID();
				}
				if(k==2)
				{
					ConsultName();
					
				}
				
				break;
				
			case 4:
				
				cout << "1. Filtrar por genero\n";
				cout << "2. Filtrar por duración\n";
				cout << "3. Filtrar por director\n";
				cout << "4. Filtrar por fecha de lanzamiento\n";
				cout << "5. Filtrar por precio\n";
				cin >> filtrador;

				cout << "1. Ordenar por precio\n";
				cout << "2. Ordenar por duracion\n";
				cout << "3. Ordenar por fecha de lanzamiento\n";
				cout << "4. Ordenar por ID\n";
				cin >> orden;

				switch (filtrador)
				{
				case 1:
					// Filtrar por género
					cout << "Ingrese el genero: ";
					cin >> genero;
					filtrarPorGenero(original, filtradas, tamano, genero);
					break;
				case 2:
					// Filtrar por duración
					cout << "Ingrese la duracion minima: ";
					cin >> duracionMinima;
					cout << "Ingrese la duracion maxima: ";
					cin >> duracionMaxima;
					filtrarPorDuracion(original, filtradas, tamano, duracionMinima, duracionMaxima);
					break;
				case 3:
					// Filtrar por dir
					cout << "Ingrese el director: ";
					cin >> director;
					filtrarPorDirector(original, filtradas, tamano, director);
					break;
				case 4:
					// Filtrar por fecha de lanzamiento
					cout << "Ingrese la fecha de lanzamiento (YYYY-MM-DD): ";
					cin >> fechaLanzamiento;
					filtrarPorFechaLanzamiento(original, filtradas, tamano, fechaLanzamiento);
					break;
				case 5:
					// Filtrar por precio
					cout << "Ingrese el precio minimo: ";
					cin >> precioMinimo;
					cout << "Ingrese el precio maximo: ";
					cin >> precioMaximo;
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
				for (i = 0; i < tamano; i++) {
					if (filtradas[i].id == 0) continue;
					imprimirPelicula(filtradas[i]);
				}
				break;
			case 5:
				crearUsuario(archivo);
				break;
			case 6:
				std::cout << "Ingrese el ID de la película que desea borrar: ";
    			std::cin >> idPelicula;

  				  borrarPeliculaPorID(nombreArchivo,idPelicula);
				break;
			case 7:
				borrarCuentaPorCedula("users.csv");
		
				break;
			case 8:
				cout<<""<<endl;
				cout<<"================================"<<endl;   
				cout<<"quieres seguir en el programa? "<<endl;cout<<"(1)Si "<<endl;cout<<"(2)No "<<endl;cin>>y;
				if(y==1)
				{
					cout<<""<<endl;
					cout<<"Genial... Sigamos XD"<<endl;
					cout<<"================================"<<endl;   
					
				}
				else if(y==2)
				{
					cout<<""<<endl;
					cout<<"================================"<<endl;   
					cout<<"Nos vemos "<<endl;
					exit(0);
				}
				else
				{
					cout<<""<<endl;
					cout<<"================================"<<endl;   
					cout<<"Opcion erronea, se cerrara el programa por defecto"<<endl;
					exit(0);	
				} 
				break;
			default:
				break;
			}
		}
	
	system("pause");
	return 0;
}

