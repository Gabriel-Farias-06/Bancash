#include "bibli.h"
void LeASenhaDeADM()
{
    FILE *arq = fopen("senhaADM.txt", "r");
    fscanf(arq, "Senha: %d", &senhaADM);
    fclose(arq);
}
void TransformarTxtEmCSV(char *arquivoTXT, char *arquivoCSV)

{
    FILE *arqtext = fopen(arquivoTXT, "r");
    FILE *arqcsv = fopen(arquivoCSV, "w");
    if (arqtext == NULL || arqcsv == NULL)
    {
        printf("Erro ao abrir os arquivos\n");
        system("pause");
        system("cls");
        return;
    }
    int ver = 0;
    char temporario[100]; //lugar temporario para alocar as strings
    while (fgets(temporario, sizeof(temporario), arqtext) != NULL)
    {
        for (int i = 0; temporario[i] != '\0'; i++)
        {
            if (temporario[i] == '\n')
            {
                ver++;
                if (ver%2 != 0) temporario[i] = ';';
            }
        } 
        fputs(temporario, arqcsv); 
    } 
    fclose(arqtext);
    fclose(arqcsv);
}
void ConfereOQueFaltaNoCadastro(int TipoCadastro) //0 pra tipo poupanca, 1 para corrente e 2 para funcionario
{
    if(TipoCadastro == 0)
    {
        if (!verificarPoup[0]) printf("Falta cadastrar a agencia do cliente\n");
        if (!verificarPoup[1]) printf("Falta cadastrar o nome do cliente\n");
        if (!verificarPoup[2]) printf("Falta cadastrar o CPF do cliente\n");
        if (!verificarPoup[3]) printf("Falta cadastrar a data de nascimento do cliente\n");
        if (!verificarPoup[4]) printf("Falta cadastrar o telefone do cliente\n");
        if (!verificarPoup[5]) printf("Falta cadastrar o endereco do cliente\n");
        if (!verificarPoup[6]) printf("Falta cadastrar o CEP do cliente\n");
        if (!verificarPoup[7]) printf("Falta cadastrar a casa do cliente\n");
        if (!verificarPoup[8]) printf("Falta cadastrar o bairro do cliente\n");
        if (!verificarPoup[9]) printf("Falta cadastrar a cidade do cliente\n");
        if (!verificarPoup[10]) printf("Falta cadastrar o estado do cliente\n");
        if (!verificarPoup[11]) printf("Falta cadastrar a senha do cliente\n");
        system("pause");
        system("cls");
    }

    if(TipoCadastro == 1)
    {
        if (!verificarCor[0]) printf("Falta cadastrar a agencia do cliente\n");
        if (!verificarCor[1]) printf("Falta cadastrar o nome do cliente\n");
        if (!verificarCor[2]) printf("Falta cadastrar o CPF do cliente\n");
        if (!verificarCor[3]) printf("Falta cadastrar a data de nascimento do cliente\n");
        if (!verificarCor[4]) printf("Falta cadastrar o telefone do cliente\n");
        if (!verificarCor[5]) printf("Falta cadastrar o endereco do cliente\n");
        if (!verificarCor[6]) printf("Falta cadastrar o CEP do cliente\n");
        if (!verificarCor[7]) printf("Falta cadastrar a casa do cliente\n");
        if (!verificarCor[8]) printf("Falta cadastrar o bairro do cliente\n");
        if (!verificarCor[9]) printf("Falta cadastrar a cidade do cliente\n");
        if (!verificarCor[10]) printf("Falta cadastrar o estado do cliente\n");
        if (!verificarCor[11]) printf("Falta cadastrar a senha do cliente\n");
        if (!verificarCor[12]) printf("Falta cadastrar o limite da conta do cliente\n");
        if (!verificarCor[13]) printf("Falta cadastrar a data de vencimento da conta do cliente\n");
        system("pause");
        system("cls");
    }

    if(TipoCadastro == 2)
    {
        if (!verificarFunc[0]) printf("Falta cadastrar o cargo do funcionario\n");
        if (!verificarFunc[1]) printf("Falta cadastrar o nome do funcionario\n");
        if (!verificarFunc[2]) printf("Falta cadastrar o CPF do funcionario\n");
        if (!verificarFunc[3]) printf("Falta cadastrar a data de nascimento do funcionario\n");
        if (!verificarFunc[4]) printf("Falta cadastrar o telefone do funcionario\n");
        if (!verificarFunc[5]) printf("Falta cadastrar o endereco do funcionario\n");
        if (!verificarFunc[6]) printf("Falta cadastrar o CEP do funcionario\n");
        if (!verificarFunc[7]) printf("Falta cadastrar a casa do funcionario\n");
        if (!verificarFunc[8]) printf("Falta cadastrar o bairro do funcionario\n");
        if (!verificarFunc[9]) printf("Falta cadastrar a cidade do funcionario\n");
        if (!verificarFunc[10]) printf("Falta cadastrar o estado do funcionario\n");
        if (!verificarFunc[11]) printf("Falta cadastrar a senha do funcionario\n");
        system("pause");
        system("cls");
    }
}
void lembrarContaPoup()
{
    FILE *arq;
    arq = fopen("contasPoup.txt", "r");
    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        system("pause");
        system("cls");
        return;
    }
    int i = 0;
    while (fscanf(arq, " Agencia: %d\n Numero da conta: %d\n Nome: %99[^\n]\n CPF: %99[^\n]\n Data de nascimento: %d/%d/%d\n Telefone: %99[^\n]\n Endereco: %99[^\n]\n CEP: %99[^\n]\n Casa: %d\n Bairro: %99[^\n]\n Cidade: %99[^\n]\n Estado: %99[^\n]\n Senha: %d\n Saldo: %f\n\n",
        &ContasPoupanca[i].agen,
        &ContasPoupanca[i].numCont,
        ContasPoupanca[i].nome,
        ContasPoupanca[i].cpf,
        &ContasPoupanca[i].nasc.dia,
        &ContasPoupanca[i].nasc.mes,
        &ContasPoupanca[i].nasc.ano,
        ContasPoupanca[i].tel,
        ContasPoupanca[i].ende,
        ContasPoupanca[i].cep,
        &ContasPoupanca[i].casa,
        ContasPoupanca[i].bairro,
        ContasPoupanca[i].cid,
        ContasPoupanca[i].est,
        &ContasPoupanca[i].senha,
        &ContasPoupanca[i].Saldo) == 16)
        {
            ContaPoupQntdd++;
            i++;
        }
    fclose(arq);
}

void lembrarContaCor()
{
    FILE *arq;
    arq = fopen("contasCor.txt", "r");
    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        system("pause");
        system("cls");
        return;
    }
    int i = 0;
    while (fscanf(arq, " Agencia: %d\n Numero da conta: %d\n Limite: %f\n Data de vencimento: %d/%d/%d\n Nome: %99[^\n]\n CPF: %99[^\n]\n Data de nascimento: %d/%d/%d\n Telefone: %99[^\n]\n Endereco: %99[^\n]\n CEP: %99[^\n]\n Casa: %d\n Bairro: %99[^\n]\n Cidade: %99[^\n]\n Estado: %99[^\n]\n Senha: %d\n Saldo: %f\n\n",
        &ContasCorrente[i].agen,
        &ContasCorrente[i].numCont,
        &ContasCorrente[i].lim,
        &ContasCorrente[i].venc.dia,
        &ContasCorrente[i].venc.mes,
        &ContasCorrente[i].venc.ano,
        ContasCorrente[i].nome,
        ContasCorrente[i].cpf,
        &ContasCorrente[i].nasc.dia,
        &ContasCorrente[i].nasc.mes,
        &ContasCorrente[i].nasc.ano,
        ContasCorrente[i].tel,
        ContasCorrente[i].ende,
        ContasCorrente[i].cep,
        &ContasCorrente[i].casa,
        ContasCorrente[i].bairro,
        ContasCorrente[i].cid,
        ContasCorrente[i].est,
        &ContasCorrente[i].senha,
        &ContasCorrente[i].Saldo) == 20)
        {
            ContaCorQntdd++;
            i++;
        }
    fclose(arq);
}

void LembrarRelatorio()
{
    FILE *arq;
    arq = fopen("relatorio.txt", "r");
    int i = 0;
        while (fscanf(arq, "Conta: %d\nDeposito: %f\n", &StructDeposito[i].NumClient, &StructDeposito[i].ValorDeposito) == 2)
        {
            QntddDeposito++;
            i++;
        }
        while (fscanf(arq, "Conta: %d\nSaque: %f\n", &StructSaque[i].NumClient, &StructSaque[i].ValorSaque) == 2)
        {
            QntddSaque++;
            i++;
        }
    fclose(arq);
}
void lembrarFuncio()
{
    FILE *arq;
    arq = fopen("funcio.txt", "r");
    int i = 0;
    while (fscanf( arq, " Codigo: %d\n Cargo: %99[^\n]\n Nome: %99[^\n]\n CPF: %99[^\n]\n Data de nascimento: %d/%d/%d\n Telefone: %99[^\n]\n Endereco: %99[^\n]\n CEP: %99[^\n]\n Casa: %d\n Bairro: %99[^\n]\n Cidade: %99[^\n]\n Estado: %99[^\n]\n Senha: %d\n\n",
    &Funcionario[i].codigoFuncionario,
    Funcionario[i].cargo,
    Funcionario[i].nome,
    Funcionario[i].cpf,
    &Funcionario[i].nasc.dia,
    &Funcionario[i].nasc.mes,
    &Funcionario[i].nasc.ano,
    Funcionario[i].tel,
    Funcionario[i].ende,
    Funcionario[i].cep,
    &Funcionario[i].casa,
    Funcionario[i].bairro,
    Funcionario[i].cid,
    Funcionario[i].est,
    &Funcionario[i].senha) == 15)
    {
        FuncioQntdd++;
        i++;
    }
    
    fclose(arq);
}

int VerSenhaADM()
{
    boolean ver = 0;
    int senhaDig; // senha digitada
    printf("Digite a senha de administrador: ");
    scanf("%d", &senhaDig);
    if(senhaADM == senhaDig) ver = 1;
    if (!ver) printf("Senha incorreta\n");
    else printf("Senha correta\n");
    system("pause");
    system("cls");
    return ver;
}

void ContaPou()
{
    int tipoConta = 0;
    if(!verGeralPoup)
    {
        printf("Digite o numero da conta do novo cliente: ");
        scanf("%d", &ContasPoupanca[ContaPoupQntdd].numCont);
        for (int j = ContaPoupQntdd - 1; j >= 0; j--)
        {
            if (ContasPoupanca[ContaPoupQntdd].numCont == ContasPoupanca[j].numCont)
            {
                printf("Numero de conta ja cadastrado\n");
                system("pause");
                system("cls");
                ContasPoupancaArq(ContaPoupQntdd);
                return;
            }
        }
        for (int j = ContaCorQntdd; j >= 0; j--)
        {
            if (ContasPoupanca[ContaPoupQntdd].numCont == ContasCorrente[j].numCont)
            {
                printf("Numero de conta ja cadastrado\n");
                system("pause");
                system("cls");
                ContasPoupancaArq(ContaPoupQntdd);
                return;
            }
        }
        verGeralPoup = 1;
    }
    if(!verificarPoup[0] && !verificarPoup[1] && !verificarPoup[2] && !verificarPoup[3] && !verificarPoup[4] && !verificarPoup[5] && !verificarPoup[6] && !verificarPoup[7] && !verificarPoup[8] && !verificarPoup[9] && !verificarPoup[10] && !verificarPoup[11]);
    else
    {
    char continuar;
        printf("Voce tem uma conta pendendente para cadastrar, quer continuar o cadastro da conta %d? (s/n)\nDigite sua opcao: ", ContasPoupanca[ContaPoupQntdd].numCont);
        scanf(" %c", &continuar);
        if (continuar == 'n' || continuar == 'N')
        {
            verGeralPoup = 0;
            verificarPoup[0]  = 0, verificarPoup[1] = 0, verificarPoup[2]  = 0, verificarPoup[3] = 0, verificarPoup[4]  = 0, verificarPoup[5] = 0, verificarPoup[6]  = 0, verificarPoup[7] = 0, verificarPoup[8]  = 0, verificarPoup[9] = 0, verificarPoup[10]  = 0, verificarPoup[11] = 0;
            ContaPou();
        }
    }

    if(!verificarPoup[0] || !verificarPoup[1] || !verificarPoup[2] || !verificarPoup[3] || !verificarPoup[4] || !verificarPoup[5] || !verificarPoup[6] || !verificarPoup[7] || !verificarPoup[8] || !verificarPoup[9] || !verificarPoup[10] || !verificarPoup[11])
    {
        int opcCadastro;
        while (opcCadastro != 13)
        {
        printf("Qual informacao da conta %d deseja incluir?\n1- Agencia\n2- Nome\n3- CPF\n4- Data de nascimento\n5- Telefone\n6- Endereco\n7- CEP\n8- Casa\n9- Bairro\n10- Cidade\n11- Estado\n12- Senha\n13- Terminar o cadastro depois\nDigite sua opcao: ", ContasPoupanca[ContaPoupQntdd].numCont);
        scanf("%d", &opcCadastro);

            switch (opcCadastro)
            {
                case 1:
                    if(verificarPoup[0] == 0)
                    {
                        printf("Digite a agencia do novo cliente: ");
                        scanf("%d", &ContasPoupanca[ContaPoupQntdd].agen);
                        verificarPoup[0]++;
                        printf("Informacao registrada com  sucesso\n");
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        InformacaoJaCadastrada;
                        ConfereOQueFaltaNoCadastro(tipoConta);
                    }
                    break;
                    
                case 2:
                    if(verificarPoup[1] == 0)
                    {
                        printf("Digite o nome do novo cliente: ");
                        fflush(stdin);
                        gets(ContasPoupanca[ContaPoupQntdd].nome);
                        verificarPoup[1]++;
                        printf("Informacao registrada com  sucesso\n");
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        InformacaoJaCadastrada;
                        ConfereOQueFaltaNoCadastro(tipoConta);
                    }
                    break;
                    
                case 3:
                    if(verificarPoup[2] == 0)
                    {
                        printf("Digite o cpf do novo cliente: ");
                        fflush(stdin);
                        gets(ContasPoupanca[ContaPoupQntdd].cpf);

                        for (int j = ContaPoupQntdd - 1; j >= 0; j--)
                        {
                            if (strcmp(ContasPoupanca[ContaPoupQntdd].cpf, ContasPoupanca[j].cpf) == 0)
                            {
                                printf("CPF ja cadastrado\n");
                                system("pause");
                                system("cls");
                                ContasPoupancaArq(ContaPoupQntdd);
                                printf("Informacao registrada com  sucesso\n");
                                system("pause");
                                system("cls");
                                return;
                            }
                        }

                        for (int j = ContaCorQntdd; j >= 0; j--)
                        {
                            if (strcmp(ContasPoupanca[ContaPoupQntdd].cpf, ContasCorrente[j].cpf) == 0)
                            {
                                printf("CPF ja cadastrado\n");
                                system("pause");
                                system("cls");
                                ContasPoupancaArq(ContaPoupQntdd);
                                printf("Informacao registrada com  sucesso\n");
                                system("pause");
                                system("cls");
                                return;
                            }
                        }
                        verificarPoup[2]++;
                        printf("Informacao registrada com  sucesso\n");
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        InformacaoJaCadastrada;
                        ConfereOQueFaltaNoCadastro(tipoConta);
                    }
                    break;
                    
                case 4:
                    if(verificarPoup[3] == 0)
                    {
                        printf("Digite a data de nascimento do novo cliente no formato (dd/mm/aa): ");
                        scanf("%d/%d/%d", &ContasPoupanca[ContaPoupQntdd].nasc.dia, &ContasPoupanca[ContaPoupQntdd].nasc.mes, &ContasPoupanca[ContaPoupQntdd].nasc.ano);
                        verificarPoup[3]++;
                        printf("Informacao registrada com  sucesso\n");
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        InformacaoJaCadastrada;
                        ConfereOQueFaltaNoCadastro(tipoConta);
                    }
                    break;
                    
                case 5:
                    if(verificarPoup[4] == 0)
                    {
                        printf("Digite o telefone do novo cliente: ");
                        fflush(stdin);
                        gets(ContasPoupanca[ContaPoupQntdd].tel);
                        verificarPoup[4]++;
                        printf("Informacao registrada com  sucesso\n");
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        InformacaoJaCadastrada;
                        ConfereOQueFaltaNoCadastro(tipoConta);
                    }
                    break;
                    
                case 6:
                    if(verificarPoup[5] == 0)
                    {
                        printf("Digite o endereco do novo cliente: ");
                        fflush(stdin);
                        gets(ContasPoupanca[ContaPoupQntdd].ende);
                        verificarPoup[5]++;
                        printf("Informacao registrada com  sucesso\n");
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        InformacaoJaCadastrada;
                        ConfereOQueFaltaNoCadastro(tipoConta);
                    }
                    break;
                    
                case 7:
                    if(verificarPoup[6] == 0)
                    {
                        printf("Digite o cep do novo cliente: ");
                        fflush(stdin);
                        gets(ContasPoupanca[ContaPoupQntdd].cep);
                        verificarPoup[6]++;
                        printf("Informacao registrada com  sucesso\n");
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        InformacaoJaCadastrada;
                        ConfereOQueFaltaNoCadastro(tipoConta);
                    }
                    break;
                    
                case 8:
                    if(verificarPoup[7] == 0)
                    {
                        printf("Digite o numero da casa do novo cliente: ");
                        scanf("%d", &ContasPoupanca[ContaPoupQntdd].casa);
                        verificarPoup[7]++;
                        printf("Informacao registrada com  sucesso\n");
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        InformacaoJaCadastrada;
                        ConfereOQueFaltaNoCadastro(tipoConta);
                    }
                    break;
                    
                case 9:
                    if(verificarPoup[8] == 0)
                    {
                        printf("Digite o bairro do novo cliente: ");
                        fflush(stdin);
                        gets(ContasPoupanca[ContaPoupQntdd].bairro);
                        verificarPoup[8]++;
                        printf("Informacao registrada com  sucesso\n");
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        InformacaoJaCadastrada;
                        ConfereOQueFaltaNoCadastro(tipoConta);
                    }
                    break;
                    
                case 10:
                    if(verificarPoup[9] == 0)
                    {
                        printf("Digite a cidade do novo cliente: ");
                        fflush(stdin);
                        gets(ContasPoupanca[ContaPoupQntdd].cid);
                        verificarPoup[9]++;
                        printf("Informacao registrada com  sucesso\n");
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        InformacaoJaCadastrada;
                        ConfereOQueFaltaNoCadastro(tipoConta);
                    }
                    break;
                    
                case 11:
                    if(verificarPoup[10] == 0)
                    {
                        printf("Digite o estado do novo cliente: ");
                        fflush(stdin);
                        gets(ContasPoupanca[ContaPoupQntdd].est);
                        verificarPoup[10]++;
                        printf("Informacao registrada com  sucesso\n");
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        InformacaoJaCadastrada;
                        ConfereOQueFaltaNoCadastro(tipoConta);
                    }
                    break;
                    
                case 12:
                    if(verificarPoup[11] == 0)
                    {
                        printf("Digite a senha do novo cliente: ");
                        scanf("%d", &ContasPoupanca[ContaPoupQntdd].senha);
                        verificarPoup[11]++;
                        printf("Informacao registrada com  sucesso\n");
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        InformacaoJaCadastrada;
                        ConfereOQueFaltaNoCadastro(tipoConta);
                    }
                    break;
                case 13:
                    break;
                default:
                    printf("Digite uma opcao valida\n");
                    
            }
            if (verificarPoup[0] && verificarPoup[1] && verificarPoup[2] && verificarPoup[3] && verificarPoup[4] && verificarPoup[5] && verificarPoup[6] && verificarPoup[7] && verificarPoup[8] && verificarPoup[9] && verificarPoup[10] && verificarPoup[11])
            {
                ContaPoupQntdd++;
                ContasPoupancaArq(ContaPoupQntdd);
                verGeralPoup = 0;
                verificarPoup[0]  = 0, verificarPoup[1] = 0, verificarPoup[2]  = 0, verificarPoup[3] = 0, verificarPoup[4]  = 0, verificarPoup[5] = 0, verificarPoup[6]  = 0, verificarPoup[7] = 0, verificarPoup[8]  = 0, verificarPoup[9] = 0, verificarPoup[10]  = 0, verificarPoup[11] = 0;
                printf("      Conta poupanca registrada com sucesso\n");
                system("pause");
                system("cls");
                return;
            }
        }
    }

    system("pause");
    system("cls");
}

void ContasPoupancaArq(int qnt) //recebe a quantidade de contas poupança pra escrever no arquivo
{
    FILE *arq;
    arq = fopen("contasPoup.txt", "w");
    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        system("pause");
        system("cls");
        return;
    }
    for (int i = 0; i < qnt; i++)
    {
        fprintf( arq, " Agencia: %d\n Numero da conta: %d\n Nome: %s\n CPF: %s\n Data de nascimento: %d/%d/%d\n Telefone: %s\n Endereco: %s\n CEP: %s\n Casa: %d\n Bairro: %s\n Cidade: %s\n Estado: %s\n Senha: %d\n Saldo: %.2f\n\n", ContasPoupanca[i].agen, ContasPoupanca[i].numCont, ContasPoupanca[i].nome, ContasPoupanca[i].cpf, ContasPoupanca[i].nasc.dia, ContasPoupanca[i].nasc.mes, ContasPoupanca[i].nasc.ano, ContasPoupanca[i].tel, ContasPoupanca[i].ende, ContasPoupanca[i].cep, ContasPoupanca[i].casa, ContasPoupanca[i].bairro, ContasPoupanca[i].cid, ContasPoupanca[i].est, ContasPoupanca[i].senha, ContasPoupanca[i].Saldo);
    }    
    fclose(arq);
}

void ContaCorre()
{
    int tipoConta = 1;
    if(!verGeralCor)
    {
        printf("Digite o numero da conta do novo cliente: ");
        scanf("%d", &ContasCorrente[ContaCorQntdd].numCont);
        for (int j = ContaCorQntdd - 1; j >= 0; j--)
        {
            if (ContasCorrente[ContaCorQntdd].numCont == ContasCorrente[j].numCont)
            {
                printf("Numero de conta ja cadastrado\n");
                system("pause");
                system("cls");
                ContasCorrenteArq(ContaCorQntdd);
                return;
            }
        }
        for (int j = ContaPoupQntdd; j >= 0; j--)
        {
            if (ContasCorrente[ContaCorQntdd].numCont == ContasPoupanca[j].numCont)
            {
                printf("Numero de conta ja cadastrado\n");
                system("pause");
                system("cls");
                ContasCorrenteArq(ContaCorQntdd);
                return;
            }
        }
        verGeralCor = 1;
    }
    if(!verificarCor[0] && !verificarCor[1] && !verificarCor[2] && !verificarCor[3] && !verificarCor[4] && !verificarCor[5] && !verificarCor[6] && !verificarCor[7] && !verificarCor[8] && !verificarCor[9] && !verificarCor[10] && !verificarCor[11] && !verificarCor[12] && !verificarCor[13]);
    else
    {
    char continuar;
        printf("Voce tem uma conta pendendente para cadastrar, quer continuar o cadastro da conta %d? (s/n)\nDigite sua opcao: ", ContasCorrente[ContaCorQntdd].numCont);
        scanf(" %c", &continuar);
        if (continuar == 'n' || continuar == 'N')
        {
            verGeralCor = 0;
            verificarCor[0]  = 0, verificarCor[1] = 0, verificarCor[2]  = 0, verificarCor[3] = 0, verificarCor[4]  = 0, verificarCor[5] = 0, verificarCor[6]  = 0, verificarCor[7] = 0, verificarCor[8]  = 0, verificarCor[9] = 0, verificarCor[10]  = 0, verificarCor[11] = 0, verificarCor[12] = 0, verificarCor[13] = 0;
            system("cls");
            ContaCorre();
        }
    }

    if(!verificarCor[0] || !verificarCor[1] || !verificarCor[2] || !verificarCor[3] || !verificarCor[4] || !verificarCor[5] || !verificarCor[6] || !verificarCor[7] || !verificarCor[8] || !verificarCor[9] || !verificarCor[10] || !verificarCor[11] || !verificarCor[12] || !verificarCor[13])
    {
        int opcCadastro;
        while (opcCadastro != 15)
        {
        printf("Qual informacao da conta %d deseja incluir?\n1- Agencia\n2- Nome\n3- CPF\n4- Data de nascimento\n5- Telefone\n6- Endereco\n7- CEP\n8- Casa\n9- Bairro\n10- Cidade\n11- Estado\n12- Senha\n13- Limite\n14- Data de vencimento\n15- Terminar o cadastro depois\nDigite sua opcao: ", ContasCorrente[ContaCorQntdd].numCont);
        scanf("%d", &opcCadastro);

            switch (opcCadastro)
            {
                case 1:
                    if(verificarCor[0] == 0)
                    {
                        printf("Digite a agencia do novo cliente: ");
                        scanf("%d", &ContasCorrente[ContaCorQntdd].agen);
                        verificarCor[0]++;
                        printf("Informacao registrada com  sucesso\n");
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        InformacaoJaCadastrada;
                        ConfereOQueFaltaNoCadastro(tipoConta);
                    }
                    break;
                    
                case 2:
                    if(verificarCor[1] == 0)
                    {
                        printf("Digite o nome do novo cliente: ");
                        fflush(stdin);
                        gets(ContasCorrente[ContaCorQntdd].nome);
                        verificarCor[1]++;
                        printf("Informacao registrada com  sucesso\n");
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        InformacaoJaCadastrada;
                        ConfereOQueFaltaNoCadastro(tipoConta);
                    }
                    break;
                    
                case 3:
                    if(verificarCor[2] == 0)
                    {
                        printf("Digite o cpf do novo cliente: ");
                        fflush(stdin);
                        gets(ContasCorrente[ContaCorQntdd].cpf);

                        for (int j = ContaCorQntdd - 1; j >= 0; j--)
                        {
                            if (strcmp(ContasCorrente[ContaCorQntdd].cpf, ContasCorrente[j].cpf) == 0)
                            {
                                printf("CPF ja cadastrado\n");
                                system("pause");
                                system("cls");
                                ContasCorrenteArq(ContaCorQntdd);
                                printf("Informacao registrada com  sucesso\n");
                                system("pause");
                                system("cls");
                                return;
                            }
                        }

                        for (int j = ContaPoupQntdd; j >= 0; j--)
                        {
                            if (strcmp(ContasCorrente[ContaCorQntdd].cpf, ContasPoupanca[j].cpf) == 0)
                            {
                                printf("CPF ja cadastrado\n");
                                system("pause");
                                system("cls");
                                ContasCorrenteArq(ContaCorQntdd);
                                printf("Informacao registrada com  sucesso\n");
                                system("pause");
                                system("cls");
                                return;
                            }
                        }
                        verificarCor[2]++;
                        printf("Informacao registrada com  sucesso\n");
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        InformacaoJaCadastrada;
                        ConfereOQueFaltaNoCadastro(tipoConta);
                    }
                    break;
                    
                case 4:
                    if(verificarCor[3] == 0)
                    {
                        printf("Digite a data de nascimento do novo cliente no formato (dd/mm/aa): ");
                        scanf("%d/%d/%d", &ContasCorrente[ContaCorQntdd].nasc.dia, &ContasCorrente[ContaCorQntdd].nasc.mes, &ContasCorrente[ContaCorQntdd].nasc.ano);
                        verificarCor[3]++;
                        printf("Informacao registrada com  sucesso\n");
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        InformacaoJaCadastrada;
                        ConfereOQueFaltaNoCadastro(tipoConta);
                    }
                    break;
                    
                case 5:
                    if(verificarCor[4] == 0)
                    {
                        printf("Digite o telefone do novo cliente: ");
                        fflush(stdin);
                        gets(ContasCorrente[ContaCorQntdd].tel);
                        verificarCor[4]++;
                        printf("Informacao registrada com  sucesso\n");
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        InformacaoJaCadastrada;
                        ConfereOQueFaltaNoCadastro(tipoConta);
                    }
                    break;
                    
                case 6:
                    if(verificarCor[5] == 0)
                    {
                        printf("Digite o endereco do novo cliente: ");
                        fflush(stdin);
                        gets(ContasCorrente[ContaCorQntdd].ende);
                        verificarCor[5]++;
                        printf("Informacao registrada com  sucesso\n");
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        InformacaoJaCadastrada;
                        ConfereOQueFaltaNoCadastro(tipoConta);
                    }
                    break;
                    
                case 7:
                    if(verificarCor[6] == 0)
                    {
                        printf("Digite o cep do novo cliente: ");
                        fflush(stdin);
                        gets(ContasCorrente[ContaCorQntdd].cep);
                        verificarCor[6]++;
                        printf("Informacao registrada com  sucesso\n");
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        InformacaoJaCadastrada;
                        ConfereOQueFaltaNoCadastro(tipoConta);
                    }
                    break;
                    
                case 8:
                    if(verificarCor[7] == 0)
                    {
                        printf("Digite o numero da casa do novo cliente: ");
                        scanf("%d", &ContasCorrente[ContaCorQntdd].casa);
                        verificarCor[7]++;
                        printf("Informacao registrada com  sucesso\n");
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        InformacaoJaCadastrada;
                        ConfereOQueFaltaNoCadastro(tipoConta);
                    }
                    break;
                    
                case 9:
                    if(verificarCor[8] == 0)
                    {
                        printf("Digite o bairro do novo cliente: ");
                        fflush(stdin);
                        gets(ContasCorrente[ContaCorQntdd].bairro);
                        verificarCor[8]++;
                        printf("Informacao registrada com  sucesso\n");
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        InformacaoJaCadastrada;
                        ConfereOQueFaltaNoCadastro(tipoConta);
                    }
                    break;
                    
                case 10:
                    if(verificarCor[9] == 0)
                    {
                        printf("Digite a cidade do novo cliente: ");
                        fflush(stdin);
                        gets(ContasCorrente[ContaCorQntdd].cid);
                        verificarCor[9]++;
                        printf("Informacao registrada com  sucesso\n");
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        InformacaoJaCadastrada;
                        ConfereOQueFaltaNoCadastro(tipoConta);
                    }
                    break;
                    
                case 11:
                    if(verificarCor[10] == 0)
                    {
                        printf("Digite o estado do novo cliente: ");
                        fflush(stdin);
                        gets(ContasCorrente[ContaCorQntdd].est);
                        verificarCor[10]++;
                        printf("Informacao registrada com  sucesso\n");
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        InformacaoJaCadastrada;
                        ConfereOQueFaltaNoCadastro(tipoConta);
                    }
                    break;
                    
                case 12:
                    if(verificarCor[11] == 0)
                    {
                        printf("Digite a senha do novo cliente: ");
                        scanf("%d", &ContasCorrente[ContaCorQntdd].senha);
                        verificarCor[11]++;
                        printf("Informacao registrada com  sucesso\n");
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        InformacaoJaCadastrada;
                        ConfereOQueFaltaNoCadastro(tipoConta);
                    }
                    break;
                case 13:
                    if(verificarCor[12] == 0)
                    {
                        printf("Digite o limite da conta do novo cliente: ");
                        scanf("%f", &ContasCorrente[ContaCorQntdd].lim);
                        verificarCor[12]++;
                        printf("Informacao registrada com  sucesso\n");
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        InformacaoJaCadastrada;
                        ConfereOQueFaltaNoCadastro(tipoConta);
                    }
                    break;
                case 14:
                    if(verificarCor[13] == 0)
                    {
                        printf("Digite a data de vencimento da conta do novo cliente no formato(dd/mm/aa): ");
                        scanf("%d/%d/%d", &ContasCorrente[ContaCorQntdd].venc.dia, &ContasCorrente[ContaCorQntdd].venc.mes, &ContasCorrente[ContaCorQntdd].venc.ano);
                        verificarCor[13]++;
                        printf("Informacao registrada com  sucesso\n");
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        InformacaoJaCadastrada;
                        ConfereOQueFaltaNoCadastro(tipoConta);
                    }
                    break;
                case 15:
                    break;
                default:
                    printf("Digite uma opcao valida\n");
            }
            if (verificarCor[0] && verificarCor[1] && verificarCor[2] && verificarCor[3] && verificarCor[4] && verificarCor[5] && verificarCor[6] && verificarCor[7] && verificarCor[8] && verificarCor[9] && verificarCor[10] && verificarCor[11] && verificarCor[12] && verificarCor[13])
            {
                ContaCorQntdd++;
                ContasCorrenteArq(ContaCorQntdd);
                verGeralPoup = 0;
                verificarCor[0]  = 0, verificarCor[1] = 0, verificarCor[2]  = 0, verificarCor[3] = 0, verificarCor[4]  = 0, verificarCor[5] = 0, verificarCor[6]  = 0, verificarCor[7] = 0, verificarCor[8]  = 0, verificarCor[9] = 0, verificarCor[10]  = 0, verificarCor[11] = 0, verificarCor[12] = 0, verificarCor[13] = 0;
                printf("      Conta corrente registrada com sucesso\n");
                system("pause");
                system("cls");
                return;
            }  
        }
    }

    system("pause");
    system("cls");
}

void ContasCorrenteArq(int qnt) //recebe a quantidade de contas corrente pra escrever no arquivo
{
    FILE *arq;
    arq = fopen("contasCor.txt", "w");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        system("pause");
        system("cls");
        return;
    }
    for (int i = 0; i < qnt; i++)
    {
        fprintf( arq, " Agencia: %d\n Numero da conta: %d\n Limite: %.2f\n Data de vencimento: %d/%d/%d\n Nome: %s\n CPF: %s\n Data de nascimento: %d/%d/%d\n Telefone: %s\n Endereco: %s\n CEP: %s\n Casa: %d\n Bairro: %s\n Cidade: %s\n Estado: %s\n Senha: %d\n Saldo: %.2f\n\n", ContasCorrente[i].agen, ContasCorrente[i].numCont, ContasCorrente[i].lim, ContasCorrente[i].venc.dia, ContasCorrente[i].venc.mes, ContasCorrente[i].venc.ano, ContasCorrente[i].nome, ContasCorrente[i].cpf, ContasCorrente[i].nasc.dia, ContasCorrente[i].nasc.mes, ContasCorrente[i].nasc.ano, ContasCorrente[i].tel, ContasCorrente[i].ende, ContasCorrente[i].cep, ContasCorrente[i].casa, ContasCorrente[i].bairro, ContasCorrente[i].cid, ContasCorrente[i].est, ContasCorrente[i].senha, ContasCorrente[i].Saldo);
    }
    fclose(arq);
}

void EncerrarCont()
{
    boolean ver = 1;
    int contaDig;
    if(VerSenhaADM()) 
    {
        printf("Digite o numero da conta para encerramento: ");
        scanf("%d", &contaDig);
        for(int i = 0; i <= LIM; i++)
        {
            if(contaDig == ContasPoupanca[i].numCont)
            {
                ContaPoupQntdd--;
                for(int j = i; j < LIM; j++) ContasPoupanca[j] = ContasPoupanca[j + 1];
                ContasPoupancaArq(ContaPoupQntdd);
                printf("             Conta poupanca deletada com sucesso\n");
                ver = 0;
                break;
            }
            if(contaDig == ContasCorrente[i].numCont)
            {
                for(int j = i; j < LIM; j++) ContasCorrente[j] = ContasCorrente[j + 1];
                ContaCorQntdd--;
                ContasCorrenteArq(ContaCorQntdd);
                printf("             Conta corrente deletada com sucesso\n");
                ver = 0;
                break;
            }
        }
    if(ver) printf("             Conta nao registrada\n");
    system("pause");
    system("cls");
    }
}

void ConsulCont()
{
    int ver = 0, NumDig; //numero da conta digitada
    printf("Digite o numero da conta para consulta-la: ");
    scanf("%d", &NumDig);
    for(int i = 0; i < ContaPoupQntdd; i++)
    {
        if(NumDig == ContasPoupanca[i].numCont)
        {
            printf("Tipo da conta: Conta Poupanca\nNome do Cliente: %s\nCPF: %s\nSaldo da conta: %.2f\n", ContasPoupanca[i].nome, ContasPoupanca[i].cpf, ContasPoupanca[i].Saldo);
            ver = 1;
            break;
        }
    }

    for(int i = 0; i < ContaCorQntdd; i++)
    {
        if(NumDig == ContasCorrente[i].numCont)
        {
            printf("Tipo da conta: Conta Corrente\nNome do Cliente: %s\nCPF: %s\nSaldo da conta: %.2f\nLimite disponivel: %.2f\nData de vencimento: %d/%d/%d\n", ContasCorrente[i].nome, ContasCorrente[i].cpf, ContasCorrente[i].Saldo, ContasCorrente[i].lim, ContasCorrente[i].venc.dia, ContasCorrente[i].venc.mes, ContasCorrente[i].venc.ano);
            ver = 1;
            break;
        }
    }
    
    if (!ver) printf("            Conta nao registrada\n");
    system("pause");
    system("cls");
}

void ConsulCliente()
{
    boolean ver = 1;
    char CPFDig[100]; //CPF digitado
    printf("Digite o CPF do cliente para consultar suas informacoes: ");
    fflush(stdin);
    gets(CPFDig);
    for (int i = 0; i < ContaPoupQntdd; i++)
    {
        if (strcmp(CPFDig, ContasPoupanca[i].cpf) == 0)
        {
            printf("Nome do Cliente: %s\nCPF do cliente: %d\nData de nascimento: %d/%d/%d\n Telefone: %s\nEndereco: %s\nNumero da casa: %d\nCEP: %s\nBairro: %s\nCidade: %s\nEstado: %s\n", ContasPoupanca[i].nome, ContasPoupanca[i].cpf, ContasPoupanca[i].nasc.dia, ContasPoupanca[i].nasc.mes, ContasPoupanca[i].nasc.ano, ContasPoupanca[i].tel, ContasPoupanca[i].ende, ContasPoupanca[i].casa, ContasPoupanca[i].cep, ContasPoupanca[i].bairro, ContasPoupanca[i].cid, ContasPoupanca[i].est);
            ver = 0;
        }
    }
    for(int i = 0; i < ContaCorQntdd; i++)
    {
        if (strcmp(CPFDig, ContasCorrente[i].cpf) == 0)
        {
            printf("Nome do Cliente: %s\nCPF do cliente: %s\nData de nascimento: %d/%d/%d\n Telefone: %s\nEndereco: %s\nNumero da casa: %d\nCEP: %s\nBairro: %s\nCidade: %s\nEstado: %s\n", ContasCorrente[i].nome, ContasCorrente[i].cpf, ContasCorrente[i].nasc.dia, ContasCorrente[i].nasc.mes, ContasCorrente[i].nasc.ano, ContasCorrente[i].tel, ContasCorrente[i].ende, ContasCorrente[i].casa, ContasCorrente[i].cep, ContasCorrente[i].bairro, ContasCorrente[i].cid, ContasCorrente[i].est);
            ver = 0;
        }
    }
    if (ver) printf("CPF nao registrado\n");
    system("pause");
    system("cls");
}

void AlterConta()
{
    boolean verPoup = 1, verCor = 1; //verifica se achou uma conta corrente ou uma poupanca
    if(VerSenhaADM())
    {
        int contaDig;
        printf("Digite o numero da conta que voce deseja alterar: ");
        scanf("%d", &contaDig);
        for (int i = 0; i < ContaPoupQntdd; i++)
        {
            int opc;
            if (ContasPoupanca[i].numCont == contaDig)
            {
                printf("Qual informacao da conta voce deseja alterar?\n1- Tipo da Conta\n2- Limite disponivel\n3- Data de vencimento\n4- Sair\nDigite sua opcao: ");
                scanf("%d", &opc);
                verPoup = 0;
                
                if (opc == 1)
                {
                    AlterTipoPoup(i);
                    for(int j = i; j < LIM; j++) ContasPoupanca[j] = ContasPoupanca[j + 1];
                    ContaPoupQntdd--;
                    ContasPoupancaArq(ContaPoupQntdd);
                    printf("\n");
                    system("pause");
                    system("cls");
                    return;
                }
                if (opc == 2)
                {
                    printf("Essa conta e do tipo poupanca, se desejar estipular um limite disponivel a altere para uma do tipo corrente.");
                    break;
                }
                if (opc == 3)
                {
                    printf("Essa conta e do tipo poupanca, se desejar estipular uma data de vencimento a altere para uma do tipo corrente.");
                    break;
                }
                if (opc == 4) break;
            }
        }
        for (int i = 0; i < ContaCorQntdd; i++)
        {
            int opc;
            if (ContasCorrente[i].numCont == contaDig)
            {
                printf("Qual informacao da conta voce deseja alterar?\n1- Tipo da Conta\n2- Limite disponivel\n3- Data de vencimento\n4- Voltar\nDigite sua opcao: ");
                scanf("%d", &opc);
                verCor = 0;
                
                if (opc == 1)
                {
                    AlterTipoCor(i);
                    for(int j = i; j < LIM; j++) ContasCorrente[j] = ContasCorrente[j + 1];
                    ContaCorQntdd--;
                    ContasCorrenteArq(ContaCorQntdd);
                    printf("\n");
                    system("pause");
                    system("cls");
                    return;
                }
                if (opc == 2)
                {
                    printf("O limite atual e %.2f, digite o novo valor: ", ContasCorrente[i].lim);
                    scanf("%f", &ContasCorrente[i].lim);
                    ContasCorrenteArq(ContaCorQntdd);
                    printf("\n");
                    system("pause");
                    system("cls");
                }
                if (opc == 3)
                {
                    printf("A data de vencimento da conta eh %d/%d/%d, digite a nova data no formato (dd/mm/aa): ", ContasCorrente[i].venc.dia, ContasCorrente[i].venc.mes, ContasCorrente[i].venc.ano);
                    scanf("%d/%d/%d", &ContasCorrente[i].venc.dia, &ContasCorrente[i].venc.mes, &ContasCorrente[i].venc.ano);
                    ContasCorrenteArq(ContaCorQntdd);
                    printf("\n");
                    system("pause");
                    system("cls");
                }
                if (opc == 4) break;
            }
        }
    if(verPoup && verCor) printf("           Conta nao encontrada\n");
    }
    system("pause");
    system("cls");
}

void AlterTipoPoup(int ContaAnt) //A conta antiga que vai ser alterada
{
    ContasCorrente[ContaCorQntdd].agen = ContasPoupanca[ContaAnt].agen;
    ContasCorrente[ContaCorQntdd].numCont = ContasPoupanca[ContaAnt].numCont;
    strcpy(ContasCorrente[ContaCorQntdd].nome, ContasPoupanca[ContaAnt].nome);

    strcpy(ContasCorrente[ContaCorQntdd].cpf, ContasPoupanca[ContaAnt].cpf);
    ContasCorrente[ContaCorQntdd].nasc = ContasPoupanca[ContaAnt].nasc;
    strcpy(ContasCorrente[ContaCorQntdd].tel, ContasPoupanca[ContaAnt].tel);
    strcpy(ContasCorrente[ContaCorQntdd].ende, ContasPoupanca[ContaAnt].ende);

    strcpy(ContasCorrente[ContaCorQntdd].cep, ContasPoupanca[ContaAnt].cep);
    ContasCorrente[ContaCorQntdd].casa = ContasPoupanca[ContaAnt].casa;

    strcpy(ContasCorrente[ContaCorQntdd].bairro, ContasPoupanca[ContaAnt].bairro);
    strcpy(ContasCorrente[ContaCorQntdd].cid, ContasPoupanca[ContaAnt].cid);
    strcpy(ContasCorrente[ContaCorQntdd].est, ContasPoupanca[ContaAnt].est);

    ContasCorrente[ContaCorQntdd].senha = ContasPoupanca[ContaAnt].senha;
    ContasCorrente[ContaCorQntdd].Saldo = ContasPoupanca[ContaAnt].Saldo;
    printf("Digite o limite da nova conta corrente: ");
    scanf("%f", &ContasCorrente[ContaCorQntdd].lim);

    printf("Digite a data de vencimento da nova conta corrente no formato (dd/mm/aa): ");
    scanf("%d/%d/%d", &ContasCorrente[ContaCorQntdd].venc.dia, &ContasCorrente[ContaCorQntdd].venc.mes, &ContasCorrente[ContaCorQntdd].venc.ano);
    ContaCorQntdd++;
    ContasCorrenteArq(ContaCorQntdd);
}

void AlterTipoCor(int ContaAnt) //A conta antiga que vai ser alterada
{
    ContasPoupanca[ContaPoupQntdd].agen = ContasCorrente[ContaAnt].agen;
    ContasPoupanca[ContaPoupQntdd].numCont = ContasCorrente[ContaAnt].numCont;
    strcpy(ContasPoupanca[ContaPoupQntdd].nome, ContasCorrente[ContaAnt].nome);

    strcpy(ContasPoupanca[ContaPoupQntdd].cpf, ContasCorrente[ContaAnt].cpf);
    ContasPoupanca[ContaPoupQntdd].nasc = ContasCorrente[ContaAnt].nasc;
    strcpy(ContasPoupanca[ContaPoupQntdd].tel, ContasCorrente[ContaAnt].tel);
    strcpy(ContasPoupanca[ContaPoupQntdd].ende, ContasCorrente[ContaAnt].ende);

    strcpy(ContasPoupanca[ContaPoupQntdd].cep, ContasCorrente[ContaAnt].cep);
    ContasPoupanca[ContaPoupQntdd].casa = ContasCorrente[ContaAnt].casa;

    strcpy(ContasPoupanca[ContaPoupQntdd].bairro, ContasCorrente[ContaAnt].bairro);
    strcpy(ContasPoupanca[ContaPoupQntdd].cid, ContasCorrente[ContaAnt].cid);
    strcpy(ContasPoupanca[ContaPoupQntdd].est, ContasCorrente[ContaAnt].est);

    ContasPoupanca[ContaPoupQntdd].senha = ContasCorrente[ContaAnt].senha;
    ContasPoupanca[ContaPoupQntdd].Saldo = ContasCorrente[ContaAnt].Saldo;
    ContaPoupQntdd++;
    ContasPoupancaArq(ContaPoupQntdd);
}

void AlterFuncio()
{
    boolean ver = 1;
    char CPFDig[100];
    if(VerSenhaADM)
    {
        printf("Digite o CPF do funcionario para mudar as suas informacoes: ");
        fflush(stdin);
        gets(CPFDig);
        for (int i = 0; i < FuncioQntdd; i++) if (strcmp(CPFDig, Funcionario[i].cpf) == 0) 
        {
            int infoFunc;
            printf("Qual informacao do funcionario voce deseja alterar?\n\n1- Codigo do Funcionario\n2- Cargo\n3- Telefone\n4- Endereco\n5- Numero da casa\n6- CEP\n7- Bairro\n8- Cidade\n9- Estado\nDigite sua opcao: ");
            scanf("%d", &infoFunc);
            switch (infoFunc)
            {
                case 1:
                    printf("O atual codigo do funcionario e %d, digite o novo codigo do funcionario: ", Funcionario[i].codigoFuncionario);
                    scanf("%d", &Funcionario[i].codigoFuncionario);
                    printf("\nAlteracao feita com sucesso");
                    FuncioArq();
                    break;
                case 2:
                    printf("O atual cargo do funcionario e %s, digite o novo cargo do funcionario: ", Funcionario[i].cargo);
                    fflush(stdin);
                    gets(Funcionario[i].cargo);
                    printf("\nAlteracao feita com sucesso");
                    FuncioArq();
                    break;
                case 3:
                    printf("O atual telefone do funcionario e %s, digite o novo telefone do funcionario: ", Funcionario[i].tel);
                    fflush(stdin);
                    gets(Funcionario[i].tel);
                    printf("\nAlteracao feita com sucesso");
                    FuncioArq();
                    break;
                case 4:
                    printf("O atual endereco do funcionario e %s, digite o novo endereco do funcionario: ", Funcionario[i].ende);
                    fflush(stdin);
                    gets(Funcionario[i].ende);
                        printf("\nAlteracao feita com sucesso");
                    FuncioArq();
                    break;
                case 5:
                    printf("O atual telefone do funcionario e %s, digite o novo telefone do funcionario: ", Funcionario[i].tel);
                    fflush(stdin);
                    gets(Funcionario[i].tel);
                    printf("\nAlteracao feita com sucesso");
                    FuncioArq();
                    break;
                case 6:
                    printf("O atual numero da casa do funcionario e %d, digite o novo numero da casa do funcionario: ", Funcionario[i].casa);
                    scanf("%d", &Funcionario[i].casa);
                    printf("\nAlteracao feita com sucesso");
                    FuncioArq();
                    break;
                case 7:
                    printf("O atual bairro do funcionario e %s, digite o novo bairro do funcionario: ", Funcionario[i].bairro);
                    fflush(stdin);
                    gets(Funcionario[i].bairro);
                    printf("\nAlteracao feita com sucesso");
                    FuncioArq();
                    break;
                case 8:
                    printf("A atual cidade do funcionario e %s, digite a nova cidade do funcionario: ", Funcionario[i].cid);
                    fflush(stdin);
                    gets(Funcionario[i].cid);
                    printf("\nAlteracao feita com sucesso");
                    FuncioArq();
                    break;
                case 9:
                    printf("O atual estado do funcionario e %s, digite o novo estado do funcionario: ", Funcionario[i].est);
                    fflush(stdin);
                    gets(Funcionario[i].est);
                    printf("\nAlteracao feita com sucesso");
                    FuncioArq();
                    break;
            }
            ver = 0;
        }
    if (ver) printf("Funcionario nao cadastrado\n");
    }
    system("pause");
    system("cls");
}

void AlterCliente()
{
    boolean ver = 1;
    char CPFDig[100];
    if(VerSenhaADM)
    {
        printf("Digite o CPF do cliente para mudar as suas informacoes: ");
        fflush(stdin);
        gets(CPFDig);
        for (int i = 0; i < ContaCorQntdd; i++) if (strcmp(CPFDig, ContasCorrente[i].cpf) == 0) 
        {
            int infoCli;
            printf("Qual informacao do cliente voce deseja alterar?\n\n1- Telefone\n2- Endereco\n3- Numero da casa\n4- CEP\n5- Bairro\n6- Cidade\n7- Estado\nDigite sua opcao: ");
            scanf("%d", &infoCli);
            switch (infoCli)
            {
                case 1:
                    printf("O atual telefone do cliente e %s, digite o novo telefone do cliente: ", ContasCorrente[i].tel);
                    fflush(stdin);
                    gets(ContasCorrente[i].tel);
                    printf("\nAlteracao feita com sucesso\n");
                    ContasCorrenteArq(ContaCorQntdd);
                    break;
                case 2:
                    printf("O atual endereco do cliente e %s, digite o novo endereco do cliente: ", ContasCorrente[i].ende);
                    fflush(stdin);
                    gets(ContasCorrente[i].ende);
                    printf("\nAlteracao feita com sucesso\n");
                    ContasCorrenteArq(ContaCorQntdd);
                    break;
                case 3:
                    printf("O atual numero da casa do cliente e %d, digite o novo numero da casa do cliente: ", ContasCorrente[i].casa);
                    scanf("%d", &ContasCorrente[i].casa);
                    printf("\nAlteracao feita com sucesso\n");
                    ContasCorrenteArq(ContaCorQntdd);
                    break;
                case 4:
                    printf("O atual CEP do cliente e %s, digite o novo CEP do cliente: ", ContasCorrente[i].cep);
                    fflush(stdin);
                    gets(ContasCorrente[i].cep);
                    printf("\nAlteracao feita com sucesso\n");
                    ContasCorrenteArq(ContaCorQntdd);
                    break;
                case 5:
                    printf("O atual bairro do cliente e %s, digite o novo bairro do cliente: ", ContasCorrente[i].bairro);
                    fflush(stdin);
                    gets(ContasCorrente[i].bairro);
                    printf("\nAlteracao feita com sucesso\n");
                    ContasCorrenteArq(ContaCorQntdd);
                    break;
                case 6:
                    printf("A cidade atual do cliente e %s, digite a nova cidade do cliente: ", ContasCorrente[i].cid);
                    fflush(stdin);
                    gets(ContasCorrente[i].cid);
                    printf("\nAlteracao feita com sucesso\n");
                    ContasCorrenteArq(ContaCorQntdd);
                    break;
                case 7:
                    printf("O atual estado do cliente e %s, digite o novo estado do cliente: ", ContasCorrente[i].est);
                    fflush(stdin);
                    gets(ContasCorrente[i].est);
                    printf("\nAlteracao feita com sucesso\n");
                    ContasCorrenteArq(ContaCorQntdd);
                    break;
            }
            ver = 0;
    }   
    
        for (int i = 0; i < ContaPoupQntdd; i++) if (strcmp(CPFDig, ContasPoupanca[i].cpf) == 0) 
        {
            int infoCli;
            printf("Qual informacao do cliente voce deseja alterar?\n\n1- Telefone\n2- Endereco\n3- Numero da casa\n4- CEP\n5- Bairro\n6- Cidade\n7- Estado\nDigite sua opcao: ");
            scanf("%d", &infoCli);
            switch (infoCli)
            {
                case 1:
                    printf("O atual telefone do cliente e %s, digite o novo telefone do cliente: ", ContasPoupanca[i].tel);
                    fflush(stdin);
                    gets(ContasPoupanca[i].tel);
                    printf("\nAlteracao feita com sucesso\n");
                    ContasPoupancaArq(ContaPoupQntdd);
                    break;
                case 2:
                    printf("O atual endereco do cliente e %s, digite o novo endereco do cliente: ", ContasPoupanca[i].ende);
                    fflush(stdin);
                    gets(ContasPoupanca[i].ende);
                    printf("\nAlteracao feita com sucesso\n");
                    ContasPoupancaArq(ContaPoupQntdd);
                    break;
                case 3:
                    printf("O atual numero da casa do cliente e %d, digite o novo numero da casa do cliente: ", ContasPoupanca[i].casa);
                    scanf("%d", &ContasPoupanca[i].casa);
                    printf("\nAlteracao feita com sucesso\n");
                    ContasPoupancaArq(ContaPoupQntdd);
                    break;
                case 4:
                    printf("O atual CEP do cliente e %s, digite o novo CEP do cliente: ", ContasPoupanca[i].cep);
                    fflush(stdin);
                    gets(ContasPoupanca[i].cep);
                    printf("\nAlteracao feita com sucesso\n");
                    ContasPoupancaArq(ContaPoupQntdd);
                    break;
                case 5:
                    printf("O atual bairro do cliente e %s, digite o novo bairro do cliente: ", ContasPoupanca[i].bairro);
                    fflush(stdin);
                    gets(ContasPoupanca[i].bairro);
                    printf("\nAlteracao feita com sucesso\n");
                    ContasPoupancaArq(ContaPoupQntdd);
                    break;
                case 6:
                    printf("A cidade atual do cliente e %s, digite a nova cidade do cliente: ", ContasPoupanca[i].cid);
                    fflush(stdin);
                    gets(ContasPoupanca[i].cid);
                    printf("\nAlteracao feita com sucesso\n");
                    ContasPoupancaArq(ContaPoupQntdd);
                    break;
                case 7:
                    printf("O atual estado do cliente e %s, digite o novo estado do cliente: ", ContasPoupanca[i].est);
                    fflush(stdin);
                    gets(ContasPoupanca[i].est);
                    printf("\nAlteracao feita com sucesso\n");
                    ContasPoupancaArq(ContaPoupQntdd);
                    break;
            }
            ver = 0;
        }
        if (ver) printf("cliente nao cadastrado\n");
    }
    
    system("pause");
    system("cls");
}

void Saldo()
{
    for (int i = 0; i < LIM; i++)
    {
    if (NumClient == ContasCorrente[i].numCont)
    {
        printf("Saldo: %.2f \n", ContasCorrente[i].Saldo );
        system("pause");
        system("cls");
        return;
    }
    if (NumClient == ContasPoupanca[i].numCont)
    {
        printf("Saldo: %.2f \n", ContasPoupanca[i].Saldo );
        system("pause");
        system("cls");
        return;
    }
    }
}

void Deposito()
{

    for (int i = 0; i < LIM; i++)
    {
        if (NumClient == ContasCorrente[i].numCont)
        {
            printf("Digite o valor que deseja depositar: ");
            float ValorDeposito;
            scanf("%f", &ValorDeposito);

            ContasCorrente[i].Saldo += ValorDeposito;

            StructDeposito[QntddDeposito].NumClient = NumClient;
            StructDeposito[QntddDeposito].ValorDeposito = ValorDeposito;
            
            ContasCorrenteArq(ContaCorQntdd);
            
            printf("Deposito de %.2f realizado com sucesso.\n", ValorDeposito);
            
            system("pause");
            system("cls");

            FILE* arq = fopen("relatorio.txt", "a");
            fprintf( arq, "Conta: %d\nDeposito: %.2f\n", StructDeposito[QntddDeposito].NumClient, StructDeposito[QntddDeposito].ValorDeposito);

            QntddDeposito++;
            fclose(arq);

            return; 
        }
        if (NumClient == ContasPoupanca[i].numCont)
        {
            printf("Digite o valor que deseja depositar: ");
            float ValorDeposito; // Valor do deposito 
            scanf("%f", &ValorDeposito);
            
            ContasPoupanca[i].Saldo += ValorDeposito;
            
            StructDeposito[QntddDeposito].NumClient = NumClient;
            StructDeposito[QntddDeposito].ValorDeposito = ValorDeposito;
            
            ContasPoupancaArq(ContaPoupQntdd);
            
            printf("Deposito de %.2f realizado com sucesso.\n", ValorDeposito);
            
            system("pause");
            system("cls");

            FILE *arq = fopen("relatorio.txt", "a");
            fprintf( arq, "Conta: %d\nDeposito: %.2f\n", StructDeposito[QntddDeposito].NumClient, StructDeposito[QntddDeposito].ValorDeposito);

            QntddDeposito++;
            fclose(arq);

            return;
        }
    }
    printf("Conta não registrada\n");

    system("pause");
    system("cls");
}

void Saque()
{

    for (int i = 0; i < LIM; i++) {
        if (NumClient == ContasCorrente[i].numCont)
        {
            float ValorSaque; // Valor do saque
            printf("Digite o valor que deseja sacar: ");
            scanf("%f", &ValorSaque);
            if (ValorSaque > ContasCorrente[i].Saldo)
            {
                printf("Saldo insuficiente\n");
                system("pause");
                system("cls");
                return;
            }
            else
            {
                ContasCorrente[i].Saldo -= ValorSaque;
                
                ContasCorrenteArq(ContaCorQntdd);
                
                StructSaque[QntddSaque].NumClient = NumClient;
                StructSaque[QntddSaque].ValorSaque = ValorSaque;
                
                printf("Saque de %.2f realizado com sucesso.\n", ValorSaque);

                FILE* arq = fopen("relatorio.txt", "a");
                fprintf( arq, "Conta: %d\nSaque: %.2f\n", StructSaque[QntddSaque].NumClient, StructSaque[QntddSaque].ValorSaque);
                QntddSaque++;
                
                fclose(arq);
                
                system("pause");
                system("cls");
            }
        }
        if (NumClient == ContasPoupanca[i].numCont)
        {
            float ValorSaque; // Valor do saque 
            printf("Digite o valor que deseja sacar: ");
            scanf("%f", &ValorSaque);
            if (ValorSaque > ContasPoupanca[i].Saldo)
            {
                printf("Saldo insuficiente\n");
                system("pause");
                system("cls");
                return;
            }
            else
            {
                ContasPoupanca[i].Saldo -= ValorSaque;

                ContasPoupancaArq(ContaPoupQntdd);
                
                StructSaque[QntddSaque].NumClient = NumClient;
                StructSaque[QntddSaque].ValorSaque = ValorSaque;

                printf("Saque de %.2f realizado com sucesso.\n", ValorSaque);

                FILE* arq = fopen("relatorio.txt", "a");
                fprintf( arq, "Conta: %d\nSaque: %.2f\n", StructSaque[QntddSaque].NumClient, StructSaque[QntddSaque].ValorSaque);
                QntddSaque++;

                fclose(arq);

                system("pause");
                system("cls");

                return;
            }
        }
    }
}

void Extrato()
{
    boolean ver = 0;

    FILE *arq = fopen("extrato.txt", "w");
    for (int i = 0; i < LIM; i++)
    {
        for (int j = 0; j < QntddSaque; j++)if (NumClient == ContasCorrente[i].numCont && StructSaque[j].NumClient == NumClient || NumClient == ContasPoupanca[i].numCont && StructSaque[j].NumClient == NumClient)
        {
            fprintf(arq, "Conta: %d\nSaque: %.2f\n",StructSaque[j].NumClient, StructSaque[j].ValorSaque);

            ver = 1;
        }
    }
    for (int i = 0; i < LIM; i++)
    {
        for (int j = 0; j < QntddDeposito; j++) if (NumClient == ContasCorrente[i].numCont && StructDeposito[j].NumClient == NumClient || NumClient == ContasPoupanca[i].numCont && StructDeposito[j].NumClient == NumClient)
        {
            fprintf(arq, "Conta: %d\nDeposito: %.2f\n", StructDeposito[j].NumClient, StructDeposito[j].ValorDeposito);
            ver = 1;
        }
    }
    fclose(arq);
    TransformarTxtEmCSV("extrato.txt", "extrato.csv");
    system("start excel extrato.csv");

    if(!ver) printf("Nenhuma transferencia feita na conta\n");
    system("pause");
    system("cls");
}

void GerarRela()
{
    int senhaDig;
    printf("Digite sua senha de funcionario para abrir o relatorio geral: ");
    scanf("%d", &senhaDig);
    if(senhaDig == SenhaFunc)
    {
        TransformarTxtEmCSV("relatorio.txt", "relatorio.csv");
        system("start excel relatorio.csv");
    }
}

void CadasFuncio()
{
    if(VerSenhaADM)
    {

        int tipoConta = 2;
        if(!verGeralFunc)
        {
            printf("Digite o codigo do novo funcionario: ");
            scanf("%d", &Funcionario[FuncioQntdd].codigoFuncionario);
            for (int j = FuncioQntdd - 1; j >= 0; j--)
            {
                if (Funcionario[FuncioQntdd].codigoFuncionario == Funcionario[j].codigoFuncionario)
                {
                    FuncioQntdd--;
                    printf("Codigo de funcionario ja cadastrado\n");
                    system("pause");
                    system("cls");
                    FuncioArq();
                    FuncioQntdd++;
                    return;
                }
            }
            verGeralFunc = 1;
        }
        if(!verificarFunc[0] && !verificarFunc[1] && !verificarFunc[2] && !verificarFunc[3] && !verificarFunc[4] && !verificarFunc[5] && !verificarFunc[6] && !verificarFunc[7] && !verificarFunc[8] && !verificarFunc[9] && !verificarFunc[10] && !verificarFunc[11] && !verificarFunc[12]);
        else
        {
        char continuar;
            printf("Voce tem um cadastro de funcionario pendendente para cadastrar, quer continuar o cadastro do funcionario de codigo %d? (s/n)\nDigite sua opcao: ", Funcionario[FuncioQntdd].codigoFuncionario);
            scanf(" %c", &continuar);
            if (continuar == 'n' || continuar == 'N')
            {
                verGeralFunc = 0;
                verificarFunc[0]  = 0, verificarFunc[1] = 0, verificarFunc[2]  = 0, verificarFunc[3] = 0, verificarFunc[4]  = 0, verificarFunc[5] = 0, verificarFunc[6]  = 0, verificarFunc[7] = 0, verificarFunc[8]  = 0, verificarFunc[9] = 0, verificarFunc[10]  = 0, verificarFunc[11] = 0, verificarFunc[12] = 0;
                system("cls");
                ContaCorre();
            }
        }

       if(!verificarFunc[0] || !verificarFunc[1] || !verificarFunc[2] || !verificarFunc[3] || !verificarFunc[4] || !verificarFunc[5] || !verificarFunc[6] || !verificarFunc[7] || !verificarFunc[8] || !verificarFunc[9] || !verificarFunc[10] || !verificarFunc[11])
        {
            int opcCadastro;
            while (opcCadastro != 13)
            {
            printf("Qual informacao do funcionario de codigo %d deseja incluir?\n1- Cargo\n2- Nome\n3- CPF\n4- Data de nascimento\n5- Telefone\n6- Endereco\n7- CEP\n8- Casa\n9- Bairro\n10- Cidade\n11- Estado\n12- Senha\n13- Terminar o cadastro depois\nDigite sua opcao: ", Funcionario[FuncioQntdd].codigoFuncionario);
            scanf("%d", &opcCadastro);

               switch (opcCadastro)
               {
                   case 1:
                       if(verificarFunc[0] == 0)
                       {
                           printf("Digite o cargo do novo funcionario: ");
                           fflush(stdin);
                           gets(Funcionario[FuncioQntdd].cargo);
                           verificarFunc[0]++;
                           printf("Informacao registrada com  sucesso\n");
                            system("pause");
                          system("cls");
                       }
                       else
                       {
                           InformacaoJaCadastrada;
                           ConfereOQueFaltaNoCadastro(tipoConta);
                       }
                       break;

                   case 2:
                       if(verificarFunc[1] == 0)
                       {
                           printf("Digite o nome do novo funcionario: ");
                           fflush(stdin);
                           gets(Funcionario[FuncioQntdd].nome);
                           verificarFunc[1]++;
                           printf("Informacao registrada com  sucesso\n");
                           system("pause");
                           system("cls");
                       }
                       else
                       {
                           InformacaoJaCadastrada;
                           ConfereOQueFaltaNoCadastro(tipoConta);
                       }
                       break;

                   case 3:
                       if(verificarFunc[2] == 0)
                       {
                           printf("Digite o cpf do novo funcionario: ");
                           fflush(stdin);
                           gets(Funcionario[FuncioQntdd].cpf);

                           for (int j = FuncioQntdd - 1; j >= 0; j--)
                           {
                               if (strcmp(Funcionario[FuncioQntdd].cpf, Funcionario[j].cpf) == 0)
                               {
                                   FuncioQntdd--;
                                   printf("CPF ja cadastrado\n");
                                   system("pause");
                                   system("cls");
                                   FuncioArq();
                                    FuncioQntdd++;
                                    printf("Informacao registrada com  sucesso\n");
                                    system("pause");
                                    system("cls");
                                    return;
                                }
                            }
                            verificarFunc[2]++;
                            printf("Informacao registrada com  sucesso\n");
                            system("pause");
                            system("cls");
                        }
                        else
                        {
                            InformacaoJaCadastrada;
                            ConfereOQueFaltaNoCadastro(tipoConta);
                        }
                        break;

                    case 4:
                        if(verificarFunc[3] == 0)
                        {
                            printf("Digite a data de nascimento do novo funcionario no formato (dd/mm/aa): ");
                            scanf("%d/%d/%d", &Funcionario[FuncioQntdd].nasc.dia, &Funcionario[FuncioQntdd].nasc.mes, &Funcionario[FuncioQntdd].nasc.ano);
                        verificarFunc[3]++;
                        printf("Informacao registrada com  sucesso\n");
                            system("pause");
                            system("cls");
                        }
                        else
                        {
                        InformacaoJaCadastrada;
                        ConfereOQueFaltaNoCadastro(tipoConta);
                        }
                        break;

                    case 5:
                        if(verificarFunc[4] == 0)
                        {
                            printf("Digite o telefone do novo funcionario: ");
                            fflush(stdin);
                            gets(Funcionario[FuncioQntdd].tel);
                            verificarFunc[4]++;
                            printf("Informacao registrada com  sucesso\n");
                            system("pause");
                            system("cls");
                        }
                        else
                        {
                            InformacaoJaCadastrada;
                            ConfereOQueFaltaNoCadastro(tipoConta);
                        }
                        break;

                    case 6:
                        if(verificarFunc[5] == 0)
                        {
                            printf("Digite o endereco do novo funcionario: ");
                            fflush(stdin);
                            gets(Funcionario[FuncioQntdd].ende);
                            verificarFunc[5]++;
                            printf("Informacao registrada com  sucesso\n");
                            system("pause");
                            system("cls");
                        }
                        else
                        {
                            InformacaoJaCadastrada;
                            ConfereOQueFaltaNoCadastro(tipoConta);
                        }
                        break;

                    case 7:
                        if(verificarFunc[6] == 0)
                        {
                            printf("Digite o cep do novo funcionario: ");
                            fflush(stdin);
                            gets(Funcionario[FuncioQntdd].cep);
                            verificarFunc[6]++;
                            printf("Informacao registrada com  sucesso\n");
                            system("pause");
                            system("cls");
                        }
                        else
                        {
                            InformacaoJaCadastrada;
                            ConfereOQueFaltaNoCadastro(tipoConta);
                        }
                        break;

                    case 8:
                        if(verificarFunc[7] == 0)
                        {
                            printf("Digite o numero da casa do novo funcionario: ");
                            scanf("%d", &Funcionario[FuncioQntdd].casa);
                            verificarFunc[7]++;
                            printf("Informacao registrada com  sucesso\n");
                            system("pause");
                            system("cls");
                        }
                        else
                        {
                            InformacaoJaCadastrada;
                            ConfereOQueFaltaNoCadastro(tipoConta);
                        }
                        break;

                    case 9:
                        if(verificarFunc[8] == 0)
                        {
                            printf("Digite o bairro do novo funcionario: ");
                            fflush(stdin);
                            gets(Funcionario[FuncioQntdd].bairro);
                            verificarFunc[8]++;
                            printf("Informacao registrada com  sucesso\n");
                            system("pause");
                            system("cls");
                        }
                        else
                        {
                            InformacaoJaCadastrada;
                            ConfereOQueFaltaNoCadastro(tipoConta);
                        }
                        break;

                    case 10:
                        if(verificarFunc[9] == 0)
                        {
                            printf("Digite a cidade do novo funcionario: ");
                            fflush(stdin);
                            gets(Funcionario[FuncioQntdd].cid);
                            verificarFunc[9]++;
                            printf("Informacao registrada com  sucesso\n");
                            system("pause");
                            system("cls");
                        }
                        else
                        {
                            InformacaoJaCadastrada;
                            ConfereOQueFaltaNoCadastro(tipoConta);
                        }
                        break;

                    case 11:
                        if(verificarFunc[10] == 0)
                        {
                            printf("Digite o estado do novo funcionario: ");
                            fflush(stdin);
                            gets(Funcionario[FuncioQntdd].est);
                            verificarFunc[10]++;
                            printf("Informacao registrada com  sucesso\n");
                            system("pause");
                            system("cls");
                        }
                        else
                        {
                            InformacaoJaCadastrada;
                            ConfereOQueFaltaNoCadastro(tipoConta);
                        }
                        break;

                    case 12:
                        if(verificarFunc[11] == 0)
                        {
                            printf("Digite a senha do novo funcionario: ");
                            scanf("%d", &Funcionario[FuncioQntdd].senha);
                            verificarFunc[11]++;
                            printf("Informacao registrada com  sucesso\n");
                            system("pause");
                            system("cls");
                        }
                        else
                        {
                            InformacaoJaCadastrada;
                            ConfereOQueFaltaNoCadastro(tipoConta);
                        }
                        break;
                    case 13:
                        break;
                    default:
                        printf("Digite uma opcao valida\n");
                }
                if (verificarFunc[0] && verificarFunc[1] && verificarFunc[2] && verificarFunc[3] && verificarFunc[4] && verificarFunc[5] && verificarFunc[6] && verificarFunc[7] && verificarFunc[8] && verificarFunc[9] && verificarFunc[10] && verificarFunc[11])
                {
                    FuncioQntdd++;
                    FuncioArq();
                    verGeralPoup = 0;
                    verificarFunc[0]  = 0, verificarFunc[1] = 0, verificarFunc[2]  = 0, verificarFunc[3] = 0, verificarFunc[4]  = 0, verificarFunc[5] = 0, verificarFunc[6]  = 0, verificarFunc[7] = 0, verificarFunc[8]  = 0, verificarFunc[9] = 0, verificarFunc[10]  = 0, verificarFunc[11] = 0;
                    printf("      Funcionario registrado com sucesso\n");
                    system("pause");
                    system("cls");
                    return;
                }  
            }
        }
    }
    system("pause");
    system("cls");
}

void FuncioArq()
{
    FILE *arq;
    arq = fopen("funcio.txt", "w");
    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        system("pause");
        system("cls");
        return;
    }
    for (int i = 0; i < FuncioQntdd; i++)
    {
        fprintf( arq, " Codigo: %d\n Cargo: %s\n Nome: %s\n CPF: %s\n Data de nascimento: %d/%d/%d\n Telefone: %s\n Endereco: %s\n CEP: %s\n Casa: %d\n Bairro: %s\n Cidade: %s\n Estado: %s\n Senha: %d\n\n", Funcionario[i].codigoFuncionario, Funcionario[i].cargo, Funcionario[i].nome, Funcionario[i].cpf, Funcionario[i].nasc.dia, Funcionario[i].nasc.mes, Funcionario[i].nasc.ano, Funcionario[i].tel, Funcionario[i].ende, Funcionario[i].cep, Funcionario[i].casa, Funcionario[i].bairro, Funcionario[i].cid, Funcionario[i].est, Funcionario[i].senha);
    }    
    fclose(arq);
}

void ConsulFuncio()
{
    boolean ver = 1;
    char CPFDig[100]; //CPF digitado
    printf("Digite o CPF do funcionario para consultar as informacoes: ");
    fflush(stdin);
    gets(CPFDig);
    for (int i = 0; i < FuncioQntdd; i++)
    {
        if (strcmp (CPFDig, Funcionario[i].cpf) == 0)
        {
            printf(" Codigo: %d\n Cargo: %s\n Nome: %s\n CPF: %s\n Data de nascimento: %d/%d/%d\n Telefone: %s\n Endereco: %s\n CEP: %s\n Casa: %d\n Bairro: %s\n Cidade: %s\n Estado: %s\n Senha: %d\n\n", Funcionario[i].codigoFuncionario, Funcionario[i].cargo, Funcionario[i].nome, Funcionario[i].cpf, Funcionario[i].nasc.dia, Funcionario[i].nasc.mes, Funcionario[i].nasc.ano, Funcionario[i].tel, Funcionario[i].ende, Funcionario[i].cep, Funcionario[i].casa, Funcionario[i].bairro, Funcionario[i].cid, Funcionario[i].est, Funcionario[i].senha);
            ver = 0;
        }
    }
    if (ver) printf("CPF nao registrado\n");
    system("pause");
    system("cls");
}

void ConsulLim()
{
    boolean ver = 1;
    for (int i = 0, j = 0; i < ContaCorQntdd, j < ContaPoupQntdd; i++, j++)
    {
        if (NumClient == ContasCorrente[i].numCont)
        {
            printf(" Limite da conta corrente: %.2f\n ", ContasCorrente[i].lim);
            ver = 0;
        }
        else if(NumClient == ContasPoupanca[j].numCont)
        {
            printf("Sua conta e do tipo poupanca, nao possui limites.\n");
            return;
        }
    }
    if (ver) printf("Numero da conta nao registrado\n");
    system("pause");
    system("cls");
}