#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h> // Apenas para o uso da função getch().

int i; //Váriavel para contar quantidade de strings.
int quant1, quant2, quant3; // Váriavel criada (apenas) para incremento;
char produto1[20], produto2[20], produto3[20];
FILE *pfile;
	
int Edados(){
	system("cls");	
	pfile = fopen("DADOS.txt", "w"); // arquivo.txt que, se não existir ele será criado. Se não, o conteúdo original é descartado para nova gravação de dados.	
		if(pfile != NULL){
			
			printf("\nInsira o nome do 1º produto:\t");
			scanf("%s", produto1);		
			fwrite(&produto1, 1, sizeof(produto1), pfile);
			printf("\nAgora insira a quantidade desse produto:\t");
			scanf("%d", &quant1);	
			fwrite(&quant1, 1, sizeof(quant1), pfile);
					
			printf("\nInsira o nome do 2º produto:\t");
			scanf("%s", produto2);	
			fwrite(&produto2, 1, sizeof(produto2), pfile);
			printf("\nAgora insira a quantidade desse produto:\t");
			scanf("%d", &quant2);
			fwrite(&quant2, 1, sizeof(quant2), pfile);
			
			printf("\nInsira o nome do 3º produto:\t");
			scanf("%s", produto3);	
			fwrite(&produto3, 1, sizeof(produto3), pfile);
			printf("\nAgora insira a quantidade desse produto:\t");
			scanf("%d", &quant3);
			fwrite(&quant3, 1, sizeof(quant3), pfile);
							
	}
	
	else{ // Se o arquivo não for aberto corretamente, o usuáro será , e o programa fechado.
	printf("\nOcorreu um erro ao abrir o arquivo.");
	exit (1);
	}	
	
	printf("\n\n\n\n----------------DADOS SALVOS----------------");

	fclose(pfile);
	}
	
void Ldados(){
	system("cls");
	int incr = 0;
	pfile = fopen("DADOS.txt", "r");
	printf("\n\n----------------DADOS ARMAZENADOS----------------\n");
	
	fread(&produto1, 1, sizeof(produto1), pfile);
	fread(&quant1, 1, sizeof(quant1), pfile);
	printf("\n%dº produto: %s\n quantidade: %d", ++incr, produto1, quant1);
	
	fread(&produto2, 1, sizeof(produto2), pfile);
	fread(&quant2, 1, sizeof(quant2), pfile);
	printf("\n\n%dº produto: %s\n quantidade: %d", ++incr, produto2, quant2);
	
	fread(&produto3, 1, sizeof(produto3), pfile);
	fread(&quant3, 1, sizeof(quant3), pfile);
	printf("\n\n%dº produto: %s\n quantidade: %d", ++incr, produto3, quant3);

	fclose(pfile);
}


int Pdados ()
{
	system("cls");
	char produtoAUX[20];
	pfile = fopen("DADOS.txt", "r");
	int j, i, str = 0; // Váriavel criada para incremento do índice da segunda string (nome); 
	printf("\nInsira o nome (COMPLETO) a ser pesquisado:\t");
	scanf("%s", produtoAUX);
	if (pfile != NULL)
	{
		for(i = 0; i<3; i++)
		{
			fread(&produto1, 1, sizeof(produto1), pfile);
			fread(&quant1, 1, sizeof(quant1), pfile);
			for(j = 0; produtoAUX[j] != '\0';j++)
			{
				if(produtoAUX[j] != produto1[j])
				{
					break;
				}
			}
			if(produtoAUX[j] == '\0' && produto1[j] == '\0')
			{
				printf("\nProduto encontrado na memória\n %s\t quantidade: %d", produto1, quant1);
				
				fclose(pfile);
				return i;
			}		
		}
	}
	fclose(pfile);
	return -1;
}

int Pdados2()
{
	system("cls");
	pfile = fopen("dados.txt", "r");
	int cont;
	char aux;
	printf("\nInsira um caracter para pesquisar:\t ");
	scanf("%c", &aux);
	aux = getchar();
		
	if (pfile != NULL)
	{
		for(i = 0; i<3; i++)
		{
			fread(&produto1, 1, sizeof(produto1), pfile);
			fread(&quant1, 1, sizeof(quant1), pfile);
				if(aux == produto1[0])
				{
					printf("\nProduto encontrado na memória\n %s\t quantidade: %d", produto1, quant1);
					
					cont++;
				}
			}		
		}
		
		if(cont == 0)
		{
			printf("\nNenhum produto encontrado.");
		}
	
	if(i == 3){
	fclose(pfile);
	return -1;
	}
}
	
int Adados()
{
	system("cls");
	int num;
	int busca;
	
	busca = Pdados();
	
	if(busca == -1){
		printf("\nNenhum produto foi encontrado.");
		return 0;
	}
	
	num = (sizeof(produto1) + sizeof(quant1)) *busca;
	
	pfile = fopen("dados.txt", "r+");
	
		fseek(pfile, num, 0);
		fread(&produto1, 1, sizeof(produto1), pfile);
		fread(&quant1, 1, sizeof(quant1), pfile);
		
		char Prod1[20];
		int Qtd1;
		Prod1[20] = produto1[20];
		Qtd1 = quant1;
		
		for(int i = 0; i < 20; i++)
		{
			Prod1[i] = produto1[i];
		}
		
		printf("\n\nAlterar '%s':", Prod1);
		scanf("%s", produto1);
		
		printf("\tAlterar quantidade '%d': ", Qtd1);
    	scanf("%d", &quant1);
		
		fseek(pfile, num, 0);
    	fwrite(&produto1, sizeof(produto1), 1, pfile);
        fwrite(&quant1, sizeof(quant1), 1, pfile);
          
	fclose(pfile);
	
	
	printf("\n-----------Produto alterado-----------");
	
}

int Excluirdados()
{
	system("cls");
	int num;
	int busca;
	busca = Pdados();
	
	if(busca == -1)
	{
		printf("\nNenhum produto encontrado.");
		return 0;
	}
	
	num = (sizeof(produto1) + sizeof(quant1)) *busca;
	
	pfile = fopen("dados.txt", "r+");
	
	fseek(pfile, num, 0);
	fread(&produto1, 1, sizeof(produto1), pfile);
	fread(&quant1, 1, sizeof(quant1), pfile);
	
	produto1[0] = '\0';
	quant1 = NULL;
	
	fseek(pfile, num, 0);
	fwrite(&produto1, 1, sizeof(produto1), pfile);
	fwrite(&quant1, 1, sizeof(quant1), pfile);
	
	fclose(pfile);
	
	printf("\n-----------Produto excluido-----------");	
}

	

main(){
	int esc;
	setlocale(LC_ALL,"portuguese");
	do{
		system("cls");
		system("color 7");	
		printf("\n\n\t\t\t _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _");
		printf("\n\t\t\t| 					                            |");
		printf("\n\t\t\t| 0 - Sair 					                    |");
		printf("\n\t\t\t| 1 - Entrada de dados            				    |");
		printf("\n\t\t\t| 2 - Lista todos os dados tela  				    |");
		printf("\n\t\t\t| 3 - pesquisa um produto, pelo nome completo, e mostra na tela     |");
		printf("\n\t\t\t| 4 - pesquisa os produtos pela 1ª letra e mostra todos na tela     |");
		printf("\n\t\t\t| 5 - altera dados. (pesquisa pelo nome produto)    		    |");
		printf("\n\t\t\t| 6 - exclui dados. (pesquisa pelo nome produto)   		    |");
		printf("\n\t\t\t|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|"); 
		printf("\n\t\t\t\t");
		scanf("%d", &esc);
		
		switch(esc){
			case 0:
				system("cls");
				system("color 2");
				printf("\t\t\t------------------------------ENCERRANDO O PROGRAMA------------------------------\n");
				printf("Obrigado por utilizar nosso software.\n desenvolvido em 04/2021.\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tDESENVOLVIDO POR ISAAC GERBONI & LUCAS GOMES\n\n\n\n\n"); 
				getch();		
				exit(0);		
			break;	
			
			case 1:
				Edados();
				getch();
			break;
			
			case 2:
				Ldados();
				getch();
			break;	
			
			case 3:
				int Valid;
				Valid = Pdados();
				if( Valid == -1){
					printf("\nNenhum produto foi encontrado.");
				}
				getch();
			break;

			case 4:
				Pdados2();
				getch();
			break;
			
			case 5:
				Adados();
				getch();
			break;	
			
			case 6:
				Excluirdados();
				getch();
			break;			
		}
			
	}while(esc!= 0);
}
