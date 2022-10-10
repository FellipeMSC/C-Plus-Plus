#include <iostream>
#include <windows.h>
#include <stack>
#include "funcoes.hpp"
#include "funcoes.cpp"

using namespace std;
 
int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);

    string nome[] = { " " , "Hamburguer" , "X-Burguer" , "X-Egg" , "X-EggBacon" , "X-Tudo"};
    float preco[] = { 0.0 ,10.00, 13.00, 15.00 , 18.00 , 20.00};
    
    stack<Pedido> PilhaPedido, PilhaAux;
    
    int op, opp, codigo = 0, id;
    float cont = 0.0;
    
    lerArquivo(&PilhaPedido, &codigo);
    codigo++;
    
    Pedido pedido;
    Pedido aux;
  
  do{//Estrutura de repetição até o usuario pedir pra sair.
    Menu();//Função para imprimir o menu.
    Pedido pedido;
      
    cout<<"Selecione uma opção: ";
    cin>>op;
    system("cls");

    switch(op){
      
      case 1:

      pedido.codigo = codigo;
      
      cout<<"Digite a distancia entre a lanchonete e sua casa (KM): ";
      cin>>pedido.distancia;
      system("cls");

      do{
    
      Cardapio(); //Funçao para mostrar o cardapio para o usuario.

      cout<<"Digite o produto que deseja: ";
      cin>>opp;

      if(opp != 6){
      
      pedido.produtos[pedido.TamanhoProduto] = opp;
      
      if(opp < 6 & opp > 0){//Para não somar valores indevidos.
      pedido.TamanhoProduto++;
      }
      
      }
      system("cls");

      }while(opp != 6);

      
      cout<<"Pedido concluido com sucesso!!\nO codigo do seu pedido é: "<<codigo<<endl;
      codigo++;
      PilhaPedido.push(pedido);

      system("pause");
      system("cls");
      break;
      
      case 2:
        
        system("cls");

        while(!PilhaPedido.empty()){
        
        cont = 0.0;

        cout<<"Codigo do pedido: "<<PilhaPedido.top().codigo<<endl;
        cout<<"Distancia entre a lanchonete e a casa: "<<PilhaPedido.top().distancia<<endl;
        
        for(int i = 0; i < PilhaPedido.top().TamanhoProduto; i++){
          
          cout<<"Codigo dos produtos: "<<PilhaPedido.top().produtos[i]<<endl;
          cout<<"Nome do produto: "<<nome[PilhaPedido.top().produtos[i]]<<endl;
          cont = cont + preco[PilhaPedido.top().produtos[i]];   
        }
        cout<<"Valor total: "<<cont <<endl;
        cout<<endl;// Irá imprimir os pedidos que foram feitos.
        
        aux = PilhaPedido.top();
        PilhaAux.push(aux);//Comando para adicionar um novo item/topo na pilha.
        PilhaPedido.pop();//Comando para retirar o topo da pilha.

        }
        PilhaAux.swap(PilhaPedido);//Comando para trocar as pilhas.

      system("pause");
      system("cls");
      break;

      case 3: 
      
      Cardapio();//Funçao para mostrar o cardapio para o usuario.
      system("pause");
      system("cls");
      break;

      case 4: 
      cout<<"Digite o codigo do seu pedido: ";
      cin>>id;
      cout<<endl;

      PesquisaItem(PilhaPedido, id, nome, preco); //Verificar, pesquisar e retornar as informações do pedido do usuario.
      system("pause");
      system("cls");

      break;

      case 5:

      OrdenarPedido(&PilhaPedido, nome, preco); //Função para ordenar os pedidos em ordem crescente dependendo da distancia.
      system("pause");
      system("cls");
      break;

      case 6: 

      OrdenarPedido(&PilhaPedido, nome, preco);
      system("cls");
      LancarEntrega(&PilhaPedido); //Função para enviar o pedido mais proximo da lanchonete.
      system("pause");
      system("cls");
      break;

    }

  }while(op != 7); //Estrutura de repetição até o usuario pedir pra sair.  
  
salvarArquivo(&PilhaPedido);
  
  cout << endl;
  return 0;
}

