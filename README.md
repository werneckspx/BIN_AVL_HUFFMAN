# BIN_AVL_HUFFMAN

<div style="display: inline-block;">
<img align="center" height="20px" width="60px" src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white"/> 
<img align="center" height="20px" width="80px" src="https://img.shields.io/badge/Made%20for-VSCode-1f425f.svg"/> 
</a> 
</div>

# Problema Proposto
  Neste trabalho, o objetivo é criar um sistema que possibilite a funcionalidade de autocompletar e oferecer sugestões de palavras aos usuários. Para atingir essa finalidade, adotaremos a estrutura da árvore binária como base.<br>
  
  -  Criar uma arvore binaria.
  -  Criar uma arvore AVL
  -  Criar um codigo de Huffman.
    
A partir da criacao das arvores, o objetivo e ter uma compreensão mais aprofundada das suas diferentes implementações e sua influência no sistema de autocompletar e sugestões de
palavras. A análise comparativa nos permitirá avaliar a eficácia de cada abordagem em termos de desempenho e funcionalidade.

# Arquivos
|  Arquivo                        |   Função                                                                                          |
| ------------------------------- | ------------------------------------------------------------------------------------------------- |
|  `main.cpp`                       | arquivo principal para iniciar e chamar as funções do código                                                    |
|  `read.hpp`                  | define as funções que foram utilizadas no código |
|  `read.cpp`                  | contém o escopo de todas as funções que foram utilizadas |
|  `DomCasmurro.txt`               | arquivo de entrada no qual será feita a análise das palavras |
| `Semana_Machado_Assis.txt` | arquivo de entrada principal no qual será feita a análise das palavras |
| `stopwords.csv` | arquivo que contem as stop words|


## HEAP
  O heap, tem uma sequencia de elementos com chaves, c[1], c[2],...,c[n], tal que, para que as chaves satisfaçam a condição de funcionamento, a chave de um nó pai deve ser maior que a chave aplicada à seus filhos. Para todo `i`, temos que: 
  -  c[i] ≥ c[2i] <br>
  -  c[i] ≥ c[2i + 1] <br>
  
Onde os filhos de `i` sao: 2i e 2i+1. Consequentemente, temps que o pai de `i` e `i` divido por 2. Essa definição deixa a estrutura similar a de uma árvore binária completa. <br>

O exemplo abaixo mostra, por meio de um vetor, o sistema de pai e filho do heap, demonstrado pelas setas.
<div align="center"><img width="300px" src="imgs/heap.png" /> <br></div>

Observe que o heap apresenta um custo de O(logN), onde N representa o numero de elementos do heap. Uma vez que este se assemelha a uma arvore binária completa, temos a relacao ao numero de nos da arvore, que tambem apresenta custo O(logN) sendo N o numero de nos. O heap apresenta custo O(1), quando houver a necessidade de acessar o elemento que ocupa o topo do vetor.

## HASH
  A tabela hash, tem uma função de transformação, essa e responsavel por receber cada elemento da entrada e gerar uma chave para esse elemento, e armazena-lo em uma dada posição da tabela, que e endereçada pela chave. Formalmente, essa função pode ser representada como h(Kj)=[1,...,M], em que o subconjunto da entrada de tamanho M é mapeada na posição Kj da tabela. Na literatura, há diversas implementações de tal função, sendo algumas dessas o resto da divisão, meio do quadrado, método da dobra, método da multiplicação, hashing universal. Se a escolha de tal função for adequada ao conjunto e houver entradas suficiente para armazenar todos os elementos sem a repetição de chaves, o custo da pesquisa cairá para O(1). O exemplo abaixo utiliza como função o resto da divisão para o conjunto de dados.Para este exemplo, considere a variável T como tamanho da tabela hash e "e" como o elemento a ser indexado. <br>
  <div align="center"><img width="500px" src="imgs/hash.jpeg" /> <br></div>
Observe através do exemplo que se a função utilizada for adequada e houver espaço suficiente para armazenar um único elemento por posição a estrutura em hash pode alcançar tempos de O( 1 ), o qual se refere ao melhor tempo de execução / melhor caso. Em um caso médio teremos algo próximo de O(1+N/T) e no pior caso O(n).

## BINARIA
A árvore de pesquisa é uma estrutura muito eficiênte para armazenar informações. Sua estrutura é adequada para situações quando há necessidade de considerar todos ou alguma combinação dos itens a seguir: <br>
▶ Acesso direto e sequencial eficiente<br>
▶ Facilidade de inserção e retirada de registros<br>
▶ Boa taxa de utilização de memória<br>
▶ Utilização de memória primária e secundária<br>
<div align="center"><img width="500px" src="imgs/hash.jpeg" /> <br></div>
Chamamos R de raiz da árvore, FE de filho esquerdo e FD de filho direito
Todos os elementos menores ficam na subárvore esquerda.
Todos os elementos maiores ficam na subárvore direira.

Diferentemente de uma arvore natural, estas sao representadas de cima para baixo, com a raiz no topo e as folhas na base(nodos terminais). A raiz e um no que nao tem ancestrais; so pode ter nos filhos. As folhas, por outro lado, nao tem filhos, ou melhor, seus filhoes sao estruturas vazias. Uma arvore pode ser definida recursivamente como:
  -Uma estrutura vazia, e uma arvore vazia.
  -Se t1,...,tk sao arvores disjuntas, entao a estrutura cuja raiz tem como suas filhas as raizes de t1,...,tk tambem e uma arvore.
  -Somente estruturas geradas pela regra 1 e 2 sao arvores.
Una arvire binaria de busca tem a seguinte propriedade: cada no n da arvore, todos os valores armazenados em sua subarvore a esquerda (a arvore cuja raiz e o filho da esquerda) sao menores que o valor v armazenado em n, e todos os valores armzenados na subarcore direita sao maiores ou igual a v. A ordenacao de maneira lexicografica tambem pode ser utilizada em casos de valores iguais.
Para uma árvore de pesquisa binária randômica, o número  esperado de comparações para encontrar um registro é de aproximadamente 1.39(lg n), ou seja, 39% pior que uma árvore completamente balanceada.

## AVL

Uma arvore AVL e aquela na qual as alturas das subarvores esquerda e direita de cada no diferem no mazimo por um. Os numeros nos nos indicam os fatores de balanceamento, que sao as diferencas entre as alturas das subarvores esquerda e direita. Um fator de balanceamento e a altura da subarvore direita menos a altura da subarvore esquerda. Para uma arvore AVL, todos os fatores de balanceamento devem ser +1, 0 ou -1. Note que a definicao de arvore AVL e a mesma que a da arvore balanceada. Vale ressaltar que, a tecnica de balanceamento da arvore AVL nao garante que a arvore resultante esteja perfeitamente balanceada. Se o fator de balanceamento de qualquer no em uma arvore AVL se torna menor do que -1 ou maior que 1, a arvore tem que ser balanceada. Contudo, se os fatores de balanceamento no caminho do recem-inserido no ate a raiz da arvore sao todos zero, tem que ser atualizados, mas nenhuma rotacao e necessaria para quaisquer nos encontrados. A busca de pior caso exige O(lg n) comparacoes. Para uma arvore binaria perfeitamente balanceada de mesma altura h e lg(h+1). Por esta razao, o tempo de busca no pior caso em uma arvore AVL e 44% pior(ela exige 44% mais comparacoes) do que na configuracao de arvore do melhor caso.

## HUFFMAN

A codificação de Huffman é um algoritmo cujo princípio básico está na geração de uma codificação de prefixo para tratar a frequência de cada símbolo de uma entrada. Seu objetivo é gerar o menor número de bits possível para a representação de cada uma das frequências mapeadas. O filho esquerdo esta associado ao bit ZERO enquanto o filho direito esta associado ao bit UM. A ideia do algoritmo de Huffman começa com um conjunto de N folhas e, em seguida, realiza N - 1 operações sequenciais de combinação de dois vértices da árvore. Em cada uma dessas combinações, um novo vértice interno é criado, que se torna o pai dos vértices que estão sendo combinados. A escolha de quais dois vértices combinar em cada passo depende da soma das frequências das folhas das subárvores com raízes nos vértices que ainda não foram combinados.

A:0.08, B:0.10, C:0.12, D:015, E:0.20 e F:0.35 como suas respectivas frequências.
<div align="center"><img width="500px" src="imgs/hash.jpeg" /> <br></div>

Se T e a  arvore que representa a codificacao, dT (c) e a profundidade da folha representado o caracter c e f(c) e a sua frequencia, o tamanho do arquivo comprimido ser a dado por:
<div align="center"><img width="500px" src="imgs/hash.jpeg" /> <br></div>
Dizemos que B(T) e o custo da arvore T.Isto e exatamente o tamanho do arquivo codificado.

## Utilizados

Unordered_map: Mapas não ordenados são contêineres associativos que armazenam elementos formados pela combinação de um valor de chave e um valor mapeado e que permitem a recuperação rápida de elementos individuais com base em suas chaves. Em um unordered_map, o valor da chave geralmente é usado para identificar exclusivamente o elemento, enquanto o valor mapeado é um objeto com o conteúdo associado a essa chave. Os tipos de chave e valor mapeado podem ser diferentes. Internamente, os elementos no unordered_map não são classificados em nenhuma ordem específica em relação a sua chave ou valores mapeados, mas organizados em buckets dependendo de seus valores de hash para permitir acesso rápido a elementos individuais diretamente por seus valores de chave.

Make_heap: Transforma um intervalo de elementos em uma heap. Constrói um heap binário no vetor reordenando os elementos para que eles satisfaçam a restrição de heap. O heap binário é uma árvore binária balanceada que satisfaz a condição de que o valor no nó pai é sempre maior/menor do que os valores dos nós filho. Isso significa que a raiz sempre contém o maior/menor elemento.

Pop_heap(): Remove o elemento de maior prioridade (maior ou menor valor, dependendo da logica do codigo) do topo do heap, e coloca-o na última posição do intervalo do heap. Isso é feito para abrir espaço para inserir um novo valor maior/menor.


# Lógica
Para a resolucao do problema descrito, a funcao `fn_principal()` e responsavel por fazer tudo que e necessario, com o auxilio de outras funcoes. Nela ocorre a criacao das tabela Hash principal, denominada Hash, que sera responsavel por guardar os elementos, a tabela Hash stopWords, que e responsavel por guardar as stopwords, e a tabela Hash pontos, que e responsavel por guardar pontuacoes a serem desconsideradas. Em seguida ocorre a criacao do vector, que sera onde o Heap vai ser realizado. <br>
Em seguida e chamada a funcao `readStopWords()`, nela ocorre a leitura do arquivo stopwords e as palavras sao guardadas na hash de stopwords. <br>
A leitura dos arquivos, que detem os textos para que as palavras sejam analizadas e feita na funcao `leitor_principal()`, nela, enquanto nao chegar ao fim do arquivo, o programa pega linha por linha, passa os caracteres para minusculo, em seguida chama a funcao `converterAcentuadasParaMinusculas()`, que converte os caracteres acentuados para minusculo, e a funcao `removePontuacao()`, essa, procura na hash de pontos por meio do `find()`, pontuacoes indesejadas, e faz a remocao delas na linha. <br>
Ocorre a tokenizacao da linha, para que seja possivel separar palavra por palavra. Apos, ocorre a verificacao se a palavra e StopWord por meio da funcao `count()` esta conta quantas vezes a palavra apareceu, no caso, se a palavra denominada stopWord nao apareceu nenhuma vez, significa que a palavra e valida e sera analisada. <br>
Verifica se existe numeros nessa palavra, uma vez que uma palavra e feita apenas de letras. Caso nao exista numeros ocorre a insercao na Hash.
A insercao na hash e feita atraves de uma condicao, utilizando a funcao `find()` e `end()` que percorre toda a Hash, verifica se a palavra a ser inserida ja existe, se a palavra existir, e somado 1 a sua quantidade, do contrario a palavra e inserida na Hash.
Sendo assim, a partir da funcao `leitor_principal()`, chamada na funcao `fn_principal()` ocorre a leitura dos arquivos desejados. <br>
Em seguida, inicializa-se a vector com 20 elementos da Hash, e e feito o processo do Heap, por meio da funcao `make_heap()`. Apos isso, com o vector ja inicializado, ocorre a leitura dos restantes elementos que estao na Hash. Se o valor da Hash, for maior que o primeiro elemento do vector, este primeiro elemento do vector, que apresenta o menor valor entre os demais e removido, utilizando as funcoes `pop_heap()` e `pop_back()`, e o elemento maior vindo da Hash e adionado ao vector, em seguida a funcao `make_heap()` e novamente chamada para realizar o Heap novamente apos a insercao do novo valor.
Assim, o programa descrito realiza as acoes necessarias para solucionar o problema descrito.
 # Resultados 
   Considerando a lógica e a descrição do problema acima, o resultado esperado durante a leitura dos arquivos:
   <div align="center"><img width="500px" src="imgs/resultados.jpeg" /> <br></div>

# Conclusao
  Por meio do projeto e possivel compreender melhor o funcionamento da Hash e do Heap, sendo estruturas fundamentais, que podem ser utilizadas para resolver diversos problemas. Neste caso, para a solucao do problema Top K itens, essa combinacao e extramamente viavel, uma vez que elas resolvem o problema, pois e possivel quantificar os elementos, sem o problema de colisoes, e ordenar os elementos de modo que apenas os elementos que mais aparecem nos textos escolhidos sejam mostrados. Para projetos futuros e valida pensar uma melhor forma de retirar caracteres indesejados, para que as palavras sejam contabilizadas de maneira exata.
 # Bibliotecas 
<p>Para o funcionamento do programa, é necessário incluir as seguintes bibliotecas: 
<ul>
    <li><code>#include 'bits/stdc++.h'</code></li>
    <li><code>#include 'algorithm'</code></li>
    <li><code>#include 'vector'</code></li>
    <li><code>#include 'cctype'</code></li>
    <li><code>#include 'iomanip'</code></li>
    <li><code>#include 'iostream'</code></li>
</ul>

# Compilação e Execução

Esse pequeno exemplo possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:


| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o g++, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |


# Contatos

<div style="display: inline-block;">
<a href="https://t.me/felipewom">
<img align="center" height="20px" width="90px" src="https://img.shields.io/badge/Telegram-2CA5E0?style=for-the-badge&logo=telegram&logoColor=white"/> 
</a>

<a href="https://www.linkedin.com/in/felipe-werneck-93520a209">
<img align="center" height="20px" width="90px" src="https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white"/>
</a>

</div>

<p> </p>
