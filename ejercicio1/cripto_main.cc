/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Miguel Díaz Dávila
 * @date 13/12/2020
 * @brief Encriptar y desencriptar con XOR o el MÉTODO CÉSAR.
 *        
 *        
 *
 */   
 ///exit

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>
#include <cstring>
#include "cripto.h"

int main(int argc, char *argv[]){
    if(argc != 6){
        std::cout << "./cripto -- Cifrado de ficheros" << std::endl;
        std::cout << "Modo de uso: ./cripto fichero_entrada fichero_salida método password operación" << std::endl;
        std::cout << "Pruebe ./cripto --help para más información" << std::endl;
    }
    if(argc == 2){
        std::string parametro{argv[1]};
        if(parametro == "--help"){
            std::cout << "./cripto -- Cifrado de ficheros" << std::endl;
            std::cout << "Modo de uso: ./cripto fichero_entrada fichero_salida método password operación" << std::endl;
            std::cout << "fichero_entrada: Fichero a codificar" << std::endl;
            std::cout << "fichero_salida:  Fichero codificado" << std::endl;
            std::cout << "método:          Indica el método de encriptado" << std::endl;
            std::cout << "                   1: Cifrado xor " << std::endl;
            std::cout << "                   2: Cifrado de César" << std::endl;
            std::cout << "password:        Palabra secreta en el caso de método 1, Valor de K en el método 2" << std::endl;
            std::cout << "operación:       Operación a realizar en el fichero" << std::endl;
            std::cout << "                   +: encriptar el fichero" << std::endl;
            std::cout << "                   -: desencriptar el fichero" << std::endl;
        }
    }
    
    std::string input = argv[1];
    std::string output = argv[2];
    std::ifstream texto (input.c_str()); 
    std::ofstream nuevo_texto (output.c_str());
    unsigned metodo = atoi(argv[3]);
    std::string operacion = argv[5]; 
    std::string newline;
    std::string file_lines;
    
    if(metodo == 1){  
        std::string pass = argv[4];
        newline = XOR(file_lines,pass); 
        newline.pop_back();
    
        if(operacion=="+"){
            std::cout<<"Encriptado en método XOR: "<<argv[2]<<std::endl;
            nuevo_texto<<newline;
        }
        if(operacion=="-"){
            std::cout<<"Desencriptado en método XOR: "<<argv[2]<<std::endl;
            nuevo_texto<<newline;
        }
    }
    
    if(metodo == 2){  
        newline = cesar(file_lines,argv);
        newline.pop_back();
        nuevo_texto<<newline;
    
        if(operacion == "+"){
            std::cout<<"Encriptado en método César: "<<argv[2]<<std::endl;
        }
        if(operacion == "-"){
            std::cout<<"Desencriptado en método César: "<<argv[2]<<std::endl;
        }
    }
  
}