#include<iostream>
#include<fstream>
#include<vector>
#include<cstdlib>
#include <string>
#include <ctime>

using namespace std;

struct question{
   string question_text;
   string options[4];
   int answer=0;
};


int main(){

   srand ((unsigned int)time(0) );
   ifstream input;
   input.open("questions.txt");
   if(!input)
   {
       cout << "File not open";
   }
   string line,word;
   vector<question>ques;
   while(input){
       question q;
       getline(input,line);
       //this is where we are struggled
       if(line==""){
          break;
       }
       q.question_text=line;
       for(int i=0;i<4;i++){
           getline(input,line);
           q.options[i]=line;
       }
       getline(input,line);
       q.answer=(line[0]-'0');
       ques.push_back(q);
   }

   input.close();

   for(int i=ques.size()-1;i>0;i--){
       int j=rand()%(i+1);
       question temp=ques[j];
       ques[j]=ques[i];
       ques[i]=temp;
   }

   cout<<"\t....Let The Quiz Begin...."<<endl;
   cout<<"This quiz contains "<<ques.size()<<" questions"<<endl;
   int score=0,ans;
   for(int i=0;i<ques.size();i++){
       cout<<"\nquestion "<<(i+1)<<endl;
       cout<<ques[i].question_text<<endl;
       cout<<endl;
       for(int j=0;j<4;j++){
           cout<<(j+1)<<"."<<ques[i].options[j]<<endl;
       }
       cout<<endl;
       cout<<"Enter your answer (1-4) :";
       cin>>ans;
       if(ques[i].answer==ans){
           score++;
       }
   }
   cout<<"You scored ("<<score<<" Out of "<<ques.size()<<")"<<endl;
}
