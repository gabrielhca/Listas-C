# Sistema de Abastecimento de Naves Espaciais

Este diretório contém uma implementação em C de um sistema de abastecimento para uma frota de naves em órbita circular. O programa utiliza uma lista circular para simular o processo de abastecimento sequencial de naves em uma missão interplanetária.

## Descrição do Problema

As naves estão dispostas em uma órbita circular ao redor de uma estação espacial, e o sistema precisa garantir que todas sejam abastecidas de forma eficiente. Cada nave possui uma capacidade de combustível diferente, e o sistema de abastecimento segue uma ordem cíclica, reabastecendo as naves em sequência.

## Estrutura do Código

O programa está dividido em três arquivos:
- `main.c`: Contém a função principal que inicializa o sistema
- `fuel.c`: Implementa as funções de gerenciamento da lista circular e operações de abastecimento
- `fuel.h`: Define as estruturas de dados e protótipos das funções

### Estruturas de Dados
- `Fuel`: Representa uma nave com sua capacidade máxima e quantidade atual de combustível
- `Descriptor`: Gerencia a lista circular, mantendo um ponteiro para a cauda e o tamanho da lista

## Funcionalidades

- Criação de uma lista circular para representar a órbita das naves
- Definição da capacidade máxima de combustível para cada nave
- Registro da quantidade inicial de combustível de cada nave
- Abastecimento cíclico das naves até que todas estejam com os tanques cheios

## Exemplo de Uso

No arquivo `main.c`, cinco naves são criadas com diferentes capacidades:
```c
capacityFuel(starships, 75);
capacityFuel(starships, 100);
capacityFuel(starships, 90);
capacityFuel(starships, 120);
capacityFuel(starships, 100);
```

O usuário é então solicitado a informar a quantidade inicial de combustível para cada nave, respeitando a capacidade máxima. Em seguida, o sistema solicita a quantidade de combustível a ser distribuída por ciclo e realiza o abastecimento até que todas as naves estejam com os tanques cheios.

## Como Compilar e Executar

```bash
gcc -o sistema_abastecimento main.c fuel.c -I.
./sistema_abastecimento
```

## Implementação

O programa utiliza uma estrutura de lista circular, onde cada nó contém:
- Capacidade máxima de combustível da nave
- Quantidade atual de combustível
- Ponteiro para a próxima nave na órbita

O algoritmo percorre a lista circular, abastecendo cada nave sequencialmente e ignorando aquelas que já estão com o tanque cheio, até que todas estejam completamente abastecidas.