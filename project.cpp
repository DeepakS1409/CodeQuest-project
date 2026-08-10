#include <iostream>
#include <string>
using namespace std;

class Participant{
    public:
        string participantID,participantname,department,teamname;
};

class prompt{
    public:
        int promptID,participantID;
        string challengeName,promptText,promptCategory;
};

class score{
    public:
        float creativeScore,revelanceScore,clarityScore,outputScore,audienceScore;
        float promptScore=(creativeScore+revelanceScore+clarityScore+outputScore)/4.0;


        float finalScore=(promptScore)*0.8+audienceScore*0.2;
    };

class Security
{
    string admin[3]={"Deepak","Vikashini","Dhanush"};
    string password[3]={"Deepak@123","Vikashini@123","Dhanush@123"};
    public:
    int index=0;
        bool getaccess(string name,string pass){
            for(int i=0;i<=2;i++){
                if(name==admin[i]){
                    index=i;
                    break;
                }
            }
                return password[index]==pass;
        }
};
// class display{
//     void displayPrompts(Participant* Participant,int participantCount){
//             cout<<"\nDisplaying all prompts:\n";
//             for(int i=0;i<participantCount;i++){
//                 cout<<"Prompt ID:          "<<Participant[i].promptID<<endl;
//                 cout<<"Prompt Category:    "<<Participant[i].promptCategory<<endl;
//                 cout<<"Prompt Text:        "<<Participant[i].promptText<<endl;
//                 cout<<"Prompt final Score: "<<Participant[i].score<<endl;}
// }
int main(){
    cout<<"==================================="<<endl;
    cout<<"WELCOME TO PROMPT FOUNDRY💻⚡"<<endl;
    cout<<"\nDemonstrate your code...Conquer the leaderboard💹🔥"<<endl;
    cout<<"This is purly for admin use only"<<endl;
    string username,password;
    cout<<"Enter the username:";
    cin>>username;
    cout<<"Enter the password:";
    cin>>password;
    Security s;
    if(s.getaccess(username,password)){
    int maxparticipant,choice,participantCount=0;
    cout<<"Enter the maximum participant of this event:";
    cin>>maxparticipant;
    int maxprompt=maxparticipant;
    Participant* part=new Participant[maxparticipant];
    prompt* prompts=new prompt[maxprompt];
   // display d;

    score* scores=new score[maxprompt];
    do{
        cout<<"==============Menu================="<<endl;
        cout<<"1.Register Participant\n";
        cout<<"2.Prompt Details\n";
        cout<<"3.Enter the scores\n";
        cout<<"4.Display all prompts\n";
        cout<<"5.Exit\n";
        cout<<"===================================\n";
        cout<<"Enter your choice:";
        cin>>choice;
        switch(choice){

        case 1:
            cout<<"Enter the participant ID:";
            cin>>part[participantCount].participantID;
            cin.ignore();
            cout<<"\nEnter the participant name:";
            getline(cin,part[participantCount].participantname);
            cout<<"\nEnter the department:";
            getline(cin,part[participantCount].department);
            cout<<"\nEnter the team name:";
            getline(cin,part[participantCount].teamname);
            cout<<"Participant details has been successfully Updated"<<endl;
            break;
        case 2:
            cin.ignore();
            cout<<"\nEnter the prompt category(story generation, coding, image ideas, problem-solving, summarization and creative writing.):";
            getline(cin,prompts[participantCount].promptCategory);
            cout<<"\nEnter the prompt ID:";
            cin>>prompts[participantCount].promptID;
            cout<<"\nType your prompt here:";
            cin.ignore();
            getline(cin,prompts[participantCount].promptText);
            cout<<"\nEnter the challenge name:";
            getline(cin,prompts[participantCount].challengeName);
            cout<<"\nPrompt details added successfully!"<<endl;
            break;
        case 3:
            cout<<"\nEnter the score for the prompt:";
            cout<<"\nEnter the creative score:";
            cin>>scores[participantCount].creativeScore;
            cout<<"\nEnter the relevance score:";
            cin>>scores[participantCount].revelanceScore;
            cout<<"\nEnter the clarity score:";
            cin>>scores[participantCount].clarityScore;
            cout<<"\nEnter the output score:";
            cin>>scores[participantCount].outputScore;
            cout<<"\nEnter the audience score:";
            cin>>scores[participantCount].audienceScore;
            cout<<"\nPrompt scores added successfully!";
            cout<<"\nFinal score is being calculated...";
            break;
        case 4:
         //   d.displayPrompts(Participant, participantCount);
            break;
        case 5:
            cout<<"Exiting the program."<<endl;
            break;
        default:
            cout<<"Invalid choice. Please try again."<<endl;

    }
    }while(choice!=5 && participantCount<maxparticipant);
}else{
    cout<<"Invalid Username or password";
}
    return 0;
}
