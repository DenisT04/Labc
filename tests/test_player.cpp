#include "player.hpp"
#include <cassert>

int main() {
    // Testează constructorul
    Player p1('X');
    assert(p1.GetMarker() == 'X');

    // Testează GetMove (de obicei este o metodă abstractă, dar aici este doar pentru exemplu)
    // Nu se poate testa GetMove fără o implementare validă a unui input de la utilizator,
    // deci poate fi ignorat pentru acest exemplu simplu.
    
    return 0;
}
