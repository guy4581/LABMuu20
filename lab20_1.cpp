#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>

using namespace std;

char score2grade(int score){
    if(score >= 80) return 'A';
    if(score >= 70) return 'B';
    if(score >= 60) return 'C';
    if(score >= 50) return 'D';
    else return 'F';
}

string toUpperStr(string x){
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}

void importDataFromFile(string filename , vector<string> &names, vector<int> &scores , vector<char> &grade ){
    
    ifstream myfile (filename);
    string line;
    char format[] = "%[^:]:%d %d %d";
    char namel[100];
    int a,b,c;

    while(getline ( myfile , line)){
        const char * line2 = line.c_str();
        sscanf(line2,format,namel,&a,&b,&c);
        int sumscore = a + b + c;
        names.push_back(namel);
        scores.push_back(sumscore);
        grade.push_back(score2grade(sumscore));

    }
}

void getCommand(string &command , string &key){
    cout << "Please input your command: ";
    cin >> command;
    if(toUpperStr(command) == "NAME"||toUpperStr(command) == "GRADE"){
        cin.ignore();
        cin >> key;
    }
    
}

void searchName(vector<string> &names, vector<int> &scores , vector<char> &grade , string key){
    int count = 0;
for(unsigned int i = 0 ; i < names.size();i++ ){
    
    if( key == toUpperStr(names[i])){
         
        cout << "---------------------------------\n";
        cout << names[i] << "'s score = "<< scores[i] << endl;
        cout << names[i] << "'s grade = " << grade[i] << endl;
        cout << "---------------------------------\n";
        count ++;
    }else if(i == names.size()-1 && count == 0){
        cout << "---------------------------------\n";
        cout << "Cannot found."<< endl;
        cout << "---------------------------------\n";
    }
    }
}
void searchGrade(vector<string> &names, vector<int> &scores, vector<char> &grades, string key){
    int count = 0;
    cout << "---------------------------------\n";
for(unsigned int i = 0 ; i < grades.size();i++ ){
    
    if( key[0] == grades[i]){
         
        
        cout << names[i] << " ("<< scores[i] << ")" << endl;
        
        count ++;
    }else if(i == names.size()-1 && count == 0){
        
        cout << "Cannot found."<< endl;
        
    }
    }
    cout << "---------------------------------\n";
}



int main(){
    string filename = "name_score.txt";
    vector<string> names;
    vector<int> scores;
    vector<char> grades; 
    importDataFromFile(filename, names, scores, grades);
    
    do{
        string command, key;
        getCommand(command,key);
        command = toUpperStr(command);
        key = toUpperStr(key);
        if(command == "EXIT") break;
        else if(command == "GRADE") searchGrade(names, scores, grades, key);
        else if(command == "NAME") searchName(names, scores, grades, key);
        else{
            cout << "---------------------------------\n";
            cout << "Invalid command.\n";
            cout << "---------------------------------\n";
        }
    }while(true);
    
    return 0;
}
