#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
using namespace std;

int __Next_token (string &s, string &target) 
{
    target = "";
    int cnt = 0;
    for (string::iterator i=s.begin();i!=s.end();++i,cnt++)
        if (*i == ',') {
            target.insert(target.begin(),s.begin(),i);
            s.erase(0,cnt+1);
            return true;
        }
    target = s;
    return false;
}

bool Change_password (string username, string password)
{
	ifstream filein;
	ofstream fileout;
	filein.open ("user.txt");
	fileout.open ("user_out.txt");
//	string line;
	string usn, tmp;
	char* line_c= new char [100];
	int swi= 0, i= 0;
	bool check= false;

	while (!filein.eof ())
	{
		if (i!=0) fileout << endl;
		i++;
		filein.getline (line_c, 200);
//		cout << line_c << endl;
		string line(line_c);
//		cout << line << endl;
		swi= __Next_token (line, usn);
		if (usn!= username)
			fileout << usn << ',' << line;
		else 
		{
			fileout << usn << ',';
			for (int i= 0; i< 4; i++)
			{
				swi= __Next_token (line, tmp);
				fileout << tmp << ',';
			}
			fileout << password << ',';
			swi= __Next_token (line, tmp);
			swi= __Next_token (line, tmp);
			fileout << tmp;
			check= true;
		}
	}
	filein.close ();
	fileout.close ();

	// File control
	remove ("user.txt");
	rename ("user_out.txt", "user.txt");

	return check;
	delete []line_c;
}

void main ()
{
	char *pass_c = new char [100];
	string username;
	cout << "Enter username: ";
	cin >> username;
	cout << "Enter new password: ";
	fflush (stdin);
	cin.getline (pass_c, 99, '\n');
	string password (pass_c);
	bool change= Change_password (username, password);
	if (change) cout << "Password successfully changed." << endl;
	else cout << "There's no user with such username." << endl;

	delete []pass_c;
}
