# BitDogLab - UART, I2C e Display


## Descrição

Este projeto implementa comunicação serial usando **UART e I2C** no microcontrolador **RP2040**, utilizando a placa **BitDogLab**. O sistema interage com botões, LEDs e um display OLED SSD1306, explorando interrupções e debounce.

## Funcionalidades

- 📡 **Recebimento de caracteres via UART**:
  - Cada caractere digitado no **Serial Monitor** é exibido no **display SSD1306**.
  - Números de **0 a 9** ativam símbolos na **matriz 5x5 WS2812**.
  
- 🎛 **Interação com botões**:
  - **Botão A** alterna o estado do **LED Verde** e exibe informações no **display** e no **Serial Monitor**.
  - **Botão B** alterna o estado do **LED Azul** com registro no **display** e **Serial Monitor**.

- 🔄 **Modificação da biblioteca `font.h`**:
  - Adição de caracteres minúsculos personalizados.

- 🖥 **Controle de LEDs**:
  - Uso da **matriz WS2812** e **LED RGB** com GPIOs da **BitDogLab**.

## Requisitos

✅ Implementação de **interrupções (IRQ)** para botões.  
✅ Tratamento de **debouncing** via software.  
✅ Controle de **LEDs comuns e endereçáveis WS2812**.  
✅ Uso do **display SSD1306** via **I2C**.  
✅ Envio de informações via **UART**.  
✅ Código bem estruturado e comentado.  

---

## 📌 Hardware Utilizado

| Componente        | Conexão GPIO |
|------------------|-------------|
| Matriz WS2812 (5x5) | GPIO 7 |
| LED RGB (R, G, B)  | GPIO 11, 12, 13 |
| Botão A          | GPIO 5 |
| Botão B          | GPIO 6 |
| Display SSD1306  | GPIO 14, 15 (I2C) |

---

## 🚀 Como Executar

### 🔧 Instalação

1. Clone o repositório:
   ```sh
   git clone https://github.com/ElissonNadson/BitDogLab-UART-I2C-Display.git
   cd BitDogLab-UART-I2C-Display
Compile e carregue o código na BitDogLab utilizando VS Code + Pico SDK.
▶️ Uso
Conecte a placa ao computador via USB.
Abra o Serial Monitor no VS Code.
Envie caracteres e veja a resposta no display OLED e matriz WS2812.
Pressione os botões para alternar o estado dos LEDs.
📷 Fluxo do Projeto

🎥 Demonstração


