#include <iostream>
#include <fstream>
#include <filesystem>
#include "windows.h"

void crearArchivos(int cantidad);
int contarArchivosDeDirectorio();
void listarArchivosDeDirectorio();
void mostrarDetalles();

using namespace std;

int main()
{
    int cantidad;

    cout << "Cuantos archivos quiere crear \n";
    cin >> cantidad;
    crearArchivos(cantidad);
    cout << contarArchivosDeDirectorio();
    cout << endl;
    listarArchivosDeDirectorio();
    mostrarDetalles();

    return 0;
}

void crearArchivos(int cantidad) {
    string nombreArchivo="archivo";
    int i= cantidad;
    for(i=0; i<cantidad; i++){
        ofstream file;
        file.open("C:\\Users\\cliente\\Desktop\\Implementacion\\" + nombreArchivo + to_string(i) +".txt");
        file << "Cursos del III Ciclo de Ingeniería en Sistemas\n";
        file << endl;
        file << "I. Cálculo I\n";
        file << "II. Programación I\n";
        file << "III. Derecho Informático\n";
        file << "IV. Física I\n";
        file << "V. Proceso Administrativo\n";
        file.close();
    }
    cout<<"Archivos creados : " + to_string(i);
}


void listarArchivosDeDirectorio(){
    WIN32_FIND_DATA findFileData;
    HANDLE          hFind;
    hFind = FindFirstFile("C:\\Users\\cliente\\Desktop\\Implementacion\\", &findFileData);

    if (hFind == INVALID_HANDLE_VALUE)
        cout << "Ruta incorrecta";
    else
    {
        cout << findFileData.cFileName << '\n'; //El primer archivo
        // Listamos todos los archivos

        while (FindNextFile(hFind, &findFileData) != 0)
            cout << findFileData.cFileName << '\n';
    }
}

int contarArchivosDeDirectorio(){
    WIN32_FIND_DATA findFileData;
    HANDLE          hFind;
    int cantidadDeArchivos=0;
    hFind = FindFirstFile("C:\\Users\\cliente\\Desktop\\Implementacion\\", &findFileData);

    if (hFind == INVALID_HANDLE_VALUE)
        cout << "Ruta incorrecta";
    else
        while (FindNextFile(hFind, &findFileData)!=0){
            cantidadDeArchivos=cantidadDeArchivos+1;
        }
    return cantidadDeArchivos-1;
}

void mostrarDetalles(){
    std::filesystem::directory_iterator directoryIterator("C:\\Users\\cliente\\Desktop\\Implementacion\\");
    for (const auto& entry : directoryIterator) {
        if (!std::filesystem::is_directory(entry.status())) {
            std::cout << entry.path().filename() << " "
                      << file_size(entry.path()) << std::endl;
        }
    }
}