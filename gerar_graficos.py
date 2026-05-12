import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
import numpy as np

# 1. Carregamento dos dados
# O script tenta ler as colunas exatas informadas. Caso o CSV tenha sido gerado
# com os nomes antigos do script em C, ele faz o mapeamento automaticamente.
try:
    df = pd.read_csv('resultados.csv')
    
    renames = {
        'Distribuicao': 'Cenário', 
        'TempoMedio_Segundos': 'Tempo(s)'
    }
    df.rename(columns=renames, inplace=True, errors='ignore')
    
    df['Cenário'] = df['Cenário'].str.replace('ó', 'o').str.replace('é', 'e')
    
except FileNotFoundError:
    print("Erro: Arquivo 'resultados.csv' não encontrado no diretório atual.")
    exit()

# 2. Tratamento de Falhas (Quick Sort Stack Overflow)
# Tempos nulos ou negativos (indicadores de falha/pior caso) são convertidos para NaN.
# Isso garante que o Matplotlib interrompa a linha no gráfico, evidenciando a falha sem distorcer o eixo Y.
df['Tempo(s)'] = df['Tempo(s)'].apply(lambda x: np.nan if x <= 0 else x)

# 3. Processamento de Médias
# Se houver coluna 'Amostra', agrupa e tira a média. Se não houver, apenas consolida.
if 'Amostra' in df.columns:
    df_agg = df.groupby(['Algoritmo', 'Cenário', 'Tamanho'])['Tempo(s)'].mean().reset_index()
else:
    df_agg = df.copy()

# 4. Geração de Tabelas (Markdown)
def gerar_tabela_markdown(cenario_nome):
    df_cenario = df_agg[df_agg['Cenário'].str.contains(cenario_nome, case=False, na=False)]
    if df_cenario.empty:
        return
        
    pivot = df_cenario.pivot(index='Tamanho', columns='Algoritmo', values='Tempo(s)')
    
    print(f"\n### Tabela Comparativa: Cenário {cenario_nome.capitalize()}")
    
    pivot_tratado = pivot.fillna("Estouro de Pilha")
    print(pivot_tratado.to_markdown(floatfmt=".6f"))

# 5. Geração de Gráficos
sns.set_theme(style="whitegrid")
paleta_cores = {'QuickSort': '#e74c3c', 'HeapSort': '#3498db', 'RadixSort': '#2ecc71'}

fig, axes = plt.subplots(1, 2, figsize=(16, 6))
fig.suptitle('Análise Empírica de Escalabilidade e Sensibilidade', fontsize=16, fontweight='bold')

# Gráfico 1: Escalabilidade
df_aleatorio = df_agg[df_agg['Cenário'].str.contains('Aleatorio', case=False, na=False)]
sns.lineplot(
    ax=axes[0], data=df_aleatorio, x='Tamanho', y='Tempo(s)', 
    hue='Algoritmo', marker='o', palette=paleta_cores, linewidth=2.5
)
axes[0].set_xscale('log')
axes[0].set_title('Desempenho no Cenário Aleatório (Caso Médio)', fontsize=14)
axes[0].set_xlabel('Tamanho do Vetor (Log Scale)', fontsize=12)
axes[0].set_ylabel('Tempo de Execução (Segundos)', fontsize=12)

# Gráfico 2: Sensibilidade
df_crescente = df_agg[df_agg['Cenário'].str.contains('Crescente', case=False, na=False)]
sns.lineplot(
    ax=axes[1], data=df_crescente, x='Tamanho', y='Tempo(s)', 
    hue='Algoritmo', marker='X', palette=paleta_cores, linewidth=2.5, linestyle='--'
)
axes[1].set_xscale('log')
axes[1].set_title('Degradação do Quick Sort (Cenário Crescente)', fontsize=14)
axes[1].set_xlabel('Tamanho do Vetor (Log Scale)', fontsize=12)
axes[1].set_ylabel('Tempo de Execução (Segundos)', fontsize=12)

plt.tight_layout()
plt.savefig('graficos_comparativos.png', dpi=300)
print("\nGráficos gerados e salvos como 'graficos_comparativos.png'.")
plt.show()