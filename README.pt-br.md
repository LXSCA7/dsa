# Estruturas de Dados e Algoritmos em C

[English Version](README.md)

Este repositório é um projeto de estudo pessoal para implementar estruturas de dados e algoritmos clássicos em C puro, com foco em código limpo, modular e eficiente.

---

## Estruturas de Dados Implementadas

- [x] **Linked list**: A base para outras estruturas de dados.
- [x] **Queue**: Implementada sobre a Lista Encadeada (LIFO).
- [x] **Stack**: Implementada sobre a Lista Encadeada (FIFO).
- [ ] **Árvore Binária de Busca (BST)**
- [ ] **Hash Table**

---

## Como Executar

### Pré-requisitos
Para compilar e executar este projeto, você precisa de:
- git;
- Um compilador C. (gcc, clang);
- make.

### Passos

1.  **Clone o repositório:**
      ```bash
      git clone https://github.com/LXSCA7/dsa.git
      cd dsa
      ```

2.  **Compile o projeto:**
A maneira mais fácil e recomendada é usar o `Makefile` fornecido. No seu terminal, na raiz do projeto, execute:
      ```bash
      make
      ```
    Isso irá compilar todos os arquivos-fonte e criar o executável `main` dentro de uma pasta `bin/`.

3.  **Execute o programa:**
   Você pode usar outra regra do `Makefile` para executar o programa diretamente:
      ```bash
      make run
      ```

### Comandos úteis do makefile
- `make`: Compila o projeto.
- `make run`: Compila (se necessário) e executa o projeto.
- `make clean`: Remove todos os arquivos gerados pela compilação (a pasta `bin/`).
