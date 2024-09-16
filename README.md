# Denumirea proiectului
Tic-Tac-Toe

# Ce reprezintă proiectul
Acest proiect implementează jocul clasic Tic-Tac-Toe folosind limbajul de programare C++. Jocul implică doi jucători care alternează mutările pe o tablă de 3x3. Scopul fiecărui jucător este de a forma o linie de trei simboluri identice (X sau O) pe orizontală, verticală sau diagonală.

# Care sunt regulile jocului Tic-Tac-Toe
Jocul se desfășoară pe o tablă de 3x3.
Doi jucători joacă, unul utilizând simbolul X, celălalt simbolul O.
Jucătorii plasează alternativ simbolurile lor într-o celulă goală de pe tablă.
Câștigătorul este primul care reușește să alinieze trei simboluri identice pe orizontală, verticală sau diagonală.
Jocul se termină dacă un jucător câștigă sau dacă tabla este completă fără a exista un câștigător, caz în care jocul se încheie cu egalitate.

# Tipuri de date noi declarate
Point: Reprezintă o poziție pe tabla de joc, folosind coordonatele x și y.
Board: Reprezintă tabla de joc 3x3 și gestionează plasarea simbolurilor, verificarea câștigătorului și afișarea stării tablei.
Player: Reprezintă un jucător al jocului, fie X, fie O. Gestionază simbolul și mutările jucătorului.
GameEngine: Controlează logica principală a jocului, inclusiv alternarea între jucători, determinarea câștigătorului și starea generală a jocului.
Painter: Este responsabil de afișarea grafică a tablei de joc și a mesajelor pentru jucători.








