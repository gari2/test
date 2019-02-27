#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n ;
    float total = 0;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        float m;
        scanf("%f",&m);
        char A[10];
        scanf("%s",A);
        for(int i=0;i<n;i++){
            float m;
            scanf("%f", &m);
            if(A[0] == 'j'){
                total += m;

            } else{
                total += (m * 300000);
            }
        }
        printf("%f\n", total);
        return 0;

    }
}