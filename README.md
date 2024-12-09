### Como rodar o projeto?

1. **Baixar e instalar o VS Code**  
   - Acesse o site oficial do [Visual Studio Code](https://code.visualstudio.com/) e instale a versão para o seu sistema operacional.

2. **Instalar a extensão C/C++**  
   - Abra o VS Code, vá até a aba de extensões (ícone de quadrado no menu à esquerda ou use `Ctrl+Shift+X`) e procure pela extensão **C/C++** (desenvolvida pela Microsoft). Instale-a.

3. **Instalar o MinGW**  
   - Baixe o MinGW ou MinGW-w64 do [site oficial](http://mingw-w64.org/).  
   - Durante a instalação, selecione o compilador para **x86_64**.  
   - Após instalar, copie o caminho do diretório `bin` (ex.: `C:\mingw-w64\bin`).  
   - **Adicione o MinGW ao PATH** do sistema:  
     - No Windows, abra as **Configurações do Sistema** > **Variáveis de Ambiente** > Edite a variável `Path` e adicione o caminho do `bin`.

4. **Instalar a extensão Code Runner**  
   - No VS Code, vá até a aba de extensões e procure por **Code Runner**. Instale a extensão.

5. **Rode o projeto**
   - Vá até main.c e no canto superior direito clique em **Run code**.
