#define string char*
#define fnum float
#define twice_as_bignum double
#define bignum long int
#define num int

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "lkutils.h"

#define LINE 1024
#define then {
#define fi }
#define esac break;
#define ptr *
#define iterate(buf,fp) while(fgets(buf,LINE,fp) != NULL)
#define putts(str) printf("%s\n",str)
#define loop(times) for(int g = 0;g < times;g++)
#define forever for( ; ; )

num used = 0;
char tttt[4];
int ignore = 0;
int queue;
int Lline = 0;

num number(string what){
	num n = (num)what[0] - (48 * (what[0] >= '0' && what[0] <= '9'));	
	num nn = (num)what[1] - (48 * (what[1] >= '0' && what[1] <= '9'));
	return(n * nn);
}

char replace(char old, char neww, char* where){
	char *src,*dest;
	for(src = dest = where;*src != '\0';src++){
		*dest = *src;
		if(old == *dest){
			*dest = neww;
			return(old);
		}
		dest++;
	}
	return(0);
}

char* sub(int start,int end,char* where){
	char *src,*dest;
	char *copy = (char*)malloc(LINE);
	strncpy(copy,where,LINE);
	int counter = 0;
	for(src = dest = copy;*src != '\0';src++){
		*dest = *src;
		if(counter >= start && counter <= end) dest++;
		counter++;
	}
	*dest = '\0';
	return(copy);
}

num read(string line,num linum){
	num repeater = -10;
	int ttmp = ' ';
	char forif[4];
	char tmp;
	char parg1 = 0;
	char parg2 = 0;
	string parg3 = (string)malloc(255);
	num  res  = 0;
	num  temp = 0;

	lp:
	for(int i = 0;i < strlen(line);i++){
		parg1 = line[i+1];
		parg2 = line[i+2];
		strncpy(forif,sub(i+1,i+5,line),4);
		strncpy(parg3,sub(i+1,xlookfor(i,';',line)-1,line),254);
		switch(line[i]){
			case '#':
				queue = 0;
			esac
			case '"':
				queue++;
			esac
			case '.':
				if(queue != number(sub(i+1,i+2,line))){
					goto out;
				}
			esac
			case '&':
				Lline = linum;
			esac
			case '@':
				if(repeater == -10){
				    repeater = number(parg3);
				}
			esac
			case 'G':
				scanf("%d",&ttmp);
			esac
			case 'R':
				srand(repeater + time(NULL));
				if((temp = lookfor('*',parg3)) != -1){
					if(lookfor('%',parg3) != -1){
						temp = ttmp;
					}
					else {
						temp = number(sub(temp+1,temp+2,parg3));
					}
				}
				else{
					temp = 0;
				}
				if(rand() % 3 == 1 || rand() % 3 == 0){
					for(int c = 0;c < temp;c++){
						putchar(parg1);
					}
				}
				else{
					for(int c = 0;c < temp;c++){
						putchar(parg2);
					}
				}
				putchar('\n');
			esac
			case 'P':
				putchar(parg1);
			esac
			case '$':
				scanf("%4s",tttt);
			esac
			case '|':
				srand(repeater + time(NULL));
				if(rand() % 2 == 1){
					goto out;
				}
			esac
			case '/':
				srand(repeater + time(NULL));
				if(rand() % 5 != 1){
					goto out;
				}
			esac
			case '?':
				if(strncmp(tttt,forif,3) != 0){
					goto out;
				}
			esac
			case '{':
			esac
			case '>':
				printf("%s\n",line);
			esac
			case '!':
				exit(0);
			esac
			case '=':
				printf("%s\n",parg3);
			esac
			case 'Z':
				printf("%d\n",queue);
			esac
		}
	}
	out:
	if(repeater > 0){
		repeater--;
		goto lp;
	}
	return(0);
}

