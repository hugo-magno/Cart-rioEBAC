#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsavel por cuidar dos strings

int registro() //função responsavel por cadastrar os usuarios no sistema
{
	//inicio criação de variaveis/string
	char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final da criaçao de variaveis/string
    
    printf("Digite o CPF a ser escaneado: "); //coletando informação do usuario
    scanf("%s", cpf); //%s refere-se a string
    
    strcpy(arquivo, cpf); //responsavel por copiar os valores das strings
    
    FILE *file; //cria o arquivo
    file = fopen(arquivo, "w"); // cria o arquivo
    fprintf(file,cpf); //salvo o valor da variavel
    fclose(file); //fecha o arquivo
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o nome ser cadastrado: ");
    scanf("%s",nome);
    
    file = fopen(arquivo, "a");
    fprintf(file,nome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o Sobrenome: ");
    scanf("%s",sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file,sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("digite o cargo: ");
    scanf("%s",cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file,cargo);
    fclose(file);
    
    system("pause");
    
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a Linguagem
	
    char cpf[40];
    char conteudo[200];
    
    printf("digite o CPF: ");
    scanf("%s",cpf);
    
    FILE *file;
    file = fopen(cpf, "r");
    
    if(file == NULL)
    {
    	printf("Arquivo nõo encontrado.\n");
	}
    
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas sao as informacoes do usuario: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	fclose (file);
	
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF para deleta-lo: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen (cpf,"r");
	fclose (file);
	
	if(file == NULL)
	{
		printf("Usuario nao Encontrado.\n");
		system("pause");
		
	}
	
}



int main()
  {
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	system("cls"); //responsavel por limpar a tela
	
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	printf("### cartório EBAC ###\n\n"); //inicio menu
	printf("Escolha a opção desejada do menu:\n\n");
	printf("\t1 registrar nomes\n");
	printf("\t2 consultar nomes\n");
	printf("\t3 deletar nomes\n\n");
	printf("opcao: "); //fim do menu
	
	scanf("%d", &opcao); //onde as escolhas do usuario ficam
	
	system("cls");
	
	switch(opcao)
	{
		case 1:
		registro(); //chama as funções
	    break;
	    
	    case 2:
	    consulta(); //
		break;
		
		case 3:
	    deletar();
		break;
		
		default:
		printf("esta opcao nao esta disponivel\n");
        system("pause");
        break;
	}
	
	
  }
  
  
}
