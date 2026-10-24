# Cyber-Swiss-Knife
The Cyber Swiss Knife is a tool that can be used as a watch and a NFC key for such things as cards, scooters etc. it has security systems and a esp-32S3 mini on it.

## Features
---
This Hacking tool works as a keychain on your bag, a watch, a nfc wallet and a  wireless connections trolling-tool.
1- You can scan high frequencies and reuse them, troll wifi and bluetooth connections.
2-You can use it as a NFC-Wallet for simple cards such as escooter, e bike and metro cards.
3-You can use it as a keychain! it looks Cool and works pretty well.
4-A watch! 

---

## Technical overview
---
It uses a ESP32-S3-N16R8 board as a main controller, a 1.3'' OLED screen for the menu and timer,a PN532 NFC reader for the NFC stuff,a CC1101 high-frequency antenna for higher frequencies, 2x NRF24L01+ Module for lower frequencies and radio, a 5-way mini joystick module for selecting the feature over the OLED screen, and a 3.7v 2000mah Li-po battery.

---

## PCB 

The PCB was designed in **KiCad**.

The repository contains:

- KiCad schematic
- KiCad PCB layout
- Gerber files
- Drill files
- BOM
- PCB production files

---

## 📁 Repository Structure

```text
Wifi-Death-V1/
│
├── Firmware/
│   └── Firmware source
│
├── Images/
│   └── Project photos and renders
│
├── PCB/
│   ├── KiCad project
│   ├── Schematic
│   ├── PCB layout
│   └── BOM
│
├── Production/
│   └── Gerber and drill files
│
└── README.md
