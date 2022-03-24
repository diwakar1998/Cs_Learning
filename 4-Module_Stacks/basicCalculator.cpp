#include <iostream>
#include <stack>
#include<string>
int operateOnAB(int a,int b,char operation){
    switch (operation) {
        case '+':
            return a+b;
        case '-':
            return a-b;
        case '/':
            return a/b;
        case '*':
            return a*b;

    }
    return 0;
}
int precedence(char a){
    if(a=='+'||a=='-'){
        return 1;
    }
    else if(a=='*'||a=='/'){
        return 2;
    }
    else if(a=='^'){
        return 3;
    }
    else return -1;
}
bool isNumber(char a){
    if(a >= '0' && a <='9'){
        return true;
    }
    return false;
}
bool isOperator(char a){
    if(a == '+' ||a == '-' ||a == '*' ||a == '/'){
        return true;
    }
    return false;
}
std::string postFixConverter(std::stack<char> stack,std::string infix){
    std::string postfix;
    for(int i=0;i<infix.length();i++){
        //takes all numbers and appends it to postfix expression
        if(isNumber(infix[i])){
            postfix+=infix[i];
        }
        //pushes opening braces into stack
        else if(infix[i] == '('){
            stack.push(infix[i]);
        }
        //when a closing brace is found we need to pop stack elements until
        //a opening brace is found or till the stack is empty
        else if(infix[i] == ')'){
            while(stack.top()!='('  && !stack.empty()){
                char temp = stack.top();
                postfix+=temp;
                stack.pop();
            }
            if(stack.top() == '('){
                stack.pop();
            }
        }
        //check if char is operator
        else if(isOperator(infix[i])){
            if(stack.empty()){
                stack.push(infix[i]);
            }
            else{
                if(precedence(infix[i])> precedence(stack.top())){
                    stack.push((infix[i]));
                }
                else if(precedence(infix[i])== precedence(stack.top()) && infix[i] == '^'){
                    stack.push(infix[i]);
                }
                else{
                    while(!stack.empty()&& precedence(infix[i])<= precedence(stack.top())){
                        char temp = stack.top();
                        postfix+= temp;
                        stack.pop();
                    }
                    stack.push(infix[i]);
                }
            }
        }
    }

    while(!stack.empty()){
        postfix+=stack.top();
        stack.pop();
    }
    return postfix;
}
int solvePostFixExp(std::string postfixExp){
    std::stack<int> stack;
    for(int i=0;i<postfixExp.length();i++){
        if(isNumber(postfixExp[i])){
            stack.push(postfixExp[i]-'0');
        }
        else if(isOperator(postfixExp[i])){
            int a,b;
            a= stack.top();
            stack.pop();
            b= stack.top();
            stack.pop();
            stack.push(operateOnAB(b,a,postfixExp[i]));
        }
    }
    return stack.top();
}

int main(){
    std::string infix,postfix;
    std::cout<<"Enter a expression to be evaluated: ";
    std::getline(std::cin,infix);
//    infix = "5+1-4";
    std::stack<char> stack;
    int result = solvePostFixExp(postFixConverter(stack,infix));
    std::cout<<result;
}