

# Atividade 1: Semáforo com Temporizador Periódico

## Descrição
Este projeto implementa um semáforo utilizando o microcontrolador **Raspberry Pi Pico W** e a função `add_repeating_timer_ms()` do SDK Pico. O semáforo alterna entre os estados **vermelho**, **amarelo** e **verde** a cada **3 segundos**. Além disso, o programa imprime mensagens na porta serial a cada segundo.

---
## Requisitos

### Hardware
- **Microcontrolador**: Raspberry Pi Pico W.
- **LEDs**:
  - 1 LED vermelho.
  - 1 LED amarelo.
  - 1 LED verde.
- **Resistores**: 3 resistores de 330Ω.
- **Simulador**: [Wokwi](https://wokwi.com/)

### Software
- **Ambiente de Desenvolvimento**: VS Code com extensões para Pico SDK.
- **Ferramentas**:
  - Kit de Desenvolvimento de Software (SDK) do Raspberry Pi Pico.
- **Monitor Serial**: Extensão "Serial Monitor" no VS Code

---

## Configuração do Projeto

### 1. Clone o Repositório
Clone este repositório em sua máquina local:

```bash
git clone https://github.com/lipesilvapr/Atv-Semaforo.git
```

### 2. Configure o `CMakeLists.txt`
Certifique-se de que o arquivo `CMakeLists.txt` está configurado corretamente para habilitar a saída serial via USB:

```cmake
pico_enable_stdio_usb(semaforo 1)
```

### 3. Compile o Projeto pela extensão instalada no VS code

Isso gerará o arquivo binário `semaforo.uf2`.

---

## Simulação no Wokwi

Se você estiver usando o simulador Wokwi:
1. Abra o diagrama JSON fornecido no Wokwi.
2. Carregue o código `semaforo.c` no simulador.
3. Execute a simulação e visualize a saída serial na aba "Serial Monitor".

---

## Funcionalidades

### 1. Semáforo
- O semáforo inicia no estado **vermelho**.
- A cada **3 segundos**, o estado muda sequencialmente:
  - Vermelho → Amarelo → Verde → Vermelho.

### 2. Saída Serial
- A rotina principal imprime a mensagem `"Semáforo em execução..."` a cada segundo via porta serial.

---

## Estrutura do Código

### Arquivos Principais
- `semaforo.c`: Código-fonte principal com a lógica do semáforo.
- `CMakeLists.txt`: Configuração do projeto para compilação com o SDK Pico.

### Funções Importantes
- `repeating_timer_callback()`: Função de callback chamada a cada 3 segundos para alternar os estados do semáforo.
- `main()`: Rotina principal que inicializa os LEDs e imprime mensagens na porta serial.
