//
//  main.cpp
//  assignement4
//
//  Created by Tucker King on 10/3/21.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

struct Task
{
    int task_num;
    char task_status;
    string task_description;
};

void update_task(int, vector<Task>, ofstream);
void display_all_tasks(vector<Task>);
void display_selected_task(int, vector<Task>);

int main(int argc, const char * argv[])
{
    // Task list file
    ifstream in_file("/Users/tuckerking/Documents/Documents - Tucker’s MacBook Pro (2)/Comp Sci Classes/CS 372 - Data Structures/Assignments/assignment04/assignement4/assignement4/task_list.txt");
    ofstream out_file("/Users/tuckerking/Documents/Documents - Tucker’s MacBook Pro (2)/Comp Sci Classes/CS 372 - Data Structures/Assignments/assignment04/assignement4/assignement4/task_list.txt");
    
    
    // Create task list
    vector<Task> task_list;
    
    // Populate task list
    int i = 0;
    int task_num = 0;
    char task_status;
    string task_description;
    
    while(!in_file.eof())
    {
        Task new_task;
        in_file >> task_num;
        new_task.task_num= task_num;
        in_file >> task_status;
        new_task.task_status= task_status;
        in_file >> task_description;
        new_task.task_description= task_description;
        
        task_list.push_back(new_task);
        
        i++;
    }
    
    // Display menu
    int user_choice= 0;
    while(user_choice!= 4)
    {
        cout << "\tYour To-Do List" << endl << endl;
        cout << "[1] - Display To-Do List" << endl;
        cout << "[2] - Display Selected Task" << endl;
        cout << "[3] - Mark a Task as Done" << endl;
        cout << "[4] - Exit the Program" << endl;
    
        cin >> user_choice;
        cout << endl;
        
        switch(user_choice)
        {
            case 1:
                display_all_tasks(task_list);
                break;
            case 2:
                int task_num;
                cout << "Enter task number you want to display: ";
                cin >> task_num;
                cout << endl;
                
                display_selected_task(task_num, task_list);
                break;
            case 3:
                cout << "Enter task number you want to mark as done: ";
                cin >> task_num;
                cout << endl;
                
                update_task(task_num, task_list);
                break;
            case 4:
                exit(1);
                break;
        }
    }
    
    return 0;
}

void read_file(ifstream input, vector<Task> task_list) {
    int i = 0;
    int task_num = 0;
    char task_status;
    string task_description;
    
    while(!input.eof())
    {
        input >> task_num;
        task_list[i].task_num= task_num;
        input >> task_status;
        task_list[i].task_status= task_status;
        input >> task_description;
        task_list[i].task_description= task_description;
        
        i++;
    }
}

void display_all_tasks(vector<Task> task_list)
{
    for(int i= 0; i < task_list.size(); i++)
    {
        cout << task_list[i].task_num << " " << task_list[i].task_status << " " <<
            task_list[i].task_description << endl;
    }
}
