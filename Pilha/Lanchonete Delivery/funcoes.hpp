#ifndef Pilha_h
#define Pilha_h
#include <stack>

using namespace std;

#define MAXTAM 10
#define MAX_ENTREGA 7

typedef struct {
int codigo;
int produtos [ MAXTAM ];
float valor_pedido = 0.0;
float distancia = 0.0;
int TamanhoProduto = 0;
}Pedido;

void Menu();
void Cardapio();
void PesquisaItem(stack <Pedido> pesquisa, int id, string nome[], float preco[]);
void OrdenarPedido(stack <Pedido> *ordem, string nome[], float preco[]);
void LancarEntrega(stack <Pedido> *PilhaPedido);
void lerArquivo(stack <Pedido> *PilhaAux, int *id);
void salvarArquivo(stack <Pedido> *PilhaAux);

#endif
