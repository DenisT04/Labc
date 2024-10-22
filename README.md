# Tic-Tac-Toe Game

Acest proiect este un joc simplu de **Tic-Tac-Toe**, implementat în C++.

## Structura Proiectului

- **board.hpp / board.cpp**: Gestionarea tablei de joc.
- **gameengine.hpp / gameengine.cpp**: Motorul jocului, logica principală.
- **painter.hpp / painter.cpp**: Desenarea tablei și afișarea mesajelor.
- **player.hpp / player.cpp**: Definirea jucătorilor și gestionarea mutărilor.
- **point.hpp / point.cpp**: Reprezentarea punctelor pe tabla de joc.
- **main.cpp**: Funcția principală care inițializează și rulează jocul.

## Pași pentru construirea proiectului

1. Asigură-te că ai instalat un compilator C++ (precum `g++`).
2. În terminal, navighează către directorul proiectului.
3. Rulează comanda:

    ```bash
    make
    ```

   Aceasta va compila toate fișierele sursă și va genera executabilul `TicTacToe.exe`.

4. Pentru a curăța fișierele obiect și executabilul, rulează:

    ```bash
    make clean
    ```

## Rularea jocului

După ce proiectul a fost compilat, poți rula jocul executând:

```bash
./TicTacToe.exe









