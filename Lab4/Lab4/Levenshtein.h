#pragma once
int levenshtein_r(
	int lx,           // длина строки x 
	const char x[],   // строка длиной lx
	int ly,           // длина строки y
	const char y[]    // строка y
);
int levenshtein(int lx, const char x[], int ly, const char y[]);