// checklist.cpp — part of wipe-clock.

#include "wipeclock/checklist.h"

#include <cstdio>

namespace wipeclock {

Checklist::Checklist(const std::string& config_path)
    : config_path_(config_path) {}

void Checklist::configure(const std::string& key, const std::string& value) {
    if (key == "verbose") verbose_ = (value == "true");
}

bool Checklist::run() {
    if (verbose_) std::fprintf(stderr, "[wipe-clock] checklist: run\n");
    // core logic lives here
    return true;
}

}  // namespace wipeclock
