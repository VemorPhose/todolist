#include <bits/stdc++.h>
#include <fstream>
using namespace std;

void write(string filename) // write new reminder function
{
    fstream file;
    file.open(filename, ios::app);
    
    string s;
    cout << "enter new task: ";
    cin.ignore();
    getline(cin, s);
    file << s << endl;
    cout << "added new task successfully." << endl << endl;
    
    file.close();
}

void read(string filename) // read all reminders function
{
    fstream file;
    file.open(filename, ios::in);

    string s;
    while(1)
    {      
        if(file.eof()) break;
        getline(file, s);
        cout << s << endl;
    }   

    file.close();
}

void remove(string filename) // remove reminder by exact text
{
    cout << "enter task to remove: ";
    string rem, postrem[10000], s;
    cin.ignore();
    getline(cin, rem);

    fstream file;
    file.open(filename, ios::in);

    int counter = 0;
    while(1)
    {
        getline(file, s);
        if(s == rem)
        {
            cout << "removed task successfully." << endl << endl;
            while(1)
            {
                if(file.eof()) break; 
                getline(file, s);
                postrem[counter] = s;
                counter++;
            }

            break;
        }
        else
        {
            postrem[counter] = s;
            counter++;
        }
        if(file.eof())
        {
            cout << "invalid entry!!!" << endl << endl;
            break; 
        }
    }
    file.close();

    file.open(filename, ios::out | ios::trunc); // trunc flag truncates file before overwriting.

    for(int i = 0; i < (counter - 1); i++)
    {
        file << postrem[i] << endl;
    }
    file.close();
}


int main()
{
    string filename;
    filename = "todolist.txt";
    
    // char newfile;
    // while(1)
    // {
    //     cout << "do you want to create a new file? y/n ";
    //     cin >> newfile;
    //     if(newfile == 'y' || newfile == 'Y')
    //     {
    //         cout << "enter name of new file with extension: ";
    //         cin.ignore();
    //         getline(cin, filename);
    //         fstream file;
    //         file.open(filename, ios::out);
    //         file.close();
    //         cout << "file created successfully." << endl;
    //     }
    //     else if(newfile == 'n' || newfile == 'N')
    //     {
    //         break;
    //     }
    // }

    // while(1)
    // {
    //     cout << "enter filename to access with extension: ";
    //     cin.ignore();
    //     getline(cin, filename);
    //     fstream file;
    //     file.open(filename, ios::in);
    //     if(!file) cout << "error in accessing file!!!" << endl;
    //     else
    //     {
    //         cout << "file accessed successfully." << endl;
    //         break;
    //     }
    // }

    int flag = 1;
    while(flag)
    {
        cout << "enter action number:" << endl;
        cout << "0. exit" << endl;
        cout << "1. display tasks" << endl;
        cout << "2. add a new task" << endl;
        cout << "3. remove a task" << endl;

        cout << "choose action: ";
        cin >> flag;
        cout << endl;

        switch(flag)
        {
            case 0:
                break;
            case 1:
                read(filename);
                break;
            case 2:
                write(filename);
                break;
            case 3:
                remove(filename);
                break;
            default:
                break;
        }
    }

    return 0;
}
