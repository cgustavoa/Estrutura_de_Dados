#include <stdio.h>
#include <stdlib.h>

typedef struct{
    double x;
    double y;
} Ponto;

double areaTriangulo(Ponto a, Ponto b,Ponto c){
    
    return 0.5 * abs(a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y));
    
}

double calcularPoligono(Ponto Vertices[], int TotalVertices){
    
    double area = 0.0;

    for (int i = 0; i < TotalVertices -1; i++){
        
        area += areaTriangulo(Vertices[0],Vertices[i],Vertices[i + 1]);
        
    }

    return area;
}

int main(){
    
    FILE *arquivo= fopen("trianguloABC.txt.txt", "r");
    int TotalVertices;
    Ponto *Vertices;

    if (arquivo == NULL){
        fprintf(stderr, "Erro ao abrir o arquivo.\n");
        return 1;
    }
    
    fscanf(arquivo, "%d", &TotalVertices);
    
    Vertices = (Ponto *)malloc(TotalVertices * sizeof(Ponto));
    
    for (int i = 0; i < TotalVertices; i++) {
        fscanf(arquivo, "%lf %lf", &Vertices[i].x, &Vertices[i].y);
    }
    
    fclose(arquivo);
    
    double area = calcularPoligono(Vertices, TotalVertices);
    printf("A area do poligono eh: %.2lf\n", area);
    free(Vertices);

    return 0;
}
