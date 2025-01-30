# Geração de Animações em Matriz de LEDs 5x5

Este projeto tem como objetivo criar animações visuais em uma matriz de LEDs 5x5 utilizando o **Raspberry Pi Pico W**, um teclado matricial 4x4 e o simulador Wokwi. 

## Descrição do Projeto

A matriz de LEDs é controlada por um microcontrolador, respondendo a comandos definidos pelas teclas do teclado matricial. Cada tecla aciona uma animação ou comportamento específico dos LEDs. As animações são configuradas pelos integrantes da equipe, que também implementam funcionalidades adicionais como reinício do sistema e controle de cores.

### Requisitos
1. Geração de **10 animações diferentes**, cada uma com pelo menos 5 frames.
2. Implementação dos seguintes comportamentos:
   - **Teclas de 0 a 9**: Executam animações.
   - **Tecla A**: Desliga todos os LEDs.
   - **Tecla B**: Liga todos os LEDs na cor azul com 100% de intensidade.
   - **Tecla C**: Liga todos os LEDs na cor vermelha com 80% de intensidade.
   - **Tecla D**: Liga todos os LEDs na cor verde com 50% de intensidade.
   - **Tecla #**: Liga todos os LEDs na cor branca com 20% de intensidade.
   - **Tecla \***: Coloca o microcontrolador em modo de gravação via software (reboot).

### Especificações Opcionais
- Utilização de um buzzer para gerar som em uma das animações.

## Tecnologias Utilizadas
- **Microcontrolador:** Raspberry Pi Pico W
- **Ambiente de Desenvolvimento:** VS Code
- **Simulador:** Wokwi
- **Linguagem:** C (com Pico SDK)

## Organização da Equipe
A equipe está organizada conforme a tabela abaixo:

| Nome do Membro      | Função                  | Contribuições                        |
|---------------------|-------------------------|--------------------------------------|
| Reinan Argolo       | Líder                   | Gestão do repositório e revisão de PRs Animação para a tecla 1 |
| Pedro Duarte        | Desenvolvedor           | Animação para a tecla 2 e implementação da função da letra B (azul 100%)|
| Nome 3              | Desenvolvedor           | Animação para a tecla 3              |
| Nome 4              | Desenvolvedor           | Animação para a tecla 4              |
| Nome 5              | Desenvolvedor           | Animação para a tecla 5              |
| Nome 6              | Desenvolvedor           | Animação para a tecla 6              |
| Nome 7              | Desenvolvedor           | Animação para a tecla 7              |
| Nome 8              | Desenvolvedor           | Animação para a tecla 8              |
| Gabriel Shiva             | Desenvolvedor           | Animação para a tecla 9 e implementação da rotina das letras A e *             |


## Como Executar
1. Clone o repositório:
   ```bash
   git clone https://github.com/ReinanArgolo/U4C3-embarcatech.git

2. Navegue até o diretório do projeto:
    ```bash
        cd U4C3-embarcatech

3. Cmpile e execute o projeto utilizando o Pico SDK no VS Code.


## Link do Vídeo
O vídeo de apresentação pode ser acessado [aqui](#).
