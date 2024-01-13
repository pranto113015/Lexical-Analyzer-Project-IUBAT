// Pranto Kumar

#include<bits/stdc++.h>

using namespace std;

#define letter (nc<='z' && nc>='a')||(nc<='Z' && nc>='A')
#define relop cn=='<' || cn=='>' || cn=='=' || cn=='!'


string power="",key="";
char nc, operators[] = "+-";


//This step work for keyword
void isKeyword(string s)
{
    if(s=="Void" || s=="int"|| s=="return"||s=="cin"||s=="cout" || s=="endl")
    {
        cout<<"keyword : "<<s<<endl;
    }

}

//This step work for Modulus Operator
void mod_check(char c)
{
    if(c=='%') cout<<"Modulus Operator : "<<c<<endl;
}


//This step work for Add Operator
void checkOperator()
{
    for(int i = 0; i < 6; ++i)
    {
        if(nc == operators[i])
            cout<<"Add operator : "<<nc<<endl;;
    }
}


int main()
{
    int j=0;
    //linkup the source code Program
    ifstream fin("Sample_Input.txt");
    string RELOP="";

    while(!fin.eof())
    {
        nc = fin.get();
        checkOperator();

        mod_check(nc);


        if(letter)
        {
            key= key+nc;;
        }
        else
        {
            isKeyword(key);
            key="";
        }

        char cn=nc;
        if(cn=='+'||cn=='-')
        {
            power+=cn;
            if(power=="++" || power=="--") //This step work for increment decrement operator
            {
                cout<<"Increment Decrement Operator : "<<power<<endl;
                power="";
            }
            else
            {
                if(power.size()>=2) power="";
            }
        }


        if(relop)
        {
            RELOP= RELOP+cn;
        }
        else
        {

            if(RELOP=="<=" || RELOP==">=" ||RELOP=="!=" ||RELOP=="==" ||RELOP=="<" ||RELOP==">")
            {

                cout<<"Relational Operator : "<<RELOP<<endl;//This step work for Relational operator
            }


            RELOP="";
        }

    }

    fin.close();

    return 0;
}
