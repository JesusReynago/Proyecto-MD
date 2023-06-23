#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

// Función para convertir un número hexadecimal a binario
std::vector<int> hexadecimalABinario(int hexadecimal) {
    std::vector<int> binario;
    std::cout << "Para convertir el número hexadecimal " << std::hex << hexadecimal << " a binario, sigue estos pasos:" << std::endl;
    std::cout << "Divide el número hexadecimal " << std::hex << hexadecimal << " entre 2:" << std::endl;
    while (hexadecimal > 0) {
        int residuo = hexadecimal % 2;
        hexadecimal /= 2;
        std::cout << "División: " << std::hex << hexadecimal << " cociente, " << residuo << " residuo" << std::endl;
        binario.insert(binario.begin(), residuo);
    }
    std::cout << std::endl;
    return binario;
}

// Función para convertir un número binario a hexadecimal
int binarioAHexadecimal(const std::vector<int>& binario) {
    int hexadecimal = 0;
    int tamaño = binario.size();
    std::cout << "Para convertir el número binario ";
    for (int i = 0; i < tamaño; ++i) {
        std::cout << binario[i];
        if (i != tamaño - 1)
            std::cout << " ";
        hexadecimal += binario[i] * std::pow(2, tamaño - 1 - i);
    }
    std::cout << " a hexadecimal, sigue estos pasos:" << std::endl;

    std::cout << "Multiplica cada bit por la potencia correspondiente de 2:" << std::endl;
    for (int i = 0; i < tamaño; ++i) {
        std::cout << binario[i] << " * 2^" << tamaño - 1 - i;
        if (i != tamaño - 1)
            std::cout << " + ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
    return hexadecimal;
}

int main() {
    int opcion;

    while (true) {
        std::cout << "¡Bienvenido al convertidor hexadecimal-binario!" << std::endl;
        std::cout << "Por favor, seleccione una opción:" << std::endl;
        std::cout << "1. Convertir de hexadecimal a binario" << std::endl;
        std::cout << "2. Convertir de binario a hexadecimal" << std::endl;
        std::cout << "3. Salir" << std::endl;
        std::cout << "Opción: ";
        std::cin >> opcion;

        if (opcion == 1) {
            int hexadecimal;
            std::cout << "Introduzca el número hexadecimal que desea convertir: ";
            std::cin >> std::hex >> hexadecimal;
            std::vector<int> binario = hexadecimalABinario(hexadecimal);
            std::cout << "El número hexadecimal " << std::hex << hexadecimal << " en binario es: ";
            for (int i = 0; i < binario.size(); ++i) {
                std::cout << binario[i];
            }
            std::cout << std::endl;
        } else if (opcion == 2) {
            std::vector<int> binario;
            char bit;
            std::cout << "Introduzca el número binario que desea convertir (bits de izquierda a derecha): ";
            std::cin >> bit;
            while (bit != '\n') {
                binario.push_back(bit - '0');
                std::cin.get(bit);
            }
            int hexadecimal = binarioAHexadecimal(binario);
            std::cout << "El número binario ";
            for (int i = 0; i < binario.size(); ++i) {
                std::cout << binario[i];
            }
            std::cout << " en hexadecimal es: " << std::hex << hexadecimal << std::endl;
        } else if (opcion == 3) {
            break;
        } else {
            std::cout << "Opción inválida." << std::endl;
        }

        std::cout << std::endl;
    }

    return 0;
}
