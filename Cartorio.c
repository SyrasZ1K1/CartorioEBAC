#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //bliblioteca das strings

int main(){
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	int opcao=0;
	int laco=1;	
		
	for(laco=1;laco=1;){
		system("cls"); //'System' chama pelos métodos da biblioteca e 'cls' é o comando que limpa a tela do console
		
		printf("### Cartório da EBAC ### \n\n"); //Início do menu
		printf("Escolha a opção desejada do menu: \n\n");
		printf("\t1 - Registrar nomes\n\n");
		printf("\t2 - Consultar os nomes\n\n");
		printf("\t3 - Deletar nomes\n\n"); //Fim do menu
		printf("\t4 - Retornar ao menu\n\n");
		printf("Opção: ");
	
		scanf("%d", &opcao); //Armazenando a escolha do usuário
			
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
				printf("Essa opção não está disponível!\n\t----------------\n");
				system("pause");
				break;
		}
	}
}

int registro(){
	printf("Voçê escolheu a opção registro de nomes!\n\t----------------\n");
	
	//Informações básicas do usuário
	char arquivo[40]; //Contém o nome do arquivo gerado, neste caso sera o cpf
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	char cpf[40];
	
	printf("Digite o nome: ");
	scanf("%s", nome); //%s monta em forma de string o texto do cliente dentro da variável nome
	printf("Digite seu sobrenome: ");
	scanf("%s", sobrenome);
	printf("Digite o CPF: ");
	scanf("%s", cpf);
	printf("Digite seu cargo: ");
	scanf("%s", cargo);
	strcpy(arquivo, cpf); //copia os dados de cpf
	
	FILE *file; //Referencia os arquivos salvos na mesma pasta do projeto em 'file'
	file = fopen(arquivo, "w"); //'fopen' abri file. primeiro parâmetro cria o nome do arquivo e o segundo parâmetro 'w' é um comando para criar o novo arquivo
	fprintf(file, cpf); //Imprimi dentro de file o dado de cpf
	fclose(file); //Fecha file
	file = fopen(arquivo, "a"); //Comando 'a' significa atualizar um arquivo já existente
	fprintf(file, ", ");
	fclose(file);
	
	//-----------------//
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	//-----------------//
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	//------------------//
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	file = fopen(arquivo, "a");
	fprintf(file, ". ");
	fclose(file);
	
	system("pause");
}
int consulta(){
	printf("Voçê escolheu a opção consultar nomes!\n\t----------------\n");
	
	char cpf[40]; //Armazena o usuário que queremos verificar
	char conteudo[200]; //As informações do usuário seram armazenadas aqui
	
	printf("Digite o CPF do usuário que deseja consultar: ");
	scanf("%s", cpf); //Pega o cpf do usuário desejado e armazena na variável cpf
	
	FILE *file;
	file = fopen(cpf, "r"); //Abri os arquivos e procura pelas informaçoes do usuário
	
	if(file == NULL){ //Verifica se ele esta registrado
		printf("Esse usuário não existe.\n\n");
	}
	
	while(fgets(conteudo, 200, file)){ //Monta uma string com os dados do usuário dentro da variável conteudo
		printf("Esses são os dados do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");		
	}
	
	fclose(file);
	system("pause");
}
int deletar(){
	printf("Voçê escolheu a opção deletar nomes!\n\t----------------\n");
	char cpf[40]; //Usuário que desejamos deletar sera buscado nos dados pelo cpf
		
	printf("Escolha o CPF do usuário: ");
	scanf("%s", cpf); //Armazena o cpf na variável
	
	FILE* file = fopen(cpf, "r"); //Acessa os arquivos
	fclose(file);	
	if(file == NULL){ //Verifica se o usuário existe
		printf("Esse usuário não existe.\n\n");
	}
	
	if(remove(cpf) == 0){ //Tenta remover o usuário e verifica se deu tudo certo
		printf("Usuário deletado!\n\n");
	} 
	else{ //Caso falhe a remoção do usuário
		printf("Falha! Tente novamente...");
	}
	
	system("pause");
}
