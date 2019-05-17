#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

char** llenado(){
	char** tablero = NULL;
	int sizefilas = 11, columnas = 11;
	tablero = new char*[sizefilas];
	for(int i = 0; i < columnas; i++){
		tablero[i] = new char[columnas];
	}
	tablero[0][4] = 'N';
	tablero[0][5] = 'N';
	tablero[0][6] = 'N';
	tablero[1][4] = 'N';
	tablero[1][6] = 'N';
	tablero[2][5] = 'N';
	tablero[3][5] = 'B';
	tablero[4][0] = 'N';
	tablero[4][1] = 'N';
	tablero[4][4] = 'B';
	tablero[4][5] = 'B';
	tablero[4][6] = 'B';
	tablero[4][9] = 'N';
	tablero[4][10] = 'N';
	tablero[5][0] = 'N';
	tablero[5][2] = 'N';
	tablero[5][3] = 'B';
	tablero[5][4] = 'B';
	tablero[5][5] = 'W';
	tablero[5][6] = 'B';
	tablero[5][7] = 'B';
	tablero[5][8] = 'N';
	tablero[5][10] = 'N';
	tablero[6][0] = 'N';
	tablero[6][1] = 'N';
	tablero[6][4] = 'B';
	tablero[6][5] = 'B';
	tablero[6][6] = 'B';
	tablero[6][9] = 'N';
	tablero[6][10] = 'N';
	tablero[7][5] = 'B';
	tablero[8][5] = 'N';
	tablero[9][4] = 'N';
	tablero[9][6] = 'N';
	tablero[10][4] = 'N';
	tablero[10][5] = 'N';
	tablero[10][6] = 'N';
	tablero[0][0] = 'X';
	tablero[0][10] = 'X';
	tablero[10][0] = 'X';
	tablero[10][10] = 'X';
	for(int i = 0; i < sizefilas; i++){
        	for(int j = 0; j < columnas; j++){
                        if(tablero[i][j] != 'X' && tablero[i][j] != 'N' && tablero[i][j] != 'B' && tablero[i][j] != 'W'){
				tablero[i][j] = ' ';
			}
                }
        }
	return tablero;
}
void imprimir (char** tablero){
	int filas = 11, columnas = 11;
	for(int i = 0; i < filas; i++){
		for(int j = 0; j < columnas; j++){
			cout << '['<< tablero[i][j] << ']';
		}
		cout << endl;
	}
}
int fila_movimiento (char fila){
	int filas = 0;
	switch (fila){
                case 'A':
                        filas = 0;
                break;
                case 'B':
                        filas = 1;
                break;
                case 'C':
                        filas = 2;
                break;
                case 'D':
                        filas = 3;
                break;
                case 'E':
                        filas = 4;
                break;
                case 'F':
                        filas = 5;
                break;
                case 'G':
                        filas = 6;
                break;
                case 'H':
                        filas = 7;
                break;
                case 'I':
                        filas = 8;
                break;
                case 'J':
                        filas = 9;
                break;
                case 'K':
                        filas= 10;
                break;
        }
	return filas;
}
int columna_movimiento (char columna){
	int columnas = 0;
	switch (columna){
                case '0':
                        columnas = 0;
                break;
                case '1':
                        columnas = 1;
                break;
                case '2':
                        columnas = 2;
                break;
                case '3':
                        columnas = 3;
                break;
                case '4':
                        columnas = 4;
                break;
                case '5':
                        columnas = 5;
                break;
                case '6':
                        columnas = 6;
                break;
                case '7':
                        columnas = 7;
                break;
                case '8':
                        columnas = 8;
                break;
                case '9':
                        columnas = 9;
                break;
		default:
                        columnas = 10;
                break;
        }
        return columnas;
}
bool piezas_blancas(char** matriz, int fila, int columna){
	if(matriz[fila][columna] != 'B'){
		cout << "MOVIMIENTO INVALIDO, INTENTE DE NUEVO"<<endl;
		return false;
	} else {
		return true;
	}
		
	
}
bool movimiento_blancas(char** matriz, int filapieza, int columnapieza, int movfila, int movcolumna){
	if(matriz[movfila][movcolumna] != ' '){
		cout << "MOVIMIENTO INVALIDO, INTENTE DE NUEVO"<<endl;
		return false;
	} else {
		if(filapieza == movfila || columnapieza == movcolumna){
			return true;
		}
		else {
			cout << "MOVIMIENTO INVALIDO, INTENTE DE NUEVO"<<endl;
			return false;
		}
	}
}
bool movimiento_negras(char** matriz, int filapieza, int columnapieza, int movfila, int movcolumna){
	if(matriz[movfila][movcolumna] != ' '){
                cout << "MOVIMIENTO INVALIDO, INTENTE DE NUEVO"<<endl;
                return false;
        } else {
                if(filapieza == movfila || columnapieza == movcolumna){
                        return true;
                }
                else {
                        cout << "MOVIMIENTO INVALIDO, INTENTE DE NUEVO"<<endl;
                        return false;
                }
        }

}
bool piezas_negras(char** matriz, int filapieza, int columnapieza){
	if(matriz[filapieza][columnapieza] != 'N'){
        	cout << "MOVIMIENTO INVALIDO, INTENTE DE NUEVO"<<endl;
                return false;
        } else {
                return true;
        }

}
char** comerpieza_blanca(char** matriz){
	for(int i = 0; i < 11; i++){
		for(int j = 0; j < 11; j++){
			if (matriz[i][j] == 'B'){
				if(j == 0 && i > 1 ){
					if(matriz[i-1][j] == 'N' && matriz[i+1][j] == 'N'){
						matriz[i][j] = ' ';
					} 
				} else if (j > 0 && j < 10 && (i > 0 && i < 10)){
					if((matriz[i-1][j] == 'N' && matriz[i+1][j] == 'N') || (matriz[i][j-1] == 'N' && matriz[i][j+1] == 'N')){
						matriz[i][j] = ' ';
					}
				} else if(j == 10 && i > 1 && i < 9){
					if(matriz[i-1][j] == 'N' && matriz[i+1][j] == 'N'){
						matriz[i][j] = ' ';
					}
				} else if(i == 0 && j > 1 && j < 9){
					if(matriz[i][j+1] == 'N' && matriz[i][j-1] == 'N'){
						matriz[i][j] = ' ';
					}
				} else if(i == 10 && j > 1 && j < 9){
					if(matriz[i][j+1] == 'N' && matriz[i][j-1] == 'N'){
                                                matriz[i][j] = ' ';
                                        }
				}
			}
		}
	}
	return matriz;
}
char** comerpieza_negra(char** matriz){
	        for(int i = 0; i < 11; i++){
                	for(int j = 0; j < 11; j++){
                        	if (matriz[i][j] == 'N'){
                                	if(j == 0 && i > 1 ){
                                        	if(matriz[i-1][j] == 'B' && matriz[i+1][j] == 'B'){
                                                	matriz[i][j] = ' ';
                                       		 }
                                	} else if (j > 0 && j < 10 && (i > 0 && i < 10)){
                                        	if((matriz[i-1][j] == 'B' && matriz[i+1][j] == 'B') || (matriz[i][j-1] == 'B' && matriz[i][j+1] == 'B')){
                                     			matriz[i][j] = ' ';
                                        	}
                                	} else if(j == 10 && i > 1 && i < 9){
                                        	if(matriz[i-1][j] == 'B' && matriz[i+1][j] == 'B'){
                                                	matriz[i][j] = ' ';
                                        	}
                                	} else if(i == 0 && j > 1 && j < 9){
                                        	if(matriz[i][j+1] == 'B' && matriz[i][j-1] == 'B'){
                                                	matriz[i][j] = ' ';
                                        	}
                                	} else if(i == 10 && j > 1 && j < 9){
                                        	if(matriz[i][j+1] == 'B' && matriz[i][j-1] == 'B'){
                                                	matriz[i][j] = ' ';
                                        	}
                                	}
                        	}
                	}
        	}
        	return matriz;
}
bool ganar(char** matriz){
	for(int i = 0; i < 11; i++){
		for(int j = 0; j < 11; j++){
			if(matriz[i][j] == 'W'){        
                                if (j > 0 && j < 10 && (i > 0 && i < 10)){
                                        if(matriz[i-1][j] == 'N' && matriz[i+1][j] == 'N' && matriz[i][j-1] == 'N' && matriz[i][j+1] == 'N'){
                                                return true;
                                        } else {
						return false;
					}
				} 
			}
		}
	}
}
int main(){
	int jugador = 1, filapieza2 = 0, filapieza1 = 0, filamov1 = 0, filamov2 = 0, colpieza1 = 0, colpieza2 = 0, colmov1 = 0, colmov2 = 0;
	string mov_jugador1 = "", mov_jugador2 = "", pieza_jug1 = "", pieza_jug2 = "";
	bool turno = true;
	char** tablero = llenado();
	char filas_pieza, columnas_pieza, filasmov, columnasmov;
	imprimir(tablero);
	while (turno){
		while (jugador == 1){
			cout << "Jugador 1, ingrese su pieza a mover: "<<endl;
			cin >> pieza_jug1;
			cout << "Jugador 1, ingrese lugar a mover: "<<endl;
			cin >> mov_jugador1;
			filas_pieza = pieza_jug1[0];
			columnas_pieza = pieza_jug1[2];
			filapieza1 = fila_movimiento(filas_pieza);
                        colpieza1 = columna_movimiento(columnas_pieza);
			if(!piezas_blancas(tablero, filapieza1, colpieza1)){
                                jugador = 1;
                        }
			filasmov = mov_jugador1[0];
			columnasmov = mov_jugador1[2];
			filamov1 = fila_movimiento(filasmov);
			colmov1 = columna_movimiento(columnasmov);
			if(!movimiento_blancas(tablero, filapieza1, colpieza1, filamov1, colmov1)){
				jugador = 1;			
			} else {
				tablero[filapieza1][colpieza1] = ' ';
				tablero[filamov1][colmov1] = 'B';
				comerpieza_blanca(tablero);
				comerpieza_negra(tablero);
				if(ganar(tablero)){
					turno = false;
					jugador = 3;
				}
				else {
					jugador = 2;
				}
				imprimir(tablero);
			}
		}
		while (jugador == 2){
			cout << "Jugador 2, ingrese su pieza a mover: "<<endl;
                        cin >> pieza_jug2;
                        cout << "Jugador 2, ingrese lugar a mover: "<<endl;
                        cin >> mov_jugador2;
                        filas_pieza = pieza_jug2[0];
                        columnas_pieza = pieza_jug2[2];
                        filapieza2 = fila_movimiento(filas_pieza);
                        colpieza2 = columna_movimiento(columnas_pieza);
                        if(!piezas_negras(tablero, filapieza2, colpieza2)){
                                jugador = 2;
                        }
                        filasmov = mov_jugador2[0];
                        columnasmov = mov_jugador2[2];
                        filamov2 = fila_movimiento(filasmov);
                        colmov2 = columna_movimiento(columnasmov);
                        if(!movimiento_negras(tablero, filapieza2, colpieza2, filamov2, colmov2)){
                                jugador = 2;
                        } else {
                                tablero[filapieza2][colpieza2] = ' ';
                                tablero[filamov2][colmov2] = 'N';
				comerpieza_blanca(tablero);
				comerpieza_negra(tablero);
				if(ganar(tablero)){
					turno = false;
					jugador = 3;
				} else {
					jugador = 1;
				}
                                imprimir(tablero);
                        }
		}
	}
	
}
