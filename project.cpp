#include <iostream>
#include <string>
using namespace std;

class Participant{
    public:
        string participantID,participantname,department,teamname;

        void displayParticipant(){
            cout<<"Participant ID: "<<participantID<<endl;
            cout<<"Participant Name: "<<participantname<<endl;
            cout<<"Department: "<<department<<endl;
            cout<<"Team Name: "<<teamname<<endl;
        }
};

class prompt{
    public:
        int promptID,participantId;
        string challengeName,promptText,promptCategory;// wait for 1 min OK BHAI

        void displayPrompt(){
            cout<<"Prompt ID: "<<promptID<<endl;
            cout<<"Prompt Category: "<<promptCategory<<endl;
            cout<<"Prompt Text: "<<promptText<<endl;
            cout<<"Challenge Name: "<<challengeName<<endl;
        }
};

class score{
    public:
        float creativeScore,revelanceScore,clarityScore,outputScore,audienceScore,promptScore,finalScore;

        void scoreCalculation(){
            float promptScore=(creativeScore+revelanceScore+clarityScore+outputScore)/4.0;
            float finalScore=(promptScore*0.8)+(audienceScore*0.2);
        }

        void displayScore(){
            cout<<"Creative Score:"<<creativeScore<<endl;
            cout<<"Relevance Score:"<<revelanceScore<<endl;
            cout<<"Output Score:"<<outputScore<<endl;
            cout<<"Clarity Score:"<<clarityScore<<endl;
            cout<<"Audience Score:"<<audienceScore<<endl;
            cout<<"Prompt Score:"<<promptScore<<endl;
            cout<<"Final Score:"<<finalScore<<endl;
        }

        string promptAnalyze()
        {
            if(finalScore >= 8){
                return "Master Prompt";
            }else if(finalScore >= 6){
                return "Strong Prompt";
            }else if(finalScore >= 4){
                return "Average Prompt";
            }else{
                return "Needs Improvement";
            }

        }
    };

class getDetails:public Participant,public prompt,public score
{
    public:
    void getParticipant(){
            cout<<"Enter the participant ID:";
            cin>>participantID;
            cin.ignore();
            cout<<"\nEnter the participant name:";
            getline(cin,participantname);
            cout<<"\nEnter the department:";
            getline(cin,department);
            cout<<"\nEnter the team name:";
            getline(cin,teamname);
            cout<<"Participant details has been successfully Updated"<<endl;
        }

        void getPrompt(){
            cout<<"Enter the Participant ID:";
            cin.ignore();
            cin>>participantID;
            cout<<"\nEnter the prompt category(story generation, coding, image ideas, problem-solving, summarization and creative writing.):";
            cin.ignore();
            getline(cin,promptCategory);
            cout<<"\nEnter the prompt ID:";
            cin>>promptID;
            cout<<"\nType your prompt here:";
            cin.ignore();
            getline(cin,promptText);
            cout<<"\nEnter the challenge name:";
            getline(cin,challengeName);
            cout<<"\nPrompt details added successfully!"<<endl;
        }

        void getScore(){
            cout<<"\nEnter the score for the prompt";
            cout<<"\nEnter the creative score:";
            cin>>creativeScore;
            cout<<"\nEnter the relevance score:";
            cin>>revelanceScore;
            cout<<"\nEnter the clarity score:";
            cin>>clarityScore;
            cout<<"\nEnter the output score:";
            cin>>outputScore;
            cout<<"\nEnter the audience score:";
            cin>>audienceScore;
            cout<<"\nPrompt scores added successfully!";
            cout<<"\nFinal score is being calculated..."<<endl;
        }
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
    Security s;

    cout<<"==================================="<<endl;
    cout<<"WELCOME TO PROMPT FOUNDRY💻⚡"<<endl;
    cout<<"\nDemonstrate your code...Conquer the leaderboard💹🔥"<<endl;
    cout<<"This is Purely for admin use only 😊"<<endl;
    cout<<"Enter the username:";
    cin>>username;
    cout<<"Enter the password 🔑:";
    cin>>password;
if(s.getaccess(username,password)){
    cout<<"Enter the maximum participant of this event:";
    cin>>maxparticipant;
    maxprompt=maxparticipant;

    Participant* part=new Participant[maxparticipant];
    prompt* prompts=new prompt[maxprompt];
    score* scores=new score[maxprompt];
    getDetails* details=new getDetails[maxparticipant];

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
            details[participantCount].getParticipant();
            participantCount++;
            break;
        }
        else{
            cout<<"You can't able to add more participant."<<endl<<endl;
            break;
        }
        case 2:
            if(promptCount<maxprompt){
                details[promptCount].getPrompt();
                promptCount++;
                break;
            }else{
                cout<<"You can't able to add more details"<<endl<<endl;
                break;
            }
        case 3:
            if(scoreCount<maxparticipant){
                details[scoreCount].getScore();
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
                    part[i].displayParticipant();
                }
                if(promptCount!=0){
                    prompts[i].displayPrompt();
                }
                if(scoreCount!=0){
                    scores[i].displayScore();
                    cout<<scores[i].promptAnalyze();
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
