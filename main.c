#define _CRT_SECURE_NO_WARNINGS
#define _WINDOWS


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <Windows.h>

#include "mione.h"
#include "verson.h"




int main() {
	LPWSTR* cmds;
	int num;
	cmds = CommandLineToArgvW(GetCommandLineW(), &num);
	char m[256];
	if (num >= 2) {
		if (wcscmp(cmds[1], L"o") == 0) {
			WideCharToMultiByte(CP_ACP, 0, cmds[2], -1, m, sizeof(m), NULL, NULL);

			OPEN(m);
		}

		if (wcscmp(cmds[1], L"home") == 0) {

			printf("==================================================================\n");
			printf("          ____                                                \n");
			printf("        ,'  , `.                                              \n");
			printf("     ,-+-,.' _ |   ,--,                                       \n");
			printf("  ,-+-. ;   , || ,--.'|       ,---.         ,---,             \n");
			printf(" ,--.'|'   |  ;| |  |,       '   ,'\\    ,-+-. /  |            \n");
			printf("|   |  ,', |  ': `--'_      /   /   |  ,--.'|'   |    ,---.   \n");
			printf("|   | /  | |  || ,' ,'|    .   ; ,. : |   |  ,'' |   /     \\  \n");
			printf("'   | :  | :  |, '  | |    '   | |: : |   | /  | |  /    /  | \n");
			printf(";   . |  ; |--'  |  | :    '   | .; : |   | |  | | .    ' / | \n");
			printf("|   : |  | ,     '  : |__  |   :    | |   | |  |/  '   ;   /| \n");
			printf("|   : '  |/      |  | '.'|  \\   \\  /  |   | |--'   '   |  / | \n");
			printf(";   | |`-'       ;  :    ;   `----'   |   |/       |   :    | \n");
			printf("|   ;/           |  ,   /             '---'         \\   \\  /  \n");
			printf("'---'             ---`-'                             `----'   \n");
			printf("==================================================================");
		}
		if (wcscmp(cmds[1], L"version") == 0) {
			printf("Mione version:%s\n\n\n", mione_verson);
		}
        if (wcscmp(cmds[1], L"open_source") == 0){
            printf("\n\n\nMione : %s \n\n\n", "https://github.com/Mioprety/Mione");
        }
	}
	else if (num == 1) {
		OPEN("index.mio");
		printf("a... you might find page is here => 'mione home'\n\n");
	}



	LocalFree(cmds);
	return 0;
}