# Implementação de algoritmos em grafos

<picture>
  <source media="(prefers-color-scheme: dark)" srcset="./.github/cover.png">
  <source media="(prefers-color-scheme: light)" srcset="./.github/cover_light.png">
  <img alt="Implementação de algoritmos em grafos" src="/.github/cover_light.png">
</picture>

Neste repositório, você encontrará implementações de diversos algoritmos de grafos com foco em eficiência e precisão.  
Entre os algoritmos abordados estão **DFS (Depth-First Search)**, **BFS (Breadth-First Search)**, algoritmos para **componentes fortemente conexos** (como Kosaraju), **Árvore Geradora Mínima** (Prim e Kruskal) e **Caminhos Mínimos** (Dijkstra).

Este projeto prático foi desenvolvido como requisito para a disciplina de **Teoria dos Grafos** na **Universidade Federal de Alagoas** (UFAL), com o objetivo de consolidar conceitos teóricos por meio de implementações práticas e testes robustos que garantem a corretude dos algoritmos em diferentes cenários.

## 🧪 Testes

Para testar os algoritmos utilizando a bateria `Bat1`, desenvolvida pelo [professor Rian](https://ic.ufal.br/professor/rian/), siga as instruções abaixo.  
**Este ambiente requer um sistema Linux** (distribuições Linux nativas ou o WSL no Windows funcionam adequadamente).

### ⚙️ Pré-requisitos

1. **Instale o pacote `gawk`** no ambiente Linux (caso não esteja instalado):
    ```bash
    sudo apt update
    sudo apt install gawk
    ```
2. Após a instalação, **verifique se o pacote foi instalado com sucesso** ao rodar `gawk` no terminal.

> [!TIP]  
Caso o comando `gawk` não funcione após a instalação, reinicie o terminal e tente novamente. Se o problema persistir, verifique se houve erros durante a instalação.

### 🧩 Teste dos Algoritmos
Para rodar os testes dos algoritmos de grafos implementados,

1. **Compile os algoritmos**:
    - Acesse a pasta do algoritmo e execute:
      ```bash
      cd [nome do algoritmo]
      make
      ```
    - Em seguida, mova o executável gerado para a pasta `tests/Bat1`.

> [!NOTE]  
A pasta `tests/Bat1` já contém a versão mais recente dos algoritmos. Esse passo é necessário apenas se você tiver feito atualizações manuais.

2. **Dê permissão de execução** aos arquivos da bateria de testes e ao(s) algoritmo(s) desejado(s):
    ```bash
    chmod +x Bat1.sh ordena.sh kosaraju.bin
    ```

3. **Execute o script de testes** `Bat1.sh` para iniciar a verificação dos algoritmos:
    ```bash
    ./Bat1.sh
    ```
   Esse script automatiza a execução e verifica se os algoritmos funcionam conforme esperado.

## 🐞 Debugging

Para realizar o debug de um algoritmo específico, ajuste os arquivos `launch.json` e `tasks.json` para o nome do algoritmo desejado.

> Exemplo: para testar o algoritmo de **Kosaraju**, os arquivos teriam a seguinte configuração:

<details>
  <summary><strong>launch.json</strong></summary>

  ```json
  {
      "configurations": [
          {
              // ...
              "program": "${workspaceFolder}/kosaraju/kosaraju.bin",
              "args": [
                  "-f",
                  "graph.dat"
              ],
              // ...
          }
      ]
  }
  ```
</details>

<details>
  <summary><strong>tasks.json</strong></summary>

  ```json
  {
      "version": "2.0.0",
      "tasks": [
          {
              // ...
              "options": {
                  "cwd": "${workspaceFolder}/kosaraju"
              },
              // ...
          }
      ]
  }
  ```
</details>

Essas configurações permitem o uso de **debugging em ambientes como VS Code**, facilitando a análise dos algoritmos em execução.



## 📝 Licença

Este projeto utiliza a MIT License. Veja o arquivo de [LICENÇA](LICENSE) para mais detalhes.