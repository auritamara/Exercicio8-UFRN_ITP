#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getFunction(int posicaoPrimera, int posicaoSegunda, char *letra,
                 int valorMeio, int valorDigitado) {
  int contador;
  int contadorTemp = 0;
  char *linha = malloc(sizeof(char) * (posicaoSegunda + 1));
  linha[0] = 0;
  for (contador = 0; contador <= posicaoSegunda; contador++) {    
    if (contador == posicaoPrimera) {      
      linha = strcat(linha, letra);
    } else if (contador == posicaoSegunda - 1) {
      if (valorDigitado % 2 == 0) {
        if (contador == valorMeio - 1) {
          linha = strcat(linha, " ");
        } else {
          linha = strcat(linha, letra);
        }
      } else {
        linha = strcat(linha, letra);
      }
    } else {
      linha = strcat(linha, " ");
    }    
    contadorTemp = contadorTemp + 1;    
  }
  if (valorDigitado % 2 == 0) {
    if (contadorTemp == (valorDigitado/2)+1) {
      printf("%s", " ");
    }  
  }
  printf("%s\n", linha);
}

int main(void) {
  int valorDigitado;
  char letra[1];
  scanf("%d %s", &valorDigitado, letra);
  int valorReal = valorDigitado - 1;
  int valorFixo = valorDigitado - 1;
  int valorMeio = (valorReal / 2) + 1;
  int valorRealDepois = 0;
  int contadorMeio = 1;
  int posicaoLetra = 0;
  int i;

  for (i = 0; i < valorFixo; i++) {
    if (valorReal > valorMeio) {
      posicaoLetra = valorFixo - valorReal;
      valorReal = valorReal - 1;
      getFunction(posicaoLetra, valorReal + 1, letra, valorMeio, valorDigitado);
    } else if ((valorReal == valorMeio) && (contadorMeio <= 2)) {
      if (valorDigitado % 2 == 0) {
        contadorMeio = contadorMeio + 2;
      } else {
        contadorMeio = contadorMeio + 1;
      }
      valorRealDepois = valorReal;
      posicaoLetra = valorReal - 2;
      getFunction(posicaoLetra, valorReal, letra, valorMeio, valorDigitado);
    } else {
      valorRealDepois = valorRealDepois + 1;
      posicaoLetra = valorFixo - valorRealDepois;
      getFunction(posicaoLetra, valorRealDepois, letra, valorMeio,
                  valorDigitado);
    }
  }
  return 0;
}