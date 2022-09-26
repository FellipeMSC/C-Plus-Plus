#ifndef LISTA_H
#define LISTA_H
# define MAXTAM 5
# define INICIO 1


 typedef int TChave;

 typedef struct TipoElemento*TApontador;

 typedef struct TProjetos{
 TChave codigo; // codigo do projeto
 char nome [30]; // nome do projeto
 int horas; // numero de horas trabalhas no projeto

 }TProjetos;

 typedef struct TListaSequencial {
 TProjetos item [ MAXTAM ];
 int primeiro = 0;
 int ultimo = 0;
 int tamanho = 0;
 };
 
typedef struct Endereco{
    char rua[40], bairro[40], cidade[40];
    int numcasa;
}Endereco;

 typedef struct TipoItem {
 TChave numero; // codigo do funcionario
 char nome[40]; // nome do funcionário
 Endereco endereco; // endereco do funcionario
 int dependentes; // numero de dependentes do funcionario
 int id; // id do funcionario
 TListaSequencial projetos; // Lista Sequencial que guarda os projetos nos quais o funcionario trabalha
 }TipoItem;



 typedef struct TipoElemento{
 TipoItem item;
 TApontador prox;
 };

 typedef struct TipoLista{
 TApontador primeiro ;
 TApontador ultimo;
 int tamanho = 0;
 }TipoLista;

bool ListaCriada = false;

void CriaListaVazia(TipoLista *lista);
bool VerificaListaVazia(TipoLista *lista);
void InsereListaPrimeiro(TipoLista *lista, TipoItem *item);
void AtualizaUltimo(TipoLista *lista);
void ImprimeItem(TipoLista *lista, int id);
int PesquisaItem(TipoLista *lista, int id);
void InsereListaUltimo(TipoLista *lista, TipoItem *item);
void RemoveItemPorId(TipoLista *lista, int id);
int RemoveItem(TListaSequencial *lista, int id);
void ExcluirProjeto(TipoLista *lista, int id);
int InsereItem(TListaSequencial *lista, TProjetos);
void CadastraProjeto(TipoLista *projetos, int id);
void ImprimeListaSeq(TListaSequencial lista);
TApontador PesquisaItemTwo(TipoLista *lista, int id);
void ExcluirFuncSP(TipoLista *lista, int opp);
void ImprimeContraCheque(TipoLista *lista);

 #endif
