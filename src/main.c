#include <stdio.h>
#include <string.h>
#include "../include/fields.h"
#include "../include/jrb.h"

JRB b;
JRB bn;

typedef struct {
  char *key;
  char *value;
} Huffman;
Huffman *p;

void writeOutputFile(char *data, char*filename){
    FILE *fp = fopen(filename,"a");
    fprintf(fp,"%s \n", data);
	fclose(fp);
}

void addJRBTree(char *parametre, JRB b){
    IS is;
    int i;
    is = new_inputstruct("kilit.txt");
    if (is == NULL) {
        perror("error");
        exit(1);
    }

    while(get_line(is) >= 0) {
        p = malloc(sizeof(Huffman));
        if(is->fields[i+1] != NULL && is->fields[i] != NULL && !strstr(is->fields[i], "}")){

            if(strstr(parametre, "e")){
                p->key = (char *) malloc(sizeof(char)*(strlen(is->fields[i])+1));
                strcpy(p->key, is->fields[i]);
                p->value = (char *) malloc(sizeof(char)*(strlen(is->fields[i+1])+1));
                strcpy(p->value, is->fields[i+1]);
                (void) jrb_insert_str(b, p->key, new_jval_v((void *) p));
            }
            if(strstr(parametre, "d")){
                p->key = (char *) malloc(sizeof(char)*(strlen(is->fields[i+1])+1));
                strcpy(p->key, is->fields[i+1]);
                p->value = (char *) malloc(sizeof(char)*(strlen(is->fields[i])+1));
                strcpy(p->value, is->fields[i]);
                (void) jrb_insert_str(b, p->key, new_jval_v((void *) p));
            }

        }
    }
    jettison_inputstruct(is);

}
// Kilit dosyasının okunacağı fonksiyon
char *returnKey(char *data){

    jrb_traverse(bn, b) {
        p = (Huffman *) bn->val.v;

        char *text = "";
        if(strstr(p->key, data)){
                text = p->value;
                char *ptr = strtok(text, "\"\"");
                if(ptr != NULL){
                    return ptr;
                }
        }
    }
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
            printf("%s\n",returnKey(is->fields[i]));
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
    b = make_jrb();
	addJRBTree(parameter, b);
	readInputFile(inputFileName, parameter);
    
    return 0;
}
