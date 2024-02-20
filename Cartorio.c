#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //bliblioteca das strings

int main(){
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	int opcao = 0;
	int laco = 1;	
	char senhadm[] = "a";
	int comparacao;
		
	printf("Acesso de administrador.\nPor favor digite sua senha: ");
	scanf("%s", senhadm);
		
	comparacao = strcmp(senhadm, "admin"); //strcmp compara os valores na mem�ria para confirma��o de iguldade
		
	if(comparacao == 0){
		
		system("cls");
		
        for(laco=1;laco=1;){
			system("cls"); //'System' chama pelos m�todos da biblioteca e 'cls' � o comando que limpa a tela do console
		
			printf("### Cart�rio da EBAC ### \n\n"); //In�cio do menu
			printf("Escolha a op��o desejada do menu: \n\n");
			printf("\t1 - Registrar nomes\n\n");
			printf("\t2 - Consultar os nomes\n\n");
			printf("\t3 - Deletar nomes\n\n"); //Fim do menu
			printf("\t4 - Retornar ao menu\n\n");
			printf("Op��o: ");
	
			scanf("%d", &opcao); //Armazenando a escolha do usu�rio
			
			switch(opcao){
	            case 1:
					 registro();
					 break;
			
		        case 2:
					 consulta();
					 break;
				
				case 3:
					 deletar();
					 break;
				
				case 4:
		 			 printf("Obrigado por utilizar esse sistema!\n");
		 			 return 0;
			 		 break;
				
				default:
						printf("Essa op��o n�o est� dispon�vel!\n\t----------------\n");
						system("pause");
						break;
			}
	    }
	}
	else{
 		printf("Senha inv�lida!");
	}
}

int registro(){
	printf("Vo�� escolheu a op��o registro de nomes!\n\t----------------\n");
	
	//Informa��es b�sicas do usu�rio
	char arquivo[40]; //Cont�m o nome do arquivo gerado, neste caso sera o cpf
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	char cpf[40];
	
	printf("Digite o nome: ");
	scanf("%s", nome); //%s monta em forma de string o texto do cliente dentro da vari�vel nome
	printf("Digite seu sobrenome: ");
	scanf("%s", sobrenome);
	printf("Digite o CPF: ");
	scanf("%s", cpf);
	printf("Digite seu cargo: ");
	scanf("%s", cargo);
	strcpy(arquivo, cpf); //copia os dados de cpf
	
	FILE *file; //Referencia os arquivos salvos na mesma pasta do projeto em 'file'
	file = fopen(arquivo, "w"); //'fopen' abri file. primeiro par�metro cria o nome do arquivo e o segundo par�metro 'w' � um comando para criar o novo arquivo
	fprintf(file, cpf); //Imprimi dentro de file o dado de cpf
	fclose(file); //Fecha file
	file = fopen(arquivo, "a"); //Comando 'a' significa atualizar um arquivo j� existente
	fprintf(file, ", ");
	fclose(file);
	
	//-----------------//
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fprintf(file, ", ");
	fclose(file);
	
	//-----------------//
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fprintf(file, ", ");
	fclose(file);
	
	//------------------//
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fprintf(file, ". ");
	fclose(file);
	
	system("pause");
}
int consulta(){
	printf("Vo�� escolheu a op��o consultar nomes!\n\t----------------\n");
	
	char cpf[40]; //Armazena o usu�rio que queremos verificar
	char conteudo[200]; //As informa��es do usu�rio seram armazenadas aqui
	
	printf("Digite o CPF do usu�rio que deseja consultar: ");
	scanf("%s", cpf); //Pega o cpf do usu�rio desejado e armazena na vari�vel cpf
	
	FILE *file;
	file = fopen(cpf, "r"); //Abri os arquivos e procura pelas informa�oes do usu�rio
	
	if(file == NULL){ //Verifica se ele esta registrado
		printf("Esse usu�rio n�o existe.\n\n");
	}
	
	while(fgets(conteudo, 200, file)){ //Monta uma string com os dados do usu�rio dentro da vari�vel conteudo
		printf("Esses s�o os dados do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");		
	}
	
	fclose(file);
	system("pause");
}
int deletar(){
	printf("Vo�� escolheu a op��o deletar nomes!\n\t----------------\n");
	char cpf[40]; //Usu�rio que desejamos deletar sera buscado nos dados pelo cpf
		
	printf("Escolha o CPF do usu�rio: ");
	scanf("%s", cpf); //Armazena o cpf na vari�vel
	
	FILE* file = fopen(cpf, "r"); //Acessa os arquivos
	fclose(file);	
	if(file == NULL){ //Verifica se o usu�rio existe
		printf("Esse usu�rio n�o existe.\n\n");
	}
	
	if(remove(cpf) == 0){ //Tenta remover o usu�rio e verifica se deu tudo certo
		printf("Usu�rio deletado!\n\n");
	} 
	else{ //Caso falhe a remo��o do usu�rio
		printf("Falha! Tente novamente...");
	}
	
	system("pause");
}
