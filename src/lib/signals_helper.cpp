// Copyright (c) 2013, Ali Alavi unless otherwise noted.
// This program is integrated in Molpro with the permission of George Booth and Ali Alavi
  
#include <signal.h>

extern "C"
void neci_sigint(int signo);

// Clear all set signals
extern "C"
void clear_signals() {
	signal(SIGINT, SIG_DFL);
}

// Initialise signals
// --> Catch SIGINT and refer it to the f90 signal handler
extern "C"
void init_signals_helper() {
	clear_signals();
	signal(SIGINT, neci_sigint);
}

