<h1 align="center"> 💻 Projeto Jogos de Tabuleiro 🥇 </h1>

<p>Esse repositório possui um projeto envolvendo jogos de tabuleiro. Em resumo, implementamos alguns jogos comuns e unimos todos em um só código, que, assim, conta com
um índice e um tratamento de erros. O projeto foi desenvolvido como trabalho final da matéria de Programação e Desenvolvimento de Software II, cursada na Universidade 
Federal de Minas Gerais como matéria obrigatória dos cursos de Ciências da Computação, Ciência de Dados e afins. </p>

 ![Badge Em Desenvolvido](https://img.shields.io/badge/STATUS-EmDesenvolvimento-orange)

# 🔨 Funcionalidades do projeto

- `Aprendizado`: Desenvolvido para aprimorar habilidades aprendidas durante o semestre cursado
- `Diversão`: Todo o código resulta em um programa divertido para o usuário, que pode jogar!
- `Desnvolvimento de habilidades lógicas`: Os jogos de tabuleiro tem um grande poder sobre a mente de seus jogadores. 

# 👀 Objetivos

Desenvolver aprendizados adquiridos no curso de PDS II, praticar a linguagem de C++, desenvolver habilidades em trabalhar em grupo e impulsionar a criatividade.

# ✔️ Tecnologias Utilizadas

- `C++`
- `Tabelas, bloco de notas`
- `Canva`

#  Descrição e visão geral do projeto

O projeto consiste em um programa cuja finalidade é oferecer uma plataforma para jogadores se registrarem, competirem nos jogos Reversi, Jogo da Velha, Lig 4 ou Batalha Naval, e manter um registro das estatísticas de desempenho de cada jogador. O sistema permite o cadastro de jogadores, realizar partidas entre eles e armazenar informações como vitórias, derrotas e empates para cada jogo.

Desenvolvemos uma documentação utilizando o Doxygen, que detalha as classes e métodos implementados no projeto. Recomendamos acessar a documentação utilizando o Google Chrome, pois realizamos testes em outros navegadores e identificamos problemas de compatibilidade durante a abertura.

#  Como rodar e compilar

Inicialmente, o usuário deve executar o comando "make" para compilar o programa corretamente. Após a compilação bem-sucedida, o programa será iniciado e o usuário poderá interagir com ele utilizando comandos específicos:

CJ: Cadastrar um novo jogador.
RJ: Remover um jogador existente.
LJ: Listar todos os jogadores cadastrados.
EP: Executar uma partida entre jogadores.
VE: Visualizar estatísticas relacionadas aos jogos.
VT: Visualizar um tutorial explicativo sobre o sistema.
FS: Finalizar o sistema.

Para verificar a execução dos testes implementados, é necessário usar o comando "make testes". Após corrigirmos pequenos erros nos métodos, conseguimos tornar todos os testes bem-sucedidos.

#  Estrutura e funcionamento do programa

O projeto foi estruturado de forma modular, com cada classe definida em seus próprios arquivos de cabeçalho (.hpp) e implementação (.cpp). Esta abordagem permite uma melhor organização e legibilidade do código, bem como facilita a manutenção e o entendimento do funcionamento interno do sistema. Há um total de 12 classes no programa, cada uma com suas responsabilidades específicas, como cadastro de jogadores, execução de partidas, armazenamento de estatísticas, validação de entradas, etc.

#  Principais dificuldades encontradas

- Manter a integração entre diferentes módulos e classes foi uma grande dificuldade, principalmente no início do projeto.

- Enfrentamos diversos problemas relacionados a vazamentos de memória e "segmentation faults". Isso ocorreu principalmente devido ao uso intensivo de ponteiros em nosso código, combinados com acessos incorretos a áreas de memória não alocadas ou já liberadas. Esses problemas impactaram diretamente a estabilidade do programa e exigiram uma análise cuidadosa para encontrar e corrigir os erros.

- Identificar métodos em que seriam necessários aplicar Testes de Software.


#  Extras

Como parte dos extras, introduzimos duas novas classes: Estatisticas e Tutorial. A classe Estatisticas organiza rankings dos jogadores, permitindo acompanhar o desempenho geral e por jogo. Já a classe Tutorial oferece explicações detalhadas sobre os jogos disponíveis, simulando jogadas e apresentando as regras de forma interativa, ajudando os usuários a entenderem rapidamente cada jogo.

Além dos jogos Reversi, Jogo da Velha e Lig 4, adicionamos o clássico Batalha Naval, ampliando as opções de entretenimento. Também aprimoramos a experiência do usuário ao permitir a personalização de cores e tipos de peças nos jogos. Essas implementações visam tornar o sistema mais intuitivo, inclusivo e envolvente para todos os jogadores.


# 👩 Autores

| [Carolina Penido Barcellos](https://github.com/carolinabarcellos) |
| :--------------------------------------------------------------------------------------------------------------------------------: |

| [Gabrielly Xavier](https://github.com/gabyxsantos) |
| :--------------------------------------------------------------------------------------------------------------------------------: |

| [Júlia Araújo](https://github.com/j-gmd) |
| :--------------------------------------------------------------------------------------------------------------------------------: |

| [Lívia Pereira](https://github.com/Livia-CRPereira) |
| :--------------------------------------------------------------------------------------------------------------------------------: |

| [Sophia Vieira](https://github.com) |
| :--------------------------------------------------------------------------------------------------------------------------------: |


