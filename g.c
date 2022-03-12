#include <stdio.h>

#define HEIGHT 100
#define WIDTH 100
int main()
{
    int len = 100;
    char line[len];
    int matrix[HEIGHT][WIDTH];

    int w = 0, h = 0;

    char vert[] = "ABCDEFGHIJKLMNOPQRST";
    int f;

    FILE * matrixFile;
    FILE * graphFile;

    matrixFile = fopen("graph.txt", "r");

    while(fgets(line, len, matrixFile)){
        w = 0;
        for(int i = 0; line[i]; i++){
            if(line[i] != ' '){
                matrix[h][w] = line[i]-'0';
                w++;
            }
        }
        h++;
    }
    graphFile = fopen("graf.gv", "w");
    
    fputs("graph  {", graphFile);

    for (int i = 0; i < h; i++) {
        f = 1;
        for (int j = 0; j < w; j++) {
            if(matrix[i][j] == 1){
                if(f){
                    fputc(vert[i], graphFile);
                    fputs("--", graphFile);
                    fprintf(graphFile, "%c;", vert[j]);
                    fputs("\n", graphFile);

                    //f = 0;
                }else{
                    fprintf(graphFile, "%c;", vert[j]);
                }

            }
        }
        
    }
    fputs("}", graphFile);
    fclose(graphFile);
    fclose(matrixFile);
    return 0;
}