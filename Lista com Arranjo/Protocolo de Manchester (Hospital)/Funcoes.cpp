#include <iostream>
#include "Funcoes.hpp"
using namespace std;

void InicializaFila(TipoFila *fila)
{
    fila->primeiro = NULL;
    fila->ultimo = NULL;
    fila->tamanho = 0;
}

bool VerificaFilaVazia(TipoFila *fila)
{
    return (fila->primeiro == NULL);
}

void Enfileira(TipoFila *fila, Paciente paciente)
{
    Apontador novo = new TipoElemento;
    novo->paciente = paciente;
    novo->prox = NULL;

    if (VerificaFilaVazia(fila))
    {
        fila->primeiro = novo;
    }
    else
    {
        fila->ultimo->prox = novo;
    }

    fila->ultimo = novo;
    fila->tamanho++;
}

void Desenfileira(TipoFila *fila, Paciente *paciente)
{
    if (VerificaFilaVazia(fila))
    {
        cout << "Fila vazia!" << endl;
        return;
    }
    Apontador aux = fila->primeiro;
    *paciente = aux->paciente;
    fila->primeiro = aux->prox;
    delete aux;
    fila->tamanho--;
}

void EnfileiraPrioridade(TipoFila *fila, Paciente paciente)
{
    Apontador novo = new TipoElemento;
    novo->paciente = paciente;
    novo->prox = NULL;

    Apontador aux = fila->primeiro;

    if (VerificaFilaVazia(fila))
    {
        fila->primeiro = novo;
    }
    else
    {
        if (!aux->paciente.prioridade)
        {
            novo->prox = aux;
            fila->primeiro = novo;
        }
        else
        {
            while (aux->prox != NULL && aux->prox->paciente.prioridade)
            {
                aux = aux->prox;
            }

            novo->prox = aux->prox;
            aux->prox = novo;
        }
    }

    fila->tamanho++;
}

int Menu(){
    cout<<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|"<<endl;
    cout<<"|      1. Registro do Hospital (UPA)                  |"<<endl;
    cout<<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|"<<endl;
    cout<<"|      2. Cadastro de Médico                          |"<<endl;
    cout<<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|"<<endl;
    cout<<"|      3. Triagem                                     |"<<endl;
    cout<<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|"<<endl;
    cout<<"|      4. Cadastro de Paciente                        |"<<endl;
    cout<<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|"<<endl;
    cout<<"|      5. Novo Atendimento                            |"<<endl;
    cout<<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|"<<endl;
    cout<<"|      6. Sair                                        |"<<endl;
    cout<<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|"<<endl;

}

void TriagemPaciente(Triagem *RespostasTriagem){
    char resposta[18];

    cout<<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
    cout<<"|               TRIAGEM                  |\n";
    cout<<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n\n";
    cout << "Emergencia______________ Atendimento imediato. (vermelho)\n";
    cout << "Muito Urgente___________ Atendimento em ate 10 min. (laranja)\n";
    cout << "Urgente_________________ Atendimento em ate 60 min. (amarelo)\n";
    cout << "Pouco Urgente___________ Atendimento em ate 120 min. (verde)\n";
    cout << "Não Urgente_____________ Atendimento em ate 240 min. (azul)\n\n";

    cout<<"1. Comprometimento das vias aeriais (S/N)? "<<endl;
    RespostasTriagem->salvaResposta[0];
    cout<<"2. Respiração ineficaz (S/N)? "<<endl;
    RespostasTriagem->salvaResposta[1];
    cout<<"3. Choque (S/N)?"<<endl;
    RespostasTriagem->salvaResposta[2];
    cout<<"4. Não responde os estimulos (S/N)?"<<endl;
    RespostasTriagem->salvaResposta[3];
    cout<<"5. Em convulsão (S/N)?"<<endl;
    RespostasTriagem->salvaResposta[4];
    cout<<"6. Dor severa (S/N)?"<<endl;
    RespostasTriagem->salvaResposta[5];
    cout<<"7. Grande hemorragia incontrolavél (S/N)?"<<endl;
    RespostasTriagem->salvaResposta[6];
    cout<<"8. Alteração no estado de consciencia (S/N)?"<<endl;
    RespostasTriagem->salvaResposta[7];
    cout<<"9. Temperatura acima dos 39 graus (S/N)?"<<endl;
    RespostasTriagem->salvaResposta[8];
    cout<<"10. Trauma craniano severo (S/N)?"<<endl;
    RespostasTriagem->salvaResposta[9];
    cout<<"11. Dor moderada (S/N)?"<<endl;
    RespostasTriagem->salvaResposta[10];
    cout<<"12. Pequena hemorragia controlada (S/N)?"<<endl;
    RespostasTriagem->salvaResposta[11];
    cout<<"13. Vômito persistente (S/N)?"<<endl;
    RespostasTriagem->salvaResposta[12];
    cout<<"14. Temperatura entre 38 a 39 graus (S/N)?"<<endl;
    RespostasTriagem->salvaResposta[13];
    cout<<"15. Idoso ou gravida (S/N)?"<<endl;
    RespostasTriagem->salvaResposta[14];
    cout<<"16. Dor leve (S/N)?"<<endl;
    RespostasTriagem->salvaResposta[15];
    cout<<"17. Nauseas (S/N)?"<<endl;
    RespostasTriagem->salvaResposta[16];
    cout<<"18. Temperatura entre 37 a 38 graus (S/N)?"<<endl;
    RespostasTriagem->salvaResposta[17];
}

void Cadastro_Medico(Medico medico[]){

    medico[0].nome = "Fellipe";
    medico[0].area = "Cardiologista";
    medico[0].CRM = "MG-144.230";
    medico[1].nome = "Lucas";
    medico[1].area = "Clinico geral";
    medico[1].CRM = "SP-226.563";
    medico[2].nome = "Tiago";
    medico[2].area = "Radiologista";
    medico[2].CRM = "RJ-664.157";
    medico[3].nome = "Henrique";
    medico[3].area = "Cirurgião";
    medico[3].CRM = "CE-982.996";
    medico[4].nome = "Kayky";
    medico[4].area = "Psicologo";
    medico[4].CRM = "SC-539.862";
}

int FilaPacientes(Triagem RespostasTriagem){
    int tamanho;

    tamanho = sizeof(RespostasTriagem.salvaResposta) / sizeof(RespostasTriagem.salvaResposta);
    
    for(int i = 0; i < tamanho; i++){
        if(RespostasTriagem.salvaResposta[i] == 'S'){
            if(i <= 5){
                return 0;
            }
            if(i > 5 && i <= 10){
                return 1;
            }
            if(i >10 && i <= 15){
                return 2;
            }
            if(i > 15){
                return 3;
            }
        }
    }
}
