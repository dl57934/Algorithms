 #include <stdio.h>
 #include <algorithm>
 #include <stdlib.h> 
 using namespace std;
 
 void solve(int index);
 
 int main(){
    int testCase = 0;
    
    scanf("%d", &testCase);
    for(int i = 1; i <= testCase; i++)
        solve(i);
 }
 
 void solve(int index){
     int S, N, K; // N total Level, K now Level, S find Level
     
     scanf("%d %d %d", &N, &K, &S);
     
     int maxNum = min((N - S) + (K - S), N);
     
     printf("Case #%d: %d\n", index, maxNum + K); 
 } 