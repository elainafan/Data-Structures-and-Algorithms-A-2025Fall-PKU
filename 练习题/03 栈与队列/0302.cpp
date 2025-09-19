#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x&(-x))
using namespace std;
string x;
int t;
stack<int>s;
stack<char>fs;
int pro(char x){
    if(x=='('||x==')') return 3;
    else if(x=='*'||x=='/') return 2;
    else if(x=='+'||x=='-') return 1;
    return 0;
}
void calculate(char t){
    int y=s.top();s.pop();
    int x=s.top();s.pop();
    if(t=='+') s.push(x+y);
    else if(t=='-') s.push(x-y);
    else if(t=='*') s.push(x*y);
    else if(t=='/') s.push(x/y);
    return ;
}
int main(){
    cin>>t;
    while(t--){
        while(!s.empty()) s.pop();
        while(!fs.empty()) fs.pop();
        cin>>x;
        for(int i=0;i<x.length();i++){
            if(x[i]>='0'&&x[i]<='9'){
                string temp="";
                while(x[i]>='0'&&x[i]<='9'){
                    temp+=x[i];i++;
                }
                i--;s.push(stoi(temp));
            }
            else{
                if(x[i]==')'){
                    while(!fs.empty()&&fs.top()!='('){
                        calculate(fs.top());fs.pop();
                    }
                    fs.pop();
                }
                else if(fs.empty()||pro(x[i])>pro(fs.top())||fs.top()=='(') fs.push(x[i]);
                else{
                    calculate(fs.top());fs.pop();i--;
                }
            }
        }
        while(!fs.empty()){
            calculate(fs.top());fs.pop();
        }
        cout<<s.top()<<endl;
    }
    system("pause");
    return 0;
}