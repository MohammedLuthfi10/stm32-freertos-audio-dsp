# 🎧 Inertial Audio Engine

A **real-time, motion-controlled audio effects processor** built on the **STM32F407 Discovery** board using **FreeRTOS**.

This project is designed as an advanced, hands-on learning experience for mastering **FreeRTOS** and real-time embedded audio systems. It implements a complete **audio digital signal processing (DSP)** pipeline—from microphone input to headphone output—with effect parameters dynamically controlled by the **physical orientation** of the board.

---

## 📑 Table of Contents
- [Overview](#overview)
- [Features](#features)
- [How It Works](#how-it-works)
- [Hardware Requirements](#hardware-requirements)
- [Software Requirements](#software-requirements)
- [Getting Started](#getting-started)
- [How to Use](#how-to-use)
- [Project Architecture](#project-architecture)
- [Future Enhancements](#future-enhancements)
- [License](#license)

---

## 🧠 Overview

The **Inertial Audio Engine** captures live audio from the onboard MEMS microphone, processes it in real-time using DSP algorithms, and plays the result through the headphone jack.  
The twist: effect parameters (like delay time or tremolo rate) are **controlled by tilting** the STM32F4 Discovery board — using its onboard MEMS **accelerometer**.

This project demonstrates:

- **Hard Real-Time Constraints** – Managing high-frequency audio data without glitches  
- **Multitasking** – Running multiple real-time FreeRTOS tasks concurrently  
- **Inter-Task Communication** – Using Stream Buffers and Mutexes for synchronization  
- **Hardware Interfacing** – Using DMA with I2S, I2C, and SPI in real time  

---

## ✨ Features

- 🎵 **Real-Time Audio Pipeline**  
  Captures, processes, and outputs audio at a **48kHz** sampling rate.

- 🎚️ **Motion-Controlled Effects**  
  Tilt the board on the **X** and **Y** axes to dynamically modulate DSP parameters.

- 🎧 **Multiple DSP Effects**
  - **Bypass:** Clean audio pass-through  
  - **Echo:** Delay and feedback controlled by tilt  
  - **Flanger:** “Jet-plane” modulation; tilt controls LFO rate/depth  
  - **Tremolo:** Pulsating volume modulation; tilt controls LFO rate/depth  

- ⚡ **FreeRTOS Powered**  
  Built on a robust preemptive multitasking RTOS architecture.

- 🌀 **Efficient Data Handling**  
  Utilizes DMA and **double-buffering (ping-pong)** to free CPU for DSP work and prevent dropouts.

- 🟢 **Simple User Interface**  
  One push-button cycles through effects; onboard LEDs indicate the current effect mode.

---

## ⚙️ How It Works

1. **Audio Input:**  
   Captured via the **I2S peripheral** connected to the MEMS microphone.  
   DMA operates in circular (double-buffered) mode to continuously fill buffers.

2. **Audio Input Task:**  
   Triggered by DMA interrupts when a buffer half completes.  
   It copies raw audio blocks into a **FreeRTOS StreamBuffer**.

3. **DSP Task:**  
   Waits for audio data from the input stream.  
   Applies the selected DSP effect and writes processed audio to an output stream.  
   Reads accelerometer data (protected by a mutex) to dynamically adjust effect parameters.

4. **Sensor Task:**  
   Reads the MEMS accelerometer periodically via **I2C** and updates a shared data structure with tilt data.

5. **Audio Output Task:**  
   Reads processed audio from the output stream and sends it to the onboard DAC via I2S/DMA for playback.

---

## 🧰 Hardware Requirements

| Component | Description |
|------------|-------------|
| **STM32F407G-DISC1 (Discovery)** | Main development board |
| **Micro-USB Cable** | Power and programming |
| **Headphones (3.5mm jack)** | For audio output |

---

## 💻 Software Requirements

- **STM32CubeIDE** *(v1.10.0 or later recommended)*  
- **STM32Cube FW_F4 MCU Package** (managed within CubeIDE)  
- **Git** (for cloning the repository)  

---

## 🚀 Getting Started

### 1️⃣ Clone the Repository
```bash
git clone https://your-repository-url/inertial-audio-engine.git

# STM32F4 Audio Effects Project

## Setup Instructions

1. **Open in STM32CubeIDE**
   - Launch STM32CubeIDE
   - Go to File → Open Projects from File System...
   - Select the cloned repository folder
   - Click Finish

2. **Build the Project**
   - The project includes all peripheral and FreeRTOS configurations via the .ioc file.
   - Click the Build button (🛠️) or press Ctrl + B.

3. **Flash to the Board**
   - Connect the STM32F4 Discovery board via Micro-USB
   - Click the Run button (▶️) or press Ctrl + F11
   - (This compiles, flashes, and starts debugging.)

## How to Use

- **Connect Headphones**
  - Plug them into the 3.5mm jack.

- **Power On**
  - The board powers via USB.

- **Select an Effect**
  - Press the blue user button (B1) to cycle through effects.

  | LED Indicator | Effect   |
  |---------------|----------|
  | No LED        | Bypass   |
  | Green (LD4)   | Echo     |
  | Orange (LD3)  | Flanger  |
  | Red (LD5)     | Tremolo  |

- **Control the Sound**
  - Speak into the onboard MEMS microphone (marked “MIC”).
  - Tilt the board left/right or forward/backward to modulate the sound dynamically.

## Project Architecture

The application runs five primary FreeRTOS tasks, each handling a dedicated subsystem:

| Task              | Responsibility                              |
|-------------------|---------------------------------------------|
| audioInputTask    | Handles DMA/I2S microphone input            |
| dspTask           | Processes audio and applies effects         |
| audioOutputTask   | Sends processed data to DAC                 |
| sensorTask        | Reads accelerometer via I2C                 |
| uiTask            | Handles button and LED updates              |

All tasks communicate via Stream Buffers, Queues, and Mutexes to ensure safe and synchronized data flow.

## Future Enhancements

- 🎶 More DSP Effects: Reverb, Pitch Shift, Distortion
- 💾 SD Card Integration: Record or playback audio via FATFS
- 🌐 Network Control: Adjust effects remotely via TCP/IP or OSC
- 📊 Visualizer: Add LCD to show waveforms or effect parameters in real-time

