#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Structure to represent a Task
struct Task {
    int taskId;
    int priority;
    int deadline;
};

// Comparator for priority queue (Max Heap)
struct CompareTask 
{
    bool operator()(Task const& t1, Task const& t2) 
    {
        return t1.priority<t2.priority; 
        // higher priority comes first
    }
};

// Display a task
void displayTask(Task t)
{
    cout <<"Task ID: "<<t.taskId
         <<"|Priority:"<<t.priority
         <<"|Deadline:"<<t.deadline<<endl;
}

int main() 
{
    priority_queue<Task, vector<Task>, CompareTask> pq;
    int choice;

    do {
        cout<<"\n===== TASK SCHEDULER =====\n";
        cout<<"1.Add Task\n";
        cout<<"2.Execute Highest Priority Task\n";
        cout<<"3.View All Tasks\n";
        cout<<"4.Exit\n";
        cout<<"Enter your choice:";
        cin>>choice;

        if (choice == 1)
         {
            Task t;
            cout<<"Enter Task ID:";
            cin>>t.taskId;
            cout<<"Enter Priority(Higher number = higher priority):";
            cin>>t.priority;
            cout<<"Enter Deadline:";
            cin>>t.deadline;

            pq.push(t);
            cout<<"Task added successfully!\n";
        }
        else if(choice == 2) 
        {
            if(pq.empty()) 
            {
                cout<<"No tasks to execute.\n";
            } 
            else 
            {
                Task t=pq.top();
                pq.pop();
                cout<<"Executing Task:\n";
                displayTask(t);
            }
        }
        else if(choice == 3) 
        {
            if(pq.empty()) 
            {
                cout<<"No pending tasks.\n";
            } 
            else
            {
                priority_queue<Task, vector<Task>, CompareTask> temp = pq;
                cout<<"Pending Tasks:\n";
                while(!temp.empty()) {
                    displayTask(temp.top());
                    temp.pop();
                }
            }
        }
        else if (choice == 4)
        {
            cout<<"Exiting Task Scheduler...\n";
        }
        else {
            cout<<"Invalid choice. Try again.\n";
        }

    } 
    while (choice != 4);

    return 0;
}
