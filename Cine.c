#include <stdio.h>
//Prototipo
void InicialzarV(int , int []);
void InicializarM (int , int , char ,char [][9]);
void Mostrar(int , int ,int [], int [], char [][9]);
int validarPos (int, int , char [][9]);
int validarCelda (int ,int ,char [][9],char );
void Guardar (int , int , char , char [][9]);
int Contar (int , int , char ,char [][9]);
int ContarFila (int , int , char [][9]);
void filasConMasEspec(int , int ,char [][9]);
void listadoCantEspecButacas(int , int , char [][9]);

int main(){
    char sala[12][9];
    int TotalDis, TotalRer, FilasVacias = 0;
    int fi[12], but[9]; //Vectores pararelos a la matriz para brindarle una mejor visualizacion de sus lugares
    int fila, butaca;
    int reset, fin=0;

    printf("\n Sala 5, Pelicula Batman\n");
    printf("\n");
    //inicializar vectores paralelos
    InicialzarV(9, but);
    InicialzarV(12, fi);
    //Inicializar Sala en todas su posiciones tenga D(Disponible)
    InicializarM(12 ,9 ,'D' ,sala);
    Mostrar(12 ,9 ,fi, but, sala);
    do{
        reset = 0; // En caso de que se superpongan las posiciones

        printf("\nSeleccione su lugar en la sala\n");
        //Ingresar fila
        printf("\nFila:");
        fila = validarPos(0,12,sala);

        if(fila < 0){
            fin = 1;
        }
        if(fila > 0){
                    printf("\nButaca:");
        //Ingresar columna
        butaca = validarPos(0,9,sala);
                switch(butaca){
                    case 8:
                        reset = validarCelda(fila, 0, sala, 'R'); //No sobreescribir la Reservas
                        if(reset == 0)
                        Guardar(fila, 0, 'R', sala);
                        break;
                    case 6:
                        reset = validarCelda(fila, 1, sala, 'R');
                        if(reset == 0)
                        Guardar(fila, 1, 'R', sala);
                        break;
                    case 4:
                        reset = validarCelda(fila, 2, sala, 'R');
                        if(reset == 0)
                        Guardar(fila, 2, 'R', sala);
                        break;
                    case 2:
                        reset = validarCelda(fila, 3, sala, 'R');
                        if(reset == 0)
                        Guardar(fila, 3, 'R', sala);
                        break;
                    case 1:
                        reset = validarCelda(fila, 4, sala, 'R');
                        if(reset == 0)
                        Guardar(fila, 4, 'R', sala);
                        break;
                    case 3:
                        reset = validarCelda(fila, 5, sala, 'R');
                        if(reset == 0)
                        Guardar(fila, 5, 'R', sala);
                        break;
                    case 5:
                        reset = validarCelda(fila, 6, sala, 'R');
                        if(reset == 0)
                        Guardar(fila, 6, 'R', sala);
                        break;
                    case 7:
                        reset = validarCelda(fila, 7, sala, 'R');
                        if(reset == 0)
                        Guardar(fila, 7, 'R', sala);
                        break;
                    case 9:
                        reset = validarCelda(fila, 8, sala, 'R');
                        if(reset == 0)
                        Guardar(fila, 8, 'R', sala);
                        break;
                }
            }

        printf("\n");
        Mostrar(12 ,9 ,fi, but, sala);

    }while(fin == 0);//Continuar mientras la fila sea mayor a cero

    //a la cantidad de asientos disponibles y la cantidad de asientos reservados.
    TotalDis = Contar(12,9,'D',sala);
    printf("\nTotal de butacas disponibles: %d\n",TotalDis);
    TotalRer = Contar(12,9,'R',sala);
    printf("\nTotal de butacas reservadas: %d\n",TotalRer);

    //b los números de filas que quedaron vacías.
    FilasVacias = ContarFila(12,9,sala);
    printf("\nTotal de Filas vacias: %d\n",FilasVacias);
    //c la o las filas con mayor cantidad de espectadores.
    filasConMasEspec(9,12,sala);
    //d  un listado con la cantidad de personas que se sentaron en los mismos números de butacas mayor a menor
    listadoCantEspecButacas(12,9,sala);

    return 0;
}
//Funciones

void InicialzarV(int tam, int vec[]){
    int i, num = 1;
        for(i=0 ;i<tam ;i++){
            vec[i] = num;
            num++;
        }
}

void InicializarM (int fila, int colum, char letra,char mat[][9]){//Inicializar valores a una letra deseada
    int i, j;
        for(i=0;i<fila;i++){

            for(j=0;j<colum;j++){

                mat[i][j] = letra;
            }
        }
}
void Mostrar(int fila, int colum,int vecVer[], int vecHor[], char mat[][9]){//Mostrar por pantalla matriz
    int i,j;
    //mostrar butacas horizontal por encima
    printf("\t Butacas\n");
    printf("    ");
    //pares
    for(i=7;i>0;i-=2){
        printf(" %d ", vecHor[i]);
    }
    //impares
    for(i=0;i<colum;i=i+2){
        printf(" %d ", vecHor[i]);
    }
    printf("\n");
        for(i=0;i<fila;i++){
            printf(" %d  ", vecVer[i]);
            for(j=0;j<colum;j++){
                printf(" %c ", mat[i][j]);
            }
            printf("\n");
        }
    printf("\n");
}
int validarPos (int infe,int supe, char mat[][9]){//validar posicion pos-1= posi real. y Finaliza con num<0
   int i;
   int num;

   do{
    scanf("%d",&num);

    if(num == infe || num > supe)

        printf("\nEl valor ingresado no es valido, Intente nuevamente:");

   }while(num == infe || num > supe);

   return num;
}
int validarCelda (int n1,int n2,char mat[][9],char letra){//donde n1 y n2 son las posiciones ingresadas en el main, para evitar suporponer datos
    int num = 0;

    if(mat[n1-1][n2] == letra){
        printf("\nEl valor ingresado no es valido, Intente nuevamente:\n");
        num = 1;
        }

    return num;
}
void Guardar (int n1, int n2, char letra, char mat[][9]){

    mat[n1-1][n2] = letra; //Una vez validado la posi y la celda, procedemos a guardarlo el valor en as posiciones correspondiente
}

int Contar (int fila, int columna, char let,char mat[][9]){ //devuelve la cantidad de veces que se repete cierta letra
    int num=0;
    int i, j;
    for(i=0; i<fila; i++){
        for(j=0; j<columna; j++){
            if(mat[i][j] == let){
                num++;
            }
        }
    }
    return num;
}

int ContarFila (int fila, int columna, char mat[][9]){ //Revisa cada fila si es que todas sus componentes son iguales
    int num = 0;
    int filaIgual;
    int i,j;

    for(i=0 ; i< fila; i++){
        filaIgual = 1;// asumimos que son iguales

        for(j=1 ; j< columna; j++){
            if(mat[i][j] != mat[i][0]){//Comparamos todos sus componentes con el primero
                filaIgual = 0;//Si encontramos un elemento diferente
            }
        }
        if(filaIgual){//Si sigue valiendo 1 quiere decir que son iguales y sumamos uno.
            num++;
        }
    }
    return num;
}

void filasConMasEspec(int filas, int columnas, char mat[][9]) {
    int maxEspec = 0;
    int especPorFila[12] = {0};

    // Contar espectadores en cada fila
    for (int i = 0; i < filas; i++) {
        int espec = 0;
        for (int j = 0; j < columnas; j++) {
            if (mat[i][j] == 'R') {
                espec++;
            }
        }
        especPorFila[i] = espec;
        if (espec > maxEspec) {
            maxEspec = espec;
        }
    }

    // Imprimir las filas con la mayor cantidad de espectadores
    printf("\nFilas con la mayor cantidad de espectadores:\n");
    for (int i = 0; i < filas; i++) {
        if (especPorFila[i] == maxEspec) {
            printf("Fila %d: %d espectadores\n", i + 1, especPorFila[i]);
        }
    }
}
/*Butaca Cantidad
    1      10
    4      6
    8      2*/
void listadoCantEspecButacas(int fila, int columna, char mat[][9]){
    int i,j;
    int Cantidad[9] = {0};
    int Butacas[9] = {8,6,4,2,1,3,5,7,9};

    //Cantidad personas
    for(i=0; i<fila; i++){
        for(j=0; j<columna; j++){
            if(mat[i][j] == 'R'){
            Cantidad[j]++; //Acumula la cant de persona en el vector
        }
      }
    }
    //Numerar las butacas
    /*
    //pares
    for(i=8,j=0; i>0; i-=2){
        Butacas[j++]=i;
    }
    //impares
    for(i=1; i<columna; i=i+2){
        Butacas[j++]=i;
    }
    */
    //Manual
    /*Butacas[0]=8;
        Butacas[1]=6;
        Butacas[2]=4;
        Butacas[3]=2;
        Butacas[4]=1;
        Butacas[5]=3;
        Butacas[6]=5;
        Butacas[7]=7;
        Butacas[8]=9;*/

    //Ordenar segun la cantidad --> mayor a menor
    for(i=0; i<columna-1; i++){
        for(j= i + 1; j<columna; j++){
            if(Cantidad[i] < Cantidad[j]){
                int aux; //Guardo lo q tengo en mi vector en un auxiliar e intercambio.
                aux = Cantidad[i];
                Cantidad[i] = Cantidad[j];
                Cantidad[j] = aux;

                int aux2;
                aux2 = Butacas[i];
                Butacas[i]=Butacas[j];
                Butacas[j]=aux2;
            }
        }
    }
    //Mostrar
    printf("\n\n");
    printf("Butaca Cantidad\n");

    for(i=0; i<columna; i++){
        if(Cantidad[i] > 0){

            printf("%d \t %d \n", Butacas[i], Cantidad[i]);
        }
    }
}
























