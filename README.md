# Cryptocurrency Exchange Simulation (C++)

A modular, object-oriented cryptocurrency exchange simulation built in modern C++, modeling order books and trading engine workflows.

> **Status:** Active Development (University of London — OOP Specialization)

## Architecture Overview
- **`OrderBookEntry`**: Models individual market orders with timestamps, currency pairs, scoped order types (`bid`/`ask`), price, and amount.
- **`MerkelMain`**: Application coordinator managing menu loops, user interactions, and market analytics displays.
- **`main.cpp`**: Clean bootstrap entry point launching the trading application.

## Build and Run
Compile all translation units together using `g++`:
```powershell
g++ *.cpp -o main.exe
.\main.exe