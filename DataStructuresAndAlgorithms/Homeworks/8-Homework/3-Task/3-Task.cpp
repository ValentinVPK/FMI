
#include <iostream>
#include <queue>
#include <cmath>
#include <vector>

using namespace std;

struct Exam
{
    int startingTime;
    int duration;

    Exam(int startingTime, int duration)
    {
        this->startingTime = startingTime;
        this->duration = duration;
    }
};

struct CompareStartingTime
{
    bool operator()(const Exam& a, const Exam& b)
    {
        return a.startingTime > b.startingTime;
    }
};

struct CompareDuration
{
    bool operator()(const Exam& a, const Exam& b)
    {
        return a.duration > b.duration;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    priority_queue<Exam, vector<Exam>, CompareStartingTime> minStartingTimeHeap;

    int N;
    cin >> N;

    int time, duration;
    for (int i = 0; i < N; i++)
    {
        cin >> time >> duration;

        Exam currTask(time, duration);
        minStartingTimeHeap.push(currTask);
    }

    vector<long> allTimes;

    long passedTime = minStartingTimeHeap.top().startingTime;

    priority_queue<Exam, vector<Exam>, CompareDuration> minDurationHeap;
    while (true)
    {
        if (minStartingTimeHeap.empty())
        {
            while (!minDurationHeap.empty())
            {
                Exam finalExam = minDurationHeap.top();

                long timeNeeded = 0;

                if (passedTime > finalExam.startingTime)
                {
                    timeNeeded += passedTime - finalExam.startingTime;
                }

                timeNeeded += finalExam.duration;
                passedTime += finalExam.duration;
                allTimes.push_back(timeNeeded);

                minDurationHeap.pop();
            }
            break;
        }

        Exam exam = minStartingTimeHeap.top();

        if (exam.startingTime <= passedTime)
        {
            minDurationHeap.push(exam);
            minStartingTimeHeap.pop();
            continue;
        }


        if (!minDurationHeap.empty())
        {
            Exam currExam = minDurationHeap.top();
            long timeNeeded = 0;

            if (passedTime > currExam.startingTime)
            {
                timeNeeded += passedTime - currExam.startingTime;
            }

            timeNeeded += currExam.duration;
            passedTime += currExam.duration;
            allTimes.push_back(timeNeeded);

            minDurationHeap.pop();
        }
        else
        {
            passedTime = minStartingTimeHeap.top().startingTime;
        }
    }

    long sum = 0;
    for (size_t i = 0; i < allTimes.size(); i++)
    {
        sum += allTimes[i];
    }

    long result = floor(sum / allTimes.size());
    cout << result;
    return 0;
}


