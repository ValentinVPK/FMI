
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <deque>
using namespace std;

int main()
{
    int N;
    cin >> N;

    //p stores new elements
    vector<int> contestants;
    vector<int> daysOfSurvival;
    for (int i = 0; i < N; i++)
    {
        int currContestant;
        cin >> currContestant;

        contestants.push_back(currContestant);
        daysOfSurvival.push_back(0);
    }
        

    int minContestant = contestants[0];//stores current  minimum element
    int maxDays = daysOfSurvival[0];//stores max no. of days taken
    stack<int> st;

    st.push(0);//store index of the first element

    for (int i = 1; i < N; i++)
    {
        //if this is greateer thean the previous element
        // than this will die on day 1.
        if (contestants[i] > contestants[i - 1])
        {
            daysOfSurvival[i] = 1;
        }
            

        //if curent element is less than global min element
        //update global min element
        if (minContestant > contestants[i]) 
        {
            minContestant = contestants[i];
        }

        //checking span of a plant
        while (!st.empty() && contestants[st.top()] >= contestants[i]) 
        {
            //if it is greater than the min than it will die someday
            //calculating days of survival
            if (contestants[i] > minContestant) 
            {
                //current element is less than or equal to last element in stack
                //and also greater than the min
                //hence it will survive one more day than the current element in stack
                //if it further finds another element in stack which has same behaviour then
                //no. of days of its survival increase one more day
                if (daysOfSurvival[i] < daysOfSurvival[st.top()] + 1)
                {
                    daysOfSurvival[i] = daysOfSurvival[st.top()] + 1;
                }
            }
            st.pop();
        }

        //update global max_number_of_days a plant can survive
        maxDays = maxDays > daysOfSurvival[i] ? maxDays : daysOfSurvival[i];
        //push this index in stack for other elements to check their survival time
        st.push(i);
    }

    cout << maxDays << endl;
}


