#include <iostream>
#include <stack>
#include <string>
#include <vector>

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

int precedence(std::string a){
    if(a=="+"||a=="-"){
        return 1;
    }
    else if(a=="*"||a=="/"){
        return 2;
    }
    else if(a=="^"){
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
bool isOperator(std::string a){
    if(a == "+" ||a == "-" ||a == "*" ||a == "/"){
        return true;
    }
    return false;
}

void postFixConverter(std::vector<std::string> &tokens,std::vector<std::string> &tokensPostfix){
    std::stack<std::string> stack;
    for(int i=0;i<tokens.size();i++){
        if(tokens[i] == "("){
            stack.push(tokens[i]);
        }
        //when a closing brace is found we need to pop stack elements until
        //a opening brace is found or till the stack is empty
        else if(tokens[i] == ")"){
            while(stack.top()!="("  && !stack.empty()){
                tokensPostfix.push_back(stack.top());
                stack.pop();
            }
            if(stack.top() == "("){
                stack.pop();
            }
        }
        //check if char is operator
        else if(isOperator(tokens[i])){
            if(stack.empty()){
                stack.push(tokens[i]);
            }
            else{
                if(precedence(tokens[i])> precedence(stack.top())){
                    stack.push((tokens[i]));
                }
                else if(precedence(tokens[i])== precedence(stack.top()) && tokens[i] == "^"){
                    stack.push(tokens[i]);
                }
                else{
                    while(!stack.empty()&& precedence(tokens[i])<= precedence(stack.top())){
                        tokensPostfix.push_back(stack.top());
                        stack.pop();
                    }
                    stack.push(tokens[i]);
                }
            }
        }
        else{
            tokensPostfix.push_back(tokens[i]);
        }
    }

    while(!stack.empty()){
        tokensPostfix.push_back(stack.top());
        stack.pop();
    }

}

int solvePostFixExp(std::vector<std::string> &postfixExp){
    std::stack<int> stack;
    for(int i=0;i<postfixExp.size();i++){
        if(isOperator(postfixExp[i])){
            int a,b;
            a= stack.top();
            stack.pop();
            b= stack.top();
            stack.pop();
            char operation = postfixExp[i][0];
            stack.push(operateOnAB(b,a,operation));
        }
        else if(isNumber(postfixExp[i][0])){
            stack.push(std::stoi(postfixExp[i]));
        }
    }
    return stack.top();
}

void convertToVecotor(std::vector<std::string> &tokens,std::string infixExpr){
    std::string buffer="";
    for(int i=0;i<infixExpr.length();i++){
        // std::cout<<infixExpr[i]<<std::endl;
        std::string currentToken(1,infixExpr[i]);
        if(isNumber(infixExpr[i])){
            buffer+=infixExpr[i];
        }
        else if(isOperator(currentToken)||currentToken == "(" || currentToken == ")"){
            tokens.push_back(buffer);
            buffer="";
            buffer = infixExpr[i];
            tokens.push_back(buffer);
            buffer="";
        }
    }
    tokens.push_back(buffer);
}



int main(){
    std::string infix,postfix;
    std::cout<<"Enter a expression to be evaluated: ";
    std::getline(std::cin,infix);
//    infix = "(444-22)/2+10";
    std::vector<std::string> tokens;
    std::vector<std::string> tokensPostfix;
    convertToVecotor(tokens,infix);
    for(auto a:tokens){
        std::cout<<a<<" ";
    }
    std::cout<<"\n";
    postFixConverter(tokens,tokensPostfix);
    for(auto a:tokensPostfix){
        std::cout<<a<<" ";
    }
    int result = solvePostFixExp(tokensPostfix);
    std::cout<<result;
}