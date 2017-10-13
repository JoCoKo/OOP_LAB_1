#include <iostream>
#include <string> // ���������� ������
#include <fstream> // ���������� �����
#include "IniParser.h"



using namespace std; // ���������� ����������� ������������ ����
/*
void inOut(char* inp)
{
    string section;
    string s; // ���� ����� ������ ��������� ������
    ifstream file(inp); // ���� �� �������� ������

    while(getline(file, s)){ // ���� �� ��������� ����� ����� ������ ��������� ������ � ���������� (s)
        cout << s << endl; // ������� �� �����
        if (s[0] == '['){
            cout << "Section: " <<(section = s.substr(1,s.length()-2)) << endl;
        }
        else {
            if (s.find("=") != -1)//���� ������ �������� ��������
            {
                if (s.find(";") != -1)
                    s=s.substr(0,s.find(";")); //������� �����������
                while (s.find(" ") != -1)
                    s.erase(s.find(" "),1); //������� �������
                cout << "Param: " << section << "." << s.substr(0,s.find("=")) << " Value: " << s.substr(s.find("=")+1) <<endl;
            }
        }
    }

    file.close(); // ����������� ��������� ���� ��� �� �� ��������� ���
}*/
int main()
{
    /*char inp[255];
    cin >> inp;
    cout << "String input: " << inp << endl;
    inOut(inp);
    inOut("inpf.txt"); */
    char * sin = (char*)"lab01_input_correct.ini";
    IniParser parser = IniParser(sin);
    parser.printAll();
    try
    {
    cout << parser.getDouble("COMMON", "StatisterTimeMs") << endl;
//    cout << parser.getString("COMMON", "StatisterTimeMS") << endl;
    }
    catch (IniParserExeptionNoSuchParam& e)
    {
        cerr << e.get() << endl;
    }
    try
    {
    cout << parser.getString("COMMOn", "StatisterTimeMS") << endl;
    }
    catch (IniParserExeptionNoSuchParam& e)
    {
        cerr << e.get() << endl;
    }
	getchar();

    return 0;
}
