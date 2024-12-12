# Parte 1: Exploração Teórica e Comparativa
## 1. Explique a importância do espalhamento uniforme em funções hash.
- A importância do espalhamento uniforme seria para não pesar computacionalmente a tabela hash

## 2. Descreva uma situação em que o fator de carga alto pode comprometer o desempenho.
- Ocorreria um aumento de colisão, onde poderia aumentar o tempo de execução nas operações.  
- Poderia gerar uma lista linear fazendo com que as vantagens de uma tabela hash seja anulada.  
- O tempo de busca seria aumentado pois teria que passar por mais posições até encontrar o elemento desejado ou um local livre.

# Parte 2: Código Base e Análise
## 3. Analise e responda se o código base apresenta problemas de colisão.
- Sim, ocorre colisões pois os restos dos inserts de chave 1, 11, 21 serão 0, o que tos leva a mesma chave na tabela hash

## 4. Explique como o encadeamento é usado para resolver colisões no programa
- O encadeamento é usado pois caso não fosse haveria colisões nas chaves 1 pois o elemento é inserido no indice em que mais de um elemento está sendo inserido.

## 5. Qual seria o impacto de usar um tamanho de tabela pequeno (menor do que 5, por exemplo), considerando a mesma quantidade de itens que são inseridos pelo programa na tabela?
- O impacto seria que com um tamanho pequeno, ocorreria muitas colisões, fazendo assim com que perca eficiencia, e uma grande degradação no desempenho.

## 6. O código apresentado utiliza o Método da Divisão na função hash, no qual temos: index = chave % TamanhoTabela. Explique a lógica de funcionamento do Método da Divisão
- O funcionamento do metodo é que para calcular o indice ele divide a chave do elemento pelo tamanho da tabela e o resto da divisão vira o indice da hash.

# Parte 3: Modificações e Melhorias
## 7. Apresente o código para a função de remoção (com comentários explicativos no código)
- No codigo.

## 8. Discuta a importância e as dificuldades envolvidas para realizar o Redimensionamento Dinâmico de Tabela Hash.
- É importante pois quando a tabela fica muito cheia, colisões se tornam algo mais frequentes, fazendo o desempenho ficar pior nas operação de inserção, busca e remoção.  
- A dificuldade é pois temos que implementar um monitoramento para o fator de carga, onde caso o ultrapasse irá criar uma nova tabela que irá alocar o tamanho novo desejado, para então reinserir os dados da tabela antiga na nova e só então liberar a memória da tabela antiga.

# Parte 4: Experimente Diferentes Funções Hash
## 9. Apresente o código para a função hashFunction implementando o Método da Multiplicação (com comentários explicativos no código).
- No código.

## 10. Compare a distribuição de chaves proporcionada pelo Método da Multiplicação com a Distribuição obtida pelo método da Divisão.
- Foi visualizado menos uma tabela com menos colisões, o que melhora o desempenho da tabela hash.

## 11. Pesquise e explique com suas palavras como poderia ser implementada uma função Hash para chaves do tipo string.
- Há várias formas, podendo usar a soma dos codigos ascii de cada caractere da string, como também multiplicar cada caractere pelo seu indice e por um número primo, somando os resultados.  
- Sobre a soma pelos códigos ascii temos a vantagem de ser simples de implementar, mas com a desvantagem que a distribuição pode não ser regular, principalmente para strings com padrões simples.  
- Já por multiplicação dos números primos, há uma melhora na distribuição comparado com a ascii, mas pode pesar mais computacionalmente.  
- Há também a forma mais usada atualmente, que utilizam os algoritimos MD5 ou SHA-256 para gerar uma hash de tamanho fixo, onde sua vantagem é a alta resistencia a colisões, mas tem de desvantagem um alto custo computacional que é desnecessário para tabelas hash simples.

# Parte 5: Conclusões
## 12. Quais os principais aprendizados que foram alcançados com a realização deste trabalho sobre Tabelas Hash? Quais as dificuldades? Quais as limitações? Quais as possibilidades de aplicação de Tabelas? Elabore uma conclusão sobre o trabalho realizado, considerando esses e outros aspectos. 
