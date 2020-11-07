int lookfor(char what, string where){
	char *src,*dest;
	char *copy = (char*)malloc(1024);
	int counter = 0;
	strcpy(copy,where);
	for(src = dest = copy;*src != '\0';src++){
		*dest = *src;
		if(*dest == what) return(counter);
		dest++;
		counter++;
	}
}

int xlookfor(int start, char what, string where){
	char *src;
	num counter = 0;
	for(src = where;src != '\0';src++){
		if(*src == what && counter >= start){
			return(counter);
		}
		counter++;
	}
	return(-1);
}
