#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define ERRO 1

struct Pessoa{
    char nome [100];
    int idade;
    float altura;
    float peso;
};

void ExibirPessoa(struct Pessoa X);
struct Pessoa CadastraPessoa();
float CalcularIMC(struct Pessoa X);
void FazendoAniversario(struct Pessoa *X)

void main(){

    system("cls");

    struct Pessoa X;
    ExibirPessoa X;
    FazendoAniversario(&X);
    ExibirPessoa X;
    printf("O IMC é igual a %.3f.\n", CalcularIMC);

};

void ExibirPessoa(struct Pessoa X){
    printf("%s %d %.2f %.2f \n", X.nome, X.idade, X.altura, X.peso);
};

struct Pessoa CadastraPessoa(){
    struct Pessoa P;

    printf("Nome: ");
    gets(X->nome);
    printf("Idade: ");
    scanf("%d", &X->idade);
    printf("Altura: ");
    scanf("%f", &X->altura);
    printf("Peso: ");
    scanf("%f", &X->peso);  

    return P;
}

float CalcularIMC(struct Pessoa X){
    float IMC = X.peso / (X.altura * X.altura);
    return(IMC);
}
void FazendoAniversario(struct Pessoa X){
    X-> idade = X->idade +1;
}
void CadastraPessoa_V02(struct Pessoa *X){
    printf("Nome: ");
    gets(X->nome);
    printf("Idade: ");
    scanf("%d", &X->idade);
    printf("Altura: ");
    scanf("%f", &X->altura);
    printf("Peso: ");
    scanf("%f", &X->peso);  
}