#include <iostream>
#include <windows.h>
#include <stack>
#include <fstream>
#include "funcoes.hpp"

using namespace std;

void Menu(){//Função para imprimir o menu.
    cout<<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|"<<endl;
    cout<<"|             MENU             |"<<endl;
    cout<<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|"<<endl;
    cout<<"| 1. Fazer novo pedido         |"<<endl;
    cout<<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|"<<endl;
    cout<<"| 2. Listar os pedidos         |"<<endl;
    cout<<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|"<<endl;
    cout<<"| 3. Ver cardápio              |"<<endl;
    cout<<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|"<<endl;
    cout<<"| 4. Consultar pedido          |"<<endl;
    cout<<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|"<<endl;
    cout<<"| 5. Imprimir lista de entrega |"<<endl;
    cout<<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|"<<endl;
    cout<<"| 6. Lançar entrega            |"<<endl;
    cout<<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|"<<endl;
    cout<<"| 7. Sair                      |"<<endl;
    cout<<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|"<<endl;
}

void Cardapio(){//Funçao para mostrar o cardapio para o usuario.
    cout<<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|"<<endl;
    cout<<"|                    CARDÁPIO                   |"<<endl;
    cout<<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|"<<endl;
    cout<<"| 1. Hamburguer........................R$ 10,00 |"<<endl;
    cout<<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|"<<endl;
    cout<<"| 2. X-Burguer.........................R$ 13,00 |"<<endl;
    cout<<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|"<<endl;
    cout<<"| 3. X-Egg.............................R$ 15,00 |"<<endl;
    cout<<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|"<<endl;
    cout<<"| 4. X-EggBacon........................R$ 18,00 |"<<endl;
    cout<<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|"<<endl;
    cout<<"| 5. X-Tudo............................R$ 20,00 |"<<endl;
    cout<<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|"<<endl;
    cout<<"| 6. Sair.......................................|"<<endl;
    cout<<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|"<<endl;
}

void PesquisaItem(stack <Pedido> pesquisa, int id, string nome[], float preco[]){ //Funçao que irá verificar se o codigo existe e retornar as informações para o usuario.
    
    float cont = 0.0;

    while(!pesquisa.empty()){
        
        if(id == pesquisa.top().codigo){
        
        cont = 0.0;

        cout<<"Codigo do pedido: "<<pesquisa.top().codigo<<endl;
        cout<<"Distância: "<<pesquisa.top().distancia<<endl;
        
        for(int i = 0; i < pesquisa.top().TamanhoProduto; i++){
          
          cout<<"Codigo dos produtos: "<<pesquisa.top().produtos[i]<<endl;//Codigos dos produtos.
          cout<<"Nome do produto: "<<nome[pesquisa.top().produtos[i]]<<endl;//Imprimir o nome do item.
          cont = cont + preco[pesquisa.top().produtos[i]];//Soma dos produtos.
        }
        cout<<"Valor total: "<<cont <<endl;
        }
        pesquisa.pop();
    }
}

void OrdenarPedido(stack <Pedido> *ordem, string nome[], float preco[]){ //Ordena de acordo com a distancia da lanchonete a casa do usuario a maior distancia entra primeiro e sai por ultimo.
  stack <Pedido> PilhaAux, PilhaDistancia;
  int tamanho;
  float distancia = 0.0, cont = 0.0;

  tamanho = ordem->size();//Retira o tamanho da pilha.
  
  do{

    distancia = 0.0;
    
    while(!ordem->empty()){//Estrutura de repetiçao ate a pilha ficar vazia.

      if(ordem->top().distancia > distancia){
        distancia = ordem->top().distancia; 
      }//Salvar o maior distancia.

    PilhaDistancia.push(ordem->top());
    ordem->pop();
    }

    while(!PilhaDistancia.empty()){
      
      if(PilhaDistancia.top().distancia == distancia){
        PilhaAux.push(PilhaDistancia.top());
      }//Guardar o maior distancia na pilha da distancia
      
      else{
      ordem->push(PilhaDistancia.top());
      }
     
      PilhaDistancia.pop();
     }
  
  }while(PilhaAux.size() != tamanho);//Estrutura de repetiçao e uma "verificação de igualdade da pilha aux com a pilha inicial (ordem"
  
  PilhaAux.swap(*ordem);//Troca de pilha.

  while(!ordem->empty()){//Imprimir as informações dos pedidos e pecorrer a pilha toda.

        cont = 0.0;
        cout<<"Codigo do pedido: "<<ordem->top().codigo<<endl;
        cout<<"Distância: "<<ordem->top().distancia<<endl;
        
        for(int i = 0; i < ordem->top().TamanhoProduto; i++){
          cout<<"Codigo dos produtos: "<<ordem->top().produtos[i]<<endl;
          cout<<"Nome do produto: "<<nome[ordem->top().produtos[i]]<<endl;
          cont = cont + preco[ordem->top().produtos[i]];
        }

        cout<<"Valor total: "<<cont <<endl;
        PilhaAux.push(ordem->top());
        ordem->pop();
        cout<<endl;
  }
 
  while(!PilhaAux.empty()){//Inverter a pilha e trocar de pilha.
    ordem->push(PilhaAux.top());
    PilhaAux.pop();
  }
}

void LancarEntrega(stack <Pedido> *PilhaAux){//Envia o pedido mais proximo.

    PilhaAux->pop();
    
    cout<<"Pedido enviado com sucesso"<<endl;
}
