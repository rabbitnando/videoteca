//---------------------------------P1---------------------------------------------
#include  <iostream>
#include  <cstring>
#include  <string>
#include  <cstdio>
#include  <cstdlib>
#include  <fstream>

using namespace std;
//---------------------------------P2---------------------------------------------
// prototipo das funcoes
void menu();
void adicionarFilme();
void pesquisarFilme();
void excluirFilme();
void mostraFilme();
void titulo();
void ajuda();
//---------------------------------P3---------------------------------------------
int main()
{
  int op;
  bool loop = true;
  ifstream verifica;

  system("clear"); //Limpar tela
//Verificar se o arquivo 'lista.txt' foi aberto
  //ajuda();
  verifica.open("lista.txt");
  if(verifica.is_open())
  {
    titulo();
    while(loop != false)
    {
      menu();
      cout << "\nInforme opcao\n> ";
      cin >> op;

      getchar(); //limpar buffer do teclado

      switch (op)
      {
        case 1:
          adicionarFilme();
        break;

        case 2:
          pesquisarFilme();
        break;

        case 3:
          excluirFilme();
        break;

        case 4:
          mostraFilme();
        break;

        case 0:
          system("clear");
          cout << "\n\t==========..Obrigado!!! Por Rabbit_nando :)..==========" << endl;
          loop = false;
        break;

        default:
          cout << "==========..Informe um valor valido..==========";
      }
    }
  }
  else
  {
    cout << "\n\t=============================\n";
    cout << "Arquivo de 'lista.txt' nao encontrado.";
    cout << "\n#AVISO: adicione o arquivo 'lista.txt' no diretorio atual" << endl;
    cout << "\t=============================\n";
    getchar();
  }
  verifica.close();
  return 0;
}

//------------------------------------P4------------------------------------------
//Informa na tela o menu de opcao que o usuario podera usar
void menu()
{
  system("clear");
  cout << "\n\t==========..Menu..==========";
  cout << "\n> 1. Adicionar Filme" << "\t > 2. Pesquisar Filme";
  cout << "\n> 3. Excluir filme" << "\t > 4. Mostra Filmes";
  cout << "\n> 0. Sair\n";
  cout << "\t=============================\n";
}

//Adicionar filme informado pelo usuario na 'lista.txt'
void adicionarFilme()
{
  system("clear"); //Limpar tela
  ofstream adcFilme;
  string infoFilme;

  adcFilme.open("lista.txt",ios::app); //ios::app = Adiciona o elemento informado no final do arquivo

  cout << "\n\t==========..Adicionar..==========\n";

  cout << "Informe o nome do filme\n> ";
  getline(cin,infoFilme);

  adcFilme << infoFilme << endl;
  cout << "\n======================================\n";
  cout << "Filme informado adicionado na lista\n> " << infoFilme << endl;
  cout << "========================================\n";

  adcFilme.close();
  getchar();
}
//Funcao faz uma persuisa na 'lista.txt' pelo o nome que o usuario digitou
void pesquisarFilme()
{
  system("clear"); //Limpar tela

  ifstream pesFilme;
  string infoFilme;
  string linha;
  int i = 0; //contador
  bool temfilme = false;

  pesFilme.open("lista.txt"); //Abrir o arquivo da lista de filmes

  cout << "\n\t==========..Pesquisar..==========\n";
  cout << "Informe o nome do filme\n> ";
  getline(cin,infoFilme);

//Usado para percorrer o arquivo 'lista.txt', e armazenar linha por linha na variavel 'linha'
  while(getline(pesFilme,linha))
  {
    if(linha.compare(infoFilme)==0 || linha.compare(0,3,infoFilme)==0) //Faz a comparacao das strings
    {
      temfilme = true;
      cout << "\n=============================\n";
      cout << "Filme informado encontrado\n> " << i << "." << linha << endl;
      cout << "=============================\n";
    }
    i++;
  }
  if(temfilme == false) //caso ainda seja falso o filme nao foi encontrado
  {
    cout << "\n=============================\n";
    cout << "Filme informado nao encontrado\n> " << infoFilme;
    cout << "\n=============================\n";
  }
  getchar();
  pesFilme.close();
}
//Exclui filme informado pelo o usuario
void excluirFilme()
{
  system("clear");
  ifstream pesFilme;
  ofstream tempFilme;
  string infoFilme;
  string linha;
  int i = 0; //contador
  bool temfilme = false;

  pesFilme.open("lista.txt"); //Abrir o arquivo da lista de filmes
  tempFilme.open("temp.txt");

  cout << "\n\t==========..Excluir..==========\n";
  cout << "Informe o nome do filme\n> ";
  getline(cin,infoFilme);

  //Usado para percorrer o arquivo 'lista.txt', e armazenar linha por linha na variavel 'linha'
  while(getline(pesFilme,linha))
  {
    if(linha.compare(infoFilme)==0) //Faz a comparacao das strings
    {
      temfilme = true;
      cout << "\n=============================\n";
      cout << "Filme informado removido\n> " << i << "." << linha << endl;
      cout << "=============================\n";
    }
  //Salva no arquivo 'temp.txt' todas as linha menos a que voce deseja excluir
    else
    {
      tempFilme << linha << endl;
    }
    i++;
  }
  if(temfilme == false) //caso ainda seja falso o filme nao foi encontrado
  {
    cout << "\n=============================\n";
    cout << "Filme informado nao encontrado\n> " << infoFilme;
    cout << "\n=============================\n";
  }

  pesFilme.close();
  tempFilme.close();
  getchar();

  //Faz a troca do arquivo 'temp.txt' por 'lista.txt'
  remove("lista.txt");
  rename("temp.txt","lista.txt");
}
//Funcao faz que todos os filmes adicionado na 'lista.txt' seja mostrado na tela
void mostraFilme()
{

  system("clear"); //Limpa tela
  ifstream mosFilme;
  string filme;
  int i = 0;

  mosFilme.open("lista.txt"); //Abrir arquivo

  cout << "\n\t==========..LISTA..==========\n" << endl;
  while(getline(mosFilme, filme))
  {
    cout << i << "." << filme << endl;
    i++;
  }

  getchar();
  mosFilme.close(); //Fechar arquivo
  cout << endl; //Quebra de linha
}
//Funcao mostra titulo do programa
void titulo()
{
    ifstream mosTitulo;
    string titulo;

    mosTitulo.open("titulo.txt");

    if(mosTitulo.is_open()) //Verificar se o titulo.txt foi aberto
    {
        while(getline(mosTitulo,titulo))
        {
            cout << titulo << endl;
        }
    }
    else
    {
        cout << "Arquivo nao encontrado" << endl;
    }

    mosTitulo.close();

    cout << "Para continuar tecle <enter>. ";

    getchar();
    cout << endl;
}
//Funcao feita para ajudar o usuario no uso do programa
void ajuda()
{
  char opc, opc2;
  ofstream arquivo;


  cout << "\n#..Aviso: Ao fazer um novo arquvo\nvai apagar todos os dados do arquivo\n'lista.txt' anterior..#\n";
  cout << "\nDeseja que seja feito o arquivo?(s/n)";
  cout << "\n> ";
  cin >> opc;

  if(opc == 's')
  {
    arquivo.open("lista.txt");
    arquivo.close();
  }

  cout << "Deseja ver as instrucoes?(s/n): ";
  cin >> opc2;
  if(opc2 == 's')
  {
    cout << "\n\t==========..AJUDA..==========\n";
    cout << "\n#. 1.Arquivo 'lista.txt' tem que existir no diretorio atual.............#";
    cout << "\n#. 2.Evite coloca numeros no inicio dos nomes dos filmes................#";
    cout << "\n#. 3.Cuidado ao excluir um filme, pois pode ter filme com o mesmo nome..#";
    cout << "\n#..4.As pesquisas podem ser feitas com apenas 3 digitos.................#";
    cout << "\n\t=============================" << endl;
    getchar();
  }

  cout << "\n\t==========..Tenha um bom uso..==========\n" << endl;
  getchar();
  cout << endl;
}
