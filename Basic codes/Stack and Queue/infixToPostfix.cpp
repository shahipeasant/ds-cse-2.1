#include<bits/stdc++.h>

using namespace std;

int precedence(char c){
    if(c=='^'){
        return 100;
    }
    else if(c=='*'||c=='/'){
        return 50;
    }
    else if(c=='+'||c=='-'){
        return 25;
    }
    else{
        return 0;
    }
}

string infixToPostfix(string infix){
    string postfix = "";
    stack<char> s;
    for(int i=0; i<infix.size(); i++){
        char symbol = infix[i];
        //operand
        if(symbol>='a'&&symbol<='z'||symbol>='0'&&symbol<='9'){
            postfix += symbol;
        }
        //opening parenthesis
        if(symbol=='('){
            s.push(symbol);
        }
        //operator
        if(symbol=='+'||symbol=='-'||symbol=='*'||symbol=='/'||symbol=='^'){
            while(!s.empty() && s.top() != '(' &&
                   (precedence(s.top()) > precedence(symbol) ||
                   (precedence(s.top()) == precedence(symbol)))){
                postfix += s.top();
                s.pop();
            }
            s.push(symbol);
        }
        //closing parenthesis
        if(symbol==')'){
            while(!s.empty()&&s.top()!='('){
                postfix += s.top();
                s.pop();
            }
            s.pop();
        }
    }
    while(!s.empty()){
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int postfixEval(string infix){
    stack<int> s2;
    int a, b, c;
    string postfix = infixToPostfix(infix);
    for(int i=0; i<postfix.size(); i++){
        if(postfix[i]>='0'&&postfix[i]<='9'){
            s2.push(postfix[i]-'0');
        }
        else if(postfix[i]=='+'||postfix[i]=='-'||postfix[i]=='*'||postfix[i]=='/'){
            a = s2.top()-'0';
            s2.pop();
            b = s2.top()-'0';
            s2.pop();
            if(postfix[i]=='+'){
                c = b+a;
            }
            else if(postfix[i]=='-'){
                c = b-a;
            }
            else if(postfix[i]=='*'){
                c = b*a;
            }
            else if(postfix[i]=='/'){
                c = b/a;
            }

            s2.push(c+'0');
        } 
    }
    return c;
}

int main(){
    string infix, postfix = "";
    cin >> infix;
    postfix = infixToPostfix(infix);
    cout << postfix << endl;  
    return 0;
}