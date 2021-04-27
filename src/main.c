#include <stdio.h>
#include "../include/fields.h"
void readInputFile(){
    IS is;
    int i;

    is = new_inputstruct("a.txt");
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

void writeOutputFile(char *data){
    FILE *fp = fopen("output.txt","a");
    fprintf(fp,"%s \n", data);
	fclose(fp);
}

int main(int argc, char** argv) {
    //readInputFile();
    writeOutputFile("hello");
    writeOutputFile("world");
    return 0;
}