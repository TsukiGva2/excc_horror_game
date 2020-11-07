#include "excc.h"

num main(num argc, string argv[]) {
	FILE ptr fp;
	char ptr buf = (string)malloc(LINE);
	num lc = 0;

	if((fp = fopen("main.xc","r")) == NULL) then
		printf("There's no 'main.xc' in that directory!\nplease create one and rerun the program\n");
		exit(1);
	fi

	refile:
	lc = 0;
	fp = fopen("main.xc","r");
	iterate(buf,fp) {
		if(ignore < 1) then
			read(buf,lc);
		fi
		else {
			--ignore;
		}
		++ lc;
	}
	ignore = Lline;
	goto refile;
	return(0);
}
