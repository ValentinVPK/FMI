
#include <iostream>
#include <queue>

using namespace std;

struct Task
{
    int index;
    int startingTime;
    int duration;

    Task(int index, int startingTime, int duration)
    {
        this->index = index;
        this->startingTime = startingTime;
        this->duration = duration;
    }
};

struct CompareStartingTime
{
    bool operator()(const Task& a, const Task& b)
    {
        return a.startingTime > b.startingTime;
    }
};

struct CompareDurationThenIndex
{
    bool operator()(const Task& a, const Task& b)
    {
        if (a.duration == b.duration)
        {
            return a.index > b.index;
        }

        return a.duration > b.duration;
    }
};

//struct CompareTask
//{
//    bool operator()(const Task& a, const Task& b)
//    {
//        if (a.startingTime != b.startingTime)
//        {
//            return a.startingTime > b.startingTime;
//        }
//        
//        if (a.duration != b.duration)
//        {
//            return a.duration > b.duration;
//        }
//
//        return a.index > b.index;
//    }
//};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    priority_queue<Task, vector<Task>, CompareStartingTime> minStartingTimeHeap;

    int N;
    cin >> N;

    int time, duration;
    for (int i = 0; i < N; i++)
    {
        cin >> time >> duration;

        Task currTask(i, time, duration);
        minStartingTimeHeap.push(currTask);
    }


    int passedTime = minStartingTimeHeap.top().startingTime;

    priority_queue<Task, vector<Task>, CompareDurationThenIndex> minDurationHeap;
    while (true)
    {
        if (minStartingTimeHeap.empty())
        {
            while (!minDurationHeap.empty())
            {
                printf("%d ", minDurationHeap.top().index);
                minDurationHeap.pop();
            }
            break;
        }
        Task currTask = minStartingTimeHeap.top();

        if (currTask.startingTime <= passedTime)
        {
            minDurationHeap.push(currTask);
            minStartingTimeHeap.pop();
            continue;
        }


        if (!minDurationHeap.empty())
        {
            passedTime += minDurationHeap.top().duration;
            printf("%d ", minDurationHeap.top().index);

            minDurationHeap.pop();
        }
        else
        {
            passedTime = minStartingTimeHeap.top().startingTime;
        }
    }

    return 0;
}


