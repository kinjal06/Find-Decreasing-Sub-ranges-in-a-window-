#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include<fstream>
using namespace std; 

typedef long long ll;
const int MAX = 200000;
int N, K, in[MAX];
int increase[2][MAX], decrease[2][MAX];

int main()
{
    //scanf("%d%d", &N, &K);
    //read the input file
	ifstream  read("input.txt");
	char ch;
	int N,K,c1[100],lines;
	read>>lines;
	N=lines;
	//cout<<N<<endl;
    for( int i=0;i<=lines;i++){
      read>>c1[i];  
    }
    K= c1[0];
    //cout<<K;
    for(int i=0;i<N;i++){
      in[i]=c1[i+1]; 
      
    }
    //for(int i =0; i<N;i++){printf("%lld",in);}
//populating first row of arrays increase and decrease going through the input
    for(int i=0;i<N-1;i++)
    {
        increase[0][i] = 1 + (i && in[i] >= in[i-1] ? increase[0][i-1] : 0);
        decrease[0][i] = 1 + (i && in[i] <= in[i-1] ? decrease[0][i-1] : 0);
    }
//populating second row of arrays increase and decrease going through the input from end to start	
    for(int i = N-1;i>=0;i--)
    {
        increase[1][i] = 1 + (i < N-1 && in[i] >= in[i+1] ? increase[1][i+1] : 0);
        decrease[1][i] = 1 + (i < N-1 && in[i] <= in[i+1] ? decrease[1][i+1] : 0);
    }

    ll no_inc = 0, no_dec = 0; // to find number of increasing / decreasing subranges
//count the number of increase or decrease in the array 
 for(int i=0;i<K-1;i++)
    {
        no_inc += increase[0][i];
        no_dec += decrease[0][i];
    }
//adjust according to the given window size
    for(int i=K-1;i<=N-1;i++)
    {
        no_inc += min(K, increase[0][i]);
        no_dec += min(K, decrease[0][i]);
        printf("%lld\n", no_inc - no_dec);
        no_inc -= min(K, decrease[1][i-(K-1)]);
        no_dec -= min(K, increase[1][i-(K-1)]);
    }

    return 0;
}