#include <stdio.h>
#include <string.h>
#include "../include/fields.h"
void readInputFile(char*filename){
    IS is;
    int i;

    is = new_inputstruct(filename);
    if (is == NULL) {
        perror("error");
        exit(1);
    }

    while(get_line(is) >= 0) {
        for (i = 0; i < is->NF; i++) {
            printf("%s\n", is->fields[i]);
        }
    }
    jettison_inputstruct(is);
}

void writeOutputFile(char *data,char*filename){
    FILE *fp = fopen(filename,"a");
    fprintf(fp,"%s \n", data);
	fclose(fp);
}

int main(int argc, char** argv) {
    //readInputFile();
    
	
	
	int d=0;
	char* parameter;
	char *inputFileName;
	char *outputFileName;
	const char *delp;
	char* dz[4];
	printf("komut girin\n");
	char command[40];
	scanf("%[^\n]s",command);
	delp = strtok (command, " &");
	while (delp != NULL)  {
      printf ("%s\n", delp);
	  dz[d]=delp;	  
	  d++;	  
      delp = strtok (NULL, " &");
    }
	
	parameter=dz[1];
	inputFileName=dz[2];
	outputFileName=dz[3];
	
	//printf (parameter);
	//printf (inputFileName);
	//printf (outputFileName);
	
	writeOutputFile("hello",outputFileName);
    
	
	
    return 0;
}