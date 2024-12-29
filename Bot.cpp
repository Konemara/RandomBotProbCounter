#include<bits/stdc++.h>
using namespace std;

int GENERATE(int a, int b){
    return a + (rand() % b);
}
int N;
vector<double> prob;
vector<vector<bool>> MADESHOT;
vector<double> trueprob;
int BOT(int BOT){
    int am = 0;
    for(int i = 0; i < N; ++i){
        if(GENERATE(1, 100) <= prob[i]){
            am++;
            MADESHOT[BOT].push_back(true);
            trueprob[i]++;
        }
        else{
            MADESHOT[BOT].push_back(false);
        }
    }
    return am;
}
int main(){
    srand((unsigned) time(NULL));
    cout << "Input the Number of tasks: ";
    cout << flush;
    cin >> N;
    cout << "Input the probabilities of each task (0-100%): ";
    cout << flush;
    prob.resize(N);
    trueprob.resize(N);
    for(int i = 0; i < N; ++i){
        cin >> prob[i];
        trueprob[i]= 0;
    }
    cout << "Finally input the number of test bots: ";
    cout << flush;
    double BOTAMOUNT;
    cin >> BOTAMOUNT;
    MADESHOT.resize(BOTAMOUNT);
     double AM[N+1];
    for(int i = 0; i < N+1; ++i){
        AM[i]=0;
    }
    for(int i = 0; i < BOTAMOUNT; ++i){
        AM[BOT(i)]++;
    }
    for(int i = 0; i < N+1; ++i){
        cout << "Prob. of " << i << " - " << (AM[i]/BOTAMOUNT)*100<< "%\n";
    }
    cout << "For more accurate stats, see file PROB.txt.\n";
    ofstream cout ("PROB.txt");
    cout << "Probabilities:\n";
    int max = 0;
    for(int i = 0; i < N+1; ++i){
        cout << i << " - " << (AM[i]/BOTAMOUNT)*100<< "% ("<< AM[i] << " BOTS).\n";
        if((AM[i]/BOTAMOUNT)*7 > max){
            max = (AM[i]/BOTAMOUNT)*7;
        }
    }
    
    cout << "\n\nPlot Graph:\n";
    for(int i = max+1; i >= 0; --i){
        for(int j = 0; j < N+1; ++j){
            if((AM[j]/BOTAMOUNT)*7 >= i){
                cout << "##";
            }
            else{
                cout << "  ";
            }
        }
        cout << "\n";
    }
    long double diff = 0;
    cout << "\n\nHow well did the bots perform on certain shots:\n";
    for(int i = 0; i < N; ++i){
        cout << "SHOT #"<<i+1 << " - " << (trueprob[i]/BOTAMOUNT)*100<< "% (" <<  trueprob[i] << "  BOTS)   EXPECTED PERCENTAGE - " << prob[i] << "% (" << (floor)(prob[i]/100 * BOTAMOUNT) << " BOTS)\n";
        if(abs((trueprob[i]/BOTAMOUNT)*100 - prob[i]) > diff){
            diff = abs((trueprob[i]/BOTAMOUNT)*100 - prob[i]);
        }
    }
    cout << "Answers can be unaccurate from expected values for up to " << diff << "% (" << (floor)(diff/100 * BOTAMOUNT) << " BOTS)\n";
    cout << "\n\nSuccess of shots:\n";
    for(int i = 0; i < BOTAMOUNT; ++i){
        cout << "BOT #" << i+1 << ": ";
        int sum = 0;
        for(int j = 0; j < N; ++j){
            cout << MADESHOT[i][j] << " ";
            sum +=MADESHOT[i][j];
        }
        cout << "- " << sum << " successful shots.\n";
    }
}
