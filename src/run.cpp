#include <bits/stdc++.h>
#include <format.h>
using namespace std;

const int REMSIZE = 8;

char rem[REMSIZE];
short current;
string com;
stack<int> bcs;

int main() {
    if (__argc < 2) {
        printf("Error : Args Error");
        exit(1);
    }
    freopen(__argv[1],"r",stdin);
    char c;
    while ((c = getchar()) != EOF) com += c;

    for (int i=0;i<com.length();i++) {
        switch(com[i]) {
            case '+':rem[current]++;break;
            case '-':rem[current]--;break;
            case '.':printf("%c",rem[current]);break;
            case '>':{current++;current%=REMSIZE;};break;
            case '<':{current--;if (current < 0) current=REMSIZE-1;};break;
            case '[':{
                if (rem[current] != 0) bcs.push(i);
                else {
                    int flor = 0;
                    do {
                        if (com[i] == '[') flor++;
                        else if (com[i] == ']') flor--;
                        else if (i >= com.length()) {
                            printf("Error : There are no matching parentheses");
                            exit(1);
                        }
                        i++;
                    }while(flor);
                }
            };break;
            case ']':{i = bcs.top()-1;bcs.pop();};break;
            case ' ':case '\n':break;
            default:{printf("Error : '%c' not a command",com[i]);exit(1);};break;
        }
    }
    
    return 0;
}