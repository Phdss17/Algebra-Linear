#ifndef MATRIZ_HPP
#define MATRIZ_HPP

#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class matriz{
private:
    int altura;
    int largura;
    vector<vector<T>> _matriz;
public:
    matriz(int altura, int largura);
    void show();
    void insert(T n, int x, int y);
    void remove(int x, int y);
};

template<typename T>
matriz<T>::matriz(int altura, int largura){
    this->altura = altura;
    this->largura = largura;
    this->_matriz = vector<vector<T>>(altura);
    for(int i = 0; i < altura; i++){
        this->_matriz[i] = vector<T>(largura);
    }
}

template<typename T>
void matriz<T>::show(){
   for(int i = 0; i < this->altura; i++){
     for(int j = 0; j < this->largura; j++){
        cout << this->_matriz[i][j] << " "; 
     }
     cout << endl;
   } 
}

template<typename T>
void matriz<T>::insert(T n, int x, int y){
    x -= 1;
    y -= 1;
    if(x >= this->altura || y >= this->largura || x < 0 || y < 0){
        cout << "Fail: Posição Invalida!" << endl;
    }else{
        this->_matriz[x][y] = n;
    }
}

template<typename T>
void matriz<T>::remove(int x, int y){
    x -= 1;
    y -= 1;
    if(x >= this->altura || y >= this->largura || x < 0 || y < 0){
        cout << "Fail: Posição Invalida!" << endl;
    }else{
        this->_matriz[x][y] = 0;
    }
}

#endif 