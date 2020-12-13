#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cstring>
#include "cripto.h"
std::string cesar(std::string texto_a_codificar, char* argv[]){
    std::string palabra = texto_a_codificar;
    int largo = palabra.length();
    std::string opereacion = argv[5];
    char letra;
    int clave = std::stoi(argv[4]);
    std::string operacion= argv[5];
    std::string palabra_cripto=palabra;
    if (operacion=="+"){  
        for(int i=0;i<=largo;i++){
            letra=palabra[i];
            letra=static_cast<char>(letra+clave);
            palabra_cripto[i]= letra;
        }   
        return palabra_cripto;
    }
    if(operacion=="-"){
        for(int i=0;i<=largo;i++){
            letra=palabra[i];
            letra=static_cast<char>(letra-clave);
            palabra_cripto[i]= letra;
        }
        return palabra_cripto;
    }

    if(operacion !="-" || operacion != "+"){
        std::cout<<"Error"<<std::endl;
        std::cout<<"Debe introducir un "+" o un "-" " << std::endl;
        return 0;
    }
}

std::string XOR(std::string opcion_xor,std::string pass){ 
    std::string texto = opcion_xor;
    std::string texto_encriptado;
    std::string clave = pass;
    int contador = 0;
    unsigned char letra_xor;
    for (auto &element: clave){
        element ^= 128;
    }
    for (int i = 0; i < texto.length(); i++){
        letra_xor = texto[i] ^ clave[contador];
        texto_encriptado += letra_xor;
        contador++;
    }
    if(contador >= clave.length()){
    contador = 0;
    }

    return texto_encriptado;
}