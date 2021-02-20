#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime> 
#include <cstdio>
#include <iomanip>

using namespace std;

struct noAnimal {
	string nome; 
	string especie;
	string porte;
	string dieta;
	float peso;
};

const int N = 10;

noAnimal vAnimal[N]={
					{"Bob", "Lobo-Cinzento", "M","Carnivoro", 80},
					{"Fifi", "Camundongo", "P", "Carnivoro", 0.019},
					{"Espiriti", "Cavalo", "G", "Herbivoro", 1000},
					{"Dumbo", "Elefante-da-savana", "GG", "Herbivoro", 6000},
					{"Jaja", "Urso", "G", "Onivoro", 600}
					};
					
int final = 4;	
noAnimal val;
char conf;
bool sinal;

void inseirirNoFim();
void removerNoPosicaoK();	
void alterarNoPosicaoAnterior();	
void inserirNoPosteriorAoNoK();
void consultarNo();
void removerNoPosterior();
void alterarConteudoDoNoAnteriorAX();
void quantidadeValorMaiorQue80();
void classificarOrdemDecrescente();
void alterarConteudoDaPosicaoK();
void procurarNoInserirNovoNoAnterior();
void imprimirLista();
void imprimirListaOrdemInversa();

int main() { 

	// Configura��es do Programa
	setlocale(LC_ALL, "Portuguese");
	system("color 02");
	
	char op = 'X';
	while (op != 'O') {
		
		system("cls");
		cout << "\n\n\t\t\tPrograma Lista de Animais\n\n";
		
		//imprimir op��es do menu
		cout << "\n\t\tO - Sair";
		cout << "\n\t\tA - Inserir um n� no fim";
		cout << "\n\t\tB - Remover um n� na posi��o K";
		cout << "\n\t\tC - Alterar o conte�do de um n� na posi��o K-1";
		cout << "\n\t\tD - Procurar um n� e inserir um novo n� ap�s o n� encontrado";
		cout << "\n\t\tE - Consultar um n� com valor igual a X";
		cout << "\n\t\tF - Remover o n� posterior ao n� da posi��o K";
		cout << "\n\t\tG - Alterar o conte�do de um n� anterior ao n� com valor igual a X";
		cout << "\n\t\tH - Verificar a quantidade de n�s com valor(peso) maior que 80";
		cout << "\n\t\tI - Classificar em ordem decrescente";
		cout << "\n\t\tJ - Alterar o conte�do do n� da posi��o K";
		cout << "\n\t\tK - Procurar um n� e inserir um novo n� anterior ao n� encontrado";
		cout << "\n\t\tL - Imprimir a lista";
		cout << "\n\t\tM - Imprimir a lista em ordem inversa";
		
		cout << "\n\n\t\tEscolha uma op��o ";
		fflush(stdin);
		op= getchar();
		op = toupper(op); // Se for usar Alfabeto;

		// executar as fun��es conforme a escolha
		switch(op) {
			case 'O': {
				cout << "\n\t\tObrigado por usar nosso Sistema\n\n";
				break;
			} 
			case 'A': {
				inseirirNoFim();
				break;
			}
			case 'B': {
				removerNoPosicaoK();
				break;
			}
			case 'C': {
				alterarNoPosicaoAnterior();
				break;
			}
			case 'D': {
				inserirNoPosteriorAoNoK();
				break;
			}
			case 'E': {
				consultarNo();
				break;
			}
			case 'F': {
				removerNoPosterior();
				break;
			}
			case 'G': {
				alterarConteudoDoNoAnteriorAX();
				break;
			}
			case 'H': {
				quantidadeValorMaiorQue80();
				break;
			}
			case 'I': {
				classificarOrdemDecrescente();
				break;
			}
			case 'J': {
				alterarConteudoDaPosicaoK();
				break;
			}
			case 'K': {
				procurarNoInserirNovoNoAnterior();
				break;
			}
			case 'L': {
				imprimirLista();
				break;
			} 
			case 'M': {
				imprimirListaOrdemInversa();
				break;
			}
			default: {
				cout << "\n\t\tOp��o Invalida: " << op;
				break;
			}
		}
	}
	
}

//Inserir um n� no fim
void inseirirNoFim() {
	sinal = false;
	system ("cls");
	cout << "\t\t\tInserir um novo n� no fim da lista\n\n";
	if (final < N-1) {
		cout << "\n\t\tInforme um nome: ";
		cin >> val.nome;
		fflush(stdin);
		
		cout << "\n\t\tInforme uma especie: ";
		cin >> val.especie;
		fflush(stdin);
		
		cout << "\n\t\tInforme a dieta: ";
		cin >> val.dieta;
		fflush(stdin);
		
		cout << "\n\t\tInforme o porte (P = Pequeno | M = M�dio | G = Grande | GG = Gigante): ";
		cin >> val.porte;
		fflush(stdin);
		
		cout << "\n\t\tInforme o peso: ";
		cin >> val.peso;
		fflush(stdin);
		
		cout << "\n\t\tConfirma a opera��o ? (S/N)";
		cin >> conf;
		fflush(stdin);
		conf = toupper (conf);

		if (conf == 'S') {
			final ++;
			vAnimal[final] = val;
			sinal = true;
		} 
		else {
			cout << "\n\n\t\tDados n�o confirmados";
		} 
	} else {
		cout << "\n\n\t\tLista cheia - overflow\n";
	}
	system ("pause");
}

//Remover n� na posi��o K
void removerNoPosicaoK() {
	int k, aux;
	system("cls");
	sinal = false;
	cout << "\n\t\t\tRemover n� na posi��o K\n\n";
	if (final > -1) { //verificar se tem lista
		cout << "\t\t\tInforme a posi��o: ";
		cin >> k;
		fflush(stdin);
			if ((k >= 0) && (k <= final)) {
				val = vAnimal[k];
				for (int i = 0; i < 75; i++) {
					cout << "-";
				}
				cout << "\n\t\tNome: " << val.nome;
				cout << "\n\t\tEsp�cie: " << val.especie;
				cout << "\n\t\tDieta: " << val.dieta;
				cout << "\n\t\tPorte: " << val.porte;
				cout << "\n\t\tPeso: " << val.peso << endl;
				for (int i = 0; i < 75; i++) {
					cout << "-";
				}
				cout << "\n\t\tConfirma a opera��o (S/N)";
				cin >> conf;
				fflush(stdin);
				conf = toupper (conf);
				if (conf == 'S') {
					aux = k;
						while (aux < final) {
						vAnimal[aux] = vAnimal[aux + 1];
						aux ++;
						}
						final--;
						sinal = true;
				}
				else {
					cout << "\n\t\tDados n�o confirmados ";
				} 
			} else {
				cout << "\n\t\tA posi��o " << k << " nao pertence a lista";
			} 
	} else {
		cout << "\n\t\tLista vazia";
		system ("pause");
	}
}

//Alterar o conte�do de um n� na posi��o K-1
void alterarNoPosicaoAnterior() {
		int k, aux;
		sinal = false;
		system("cls");
		cout << "\n\t\t\tAlterar o conte�do de um n� na posi��o K-1\n\n";
		if (final > -1) {
		cout << "\t\t\tInforme o valor um valor: ";
		cin >> k;
		fflush(stdin);
		if ((k > 0) && (k <= final)) {
			val = vAnimal[k];
			aux = k;
			cout << "\n\t\t\tDigite um nome: ";
			cin >> val.nome;
			fflush(stdin);
		
			cout << "\n\t\t\tDigite uma especie: ";
			cin >> val.especie;
			fflush(stdin);
		
			cout << "\n\t\t\tDigite a dieta: ";
			cin >> val.dieta;
			fflush(stdin);
		
			cout << "\n\t\t\tDigite o porte (P = Pequeno | M = M�dio | G = Grande | GG = Gigante): ";
			cin >> val.porte;
			fflush(stdin);
		
			cout << "\n\t\t\tDigite o peso(Kg): ";
			cin >> val.peso;
			fflush(stdin);
			
			cout << "\n\t\t\tConfirma a Inser��o de dados(S/N): ";
			cin >> conf;
			conf = toupper(conf); // Converte para maiusculo
			
			if (conf == 'S') {
				vAnimal[aux-1] = val;
				sinal = true;
			} else {
				cout << "\n\t\t\tDados n�o confirmados para a remo��o";
				cout << "\n\t\t";
				system("pause");
			} 
		} else {
			cout << "\n\n\t\tA posi��o " << k << " � inv�lida";
			cout << "\n\t\t";
			system("pause");
		}
	} else {
		cout << "\n\n\t\tLista Vazia...";
		cout << "\n\t\t";
		system("pause");
	}
}

//Procurar um n� e inserir um novo n� ap�s o n� encontrado
void inserirNoPosteriorAoNoK() {
	noAnimal auxLista; 
	int aux, k;
	system("cls");
	sinal = false;
	cout << "\n\t\t\tProcurar um n� e inserir um novo n� ap�s o n� encontrado\n\n";
	if (final < N-1) {
		cout << "\t\t\tInforme a posi��o: ";
		cin >> k;
		fflush(stdin);
			if ((k >= 0) && (k < final)) {
				for (int i = 0; i < 75; i++) {
					cout << "-";
				}
				cout << "\n\t\t\tInforme um nome: ";
				cin >> val.nome;
				fflush(stdin);
		
				cout << "\n\t\t\tInforme uma especie: ";
				cin >> val.especie;
				fflush(stdin);
		
				cout << "\n\t\t\tInforme a dieta: ";
				cin >> val.dieta;
				fflush(stdin);
		
				cout << "\n\t\t\tInforme o porte (P = Pequeno | M = M�dio | G = Grande | GG = Gigante): ";
				cin >> val.porte;
				fflush(stdin);
		
				cout << "\n\t\t\tInforme o peso: ";
				cin >> val.peso;
				fflush(stdin);
		
				cout << "\n\t\t\tConfirma a opera��o ? (S/N)";
				cin >> conf;
				fflush(stdin);
				conf = toupper (conf);
				
				if (conf == 'S') {
					final++;
					aux = k;
					while (aux < final) {
						auxLista = vAnimal[aux+1];
						vAnimal[aux+1] = val;
						val = auxLista;
						aux ++;
					}
					sinal = true;
				}
				else {
					cout << "\n\t\t\tDados n�o confirmados ";
					system("pause");
				} 
			} else {
				cout << "\n\t\t\tA posi��o " << k << " nao pertence a lista\n\n";
				system("pause");
			} 
	} else {
		cout << "\n\t\t\tLista cheia - overflow";
		system("pause");
	} 
}

/*Consultar um n� com valor igual a X*/
void consultarNo() {
	int aux;
	string nome;
	system("cls");
	sinal = false;
	cout << "\n\t\t\tConsultar um n� pelo nome\n\n";
	if (final>-1) {
		cout << "\t\t\tDigite um nome: ";
		cin >> nome;
		fflush(stdin);
		cout << "\n\t\tConfirma a Inser��o de dados(S/N): ";
		cin >> conf;
		conf = toupper(conf); // Converte para maiusculo
		if (conf == 'S') {	
			aux = 0;
			while((aux != final) && (vAnimal[aux].nome != nome)) {
				aux++;
			}
			val = vAnimal[aux];
			if (val.nome == nome) {
				cout << "\n\t\tO registro no n� " << aux << " te as seguintes informa��es" << "\n\n\n";
				cout << "\t\t" << setw(7) << "Nome" << setw(15) << "Especie" << setw(15) << "Porte" << setw(15) << "Dieta" << setw(15) << "Peso" << endl;
				cout << "\t\t" << setw(7) << val.nome << setw(15) << val.especie << setw(15) << val.porte << setw(15) << val.dieta << setw(15) << val.peso << "\n\n";
				sinal = true;
				system("pause");
			} else {
				cout << "\n\t\tN�o existe nenhum registro com o nome de " << nome << " na lista" << "\n\n";
				system("pause");
			}
		} else {
			cout << "\n\t\tDados n�o confirmados para buscar" << "\n\n";
			system("pause");
		}
	} else {
		cout << "\t\t\tLista Vazia";
		system("pause");
	}
	
}

/*Remover o n� posterior ao n� da posi��o K*/
void removerNoPosterior() {
	int k, aux;
	system("cls");
	sinal = false;
	cout << "\n\t\t\tRemover o n� posterior ao n� da posi��o K\n\n";
	if (final > -1) {
		cout << "\t\t\tInforme o valor de K: ";
		cin >> k;
		fflush(stdin);
		if ((k >= 0) && (k <= final)) {
			val = vAnimal[k];
			cout << "\t\t" 
			<< setw(7) << "Nome: " << val.nome 
			<< setw(15) << "Especie: " << val.especie 
			<< setw(15) << "Porte: " << val.porte 
			<< setw(15) << "Dieta: " << val.dieta 
			<< setw(15) << "Peso(kg): " << val.peso << endl;
			
			cout << "\n\t\tConfirma a Inser��o de dados(S/N): ";
			cin >> conf;
			conf = toupper(conf); // Converte para maiusculo
			if (conf == 'S') {
				aux = k;
				while (aux < final) {
					vAnimal[aux] = vAnimal[aux+1];
					aux++;
				}
				final--;
				sinal = true;
			} else {
				cout << "\n\t\tDados n�o confirmados para a remo��o";
				cout << "\n\t\t";
				system("pause");
			} 
		} else {
			cout << "\n\n\t\tA posi��o " << k << " n�o pertence a lista";
			cout << "\n\t\t";
			system("pause");
		}
	} else {
		cout << "\n\n\t\tLista Vazia...";
		cout << "\n\t\t";
		system("pause");
	}
	
}

/*Alterar o conte�do de um n� anterior ao n� com valor igual a X*/
void alterarConteudoDoNoAnteriorAX() {
	int x, aux;
	system("cls");
	sinal = false;
	cout << "\n\t\t\tAlterar o conte�do de um n� anterior ao n� com valor igual a X\n\n";
	if (final > -1) {
		cout << "\t\t\tInforme o valor um valor: ";
		cin >> x;
		fflush(stdin);
		if ((x > 0) && (x <= final)) {
			val = vAnimal[x];
			aux = x;
			cout << "\n\t\tDigite um nome: ";
			cin >> val.nome;
			fflush(stdin);
		
			cout << "\n\t\tDigite uma especie: ";
			cin >> val.especie;
			fflush(stdin);
		
			cout << "\n\t\tDigite a dieta: ";
			cin >> val.dieta;
			fflush(stdin);
		
			cout << "\n\t\tDigite o porte (P = Pequeno | M = M�dio | G = Grande | GG = Gigante): ";
			cin >> val.porte;
			fflush(stdin);
		
			cout << "\n\t\tDigite o peso(Kg): ";
			cin >> val.peso;
			fflush(stdin);
			
			cout << "\n\t\tConfirma a Inser��o de dados(S/N): ";
			cin >> conf;
			conf = toupper(conf); // Converte para maiusculo
			
			if (conf == 'S') {
				vAnimal[aux-1] = val;
				sinal = true;
			} else {
				cout << "\n\t\tDados n�o confirmados para a remo��o";
				cout << "\n\t\t";
				system("pause");
			} 
		} else {
			cout << "\n\n\t\t\tA posi��o " << x << " � inv�lida";
			cout << "\n\t\t";
			system("pause");
		}
	} else {
		cout << "\n\n\t\t\tLista Vazia...";
		cout << "\n\t\t";
		system("pause");
	}
}

//Verificar a quantidade de n�s com valor maior que 80
void quantidadeValorMaiorQue80() {
	int maior80 = 0, cont;
	system("cls");
	cout << "\n\n\t\t\tQuantidade de animais que possuem o peso superior a 80Kg\n\n";
	sinal = false;
	if (final > -1) {
		cont = 0;
		while (cont <= final) {
			if ((float)vAnimal[cont].peso > 80) {
				maior80++;
			}
			cont++;
		}
		cout << "\n\t\t\tTem " << maior80 << " animal(is) que possuem o peso maior que 80Kg\n\n";
		cout << "\n\t\t";
		system("pause");
	} else {
		cout << "\n\n\t\tLista Vazia...\n\n";
		cout << "\n\t\t";
		system("pause");
	}
}

//Classificar em ordem decrescente
void classificarOrdemDecrescente() {
	 sinal = false;
     system("cls");
     cout << "\n\t\t\t Classifica��o em ordem decrescente\n\n";
     if (final >= -1){
        for (int x=0; x<final; x++) {
        	for (int y=0; y<final; y++){
               if (vAnimal[y].nome < vAnimal[y+1].nome) {
               	   val = vAnimal[y];
                   vAnimal[y] = vAnimal[y+1];
                   vAnimal[y+1] = val;
                   sinal = true;
			   } 
        	}	
		}
     }
     else {
     	cout << "\n\t\t\tLista Vazia";
	 } 
     system("pause");	
}

//Alterar o conte�do do n� da posi��o k
void alterarConteudoDaPosicaoK() {
	int k;
    sinal = false;
    system("cls");
    cout << "\n\t\t\tAlterar o conte�do do n� da posi��o k\n\n";
    if (final > -1){
        cout << "\n\t\tInforme uma posi��o: ";
        cin >> k;
        if (k>-1 && k<= final){
            val = vAnimal[k];
            
            cout << "\n\t\tInforme o nome: ";
            cin >> val.nome;
            fflush(stdin);
            
            cout << "\n\t\tInforme a especie: ";
            cin >> val.especie;
			fflush(stdin);
	
            cout << "\n\t\tInforme o porte (P = Pequeno | M = M�dio | G = Grande | GG = Gigante): ";
            cin >> val.porte;
            fflush(stdin);
            
            cout << "\n\t\tInforme a dieta: ";
            cin >> val.dieta;
            fflush(stdin);
            
            cout << "\n\t\tInforme o peso: ";
            cin >> val.peso;
            fflush(stdin);
            
            cout << "\n\t\tConfirma a Inser��o de dados(S/N): ";
            cin >> conf;
            conf = toupper(conf); // Converte para maiusculo
            
            if (conf = 'S'){
                vAnimal[k] = val;
                sinal = true;
        	}
            else {
            	cout << "\n\t\tDados n�o confirmados para a altera��o\n\n";	
			}
        } else {	
        	cout << "\n\t\tA posi��o " << k << " n�o pertence a lista\n\n";
		}
    } else {
    	cout << "\n\t\tLista vazia\n\n";	
	} 
    system("pause");
}

//Procurar um n� e inserir um novo n� anterior ao n� encontrado
void procurarNoInserirNovoNoAnterior() {
   string x;
   int aux, fim;
   system("cls");
   cout << "\n\t\t\tProcurar um n� e inserir um novo n� anterior ao n� encontrado\n\n";
   sinal = false;
   if (final>-1 && final<N-1){
      cout << "\n\t\tInforme x: ";
      cin >> x;
      aux = 0;
      while (aux<final && vAnimal[aux].nome != x) {
      	aux++;
	  }
      if (vAnimal[aux].nome == x){
        if (aux > 0){
        	
           cout << "\n\t\tInforme o nome: ";
           cin >> val.nome;
           fflush(stdin);
           
           cout << "\n\t\tInforme a especie: ";
           cin >> val.especie;
           fflush(stdin);
           
           cout << "\n\t\tInforme o porte: ";
           cin >> val.porte;
           fflush(stdin);
           
           cout << "\n\t\tInforme a dieta: ";
           cin >> val.dieta;
           fflush(stdin);
           
           cout << "\n\t\tInforme o peso: ";
           cin >> val.peso;
           fflush(stdin);
           
           cout << "\n\t\tConfirma a Inser��o de dados(S/N): ";
           cin >> conf;
           conf = toupper(conf); // Converte para maiusculo
           
           if (conf = 'S'){
              fim = final + 1;
              while(fim > aux){
                 vAnimal[fim] = vAnimal[fim-1];
                 fim = fim - 1;
            }
         	vAnimal[aux] = val;
         	sinal = true;
         	final = final + 1;
        	} else {
        		cout << "\n\t\tNao confirmado";
			}
      	} else {
      		cout << "\n\t\tNao existe no antes da posi��o 0";
	  	}
     } else {
     	cout << "\n\t\t " << x << " nao pertence a lista";
	 } 
   } else {
   	  cout << "\n\t\tLista vazia\n";
   } 
   system("pause");
}

//Imprimir Lista
void imprimirLista() {
	int aux;
	system("cls");
	sinal= false;
	cout << "\n\t\t\tImprimir Lista Senador\n\n";
	if (final >- 1) {
		cout 
		<< setw(10) << "Nome" 
		<< setw(30) << "Especie" 
		<< setw(10) << "Porte" 
		<< setw(20) << "Dieta" 
		<< setw(10) << "Peso" << endl;
		for (int i = 0; i < 80; i++) {
			cout << "-";
		}
		cout << endl;
		//IMPRIMIR A LISTA
		aux = 0;
		while (aux <= final) {
			val = vAnimal[aux];
			cout 
			<< setw(10) << val.nome 
			<< setw(30) << val.especie 
			<< setw(10) << val.porte 
			<< setw(20) << val.dieta 
			<< setw(10) << val.peso << "\n\n";
			aux++;
		}
		for (int i = 0; i < 80; i++) {
			cout << "-";
		}
		cout << endl;
		sinal = true;
		system("pause");
	} else {
		cout << "\nLista Senador Vazia...";
	}
}


//Imprimir a lista em ordem inversa
void imprimirListaOrdemInversa() {
	int x;
  	sinal = false;
  	system("cls");
  	cout << "\n\t\t\tImprimir lista inversa\n\n";
  	if (final > -1){
  		cout 
		<< setw(10) << "Nome" 
		<< setw(30) << "Especie" 
		<< setw(10) << "Porte" 
		<< setw(20) << "Dieta" 
		<< setw(10) << "Peso" << endl;
		for (int i = 0; i < 80; i++) {
			cout << "-";
		}
		cout << endl;
     	for (x=final; x>=0; x--){
       		val = vAnimal[x];
       		cout 
			<< setw(10) << val.nome 
			<< setw(30) << val.especie 
			<< setw(10) << val.porte 
			<< setw(20) << val.dieta 
			<< setw(10) << val.peso << "\n\n";
  		}
  		for (int i = 0; i < 80; i++) {
			cout << "-";
		}
		cout << endl;
		sinal = true;
  	} else {
  		cout << "\nLista Senador Vazia...";
	}
  	cout << "\n";
  	system("pause");
}
