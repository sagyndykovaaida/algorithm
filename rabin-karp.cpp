#include <bits/stdc++.h> 
using namespace std; 
const int t = 256;
const int w = 1283;

void Rabin_Karp_Algorithm(string text,string pattern){
    
    int text_len = text.length();
    int patt_len = pattern.length();
    int flag;
    int c=1,i=0;
    int hash_p=0,hash=0;
    while(i<patt_len){
        hash_p=(hash_p*t + pattern[i])%w;
        hash=(hash*t + text[i])%w;
        i++;
    }
    
    for(int i=1;i<=patt_len-1;i++)
        c=(c*t)%w;
    
    i=0;
    while(i<=text_len-patt_len){
       if(hash_p==hash){
            flag=1;
            for(int j=0;j<patt_len;j++){
                if(pattern[j]==text[i+j]){
                    continue;
                }
                else{
                    flag = 0;
                    break;
                }
           }
            if(flag==1)cout<<i<<" ";
       }
       
       if(i<text_len-patt_len){
           hash=((t*(hash-text[i]*c))+text[i+patt_len])%w;
            if(hash<0){
                hash = hash + w;
            }
       }
       i++;
    }
}

int main() 
{ 
    string text = "ababcdabcb"; 
    string pattern="abc";
    Rabin_Karp_Algorithm(text,pattern);
    return 0; 
}