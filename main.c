#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
  char nomes[3][30], sexo[3], cliente[30], resposta;
  float totalCompra[3], valor, totalHomens=0, totalMulheres=0, total=0, media, compraMaisBarata=0, compraMaisCara=0;
  int repetido=0, opcao=0, qtdAbaixo=0, qtdAcima=0, qtdM=0, qtdH=0, encontrado=0;

    for (int i=0; i<3; i++) {  //entrada de dados
        repetido = 0;
        printf("\nCliente %i", i+1);
        printf("\nDigite seu nome: ");
        scanf("%s", nomes[i]);
        printf("Digite seu sexo ('f' ou 'm'): ");
        scanf(" %c", &sexo[i]);
        printf("Digite o valor total da compra: ");
        scanf("%f", &totalCompra[i]);


      // loop para percorrer a matriz 'nomes' e comparar o nome do cliente atual (índice 'i') com os nomes já cadastrados (índices menores que 'i')
      for (int j=0; j < i; j++) { 
        if (strcmp(nomes[i], nomes[j])==0) {
          printf("Erro: Não é possível cadastrar mais de uma compra no mesmo nome.\n");
          repetido++; //indica que um nome duplicado foi encontrado
        }
      }

      if (repetido == 0) {
        if (totalCompra[i]<0) {
            printf("Erro: Números negativos não são permitidos.\n");
            i--; //o decremento faz com que o loop externo repita a mesma iteração, permitindo que o usuário insira os dados corretos.
        } 
        else if (sexo[i]!='f' && sexo[i]!='m') {
          printf("Erro: Sexo inválido!\n");
          i--; 
        }
          else {
            printf("Cadastrado com sucesso!\n");
            system("cls");

            //cálculos para as estatísticas da opção 2 do menu principal
            if (sexo[i]=='f') {
              qtdM++;
              totalMulheres = totalMulheres + totalCompra[i];
            }
            else if (sexo[i]=='m') {
              qtdH++;
              totalHomens = totalHomens + totalCompra[i];
            }

            total = total + totalCompra[i];
      
            if (compraMaisBarata==0) {
              compraMaisBarata = totalCompra[i];
            }
            else if (totalCompra[i] < compraMaisBarata) {
              compraMaisBarata = totalCompra[i];
            }

            if (totalCompra[i] > compraMaisCara) {
              compraMaisCara = totalCompra[i];
            }
            
          }
      }
        
      // se for encontrado um nome duplicado, o loop externo repete a mesma iteração, permitindo que o usuário insira outro nome.
      else {
        i--;
      }
     
    }
  
    media = total/3;

    do {  
      printf("-------------------MENU-PRINCIPAL--------------------");
      printf("\n1. Ver informação de compras de um cliente específico");
      printf("\n2. Ver informações de todas as compras cadastradas");
      printf("\n3. Encerrar o programa");
      printf("\n-----------------------------------------------------");
      printf("\nEscolha uma opção: ");
      scanf("%i", &opcao);

      switch (opcao) {
        case 1:
          system("cls");
          printf("\nOpção 1 escolhida.");
          printf("\nDigite o nome do cliente: ");
          scanf("%s", cliente);

          //loop para percorrer os nomes cadastrados
          for (int i=0; i<3; i++) {
            
            if (strcmp(cliente, nomes[i])==0) {
            encontrado++; //indica que o nome digitado foi encontrado em algum cadastro
            printf("\nInformações do cliente:");
            printf("\nSexo: %c", sexo[i]);
            printf("\nValor total da compra: R$ %.2f", totalCompra[i]);
            }
          }
            if (encontrado == 0) {
              printf("\nNão há compras no nome informado.");
            }              
          
          printf("\nDeseja voltar ao menu principal? ('s' ou 'n'): ");
          scanf(" %c", &resposta);
        

          if (resposta=='s') {
            encontrado=0;
          }
          else if (resposta !='s' && resposta!='n') {
            do {
              printf("Erro: Opção inválida! Por favor, digite 's' para sim ou 'n' para não: ");
              scanf(" %c", &resposta);
            } while (resposta !='s' && resposta!='n');
          }
          system("cls");
          break;

        case 2:
          system("cls");
          printf("\nOpção 2 escolhida.");
          printf("\nDigite um valor: ");
          scanf("%f", &valor);

          for (int i=0; i<3; i++) {

            if (totalCompra[i] < valor) {
              qtdAbaixo++;
            }
            else if (totalCompra[i] > valor) {
              qtdAcima++;
            }
          }

          printf("\n------------------Estatísticas Gerais de Compra------------------");
          printf("\nQuantidade de compras abaixo deste valor: %i", qtdAbaixo);
          printf("\nQuantidade de compras acima deste valor: %i", qtdAcima);
          printf("\nValor total das compras: R$ %.2f", total);
          printf("\nValor médio das compras: R$ %.2f", media);
          printf("\nValor da compra mais barata: R$ %.2f", compraMaisBarata);
          printf("\nValor da compra mais cara: R$ %.2f", compraMaisCara);
          printf("\n-----------------------------------------------------------------");

          printf("\n\n----------------Estatísticas de Compra por Gênero----------------");
          printf("\nQuantidade de compradores mulheres: %i", qtdM);
          printf("\nQuantidade de compradores homens: %i", qtdH);
          printf("\nValor total comprado pelas mulheres: R$ %.2f", totalMulheres);
          printf("\nValor total comprado pelos homens: R$ %.2f", totalHomens);
          printf("\n-----------------------------------------------------------------");
          
        
          printf("\n\nDeseja voltar ao menu principal? ('s' ou 'n'): ");
          scanf(" %c", &resposta);
          
          if (resposta !='s' && resposta!='n') {
            do {
            printf("Erro: Opção inválida! Por favor, digite 's' para sim ou 'n' para não: ");
            scanf(" %c", &resposta);
            } while (resposta !='s' && resposta!='n');
          }
          system("cls");
          break;

        case 3:
          system("cls");
          printf("\nOpção 3 escolhida. Encerrando o programa...");
          break;
        
        default:
          printf("\nErro: Opção inválida!");
          break;
      } 
      
    } while (resposta=='s' && opcao!=3);
    printf("\nPrograma encerrado.");
  
  return 0;
}