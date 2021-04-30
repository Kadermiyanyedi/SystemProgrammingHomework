#include <stdio.h>
#include <string.h>
#include "../include/fields.h"

void writeOutputFile(char *data, char*filename){
    FILE *fp = fopen(filename,"a");
    fprintf(fp,"%s \n", data);
	fclose(fp);
}

// Kilit dosyasının okunacağı fonksiyon
char *encode(char *data){
    IS is;
    int i;

    is = new_inputstruct("kilit.txt");
    if (is == NULL) {
        perror("error");
        exit(1);
    }

    while(get_line(is) >= 0) {
        char *text = "";
        for (i = 0; i < is->NF; i++) {
            if(strstr(is->fields[i], data)){
                //returnValue(text, "-e");
                text = is->fields[i + 1];
                char *ptr = strtok(text, "\"\"");
                if(ptr != NULL){
                    return ptr;
                }
            }
        }
    }
    jettison_inputstruct(is);
    return data;
}


// Kilit dosyasının okunacağı fonksiyon
char *decode(char *data){
    IS is;
    int i;

    is = new_inputstruct("kilit.txt");
    if (is == NULL) {
        perror("error");
        exit(1);
    }

    while(get_line(is) >= 0) {
        char *text = "";
        for (i = 0; i < is->NF; i++) {
            if(strstr(is->fields[i], data)){
                //returnValue(text, "-e");
                text = is->fields[i - 1];
                char *ptr = strtok(text,"\"\"");
                if(ptr != NULL){
                    return ptr;
                }
            }
        }
    }
    jettison_inputstruct(is);
    return data;
}

void readInputFile(char* filename, char *operation){
    IS is;
    int i;

    is = new_inputstruct(filename);
    if (is == NULL) {
        perror("error");
        exit(1);
    }

    while(get_line(is) >= 0) {
        for (i = 0; i < is->NF; i++) {
            if(strstr(operation, "e")){
                printf("%s\n",encode(is->fields[i]));
            }
            if(strstr(operation, "d")){
                printf("%s\n",decode(is->fields[i]));
            }
        }
    }
    jettison_inputstruct(is);
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
	
	readInputFile(inputFileName, parameter);
    
    return 0;
}
