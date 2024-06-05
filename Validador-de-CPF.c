#include <stdio.h>


int cpfValidator(char * cpf){
  int soma = 0;
  for(int i=0;i < 9;i++){
    soma += (cpf[i] - '0') * (10-i);
  }
  int resto = soma % 11;
  int primeiroDigito = (resto < 2)? 0 : 11 - resto;
  if(primeiroDigito == cpf[9] - '0'){
    for(int i=0;i < 10;i++){
      soma += (cpf[i] - '0') * (11-i);
    }
    int resto = soma % 11;
    int segundoDigito = (resto < 2) ? 0 : 11 - resto;
    if(segundoDigito == cpf[10] - '0'){
      return 1;
    }else {
      return 0;
    }
  } else{
    return 0;
  }
}

int main(){
  char cpf[12];
  printf("Digite um cpf: ");
  scanf("%11s", cpf);
  if(cpfValidator(cpf) == 1){
    printf("CPF valido");
  }else{
    printf("CPF invalido");
  }
}

