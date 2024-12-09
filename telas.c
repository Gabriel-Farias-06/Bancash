#include "procedure.c"


void MenuPrin()
{
    int opcPrin = 0; // opcao do menu principal
    LeASenhaDeADM();
    lembrarContaCor();
    lembrarContaPoup();
    LembrarRelatorio();
    lembrarFuncio();

    while (opcPrin != 3) // Loop até que o usuário escolha a opção para sair 
    {
        printf("            Seja bem vindo ao banco Bancash\n\n");
        printf("1- Funcionario\n2- Cliente\n3- Sair do programa\nDigite sua opcao: ");
        scanf("%d", &opcPrin);
        system("cls");

        switch(opcPrin)
        {
            case 1:
                Funcio();
                break;
            case 2:
                Cliente();
                break;
            case 3:
                printf("Saindo do programa...\n");
                system("pause");
                system("cls");
                break;
            default:
                printf("Digite uma opcao valida!\n");
                system("pause");
                system("cls");
                break;
        }
    }
}

void Funcio()
{
    boolean ver = 0;
    int opcFun = 0, formaDeLogin; // opcao do Menu Funcionario 
    printf("            Bem-vindo ao menu do funcionario\n Escolha a forma de login:\n\n");
    printf("1- Logar pela senha de administrador\n2- Logar como funcionario\nDigite sua opcao: ");
    scanf("%d", &formaDeLogin);
    if (formaDeLogin == 1) if (VerSenhaADM()) ver = 1; else return;
    else if (formaDeLogin == 2)
    {
        printf("Digite seu codigo de funcionario: ");
        scanf("%d", &CodigoFunc);
        printf("Digite sua senha de funcionario: ");
        scanf("%d", &SenhaFunc);
        system("cls");
        for(int i = 0; i < FuncioQntdd; i++) if (CodigoFunc == Funcionario[i].codigoFuncionario && SenhaFunc == Funcionario[i].senha)
        {
            ver = 1;
            printf("Codigo e senha corretos\n");
        }
        else printf("Codigo de funcionario e/ou senha incorreto(s)\n");
        system("pause");
        system("cls");
    }
    else
    {
        printf("Digite uma opcao valida\n");
        system("pause");
        system("cls");
        return;
    } 

    if(ver)
    {
        while(opcFun != 7) // Loop até que o usuário escolha a opção para sair 
        {
            printf("            Bem-vindo ao menu do funcionario\n Qual acao deseja executar?\n\n");
            printf("1- Abertura de conta\n2- Encerramento de conta\n3- Consultar dados\n4- Alterar dados\n5- Cadastro de funcionarios\n6- Gerar relatorios\n7- Sair\nDigite sua opcao: ");
            scanf("%d", &opcFun);
            system("cls");
    
            switch(opcFun)
            {
                case 1:
                    AbrirCont();
                    break;
                case 2:
                    EncerrarCont();
                    break;
                case 3:
                    ConsulDados();
                    break;
                case 4:
                    AlterDados();
                    break;
                case 5:
                    CadasFuncio();
                    break;
                case 6:
                    GerarRela();
                    break;
                case 7:
                    break;
                default:
                    printf("Digite uma opcao valida!\n");
                    break;
            }
        } 
    } 
}
void AbrirCont()
{
    int opcAbri; // opcao do menu abrir contas

    while (opcAbri != 3) // Loop até que o usuário escolha a opção para sair 
    {
    printf("            Abertura de contas\n\nQual acao deseja executar?\n\n");
    printf("1- Conta Poupanca\n2- Conta Corrente\n3- Voltar\nDigite sua opcao: ");
    scanf("%d", &opcAbri);
    system("cls");

    switch(opcAbri)
    {
        case 1:
            ContaPou();
            break;
        case 2:
            ContaCorre();
            break;
        case 3:
            break;
        default:
            printf("Digite uma opcao valida!\n");
            system("pause");
            system("cls");
            break;
    }
}
} 

void ConsulDados()
{
    int opcConsul; // opcao do menu consultar dados
    printf("            Bem-vindo ao menu de consulta de dados\n\n Qual acao deseja executar?\n\n");

    while (opcConsul != 4) // Loop até que o usuário escolha a opção para sair 
    {
        printf("1- Consultar Conta\n2- Consultar Funcionario\n3- Consultar Cliente\n4- Voltar\nDigite sua opcao: ");
        scanf("%d", &opcConsul);
        system("cls");
    
        switch(opcConsul)
        {
            case 1:
                ConsulCont();
                break;
            case 2:
                ConsulFuncio();
                break;
            case 3:
                ConsulCliente();
                break;
            case 4:
                break;
            default:
                printf("Digite uma opcao valida!\n");
                system("pause");
                system("cls");
                break;
        }
    }
}

void AlterDados()
{
    int opcAlt; // opcao de alterar dados
    
    while(opcAlt != 4) // Loop até que o usuário escolha a opção para sair 
    {
        printf("            Bem-vindo ao menu de alteracao de contas\n\n Qual acao deseja executar?\n\n");
        printf("1- Alterar conta\n2- Alterar funcionario\n3- Alterar cliente\n4- Voltar\nDigite sua opcao: ");
        scanf("%d", &opcAlt);
        
        system("cls");

        switch(opcAlt)
        {
            case 1:
                AlterConta();
                break;
            case 2:
                AlterFuncio();
                break;
            case 3:
                AlterCliente();
                break;
            case 4:
                break;
            default:
                printf("Digite uma opcao valida!\n");
                system("pause");
                system("cls");
            break;
        }
   }
}

void Cliente()
{
    boolean ver = 0;
    int opcClie = 0;
    printf("            Bem-vindo ao menu do Cliente\n\n Informe os dados abaixo para logar na sua conta\n\n");
    NumClient = 0;
    SenhaClient = 0;
    printf("Digite o numero da sua conta: ");
    scanf("%d", &NumClient);
    printf("Digite a senha da sua conta: ");
    scanf("%d", &SenhaClient);
    system("cls");
    for (int i = 0; i < ContaCorQntdd; i++) if (NumClient == ContasCorrente[i].numCont && SenhaClient == ContasCorrente[i].senha) ver = 1;    
    for(int i = 0; i < ContaPoupQntdd; i++) if(NumClient == ContasPoupanca[i].numCont && SenhaClient == ContasPoupanca[i].senha) ver = 1;
    if(ver) 
    {
        while (opcClie != 6)
        {
            printf("            Bem-vindo ao menu do Cliente\n\nQual acao deseja executar?\n\n");
            printf("1- Saldo da Conta\n2- Fazer Deposito\n3- Fazer Saque\n4- Ver Extrato\n5- Consultar Limite \n6- Sair\nDigite sua opcao: ");
            scanf("%d", &opcClie);
            system("cls");
            switch(opcClie)
            {
            case 1:
                Saldo();
                break;
            case 2:
                Deposito();
                break;
            case 3:
                Saque();
                break;
            case 4:
                Extrato();
                break;
            case 5:
                ConsulLim();
                break;
            case 6:
                break;
            default:
                printf("Digite uma opcao valida!\n");
                break;
            }
        }
    } else printf("Conta ou senha invalida\n");
    FILE *arq = fopen("extrato.txt", "w");
    fclose(arq);
    system("pause");
    system("cls");
}
