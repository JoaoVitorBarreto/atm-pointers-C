#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

int clientes = 0;

typedef struct{
  char nome[100];
  int rg;
  int cpf;
  char tipoConta[3];
  int numConta;
  int agencia;
  int senha;
  double saldo;
}conta;

void printContas(conta *pont){
  for(int i=0; i<clientes; i++, pont++){
    printf("\n%d)%s\n%d\n%d\n%s\n%d\n%d\n%d\n%lf\n", i, pont->nome, pont->rg, pont->cpf, pont->tipoConta, pont->numConta, pont->agencia, pont->senha, pont->saldo);
  }
}
  

int menu1(int i){
  printf("1 - Cadastrar cliente");
  printf("\n2 - Alterar cliente");
  printf("\n3 - Excluir cliente");
  printf("\n4 - Mostrar contas");
  printf("\n5 - Retonar\n"); 
  scanf("%d",&i);
  return i;
}

void cadastrar(conta *pont){
  pont += clientes;
  //conta nova;
  printf("Nome: ");
  scanf("%s",pont->nome);
  printf("RG: ");
  scanf("%d",&pont->rg);
  printf("CPF: ");
  scanf("%d",&pont->cpf);
  printf("Tipo de conta: ");
  scanf("%s",pont->tipoConta);
  printf("Número da conta: ");
  scanf("%d",&pont->numConta);
  printf("Agência: ");
  scanf("%d",&pont->agencia);
  printf("Senha: ");
  scanf("%d",&pont->senha);
  pont->saldo = 0.00;
  clientes++;
}

void alterar(conta *pont){
  printContas(pont);
  printf("Escolha uma conta\n");
  int escolha1 = scanf("%d",&escolha1);
  pont -= clientes;
  pont += escolha1;  
  printf("Escolha uma opção:\n1 - Nome\n2 - RG\n3 - CPF\n4 - Tipo de conta\n5 - Número da conta\n6 - Agência\n7 - Senha\n8 - Saldo\n");
  int escolha = scanf("%d",&escolha);
  switch(escolha){
    case 1:
      scanf("%s",pont->nome);
      break;
    case 2:
      scanf("%d",&pont->rg);
      break;
    case 3:  
      scanf("%d",&pont->cpf);
      break;
    case 4:
      scanf("%s",pont->tipoConta);
      break;
    case 5:
      scanf("%d",&pont->numConta);
      break;
    case 6:
      scanf("%d",&pont->agencia);
      break;
    case 7:
      scanf("%d",&pont->senha);
      break;
    case 8:
      scanf("%lf",&pont->saldo);
      break;
  }
}


conta *login(conta *p, int b){
  for(int i; i<clientes; i++){
    if(p->senha==b) continue;
    else p++;
  }
  return p;  
}

int menu2(int i){
  printf("1 - Saque");
  printf("\n2 - Depósito");
  printf("\n3 - Saldo");
  printf("\n4 - Retonar\n"); 
  scanf("%d",&i);
  return i;
}

bool login2(conta *p, bool v){
  printf("Conta: ");
  int cont = scanf("%d",&cont);
  printf("Agência: ");
  int a = scanf("%d",&a);
  printf("Senha: ");
  int s = scanf("%d",&s);
  if(p->senha == s) v = true;
  else v = false; 
  return v;
}

void saque(conta *p, double valor){
  if(p->saldo >= valor){
    p->saldo -= valor;
  }
  else printf("Saldo insuficiente");
}

void deposito(conta *p, double valor){
  p->saldo += valor;
}

void saldo(conta *p){
  printf("Saldo: %lf",p->saldo);
}

//p++->conta

int main(void) {
  conta *c;
  c = (conta*) malloc(sizeof(conta)*50);
  conta *pont;
  conta *p;
  int x = 1;
  while(x==1){

    int perfil;
    printf("Escolha perfil de usuário: administrador/cliente (1/2) ou saia do sistema(3)");
    scanf("%d",&perfil);

    if(perfil==1){
      int escolha1 = menu1(escolha1);      
      switch(escolha1){
        case 1:
          pont = c;
          cadastrar(pont);
          break;
        case 2:
          pont = c;
          alterar(pont);
          break;
        case 3:
          pont = c;
          //excluir(pont);
          break;
        case 4:
          pont = c;
          printContas(pont);
          break;
        case 5:
          continue;
      }
    }

    else if(perfil==2){
      p = c;
      printf("Digite número da conta e senha\n");
      int nc, s;
      scanf("%d",&nc);
      scanf("%d",&s);
      conta *p = login(p, s);
      int escolha = menu2(escolha);
      switch(escolha){
        case 1:
          pont = c;
          bool v1 = login2(p,v1);
          if(v1==false){
            printf("Senha incorreta");
            continue;
          }
          else{
            printf("Valor a ser sacado\n");
            double valor = scanf("%lf",&valor);
            saque(p,valor);
          }
          break;

        case 2:
          pont = c;
          bool v2 = login2(p,v2);
          if(v2==false){
            printf("Senha incorreta");
            continue;
          }
          else{
            printf("Valor a ser depositado\n");
            double valor = scanf("%lf",&valor);
            deposito(p,valor);
          }
          break;

        case 3:
          pont = c;
          bool v3 = login2(p,v3);
          if(v3==false){
            printf("Senha incorreta");
            continue;
          }
          else saldo(p);
          break;

        case 4:
          continue;
      } 
    }

    else return 0;

  }
}