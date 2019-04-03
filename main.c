#include <stdlib.h>
#include "screen.h"
#include <time.h>
#include <stdio.h>
#include "sound.h"
#include <signal.h>

int main() {
	FILE *f;
	short sd[RATE];
	for(;;){
		int ret = system(RCMD);
		if(ret == SIGINT) break;
		f = fopen("test.way", "r");
		if(f == NULL) {
			printf("Cannot open the file\n");
			return 1;
		}

		clearScreen();
		setColors(RED, bg(YELLOW));
		struct WAVHDR hdr;
		fread(&hdr, sizeof(hdr), 1, f);	//read WAV header
		fread(&sd, sizeof(sd), 1, f);	//read WAV data
		fclose(f);
		displayWAVHDR(hdr);
		displayWAVDATA(sd);
	}
	resetColors();
//	getchar();
}
