#ifndef MATRIZ_HPP
#define MATRIZ_HPP

#include <iostream>
#include <vector>
#include <exception>

using namespace std;

template<typename T>
class matriz{
private:
    int altura;
    int largura;
    vector<vector<T>> _matriz;
public:
    matriz(int altura, int largura);

    template<typename U>
    friend ostream& operator<<(ostream& os, const matriz<U>& m);

    void insert(T n, int x, int y);
    void remove(int x, int y);

    int getHigh();
    int getLength();
    
    matriz<T> operator+(matriz<T> m);
    matriz<T> operator-(matriz<T> m);

    matriz<T> operator*(int n);
    matriz<T> operator*(matriz<T> m);
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

template<typename U>
ostream& operator<<(ostream& os, const matriz<U>& m){
   for(int i = 0; i < m.altura; i++){
     for(int j = 0; j < m.largura; j++){
        os << m._matriz[i][j] << " "; 
     }
     os << endl;
   } 
   return os;
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

template<typename T>
int matriz<T>::getHigh(){
    return altura;
}

template<typename T>
int matriz<T>::getLength(){
    return largura;
}

template<typename T>
matriz<T> matriz<T>::operator+(matriz<T> m){
    if(this->getHigh() != m.getHigh() || this->getLength() != m.getLength()){
        throw "Fail: Não é póssivel multiplicar";
    }

    matriz<T> new_m(m.getHigh(), this->getLength());
    for(int i = 0; i < this->altura; i++){
        for(int j = 0; j < this->largura; j++){
            new_m._matriz[i][j] = m._matriz[i][j] + this->_matriz[i][j];
        }
    }
    return new_m;
}

template<typename T>
matriz<T> matriz<T>::operator-(matriz<T> m){
    if(this->getHigh() != m.getHigh() || this->getLength() != m.getLength()){
        throw "Fail: Não é póssivel multiplicar";
    }

    matriz<T> new_m(m.getHigh(), this->getLength());
    for(int i = 0; i < this->altura; i++){
        for(int j = 0; j < this->largura; j++){
            new_m._matriz[i][j] = m._matriz[i][j] - this->_matriz[i][j];
        }
    }
    return new_m;
}

template<typename T>
matriz<T> matriz<T>::operator*(int n){
    matriz<T> new_m(this->getHigh(), this->getLength());
    for(int i = 0; i < this->altura; i++){
        for(int j = 0; j < this->largura; j++){
            new_m._matriz[i][j] = this->_matriz[i][j] * n;
        }
    }
    return new_m;
}

template<typename T>
matriz<T> matriz<T>::operator*(matriz<T>  m){
    if(this->getLength() != m.getHigh()){
        throw "Fail: Não é póssivel multiplicar";
    }
    matriz<T> new_m(this->getHigh(), m.getLength());

    for(int i=0; i < this->altura; i++){
		for(int j=0; j < m.getLength(); j++){
			for(int k=0; k < this->largura; k++){
                new_m._matriz[i][j] += this->_matriz[i][k] * m._matriz[k][j];  
		    }
		}
	}

    return new_m;
}

#endif    