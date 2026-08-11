#include <iostream>
#include <string>
using namespace std; 

class Participant{
    protected:
        string participantID,participantname,department,teamname;

};

class prompt{
    protected:
        int promptID,participantId;
        string challengeName,promptText,promptCategory;
};

class score{
    protected:
        float creativeScore,revelanceScore,clarityScore,outputScore,audienceScore,promptScore,finalScore;

    };

class getDetails : public Participant, public prompt, public score
{
public:
    float calculatedFinalScore;
    string partiId;

    void getParticipant(){
        cout<<"Enter the participant ID:";
        cin>>participantID;
        partiId=participantID;
        cin.ignore();

        cout<<"\nEnter the participant name:";
        getline(cin,participantname);

        cout<<"\nEnter the department:";
        getline(cin,department);

        cout<<"\nEnter the team name:";
        getline(cin,teamname);

        cout << "\nEnter the number of rounds participated:";
        cin>>roundsParticipated;

        cout<<"Participant details has been successfully Updated"<<endl;
    }


    void getPrompt(){
        cout<<"Enter the Participant ID:";
        cin>>participantId;

        cout<<"\nEnter the prompt category:";
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


    void getScore()
    {
        cout << "\nEnter the score for the prompt\n";
        do
        {
            cout << "\nEnter the creative score (0-10): ";
            cin >> creativeScore;
            if(creativeScore < 0 || creativeScore > 10){
                cout << "Invalid score! Enter between 0 and 10.\n";
            }
        }while(creativeScore < 0 || creativeScore > 10);

        do
        {
            cout << "\nEnter the relevance score (0-10): ";
            cin >> relevanceScore;
            if(relevanceScore < 0 || relevanceScore > 10)
            {
                cout << "Invalid score! Enter between 0 and 10.\n";
            }
        }while(relevanceScore < 0 || relevanceScore > 10);

        do
        {
            cout << "\nEnter the clarity score (0-10): ";
            cin >> clarityScore;
            if(clarityScore < 0 || clarityScore > 10)
            {    
                cout << "Invalid score! Enter between 0 and 10.\n";
            }
        }while(clarityScore < 0 || clarityScore > 10);

        do
        {
            cout << "\nEnter the output score (0-10): ";
            cin >> outputScore;
            if(outputScore < 0 || outputScore > 10)
            {
                cout << "Invalid score! Enter between 0 and 10.\n";
            }
        }while(outputScore < 0 || outputScore > 10);

        do
        {
            cout << "\nEnter the audience score (0-10): ";
            cin >> audienceScore;
            if(audienceScore < 0 || audienceScore > 10)
            {
                cout << "Invalid score! Enter between 0 and 10.\n";
            }
        }while(audienceScore < 0 || audienceScore > 10);
        cout << "\nPrompt scores added successfully!\n";
    }
    void scoreCalculation()
    {
        promptScore = (creativeScore + relevanceScore + clarityScore + outputScore) / 4.0;
        finalScore = (promptScore * 0.8) + (audienceScore * 0.2);
        calculatedFinalScore = finalScore;
        cout << "Prompt Score: " << promptScore << endl;
        cout << "Final Score: " << finalScore << endl;
    }
    void displayParticipant(){
        cout<<"Participant ID: "<<participantID<<endl;
        cout<<"Participant Name: "<<participantname<<endl;
        cout<<"Department: "<<department<<endl;
        cout<<"Team Name: "<<teamname<<endl;
    }


    void displayPrompt(){
        cout<<"Prompt ID: "<<promptID<<endl;
        cout<<"Prompt Category: "<<promptCategory<<endl;
        cout<<"Prompt Text: "<<promptText<<endl;
        cout<<"Challenge Name: "<<challengeName<<endl;
    }


    void displayScore(){
        cout<<"Creative Score: "<<creativeScore<<endl;
        cout<<"Relevance Score: "<<revelanceScore<<endl;
        cout<<"Output Score: "<<outputScore<<endl;
        cout<<"Clarity Score: "<<clarityScore<<endl;
        cout<<"Audience Score: "<<audienceScore<<endl;
        scoreCalculation();
        // cout<<"Prompt Score: "<<promptScore<<endl;
        // cout<<"Final Score: "<<finalScore<<endl;
    }



    string promptAnalyze()
    {
        if(calculatedFinalScore  >= 8){
            return "Master Prompt 💯 You gave a Top-Tier prompt 🔥";
        }
        else if(calculatedFinalScore  >= 6){
            return "Strong Prompt 👍 Well executed 🫡";
        }
        else if(calculatedFinalScore  >= 4){
            return "Average Prompt 🙃 Fairly standard 🤓";
        }
        else{
            return "Needs Improvement 🫥 Back to the Drawing Board 📝";
        }
    }
};

class Security
{
    string admin[3]={"Deepak","Vikashini","Dhanush"};
    string password[3]={"Deepak@123","Vikashini@123","Dhanush@123"};
    public:
        bool getaccess(string name,string pass){
            for(int i=0;i<3;i++){
                if(name==admin[i] && pass==password[i]){
                    return true;
                }
        }
        return false;
}
};

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

    string id[maxparticipant];
    string prom[maxprompt];

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
            if(participantCount < maxparticipant)
            {
                details[participantCount].getParticipant(id, participantCount);
                id[participantCount] = details[participantCount].partiId;
                participantCount++;
            }else{
                cout << "You can't add more participants.\n";
            }
            break;
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
                    details[i].displayParticipant();
                }
                if(promptCount!=0){
                    details[i].displayPrompt();
                }
                if(scoreCount!=0){
                    details[i].displayScore();
                    cout<<details[i].promptAnalyze()<<endl;
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
