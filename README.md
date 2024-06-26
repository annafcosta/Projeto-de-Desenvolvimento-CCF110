# Projeto de Desenvolvimento

## Sistema de Venda de Produtos 

Recentemente, a aluna Hellen Carolyna iniciou um pequeno negócio envolvendo venda de doces, denominado "Delícias da Hellen". Levando em considereção esse cenário, o objetivo deste trabalho é desenvolver um sistema de venda, dessa forma, o usuário poderá manter o controle de estoque e registrar as vendas de forma eficiente. A ideia central é facilitar o processo de compra e garantir que o estoque seja atualizado de acordo com as vendas realizadas.

___

**TAREFAS EM DESENVOLVIMENTO**

🟣 [Objetivos](#Objetivos-1)

<div id="Objetivos-1">
<!-- Seu conteúdo para a Objetivos -->
</div>

🟢 [Implementações Existentes](#implemen-4)
<div id="implemen-4">
<!-- Seu conteúdo para Autores -->
</div>

🟡  [Futuras Implementações](#implementar-3)

<div id="implementar-3">
<!-- Seu conteúdo para Autores -->
</div>

🔵 [Descrição de Funcionamento](#descrição-2)

<div id="descrição-2">
<!-- Seu conteúdo para Descrição de Funcionamento -->
</div>

⚪ [Autores](#autores-3)

<div id="autores-3">
<!-- Seu conteúdo para Autores -->
</div>

___

## 🟣 Objetivos:

* *Eficiência Operacional:* O principal objetivo do sistema é melhorar a eficiência operacional, automatizando tarefas repetitivas, como controle de estoque e registro de vendas;

* *Precisão do Estoque:* Garantir que o estoque seja mantido atualizado;

* *Controle Financeiro:* Um dos objetivos do sistema é auxiliar os usuários a acompanharem suas receitas de vendas.


## 🟢 Implementações Existentes

* *Menu Interativo:* O menu interativo foi desenvolvido de maneira que a navegação do usuário seja intuitiva. Além desse aspecto, foi adicionado cores para personalização das opções do menu, facilitando assim, a visualização e escolha do usuário. Abaixo estão as opções válidas, até o momento, para o Menu;
  * Cadastro de produtos no estoque;
  * Visualização de produtos;
  * Registro de Vendas;
  
* *Cadastro de Produtos:* O sistema desenvolvido é capaz de cadastrar produtos a escolha do usuário, lendo os nomes, o código do produto e suas respectivas quantidades e preços.
  
* *Registro de Vendas:* Recentemente, realizou-se uma implementação parcial do registro de vendas. Dessa forma, é possível registrar a venda de um produto por meio de seu código, demonstrando também, a visualização do valor total gerado pela venda.
  
* *Visualização das vendas:* Na última atualização, a opção de visualizar as vendas foi implementada. Dessa forma, é possível visualizar o valor total da venda de cada produto.

## 🟡 Futuras Implementações 

* *Visualização do estoque:* Salvar em arquivo os produtos cadastrados de maneira manual;

## 🔵 Descrição de funcionamento

* *Criação de Arquivos:* A formatação de escrita do arquivo 'estoque.txt', deve seguir ser escrito da seguinte maneira 'Nome_do_Produto 2.25 005 18';
  
   * Note que, a formatação é iniciada pelo nome do produto, seguido do valor, código e quantidade.
   * O atual sistema tem uma limitação em relação a leitura de espaços, por esse motivo, a formatação acima deve ser seguida.
   * O arquivo deve ser iniciado com o número de produtos que terão no arquivo, uma vez, que o programa irá ler esse número e fazer o cadastro desses produtos limitando-se a esse valor.

* *Compilar pelo terminal:* Utilize o seguinte comando caso compile o código pelo terminal utilizando o gcc.

```gcc
gcc src/*.c -o main
```
Para executar:
```gcc
./main
```


## ⚪ Autores

Anna Lúisa Ferreira Costa (4409). [[User-GitHub]](https://github.com/annafcosta)


