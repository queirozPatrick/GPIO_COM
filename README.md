# Controle de GPIOs com Microcontrolador RP2040

Este projeto utiliza a ferramenta educacional **BitDogLab** e o microcontrolador **RP2040** para controlar LEDs RGB e um buzzer via UART. A atividade é parte do curso **EmbarcaTech - CEPEDI.**

---

## 🎯 Objetivo

Desenvolver um programa em linguagem C para:
- Controlar os LEDs RGB (GPIOs 11, 12 e 13).
- Controlar um buzzer (GPIO 21).
- Estabelecer comunicação via terminal UART para execução de comandos.

---

## 🛠️ Ferramentas Utilizadas

- **Ferramenta Educacional:** BitDogLab (versão 6.3).
- **Microcontrolador:** RP2040.
- **Ambiente de Desenvolvimento:** VS Code.
- **Linguagem de Programação:** C (usando o kit Pico SDK).
- **Simulador:** Wokwi.
- **Controle de Versão:** GitHub.

---

## 🧩 Funcionalidades

1. **Controle dos LEDs RGB:**
   - Ligar o LED verde (GPIO 11) e desligar os demais.
   - Ligar o LED azul (GPIO 12) e desligar os demais.
   - Ligar o LED vermelho (GPIO 13) e desligar os demais.
   - Ligar os três LEDs (luz branca).
   - Desligar todos os LEDs.
   
2. **Controle do Buzzer:**
   - Acionar o buzzer por 2 segundos.

3. **Outras Funções:**
   - Habilitar o modo de gravação via reboot (opcional).

---

## 🚀 Como Executar

### Pré-requisitos
1. Instale o **VS Code** com o **Pico SDK** configurado.
2. Configure o simulador **Wokwi**.
3. Conecte o RP2040 ao computador via cabo micro-USB.


### Passos
1. Clone este repositório:
   ```bash
   git clone https://github.com/seu-usuario/seu-repositorio.git
   ```
2. Compile o código:
   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```
3. Carregue o firmware no microcontrolador RP2040.

---

## 📝 Estrutura do Projeto

```
|-- src/
    |-- main.c
    |-- gpio_control.c
|-- include/
    |-- gpio_control.h
|-- README.md
|-- LICENSE
```

---

## 🎥 Demonstração

Assista ao vídeo demonstrativo clicando [aqui](https://youtube.com/shorts/sWMTMwFygSQ?feature=share)

---

## 📌 Organização do Projeto

- **Líder do Projeto:** Responsável pela gestão do repositório, criação e inicialização do projeto, organização de tarefas e revisão de pull requests.
- **Desenvolvedores:** Cada membro da equipe trabalhou em um branch específico desenvolvendo o código e testando funcionalidades.

---

## 💡 Contribuições

1. Faça um fork deste repositório.
2. Crie um branch com sua feature:
   ```bash
   git checkout -b minha-feature
   ```
3. Faça commits com mensagens claras.
4. Envie um pull request.

 ## Desenvolvolvido por:

Patrick Queiroz queirozPatrick • Collaborator

João Victor Paim PaimJv • Collaborator

Heitor Lemos TorRLD • Collaborator
