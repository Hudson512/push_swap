# push_swap
Obj Geral : Escrever um algoritmo de classificação.

Obj esp: Rigor, uso de C e uso de algoritmos básicos.

Palavras chaves:
Algoritmos de classificação;
conceitos;
Classificar da maneira mais rápida possível é menos simples;


------------------------------------------------------------------------
						Regras

Você tem 2 pilhas chamadas a e b.

No começo:	A pilha a contém uma quantidade aleatória de números negativos e/ou positivos que não podem ser duplicados.

A pilha b está vazia.

• ​​O objetivo é classificar em ordem crescente os números na pilha a.
Para fazer isso, você tem as seguintes operações à sua disposição:

***********************************************************************************
sa (swap a): Troque os 2 primeiros elementos no topo da pilha a.
Não faça nada se houver apenas um ou nenhum elemento.

sb (swap b): Troque os 2 primeiros elementos no topo da pilha b.
Não faça nada se houver apenas um ou nenhum elemento.

ss : sa e sb ao mesmo tempo.

***********************************************************************************
pa (push a): Pegue o primeiro elemento no topo de b e coloque-o no topo de a.
Não faça nada se b estiver vazio.

pb (push b): Pegue o primeiro elemento no topo de a e coloque-o no topo de b.
Não faça nada se a estiver vazio.

***********************************************************************************
ra (rotate a): Desloca todos os elementos da pilha a para cima em 1.
O primeiro elemento se torna o último.

rb (rotate b): Desloca todos os elementos da pilha b para cima em 1.
O primeiro elemento se torna o último.

rr : ra e rb ao mesmo tempo.

***********************************************************************************
rra (reverse rotate a): Desloca todos os elementos da pilha a para baixo em 1.
O último elemento se torna o primeiro.

rrb (reverse rotate b): Desloca todos os elementos da pilha b para baixo em 1.
O último elemento se torna o primeiro.

rrr : rra e rrb ao mesmo tempo.
