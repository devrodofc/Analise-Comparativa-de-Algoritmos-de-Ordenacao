# Análise Comparativa de Algoritmos de Ordenação

Um projeto acadêmico que implementa e compara o desempenho de três algoritmos de ordenação clássicos: **Quick Sort**, **Heap Sort** e **Radix Sort**.

## 📋 Descrição

Este projeto realiza uma análise experimental de algoritmos de ordenação em diferentes cenários (dados aleatórios, crescentes e decrescentes) e com múltiplos tamanhos de entrada. Os resultados são exportados em formato CSV e visualizados através de gráficos e tabelas comparativas.

## 🗂️ Estrutura do Projeto

```
├── src/                # Código-fonte em C
│   ├── main.c          # Ponto de entrada do programa
│   ├── experiment.c    # Motor de execução dos testes
│   ├── quicksort.c     # Implementação do Quick Sort
│   ├── heapsort.c      # Implementação do Heap Sort
│   ├── radixsort.c     # Implementação do Radix Sort
│   └── utils.c         # Funções utilitárias
├── include/            # Arquivos cabeçalho
│   ├── experiment.h    # Interface dos experimentos
│   ├── sorts.h         # Interface dos algoritmos
├── obj/                # Diretório para arquivos compilados (.o)
├── Makefile            # Script de compilação e execução
├── gerar_graficos.py   # Script Python para visualização de dados
└── README.md           # Este arquivo
```

## 🔧 Requisitos

### Para Compilação e Execução
- **GCC** (ou outro compilador C compatível)
- **Make** (para executar o Makefile)
- **Biblioteca Math** (libm, geralmente incluída no sistema)

### Para Visualização de Resultados
- **Python 3.7+**
- Dependências Python:
  - `pandas`
  - `matplotlib`
  - `seaborn`
  - `numpy`

## 🚀 Como Usar

### 1. Compilar o Projeto
```bash
mingw32-make all      # Compila o executável
```

### 2. Executar os Experimentos
```bash
mingw32-make run      # Compila, executa os testes e gera resultados.csv
```

Ou manualmente:
```bash
./ordenador > resultados.csv
```

### 3. Gerar Gráficos e Tabelas
```bash
python gerar_graficos.py
```

Este comando irá:
- Carregar os dados do arquivo `resultados.csv`
- Gerar tabelas comparativas em formato Markdown
- Criar visualizações gráficas dos resultados

## 📊 Algoritmos Implementados

### Quick Sort
- **Particionamento**: Estratégia de Lomuto
- **Complexidade**: O(n log n) em média, O(n²) no pior caso
- **Características**: In-place, instável

### Heap Sort
- **Estrutura**: Heap Máximo
- **Complexidade**: O(n log n) em todos os casos
- **Características**: In-place, instável

### Radix Sort
- **Subtipo**: Counting Sort estável
- **Suporte**: Apenas inteiros decimais não negativos
- **Complexidade**: O(d × n), onde d é o número de dígitos
- **Características**: Estável, linear para inteiros

## 📈 Cenários de Teste

Os experimentos executam os três algoritmos em três cenários diferentes:

1. **Aleatório**: Dados com ordem aleatória
2. **Crescente**: Dados já ordenados em ordem crescente
3. **Decrescente**: Dados ordenados em ordem decrescente

Cada cenário é testado com múltiplos tamanhos de entrada para análise de escalabilidade.

## 📁 Saída dos Experimentos

O arquivo `resultados.csv` contém as seguintes colunas:

- `Algoritmo`: Nome do algoritmo testado
- `Cenário`: Distribuição dos dados (Aleatório, Crescente, Decrescente)
- `Tamanho`: Número de elementos no vetor
- `Tempo(s)`: Tempo de execução em segundos

## ⚠️ Observações Importantes

- O **Quick Sort** pode sofrer estouro de pilha (_stack overflow_) em certos casos, especialmente com dados em ordem decrescente. O script de visualização marca estas falhas como "Estouro de Pilha".
- O **Radix Sort** suporta apenas números inteiros não negativos.
- Os tempos medidos são em segundos e podem variar dependendo do sistema.

## 👨‍💻 Compilação Detalhada

O Makefile utiliza as seguintes opções:
- `-std=c11`: Padrão C11
- `-O3`: Otimização de compilação (nível 3)
- `-Wextra -Wall`: Avisos adicionais durante compilação
- `-I./include`: Inclui diretório de headers

## 📝 Licença

Este projeto é acadêmico e fornecido por Rodrigo Herrmann.