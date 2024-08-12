#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define LIM 500
#define InformacaoJaCadastrada printf("Essa informacao ja foi cadastrada, cadastre as informacoes que faltam!\n")
typedef int boolean;
typedef struct
{
    int dia;
    int mes;
    int ano;
} data;
struct poupanca
{
    int agen;
    int numCont;
    char nome[100];
    char cpf[100];
    data nasc;
    char tel[100];
    char ende[100];
    char cep[100];
    int casa;
    char bairro[100];
    char cid[100];
    char est[100];
    int senha;
    float Saldo;
} ContasPoupanca[LIM]; //informações contas poupança

struct corrente
{
    int agen;
    int numCont;
    float lim;
    data venc;
    char nome[100];
    char cpf[100];
    data nasc;
    char tel[100];
    char ende[100];
    char cep[100];
    int casa;
    char bairro[100];
    char cid[100];
    char est[100];
    int senha;
    float Saldo;
} ContasCorrente[LIM]; //informações contas corrente

struct Funcionario
{
    int codigoFuncionario;
    char cargo[100];
    char nome[100];
    char cpf[100];
    data nasc;
    char tel[100];
    char ende[100];
    int casa;
    char cep[100];
    char bairro[100];
    char cid[100];
    char est[100];
    int senha;
} Funcionario[LIM]; // informações funcionário

struct Saque
{
    float ValorSaque;
    int NumClient;
} StructSaque[LIM];

struct Deposito
{
    float ValorDeposito;
    int NumClient;
} StructDeposito[LIM];

int senhaADM, ContaPoupQntdd = 0, ContaCorQntdd = 0, NumClient, SenhaClient, CodigoFunc, SenhaFunc, FuncioQntdd = 0, QntddSaque = 0, QntddDeposito = 0;
boolean verGeralPoup = 0, verGeralCor = 0, verGeralFunc = 0, verificarPoup[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, verificarCor[14] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, verificarFunc[13] ={0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; //quando uma conta terminou de ser cadastrada eles tem valor 1
int VerSenhaADM(); // Verifica senha (feito)
void lembrarContaPoup(); //usar para o programa ler os dados das poupanças para salvar as informações toda vez que rodar (feito)
void lembrarContaCor(); //usar para o programa ler os dados das correntes para salvar as informações toda vez que rodar (feito)
void lembrarFuncio(); // Lembrar da conta funcionario (feito)
void MenuPrin(); // Menu Principal (feito)
void Funcio(); // Menu do Funcionario (feito)
void LembrarRelatorio(); //Lembrar do relatorio (feito)
// Contas 
void AbrirCont(); //Menu para Abrir Conta (feito)
void ContaPou(); // Conta Poupança (feito)
void ContasPoupancaArq(int qnt); //recebe a quantidade de contas poupança pra escrever no arquivo (feito)
void ContaCorre(); // Conta Corrente (feito)
void ContasCorrenteArq(int qnt); //recebe a quantidade de contas corrente pra escrever no arquivo (funcio)
// Consultas 
void EncerrarCont(); // Encerrar Conta (feito)
void ConsulDados(); //Menu Consultar Dados (feito)
void ConsulCont(); // Consultar Contas (feito)
void ConsulFuncio(); // Consultar Funcionario (feito)
void ConsulCliente(); // Consultar Clientes (feito)
void ConsulLim(); // Consultar limites (feito)
// Alteraçoes
void AlterDados(); //Menu Alterar Dados (feito)
void AlterConta(); // Alterar Conta (feito)
void AlterTipoPoup(int ContaAnt); // Altera uma conta poupanca para uma corrente (feito)
void AlterTipoCor(int ContaAnt); // Altera uma conta corrente para poupanca (feito)
void AlterFuncio(); // Alterar Funcionario (feito)
void AlterCliente(); // Alterar Cliente FALTAR FAZERRRRRRRRRR
void CadasFuncio(); // Cadastrar Funcionario  (feito)
void FuncioArq(); // Arquivo do funcionario (feito)
void GerarRela(); // Gerar Relatorio (feito)
// Cliente
void Cliente(); // Menu Cliente (feito)
void Saldo(); // Saldos do Cliente (feito)
void Deposito(); // Depositos do Cliente (feito)
void Saque(); // Saques do Cliente (feito)
void Extrato(); // Extratos Cliente (feito)