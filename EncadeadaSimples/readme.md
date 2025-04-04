# Sistema de Cadastro de Alunos

Este diretório contém uma implementação em C de um sistema de cadastro de alunos utilizando uma lista encadeada. O programa permite gerenciar informações sobre alunos, incluindo seus nomes e notas em componentes práticos e teóricos.

## Funcionalidades

O sistema oferece as seguintes operações:

- Criação de uma lista vazia
- Inserção de alunos (nome, nota prática, nota teórica)
- Busca de alunos pelo nome, retornando sua nota final
- Listagem de alunos com média superior a 70
- Remoção de alunos da lista
- Liberação da memória alocada para a lista

## Estrutura do Código

O programa está dividido em três arquivos:
- `main.c`: Implementa o menu de interação com o usuário
- `aluno.c`: Contém as funções para manipulação da lista de alunos
- `aluno.h`: Define a estrutura de dados e os protótipos das funções

### Estrutura de Dados
O programa utiliza uma estrutura encadeada simples onde cada nó contém:
- Nome do aluno (até 30 caracteres)
- Nota prática (até 50 pontos)
- Nota teórica (até 50 pontos)
- Ponteiro para o próximo aluno na lista

## Menu de Opções

O sistema apresenta um menu com as seguintes opções:
1. Inserir aluno (nome, nota prática, nota teórica)
2. Buscar aluno por nome e retornar a soma das notas
3. Listar alunos com média superior a 70
4. Remover aluno da lista
5. Sair do programa

## Como Compilar e Executar

```bash
gcc -o cadastro_alunos main.c aluno.c -I.
./cadastro_alunos
```

## Exemplo de Uso

- Para inserir um aluno, selecione a opção 1 e forneça o nome e as notas
- Para buscar a nota final de um aluno, selecione a opção 2 e informe o nome completo
- Para ver os alunos aprovados (média > 70), selecione a opção 3
- Para remover um aluno, selecione a opção 4 e informe o nome completo
- Para sair do programa, selecione a opção 5

## Implementação

A lista é implementada como uma estrutura encadeada simples, onde cada inserção é feita no início da lista para maior eficiência. As buscas e remoções percorrem a lista até encontrar o aluno com o nome correspondente.

O programa gerencia adequadamente a memória, liberando os recursos alocados ao finalizar a execução.