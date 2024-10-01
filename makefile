all: TicTacToe

TicTacToe: board.o gameengine.o painter.o player.o point.o main.o
    g++ -o TicTacToe.exe board.o gameengine.o painter.o player.o point.o main.o

board.o:
    g++ board.cpp -o board.o -c

gameengine.o:
    g++ gameengine.cpp -o gameengine.o -c

painter.o:
    g++ painter.cpp -o painter.o -c

player.o:
    g++ player.cpp -o player.o -c

point.o:
    g++ point.cpp -o point.o -c

main.o:
    g++ main.cpp -o main.o -c

clean:
    rm -f *.o *.exe
