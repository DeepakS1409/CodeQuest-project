#include <iostream>
#include <string>
using namespace std;

class Participant{
    protected:
        string participantID,participantname,department,teamname;
        int roundsParticipated;

};

class prompt{
    protected:
        string promptID,participantId;
        string challengeName,promptText,promptCategory;
};

class score{
    protected:
        float creativeScore=0,relevanceScore=0,clarityScore=0,outputScore=0,audienceScore=0,promptScore=0,finalScore=0;
};

class Challenge
{
protected:
    int challengeID;
    string challengeName;
    string challengeCategory;

public:

    void createChallenge()
    {
        cout << "\nEnter Challenge ID: ";
        cin >> challengeID;

        cin.ignore();

        cout << "Enter Challenge Name: ";
        getline(cin, challengeName);

        cout << "Enter Challenge Category: ";
        getline(cin, challengeCategory);

        cout << "\nChallenge created successfully!\n";
    }

    void displayChallenge()
    {
        cout << "\n---------- Challenge Details ----------\n";
        cout << "Challenge ID       : " << challengeID << endl;
        cout << "Challenge Name     : " << challengeName << endl;
        cout << "Challenge Category : " << challengeCategory << endl;
    }
};

class getDetails : public Participant, public prompt, public score
{
public:
    float calculatedFinalScore=0;
    string partiId,promId;
    bool hasScore = false;

    bool checkDuplicate(string id[],int n,string newId){
        for(int i=0;i<n;i++){
            if(id[i]==newId){
                return true;
            }
        }
        return false;
    }

    void getParticipant(string id[],int n){
        string newId;
        do{
            cout<<"Enter the participant ID:";
            cin>>newId;
            if(checkDuplicate(id,n,newId)){
                cout<<"Participant ID already Exist!... Enter another ID"<<endl;
            }
        }while(checkDuplicate(id,n,newId));
        participantID=newId;
        partiId=newId;
        cin.ignore();

        cout<<"\nEnter the participant name:";
        getline(cin,participantname);

        cout<<"\nEnter the department:";
        getline(cin,department);

        cout<<"\nEnter the team name:";
        getline(cin,teamname);

        do
        {
            cout << "Enter the number of rounds participated: ";
            cin >> roundsParticipated;
            if(roundsParticipated < 0)
            {
                cout << "Rounds cannot be negative.\n";
            }
        }while(roundsParticipated < 0);

        cout<<"Participant details has been successfully Updated"<<endl;
    }

    void searchParticipant(string id[], int n, getDetails details[])
    {
        string searchID;
        cout << "\nEnter Participant ID to search: ";
        cin >> searchID;
        for(int i = 0; i < n; i++)
        {
            if(id[i] == searchID)
            {
                details[i].displayParticipant();
                return;
            }
        }
        cout << "Participant not found!\n";
    }

    void getPrompt(string promptIDArray[], int n, int participantPosition)
    {
        string newPromptID;
        do
        {
            cout << "Enter Prompt ID: ";
            cin >> newPromptID;
            if(checkDuplicate(promptIDArray, n, newPromptID))
            {
                cout << "Prompt ID already exists! Enter another ID.\n";
            }
        }while(checkDuplicate(promptIDArray, n, newPromptID));
    promptID = newPromptID;
    promId = newPromptID;
    cout << "\nEnter Participant ID: ";
    cin >> participantId;
    cout << "\nEnter the prompt category: ";
    cin.ignore();
    getline(cin, promptCategory);
    cout << "\nType your prompt here: ";
    getline(cin, promptText);
    cout << "\nEnter the challenge name: ";
    getline(cin, challengeName);
    cout << "\nPrompt details added successfully!\n";
}

    void searchPrompt(string id[], int n, getDetails details[])
    {
        string searchID;
        cout << "\nEnter Prompt ID to search: ";
        cin >> searchID;
        for(int i = 0; i < n; i++)
        {
            if(id[i] == searchID)
            {
                details[i].displayPrompt();
                return;
            }
        }
        cout << "Prompt not found!\n";
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
        cout << "Rounds Participated: " << roundsParticipated << endl;
    }


    void displayPrompt(){
        cout <<"Participant ID: " << participantId << endl;
        cout<<"Prompt ID: "<<promptID<<endl;
        cout<<"Prompt Category: "<<promptCategory<<endl;
        cout<<"Prompt Text: "<<promptText<<endl;
        cout<<"Challenge Name: "<<challengeName<<endl;
    }


    void displayScore(){
        cout<<"Creative Score: "<<creativeScore<<endl;
        cout<<"Relevance Score: "<<relevanceScore<<endl;
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

    float getFinalScore()
    {
        return calculatedFinalScore;
    }

    float getCreativeScore()
    {
        return creativeScore;
    }

    float getAudienceScore()
    {
        return audienceScore;
    }

    string getCategory()
    {
        return promptCategory;
    }};

void compareParticipants(string id[], int n, getDetails details[])
{
    string id1, id2;
    int pos1 = -1, pos2 = -1;
    cout << "\nEnter first Participant ID: ";
    cin >> id1;
    cout << "Enter second Participant ID: ";
    cin >> id2;
    for(int i = 0; i < n; i++)
    {
        if(id[i] == id1)
            pos1 = i;
        if(id[i] == id2)
            pos2 = i;
    }
    if(pos1 == -1 || pos2 == -1)
    {
        cout << "One or both participants not found!\n";
        return;
    }

    cout << "\n========== COMPARISON ==========\n";
    cout << id1 << " Score: "<< details[pos1].calculatedFinalScore << endl;
    cout << id2 << " Score: "<< details[pos2].calculatedFinalScore << endl;
    if(details[pos1].calculatedFinalScore>details[pos2].calculatedFinalScore)
    {
        cout << "Winner: " << id1 << endl;
    }else if(details[pos2].calculatedFinalScore > details[pos1].calculatedFinalScore)
    {
        cout << "Winner: " << id2 << endl;
    }else
    {
        cout << "Both participants have the same score!\n";
    }
}

void displayLeaderboard(string id[], int n, getDetails details[])
{
    string tempID[n];
    float tempScore[n];
    for(int i = 0; i < n; i++)
    {
        tempID[i] = id[i];
        tempScore[i] = details[i].calculatedFinalScore;
    }
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(tempScore[j] < tempScore[j + 1])
            {
                float temp = tempScore[j];
                tempScore[j] = tempScore[j + 1];
                tempScore[j + 1] = temp;

                string tempIDValue = tempID[j];
                tempID[j] = tempID[j + 1];
                tempID[j + 1] = tempIDValue;
            }
        }
    }
    cout << "\n========== LEADERBOARD ==========\n";
    cout << "Rank\tParticipant ID\tFinal Score\n";
    for(int i = 0; i < n; i++)
    {
        cout << i + 1 << "\t"<< tempID[i] << "\t\t"<< tempScore[i] << endl;
    }
}

void displayWinners(string id[], int n, getDetails details[])
{
    if(n == 0)
    {
        cout << "No participants available.\n";
        return;
    }
    int bestPrompt = 0;
    int mostCreative = 0;
    int audienceFavorite = 0;
    int bestProblem = -1;
    int champion = 0;
    for(int i = 0; i < n; i++)
    {
        if(details[i].getFinalScore() >details[bestPrompt].getFinalScore())
        {
            bestPrompt = i;
        }
        if(details[i].getCreativeScore()>details[mostCreative].getCreativeScore())
        {
            mostCreative = i;
        }
        if(details[i].getAudienceScore()>details[audienceFavorite].getAudienceScore())
        {
            audienceFavorite = i;
        }
        if(details[i].getFinalScore() >details[champion].getFinalScore())
        {
            champion = i;
        }
        if(details[i].getCategory() == "Problem Solving")
        {
            if(bestProblem == -1 ||details[i].getFinalScore() >details[bestProblem].getFinalScore())
            {
                bestProblem = i;
            }
        }
    }
    cout << "\n========== WINNERS ==========\n";
    cout << "\nBest Prompt: "<< id[bestPrompt] << endl;
    cout << "Most Creative Prompt: "<< id[mostCreative] << endl;
    cout << "Audience Favorite: "<< id[audienceFavorite] << endl;
    if(bestProblem != -1)
    {
        cout << "Best Problem-Solving Prompt: "<< id[bestProblem] << endl;
    }
    else
    {
        cout << "Best Problem-Solving Prompt: No entry\n";
    }

    cout << "Prompt Battle Champion: "<< id[champion] << endl;
}

void finalReport(string id[], int n, getDetails details[])
{
    cout << "\n========================================\n";
    cout << "       FINAL PROMPT BATTLE REPORT          ";
    if(n == 0)
    {
        cout << "No participants registered.\n";
        return;
    }
    for(int i = 0; i < n; i++)
    {
        cout << "\n---------- Participant " << i + 1 << " ----------\n";
        details[i].displayParticipant();
        cout << "\nPrompt Details:\n";
        details[i].displayPrompt();
        cout << "\nScore Details:\n";
        details[i].displayScore();
        cout << "Classification: "<< details[i].promptAnalyze() << endl;
    }
    cout << "          END OF FINAL REPORT             ";
    cout << "\n========================================\n";
}

int findParticipant(string id[], int n, string searchID)
{
    for(int i = 0; i < n; i++)
    {
        if(id[i] == searchID)
        {
            return i;
        }
    }

    return -1;
}

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
    cout << "Enter maximum number of participants: ";
    cin >> maxparticipant;

    cout << "Enter maximum number of prompts: ";
    cin >> maxprompt;

    int maxChallenge;
    cout << "Enter maximum number of challenges: ";
    cin >> maxChallenge;

    int challengeCount = 0;

    string id[maxparticipant];
    string prom[maxprompt];
    getDetails* details=new getDetails[maxparticipant];
    Challenge* challenges = new Challenge[maxChallenge];

    do{
        cout<<"==============Menu================="<<endl;
        cout << "1. Register Participant\n";
        cout << "2. Create Challenge\n";
        cout << "3. Prompt Details\n";
        cout << "4. Enter the scores\n";
        cout << "5. Display all prompts\n";
        cout << "6. Display all challenges\n";
        cout << "7. Search Participant\n";
        cout << "8. Search Prompt\n"; 
        cout << "9. Compare Participants\n";
        cout << "10. Display Leaderboard\n";
        cout << "11. Display Winners\n";
        cout << "12. Final Prompt Battle Report\n";
        cout << "13. Exit\n";

        cout<<"===================================\n";
        cout<<"Enter your choice:";
        cin>>choice;
        switch(choice){

        case 1:
            if(participantCount < maxparticipant)
            {
                details[participantCount].getParticipant(id, participantCount);
                //id[participantCount] = details[participantCount].partiId;
                id[participantCount] = details[participantCount].partiId;
                participantCount++;
            }else{
                cout << "You can't add more participants.\n";
            }
            break;
        case 2:
            if(challengeCount < maxChallenge)
            {
                challenges[challengeCount].createChallenge();
                challengeCount++;
            }else
            {
                cout << "You cannot add more challenges.\n";
            }
            break;
        case 3:
        {
            if(participantCount == 0)
            {
                cout << "Please register a participant first.\n";
                break;
            }
            if(promptCount >= maxprompt)
            {
                cout << "You can't add more prompts.\n";
                break;
            }
            string participantSearchID;
            cout << "Enter Participant ID for this prompt: ";
            cin >> participantSearchID;
            int position = findParticipant(id, participantCount, participantSearchID);
            if(position == -1)
            {
                cout << "Participant not found!\n";
                break;
            }
            details[position].getPrompt(prom, promptCount,position);
            prom[promptCount] = details[position].promId;
            promptCount++;
            break;
        }
        case 4:
        {
            if(promptCount == 0)
            {
                cout << "Please add a prompt first.\n";
                break;
            }
            string participantSearchID;
            cout << "Enter Participant ID whose prompt is being scored: ";
            cin >> participantSearchID;
            int position = findParticipant(id, participantCount, participantSearchID);
            if(position == -1)
            {
                cout << "Participant not found!\n";
                break;
            }
            details[position].getScore();
            scoreCount++;
            break;
        }
        case 5:
            cout << "=========== Details ===========\n";
            for(int i = 0; i < participantCount; i++)
            {
                details[i].displayParticipant();
                if(i < promptCount)
                {
                    details[i].displayPrompt();
                }
                if(i < scoreCount)
                {
                    details[i].displayScore();
                    cout << details[i].promptAnalyze() << endl;
                }
            }
            break;
        case 6:
            cout << "\n========== ALL CHALLENGES ==========\n";
            if(challengeCount == 0)
            {
                cout << "No challenges created yet.\n";
            }else
            {
                for(int i = 0; i < challengeCount; i++)
                {
                    challenges[i].displayChallenge();
                }
            }
            break;
        case 7:
            if(participantCount == 0)
            {
                cout << "No participants registered.\n";
            }else
            {
                details[0].searchParticipant(id, participantCount, details);
            }
            break;
        case 8:
            if(promptCount == 0)
            {
                cout << "No prompts added.\n";
            }else
            {
                details[0].searchPrompt(prom, promptCount, details);
            }
            break;
        case 9:
            if(participantCount < 2)
            {
                cout << "At least two participants are required.\n";
            }else if (scoreCount < 2)
            {
                cout << "At least two participants must have scores.\n";
            }
            else
            {
                compareParticipants(id, participantCount, details);
            }
            break;
        case 10:
            if(scoreCount == 0)
            {
                cout << "No scores available yet.\n";
            }else
            {
                displayLeaderboard(id, participantCount, details);
            }
            break;
        case 11:
            if(scoreCount == 0)
            {
                cout << "No scores available yet.\n";
            }else
            {
                displayWinners(id, participantCount, details);
            }
            break;
        case 12:
            finalReport(id, participantCount, details);
            break;
        case 13:
            cout<<"Exiting the program."<<endl;
            break;
        default:
            cout<<"Invalid choice. Please try again."<<endl;

    }
    }while(choice!=13);
    delete[] details;
    delete[] challenges;
}else{
    cout<<"Invalid Username or password";
}
    return 0;
}
