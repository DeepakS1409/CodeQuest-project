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
void display(int maxparticipant){

}
int main(){
    string username,password;
    int maxparticipant,choice,participantCount=0,promptCount=0,scoreCount=0,maxprompt;
    maxprompt=maxparticipant;
    Security s;

    cout<<"==================================="<<endl;
    cout<<"WELCOME TO PROMPT FOUNDRY💻⚡"<<endl;
    cout<<"\nDemonstrate your code...Conquer the leaderboard💹🔥"<<endl;
    cout<<"This is Purly for admin use only"<<endl;
    cout<<"Enter the username:";
    cin>>username;
    cout<<"Enter the password:";
    cin>>password;
if(s.getaccess(username,password)){
    cout<<"Enter the maximum participant of this event:";
    cin>>maxparticipant;

    Participant* part=new Participant[maxparticipant];
    prompt* prompts=new prompt[maxprompt];
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
        if(participantCount<maxparticipant){
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
            participantCount++;
            break;
        }
        else{
            cout<<"You can't able to add more participant."<<endl<<endl;
            break;
        }
        case 2:
            if(promptCount<maxprompt){
            int id;
            cout<<"Enter the Participant ID:";
            cin.ignore();
            getline(cin,prompts[promptCount].promptCategory);
            cout<<"\nEnter the prompt category(story generation, coding, image ideas, problem-solving, summarization and creative writing.):";
            getline(cin,prompts[promptCount].promptCategory);
            cout<<"\nEnter the prompt ID:";
            cin>>prompts[promptCount].promptID;
            cout<<"\nType your prompt here:";
            cin.ignore();
            getline(cin,prompts[promptCount].promptText);
            cout<<"\nEnter the challenge name:";
            getline(cin,prompts[promptCount].challengeName);
            cout<<"\nPrompt details added successfully!"<<endl;
            promptCount++;
            break;
            }else{
                cout<<"You can't able to add more details"<<endl<<endl;
                break;
            }
        case 3:
            if(scoreCount<maxparticipant){
            cout<<"\nEnter the score for the prompt:";
            cout<<"\nEnter the creative score:";
            cin>>scores[scoreCount].creativeScore;
            cout<<"\nEnter the relevance score:";
            cin>>scores[scoreCount].revelanceScore;
            cout<<"\nEnter the clarity score:";
            cin>>scores[scoreCount].clarityScore;
            cout<<"\nEnter the output score:";
            cin>>scores[scoreCount].outputScore;
            cout<<"\nEnter the audience score:";
            cin>>scores[scoreCount].audienceScore;
            cout<<"\nPrompt scores added successfully!";
            cout<<"\nFinal score is being calculated..."<<endl;
            scoreCount++;
            break;
            }else{
                cout<<"You can't able to add more details."<<endl<<endl;
                break;
            }
        case 4:
            cout<<"===========Details==========="<<endl;
            for(int i=0;i<maxparticipant;i++){
                if(participantCount!=0){
                    cout<<"Participant ID:"<<part[i].participantID<<endl;
                    cout<<"Participant Name:"<<part[i].participantname<<endl;
                    cout<<"Department:"<<part[i].department<<endl;
                    cout<<"Team Name:"<<part[i].teamname<<endl;
                }
                if(promptCount!=0){
                    cout<<"Prompt Id:"<<prompts[i].promptID<<endl;
                    cout<<"Prompt Category:"<<prompts[i].promptCategory<<endl;
                    cout<<"Prompt:"<<prompts[i].promptText<<endl;
                    cout<<"Challenge Name:"<<prompts[i].challengeName<<endl;
                }
                if(scoreCount!=0){
                    cout<<"Creative Score:"<<scores[i].creativeScore<<endl;
                    cout<<"Revelance Score:"<<scores[i].revelanceScore<<endl;
                    cout<<"Clarity Score:"<<scores[i].clarityScore<<endl;
                    cout<<"Output Score:"<<scores[i].outputScore<<endl;
                    cout<<"Prompt Score:"<<scores[i].promptScore<<endl;
                    cout<<"Audience Score:"<<scores[i].audienceScore<<endl;
                }
            }
            break;
        case 5:
            cout<<"Exiting the program."<<endl;
            break;
        default:
            cout<<"Invalid choice. Please try again."<<endl;

    }
    }while(choice!=5);
}else{
    cout<<"Invalid Username or password";
}
    return 0;
}
