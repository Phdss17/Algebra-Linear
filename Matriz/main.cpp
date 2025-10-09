#include <iostream>
#include <vector>
#include "matriz.hpp"

using namespace std;

int main(){
    vector<matriz<int>> matrizes;

    while(true){
        cout << "\n" << "O que quer fazer?" << endl;
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
                cout << "Matriz na posição " << i << endl << matrizes[i];
            }
        }else if(arg == "insert"){
            int n, v, x, y;
            cout << "Digite a posição da matriz: ";
            cin >> n;
            cout << "Escreva abaixo e em ordem o valor a ser inserido, e a posição: ";
            cin >> v >> x >> y;
            matrizes[n].insert(v, x, y);
        }else if(arg == "remove"){
            int n, x, y;
            cout << "Digite a posição da matriz: ";
            cin >> n;
            cout << "Escreva abaixo a posição do valor a ser removido: ";
            cin >> x >> y;
            matrizes[n].remove(x, y);
        }else if(arg == "Altura"){
            int n;
            cout << "Digite a posição da matriz: ";
            cin >> n;
            cout << matrizes[n].getHigh() << endl;
        }else if(arg == "largura"){
            int n;
            cout << "Digite a posição da matriz: ";
            cin >> n;
            cout << matrizes[n].getLength() << endl;
        }else if(arg == "som"){
            int n, m;
            cout << "Digite as posições das matrizes que deseja somar: ";
            cin >> n >> m;
            matrizes.push_back(matrizes[n] + matrizes[m]);
        }else if(arg == "sub"){
            int n, m;
            cout << "Digite as posições das matrizes que deseja subtrair: ";
            cin >> n >> m;
            matrizes.push_back(matrizes[n] - matrizes[m]);
        }else if(arg == "multEsc"){
            int n, x;
            cout << "Digite a posição da matrize que deseja multiplicar e o seu escalar: ";
            cin >> n >> x;
            matrizes.push_back(matrizes[n] * x);
        }else if(arg == "mult"){
            int n, m;
            cout << "Digite as posições das matrizes que deseja multiplicar: ";
            cin >> n >> m;
            matrizes.push_back(matrizes[n] * matrizes[m]);
        }else{
            cout << "Fail: Comando inválido" << endl;
        }
    }
}
