# Projeto BitDogLab - UART, I2C e Display

## 📖 Descrição

Este projeto implementa comunicação serial utilizando **UART e I2C** no microcontrolador **RP2040**, com a placa **BitDogLab**. O sistema interage com botões, LEDs e um display OLED **SSD1306**, explorando interrupções e debounce para um funcionamento eficiente.

## ✨ Funcionalidades

- 📡 **Recebimento de caracteres via UART**:

  - Cada caractere digitado no **Serial Monitor** é exibido no **display SSD1306**.
  - Números de **0 a 9** ativam símbolos na **matriz 5x5 WS2812**.

- 🎛 **Interação com botões**:

  - **Botão A** alterna o estado do **LED Verde** e exibe informações no **display** e no **Serial Monitor**.
  - **Botão B** alterna o estado do **LED Azul**, com registro no **display** e no **Serial Monitor**.

- 🔄 **Modificação da biblioteca ****`font.h`**:

  - Adição de caracteres minúsculos personalizados.

- 🖥 **Controle de LEDs**:

  - Uso da **matriz WS2812** e **LED RGB** conectados aos GPIOs da **BitDogLab**.

## ✅ Requisitos

✔ Implementação de **interrupções (IRQ)** para botões.\
✔ Tratamento de **debounce** via software.\
✔ Controle de **LEDs comuns e endereçáveis WS2812**.\
✔ Uso do **display SSD1306** via **I2C**.\
✔ Comunicação serial via **UART**.\
✔ Código bem estruturado e comentado.

---

## 🔌 Hardware Utilizado

| Componente          | Conexão GPIO      |
| ------------------- | ----------------- |
| Matriz WS2812 (5x5) | GPIO 7            |
| LED RGB (R, G, B)   | GPIO 11, 12, 13   |
| Botão A             | GPIO 5            |
| Botão B             | GPIO 6            |
| Display SSD1306     | GPIO 14, 15 (I2C) |

---

## 🚀 Como Executar

### 🔧 Instalação

1. Clone o repositório:
   ```sh
   git clone https://github.com/ElissonNadson/BitDogLab-UART-I2C-Display.git
   cd BitDogLab-UART-I2C-Display
   ```
2. Compile e carregue o código na **BitDogLab** utilizando **VS Code + Pico SDK**.

### ▶️ Uso

1. Conecte a placa ao computador via **USB**.
2. Abra o **Serial Monitor** no VS Code.
3. Envie caracteres e veja a resposta no **display OLED** e na **matriz WS2812**.
4. Pressione os botões para alternar o estado dos LEDs.

---

## 📷 Fluxo do Projeto

### 📊 Diagrama do Sistema

![Untitled Diagram (10)](https://github.com/user-attachments/assets/f4078248-be85-4fec-9978-97e30e86c093)

(Aqui você pode incluir um diagrama do circuito e conexões.)

### 🎥 Demonstração

🔗 Assista no YouTube:

 [![Demonstração do Projeto](https://img.youtube.com/vi/klWZOF3K0bk/0.jpg)](https://youtu.be/klWZOF3K0bk)

https://youtu.be/klWZOF3K0bk

📌 Este segundo vídeo foi editado com cortes e velocidade aumentada em **x2** para se enquadrar no requisito de **2 minutos**./

🔗 Assista no YouTube: 

[![Versão Editada](https://img.youtube.com/vi/8sewJE6tilU/maxresdefault.jpg)](https://youtu.be/8sewJE6tilU)
https://youtu.be/klWZOF3K0bk

---

💡 Desenvolvido com ❤️ por **Elisson Nadson** .

