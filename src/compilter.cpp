#include <bits/stdc++.h>
#include <format.h>
using namespace std;

const int REMSIZE = 8;

string com;

string code = util::Format("#include<stdio.h>\nconst int REMSIZE = {};char rems[{}];short current;\nint main(){\n",REMSIZE,REMSIZE);

int main() {
    if (__argc < 3) {
        printf("Error : Args Error");
        exit(1);
    }
    freopen(__argv[1],"r",stdin);
    char c;
    while ((c = getchar()) != EOF) com += c;
    
    for (int i=0;i<com.length();i++) {
        switch(com[i]) {
            case '+':code+="rems[current]++;\n";break;
            case '-':code+="rems[current]--;\n";break;
            case '.':code+="printf(\"%c\",rems[current]);\n";break;
            case '>':code+="current++;current%=REMSIZE;\n";;break;
            case '<':code+="current--;if (current < 0) current=REMSIZE-1;\n";break;
            case '[':code+="while(rems[current]){\n";break;
            case ']':code+="}\n";break;
            case ' ':case '\n':break;
            default:{printf("Error : '%c' not a command",com[i]);exit(1);};break;
        }
    }
    code += ";printf(\"\\n\\n[Press Enter key to continue] \");getchar();return 0;}";
    fstream file("temp.c",ios::out);
    file << code;
    file.close();
    if (system(util::Format("gcc temp.c -o {}",__argv[2]).c_str())) {
        if (system(util::Format("clang temp.c -o {}",__argv[2]).c_str())) {
            printf("Error : No C compiler is found, you will need to install GNU or Clang");
            exit(1);
        }
    }
    printf("\n");
    system(__argv[2]);
    
    return 0;
}