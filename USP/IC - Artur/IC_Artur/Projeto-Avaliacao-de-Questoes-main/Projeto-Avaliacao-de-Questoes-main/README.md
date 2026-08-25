# Avaliação de Questões

Este projeto tem como objetivo avaliar a capacidade da LLM de acordo com a quantidade de respostas corretas de uma questão **TESTE**, ou seja, o código não suporta questões dissertativas. 

# Sumário

- [Como Funciona- Visão Geral](#como-funciona--visão-geral)
  - [Parser.py](#parserpy)
  - [Main.py](#mainpy)
- [Configurações](#configurações)
- [Estrutura das Questões](#estrutura-das-questões)
- [Como "rodar" o código](#como-rodar-o-código)
- [Onde ver os Resultados](#onde-ver-os-resultados)
- [Observações Importantes](#observações-importantes)


# Como funciona- Visão Geral

Na pasta que contém as questões a serem testadas, o código vai pegar questão por questão, reestruturar, mandar para a LLM responder e atribuir uma nota de acordo com o desempenho das questões. Assim, todas as questões que o usuário quiser testar devem estar no mesmo arquivo e as questões devem estar no formato LaTeX.

Para poder entender mais a parte da reestruturação:

Em LaTeX, uma questão é formada pelo enunciado e pelas alternativas, sendo que no começo das alternativas tem ```\correctchoice``` e ```\wrongchoice``` e no fim da questão correta tem o ```\scoring{}``` (opcional). Se fosse para mandar a LLM responder a questão sem reestruturá-la, ela vai responder a alternativa que na frente tem o ```\correctchoice```, já que a alternativa está marcada como a resposta correta. Portando, a avaliação resultante não está de fato analisando o desempenho da LLM. Logo, a reestruturação é importante para retirar os elementos que podem influenciar a resposta da LLM, para isso, em "Parser.py" está encarregada nessa parte.

### Parser.py

Como mencionado anteriormente, o código em Parser.py tem a função de reestruturar, identificar a alternativa correta e comparar a alternativa correta com a resposta da LLM.

Começando com a reestruturação: 

- A partir das questões recebidas, o código vai identificar as questões através de ```\begin{choices} ... \end{choices}```, ou seja, o começo e o fim  das alternativas indica cada questão do arquivo. 
- Analisando uma questão por vez, o código identifica onde está as alternativas ```\begin{choices} ... \end{choices}``` e retira o ```\correctchoice```, o ```\wrongchoice```, nesta etapa também é identificada qual(is) é/são a(s) alternativa(s) correta(s)
- As alternativas limpas são embaralhadas, para evitar o caso das alternativas corretas de todas questões terem um padrão, por exemplo, colocar todas as letras "a)" como corretass 
- Juntamos o enunciado com as questões
- Essa questão reestruturada é mandada para a LLM responder

Comparação:

- Com a resposta da LLM, comparamos com a resposta correta retirada anteriormente e atribuimos para a questão uma nota de 0 a 1
- Se a questõa tiver mais de uma alternativa correta, a nota que será retornada é de acordo com quantas questões estão iguais. Assimm, se as alternativas corretas forem "a), b), c) e d)", mas a LLM apenas respondeu "a) e b)" a pontuação da questão é 0,5 pois respondeu metade da resposta correta.

### Main.py

Neste arquivo, colocamos a chave API, o modelo da LLM que irá usar e a pasta onde as questões estão contidas. Além disso, é responsável em calcular o desempenho da LLM.

# Configurações

- É necessário fazer algumas configurações, essas estão em "Main.py". Sem elas, o código não funcionará:

```
key = "COLOQUE SUA CHAVE API"
```

Nesta variável coloque o código da sua chave API, não se esqueça de colocar a chave dentro de aspas duplas (" "), então um exemplo seria:

```
key = "AbCdEf12345"
```

Além disso, em:

```
model = GenerativeModel('COLOQUE O MODELO')
```

Coloque o modelo da LLM que a sua chave API consegue utilizar, não se esqueça de colocar o modelo dentro de aspas simples (' '). Por exemplo:

```
model = GenerativeModel('gemini-2.0-flash')
```

Sendo que o 'gemini-2.0-flash' é o modelo que as chaves API's suportam para os usuários que não assinam o plano pago da Google 

# Estrutura das Questões

Para conseguir usar o código, o arquivo que contém as questões deve seguir um padrão, caso não siga ele, o código não irá funcionar corretamente.

- Antes de cada questão, a implementação do enunciado não influencia na identificação das questões, ou seja, pode usar algum package específico para escrever o enunciado pois não irá influentiar. Mas é uma boa prática nas questões de usar ```\begin{question} ... \end{question}```.

- No exemplo, há uma mistura de questões com subquestões e questões que não tem subquestões, este tipo de mistura é suportado pelo código, ou seja, não é necessário criar arquivos cujo conteúdo tenha apenas questões com subquestões, ou ao contrário, arquivos que contém apenas questões sem subquestões. 

- Antes de cada alternativa deve ter ```\correctchoice{}``` ou ```\wrongchoice```, caso contrário, não irá identificar as questões corretamente.

```
\begin{question} [ENUNCIADO DA QUESTÃO 1]

[ENUNCIADO DA SUBQUESTÃO 1 DA QUESTÃO 1]
\begin{choices}
\wrongchoice{[COLOCAR ALTERNATIVA]}
\correctchoice{[COLOCAR ALTERNATIVA]}
\wrongchoice{[COLOCAR ALTERNATIVA]}
\wrongchoice{[COLOCAR ALTERNATIVA]}
\wrongchoice{[COLOCAR ALTERNATIVA]}
\end{choices}
\end{question}

\begin{question}[ENUNCIADO DA SUBQUESTÃO 2 DA QUESTÃO 1]
\begin{choices}
\correctchoice{[COLOCAR ALTERNATIVA]}
\wrongchoice{[COLOCAR ALTERNATIVA]}
\wrongchoice{[COLOCAR ALTERNATIVA]}
\wrongchoice{[COLOCAR ALTERNATIVA]}
\correctchoice{[COLOCAR ALTERNATIVA]}
\end{choices}
\end{question}

\begin{question} [ENUNCIADO DA QUESTÃO 2]
\begin{choices}
\correctchoice{[COLOCAR ALTERNATIVA]}
\wrongchoice{[COLOCAR ALTERNATIVA]}
\wrongchoice{[COLOCAR ALTERNATIVA]}
\wrongchoice{[COLOCAR ALTERNATIVA]}
\wrongchoice{[COLOCAR ALTERNATIVA]}
\end{choices}
\end{question}
```

Algo importante no exemplo, é que o código suporta questões que têm multiplas respostas corretas.

# Como "rodar" o código

É necessário executar o seguinte comando, substituindo o texto que contém as chaves ([ ]), não inclua as chaves:

```
Main.py --caminho_dos_testes ['COLOQUE A PASTA QUE CONTEM AS QUESTÕES'] --prompt ['COLOQUE O ARQUIVO QUE CONTÉM A INSTRUÇÃO']
```

Um exemplo:

```
Main.py --caminho_testes sistemas_operacionais --instrucao instrucao.tex
```

Sendo assim ```sistemas_operacionais``` o nome que contém as questões e ```instrucao.tex``` o arquivo que contém a instrução que desejar com que a LLM responda, no repositório é dado um arquivo com o prompt, recomendável usar essse, pois o código foi baseado nesse tipo de instrução

Caso não coloque nada, ou seja, execute o comando:

```
Main.py 
```

Também funciona, porém o caminho de testes e a instrução serão configuradas com a pasta e o arquivo default, ou seja, ```pasta_com_testes``` e ```instrucao.tex```, respectivamente, ambos dados no repositório.

OBS: a pasta ```pasta_com_testes``` está vazia, é necessário adicionar as questões

# Onde ver os Resultados

Se for necessário comparar a resposta dada pela LLM e a resposta correta da questão, as respostas certas estão armazenadas no arquivo ```aswer_key.tex```, enquanto as respostas dadas pela LLM estão na pasta ```results.tex```.

Adicionalmente, em ```results.tex```, há a avaliação da LLM, ou seja, a sua pontuação, e o quando ela acertou nas questões, seguindo o padrão de questões que contém multiplas alternativas corretas, é colocado quantas das alternativas acertou.
```
(Em results.py):
3/4 - j) "Parser.py" recebe a resposta da LLM 
b) O código identifica as questões através de "\begin{choices} e \end{choices}"
c) As questões são embaralhadas antes de mandar para a LLM
2/2 - a) Se a tensão V1 = 5V, o diodo age como um curto 
g) Para calcular a corrente, basta fazer a relação entre a diferença das tensões e a resistência
1/1 - c) Apenas a alternativa II é a correta

Grade: 8.57%
```

Sendo que as alternativas observadas ao lado são as respostas da LLM

```
(Em answer_key.py):
Gabarito:
Questão 1: a), b), c)
Questão 2: a), g)
Questão 3: c)
```

# Observações Importantes

- Ter uma chave API
- Colocar todas as questões no mesmo arquivo
- Especificar qual modelo de IA irá utilizar
- Questões devem estar em **estrutura LaTeX**
- As questões devem ter no começo ```\question``` e se a questão tiver subquestões colocar na frente do enunciado ```\subquestion```
- É suportado questões que tenham mais de uma alternativa correta
