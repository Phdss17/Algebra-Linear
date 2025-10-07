#include <iostream>
#include <vector>
#include "matriz.hpp"

using namespace std;

int main(){
    vector<matriz<int>> matrizes;

    cout << "O que quer fazer?" << endl;
    while(true){
        string arg;
        cin >> arg;

        if(arg == "end"){
            cout << "Adeus!" << endl;
            break;
        }else if(arg == "criar"){
            int altura, largura;
            cout << "Escreva abaixo as dimensões da matriz" << endl << "Altura: ";
            cin >> altura;
            cout << "Largura: ";
            cin >> largura;
            matrizes.push_back(matriz<int>(altura, largura));
        }else if(arg == "show"){
            int x;
            cout << "Digite a posição da matriz que gostaria de ver: ";
            cin >> x;
            cout << matrizes[x] << "\n";
        }else if(arg == "showAll"){
            for(int i = 0; i < matrizes.size(); i++){
                cout << "Matriz na posição " << i << endl << matrizes[i] << "\n";
            }
        }else if(arg == "insert"){
            int n, v, x, y;
            cout << "Digite a posição da matriz: ";
            cin >> n;
            cout << "Escreva abaixo e em ordem o valor a ser inserido, e a posição: " << endl;
            cin >> v >> x >> y;
            matrizes[n].insert(v, x, y);
        }else if(arg == "remove"){
            int n, x, y;
            cout << "Digite a posição da matriz: ";
            cin >> n;
            cout << "Escreva abaixo a posição do valor a ser removido: " << endl;
            cin >> x >> y;
            matrizes[n].remove(x, y);
        }else{
            cout << "Fail: Comando inválido" << endl;
        }
    }
}
