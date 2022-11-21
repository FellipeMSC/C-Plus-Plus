#include <iostream>
#include "Funcoes.hpp"
using namespace std;

void InicializaFila(TipoFila *fila){//Inicializa uma nova fila
    fila->primeiro = NULL;
    fila->ultimo = NULL;
    fila->tamanho = 0;
}

bool VerificaFilaVazia(TipoFila *fila){//Verifica se a fila esta vazia
    return (fila->primeiro == NULL);
}

void Enfileira(TipoFila *fila, Paciente paciente){//Coloca os itens na fila
    Apontador novo;
    novo = new TipoElemento;
    novo->paciente = paciente;
    novo->prox = NULL;

    if (VerificaFilaVazia(fila)){
        fila->primeiro = novo;
    }
    else{
        fila->ultimo = novo;
    }

    fila->ultimo = novo;
    fila->tamanho++;
}

void Desenfileira(TipoFila *fila, Paciente *paciente){//Retira os itens da fila
    if (VerificaFilaVazia(fila)){
        cout << "Fila vazia!" << endl;
        return;
    }
    Apontador aux = fila->primeiro;
    *paciente = aux->paciente;
    fila->primeiro = aux->prox;
    delete aux;
    fila->tamanho--;
}

void inserePacientePrimeiro(TipoFila* fila, Paciente paciente){//Insere o paciente como primeiro da fila

    Apontador aux = new TipoElemento;
    aux->paciente = paciente;
    aux->prox = NULL;

    if(VerificaFilaVazia(fila)){
        fila->primeiro = aux;
        fila->ultimo = fila->primeiro;
    } 
    else{
        aux->prox = fila->primeiro;
        fila->primeiro = aux;
    }
    fila->tamanho++;
}


void insereAposElemento(Apontador anterior, Apontador novo){// Insere Paciente apos outro Paciente, usado na função insere com prioridade.
    novo->prox = anterior->prox;
    anterior->prox = novo;
}

void EnfileiraComPrioridade(TipoFila* fila, Paciente paciente) {
    
    if(VerificaFilaVazia(fila)){//Se a fila estiver vazia insere o Paciente direto no primeiro.
        inserePacientePrimeiro(fila, paciente);
        return;
    }

    
    if(paciente.prioridade < fila->primeiro->paciente.prioridade){// Se a prioridade do novo Paciente for menor que a do primeiro, insere o Paciente no começo da fila.
        inserePacientePrimeiro(fila, paciente);
        return;
    }

    Apontador anterior = fila->primeiro;
    Apontador atual = anterior->prox;
    Apontador novo = new TipoElemento;
    novo->paciente = paciente;
    novo->prox = NULL;

    
    while(atual != NULL){// Insere apos a maior prioridade encontrada, não funciona para o ultimo.
        if(novo->paciente.prioridade < atual->paciente.prioridade) {
            insereAposElemento(anterior, novo);
            return;
        }
        anterior = atual;
        atual = atual->prox; 
    }
    insereAposElemento(fila->ultimo, novo);
    fila->ultimo = novo;
}

int Menu(){//Menu para indicar o que você deseja fazer
    cout<<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|"<<endl;
    cout<<"|                 HOSPITAL FUNERAL                    |"<<endl;
    cout<<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|"<<endl;
    cout<<"|      1. Registro do Hospital (UPA)                  |"<<endl;
    cout<<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|"<<endl;
    cout<<"|      2. Triagem                                     |"<<endl;
    cout<<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|"<<endl;
    cout<<"|      3. Atendimento                                 |"<<endl;
    cout<<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|"<<endl;
    cout<<"|      4. Imprimir a ordem de pacientes               |"<<endl;
    cout<<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|"<<endl;
    cout<<"|      5. Sair                                        |"<<endl;
    cout<<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|"<<endl;

}

void TriagemPaciente(Triagem *RespostasTriagem){//Triagem, faz as perguntas de acordo com o que o paciente esta sentindo e defini seu estado de prioridade
    
    cout<<"1. Comprometimento das vias aeriais (S/N)? "<<endl;
    cin>>RespostasTriagem->salvaResposta[0];
    if(RespostasTriagem->salvaResposta[0] == 'S' || RespostasTriagem->salvaResposta[0] == 's'){
        return;
    }//If para parar caso seja um caso de Emergencia

    cout<<"2. Respiração ineficaz (S/N)? "<<endl;
    cin>>RespostasTriagem->salvaResposta[1];
    if(RespostasTriagem->salvaResposta[1] == 'S' || RespostasTriagem->salvaResposta[1] == 's'){
        return;
    }

    cout<<"3. Choque (S/N)?"<<endl;
    cin>>RespostasTriagem->salvaResposta[2];
    if(RespostasTriagem->salvaResposta[2] == 'S' || RespostasTriagem->salvaResposta[2] == 's'){
    return;
    }

    cout<<"4. Não responde os estimulos (S/N)?"<<endl;
    cin>>RespostasTriagem->salvaResposta[3];
    if(RespostasTriagem->salvaResposta[3] == 'S' || RespostasTriagem->salvaResposta[3] == 's'){
        return;
    } 
    cout<<"5. Em convulsão (S/N)?"<<endl;
    cin>>RespostasTriagem->salvaResposta[4];
    if(RespostasTriagem->salvaResposta[4] == 'S' || RespostasTriagem->salvaResposta[4] == 's'){
    return;
    }
       
    cout<<"6. Dor severa (S/N)?"<<endl;
    cin>>RespostasTriagem->salvaResposta[5];
    cout<<"7. Grande hemorragia incontrolavél (S/N)?"<<endl;
    cin>>RespostasTriagem->salvaResposta[6];
    cout<<"8. Alteração no estado de consciencia (S/N)?"<<endl;
    cin>>RespostasTriagem->salvaResposta[7];
    cout<<"9. Temperatura acima dos 39 graus (S/N)?"<<endl;
    cin>>RespostasTriagem->salvaResposta[8];
    cout<<"10. Trauma craniano severo (S/N)?"<<endl;
    cin>>RespostasTriagem->salvaResposta[9];
    cout<<"11. Dor moderada (S/N)?"<<endl;
    cin>>RespostasTriagem->salvaResposta[10];
    cout<<"12. Pequena hemorragia controlada (S/N)?"<<endl;
    cin>>RespostasTriagem->salvaResposta[11];
    cout<<"13. Vômito persistente (S/N)?"<<endl;
    cin>>RespostasTriagem->salvaResposta[12];
    cout<<"14. Temperatura entre 38 a 39 graus (S/N)?"<<endl;
    cin>>RespostasTriagem->salvaResposta[13];
    cout<<"15. Idoso ou gravida (S/N)?"<<endl;
    cin>>RespostasTriagem->salvaResposta[14];
    cout<<"16. Dor leve (S/N)?"<<endl;
    cin>>RespostasTriagem->salvaResposta[15];
    cout<<"17. Nauseas (S/N)?"<<endl;
    cin>>RespostasTriagem->salvaResposta[16];
    cout<<"18. Temperatura entre 37 a 38 graus (S/N)?"<<endl;
    cin>>RespostasTriagem->salvaResposta[17];
    return;
    
}

void Cadastro_medico(Medico medico[]){//Função pra predefinir os medicos

    medico[0].nome = "Fellipe";
    medico[0].area = "Cardiologista";
    medico[0].CRM = "MG144230";
    medico[1].nome = "Lucas";
    medico[1].area = "Clinico geral";
    medico[1].CRM = "SP226563";
    medico[2].nome = "Tiago";
    medico[2].area = "Radiologista";
    medico[2].CRM = "RJ664157";
    medico[3].nome = "Henrique";
    medico[3].area = "Cirurgião";
    medico[3].CRM = "CE982996";
    medico[4].nome = "Kayky";
    medico[4].area = "Psicologo";
    medico[4].CRM = "SC539862";

    for(int i = 0; i < MAXTAM; i++){//For para percorrer os dados dos medicos e imprimir os dados
        cout<<"MEDICO " << i+1<<endl;
        cout<<"Nome: "<<medico[i].nome<<endl;
        cout<<"Area: "<<medico[i].area<<endl;
        cout<<"CRM: "<<medico[i].CRM<<endl;
        cout<<"Disponibilidade: "<<medico[i].disponivel<<endl;
        cout<<endl;
    }
}

int FilaPacientes(Triagem RespostasTriagem){//Função pra verificar a prioridade e o tempo que o paciente irá ficar esperando
    int tamanho;

    tamanho = sizeof(RespostasTriagem.salvaResposta) / sizeof(RespostasTriagem.salvaResposta[0]);
    
    for(int i = 0; i < tamanho; i++){
        if(RespostasTriagem.salvaResposta[i] == 'S' || RespostasTriagem.salvaResposta[i] == 's'){
            if(i < 5){
                return 0;
            }
            if(i < 10){
                return 1;
            }
            if(i < 15){
                return 2;
            }
            if(i < 18){
                return 3;
            }
        }
    }
            return 4;
}

void CadastraPaciente(TipoFila *fila){//Cadastra os dados do pacientes, incluindo a triagem. E enfileira de acordo com sua prioridade
    Paciente paciente;
    int opp;

    do{

    TriagemPaciente(&paciente.triagem);
    system("cls");

    cout<<"Digite seu nome: ";
    cin>>paciente.nome;
    cout<<"Digite sua idade: ";
    cin>>paciente.idade;
    cout<<"Digite seu sexo (M/F): ";
    cin>>paciente.sexo;
    cout<<"Digite seu bairro: ";
    cin>>paciente.bairro;
    cout<<"Digite sua rua: ";
    cin>>paciente.rua;
    cout<<"Digite o numero da sua casa: ";
    cin>>paciente.n;

    paciente.prioridade = FilaPacientes(paciente.triagem);
    EnfileiraComPrioridade(fila, paciente);
    
    cout<<"\n\nDeseja fazer outra triagem?\n0 - NÃO\n1 - Sim\nSelecione uma opção: ";
    cin>>opp;
    system("cls");
    }while(opp != 0);
}

void Disponivel(DadosUPA *upa){//Verifica o estado do medico, disponivel ou indisponivel

    for(int i = 0; i < MAXTAM; i++){

        if(upa->medico[i].disponivel == 0){
            continue;
        }
        else if(upa->medico[i].paciente.prioridade == 0){
            if(((upa->medico[i].tempo - clock())/CLOCKS_PER_SEC) / 60 >= 60){
                upa->medico[i].disponivel = true;
            }
        }

        else if(upa->medico[i].paciente.prioridade == 1){
            if(((upa->medico[i].tempo - clock())/CLOCKS_PER_SEC) / 60 >= 25){
                upa->medico[i].disponivel = true;
            }
        }

        else if(upa->medico[i].paciente.prioridade == 2){
            if(((upa->medico[i].tempo - clock()) / CLOCKS_PER_SEC) / 60 >= 20){
                upa->medico[i].disponivel = true;
            }
        }

        else if(upa->medico[i].paciente.prioridade == 3){
            if(((upa->medico[i].tempo - clock()) / CLOCKS_PER_SEC) / 60 >=12){
                upa->medico[i].disponivel = true;
            }
        }

        else if(upa->medico[i].paciente.prioridade == 4){
            if(((upa->medico[i].tempo - clock()) / CLOCKS_PER_SEC) / 60 >= 8){
                upa->medico[i].disponivel = true; 
            }
        }
    }
}

void AtualizaMedico(TipoFila *fila, DadosUPA *upa){//Função para atualizar a situação de disponibilidade do medico
    Paciente paciente;
    
    for(int i = 0; i < MAXTAM; i++){
        
        if(upa->medico[i].disponivel == 1){
            if(!VerificaFilaVazia(fila)){
            
            Desenfileira(fila, &paciente);
            upa->medico[i].paciente = paciente;
            upa->medico[i].tempo = clock();
            upa->medico[i].disponivel = false;
            }
        }

        else{
            Disponivel(upa);
        }
    }
}

void ImprimeFila(TipoFila *fila){//Função que irá imprimir a ordem correta da fila de prioridade dos pacientes
    if (VerificaFilaVazia(fila)){
        cout << "Fila vazia!" << endl;
        return;
    }
    Apontador aux = fila->primeiro;
    while (aux != NULL){
        cout << aux->paciente.nome << " " << aux->paciente.prioridade << endl;

        aux = aux->prox;
    }
    cout << endl;
}
