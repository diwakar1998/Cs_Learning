#include<iostream>
#include<vector>

std::vector<std::string> cases= {"Camel Case", "Snake Case", "Kebab Case", "Pascal Case" , "Upper Case Snake","Print in all formats"};

void convert(std::string stringToConvert,int caseOfChoice){
    std::string inputString="";
    std::vector<std::string> inputWordsList ={};
    std::string buffer="";

//removes anything thats not alphabet
    for(int i=0;i<stringToConvert.length();i++){
        
        if(isalpha(stringToConvert[i]) || stringToConvert[i] == ' '){
            if(caseOfChoice == 5){
                inputString+=toupper(stringToConvert[i]);    
            }
            else{
                inputString+=tolower(stringToConvert[i]);
            }
        }
        
        if(i==stringToConvert.length()-1){
            inputString+=" ";
        }
    }

//splits the string into separate words and pushed those words into list  
    for(int i=0;i<inputString.length();i++){
        if(isalpha(inputString[i])){
            buffer+=inputString[i];
        }
        else if(inputString[i] = ' '){
            inputWordsList.push_back(buffer);
            buffer="";
        }
    }

   

    //takes care of transforming the input's case
    char separator='_';
    int i=0;
    switch (caseOfChoice)
    {
        case 1:
            i=1;
        case 4:
            for(;i<inputWordsList.size();i++){
                inputWordsList[i][0] = toupper(inputWordsList[i][0]);
            }
            break;
        case 3 :
            separator = '-';
        case 2 :
        case 5 :
            for(int i=0;i<inputWordsList.size()-1;i++){
                inputWordsList[i] += separator;
            }
            break;
        
        default:
            break;
    }
    
    for(auto a:inputWordsList){
        std::cout<<""<<a<<"";
    }
    std::cout<<std::endl;
}


int main(int argc, char const *argv[])
{

    //TODO: Read input properly
    // title and reading string from user
    std::cout<<"String Manipulation Project\n";

    //   //take input
    std::cout<<"Enter a sentence\n";
    std::string stringEntered;
    getline(std::cin, stringEntered);

    //selecting an option 
    //prints options
    for(int i=0;i<cases.size();i++){
        std::cout<<i+1<<' '<<cases[i]<<'\n';
    }
    std::cout<<"Enter your choice: ";
    int option ;
    std::cin>>option;

    // convert("Hello, World! Try this",5);

    // //calls the method and prints the string obtained
    // // for seeing all cases at once
    if(option == 6){
        int m=1;
        while(m<6){
            std::cout<<"Output string in "<<cases[m-1]<<" : ";
            convert(stringEntered,m);
            m++;
        }
    }    
    else{
        convert(stringEntered,option);
    }
    return 0;
}
