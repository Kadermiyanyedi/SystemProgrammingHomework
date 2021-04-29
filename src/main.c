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

// Kilit dosyasının okunacağı fonksiyon
char *encode(char *data, char *filename){
    // char word[200];
    // FILE *fp = fopen(filename,"a");
    // while( fscanf(fp, "%s", word) != EOF ) 
    // {
    // 	if(data == is->data)
    	
    // }
	// fclose(fp);
}

int main(int argc, char** argv) {
    //readInputFile();
    
    if (argc != 4) {
    fprintf(stderr, "usage: printwords filename\n");
    exit(1);
    }
	char *parameter = argv[1];
	char *inputFileName = argv[2];
	char *outputFileName = argv[3];
	
	printf ("%s ",parameter);
	printf ("%s ",inputFileName);
	printf ("%s ",outputFileName);
	
	//writeOutputFile("hello",outputFileName);
    
    return 0;
}
