estoque_atual = {
    "canetas": 150,
    "cadernos": 95,
    "borrachas": 60,
    "lapis": 120,
    "marcadores": 80,
    "papel sulfite": 200,
    "post-it": 75,
    "cola": 40,
}

movimentacoes_dia = [
    ("canetas", "saída", 25),
    ("cadernos", "entrada", 10),
    ("borrachas", "saída", 50),
    ("lapis", "saída", 30),
    ("marcadores", "entrada", 20),
    ("papel sulfite", "saída", 60),
    ("post-it", "saída", 30),
    ("cola", "entrada", 25),
    ("canetas", "entrada", 40),
    ("cadernos", "saída", 60),
    ("borrachas", "entrada", 20),
    ("lapis", "entrada", 10),
    ("marcadores", "saída", 50),
    ("papel sulfite", "entrada", 40),
    ("post-it", "entrada", 15),
    ("cola", "saída", 30),
    ("apontador", "entrada", 35),
    ("apontador", "saída", 10),
]

# Processamento das movimentações
for produto, tipo, quantidade in movimentacoes_dia:
    if tipo == "entrada":
        if produto in estoque_atual:
            estoque_atual[produto] += quantidade
        else:
            estoque_atual[produto] = quantidade
    elif tipo == "saída":
        if produto in estoque_atual:
            estoque_atual[produto] -= quantidade
        else:
            pass

produtos_reposicao = [produto for produto, qtd in estoque_atual.items() if qtd <= 50]

print("=== Estoque Atualizado ===")
for produto, qtd in estoque_atual.items():
    print(f"{produto}: {qtd} unidades")

print("\n=== Produtos que precisam de reposição (<= 50 unidades) ===")
if produtos_reposicao:
    for produto in produtos_reposicao:
        print(f"- {produto} ({estoque_atual[produto]} unidades)")
else:
    print("Nenhum produto precisa de reposição.")