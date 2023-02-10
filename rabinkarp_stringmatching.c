#include<stdio.h>
#include <stdlib.h>
#include<string.h>
int main(){
    char text[100];
    char pattern[50];
    int q=13;
    int n=strlen(text);
    scanf("%d", &n);
    scanf ("%s", text);
    int m=strlen(pattern);
    scanf("%d", &m);
    scanf ("%s", pattern);
    int t=0;
    int i,j;
    int p=0;
    int d=10;
    int h=1;
    for ( i = 0; i < m - 1; i++){
        h = (h * d) % q;
    }
    for(int i=0;i<m;i++){
        p=(d*p+pattern[i])%q;
        t=(d*t+text[i])%q;
    }
    for(int i=0;i<=n-m;i++){
        if (p==t){
            for( j=0;j<m;j++){
                if(pattern[j]!=text[i+j]){
                    break;
                    
                }
            }
            if (j == m){
                printf("String found in position %d \n", i+1);
            }
        }
       
        else if(i<n-m){
            t = (d * (t - text[i] * h) + text[i+m]) % q;
            if (t < 0)
            t = (t + q);
        }
        
        
        
    }
    if(p!=t){
        printf("String not found");
    }
    
}
