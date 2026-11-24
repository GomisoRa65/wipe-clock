// main.cpp — entry point. Wires config and subsystems together.

#include "wipeclock/settings.h"
#include "wipeclock/timer.h"
#include "wipeclock/reminders.h"
#include "wipeclock/checklist.h"
#include <csignal>
#include <memory>

namespace { std::atomic<bool> g_running{true}; void on_signal(int) { g_running.store(false); } }

int main(int argc, char** argv) {
    std::signal(SIGINT, on_signal);
    std::signal(SIGTERM, on_signal);

    wipeclock::Settings settings = wipeclock::Settings::load_default();
    wipeclock::Timer timer(settings.store_path);
    wipeclock::Reminders reminders(settings.store_path);
    wipeclock::Checklist checklist(settings.store_path);
    std::fprintf(stderr, "[wipe-clock] ready\n");

    while (g_running.load()) {
        // main loop: pump subsystems
        break;
    }
    return 0;
}
