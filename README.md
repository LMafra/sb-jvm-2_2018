![alt text](http://www.unb.br/images/Imagens/logo_unb.png)

# Trabalho Final de Software Básico 2/2018

O trabalho final do curso Software Básico consiste na criação da **Máquina Virtual Java**(JVM). 

## Grupo:
Lucas Mafra Chagas - 12/0126443

Rodrigo Doria Vilaça - 14/0031111


## Funcionamento

## Estruturação

#### Cada pasta pode possuir seu próprio README.md

Isso devido às regras bem específicas que podem haver para
a codificação, documentação, testes, etc. Acreditamos que essas informações são relevantes o bastantepara estarem no projeto, mas não neste documento.

+ **src**
  * Pasta contendo todos os fontes que devem ser entregues

+ **spec**
  * pdf com a especificação da JVM7.
  * adicionalmente, pode-se ter um *Notas.md* contendo o que *explicitamente* foi solicitado pelo professor que *não fosse imlpementado* .

## Referências

[Documentação JVM Oracle](https://docs.oracle.com/javase/specs/jvms/se7/html/)

## TODO
- [ ] **Padronizar nomenclatura das variáveis.**
- [ ] **Decidir a cada quanto tempo iremos integrar o que foi feito.**
- [ ] Decidir as ferramentas de debug
- [ ] Decidir IDE a ser utilizada, se alguma
- [ ] Mínima padronização dos *testes unitários*.
- [ ] Colocar na pasta *doc/example* exemplos de utlização do *doxygen*
- [ ] *Makefike* que funcione com essa organização *flat*.

## Algumas Regras

+ **Jamais** subir código executável para o github; apenas os fontes.
	* Para tal, adicionem nos *.gitignore* de cada um os arquivos 
	binários que vocês gerarem. **Por padrão**, deixei para ignorar os arquivos terminados em **ig**.

+ Commits constantes, ainda que não para a master.

+ **Ter um** *.gitignore* **em** *cada diretório* **no qual haja algum arquivo cujo tracking pelo git é indesejado**.

+ Não mandar os commits diretos para a master!, salvo antes acordado pelo grupo OU situação extraordinária.