#include<iostream>
#include<string>
using namespace std;
struct Alimento{
    string name;
    float caloria;
    float carboidrato;
    float proteina;
    float gorduraTotal;
    float fibra;
};
// Posiçao da matriz
//1 abacaxi
//2 caqui
//3 limao
//4 melancia
//5 tomate
//6 laranja
//7 manga
//8 maça
//9 abacate
//10 caju
#define constante 3
void preencheMatriz(float **mat, float calorias,  float proteina,  float carboidrato,  float fibra, float gordura, int linha);
void imprime(float **mat, int linha, int coluna);
float** escolha(float **mat, int linha, int coluna);
void metodo(float**mat, float* vet,  int linha, int coluna);
int main(){
    float  **mat = new float*[10];
    for (int i = 0; i < 10; i++)
    {
        mat[i] = new float[constante];
    }    
    float **mat1 = new float*[constante];
    for (int i = 0; i < 5; i++)
    {
        mat1[i] = new float[constante];
    }
    float *vetProteina = new float[constante];
    vetProteina[0] = 2000;
    vetProteina[1] = 75;
    vetProteina[2] = 300;
    vetProteina[3] = 25;
    vetProteina[4] = 55;
    preencheMatriz(mat, 48, 0.54, 12.63, 1.4, 0.12, 0);  
    preencheMatriz(mat, 70, 0.58, 18.59, 3.06, 0.19, 1);
    preencheMatriz(mat, 29, 1.1, 9.32, 2.8, 0.3, 2);
    preencheMatriz(mat, 30, 0.61, 7.55, 0.4, 0.15, 3);
    preencheMatriz(mat, 18, 0.88, 3.92, 1.2, 0.2, 4);
    preencheMatriz(mat, 46, 0.96, 12.34, 2.5, 0.17, 5);
    preencheMatriz(mat, 65, 0.51, 17, 1.8, 0.27, 6);
    preencheMatriz(mat, 52, 0.26, 13.81, 2.4 , 0.17, 7);
    preencheMatriz(mat, 160, 2, 8.53, 6.7, 14.66, 8);
    preencheMatriz(mat, 43, 0.21, 11.41, 2, 0.14, 9);
    imprime(mat, 10, constante);
    mat1 = escolha(mat, constante, constante);
    imprime(mat1, constante, constante);
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    metodo(mat1, vetProteina, constante,constante);
    return 0;
}
void preencheMatriz(float ** mat, float calorias,  float proteina,  float carboidrato,  float fibra, float gordura, int linha){
    mat[linha][0] = calorias;
    mat[linha][1] = proteina;
    mat[linha][2] = carboidrato;
    mat[linha][3] = fibra;
    mat[linha][4] = gordura;
}
void imprime(float ** mat, int linha, int coluna)
{
    for (int i = 0; i < linha; i++)
    {
        cout <<  i+ 1 << " Alimento = ";
        for (int j = 0; j < coluna; j++)
        {
            cout << mat[i][j] << "  ";
        }
        cout << endl;
    }
    
}
float** escolha(float** mat, int linha, int coluna){
    int vetor[5];
    cout << "Bem vindo ao Horti-Fruti, escolha 5 alimentos dos seguintes abaixo: " << endl;
    cout << "Banana =  1 " << endl;
    cout << "Caqui =  2 " << endl; 
    cout << "Limao =  3 " << endl;  
    cout << "Melacia =  4 " << endl; 
    cout << "Tomate =  5" << endl; 
    cout << "Laranja =  6 " << endl; 
    cout << "Manga =  7 " << endl; 
    cout << "Maça =   8 " << endl; 
    cout << "Abacate =  9 " << endl; 
    cout << "Caju =   10 " << endl; 
    cout << "Escolha as 5 frutas sequencialmente: " << endl;
    for(int i =0; i < constante; i++){
        cout << " Opcao " << i+1 << " :";
        cin >> vetor[i];
        cout << endl;
    }
    float **mat1 = new float*[constante];
    for (int i = 0; i < constante; i++){
        mat1[i] = new float[constante];
    }
    for (int i = 0; i < constante; i++)
    {
        for(int j = 0; j < constante; j++){
            mat1[i][j] = mat[j][vetor[i - 1]];
        }
    }
    return mat1;
}
void metodo( float** mat, float* vet,  int linha, int coluna){
    float m;
    for(int i =0; i < constante; i++){

        for(int j = i+1; j < constante; j++){
            cout<<"Diagonal principal atual :"<<mat[i][i] << endl;;
            m = ((-1 * mat[j][i])/mat[i][i]);
            cout<< "Valor de m:"<< m << endl;
            cout << "Valor de elemento " << mat[j][i] << endl;
            float aux = m * mat[i][i];
            cout << "Valor do aux " << aux;
            mat[j][i] = mat[j][i] + aux;
            cout <<"Valor atualizado: "  << mat[j][i] << endl;
            vet[j] = vet[j] + (m * vet[j-1]);
        }
    }

    imprime(mat,constante,constante);
    for(int i = 0; i < constante; i++){
        cout << "vetor 1 " << vet[i] << endl;
    }
    float *vetFinal = new float[constante];
    float soma;
    vetFinal[constante -1] = (vet[constante -1]/mat[constante -1][constante -1]);
    for(int i = linha - 2; i >= 0; i--){
        soma = 0;
        for(int j = i + 1; j <constante; j++){
            soma = soma + mat[i][j] * vetFinal[j]; 
        }
        //soma = mat[i][i] + (mat[i][i+1] * vetFinal[i+1]);
        vetFinal[i] = (vet[i] - soma)/mat[i][i]; 
    } 
    for(int i = 0; i < linha; i++){
        cout << "Vetor resultante = " << vetFinal[i] << endl;
    }

}
