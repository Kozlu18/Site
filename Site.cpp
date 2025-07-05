#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

struct User
{
    string first_name;
    string last_name;
    string user_name;
    string email;
    string password;
};

struct Book
{
    string book_name;
    int nfq;
    int nft;
    string topic_name;
    int topic = 0;
    vector<string> test_name;
};

struct Teacher
{
    string firstname;
    string password;
    string email;
    string birth_day;
    string user_name;
    string surname;
};

struct Student
{
    string firstname;
    string surname;
    string email;
    string username;
    string password;
    string birth;
    vector<string> homework;
    vector<string> thomework;
};

bool is_valid_email(const string &email)
{
    return email.find("gmail.com") != string::npos ||
           email.find("hotmail.com") != string::npos || 
           email.find("icloud.com") != string::npos;

}

bool is_valid_password(const string &password)
{
    if(password.size() < 8)
    {
        cout << "Your password lenght < 8 " << endl;
        return false;
    }
    bool has_letter = false, has_digit = false;
    for(auto c : password)
    {
        if(isalpha(c)) has_letter = true;
        if(isdigit(c)) has_digit = true;
    }
    return has_digit && has_letter;

}

void create_accout(User &user)
{
    cout << "Please write first name : ";
    cin >> user.first_name;
    cout << "Please write last name : ";
    cin >> user.last_name;
    cout << "Please write username : ";
    cin >> user.user_name;

    do{
        cout << "Please write email : ";
        cin >> user.email;
    }while(!is_valid_email(user.email));
    cout << "Your email is true." << endl;
    do{
        cout << "Please write password. Your passwrod must be last 8 characters and use letter : ";
        cin >> user.password;
    }while(!is_valid_password(user.password));
    cout << "Your account succesfully created." << endl;
}

void add_book(Book &book)
{
    cout << "Please write your book name : ";
    cin >> book.book_name;
    cout << "Please enter number of quastions : ";
    cin >> book.nfq;
    cout << "Please enter number of tests : ";
    cin >> book.nft;
    int j = book.nft;
    int l = 0;
    for(int i = 0 + l; i < j; i++)
    {
        cout << "Please write topic name : ";
        cin >> book.topic_name;
        cout << "How many test are topic : ";
        cin >> book.topic;
        l = book.topic;
        cout << "Please dont use space button!!!! use '-' key or use '_' please!!!! " << endl;
        for(int k = 0; k < book.topic; k++)
        {
            string test;
            cout << "Please write test name : ";
            cin >> test;
            book.test_name.push_back(test);
            cout << "You added test name : " << endl;
        }
        if(l + i > j)
        {
            cout << "You added test!" << endl;
            break;
        }
            break;
        cout << "You added topic test name write another topic test name : " << endl;
    }
}

void add_teacher_account(Teacher &teacher)
{
    cout << "Please write teacher first name : ";
    cin >> teacher.firstname;
    cout << "Please write teacher surname : ";
    cin >> teacher.surname;
    cout << "Please write teacher birth day : ";
    cin >> teacher.birth_day;
    cout << "Please write teacher username : ";
    cin >> teacher.user_name;
    do{
        cout << "Please write teacher email : ";
        cin >> teacher.email;
    }while(!is_valid_email(teacher.email));
    cout << "Your email is correct." << endl;
    do{
        cout << "Please enter teacher password : ";
        cin >> teacher.password;
    }while(!is_valid_password(teacher.password));
    cout << "You created teacher account. Please enjoy." << endl;
}

void add_student_account(Student &student)
{
    cout << "Please write student name : ";
    cin >> student.firstname;
    cout << "Please write student surname : ";
    cin >> student.surname;
    cout << "Please write student username : ";
    cin >> student.username;
    cout << "Please write Birty year 'YY' : ";
    cin >> student.birth;
    do{
        cout << "Please write student email : ";
        cin >> student.email;
    }while(!is_valid_email(student.email));
    cout << "Your email is true" << endl;
    do{
        cout << "Please write student password : ";
        cin >> student.password;
    }while(!is_valid_password(student.password));
    cout << "You created student account : " << endl;
}

void give_homework(Book &book, User &user, Student &student)
{
    cout << endl;
    cout << "Welcome to give homework page : " << user.user_name << endl;
    cout << "S : Show the book test : " << endl;
    cout << "Q : Quit the give homework page : " << endl;
    char act;
    cin >> act;
    int l = book.nft;
    if(act == 'S' || act == 's')
    {
        int i = 0;
        while(book.nft--)
        {
            cout << book.test_name[i] << endl;
            i++;
        }
        cout << "Please write how many give test for student : ";
        int K;
        cin >> K;
        while(K > l)
        {
            cout << "You entered bigger than number of tests. Writed the how many are test have : " << l << " Please write new how many test give homework : " << endl;
            cin >> K;
        }
        for(int i = 0; i < K; i++)
        {
            int l = 0;
            cout << "Please write test name (0 to nft) : ";
            cin >> l;
            student.homework.push_back(book.test_name[l]);
        }
        cout << "You gived test for student." << endl;
    }
    else if(act == 'Q' || act == 'q')
    {
        cout << "Exiting the program...";
        this_thread::sleep_for(chrono::seconds(3));
        cout << "You exited the give homework page." << endl;
    }
    else{
        cout << "You wrong pressed key. Please try again : " << endl;
    }
}

void show_homework(Student &student, Book &book)
{
    cout << "Showing the homework..." << endl;
    for(int i = 0; i < student.homework.size(); i++)
        cout << student.homework[i] << endl;
    cout << "Showed the homework." << endl;
}

void change_information(User &user)
{
    cout << "Please write new username : ";
    cin >> user.user_name;
    string old_password;
    cout << "Please enter your old password : ";
    cin >> old_password;
    while(old_password !=  user.password)
    {
        cout << "You wrong entered password. Please try again : ";
        cin >> old_password;
    }
    cout << "You writed true password." << endl;
    do{
        cout << "Please write new password : ";
        cin >> user.password;
    }while(!is_valid_password(user.password));
    cout << "You changed information enjoy." << endl;
}

void change_sinformation(Student &student)
{
    string old_password;
    cout << "Please enter your old password : ";
    cin >> old_password;
    while(old_password !=  student.password)
    {
        cout << "You wrong entered password. Please try again : ";
        cin >> old_password;
    }
    cout << "You writed true password." << endl;
    do{
        cout << "Please write new password : ";
        cin >> student.password;
    }while(!is_valid_password(student.password));
    cout << "You changed information enjoy." << endl;
}

void change_tinformation(Teacher &teacher)
{
    string email_inputs, password_inputs;
    cout << "Please enter your email : ";
    cin >> email_inputs;
    cout << "Please enter your password : ";
    cin >> password_inputs;
    while(email_inputs != teacher.email || password_inputs != teacher.password)
    {
        cout << "Your information is wrong please try again : " << endl;
        cout << "Please enter email : ";
        cin >> email_inputs;
        cout << "Please enter your password : ";
        cin >> password_inputs;
    }
    cout << "Please write new username : ";
    cin >> teacher.user_name;
    cout << "Please write old password : ";
    cin >> password_inputs;;
    while(password_inputs != teacher.password)
    {
        cout << "Your old password is wrong. Please try again." << endl;
        cout << "Please enter old password : ";
        cin >> password_inputs;
    }
    do{
        cout << "Please write new password : ";
        cin >> teacher.password;
    }while(!is_valid_password(teacher.password));
    cout << "Your information is changed. Enjoy!" << endl;
}

void check_for_homeworkstd(Student &student)
{
    cout << "S : Show ticked homework : " << endl;
    cout << "Q : Exit the check for homework page : " << endl;
    char act;
    cin >> act;
    if(act == 'S' || act == 's')
    {
        for(int i = 0; i < student.homework.size(); i++)
        {
            cout << student.homework[i] << endl;
        }
        cout << "You showed homework and ticked homework." << endl;
    }
    else if(act == 'Q' || act == 'q')
    {
        cout << "Exiting the page...";
        this_thread::sleep_for(chrono::seconds(3));
        cout << "You exited the page." << endl;
    }
    else{
        cout << "You pressed wrong key please try again : " << endl;
    }
}

void tick_homework(Student &student)
{
    for(int i = 0; i < student.homework.size(); i++)
        cout << student.homework[i] << endl;
    for(int i = 0; i < student.homework.size(); i++)
    {
        cout << "Please write test index : ";
        int k;
        cin >> k;
        student.homework[k] += "*";
    }
    cout << "You ticked the homework." << endl;
}

bool login_account(const User &user)
{
    string email_inputs, password_inputs;
    int attemps = 0;
    while(attemps < 3)
    {
        cout << "Please enter your email: ";
        cin >> email_inputs;
        cout << "Please enter your password: ";
        cin >> password_inputs;
        if(email_inputs == user.email && password_inputs == user.password)
        {
            cout << "You logged system enjoy." << endl;
            return true;
        }
        cout << "You writted wrong information please try again." << endl;
        attemps += 1;
    }
    cout << "To many wrong attemps. Please wait 30 seconds...";
    this_thread::sleep_for(chrono::seconds(30));
    return false;
}

bool tlogin_account(const Teacher &teacher)
{
    string email_inputs, password_inputs;
    int attemps = 0;
    while(attemps < 3)
    {
        cout << "Please write teacher email : ";
        cin >> email_inputs;
        cout << "Please write teacher password : ";
        cin >> password_inputs;;
        if(email_inputs == teacher.email && password_inputs == teacher.password)
        {
            cout << "You logged teacher account." << endl;
            return true;
        }
        cout << "Your information is wrong try again." << endl;
        attemps += 1;
    }
    cout << "To many wrong attemps. Please wait 30 seconds...";
    this_thread::sleep_for(chrono::seconds(30));
    return false;
}

bool slogin_account(const Student &student)
{
    string email_inputs, password_inputs;
    int attemps = 0;
    while(attemps < 3)
    {
        cout << "Please enter student email : ";
        cin >> email_inputs;
        cout << "Please enter student password : ";
        cin >> password_inputs;
        if(email_inputs == student.email && password_inputs == student.password)
        {
            cout << "You logged student account. Enjoy.";
            return true;
        }
        cout << "Your personal information is wrong. Try again!" << endl;
    }
    cout << "To many wrong attemps. Please wait 30 seconds...";
    this_thread::sleep_for(chrono::seconds(30));
    return false;
}

int main()
{
    User user;
    Book book;
    Teacher teacher;
    Student student;
    bool logged_in = false;
    bool tlogged_in = false;
    bool slogged_in = false;
    while(logged_in == false)
    {
        cout << "İf you dont have account please press 'C' or you have account please press 'L' : ";
        char button;
        cin >> button;
        if(button == 'C' || button == 'c')
            create_accout(user);
        else if(button == 'L' || button == 'l')
            logged_in = login_account(user);
    }
    while(logged_in == true && tlogged_in == false && slogged_in == false)
    {
        cout << "Welcome the site :" << " " << user.user_name << endl; 
        cout << "A : Add book : " << endl;
        cout << "T : Add teacher account : " << endl;
        cout << "S : Add student account : " << endl;
        cout << "F : Login teacher account : " << endl;
        cout << "K : Login student account : " << endl;
        cout << "H : Give a homework for student : " << endl;
        cout << "L : Show the student homework : " << endl;
        cout << "C : Check for student homework : " << endl;
        cout << "G : Change information : " << endl;
        cout << "Q : Quit the program : " << endl;
        char action;
        cin >> action;

        if(action == 'A' || action == 'a')
            add_book(book);
        else if(action == 'T' || action == 't')
            add_teacher_account(teacher);
        else if(action == 'S' ||action == 's')
            add_student_account(student);
        else if(action == 'F' || action == 'f')
        {
            tlogged_in = tlogin_account(teacher);
            if(tlogged_in == true)
            {
                logged_in = false;
                slogged_in = false;
            }
        }
        else if(action == 'K' || action == 'k')
        {
            slogged_in = slogin_account(student);
            if(slogged_in == true)
            {
                tlogged_in = false;
                logged_in = false;
            }
        }
        else if(action == 'H' || action == 'h')
            give_homework(book, user, student);
        else if(action == 'L' || action == 'l')
            show_homework(student, book);
        else if(action == 'C' || action == 'c')
            check_for_homeworkstd(student);
        else if(action == 'G' || action == 'g')
            change_information(user);
        else if(action == 'Q' || action == 'q')
        {
            cout << "Exiting the program...";
            this_thread::sleep_for(chrono::seconds(3));
            cout << endl;
            cout << "Exited the program." << endl;
            tlogged_in = false;
            logged_in = false;
            slogged_in = false;
        }
        else
            cout << "You wrong pressed key. Please try again : " << endl;
    }
    while(tlogged_in == true)
    {
        cout << "Welcome : " << teacher.user_name << endl;
        cout << "H : Give a homework for student : " << endl;
        cout << "C : Check for student homework : " << endl;
        cout << "G : Change information : " << endl;
        cout << "Q : Quit the program : " << endl;
        char action;
        cin >> action;
        if(action == 'H' || action == 'h')
            give_homework(book, user, student);
        else if(action == 'C' || action == 'c')
            check_for_homeworkstd(student);
        else if(action == 'G' || action == 'g')
            change_tinformation(teacher);
        else if(action == 'Q' || action == 'q')
        {
            cout << "Are you sure exit the page. Please write 'SURE' : " << endl;
            char act;
            cin >> act;
            while(act == 'SURE')
            {
                cout << "You wrong writed please try again : " << endl;
                cin >> act;
            }
            cout << "Exiting the program...";
            this_thread::sleep_for(chrono::seconds(3));
            tlogged_in = false;
            slogged_in = false;
            logged_in = false;
        }
        else
            cout << "You pressed wrong key pleae try again : " << endl; 
        
    }
    while(slogged_in == true)
    {
        cout << "Welcome : " << student.username << endl;
        cout << "C : Your homework and tick " << endl;
        cout << "G : Change information : " << endl;
        cout << "Q : Qit the program : " << endl;
        char action;
        cin >> action;

        if(action == 'C' || action == 'c')
            tick_homework(student);
        else if(action == 'G' ||action == 'g')
            change_sinformation(student);
        else if(action == 'Q' || action == 'q')
        {
            cout << "Are you sure exit the program. Please write 'SURE' : " << endl;
            char act;
            cin >> act;
            while(act == 'SURE')
            {
                cout << "You writed wrong please try again : " << endl;
                cin >> act;
            }
            cout << "Exiting the program...";
            this_thread::sleep_for(chrono::seconds(3));
            cout << "You exited the program." << endl;
            slogged_in = false;
            tlogged_in = false;
            logged_in = false;
        }
        else
            cout << "You pressed wrong key please try again : " << endl;
    }
}
