#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

	char mail[110], aux[110];
	int i, j, sz;
	
	fgets( mail, 110, stdin );
	sz = strlen(mail);
	mail[sz-1] = mail[sz];
	i = 1, j = 1;
	aux[0] = mail[0];
	
	while( !(mail[i] == 'a' && mail[i+1] == 't') ) aux[j++] = mail[i++];
	aux[j++] = '@';
	i += 2;

	while( mail[i] ) aux[j++] = mail[i++];
	aux[j] = mail[i];
	sz = j;
	
	i = 1, j = 1;
	
	mail[0] = aux[0];
	
	while( (i+2) < (sz-1) ){
		if( aux[i] == 'd' && aux[i+1] == 'o' && aux[i+2] == 't' ){
			mail[j++] = '.';
			i += 3;
		} else mail[j++] = aux[i++];
	}
	
	while( aux[i] ) mail[j++] = aux[i++];
	mail[j] = aux[i];
	
	puts( mail );
	
	return 0;
}

